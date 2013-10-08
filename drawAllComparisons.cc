#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

#include "TGaxis.h"
#include "TFile.h"
#include "TH1F.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TPad.h"
#include "TLine.h"
#include "TLatex.h"
#include "TMath.h"
// #include "gPad.h"
// #include "TROOT.h"

using namespace std;

#include "/Users/vincewelke/rootTools/histUtils.cc"

bool dofsprediction = true;
bool dofsrescale = true;
bool drawsinglehist = false;
string date = "250913";

void drawPlot( TFile * &filename, string variable, string sample, string searchRegion, Float_t binwidth, Float_t xmin, Float_t xmax, Float_t ymin, Float_t ymax, bool islog, bool isblind );
void makeAndSavePlot( string variable, string searchRegion, Float_t binwidth, Float_t xmin, Float_t xmax, Float_t ymin, Float_t ymax, bool islog, bool isblind );
void drawRatio( TFile * &filename, string variable, string sample, string searchRegion, Float_t binwidth, Float_t xmin, Float_t xmax, Float_t ymin, Float_t ymax, bool islog, bool isblind );

int drawAllComparisons()
{

  bool isblind  = true;

  makeAndSavePlot( "met"    , "bveto1" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , false );
  makeAndSavePlot( "met"    , "bveto2" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , false );
  makeAndSavePlot( "met"    , "bveto3" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , false );
  makeAndSavePlot( "met"    , "bveto4" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , false );

  makeAndSavePlot( "met"    , "2btag1" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , false   );
  makeAndSavePlot( "met"    , "2btag2" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , isblind );
  makeAndSavePlot( "met"    , "2btag3" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , false   );
  makeAndSavePlot( "met"    , "2btag4" , 10.0,  0.0, 200.0, 1e-2, 10.0e1, true , false  );

  makeAndSavePlot( "njets"  , "dilep" ,  1.0, 0.0,  15.0,  1e-3, 1e2, true, isblind );
  // // makeAndSavePlot( "mll"    , "dilep" , 10.0, 50.0, 200.0, 1e-3, 1e2, true , isblind );
  // // makeAndSavePlot( "mll"    , "sig"   , 10.0, 50.0, 200.0, 1e-3, 1e2, true , isblind );

  // makeAndSavePlot( "nbtags" , "mjj150",  1.0, 0.0,  4.0,  1e-1, 1e2, false, isblind );
  // makeAndSavePlot( "nbtags" , "dilep",  1.0, 0.0,  4.0,  1e-1, 1e2, false, isblind );
  // makeAndSavePlot( "csv1" , "dilep",  1.0, 0.0,  1.0,  1e-1, 1e2, false, isblind );
  // makeAndSavePlot( "csv2" , "dilep",  1.0, 0.0,  1.0,  1e-1, 1e2, false, isblind );
  // makeAndSavePlot( "csv3" , "dilep",  1.0, 0.0,  1.0,  1e-1, 1e2, false, isblind );
  // makeAndSavePlot( "nbtags" , "mt2j"  ,  1.0, 0.0,  10.0,  1e-1, 1e2, false, isblind );

  // makeAndSavePlot( "zpt"    , "dilep" , 10.0, 50.0, 200.0, 1e-1, 1e2, true , isblind );
  // makeAndSavePlot( "zpt"    , "sig" , 10.0, 50.0, 200.0, 1e-1, 1e2, true , isblind );

  // makeAndSavePlot( "mll"    , "2jet" , 10.0, 50.0, 200.0, 1e-1, 1e2, true , isblind );
  // makeAndSavePlot( "mll"    , "3jet" , 10.0, 50.0, 200.0, 1e-1, 1e2, true , isblind );
  // makeAndSavePlot( "mll"    , "mt2j" , 10.0, 50.0, 200.0, 1e-1, 1e2, true , isblind );
  // makeAndSavePlot( "mll"    , "mjj150" , 10.0, 50.0, 200.0, 1e-1, 1e2, true , isblind );

  // makeAndSavePlot( "met"    , "mt2j"         , 10.0, 0.0, 200.0, 1e-2, 1e2, true , false );
  // makeAndSavePlot( "met"    , "dilep"        , 10.0, 0.0, 200.0, 1e-2, 1e2, true , false );
  // makeAndSavePlot( "met"    , "sig"          , 10.0, 0.0, 200.0, 1e-2, 1e2, true , false );

  makeAndSavePlot( "mll"    , "met80"        , 5.0, 0.0, 200.0, 1e-1, 2.5e1, false, isblind );
  makeAndSavePlot( "mll"    , "met100"       , 5.0, 0.0, 200.0, 1e-1, 1.5e1, false, isblind );
  makeAndSavePlot( "mll"    , "met120"       , 10.0, 0.0, 200.0, 1e-1, .5e1, false, isblind );

  makeAndSavePlot( "mll"    , "bveto1_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, false , false );
  makeAndSavePlot( "mll"    , "bveto2_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, false , false );
  makeAndSavePlot( "mll"    , "bveto3_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, false , false );
  makeAndSavePlot( "mll"    , "bveto4_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, false , false );

  makeAndSavePlot( "mll"    , "2btag1_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, false , false );
  makeAndSavePlot( "mll"    , "2btag2_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, false , true );
  makeAndSavePlot( "mll"    , "2btag3_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, false , false );
  makeAndSavePlot( "mll"    , "2btag4_met120" , 10.0,  0.0, 200.0, 1e-2, 10.0e1, false , false );

  makeAndSavePlot( "mt2"    , "2btag1_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , false );
  makeAndSavePlot( "mt2"    , "2btag2_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , true );
  makeAndSavePlot( "mt2"    , "2btag3_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , false );
  makeAndSavePlot( "mt2"    , "2btag4_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , false );
  makeAndSavePlot( "mt2"    , "bveto1_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , false );
  makeAndSavePlot( "mt2"    , "bveto2_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , true );
  makeAndSavePlot( "mt2"    , "bveto3_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , false );
  makeAndSavePlot( "mt2"    , "bveto4_met120" , 10.0,  0.0, 200.0, 1e-2, 1.5e1, true , false );

  // // makeAndSavePlot( "mbb"    , "dilep" , 25.0, 0.0, 350.0,  0e0, 1e2, false, isblind );

  // makeAndSavePlot( "mbb"    , "met80" , 50.0, 0.0, 450.0, 1e-1, 1.5e1, false, isblind );
  // makeAndSavePlot( "mbb"    , "met100", 50.0, 0.0, 450.0, 1e-1, 1.5e1, false, isblind );
  // makeAndSavePlot( "mbb"    , "met120", 25.0, 0.0, 450.0, 1e-1, 12e0, false, isblind );
  // makeAndSavePlot( "met"    , "dilep" ,  2.0, 0.0,  80.0, 1e-1, 1e2, true , isblind );
  // makeAndSavePlot( "zpt"    , "dilep" , 10.0, 0.0, 200.0, 1e-1, 1e2, true , isblind );
  // makeAndSavePlot( "zpt"    , "sig"   , 10.0, 0.0, 200.0, 1e-1, 1e2, true , isblind );
  // makeAndSavePlot( "hpt"    , "dilep" , 10.0, 0.0, 200.0, 1e-1, 1e2, false , isblind );
  // makeAndSavePlot( "mt2b"   , "dilep" , 25.0, 0.0, 350.0, 1e-1, 1e2, true , isblind );

  // makeAndSavePlot( "mt2b"   , "sig", 10.0, 0.0, 300.0, 1e-1, 1e2, true, false );


  return 0; 

}

void makeAndSavePlot( string variable, string searchRegion, Float_t binwidth, Float_t xmin, Float_t xmax, Float_t ymin, Float_t ymax, bool islog, bool isblind )
{

  TCanvas * c1 = new TCanvas("canvas1", "", 1600, 1600 );
  c1->Divide(2,2);

  TCanvas * csave = new TCanvas("canvassave", "", 400, 400 );

  TFile * file = TFile::Open("photon_template_MET_data_2jetbins_all.root","READ");

  vector <string> channel;
  channel.push_back("ee");
  channel.push_back("mm");
  channel.push_back("em");
  channel.push_back("ll");

  for( size_t ind = 0; ind < channel.size(); ind++ ){

  c1->cd();
  c1->cd(ind+1);
  drawsinglehist = false;
  drawPlot( file, variable, channel.at(ind), searchRegion, binwidth, xmin, xmax, ymin, ymax, islog, isblind );
  c1->cd(ind+1);
  drawRatio( file, variable, channel.at(ind), searchRegion, binwidth, xmin, xmax, ymin, ymax, islog, isblind );

  csave->cd();
  drawsinglehist = true;
  drawPlot( file, variable, channel.at(ind), searchRegion, binwidth, xmin, xmax, ymin, ymax, islog, isblind );
  csave->cd();
  drawRatio( file, variable, channel.at(ind), searchRegion, binwidth, xmin, xmax, ymin, ymax, islog, isblind );
  csave->cd()->SaveAs(Form( "~/Desktop/ZH_Plots/%s/data_bg/single_events/%s_%s_%s_comparison_plot.pdf", date.c_str(), variable.c_str(), searchRegion.c_str(), channel.at(ind).c_str() ));

  }

  c1->SaveAs(Form( "~/Desktop/ZH_Plots/%s/data_bg/%s_%s_comparison_plot.pdf", date.c_str(), variable.c_str(), searchRegion.c_str() ));
  c1->Close();

  return;
}

void drawPlot( TFile * &filename, string variable, string sample, string searchRegion, Float_t binwidth, Float_t xmin, Float_t xmax, Float_t ymin, Float_t ymax, bool islog, bool isblind )
{

  // bool dofsprediction = true;

  TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 0.8);
  pad->SetBottomMargin(0.12);
  pad->SetRightMargin(0.07);
  pad->SetTopMargin(0.07);
  pad->SetLeftMargin(0.18);
  pad->Draw();

  pad->cd();
  pad->cd()->SetLogy(islog);

  TFile * file = NULL;
  file = filename;

  map<string,TH1F*> hists;

  TH1F    * h_data  = NULL;
  TH1F    * h_fsbg  = NULL;
  TH1F    * h_zjets = NULL;
  TH1F    * h_wz    = NULL;
  TH1F    * h_zz    = NULL;
  TH1F    * h_ttbar = NULL;
  TH1F    * h_st    = NULL;
  TH1F    * h_ww    = NULL;
  TH1F    * h_ttv   = NULL;
  TH1F    * h_vvv   = NULL;
  TH1F    * h_smzh  = NULL;
  TH1F    * h_tbz   = NULL;
  TH1F    * h_allmc = NULL;

  THStack * stack   = NULL;
  stack = new THStack ("s_allmc", "" );
  // if( variable == "met" && searchRegion == "sig"

  //get histos from file
  h_data  =     (TH1F*)file->Get(Form("h_%s_%s_data_%s"  , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_data");

  if( true && sample != "em" ){	h_zjets = (TH1F*)file->Get(Form("h_%s_%s_zjetsll_%s"   , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_zjets");
  }else{            h_zjets = (TH1F*)file->Get(Form("h_%s_%s_zjets_%s"   , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_zjets");  }
  
  h_fsbg  =     (TH1F*)file->Get(Form("h_%s_em_data_%s"  , variable.c_str(),                 searchRegion.c_str() )) -> Clone("h_fsbg");
  // h_zjets =     (TH1F*)file->Get(Form("h_%s_%s_zjets_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_zjets");
  h_wz    =     (TH1F*)file->Get(Form("h_%s_%s_wz_%s"    , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_wz");
  h_zz    =     (TH1F*)file->Get(Form("h_%s_%s_zz_%s"    , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_zz");
  h_ttbar =     (TH1F*)file->Get(Form("h_%s_%s_ttbar_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_ttbar");
  h_st    =     (TH1F*)file->Get(Form("h_%s_%s_st_%s"    , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_st");
  h_ww    =     (TH1F*)file->Get(Form("h_%s_%s_ww_%s"    , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_ww");
  h_ttv   =     (TH1F*)file->Get(Form("h_%s_%s_ttv_%s"   , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_ttv");
  h_vvv   =     (TH1F*)file->Get(Form("h_%s_%s_vvv_%s"   , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_vvv");
  h_smzh  =     (TH1F*)file->Get(Form("h_%s_%s_smzh_%s"  , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_smzh");
  h_tbz   =     (TH1F*)file->Get(Form("h_%s_%s_tbz_%s"   , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_tbz");

  h_allmc =     (TH1F*)file->Get(Form("h_%s_%s_zjets_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_allmc");

  hists.insert ( pair<string,TH1F*>("h_data",  h_data  ) ); 
  hists.insert ( pair<string,TH1F*>("h_fsbg",  h_fsbg  ) ); 
  hists.insert ( pair<string,TH1F*>("h_zjets", h_zjets ) ); 
  hists.insert ( pair<string,TH1F*>("h_wz",    h_wz ) ); 
  hists.insert ( pair<string,TH1F*>("h_zz",    h_zz ) ); 
  hists.insert ( pair<string,TH1F*>("h_ttbar", h_ttbar ) ); 
  hists.insert ( pair<string,TH1F*>("h_st",    h_st ) ); 
  hists.insert ( pair<string,TH1F*>("h_ww",    h_ww ) ); 
  hists.insert ( pair<string,TH1F*>("h_ttv",   h_ttv ) ); 
  hists.insert ( pair<string,TH1F*>("h_vvv",   h_vvv ) ); 
  hists.insert ( pair<string,TH1F*>("h_smzh",  h_smzh ) ); 
  hists.insert ( pair<string,TH1F*>("h_tbz",   h_tbz ) ); 
  hists.insert ( pair<string,TH1F*>("h_allmc", h_allmc ) ); 



  if( variable == "met" ){
	if( dofsrescale && sample != "em" && searchRegion == "2btag1" ){
	  h_fsbg -> Scale(0.11);
	}
	if( dofsrescale && sample != "em" && searchRegion == "2btag2" ){
	  h_fsbg -> Scale(0.11);
	}
	if( dofsrescale && sample != "em" && searchRegion == "2btag3" ){
	  h_fsbg -> Scale(0.15);
	}
	if( dofsrescale && sample != "em" && searchRegion == "2btag4" ){
	  h_fsbg -> Scale(0.15);
	}

	if( dofsrescale && sample != "em" && searchRegion == "bveto1" ){
	  h_fsbg -> Scale(0.09);
	}
	if( dofsrescale && sample != "em" && searchRegion == "bveto2" ){
	  h_fsbg -> Scale(0.09);
	}
	if( dofsrescale && sample != "em" && searchRegion == "bveto3" ){
	  h_fsbg -> Scale(0.14);
	}
	if( dofsrescale && sample != "em" && searchRegion == "bveto4" ){
	  h_fsbg -> Scale(0.12);
	}
  }

  if( variable == "mll" ){
	if( dofsprediction && sample == "ll" && searchRegion == "met120" ){
	  h_allmc -> Scale( 4.0 / 5.3 );
	  h_zjets -> Scale( 4.0 / 5.3 );
	  // h_fsbg  -> Scale( 12.7 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "2btag1_met120" ){
	  h_allmc -> Scale( 3.8 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)-1));
	  h_zjets -> Scale( 3.8 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)-1));
	  h_fsbg  -> Scale( 12.7 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	  // h_fsbg -> Scale(0.819);
	}
	if( dofsprediction && sample == "ll" && searchRegion == "2btag2_met120" ){
	  h_allmc -> Scale( 0.9 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)-1));
	  h_zjets -> Scale( 0.9 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)-1));
	  h_fsbg  -> Scale( 1.2 / h_fsbg  -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	  // h_fsbg -> Scale(1.2/2.9);
	}
	if( dofsprediction && sample == "ll" && searchRegion == "2btag3_met120" ){
	  h_allmc -> Scale( 0.9 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)-1));
	  h_zjets -> Scale( 0.9 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)-1));
	  h_fsbg  -> Scale( 44.2 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	  // h_fsbg -> Scale(44.2/45.6);
	}
	if( dofsprediction && sample == "ll" && searchRegion == "2btag4_met120" ){
	  h_allmc -> Scale( 1.6 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)-1));
	  h_zjets -> Scale( 1.6 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)-1));
	  h_fsbg  -> Scale( 88.9 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	  // h_fsbg -> Scale(88.9/89.2);
	}

	if( dofsprediction && sample == "ll" && searchRegion == "bveto1_met120" ){
	  h_allmc -> Scale( 34.8 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)-1));
	  h_zjets -> Scale( 34.8 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)-1));
	  h_fsbg  -> Scale( 12.2 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "bveto2_met120" ){
	  h_allmc -> Scale( 3.7 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)-1));
	  h_zjets -> Scale( 3.7 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)-1));
	  h_fsbg  -> Scale( 2.2 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "bveto3_met120" ){
	  h_allmc -> Scale( 4.1 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)-1));
	  h_zjets -> Scale( 4.1 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)-1));
	  h_fsbg  -> Scale( 6.2 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "bveto4_met120" ){
	  h_allmc -> Scale( 16.9 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)-1));
	  h_zjets -> Scale( 16.9 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)-1));
	  h_fsbg  -> Scale( 14.3 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	}
  }

  if( dofsprediction && sample == "mm" ){
	h_fsbg -> Scale(0.53/0.97);
  }
  if( dofsprediction && sample == "ee" ){
	h_fsbg -> Scale(0.43/0.97);
  }

  if( dofsprediction && sample != "em" ){
	h_allmc -> Add( h_wz    );
	h_allmc -> Add( h_zz    );
	h_allmc -> Add( h_fsbg  );
	h_allmc -> Add( h_ttv   );
	h_allmc -> Add( h_vvv   );
	h_allmc -> Add( h_smzh  );
	h_allmc -> Add( h_tbz   );

  }else{
	h_allmc -> Add( h_wz    );
	h_allmc -> Add( h_zz    );
	h_allmc -> Add( h_ttbar );
	h_allmc -> Add( h_st    );
	h_allmc -> Add( h_ww    );
	h_allmc -> Add( h_ttv   );
	h_allmc -> Add( h_vvv   );
	h_allmc -> Add( h_smzh  );
	h_allmc -> Add( h_tbz   );
  }	

  //Set xaxis name based on input variable
  if(variable == "mll")    h_data -> GetXaxis() -> SetTitle( "M_{ll} [GeV]" );
  if(variable == "mjj")    h_data -> GetXaxis() -> SetTitle( "M_{jj} [GeV]" );
  if(variable == "mbb")    h_data -> GetXaxis() -> SetTitle( "M_{b#bar{b}} [GeV]" );
  if(variable == "met")    h_data -> GetXaxis() -> SetTitle( "#slash{E}_{T} GeV" );
  if(variable == "zpt")    h_data -> GetXaxis() -> SetTitle( "Z p_{T} GeV" );
  if(variable == "hpt")    h_data -> GetXaxis() -> SetTitle( "b#bar{b} p_{T} GeV" );
  if(variable == "bbpt")   h_data -> GetXaxis() -> SetTitle( "H p_{T} GeV" );
  if(variable == "njets")  h_data -> GetXaxis() -> SetTitle( "# of jets" );
  if(variable == "mt2")    h_data -> GetXaxis() -> SetTitle( "MT2" );
  if(variable == "mt2b")   h_data -> GetXaxis() -> SetTitle( "M_{T2}^{j} [GeV]" );
  if(variable == "mlb")    h_data -> GetXaxis() -> SetTitle( "M(l,b)" );

  //set yaxis name
  h_data -> GetYaxis() -> SetTitle( Form( "#frac{Events}{%.0f [GeV]}", binwidth  ) );
  h_data -> GetYaxis() -> SetTitleOffset(1.5);
  if( variable == "mbb" ) h_data -> GetYaxis() -> SetTitleOffset(1.75); 
  h_data->SetTitle("");

  for (map<string, TH1F*>::iterator itr = hists.begin(); itr != hists.end(); itr++){
	itr->second -> Rebin(binwidth);
	updateOverflow( itr->second, xmax );
	itr->second -> GetXaxis() ->SetRangeUser( xmin, xmax );
	itr->second -> SetFillStyle(1001); 
	itr->second -> SetLineColor(1); 
  }

  Double_t maxy = 0.0;
  if ( h_data  -> GetMaximum() > ymax ){ maxy = h_data  -> GetMaximum();
  }else if ( h_allmc -> GetMaximum() > ymax ){ maxy = h_allmc -> GetMaximum();
  }else{ maxy = ymax; }
  
  if ( islog ){
	ymax = maxy*1e2;
	if ( variable == "mbb" ) ymax = maxy*3e2;
  }else{
	ymax = maxy*1.2;
	if ( variable == "mbb" ) ymax = maxy*1.5;
	if ( variable == "nbtags" ) ymax = maxy*1.75;
  }
  

  if ( islog && fabs( ymin ) < 1e-6 ) ymin = 1e-2;
  
  h_data -> GetYaxis()->SetRangeUser( ymin, ymax );


  if( isblind ){
	if( variable == "met" && sample != "em" ){ 
	  for ( Int_t bini = h_data -> FindBin(80.0); bini < h_data -> GetNbinsX() + 1; bini++ ){
		h_data  -> SetBinContent( bini, 0.0 );
	  }
	}else if( variable == "mt2b" ){  
	  for ( Int_t bini = h_data -> FindBin(250.0); bini < h_data -> GetNbinsX() + 1; bini++ ){
		h_data  -> SetBinContent( bini, 0.0 );
	  }	  
	}else if( variable == "mbb" && searchRegion == "met80" ){  
	  for ( Int_t bini = h_data -> FindBin(100.0); bini < h_data -> FindBin(150.0); bini++ ){
		h_data  -> SetBinContent( bini, -1.0 );
	  }
	}else if( variable == "mbb" && searchRegion == "met100" ){  
	  for ( Int_t bini = h_data -> FindBin(100.0); bini < h_data -> FindBin(150.0); bini++ ){
		h_data  -> SetBinContent( bini, -1.0 );
	  }
	}else if( variable == "mbb" && searchRegion == "met120" ){  
	  for ( Int_t bini = h_data -> FindBin(100.0); bini < h_data -> FindBin(150.0); bini++ ){
		h_data  -> SetBinContent( bini, -1.0 );
	  }
	}else if( variable == "mll" && searchRegion == "2btag2_met120" ){  
	  for ( Int_t bini = h_data -> FindBin(81.0); bini < h_data -> FindBin(101.0); bini++ ){
		h_data  -> SetBinContent( bini, -1.0 );
	  }
	}
  }
  
  if( variable == "mll" && TString(searchRegion).Contains("met120") ){  
	for ( Int_t bini = 0; bini <= h_data -> FindBin(70.0); bini++ ){
	  h_data  -> SetBinContent( bini, 0.0 );
	}
  }

  h_zjets -> SetFillColor( kCyan      );//kCyan
  h_fsbg  -> SetFillColor( 42         );//kYellow
  // h_fsbg  -> SetFillColor( kCyan      );//kCyan
  h_wz    -> SetFillColor( kBlue + 1  );//kBlue + 1
  h_zz    -> SetFillColor( kRed       );//kRed
  h_ttbar -> SetFillColor( kYellow    );//kYellow
  h_st    -> SetFillColor( kBlue - 3  );//kGreen + 2
  h_ww    -> SetFillColor( kGreen + 2 );//kBlue - 3
  h_ttv   -> SetFillColor( kGray + 1  );//kGray + 1
  h_vvv   -> SetFillColor( kGray + 3  );//kGray + 3
  h_smzh  -> SetFillColor( kMagenta   );//kGray + 3
  h_tbz   -> SetFillColor( kOrange + 1 );//kGray + 3

  h_data -> SetMarkerStyle(9);
  if( drawsinglehist ){
	h_data -> SetMarkerSize(0.45);
  }

  if( dofsprediction && sample != "em" ){
	stack -> Add( h_tbz   );
	stack -> Add( h_vvv   );
	stack -> Add( h_ttv   );
	stack -> Add( h_smzh  );
	stack -> Add( h_zz    );
	stack -> Add( h_wz    );
	stack -> Add( h_fsbg  );
	stack -> Add( h_zjets );

  }else{
	stack -> Add( h_tbz   );
	stack -> Add( h_vvv   );
	stack -> Add( h_ttv   );
	stack -> Add( h_ww    );
	stack -> Add( h_st    );
	stack -> Add( h_smzh  );
	stack -> Add( h_ttbar );
	stack -> Add( h_zz    );
	stack -> Add( h_wz    );
	stack -> Add( h_zjets );
  }
	
  h_data -> Draw("");
  stack -> Draw("samehist");
  h_data -> Draw("sameE1");

  //Draw Legend
  TLegend *l1 = new TLegend(0.65, 0.60, 0.85, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry(h_data  , "Data"       , "lp");
  if( dofsprediction && sample == "ll" ){
	l1->AddEntry(h_zjets , "Z+Jets"     , "f");
	l1->AddEntry(h_fsbg  , "FS Bkg"     , "f");
	l1->AddEntry(h_wz    , "WZ"         , "f");
	l1->AddEntry(h_zz    , "ZZ"         , "f");
	l1->AddEntry(h_smzh  , "Z+H"        , "f");
	l1->AddEntry(h_ttv   , "ttv"        , "f");
	l1->AddEntry(h_vvv   , "vvv"        , "f");
	l1->AddEntry(h_tbz   , "tbZ"        , "f");

  }else{
	l1->AddEntry(h_zjets , "Z+Jets"     , "f");
	l1->AddEntry(h_wz    , "WZ"         , "f");
	l1->AddEntry(h_zz    , "ZZ"         , "f");
	l1->AddEntry(h_ttbar , "t#bar{t}"   , "f");
	l1->AddEntry(h_smzh  , "Z+H"        , "f");
	l1->AddEntry(h_st    , "single top" , "f");
	l1->AddEntry(h_ww    , "WW"         , "f");
	l1->AddEntry(h_ttv   , "ttv"        , "f");
	l1->AddEntry(h_vvv   , "vvv"        , "f");
	l1->AddEntry(h_tbz   , "tbZ"        , "f");
  }
  l1->Draw();

  if(sample == "ee"  ) drawTex( 0.2, 0.85, false, "Events with ee"     );
  if(sample == "mm"  ) drawTex( 0.2, 0.85, false, "Events with #mu#mu" );
  if(sample == "em"  ) drawTex( 0.2, 0.85, false, "Events with e#mu"   );
  if(sample == "ll" ) drawTex( 0.2, 0.85, false, "Events with ee and #mu#mu"         );

  pad->cd()->RedrawAxis();

  return;
}

void drawRatio( TFile * &filename, string variable, string sample, string searchRegion, Float_t binwidth, Float_t xmin, Float_t xmax, Float_t ymin, Float_t ymax, bool islog, bool isblind )
{

  // bool dofsprediction = true;


  TH1F * h_mc = NULL;
  TH1F * h_data = NULL;

  h_data = (TH1F*)filename->Get(Form("h_%s_%s_data_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_data");
  if( true && sample != "em" ){ h_mc = (TH1F*)filename->Get(Form("h_%s_%s_zjetsll_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_mc");
  }else{            h_mc = (TH1F*)filename->Get(Form("h_%s_%s_zjets_%s"   , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_mc"); }

  // TH1F * h_data =   (TH1F*)filename->Get(Form("h_%s_%s_data_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_data");
  TH1F * h_fsbg =   (TH1F*)filename->Get(Form("h_%s_em_data_%s" , variable.c_str(),                 searchRegion.c_str() )) -> Clone("h_fsbg");
  // TH1F * h_mc =     (TH1F*)filename->Get(Form("h_%s_%s_zjets_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_mc");

  // h_data = (TH1F*)filename->Get(Form("h_%s_%s_data_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_data");
  // if( splitzjets && sample != "em" ){ h_mc = (TH1F*)filename->Get(Form("h_%s_%s_zjetsll_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_mc");
  // }else{            h_mc = (TH1F*)filename->Get(Form("h_%s_%s_zjets_%s"   , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_mc"); }



  if( variable == "met" ){
	if( dofsrescale && sample != "em" && searchRegion == "2btag1" ){
	  h_fsbg -> Scale(0.11);
	}
	if( dofsrescale && sample != "em" && searchRegion == "2btag2" ){
	  h_fsbg -> Scale(0.11);
	}
	if( dofsrescale && sample != "em" && searchRegion == "2btag3" ){
	  h_fsbg -> Scale(0.15);
	}
	if( dofsrescale && sample != "em" && searchRegion == "2btag4" ){
	  h_fsbg -> Scale(0.15);
	}

	if( dofsrescale && sample != "em" && searchRegion == "bveto1" ){
	  h_fsbg -> Scale(0.09);
	}
	if( dofsrescale && sample != "em" && searchRegion == "bveto2" ){
	  h_fsbg -> Scale(0.09);
	}
	if( dofsrescale && sample != "em" && searchRegion == "bveto3" ){
	  h_fsbg -> Scale(0.14);
	}
	if( dofsrescale && sample != "em" && searchRegion == "bveto4" ){
	  h_fsbg -> Scale(0.12);
	}
  }

  if( variable == "mll" ){
	if( dofsprediction && sample == "ll" && searchRegion == "met120" ){
	  // h_mc -> Scale( 4.0 / 5.3 );
	  h_mc -> Scale( 3.8 / h_mc -> Integral(h_mc->FindBin(81), h_mc->FindBin(101)-1));
	  h_fsbg  -> Scale( 12.7 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "2btag1_met120" ){
	  h_mc -> Scale( 3.8 / h_mc -> Integral(h_mc->FindBin(81), h_mc->FindBin(101)));
	  h_fsbg  -> Scale( 12.7 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "2btag2_met120" ){
	  h_mc -> Scale( 0.9 / h_mc -> Integral(h_mc->FindBin(81), h_mc->FindBin(101)));
	  h_fsbg  -> Scale( 1.2 / h_fsbg  -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "2btag3_met120" ){
	  h_mc -> Scale( 0.9 / h_mc -> Integral(h_mc->FindBin(81), h_mc->FindBin(101)));
	  h_fsbg  -> Scale( 44.2 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "2btag4_met120" ){
	  h_mc -> Scale( 1.6 / h_mc -> Integral(h_mc->FindBin(81), h_mc->FindBin(101)-1));
	  h_fsbg  -> Scale( 88.9 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	}

	if( dofsprediction && sample == "ll" && searchRegion == "bveto1_met120" ){
	  h_mc -> Scale( 34.8 / h_mc -> Integral(h_mc->FindBin(81), h_mc->FindBin(101)-1));
	  h_fsbg  -> Scale( 12.2 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "bveto2_met120" ){
	  h_mc -> Scale( 3.7 / h_mc -> Integral(h_mc->FindBin(81), h_mc->FindBin(101)-1));
	  h_fsbg  -> Scale( 2.2 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "bveto3_met120" ){
	  h_mc -> Scale( 4.1 / h_mc -> Integral(h_mc->FindBin(81), h_mc->FindBin(101)-1));
	  h_fsbg  -> Scale( 6.2 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "bveto4_met120" ){
	  h_mc -> Scale( 16.9 / h_mc -> Integral(h_mc->FindBin(81), h_mc->FindBin(101)-1));
	  h_fsbg  -> Scale( 14.3 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)-1));
	}
  }

  if( dofsprediction && sample == "mm" ){
	h_fsbg -> Scale(0.53/0.97);
  }
  if( dofsprediction && sample == "ee" ){
	h_fsbg -> Scale(0.43/0.97);
  }

  // if( dofsprediction && sample == "ll" && searchRegion == "met120" ){
  // 	h_fsbg -> Scale(0.819);
  // }
  if( true && sample != "em" ){ h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_zjetstt_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) ); }

  if( dofsprediction && sample != "em" ){
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_wz_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_zz_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_ttv_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_vvv_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_smzh_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_tbz_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
	h_mc -> Add( h_fsbg );

  }else{
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_wz_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_zz_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_ttbar_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_st_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_ww_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_ttv_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_vvv_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_smzh_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
	h_mc -> Add( (TH1F*)filename->Get(Form("h_%s_%s_tbz_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) );
  }

  TPad *padr = new TPad("p_rat", "p_rat", 0.0, 0.8, 1.0, 1.0);
  padr->SetBottomMargin(0.12);
  padr->SetRightMargin(0.07);
  padr->SetTopMargin(0.07);
  padr->SetLeftMargin(0.18);
  padr->Draw();

  h_data -> Rebin(binwidth); 
  h_mc   -> Rebin(binwidth); 

  h_data -> SetMarkerStyle(20);
  if( drawsinglehist ){
	h_data -> SetMarkerSize(0.45);
  }

  updateOverflow( h_data, xmax );
  updateOverflow( h_mc,  xmax );

  TH1F * ratio = (TH1F*)h_data -> Clone("h_ratio");
  ratio->Divide(h_mc);

  if( isblind ){  
	if( variable == "met" && sample != "em" ){ 
	  for ( Int_t bini = h_data -> FindBin(80.0); bini < h_data -> GetNbinsX() + 1; bini++ ){
		h_data  -> SetBinContent( bini, 0.0 );
		ratio   -> SetBinContent( bini, -1.0 );
	  }
	}else if( variable == "mt2b" ){  
	  for ( Int_t bini = h_data -> FindBin(250.0); bini < h_data -> GetNbinsX() + 1; bini++ ){
		h_data  -> SetBinContent( bini, 0.0 );
		ratio   -> SetBinContent( bini, -1.0 );
	  }
	}else if( variable == "mbb" && searchRegion == "met80" ){  
	  for ( Int_t bini = h_data -> FindBin(100.0); bini < h_data -> FindBin(150.0); bini++ ){
		h_data  -> SetBinContent( bini, 0.0 );
		ratio   -> SetBinContent( bini, -1.0 );
	  }
	}else if( variable == "mbb" && searchRegion == "met100" ){  
	  for ( Int_t bini = h_data -> FindBin(100.0); bini < h_data -> FindBin(150.0); bini++ ){
		h_data  -> SetBinContent( bini, 0.0 );
		ratio   -> SetBinContent( bini, -1.0 );
	  }
	}else if( variable == "mbb" && searchRegion == "met120" ){  
	  for ( Int_t bini = h_data -> FindBin(100.0); bini < h_data -> FindBin(150.0); bini++ ){
		h_data  -> SetBinContent( bini, 0.0 );
		ratio   -> SetBinContent( bini, -1.0 );
	  }
	}else if( variable == "mll" && searchRegion == "2btag2_met120" ){  
	  for ( Int_t bini = h_data -> FindBin(81.0); bini < h_data -> FindBin(101.0); bini++ ){
		h_data  -> SetBinContent( bini, 0.0 );
		ratio   -> SetBinContent( bini, -1.0 );
	  }
	}
  }
  
  if( variable == "mll" && TString(searchRegion).Contains("met120") ){  
	for ( Int_t bini = 0; bini <= h_data -> FindBin(70.0); bini++ ){
	  h_data  -> SetBinContent( bini, 0.0 );
	  ratio   -> SetBinContent( bini, -1.0 );
	}
  }

  padr->cd();
  padr -> SetGridy(1);

  ratio -> GetXaxis() -> SetRangeUser(xmin, xmax);

  ratio -> GetXaxis() -> SetTitle("");
  ratio -> GetYaxis() -> SetTitle("#frac{Data}{MC}");

  ratio -> GetYaxis() -> SetNdivisions(5);
  ratio -> GetYaxis() -> SetRangeUser( 0.0, 2.0 );

  // ratio -> SetMarkerSize(0.5);
  ratio->GetXaxis()->SetLabelSize(0);
  ratio->GetYaxis()->SetLabelSize(0.12);
  // cout<<ratio->GetYaxis()->GetTitleSize()<<endl;;
  ratio->GetYaxis()->SetTitleSize(0.16);
  ratio->GetYaxis()->SetTitleOffset(0.37);

  ratio -> Draw("E1");

 return;
}
