#ifndef __NetBuilderMainFrame__
#define __NetBuilderMainFrame__

/**
@file
Subclass of MainFrame, which is generated by wxFormBuilder.
*/

#ifdef WX_GCH  
#include "wx/wx_pch.h"  
#else  
#include "wx/wx.h"  
#endif

#include "gui.h"
#include "NetBuilderProperties_frame.h"
#include "NetBuilderTopology_frame.h"
#include "NetBuilderConnectivity_frame.h"
#include "NetBuilderFdms_frame.h"
#include "NetBuilderSummary_frame.h"
#include "NetBuilderDistributions_frame.h"
#include "NetBuilderDelays_frame.h"
#include "NetBuilderConductances_frame.h"
#include "NetBuilderPlasticity_frame.h"
#include "NetBuilderModel_frame.h"
#include "NetBuilderVisualization_frame.h"
//#include "NetBuilderPython_frame.h"
#include "data_structures.h"
#include "dataio.h"
#include <typeinfo>
#include <wx/filename.h>
#include "CreateNet.h"
//#include <Python.h>
//#include "Python_functions.h"




using namespace std;

/** Implementing MainFrame */
class NetBuilderMainFrame : public MainFrame
{
protected:
	// Handlers for MainFrame events.
	void OnClose( wxCloseEvent& event );
	void OnQuit( wxCommandEvent& event );
	//void OnPython( wxCommandEvent& event );
	void OnAbout( wxCommandEvent& event );
	void OnSelectRB( wxCommandEvent& event );
	void OnFileChanged( wxFileDirPickerEvent& event );
	void OnCreateRB( wxCommandEvent& event );
	void On_total_population_Update( wxCommandEvent& event );
	void OnPropertiesClick( wxCommandEvent& event );
	void OnTopopolyClick( wxCommandEvent& event );
	void OnConnClick( wxCommandEvent& event );
	void OnFdmsClick( wxCommandEvent& event );
	void OnDistributionsClick( wxCommandEvent& event );
	void OnDelaysClick( wxCommandEvent& event );
	void OnConductancesClick( wxCommandEvent& event );
	void OnPlasticityClick( wxCommandEvent& event );
	void OnStoreClick( wxCommandEvent& event );
	void On_btn_summary_Click( wxCommandEvent& event );
	void OnCreateClick( wxCommandEvent& event );
        //void OnPythonClick ( wxCommandEvent& event );
	//void On_Status_TextEnter( wxCommandEvent& event );
	
public:
	/** Constructor */
	NetBuilderMainFrame( wxWindow* parent );
};

#endif // __NetBuilderMainFrame__
