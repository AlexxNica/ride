#ifndef RIDE_FILEEDIT_H
#define RIDE_FILEEDIT_H

#include "ride/wx.h"
#include <wx/stc/stc.h>

class wxAuiNotebook;
class MainWindow;
class CompilerMessage;

class FileEdit : public wxControl {
public:
  FileEdit(wxAuiNotebook* anotebook, MainWindow* parent, const wxString& source, const wxString& file);
  const wxString& filename() const;
  void SetSelection(int start_line, int start_index, int end_line, int end_index);
  void AddCompilerMessage(const CompilerMessage& mess);
  void ClearCompilerMessages();
  void Focus();

public:
  bool Save();
  bool SaveAs();
  void Undo();
  void Redo();
  void Cut();
  void Copy();
  void Paste();
  void Duplicate();
  void Delete();
  void Find();
  void Replace();
  void MatchBrace();
  void SelectBrace();
  void GotoLine();
  void Indent();
  void UnIndent();
  void SelectAll();
  void SelectLine();
  void ToUpper();
  void ToLower();
  void MoveLinesUp();
  void MoveLinesDown();
  void ShowProperties();

public:
  bool CanClose(bool canAbort);

  /** Event callback when a margin is clicked, used here for code folding */
  void OnMarginClick(wxStyledTextEvent& event);
  void OnCharAdded(wxStyledTextEvent& event);
  void OnUpdateUi(wxStyledTextEvent& event);
  void OnChanged(wxStyledTextEvent& event);

  void UpdateTextControl();

  ~FileEdit();
private:
  void UpdateFilename();
  void UpdateTitle();
  bool SaveTo(const wxString& target);

  bool ShouldBeSaved();
  void HighlightCurrentWord();

  wxString CalculateDocumentName() const;

private:
  MainWindow* main_;
  wxStyledTextCtrl* text_;
  wxAuiNotebook* notebook_;
  wxString filename_;

  Language* current_language_;

  int highlight_current_word_last_start_position_;
  int highlight_current_word_last_end_position_;

private:
  wxDECLARE_EVENT_TABLE();
};

void SetupScintilla(wxStyledTextCtrl* text_ctrl, const ride::Settings& set, Language* language);

void SetupScintillaCurrentLine(wxStyledTextCtrl* text_ctrl, const ride::Settings& set);
void SetupScintillaDefaultStyles(wxStyledTextCtrl* text_ctrl, const ride::Settings& set);

#endif  // RIDE_FILEEDIT_H
