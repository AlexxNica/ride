#include "ride/settingsdlg.h"
#include "ride/mainwindow.h"

SettingsDlg::SettingsDlg(wxWindow* parent, MainWindow* mainwindow) :
::ui::Settings(parent, wxID_ANY), main(mainwindow)
{
}

void SettingsDlg::OnApply( wxCommandEvent& event )
{
  editToGui(false);
  main->setSettings(edit);
}

void SettingsDlg::OnCancel( wxCommandEvent& event )
{
  main->setSettings(global);
  main->hideSettingsDlg();
}

void SettingsDlg::PrepareForShow() {
  global = main->getSettings();
  edit = global;
  editToGui(true);
}

void SettingsDlg::OnOk( wxCommandEvent& event )
{
  editToGui(false);
  main->setSettings(edit);
  edit.save();
  main->hideSettingsDlg();
}

void DoIt(bool& data, wxCheckBox* gui, bool togui)  {
  if (togui) {
    gui->SetValue(data);
  }
  else {
    data = gui->GetValue();
  }
}

void SettingsDlg::editToGui(bool togui) {
  DoIt(edit.displayEOLEnable, uiDisplayEOL, togui);
  DoIt(edit.lineNumberEnable, uiShowLineNumbers, togui);
  DoIt(edit.indentGuideEnable, uiIndentGuide, togui);
}

