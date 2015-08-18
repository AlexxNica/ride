// Copyright (2015) Gustav

#include "ride/projectsettingsdlg.h"

#include <wx/editlbox.h>
#include <wx/fontenum.h>
#include <wx/textdlg.h>

#include <string>

#include "ride/generated/ui.h"

#include "ride/resources/commonimages.h"

#include "ride/cargo.h"
#include "ride/enabledisable.h"
#include "ride/form.h"
#include "ride/mainwindow.h"
#include "ride/project.h"
#include "ride/wxutils.h"

class ProjectSettingsDlg : public ui::ProjectSettings {
 public:
  ProjectSettingsDlg(wxWindow* parent, MainWindow* mainwindow,
                     Project* project);

 protected:
  void OnApply(wxCommandEvent& event);
  void OnCancel(wxCommandEvent& event);
  void OnOk(wxCommandEvent& event);

 protected:
  bool Apply();
  void AllToGui(bool togui);
  void CargoToGui(bool togui);
  void EditorToGui(bool togui);
  void BuildToGui(bool togui);
  ride::BuildSetting* GetSelectedBuildSetting();

 protected:
  void OnlyAllowNumberChars(wxKeyEvent& event);
  void OnTabWdithChanged(wxCommandEvent& event);
  void OnEditorUseTabsClicked(wxCommandEvent& event);

  void OnBuildConfiguration(wxCommandEvent& event);
  void OnBuildConfigurationModify(wxCommandEvent& event);
  void OnBuildCheckbox(wxCommandEvent& event);
  void OnBuildText(wxCommandEvent& event);
  void OnBuildTargetHelp(wxCommandEvent& event);
  void OnBuildCustomArgHelp(wxCommandEvent& event);

  void OnBuildFeatureAdd(wxCommandEvent& event);
  void OnBuildFeatureEdit(wxCommandEvent& event);
  void OnBuildFeatureRemove(wxCommandEvent& event);
  void OnBuildFeatureUp(wxCommandEvent& event);
  void OnBuildFeatureDown(wxCommandEvent& event);

 protected:
  Cargo cargo_;

 private:
  MainWindow* main_window_;
  Project* project_;
  ride::Project project_backup_;
  bool allow_editor_to_gui_;
  bool allow_build_to_gui_;
};

void DoProjectSettingsDlg(wxWindow* parent, MainWindow* mainwindow,
                          Project* project) {
  ProjectSettingsDlg dlg(parent, mainwindow, project);
  dlg.ShowModal();
}

bool LoadCargoFile(const wxString& cargo_file, Cargo* cargo,
                   wxStaticText* error_display) {
  if (cargo_file.IsEmpty()) {
    error_display->SetLabelText("No project loaded");
    return false;
  }
  const auto result = cargo->Load(cargo_file);
  if (result.IsOk()) {
    error_display->SetLabelText("");
    return true;
  }

  error_display->SetLabelText(result.message());
  return false;
}

ProjectSettingsDlg::ProjectSettingsDlg(wxWindow* parent, MainWindow* mainwindow,
                                       Project* project)
    : ::ui::ProjectSettings(parent, wxID_ANY),
      main_window_(mainwindow),
      project_(project),
      project_backup_(project->project()),
      allow_editor_to_gui_(true),
      allow_build_to_gui_(true) {
  LoadCargoFile(project_->GetCargoFile(), &cargo_, uiCargoLoadError);

  AllToGui(true);

  // disable all cargo related gui as we can't save toml files yet
  EnableDisable(false) << uiCargoName << uiCargoVersion;
  // we can't select or scroll in disabled listboxes
  // so lets keep them enabled since we can't really do anything in them
  // << uiCargoAuthors
  // << uiCargoDependencies

  SetImageAndRemoveText(uiBuildConfigurationTargetHelp, wxART_HELP);
  SetImageAndRemoveText(uiBuildConfigurationCustomArgsHelp, wxART_TIP);
  SetImageAndRemoveText(uiBuildFeatureAdd, wxART_NEW);
  SetImageAndRemoveText(uiBuildFeatureRemove, wxART_DELETE);
  SetImageAndRemoveText(uiBuildFeatureEdit, image::edit_xpm);
  SetImageAndRemoveText(uiBuildFeatureUp, wxART_GO_UP);
  SetImageAndRemoveText(uiBuildFeatureDown, wxART_GO_DOWN);
}

void ProjectSettingsDlg::OnApply(wxCommandEvent& event) { Apply(); }

void ProjectSettingsDlg::OnCancel(wxCommandEvent& event) {
  project_->set_project(project_backup_);
  EditorToGui(true);
  EndModal(wxCANCEL);
}

void ProjectSettingsDlg::OnOk(wxCommandEvent& event) {
  if (Apply()) {
    EndModal(wxOK);
  }
}

void ProjectSettingsDlg::AllToGui(bool togui) {
  CargoToGui(togui);
  EditorToGui(togui);
  BuildToGui(togui);
}

//////////////////////////////////////////////////////////////////////////

bool ProjectSettingsDlg::Apply() {
  AllToGui(false);
  project_backup_ = project_->project();

  return true;
}

//////////////////////////////////////////////////////////////////////////

void ProjectSettingsDlg::CargoToGui(bool togui) {
  DIALOG_DATA(cargo_, name, uiCargoName, _Str);
  DIALOG_DATA(cargo_, version, uiCargoVersion, _Str);
  DIALOG_DATA(cargo_, authors, uiCargoAuthors, _Content);
  DIALOG_DATA(cargo_, dependencies, uiCargoDependencies, _Content);
  DIALOG_DATA(cargo_, features, uiCargoFeatures, _Content);
}

//////////////////////////////////////////////////////////////////////////

void ProjectSettingsDlg::EditorToGui(bool togui) {
  if (allow_editor_to_gui_ == false) return;
  allow_editor_to_gui_ = false;
  ride::Project& project = *project_->project_ptr();
  DIALOG_DATA(project, tabwidth, uiEditorTabWidth, _I32);
  DIALOG_DATA(project, usetabs, uiEditorUseTabs, );

  if (togui == false) {
    main_window_->ProjectSettingsHasChanged();
    main_window_->ProjectSettingsHasChanged();
  }
  allow_editor_to_gui_ = true;
}

void ProjectSettingsDlg::OnlyAllowNumberChars(wxKeyEvent& event) {
  ::OnlyAllowNumberChars(event);
}
void ProjectSettingsDlg::OnTabWdithChanged(wxCommandEvent& event) {
  EditorToGui(false);
}
void ProjectSettingsDlg::OnEditorUseTabsClicked(wxCommandEvent& event) {
  EditorToGui(false);
}

//////////////////////////////////////////////////////////////////////////

void ProjectSettingsDlg::OnBuildConfiguration(wxCommandEvent& event) {
  BuildToGui(true);
}

void ProjectSettingsDlg::OnBuildConfigurationModify(wxCommandEvent& event) {
  // todo
}

void ProjectSettingsDlg::OnBuildCheckbox(wxCommandEvent& event) {
  BuildToGui(false);
}

void ProjectSettingsDlg::OnBuildText(wxCommandEvent& event) {
  BuildToGui(false);
}

void ProjectSettingsDlg::OnBuildTargetHelp(wxCommandEvent& event) {
  ShowInfo(this, "this is a build target info", "info");
}

void ProjectSettingsDlg::OnBuildCustomArgHelp(wxCommandEvent& event) {
  ShowInfo(this, "this is a custom argument info", "info");
}

void ProjectSettingsDlg::BuildToGui(bool togui) {
  if (togui && static_cast<wxItemContainer*>(uiBuildConfiguration)->IsEmpty()) {
    for (int i = 0; i < project_->project().build_settings_size(); ++i) {
      ride::BuildSetting* bs =
          project_->project_ptr()->mutable_build_settings(i);
      uiBuildConfiguration->Append(bs->name().c_str(),
                                   reinterpret_cast<void*>(bs));
    }
  }

  ride::BuildSetting* setting_ptr = GetSelectedBuildSetting();
  EnableDisable(setting_ptr != NULL)
      << uiBuildConfigurationRelease << uiBuildConfigurationDefaultFeatures
      << uiBuildConfigurationVerbose << uiBuildConfigurationTarget
      << uiBuildConfigurationTargetHelp << uiBuildConfigurationCustomArgs
      << uiBuildConfigurationCustomArgsHelp << uiBuildFeatures
      << uiBuildFeatureAdd << uiBuildFeatureRemove << uiBuildFeatureUp
      << uiBuildFeatureDown << uiBuildFeatureEdit;

  if (setting_ptr == NULL) return;

  ride::BuildSetting& setting = *setting_ptr;

  DIALOG_DATA(setting, release, uiBuildConfigurationRelease, );
  DIALOG_DATA(setting, default_features, uiBuildConfigurationDefaultFeatures, );
  DIALOG_DATA(setting, verbose, uiBuildConfigurationVerbose, );

  DIALOG_DATA(setting, target, uiBuildConfigurationTarget, _Str);
  DIALOG_DATA(setting, custom_arguments, uiBuildConfigurationCustomArgs, _Str);

  if (togui) {
    int selection = uiBuildFeatures->GetSelection();
    uiBuildFeatures->Clear();
    for (int i = 0; i < setting.features_size(); ++i) {
      uiBuildFeatures->AppendString(setting.features(i));
    }
    if (setting.features_size() > 0) {
      uiBuildFeatures->SetSelection(selection);
    }
  }
}

ride::BuildSetting* ProjectSettingsDlg::GetSelectedBuildSetting() {
  const int selection = uiBuildConfiguration->GetSelection();
  const bool found = selection != wxNOT_FOUND;

  if (!found) return NULL;
  void* d = uiBuildConfiguration->GetClientData(selection);
  ride::BuildSetting* setting = reinterpret_cast<ride::BuildSetting*>(d);

  return setting;
}

void ProjectSettingsDlg::OnBuildFeatureAdd(wxCommandEvent& event) {
  ride::BuildSetting* build = GetSelectedBuildSetting();
  if (build == NULL) return;
  wxTextEntryDialog entry(this, "Feature name");
  if (entry.ShowModal() != wxID_OK) return;
  std::string* new_feature = build->add_features();
  *new_feature = entry.GetValue().c_str();
  BuildToGui(true);
}

void ProjectSettingsDlg::OnBuildFeatureEdit(wxCommandEvent& event) {
  ride::BuildSetting* build = GetSelectedBuildSetting();
  if (build == NULL) return;

  const int selection = uiBuildFeatures->GetSelection();
  if (selection == -1) return;

  wxTextEntryDialog entry(this, "New feature name");
  entry.SetValue(build->features(selection));
  if (entry.ShowModal() != wxID_OK) return;
  build->set_features(selection, entry.GetValue().c_str());
  BuildToGui(true);
}

void ProjectSettingsDlg::OnBuildFeatureRemove(wxCommandEvent& event) {
  ride::BuildSetting* build = GetSelectedBuildSetting();
  if (build == NULL) return;

  const int selection = uiBuildFeatures->GetSelection();
  if (selection == -1) return;

  build->mutable_features()->DeleteSubrange(selection, 1);

  // move back one
  int new_selection = selection - 1;
  // if there aren't a selection and there are more items, select the first one
  if (new_selection == -1 && build->features_size() > 0) new_selection = 0;
  uiBuildFeatures->SetSelection(new_selection);

  BuildToGui(true);
}

void ProjectSettingsDlg::OnBuildFeatureUp(wxCommandEvent& event) {
  event.Skip();
}

void ProjectSettingsDlg::OnBuildFeatureDown(wxCommandEvent& event) {
  event.Skip();
}
