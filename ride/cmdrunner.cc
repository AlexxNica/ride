#include "ride/cmdrunner.h"

CmdRunner::CmdRunner() {
}

void CmdRunner::Append(const wxString& str) {
  output += "\n" + str;
}

const bool CmdRunner::Run(const wxString& root, const wxString& cmd, wxString* out) {
  assert(out);
  CmdRunner runner;
  if (false == runner.RunCmd(Command(root, cmd))) {
    *out = "Unable to start";
    return false;
  }
  while (runner.IsRunning()) {
    // wait...
    wxYield();
  }
  const int result = runner.GetExitCode();
  *out = runner.output;
  return result == 0;
}
