#include "ride/project.h"
#include <wx/utils.h>
#include <wx/process.h>
#include <wx/txtstrm.h>
#include <wx/filename.h>
#include "ride/wxutils.h"

#include "ride/mainwindow.h"
#include "settings.pb.h"
#include "ride/proto.h"

#include <wx/choicdlg.h>

Project::Project(MainWindow* output, const wxString& root_folder) : main_(output), root_folder_(root_folder) {
  if (root_folder_.IsEmpty() == false) {
    if (LoadProto(&project_, GetProjectFile()) == false) {
    }
    if (project_.build_settings_size() == 0) {
      // add default build settings to the project
      ride::BuildSetting* debug = project_.add_build_settings();
      debug->set_name("Debug");
      debug->set_release(false);

      ride::BuildSetting* release = project_.add_build_settings();
      release->set_name("Release");
      release->set_release(true);
    }

    if (LoadProto(&user_, GetUserFile()) == false) {
    }

    // validate project file
    GetCurrentBuildSetting();
  }

}

Project::~Project() {
  Save();
}

const wxString& Project::root_folder() const {
  return root_folder_;
}

bool Project::Save() {
  if (root_folder_.IsEmpty() ) return false;
  bool project_saved = SaveProto(&project_, GetProjectFile());
  bool user_saved = SaveUser();
  return project_saved && user_saved;
}

int Project::tabwidth() const {
  return project_.tabwidth();
}
bool Project::usetabs() const {
  return project_.usetabs();
}

void Project::set_tabwidth(int tabwidth) {
  project_.set_tabwidth(tabwidth);
}
void Project::set_usetabs(bool usetabs) {
  project_.set_usetabs(usetabs);
}

const wxString Project::GetCargoFile() const {
  if (root_folder_.IsEmpty()) return "";
  wxFileName cargo(root_folder_, "cargo.toml");
  return cargo.GetFullPath();
}

const wxString Project::GetProjectFile() const {
  if (root_folder_.IsEmpty()) return "";
  wxFileName cargo(root_folder_, "project.ride");
  return cargo.GetFullPath();
}

const wxString Project::GetUserFile() const {
  if (root_folder_.IsEmpty()) return "";
  wxFileName cargo(root_folder_, "project.ride.user");
  return cargo.GetFullPath();
}

bool Project::IsPartOfProject(const wxString& filename) {
  // todo: implement a better logic for checking if the file is part of the project
  return true;
}

void Project::Settings() {
}

void Project::SelectActiveBuild() {
  // todo: implement me

  std::vector<wxString> names;
  names.reserve(project_.build_settings_size());
  for (const ride::BuildSetting& setting : project_.build_settings()) {
    names.push_back(setting.name());
  }

  wxSingleChoiceDialog dlg(NULL, "Select build", "Build", names.size(), &names[0]);
  dlg.SetSelection( user_.build_setting() );
  const int dialog_result = dlg.ShowModal();

  if (dialog_result != wxID_OK) return;
  user_.set_build_setting(dlg.GetSelection());
  SaveUser();
}

void Project::SaveAllFiles() {
  main_->SaveAllChangedProjectFiles();
  Save();
}

void Project::Build(bool origin_main) {
  if (origin_main) {
    CleanOutput();
    SaveAllFiles();
  }

  // todo: expand commandline with arguments
  RunCmd("cargo build");
}

void Project::Clean(bool origin_main) {
  if (origin_main) {
    CleanOutput();
    SaveAllFiles();
  }

  // todo: expand commandline with arguments
  RunCmd("cargo clean");
}

void Project::Rebuild(bool origin_main) {
  if (origin_main) {
    CleanOutput();
    SaveAllFiles();
  }
  Clean(false);
  Build(false);
}

void Project::Doc(bool origin_main) {
  if (origin_main) {
    CleanOutput();
    SaveAllFiles();
  }

  // todo: expand commandline with arguments
  RunCmd("cargo doc");
}

void Project::Run(bool origin_main) {
  if (origin_main) {
    CleanOutput();
    SaveAllFiles();
  }

  Build(false);
  //todo: run the application
}

void Project::Test(bool origin_main) {
  if (origin_main) {
    CleanOutput();
    SaveAllFiles();
  }

  // todo: expand commandline with arguments
  RunCmd("cargo test");
}

void Project::Bench(bool origin_main) {
  if (origin_main) {
    CleanOutput();
    SaveAllFiles();
  }

  // todo: expand commandline with arguments
  RunCmd("cargo bench");
}

void Project::Update(bool origin_main) {
  if (origin_main) {
    CleanOutput();
    SaveAllFiles();
  }

  // todo: expand commandline with arguments
  RunCmd("cargo update");
}

//////////////////////////////////////////////////////////////////////////

void Project::CleanOutput() {
  main_->build_output().Clear();
}

void Project::Append(const wxString& str) {
  main_->build_output().Append(str);
}

void Project::RunCmd(const wxString& cmd) {
  if (root_folder_.IsEmpty()) {
    ShowInfo(main_, "No project open, you need to open a cargo project first!", "No project open!");
    return;
  }

  MultiRunner::RunCmd(Command(root_folder_, cmd));
}

bool Project::SaveUser() {
  return SaveProto(&user_, GetUserFile());
}

int Project::GetSelectedBuildIndex() {
  if (user_.build_setting() < 0 || user_.build_setting() >= project_.build_settings_size()) {
    user_.set_build_setting(0);
    SaveUser();
  }

  return user_.build_setting();
}

const ride::BuildSetting& Project::GetCurrentBuildSetting() {
  return project_.build_settings(GetSelectedBuildIndex());
}
