#include "ride/wx.h"
#include "ride/settings.h"

#include <wx/filename.h>
#include <wx/stdpaths.h>
#include <fstream>

wxString GetConfigFolder() {
  return wxStandardPaths::Get().GetUserDataDir();
}

wxFileName GetConfigFile() {
  return wxFileName(GetConfigFolder(), "settings", "data");
}

void LoadSettings(::ride::Settings& settings) {
  const wxFileName confPath = GetConfigFile();
  const wxString path = confPath.GetFullPath();
  if (confPath.IsFileReadable()) {
    std::fstream input(path.c_str().AsChar(), std::ios::in | std::ios::binary);
    const bool parse_result = settings.ParseFromIstream(&input);
    if (false == parse_result) {
      wxMessageBox("Unable to parse settings file!", "Error", wxOK | wxICON_WARNING);
    }
  }
}

bool SaveSettings(::ride::Settings& settings) {
  const wxFileName config_file = GetConfigFile();
  const bool create_result = config_file.Mkdir(wxS_DIR_DEFAULT, wxPATH_MKDIR_FULL);
  if (config_file.FileExists() && config_file.IsFileWritable() == false) {
    // abort if the file exist and isn't writable
    return false;
  }
  const wxString config_path = config_file.GetFullPath();
  std::fstream config_stream(config_path.c_str().AsChar(), std::ios::out | std::ios::trunc | std::ios::binary);
  return settings.SerializeToOstream(&config_stream);
}

wxColor C(const ride::Color& c) {
  return wxColor(c.r(), c.g(), c.b());
}

ride::Color C(const wxColor& c) {
  ride::Color r;
  r.set_r(c.Red());
  r.set_g(c.Green());
  r.set_b(c.Blue());
  return r;
}
