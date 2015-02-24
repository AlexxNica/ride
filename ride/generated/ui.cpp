///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ride/wx.h"

#include "ui.h"

///////////////////////////////////////////////////////////////////////////
using namespace ui;

Settings::Settings( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,500 ), wxDefaultSize );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_fonts = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer6->AddGrowableCol( 0 );
	fgSizer6->AddGrowableCol( 1 );
	fgSizer6->AddGrowableRow( 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_panel9 = new wxPanel( m_fonts, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( m_panel9, wxID_ANY, wxT("Styles") ), wxVERTICAL );
	
	uiFontStyles = new wxListBox( m_panel9, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	sbSizer3->Add( uiFontStyles, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer5->Add( sbSizer3, 1, wxEXPAND, 5 );
	
	
	m_panel9->SetSizer( bSizer5 );
	m_panel9->Layout();
	bSizer5->Fit( m_panel9 );
	fgSizer6->Add( m_panel9, 1, wxEXPAND | wxALL, 5 );
	
	m_panel7 = new wxPanel( m_fonts, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer2;
	gbSizer2 = new wxGridBagSizer( 0, 0 );
	gbSizer2->SetFlexibleDirection( wxBOTH );
	gbSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( m_panel7, wxID_ANY, wxT("Typefaces") ), wxVERTICAL );
	
	uiStyleUseTypeface = new wxCheckBox( m_panel7, wxID_ANY, wxT("Use typeface?"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( uiStyleUseTypeface, 0, wxALL, 5 );
	
	uiStyleOnlyFixedSize = new wxCheckBox( m_panel7, wxID_ANY, wxT("Only fixed sizes"), wxDefaultPosition, wxDefaultSize, 0 );
	uiStyleOnlyFixedSize->SetValue(true); 
	sbSizer2->Add( uiStyleOnlyFixedSize, 0, wxALL, 5 );
	
	uiStyleTypeface = new wxListBox( m_panel7, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	sbSizer2->Add( uiStyleTypeface, 1, wxALL|wxEXPAND, 5 );
	
	
	gbSizer2->Add( sbSizer2, wxGBPosition( 0, 0 ), wxGBSpan( 1, 2 ), wxEXPAND, 5 );
	
	uiStyleBold = new wxCheckBox( m_panel7, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( uiStyleBold, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	uiStyleUseBold = new wxCheckBox( m_panel7, wxID_ANY, wxT("Bold:"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( uiStyleUseBold, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	uiStyleItalic = new wxCheckBox( m_panel7, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( uiStyleItalic, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALIGN_LEFT|wxALL, 5 );
	
	uiStyleUseItalic = new wxCheckBox( m_panel7, wxID_ANY, wxT("Italic"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( uiStyleUseItalic, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	uiStyleUnderline = new wxCheckBox( m_panel7, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( uiStyleUnderline, wxGBPosition( 3, 1 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );
	
	uiStyleUseUnderline = new wxCheckBox( m_panel7, wxID_ANY, wxT("Underline:"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( uiStyleUseUnderline, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	uiStyleSize = new wxTextCtrl( m_panel7, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( uiStyleSize, wxGBPosition( 4, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	uiStyleUseSize = new wxCheckBox( m_panel7, wxID_ANY, wxT("Font size:"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( uiStyleUseSize, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	uiStyleForeground = new wxColourPickerCtrl( m_panel7, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	gbSizer2->Add( uiStyleForeground, wxGBPosition( 5, 1 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	uiStyleUseForeground = new wxCheckBox( m_panel7, wxID_ANY, wxT("Foreground:"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( uiStyleUseForeground, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	uiStyleBackground = new wxColourPickerCtrl( m_panel7, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	gbSizer2->Add( uiStyleBackground, wxGBPosition( 6, 1 ), wxGBSpan( 1, 1 ), wxALL|wxEXPAND, 5 );
	
	uiStyleUseBackground = new wxCheckBox( m_panel7, wxID_ANY, wxT("Background:"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( uiStyleUseBackground, wxGBPosition( 6, 0 ), wxGBSpan( 1, 1 ), wxALIGN_RIGHT|wxALL, 5 );
	
	uiStyleExample = new wxTextCtrl( m_panel7, wxID_ANY, wxT("Sample text"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( uiStyleExample, wxGBPosition( 7, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer2->AddGrowableCol( 0 );
	gbSizer2->AddGrowableRow( 0 );
	
	m_panel7->SetSizer( gbSizer2 );
	m_panel7->Layout();
	gbSizer2->Fit( m_panel7 );
	fgSizer6->Add( m_panel7, 1, wxALL|wxEXPAND, 5 );
	
	
	m_fonts->SetSizer( fgSizer6 );
	m_fonts->Layout();
	fgSizer6->Fit( m_fonts );
	m_notebook1->AddPage( m_fonts, wxT("Fonts && Colors"), false );
	m_indicators = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer7->AddGrowableCol( 0 );
	fgSizer7->AddGrowableRow( 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	uiIndicatorList = new wxListBox( m_indicators, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer6->Add( uiIndicatorList, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer7->Add( bSizer6, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	uiIndicatorStyleLabel = new wxStaticText( m_indicators, wxID_ANY, wxT("Style:"), wxDefaultPosition, wxDefaultSize, 0 );
	uiIndicatorStyleLabel->Wrap( -1 );
	fgSizer8->Add( uiIndicatorStyleLabel, 0, wxALL, 5 );
	
	uiIndicatorStyle = new wxComboBox( m_indicators, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY );
	uiIndicatorStyle->Append( wxT("Plain") );
	uiIndicatorStyle->Append( wxT("Squiggle") );
	uiIndicatorStyle->Append( wxT("TT") );
	uiIndicatorStyle->Append( wxT("Diagonal") );
	uiIndicatorStyle->Append( wxT("Strike") );
	uiIndicatorStyle->Append( wxT("Hidden") );
	uiIndicatorStyle->Append( wxT("Box") );
	uiIndicatorStyle->Append( wxT("Roundbox") );
	uiIndicatorStyle->Append( wxT("Straight box") );
	uiIndicatorStyle->Append( wxT("Dash") );
	uiIndicatorStyle->Append( wxT("Dots") );
	uiIndicatorStyle->Append( wxT("Squiggle low") );
	uiIndicatorStyle->Append( wxT("Dotbox") );
	uiIndicatorStyle->Append( wxEmptyString );
	uiIndicatorStyle->Append( wxEmptyString );
	uiIndicatorStyle->Append( wxEmptyString );
	uiIndicatorStyle->Append( wxEmptyString );
	uiIndicatorStyle->Append( wxEmptyString );
	fgSizer8->Add( uiIndicatorStyle, 0, wxALL, 5 );
	
	m_staticText11 = new wxStaticText( m_indicators, wxID_ANY, wxT("Color:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	fgSizer8->Add( m_staticText11, 0, wxALL, 5 );
	
	uiIndicatorColor = new wxColourPickerCtrl( m_indicators, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer8->Add( uiIndicatorColor, 0, wxALL, 5 );
	
	
	fgSizer8->Add( 0, 0, 1, wxEXPAND, 5 );
	
	uiIndicatorUnder = new wxCheckBox( m_indicators, wxID_ANY, wxT("Under?"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( uiIndicatorUnder, 0, wxALL, 5 );
	
	m_staticText12 = new wxStaticText( m_indicators, wxID_ANY, wxT("Alpha:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	fgSizer8->Add( m_staticText12, 0, wxALL, 5 );
	
	uiIndicatorAlpha = new wxTextCtrl( m_indicators, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( uiIndicatorAlpha, 0, wxALL, 5 );
	
	m_staticText13 = new wxStaticText( m_indicators, wxID_ANY, wxT("Outline alpha:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	fgSizer8->Add( m_staticText13, 0, wxALL, 5 );
	
	uiIndicatorOutlineAlpha = new wxTextCtrl( m_indicators, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( uiIndicatorOutlineAlpha, 0, wxALL, 5 );
	
	
	fgSizer7->Add( fgSizer8, 1, wxEXPAND, 5 );
	
	
	m_indicators->SetSizer( fgSizer7 );
	m_indicators->Layout();
	fgSizer7->Fit( m_indicators );
	m_notebook1->AddPage( m_indicators, wxT("Indicators"), false );
	m_markers = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer51;
	fgSizer51 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer51->AddGrowableCol( 0 );
	fgSizer51->AddGrowableRow( 0 );
	fgSizer51->SetFlexibleDirection( wxBOTH );
	fgSizer51->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );
	
	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( m_markers, wxID_ANY, wxT("Markers") ), wxVERTICAL );
	
	uiMarkerList = new wxListBox( m_markers, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	sbSizer8->Add( uiMarkerList, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer51->Add( sbSizer8, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer61;
	fgSizer61 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer61->SetFlexibleDirection( wxBOTH );
	fgSizer61->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText7 = new wxStaticText( m_markers, wxID_ANY, wxT("Symbol:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer61->Add( m_staticText7, 0, wxALL, 5 );
	
	uiMarkerSymbol = new wxComboBox( m_markers, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY );
	uiMarkerSymbol->Append( wxT("Circle") );
	uiMarkerSymbol->Append( wxT("Roundrect ") );
	uiMarkerSymbol->Append( wxT("Arrow") );
	uiMarkerSymbol->Append( wxT("Smallrect ") );
	uiMarkerSymbol->Append( wxT("Shortarrow") );
	uiMarkerSymbol->Append( wxT("Empty") );
	uiMarkerSymbol->Append( wxT("Arrowdown ") );
	uiMarkerSymbol->Append( wxT("Minus") );
	uiMarkerSymbol->Append( wxT("Plus") );
	uiMarkerSymbol->Append( wxEmptyString );
	uiMarkerSymbol->Append( wxEmptyString );
	fgSizer61->Add( uiMarkerSymbol, 0, wxALL, 5 );
	
	m_staticText9 = new wxStaticText( m_markers, wxID_ANY, wxT("Foreground color:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer61->Add( m_staticText9, 0, wxALL, 5 );
	
	uiMarkerForegroundColor = new wxColourPickerCtrl( m_markers, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer61->Add( uiMarkerForegroundColor, 0, wxALL, 5 );
	
	m_staticText8 = new wxStaticText( m_markers, wxID_ANY, wxT("Background color:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer61->Add( m_staticText8, 0, wxALL, 5 );
	
	uiMarkerBackgroundColor = new wxColourPickerCtrl( m_markers, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer61->Add( uiMarkerBackgroundColor, 0, wxALL, 5 );
	
	
	fgSizer51->Add( fgSizer61, 1, wxEXPAND, 5 );
	
	
	m_markers->SetSizer( fgSizer51 );
	m_markers->Layout();
	fgSizer51->Fit( m_markers );
	m_notebook1->AddPage( m_markers, wxT("Markers"), false );
	m_editor = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook2 = new wxNotebook( m_editor, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel10 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	uiShowLineNumbers = new wxCheckBox( m_panel10, wxID_ANY, wxT("Show line numbers"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( uiShowLineNumbers, 0, wxALL, 5 );
	
	uiDisplayEOL = new wxCheckBox( m_panel10, wxID_ANY, wxT("Display EOL"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( uiDisplayEOL, 0, wxALL, 5 );
	
	uiIndentGuide = new wxCheckBox( m_panel10, wxID_ANY, wxT("Display indent guide"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( uiIndentGuide, 0, wxALL, 5 );
	
	uiViewWhitespace = new wxComboBox( m_panel10, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY );
	uiViewWhitespace->Append( wxT("Hidden") );
	uiViewWhitespace->Append( wxT("Always") );
	uiViewWhitespace->Append( wxT("AfterIdent") );
	fgSizer4->Add( uiViewWhitespace, 0, wxALL, 5 );
	
	uiWordwrap = new wxComboBox( m_panel10, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY );
	uiWordwrap->Append( wxT("None") );
	uiWordwrap->Append( wxT("Char") );
	uiWordwrap->Append( wxT("Word") );
	fgSizer4->Add( uiWordwrap, 0, wxALL, 5 );
	
	uiEdgeStyle = new wxComboBox( m_panel10, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY );
	uiEdgeStyle->Append( wxT("None") );
	uiEdgeStyle->Append( wxT("Line") );
	uiEdgeStyle->Append( wxT("Background") );
	fgSizer4->Add( uiEdgeStyle, 0, wxALL, 5 );
	
	uiEdgeColor = new wxColourPickerCtrl( m_panel10, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer4->Add( uiEdgeColor, 0, wxALL, 5 );
	
	uiEdgeColumn = new wxTextCtrl( m_panel10, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( uiEdgeColumn, 0, wxALL, 5 );
	
	uiTabWidth = new wxTextCtrl( m_panel10, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( uiTabWidth, 0, wxALL, 5 );
	
	uiUseTabs = new wxCheckBox( m_panel10, wxID_ANY, wxT("Use tabs"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( uiUseTabs, 0, wxALL, 5 );
	
	uiTabIndents = new wxCheckBox( m_panel10, wxID_ANY, wxT("Tab indents"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( uiTabIndents, 0, wxALL, 5 );
	
	uiBackspaceUnindents = new wxCheckBox( m_panel10, wxID_ANY, wxT("Bacspace unindents"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( uiBackspaceUnindents, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizerFolding;
	sbSizerFolding = new wxStaticBoxSizer( new wxStaticBox( m_panel10, wxID_ANY, wxT("Folding") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	uiAllowFolding = new wxCheckBox( m_panel10, wxID_ANY, wxT("Allow folding"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( uiAllowFolding, 0, wxALL, 5 );
	
	uiFoldLevelNumbers = new wxCheckBox( m_panel10, wxID_ANY, wxT("Level numbers"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( uiFoldLevelNumbers, 0, wxALL, 5 );
	
	uiFoldLineBeforeExpanded = new wxCheckBox( m_panel10, wxID_ANY, wxT("Line before (expanded)"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( uiFoldLineBeforeExpanded, 0, wxALL, 5 );
	
	uiFoldLineBeforeContracted = new wxCheckBox( m_panel10, wxID_ANY, wxT("Line before (contracted)"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( uiFoldLineBeforeContracted, 0, wxALL, 5 );
	
	uiFoldLineAfterExpanded = new wxCheckBox( m_panel10, wxID_ANY, wxT("Line after (expanded)"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( uiFoldLineAfterExpanded, 0, wxALL, 5 );
	
	uiFoldLineAfterContracted = new wxCheckBox( m_panel10, wxID_ANY, wxT("Line After (contracted)"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( uiFoldLineAfterContracted, 0, wxALL, 5 );
	
	
	sbSizerFolding->Add( fgSizer5, 1, wxEXPAND, 5 );
	
	
	fgSizer4->Add( sbSizerFolding, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_panel10, wxID_ANY, wxT("Current line") ), wxVERTICAL );
	
	uiEditCurrentLineOverdraw = new wxCheckBox( m_panel10, wxID_ANY, wxT("Overdraw?"), wxDefaultPosition, wxDefaultSize, 0 );
	uiEditCurrentLineOverdraw->SetValue(true); 
	sbSizer4->Add( uiEditCurrentLineOverdraw, 0, wxALL, 5 );
	
	uiEditCurrentLineColor = new wxColourPickerCtrl( m_panel10, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	sbSizer4->Add( uiEditCurrentLineColor, 0, wxALL, 5 );
	
	uiCurrentLineVisible = new wxCheckBox( m_panel10, wxID_ANY, wxT("Show current line?"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( uiCurrentLineVisible, 0, wxALL, 5 );
	
	uiEditCurrentLineAlpha = new wxTextCtrl( m_panel10, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( uiEditCurrentLineAlpha, 0, wxALL, 5 );
	
	
	fgSizer4->Add( sbSizer4, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panel10, wxID_ANY, wxT("Fold colors") ), wxHORIZONTAL );
	
	uiEditFoldHi = new wxColourPickerCtrl( m_panel10, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	sbSizer5->Add( uiEditFoldHi, 0, wxALL, 5 );
	
	uiEditFoldLow = new wxColourPickerCtrl( m_panel10, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	sbSizer5->Add( uiEditFoldLow, 0, wxALL, 5 );
	
	
	fgSizer4->Add( sbSizer5, 1, wxEXPAND, 5 );
	
	uiEditHighlightKeyword = new wxCheckBox( m_panel10, wxID_ANY, wxT("Auto highlight keywords"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( uiEditHighlightKeyword, 0, wxALL, 5 );
	
	uiEditIndentation = new wxComboBox( m_panel10, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY );
	uiEditIndentation->Append( wxT("None") );
	uiEditIndentation->Append( wxT("Keep") );
	uiEditIndentation->Append( wxT("Smart") );
	fgSizer4->Add( uiEditIndentation, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panel10, wxID_ANY, wxT("Auto completion") ), wxVERTICAL );
	
	uiEditAutocompleteCurlyBraces = new wxCheckBox( m_panel10, wxID_ANY, wxT("Curly braces"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( uiEditAutocompleteCurlyBraces, 0, wxALL, 5 );
	
	uiEditAutocompleteParentheses = new wxCheckBox( m_panel10, wxID_ANY, wxT("Parentheses"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( uiEditAutocompleteParentheses, 0, wxALL, 5 );
	
	uiEditAutocompleteBrackets = new wxCheckBox( m_panel10, wxID_ANY, wxT("Brackets"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( uiEditAutocompleteBrackets, 0, wxALL, 5 );
	
	
	fgSizer4->Add( sbSizer9, 1, wxEXPAND, 5 );
	
	uiEditShowMultilineIndicators = new wxCheckBox( m_panel10, wxID_ANY, wxT("Show multiline warning/errors"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( uiEditShowMultilineIndicators, 0, wxALL, 5 );
	
	uiEditShowCompilerAnnotations = new wxCheckBox( m_panel10, wxID_ANY, wxT("Show warning/errors as annotations"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( uiEditShowCompilerAnnotations, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer81;
	sbSizer81 = new wxStaticBoxSizer( new wxStaticBox( m_panel10, wxID_ANY, wxT("Selection") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	uiEditUseSelectionForeground = new wxCheckBox( m_panel10, wxID_ANY, wxT("Foreground:"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( uiEditUseSelectionForeground, 0, wxALL, 5 );
	
	uiEditSelectionForeground = new wxColourPickerCtrl( m_panel10, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer9->Add( uiEditSelectionForeground, 0, wxALL, 5 );
	
	uiEditUseSelectionBackground = new wxCheckBox( m_panel10, wxID_ANY, wxT("Background:"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( uiEditUseSelectionBackground, 0, wxALL, 5 );
	
	uiEditSelectionBackground = new wxColourPickerCtrl( m_panel10, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	fgSizer9->Add( uiEditSelectionBackground, 0, wxALL, 5 );
	
	
	sbSizer81->Add( fgSizer9, 1, wxEXPAND, 5 );
	
	
	fgSizer4->Add( sbSizer81, 1, wxEXPAND, 5 );
	
	
	m_panel10->SetSizer( fgSizer4 );
	m_panel10->Layout();
	fgSizer4->Fit( m_panel10 );
	m_notebook2->AddPage( m_panel10, wxT("General"), true );
	m_panel11 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook2->AddPage( m_panel11, wxT("C++"), false );
	
	bSizer2->Add( m_notebook2, 1, wxEXPAND | wxALL, 5 );
	
	
	m_editor->SetSizer( bSizer2 );
	m_editor->Layout();
	bSizer2->Fit( m_editor );
	m_notebook1->AddPage( m_editor, wxT("Editor && Feel"), true );
	m_window = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook1->AddPage( m_window, wxT("Window behaviour"), false );
	
	bSizer3->Add( m_notebook1, 1, wxEXPAND | wxALL, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Apply = new wxButton( this, wxID_APPLY );
	m_sdbSizer1->AddButton( m_sdbSizer1Apply );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	m_sdbSizer1->SetMinSize( wxSize( -1,50 ) ); 
	
	bSizer3->Add( m_sdbSizer1, 0, wxEXPAND|wxFIXED_MINSIZE, 5 );
	
	
	this->SetSizer( bSizer3 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	uiFontStyles->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Settings::OnSelectedStyleChanged ), NULL, this );
	uiStyleUseTypeface->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleOnlyFixedSize->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnOnlyFixedSysChanged ), NULL, this );
	uiStyleTypeface->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Settings::OnStyleFontChanged ), NULL, this );
	uiStyleBold->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleUseBold->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleItalic->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleUseItalic->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleUnderline->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleUseUnderline->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleSize->Connect( wxEVT_CHAR, wxKeyEventHandler( Settings::OnlyAllowNumberChars ), NULL, this );
	uiStyleSize->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Settings::OnStyleTextChanged ), NULL, this );
	uiStyleUseSize->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleForeground->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnStyleColorChanged ), NULL, this );
	uiStyleUseForeground->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleBackground->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnStyleColorChanged ), NULL, this );
	uiStyleUseBackground->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiIndicatorList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Settings::OnIndicatorListChanged ), NULL, this );
	uiIndicatorStyle->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Settings::OnIndicatorCombobox ), NULL, this );
	uiIndicatorColor->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnIndicatorColor ), NULL, this );
	uiIndicatorUnder->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnIndicatorCheckbox ), NULL, this );
	uiIndicatorAlpha->Connect( wxEVT_CHAR, wxKeyEventHandler( Settings::OnlyAllowNumberChars ), NULL, this );
	uiIndicatorAlpha->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Settings::OnIndicatorText ), NULL, this );
	uiIndicatorOutlineAlpha->Connect( wxEVT_CHAR, wxKeyEventHandler( Settings::OnlyAllowNumberChars ), NULL, this );
	uiIndicatorOutlineAlpha->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Settings::OnIndicatorText ), NULL, this );
	uiMarkerList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Settings::OnMarkerListChanged ), NULL, this );
	uiMarkerSymbol->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Settings::OnMarkerComboChanged ), NULL, this );
	uiMarkerForegroundColor->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnMarkerColorChanged ), NULL, this );
	uiMarkerBackgroundColor->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnMarkerComboChanged ), NULL, this );
	uiShowLineNumbers->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiDisplayEOL->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiIndentGuide->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiViewWhitespace->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Settings::OnComboboxChanged ), NULL, this );
	uiWordwrap->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Settings::OnComboboxChanged ), NULL, this );
	uiEdgeStyle->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Settings::OnComboboxChanged ), NULL, this );
	uiEdgeColor->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnColorChanged ), NULL, this );
	uiEdgeColumn->Connect( wxEVT_CHAR, wxKeyEventHandler( Settings::OnlyAllowNumberChars ), NULL, this );
	uiEdgeColumn->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Settings::OnEditChanged ), NULL, this );
	uiTabWidth->Connect( wxEVT_CHAR, wxKeyEventHandler( Settings::OnlyAllowNumberChars ), NULL, this );
	uiTabWidth->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Settings::OnEditChanged ), NULL, this );
	uiUseTabs->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiTabIndents->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiBackspaceUnindents->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiAllowFolding->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiFoldLevelNumbers->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiFoldLineBeforeExpanded->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiFoldLineBeforeContracted->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiFoldLineAfterExpanded->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiFoldLineAfterContracted->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiEditCurrentLineOverdraw->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiEditCurrentLineColor->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnColorChanged ), NULL, this );
	uiCurrentLineVisible->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiEditCurrentLineAlpha->Connect( wxEVT_CHAR, wxKeyEventHandler( Settings::OnlyAllowNumberChars ), NULL, this );
	uiEditCurrentLineAlpha->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Settings::OnEditChanged ), NULL, this );
	uiEditFoldHi->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnColorChanged ), NULL, this );
	uiEditFoldLow->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnColorChanged ), NULL, this );
	uiEditHighlightKeyword->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiEditIndentation->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Settings::OnComboboxChanged ), NULL, this );
	uiEditUseSelectionForeground->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiEditSelectionForeground->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnColorChanged ), NULL, this );
	uiEditUseSelectionBackground->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiEditSelectionBackground->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnColorChanged ), NULL, this );
	m_sdbSizer1Apply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnApply ), NULL, this );
	m_sdbSizer1Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnCancel ), NULL, this );
	m_sdbSizer1OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnOk ), NULL, this );
}

Settings::~Settings()
{
	// Disconnect Events
	uiFontStyles->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Settings::OnSelectedStyleChanged ), NULL, this );
	uiStyleUseTypeface->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleOnlyFixedSize->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnOnlyFixedSysChanged ), NULL, this );
	uiStyleTypeface->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Settings::OnStyleFontChanged ), NULL, this );
	uiStyleBold->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleUseBold->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleItalic->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleUseItalic->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleUnderline->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleUseUnderline->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleSize->Disconnect( wxEVT_CHAR, wxKeyEventHandler( Settings::OnlyAllowNumberChars ), NULL, this );
	uiStyleSize->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Settings::OnStyleTextChanged ), NULL, this );
	uiStyleUseSize->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleForeground->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnStyleColorChanged ), NULL, this );
	uiStyleUseForeground->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiStyleBackground->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnStyleColorChanged ), NULL, this );
	uiStyleUseBackground->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnStyleCheckChanged ), NULL, this );
	uiIndicatorList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Settings::OnIndicatorListChanged ), NULL, this );
	uiIndicatorStyle->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Settings::OnIndicatorCombobox ), NULL, this );
	uiIndicatorColor->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnIndicatorColor ), NULL, this );
	uiIndicatorUnder->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnIndicatorCheckbox ), NULL, this );
	uiIndicatorAlpha->Disconnect( wxEVT_CHAR, wxKeyEventHandler( Settings::OnlyAllowNumberChars ), NULL, this );
	uiIndicatorAlpha->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Settings::OnIndicatorText ), NULL, this );
	uiIndicatorOutlineAlpha->Disconnect( wxEVT_CHAR, wxKeyEventHandler( Settings::OnlyAllowNumberChars ), NULL, this );
	uiIndicatorOutlineAlpha->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Settings::OnIndicatorText ), NULL, this );
	uiMarkerList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( Settings::OnMarkerListChanged ), NULL, this );
	uiMarkerSymbol->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Settings::OnMarkerComboChanged ), NULL, this );
	uiMarkerForegroundColor->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnMarkerColorChanged ), NULL, this );
	uiMarkerBackgroundColor->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnMarkerComboChanged ), NULL, this );
	uiShowLineNumbers->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiDisplayEOL->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiIndentGuide->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiViewWhitespace->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Settings::OnComboboxChanged ), NULL, this );
	uiWordwrap->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Settings::OnComboboxChanged ), NULL, this );
	uiEdgeStyle->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Settings::OnComboboxChanged ), NULL, this );
	uiEdgeColor->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnColorChanged ), NULL, this );
	uiEdgeColumn->Disconnect( wxEVT_CHAR, wxKeyEventHandler( Settings::OnlyAllowNumberChars ), NULL, this );
	uiEdgeColumn->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Settings::OnEditChanged ), NULL, this );
	uiTabWidth->Disconnect( wxEVT_CHAR, wxKeyEventHandler( Settings::OnlyAllowNumberChars ), NULL, this );
	uiTabWidth->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Settings::OnEditChanged ), NULL, this );
	uiUseTabs->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiTabIndents->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiBackspaceUnindents->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiAllowFolding->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiFoldLevelNumbers->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiFoldLineBeforeExpanded->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiFoldLineBeforeContracted->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiFoldLineAfterExpanded->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiFoldLineAfterContracted->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiEditCurrentLineOverdraw->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiEditCurrentLineColor->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnColorChanged ), NULL, this );
	uiCurrentLineVisible->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiEditCurrentLineAlpha->Disconnect( wxEVT_CHAR, wxKeyEventHandler( Settings::OnlyAllowNumberChars ), NULL, this );
	uiEditCurrentLineAlpha->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Settings::OnEditChanged ), NULL, this );
	uiEditFoldHi->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnColorChanged ), NULL, this );
	uiEditFoldLow->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnColorChanged ), NULL, this );
	uiEditHighlightKeyword->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiEditIndentation->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Settings::OnComboboxChanged ), NULL, this );
	uiEditUseSelectionForeground->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiEditSelectionForeground->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnColorChanged ), NULL, this );
	uiEditUseSelectionBackground->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Settings::OnCheckboxChanged ), NULL, this );
	uiEditSelectionBackground->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( Settings::OnColorChanged ), NULL, this );
	m_sdbSizer1Apply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnApply ), NULL, this );
	m_sdbSizer1Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnCancel ), NULL, this );
	m_sdbSizer1OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Settings::OnOk ), NULL, this );
	
}

FileProperties::FileProperties( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer4->AddGrowableCol( 1 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Filename:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer4->Add( m_staticText1, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	uiFileName = new wxStaticText( this, wxID_ANY, wxT("<C:\\Some\\Long\\Folder\\path\\to\\file.cpp>"), wxDefaultPosition, wxDefaultSize, 0 );
	uiFileName->Wrap( -1 );
	fgSizer4->Add( uiFileName, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Language:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	fgSizer4->Add( m_staticText3, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	uiLanguage = new wxStaticText( this, wxID_ANY, wxT("<C++>"), wxDefaultPosition, wxDefaultSize, 0 );
	uiLanguage->Wrap( -1 );
	fgSizer4->Add( uiLanguage, 0, wxALL|wxEXPAND, 5 );
	
	m_button1 = new wxButton( this, wxID_ANY, wxT("Line ending..."), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_button1, 0, wxALL, 5 );
	
	uiLineEndings = new wxStaticText( this, wxID_ANY, wxT("CLRF (Windows)"), wxDefaultPosition, wxDefaultSize, 0 );
	uiLineEndings->Wrap( -1 );
	fgSizer4->Add( uiLineEndings, 0, wxALL|wxEXPAND, 5 );
	
	m_button2 = new wxButton( this, wxID_ANY, wxT("Endoding..."), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_button2, 0, wxALL, 5 );
	
	uiEncoding = new wxStaticText( this, wxID_ANY, wxT("UTF-8"), wxDefaultPosition, wxDefaultSize, 0 );
	uiEncoding->Wrap( -1 );
	fgSizer4->Add( uiEncoding, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer5->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	wxGridBagSizer* gbSizer2;
	gbSizer2 = new wxGridBagSizer( 0, 0 );
	gbSizer2->SetFlexibleDirection( wxBOTH );
	gbSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	bSizer5->Add( gbSizer2, 1, wxEXPAND, 5 );
	
	
	bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );
	
	m_sdbSizer3 = new wxStdDialogButtonSizer();
	m_sdbSizer3OK = new wxButton( this, wxID_OK );
	m_sdbSizer3->AddButton( m_sdbSizer3OK );
	m_sdbSizer3->Realize();
	
	bSizer4->Add( m_sdbSizer3, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FileProperties::OnChangeLineEnding ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FileProperties::OnChangeEncoding ), NULL, this );
}

FileProperties::~FileProperties()
{
	// Disconnect Events
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FileProperties::OnChangeLineEnding ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FileProperties::OnChangeEncoding ), NULL, this );
	
}
