#ifndef __NetBuilderConductances_frame__
#define __NetBuilderConductances_frame__

/**
@file
Subclass of Conductances_frame, which is generated by wxFormBuilder.
*/

#include "gui.h"
#include "data_structures.h"
#include "data_structures.h"
#include "FastComboEditor.h"
#include "GridCellChoiceRenderer.h"
#include "GridCellIconRenderer.h"
#include "NetBuilderSummary_frame.h"
#include "NetBuilderModel_frame.h"


/** Implementing Conductances_frame */
class NetBuilderConductances_frame : public Conductances_frame
{
protected:
	// Handlers for Conductances_frame events.
	void OnInitConductances( wxInitDialogEvent& event );
	void OnCellClick( wxGridEvent& event );
	void Onbtn_Conductances_CancelClick( wxCommandEvent& event );
	void Onbtn_Conductances_OKClick( wxCommandEvent& event );
	
public:
	/** Constructor */
	NetBuilderConductances_frame( wxWindow* parent );
};

#endif // __NetBuilderConductances_frame__
