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

#ifndef RIDE_SWITCHERITEMLIST_H_
#define RIDE_SWITCHERITEMLIST_H_

#include <ride/wx.h>
#include <wx/html/htmlwin.h>

#include <vector>

#include "ride/switcheritem.h"

/*!
 * wxSwitcherItems
 * An object containing switcher items
 */

class SwitcherItemList : public wxObject {
  DECLARE_CLASS(SwitcherItemList)

 public:
  SwitcherItemList() { Init(); }
  SwitcherItemList(const SwitcherItemList& items) {
    Init();
    Copy(items);
  }

  bool operator==(const SwitcherItemList& items) const;

  void operator=(const SwitcherItemList& items) { Copy(items); }

  void Init();

  void Copy(const SwitcherItemList& items);

  // Public API

  SwitcherItem& AddItem(const wxString& title, const wxString& name, int id = 0,
                        const wxBitmap& bitmap = wxNullBitmap);
  SwitcherItem& AddItem(const SwitcherItem& item);
  SwitcherItem& AddGroup(const wxString& title, const wxString& name,
                         int id = 0, const wxBitmap& bitmap = wxNullBitmap);

  void Clear();

  int FindItemByName(const wxString& name) const;
  int FindItemById(int id) const;

  void set_selection(int sel);
  void SelectByName(const wxString& name);  // by name
  int selection() const { return selection_; }

  // Find the index for the item associated with the current focus
  int GetIndexForFocus() const;

  // Hit test, returning an index or -1
  int HitTest(const wxPoint& pt) const;

  const SwitcherItem& GetItem(int i) const;
  SwitcherItem& GetItem(int i);

  int GetItemCount() const { return items_.size(); }

  void set_row_count(int rows) { row_count_ = rows; }
  int row_count() const { return row_count_; }

  void set_column_count(int cols) { column_count_ = cols; }
  int column_count() const { return column_count_; }

  void set_background_color(const wxColour& colour) {
    background_color_ = colour;
  }
  const wxColour& background_color() const { return background_color_; }

  void set_text_color(const wxColour& colour) { text_color_ = colour; }
  const wxColour& text_color() const { return text_color_; }

  void set_selection_color(const wxColour& colour) {
    selection_color_ = colour;
  }
  const wxColour& selection_color() const { return selection_color_; }

  void set_selection_outline_color(const wxColour& colour) {
    selection_outline_color_ = colour;
  }
  const wxColour& selection_outline_color() const {
    return selection_outline_color_;
  }

  void set_item_font(const wxFont& font) { item_font_ = font; }
  const wxFont& item_font() const { return item_font_; }

  // Implementation

  void PaintItems(wxDC& dc, wxWindow* win);  // NOLINT
  wxSize CalculateItemSize(wxDC& dc);        // NOLINT

 protected:
  std::vector<SwitcherItem> items_;
  int selection_;
  int row_count_;
  int column_count_;

  wxColour background_color_;
  wxColour text_color_;
  wxColour selection_color_;
  wxColour selection_outline_color_;

  wxFont item_font_;
};

#endif  // RIDE_SWITCHERITEMLIST_H_
