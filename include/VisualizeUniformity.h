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
#include <algorithm>
#include <cmath>
#include <iterator>
#include <map>
//#include <memory>
#include <numeric>
#include <stdio.h>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

//Framework Includes
#include "TimingUtilityFunctions.h"
#include "UniformityUtilityOperators.h"
#include "UniformityUtilityTypes.h"
#include "Visualizer.h"

//ROOT Includes
#include "TCanvas.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TGraph2D.h"
//#include "TGraph2DErrors.h"
#include "TGraphErrors.h"
#include "TH1.h"
#include "TH1F.h"
//#include "TImage.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TLine.h"
#include "TMultiGraph.h"
#include "TObject.h"
#include "TPad.h"
#include "TROOT.h"
#include "TStyle.h"
//#include "TView.h"

//using namespace ROOT;

#endif /* defined(____VisualizeUniformity__) */

namespace QualityControl {
    namespace Uniformity {
        
        class VisualizeUniformity : public Visualizer {
            
        public:
            //Constructors
            //------------------------------------------------------------------------------------------------------------------------------------------
            //Default
            VisualizeUniformity();
            
            VisualizeUniformity(Uniformity::AnalysisSetupUniformity inputSetup, Uniformity::DetectorMPGD inputDet);
            
            //Actions - Methods that Do Something
            //------------------------------------------------------------------------------------------------------------------------------------------
            //Draws the distribution of an observable onto a single pad of canvas
            //Takes a std::string which stores the physical filename as input
            virtual void storeCanvasData(std::string & strOutputROOTFileName, std::string strOption, std::string strObsName, std::string strDrawOption, bool bShiftMean);
            
            //Draws the distribution of an observable onto a single pad of canvas
            //Takes a TFile *, which the canvas is written to, as input
            virtual void storeCanvasData(TFile * file_InputRootFile, std::string strObsName, std::string strDrawOption, bool bShiftMean);
            
            //Draws a canvas with the slice histo & fit for all slices
            //Also makes a summary distribution showing the % of good fits per ReadoutSectorPhi
            virtual void storeCanvasFits(std::string & strOutputROOTFileName, std::string strOption, std::string strDrawOption);
            virtual void storeCanvasFits(TFile * file_InputRootFile, std::string strDrawOption);
            
            //Draws a given observable onto a single pad of canvas
            //Takes a std::string which stores the physical filename as input
            virtual void storeCanvasGraph(std::string & strOutputROOTFileName, std::string strOption, std::string strObsName, std::string strDrawOption, bool bShowPhiSegmentation);
            
            //Draws a given observable onto a single pad of canvas
            //Takes a TFile *, which the canvas is written to, as input
            virtual void storeCanvasGraph(TFile * file_InputRootFile, std::string strObsName, std::string strDrawOption, bool bShowPhiSegmentation);
            
            //Makes a 2D plot of a given observable in the detector's active area
            //Takes a std::string which stores the physical filename as input
            virtual void storeCanvasGraph2D(std::string & strOutputROOTFileName, std::string strOption, std::string strObsName, std::string strDrawOption, bool bNormalize);
            
            //Makes a 2D plot of a given observable in the detector's active area
            //Takes a TFile *, which the canvas is writtent to, as input
            virtual void storeCanvasGraph2D(TFile * file_InputRootFile, std::string strObsName, std::string strDrawOption, bool bNormalize);
            
            //Draws a given observable onto a single pad of canvas
            //Takes a std::string which stores the physical filename as input
            virtual void storeCanvasHisto(std::string & strOutputROOTFileName, std::string strOption, std::string strObsName, std::string strDrawOption, bool bShowPhiSegmentation);
            
            //Draws a given observable onto a single pad of canvas
            //Takes a TFile * which the histograms are written to as input
            virtual void storeCanvasHisto(TFile * file_InputRootFile, std::string strObsName, std::string strDrawOption, bool bShowPhiSegmentation);
            
            //Makes a 2D plot of a given observable in the detector's active area
            //Takes a std::string which stores the physical filename as input
            virtual void storeCanvasHisto2D(std::string & strOutputROOTFileName, std::string strOption, std::string strObsName, std::string strDrawOption);
            
            //Makes a 2D plot of a given observable in the detector's active area
            //Takes a TFile *, which the canvas is writtent to, as input
            virtual void storeCanvasHisto2D(TFile * file_InputRootFile, std::string strObsName, std::string strDrawOption);
            
            virtual void storeCanvasHistoSegmented(std::string & strOutputROOTFileName, std::string strOption, std::string strObsName, std::string strDrawOption, bool bShowPhiSegmentation);
            
            //Partitions a canvas into N TPads where N = number of ReadoutSectorEta for input DetectorMPGD
            //Draws a given observable on each pad
            //Takes a std::string which stores the physical filename as input
            //Takes a TFile * which the histograms are written to as input
            virtual void storeCanvasHistoSegmented(TFile * file_InputRootFile, std::string strObsName, std::string strDrawOption, bool bShowPhiSegmentation);

            //Draws the run history of a given observable onto a segment canvas
            //Takes a std::string which stores the physical filename as input
            virtual void storeCanvasHisto2DHistorySegmented(std::string & strOutputROOTFileName, std::string strOption, std::string strObsName, std::string strDrawOption, bool bIsEta);
            
            //Draws the run history of a given observable onto a segment canvas
            //Takes a std::string which stores the physical filename as input
            virtual void storeCanvasHisto2DHistorySegmented(TFile * file_InputRootFile, std::string strObsName, std::string strDrawOption, bool bIsEta);
            
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
            
        private:
            //Actions - Methods that Do Something
            //------------------------------------------------------------------------------------------------------------------------------------------
            
            //Getters - Methods that Get (i.e. Return) Something
            //------------------------------------------------------------------------------------------------------------------------------------------
            virtual TCanvas *getCanvasSliceFit(Uniformity::SectorSlice & inputSlice, int iEta, int iPhi, int iSlice, bool bDataOverFit);
            
            //std::vector<float> getObsData(std::string strObsName, Uniformity::ReadoutSectorEta &inputEta);
            virtual Uniformity::SummaryStatistics getObsData(std::string strObsName);
            
            virtual std::shared_ptr<TGraphErrors> getObsGraph(std::string strObsName, Uniformity::ReadoutSectorEta &inputEta);
            
            virtual std::shared_ptr<TH1F> getObsHisto(std::string strObsName, Uniformity::ReadoutSector &inputSector);
            
            virtual std::map<int, std::shared_ptr<TH2F> > getMapObsHisto2D(std::string strObsName, Uniformity::ReadoutSector &inputSector);
            
            virtual std::shared_ptr<TH2F> getSummarizedRunHistoryHisto2D(std::map<int, std::shared_ptr<TH2F> > inputMapHisto2D, int iEta, int iPhi );
            
            //Printers - Methods that Print Something
            //------------------------------------------------------------------------------------------------------------------------------------------
            
            //Setters - Methods that Set Something
            //------------------------------------------------------------------------------------------------------------------------------------------
            
            //Data Members
            //------------------------------------------------------------------------------------------------------------------------------------------
            
        }; //End class VisualizeUniformity
    } //End namespace Uniformity
} //End namespace QualityControl

