#include "ride/projectexplorer.h"

#include <vector>

#include <wx/dir.h>
#include <wx/filename.h>

#include "ride/mainwindow.h"
#include "ride/resources/icons.h"
#include "ride/wxutils.h"

enum {
  ICON_FILE_NORMAL,
  ICON_FOLDER_NORMAL
};

ProjectExplorer::ProjectExplorer(MainWindow* main)
  : wxTreeCtrl(main, wxID_ANY, wxDefaultPosition, wxDefaultSize,
  wxTR_HAS_BUTTONS
  | wxTR_TWIST_BUTTONS
  | wxTR_MULTIPLE
  | wxTR_LINES_AT_ROOT
  ), images_(16, 16), main_(main), last_highlighted_item_(NULL) {
  UpdateColors();

  this->SetImageList(&images_);

  images_.Add(wxIcon(file_normal_xpm));
  images_.Add(wxIcon(folder_normal_xpm));
}

void ProjectExplorer::UpdateColors() {
  const ride::Style& style = main_->settings().fonts_and_colors().default_style();
  this->SetBackgroundColour(C(style.background()));
  this->SetForegroundColour(C(style.foreground()));
}

void ProjectExplorer::SetFolder(const wxString& folder) {
  folder_ = folder;
  UpdateFolderStructure();
}

void ProjectExplorer::HighlightOpenFile(const wxString& file_path) {
  auto res = folder_to_item_.find(file_path);
  if (res != folder_to_item_.end()) {
    wxTreeItemId id = res->second;
    this->SetItemBold(id, true);
    if (last_highlighted_item_.IsOk()) {
      this->SetItemBold(last_highlighted_item_, false);
    }
    last_highlighted_item_ = id;
  }
}

wxFileName SubFolder(const wxFileName& root, const wxString& sub_folder) {
  wxFileName folder(root);
  folder.AppendDir(sub_folder);
  return folder;
}

bool IsDirectory(const wxFileName& root, const wxString directory) {
  const wxFileName temp = SubFolder(root, directory);
  const wxString full_path = temp.GetFullPath();
  const bool ret = wxDir::Exists(full_path);
  return ret;
}

class FileEntry : public wxTreeItemData {
public:
  FileEntry(bool is_directory, const wxString& path) : is_directory_(is_directory), path_(path) {}
  const wxString& path() const {
    return path_;
  }
  bool is_directory() const {
    return is_directory_;
  }
private:
  bool is_directory_;
  wxString path_;
};

void ProjectExplorer::UpdateFolderStructure() {
  const int flags = wxDIR_FILES | wxDIR_DIRS; // walk files and folders
  const wxString filespec = "";
  
  last_highlighted_item_.Unset();
  folder_to_item_.clear();
  this->Freeze();
  this->DeleteAllItems();
  this->AppendItem(this->GetRootItem(), "Project", ICON_FOLDER_NORMAL, ICON_FOLDER_NORMAL, new FileEntry(true, folder_));
  SubUpdateFolderStructure(folder_, this->GetRootItem(), filespec, flags, 0);
  this->Thaw();

  this->ExpandAll();
}


std::vector<wxString> TraverseFilesAndFolders(const wxFileName& root, const wxString filespec, const int flags) {
  const wxString root_full_path = root.GetFullPath();

  if (root_full_path.IsEmpty()) return std::vector<wxString>();

  wxDir directory(root_full_path);

  directory.Open(root_full_path);

  std::vector<wxString> ret;
  wxString file_or_directory_name;
  bool cont = directory.GetFirst(&file_or_directory_name, filespec, flags);
  while (cont)
  {
    ret.push_back(file_or_directory_name);
    cont = directory.GetNext(&file_or_directory_name);
  }

  directory.Close();
  return ret;
}

wxString JoinPath(const wxFileName& root, const wxString& file_or_folder) {
  // todo: is this really the correct way to do things?
  return root.GetFullPath() + file_or_folder;
}

void ProjectExplorer::SubUpdateFolderStructure(const wxFileName& root, wxTreeItemId parent, const wxString filespec, const int flags, int index)
{
  const wxString root_full_path = root.GetFullPath();
  const std::vector<wxString> files_and_folders = TraverseFilesAndFolders(root, filespec, flags);
  for (const wxString file_or_directory_name : files_and_folders)
  {
    if( file_or_directory_name == "target" && index == 0 ) continue;

    const bool is_dir = IsDirectory(root, file_or_directory_name);
    const int image = is_dir ? ICON_FOLDER_NORMAL : ICON_FILE_NORMAL;

    const wxString path = JoinPath(root, file_or_directory_name);
    wxTreeItemData* data = new FileEntry(is_dir, path);
    wxTreeItemId child = this->AppendItem(parent, file_or_directory_name, image, image, data);
    folder_to_item_[path] = child;
    if (is_dir) {
      const wxFileName folder_name = SubFolder(root, file_or_directory_name);
      SubUpdateFolderStructure(folder_name, child, filespec, flags, index+1);
    }
  }
}

typedef std::pair<wxTreeItemId, FileEntry*> TreeItemFileEntry;

TreeItemFileEntry GetFocused(ProjectExplorer* pe) {
  wxTreeItemId selected = pe->GetFocusedItem();
  if (selected.IsOk() == false) return TreeItemFileEntry(NULL, NULL);
  wxTreeItemData* data = pe->GetItemData(selected);
  if (data) {
    FileEntry* entry = reinterpret_cast<FileEntry*>(data);
    return TreeItemFileEntry(selected, entry);
  }
  else {
    return TreeItemFileEntry(selected, NULL);
  }
}

void ProjectExplorer::OnDoubleClick(wxMouseEvent& event) {
  const auto focused = GetFocused(this);
  if (focused.first.IsOk() == false) return;
  this->Toggle(focused.first);
  if (focused.second) {
    if (false == focused.second->is_directory()) {
      main_->OpenFile(focused.second->path());
    }
  }
}

enum {
  ID_FOLDER_COLLAPSE = wxID_HIGHEST
  , ID_FOLDER_EXPAND

  , ID_FOLDER_COLLAPSE_ALL_CHILDREN
  , ID_FOLDER_EXPAND_ALL_CHILDREN

  , ID_COLLAPSE_ALL
  , ID_EXPAND_ALL

  , ID_OPEN_FILE
};

void ProjectExplorer::OnContextMenu(wxContextMenuEvent& event) {
  const wxPoint mouse_point = GetContextEventPosition(event);
  const wxPoint client_point = ScreenToClient(mouse_point);

  const auto selected = GetFocused(this);

  const bool is_folder = selected.second ? selected.second->is_directory() == true  : false;
  const bool is_file   = selected.second ? selected.second->is_directory() == false : false;
  
  wxMenu menu;
  AppendEnabled(menu, ID_FOLDER_COLLAPSE, "Collapse", is_folder);
  AppendEnabled(menu, ID_FOLDER_EXPAND, "Expand", is_folder);
  menu.AppendSeparator();
  AppendEnabled(menu, ID_FOLDER_COLLAPSE_ALL_CHILDREN, "Collapse children", is_folder);
  AppendEnabled(menu, ID_FOLDER_EXPAND_ALL_CHILDREN, "Expand children", is_folder);
  menu.AppendSeparator();
  AppendEnabled(menu, ID_COLLAPSE_ALL, "Collapse all", is_folder);
  AppendEnabled(menu, ID_EXPAND_ALL, "Expand all", is_folder);
  menu.AppendSeparator();
  AppendEnabled(menu, ID_OPEN_FILE, "Open file", is_file);

  PopupMenu(&menu);
}

wxBEGIN_EVENT_TABLE(ProjectExplorer, wxTreeCtrl)
EVT_LEFT_DCLICK(ProjectExplorer::OnDoubleClick)
EVT_CONTEXT_MENU(ProjectExplorer::OnContextMenu)
wxEND_EVENT_TABLE()
