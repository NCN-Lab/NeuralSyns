#ifndef __NetBuilderVisualization_frame__
#define __NetBuilderVisualization_frame__

/**
@file
Subclass of Visualization_frame, which is generated by wxFormBuilder.
*/

#include "gui.h"
#include "drawpane.h"
#include "data_structures.h"
#include "NetBuilderDynamics_frame.h"



/** Implementing Visualization_frame */
class NetBuilderVisualization_frame : public Visualization_frame
{
protected:
	// Handlers for Visualization_frame events.
	//void Onbtn_CancelClick( wxCloseEvent& event );
	void OnClose( wxCloseEvent& event );
	void OnInitVisualization( wxInitDialogEvent& event );
	
public:
	/** Constructor */
	NetBuilderVisualization_frame( wxDialog* parent );
};

#endif // __NetBuilderVisualization_frame__
