#ifndef RIDE_WXUTILS_H
#define RIDE_WXUTILS_H

#include <wx/gdicmn.h>
#include <wx/string.h>
#include <vector>
#include <wx/msgdlg.h>

class wxContextMenuEvent;
class wxMenu;
class wxWindow;

wxPoint GetContextEventPosition(const wxContextMenuEvent& event);
void AppendEnabled(wxMenu& menu, int id, const wxString& text, bool enabled);
std::vector<wxString> Split(const wxString& str, char c);

enum class DialogResult {
  YES, NO, CANCEL
};

DialogResult ShowYesNo(wxWindow* self, const wxString& caption,
  const wxMessageDialogBase::ButtonLabel& yes_button,
  const wxMessageDialogBase::ButtonLabel& no_button,
  const wxString& title_ok, const wxString title_error);

DialogResult ShowYesNoCancel(wxWindow* self, const wxString& caption,
  const wxMessageDialogBase::ButtonLabel& yes_button,
  const wxMessageDialogBase::ButtonLabel& no_button,
  const wxMessageDialogBase::ButtonLabel& cancel_button,
  const wxString& title_ok, const wxString title_error);

void ShowInfo(wxWindow* self, const wxString& message, const wxString& title);
void ShowWarning(wxWindow* self, const wxString& message, const wxString& title);
void ShowError(wxWindow* self, const wxString& message, const wxString& title);

#endif  // RIDE_WXUTILS_H