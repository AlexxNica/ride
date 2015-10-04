/////////////////////////////////////////////////////////////////////////////
// Name:        switcherdlg.h
// Purpose:     Pane switcher dialog
// Author:      Julian Smart
// Modified by:
// Created:     2007-08-19
// RCS-ID:      $Id: switcherdlg.h,v 1.3 2007/08/20 17:38:24 anthemion Exp $
// Copyright:   (c) Julian Smart
// Licence:     wxWidgets licence
/////////////////////////////////////////////////////////////////////////////

#ifndef RIDE_SWITCHERDLG_H_
#define RIDE_SWITCHERDLG_H_

#include <ride/wx.h>
#include <wx/html/htmlwin.h>

#include <vector>

#include "ride/switcheritem.h"
#include "ride/switcheritemlist.h"
#include "ride/switcherctrl.h"

/*!
 * wxSwitcherDialog shows a wxMultiColumnListCtrl with a list of panes
 * and tabs for the user to choose. Ctrl+Tab cycles through them.
 */

class SwitcherDialog : public wxDialog {
 public:
  // constructors and destructors
  SwitcherDialog() {
    BindEvents();
    Init();
  }
  SwitcherDialog(const SwitcherItemList& items, wxWindow* parent,
                 wxWindowID id = -1, const wxString& title = _("Pane Switcher"),
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style  // NOLINT
                 = wxSTAY_ON_TOP | wxDIALOG_NO_PARENT | wxBORDER_SIMPLE);

  bool Create(const SwitcherItemList& items, wxWindow* parent,
              wxWindowID id = -1, const wxString& title = _("Pane Switcher"),
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              long style  // NOLINT
              = wxSTAY_ON_TOP | wxDIALOG_NO_PARENT | wxBORDER_SIMPLE);

  void Init();
  void BindEvents();

  void OnCloseWindow(wxCloseEvent& event);
  void OnActivate(wxActivateEvent& event);
  void OnSelectItem(wxCommandEvent& event);
  void OnPaint(wxPaintEvent& event);

  // Get the selected item
  int GetSelection() const;

  void ShowDescription(int i);

  void SetBorderColour(const wxColour& colour) { border_color_ = colour; }

  // Set an extra key that can be used to cycle through items,
  // in case not using the Ctrl+Tab combination
  void SetExtraNavigationKey(int keyCode);
  int GetExtraNavigationKey() const { return extra_navigation_key_; }

  // Set the modifier used to invoke the dialog, and therefore to test for
  // release
  void SetModifierKey(int modifierKey);
  int GetModifierKey() const { return modifier_key_; }

 private:
  SwitcherCtrl* list_ctrl_;
  wxHtmlWindow* description_ctrl_;
  bool is_closing_;
  long switcher_border_style_;  // NOLINT
  wxColour border_color_;
  int extra_navigation_key_;
  int modifier_key_;
};

#endif  // RIDE_SWITCHERDLG_H_
