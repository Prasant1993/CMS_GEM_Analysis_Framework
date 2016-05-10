//
//  VisualizeUniformity.h
//  
//
//  Created by Brian L Dorney on 18/02/16.
//
//

#ifndef ____VisualizeUniformity__
#define ____VisualizeUniformity__

//C++ Includes
#include <cmath>
#include <iterator>
#include <map>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

//Framework Includes
#include "AnalyzeResponseUniformity.h"
//#include "DetectorMPGD.h" //Done in source file not header file due to inheritance/friendship
#include "TimingUtilityFunctions.h"
#include "UniformityUtilityTypes.h"

//ROOT Includes
#include "TCanvas.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TGraphErrors.h"
#include "TH1.h"
#include "TH1F.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TLine.h"
#include "TMultiGraph.h"
#include "TObject.h"
#include "TPad.h"
#include "TROOT.h"

using namespace ROOT;

#endif /* defined(____VisualizeUniformity__) */

namespace Uniformity {
    
    class VisualizeUniformity : public AnalyzeResponseUniformity {
    
    public:
        //Constructors
        //------------------------------------------------------------------------------------------------------------------------------------------
        //Default
        VisualizeUniformity();
        
        VisualizeUniformity(Uniformity::AnalysisSetupUniformity inputSetup, Uniformity::DetectorMPGD inputDet);
        
        //Actions - Methods that Do Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        //Draws a given observable onto a single pad off canvas
        //Takes a std::string which stores the physical filename as input
        virtual void storeCanvasGraph(std::string & strOutputROOTFileName, std::string strOption, std::string strObsName, std::string strDrawOption, bool bShowPhiSegmentation);
        
        //Draws a given observable onto a single pad off canvas
        //Takes a TFile * which the histograms are written to as input
        virtual void storeCanvasGraph(TFile * file_InputRootFile, std::string strObsName, std::string strDrawOption, bool bShowPhiSegmentation);
        
        //Draws a given observable onto a single pad off canvas
        //Takes a std::string which stores the physical filename as input
        virtual void storeCanvasHisto(std::string & strOutputROOTFileName, std::string strOption, std::string strObsName, std::string strDrawOption, bool bShowPhiSegmentation);
        
        //Draws a given observable onto a single pad off canvas
        //Takes a TFile * which the histograms are written to as input
        virtual void storeCanvasHisto(TFile * file_InputRootFile, std::string strObsName, std::string strDrawOption, bool bShowPhiSegmentation);
        
        //Draws a set of observables onto a single pad off canvas
        //virtual void storeCanvasHisto(std::string & strOutputROOTFileName, std::string strOption, std::vector<std::string> vec_strObsName, std::string strDrawOption, bool bShowPhiSegmentation);
        
        //Partitions a canvas into N TPads where N = number of SectorEta for input DetectorMPGD
        //Draws a given observable on each pad
        //Takes a std::string which stores the physical filename as input
        virtual void storeCanvasHistoSegmented(std::string & strOutputROOTFileName, std::string strOption, std::string strObsName, std::string strDrawOption, bool bShowPhiSegmentation);
        
        //Partitions a canvas into N TPads where N = number of SectorEta for input DetectorMPGD
        //Draws a given observable on each pad
        //Takes a std::string which stores the physical filename as input
        //Takes a TFile * which the histograms are written to as input
        virtual void storeCanvasHistoSegmented(TFile * file_InputRootFile, std::string strObsName, std::string strDrawOption, bool bShowPhiSegmentation);
        
        //For each member of the input map storeListOfCanvasesGraph is called
        //Takes a std::string which stores the physical filename as input
        //map_strObsNameAndDrawOpt
        //  first   -> Obs Name
        //  second  -> Draw option
        virtual void storeListOfCanvasesGraph(std::string & strOutputROOTFileName, std::string strOption, std::map<std::string, std::string> & map_strObsNameAndDrawOpt, bool bShowPhiSegmentation);
        
        //For each member of the input map storeListOfCanvasesGraph is called
        //Takes a TFile * which the histograms are written to as input
        //map_strObsNameAndDrawOpt
        //  first   -> Obs Name
        //  second  -> Draw option
        virtual void storeListOfCanvasesGraph(TFile * file_InputRootFile, std::map<std::string, std::string> & map_strObsNameAndDrawOpt, bool bShowPhiSegmentation);
        
        //For each member of the input map storeListOfCanvasesHisto is called
        //Takes a std::string which stores the physical filename as input
        //map_strObsNameAndDrawOpt
        //  first   -> Obs Name
        //  second  -> Draw option
        virtual void storeListOfCanvasesHisto(std::string & strOutputROOTFileName, std::string strOption, std::map<std::string, std::string> & map_strObsNameAndDrawOpt, bool bShowPhiSegmentation);
        
        //For each member of the input map storeListOfCanvasesHisto is called
        //Takes a TFile * which the histograms are written to as input
        //map_strObsNameAndDrawOpt
        //  first   -> Obs Name
        //  second  -> Draw option
        virtual void storeListOfCanvasesHisto(TFile * file_InputRootFile, std::map<std::string, std::string> & map_strObsNameAndDrawOpt, bool bShowPhiSegmentation);
        
        //For each member of the input map storeListOfCanvasesHistoSegmented is called
        //Takes a std::string which stores the physical filename as input
        //map_strObsNameAndDrawOpt
        //  first   -> Obs Name
        //  second  -> Draw option
        virtual void storeListOfCanvasesHistoSegmented(std::string & strOutputROOTFileName, std::string strOption, std::map<std::string, std::string> & map_strObsNameAndDrawOpt, bool bShowPhiSegmentation);
        
        //For each member of the input map storeListOfCanvasesHistoSegmented is called
        //Takes a TFile * which the histograms are written to as input
        //map_strObsNameAndDrawOpt
        //  first   -> Obs Name
        //  second  -> Draw option
        virtual void storeListOfCanvasesHistoSegmented(TFile * file_InputRootFile, std::map<std::string, std::string> & map_strObsNameAndDrawOpt, bool bShowPhiSegmentation);
        
        //Getters - Methods that Get (i.e. Return) Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        
        //Printers - Methods that Print Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        
        //Setters - Methods that Set Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        //Sets the Analysis Setup
        void setAnalysisParameters(Uniformity::AnalysisSetupUniformity inputSetup){ aSetup = inputSetup; return; };
        
        //Sets the Detector
        void setDetector(Uniformity::DetectorMPGD inputDet){ detMPGD = inputDet; return; };
        
    private:
        //Actions - Methods that Do Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        //Prepares a Canvas for a requested observable
        //virtual void drawSectorEtaCanvas(TCanvas & inputCanvas, std::string &strObsName, std::string &strDrawOption);
        
        //Draws the distribution pointed to by inputObjPtr on a pad of inputCanvas
        //inputCanvas is split into two columns;
        //The Pad is created when this method is called; iEta and iNumEta define the pad position automatically
        //Odd (even) values of iEta are on the left (right)
        //The SectorEta is used to determine the location of the SectorPhi's
        //virtual void drawSectorEtaObs(std::shared_ptr<TH1F> inputObjPtr, TCanvas & inputCanvas, std::string &strDrawOption, int iEta, int iNumEta, Uniformity::SectorEta &inputEta);
        
        //Getters - Methods that Get (i.e. Return) Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        //Could not make the below method work with the TGraphErrors Easily
        std::shared_ptr<TGraphErrors> getObsGraph(std::string &strObsName, Uniformity::SectorEta &inputEta);

        std::shared_ptr<TH1F> getObsHisto(std::string &strObsName, Uniformity::SectorEta &inputEta);
        
        //Printers - Methods that Print Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        
        //Setters - Methods that Set Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        
        //Data Members
        //------------------------------------------------------------------------------------------------------------------------------------------
        Uniformity::AnalysisSetupUniformity aSetup; //Container to define the analysis setup
        
        Uniformity::DetectorMPGD detMPGD;
    }; //End class VisualizeUniformity
} //End namespace Uniformity