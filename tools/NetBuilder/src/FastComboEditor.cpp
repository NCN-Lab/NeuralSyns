#include "Precompiled.h"

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


#include "FastComboEditor.h"


#ifdef __WXGTK__
#include <gtk/gtk.h>
#endif
#include <wx/tokenzr.h>


//#include "EzGrid.h"
#include "NetBuilderModel_frame.h"

extern NetBuilderModel_frame *Model_frame;
extern int pop_selected;
int fdms_selected=0;
int pop_pre=0;
int pop_pos=0;
wxString dynamic_model = _T("");
extern int fdms_check;

class wxSComboBox : public wxComboBox
{
public:
   wxSComboBox();
	wxSComboBox(wxWindow *parent, wxWindowID id,
			const wxString& value = wxEmptyString,
			const wxPoint& pos = wxDefaultPosition,
			const wxSize& size = wxDefaultSize,
			int n = 0, const wxString choices[] = NULL,
			long style = 2,
			const wxValidator& validator = wxDefaultValidator,
			const wxString& name = wxComboBoxNameStr);
	void SetCellData(int nRow, int nCol, wxGrid* pGrid)
	{
		m_nRow = nRow;
		m_nCol = nCol;
		m_pGrid = pGrid;
	}
private:
	DECLARE_EVENT_TABLE()
	void OnChange(wxCommandEvent& event);
	int m_nRow;
	int m_nCol; 
	wxGrid* m_pGrid;
};


wxSComboBox::wxSComboBox(wxWindow *parent, wxWindowID id,
		const wxString& value,
		const wxPoint& pos,
		const wxSize& size,
		int n, const wxString choices[],
		long style,
		const wxValidator& validator,
		const wxString& name)
{
Create(parent, id, value, pos, size, n, choices, style, validator, name);
}

wxSComboBox::wxSComboBox() : m_pGrid(NULL)
{ 
}

BEGIN_EVENT_TABLE(wxSComboBox, wxComboBox)
   EVT_COMBOBOX(-1, wxSComboBox::OnChange)
END_EVENT_TABLE()

void wxSComboBox::OnChange(wxCommandEvent& event)
{

	if (m_pGrid) 
	{
		m_pGrid->GetTable()->SetValue(m_nRow, m_nCol, event.GetString());
		m_pGrid->SetCellValue(m_nRow, m_nCol, event.GetString());
		wxGridEvent gridEvt(m_pGrid->GetId(),wxEVT_GRID_CELL_CHANGE, m_pGrid, m_nRow, m_nCol);
		gridEvt.SetString(event.GetString());
		GetEventHandler()->ProcessEvent(gridEvt);
		
		if (fdms_check!=1){ //get out in case of fdms grid
		    //open parameters table with the corresponding choice model
		    dynamic_model=m_pGrid->GetTable()->GetValue(m_nRow,m_nCol) ;
		    fdms_selected=m_nCol;
		    pop_pre=m_nRow;
		    pop_pos=m_nCol;
		    Model_frame->Show(true);
		}
	}
	event.Skip();
}

wxFastComboEditor::wxFastComboEditor(size_t count,  const wxString choices[], bool allowOthers)
: 
m_allowOthers(allowOthers)
{
	SetClientData((void*)&m_pointActivate);
	if ( count )
	{
		m_choices.Alloc(count);
		for (size_t n = 0; n < count; n++ )
		{
			m_choices.Add(choices[n]);
		}
	}
}
wxString wxFastComboEditor::GetValue() const
{
  wxString value=wxGridCellChoiceEditor::GetValue();
  return value;
}

wxGridCellChoiceEditor *wxFastComboEditor::Clone() const
{       wxFastComboEditor *editor  = new wxFastComboEditor();
	editor->m_allowOthers = m_allowOthers;
	editor->m_choices = m_choices;
	return editor;
}

void wxFastComboEditor::Create(wxWindow* parent,wxWindowID id,wxEvtHandler* evtHandler)
{
	size_t count = m_choices.GetCount();
	wxString *choices = new wxString[count];
	for ( size_t n = 0; n < count; n++ )
	{
	  choices[n] = m_choices[n];
	}
	m_control = new wxSComboBox(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, count, choices, m_allowOthers ? 0 : wxCB_READONLY);
	delete [] choices;
	wxGridCellEditor::Create(parent, id, evtHandler);
}

void wxFastComboEditor::PaintBackground(const wxRect& rectCell, wxGridCellAttr * attr)
{
	wxGridCellEditor::PaintBackground(rectCell, attr);
}

void wxFastComboEditor::BeginEdit(int row, int col, wxGrid* grid)
{
	wxASSERT_MSG(m_control, wxT("The wxGridCellEditor must be Created first!"));

	//EzGrid* pEzGrid = (EzGrid*)grid;
	//pEzGrid->RevertSel();

	m_startValue = grid->GetTable()->GetValue(row, col);

	if (m_allowOthers)
		Combo()->SetValue(m_startValue);
	else
	{
		// find the right position, or default to the first if not found
		int pos = Combo()->FindString(m_startValue);
		if (pos == -1)
			pos = 0;
		Combo()->SetSelection(pos);
	}
	Combo()->SetInsertionPointEnd();
	Combo()->SetFocus();
	Combo()->SetCellData(row, col, grid);
// 	if (m_pointActivate.x > -1 && m_pointActivate.y > -1)
// 	{
// 		m_pointActivate = Combo()->ScreenToClient(m_pointActivate);
// #ifdef __WINDOWS__
// 		SendMessage((HWND)Combo()->GetHandle(), WM_LBUTTONDOWN, 0,
// 			MAKELPARAM(m_pointActivate.x, m_pointActivate.y));
// #else
// 		GtkCombo *combo = GTK_COMBO(Combo()->m_widget);
// 		combo->current_button = 0;
// 		GtkWidget *button = GTK_COMBO(Combo()->m_widget)->button;
// 		GdkEventButton event;
// 		memset(&event, 0, sizeof(event));
// 		gdk_window_ref (button->window);
// 		// to do: only call when the click point is on the button
// 		//event.x = m_pointActivate.x;
// 		//event.y = m_pointActivate.y;
// 		event.x = 0;
// 		event.y = 0;
// 		//event.device = GDK_CORE_POINTER;
// 		event.type = GDK_BUTTON_PRESS;
// 		//event.source = GDK_SOURCE_MOUSE;
// 		event.time = 0; 
// 		event.window = button->window;
// 		event.send_event = TRUE;
// 		event.button = 1;
// 		gtk_widget_event (button, (GdkEvent *)&event);
// 		gdk_window_unref (button->window);
// 		while (gtk_events_pending())
// 			gtk_main_iteration();
// #endif
// 	}
}

bool wxFastComboEditor::EndEdit(int row, int col, wxGrid* grid)
{
	wxString value = Combo()->GetValue();
	bool changed = value != grid->GetTable()->GetValue(row, col);

	if ( changed )
		grid->GetTable()->SetValue(row, col, value);

	m_startValue = wxEmptyString;
	if (m_allowOthers)
		Combo()->SetValue(m_startValue);
	else
		Combo()->SetSelection(0);

	return changed;
}

void wxFastComboEditor::Reset()
{
	Combo()->SetValue(m_startValue);
	Combo()->SetInsertionPointEnd();
}

void wxFastComboEditor::SetParameters(const wxString& params)
{
	if ( !params )
	{
		return;
	}
	m_choices.Empty();
	wxStringTokenizer tk(params, _T(','));
	while ( tk.HasMoreTokens() )
	{
		m_choices.Add(tk.GetNextToken());
	}
}

void wxFastComboEditor::SetParameters(size_t count, const wxString choices[])
{
	m_choices.Empty();
	if ( count )
	{
		m_choices.Alloc(count);
		for ( size_t n = 0; n < count; n++ )
		{
			m_choices.Add(choices[n]);
		}
	}
}