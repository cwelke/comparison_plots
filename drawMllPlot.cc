#include <vector>
#include <string>

#include "TGaxis.h"
#include "TMath.h"
#include "TFile.h"
#include "TH1F.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TPad.h"
#include "TLine.h"
#include "TLatex.h"

float intlumi = 19.5;

void drawTex(Float_t bottomleft, Float_t topright, bool istargeted, string thirdline){

  TLatex *tex = new TLatex(bottomleft, topright - 0.05, Form("#sqrt{s}=8 TeV, #int Ldt = %2.1f fb^{-1}", float(intlumi)));    
  // TLatex *tex = new TLatex(bottomleft,topright-0.05, "Simulation" );    
  tex->SetNDC();    
  tex->SetTextSize(0.03);    
  tex->SetLineWidth(2);    

  TLatex *tex2 = new TLatex(bottomleft,topright,"CMS Preliminary 2012");    
  tex2->SetNDC();    
  tex2->SetTextSize(0.03);    
  tex2->SetLineWidth(2);

  TLatex *tex3;
  if(!istargeted){
	tex3 = new TLatex(bottomleft,topright-0.10, thirdline.c_str());//"Inclusive Selection + b-tag");
}else if(istargeted){
	tex3 = new TLatex(bottomleft,topright-0.10, thirdline.c_str() );    
  }
  tex3->SetNDC();    
  tex3->SetTextSize(0.03);    
  tex3->SetLineWidth(2);

  tex->Draw();
  tex2->Draw();
  tex3->Draw();
  return;
}

// void drawAxes(float start, float end, float ymin, float ymax, bool islog){

//   Float_t ticksize = 1;
//   // Float_t ndiv = 5;
//   TGaxis *axisright;
//   if(islog){axisright = new TGaxis(end,ymin,end,ymax,ymin, ymax,50510,"+G");
//   }else{
// 	axisright = new TGaxis(end,ymin,end,ymax,ymin, ymax,510,"+");
//   }
//   axisright->SetLabelSize(0);
//   axisright->SetTickSize(ticksize);
//   axisright->Draw();

//   TGaxis *axistop;
//   axistop = new TGaxis(start,ymax,end,ymax,start, end,510,"-");
//   // axistop->SetNdivisions(0);
//   axistop->SetLabelSize(0);
//   axistop->SetTickSize(ticksize);
//   axistop->Draw();

//   TGaxis *axisleft;
//   if(islog){ axisleft = new TGaxis(start,ymin,start,ymax,ymin, ymax,50510,"-G");
//   }else{axisleft = new TGaxis(start,ymin,start,ymax,ymin, ymax,510,"-");
// 	// axisleft->SetNdivisions(0);
//   }
//   axisleft->SetLabelSize(0);
//   axisleft->SetTickSize(ticksize);
//   axisleft->Draw();

//   TGaxis *axisbottom;
//   axisbottom = new TGaxis(start,ymin,end,ymin,start, end,510,"+");
//   // axistop->SetNdivisions(0);
//   axisbottom->SetLabelSize(0);
//   axisbottom->SetTickSize(ticksize);
//   axisbottom->Draw();

//   return;
// }

void drawPlot( string variable = "", string sample = "", Float_t binwidth = 1.0, Float_t xmin = 0.0, Float_t xmax = 350.0, Float_t ymin = 1e-1, Float_t ymax = 1e5, bool islog  = true);
void drawRatio( string variable = "", string sample = "", Float_t binwidth = 1.0, Float_t xmin = 0.0, Float_t xmax = 350.0, Float_t ymin = 1e-1, Float_t ymax = 1e5 );
void makeAndSavePlot( string variable, Float_t binwidth, Float_t xmin, Float_t xmax, Float_t ymin, Float_t ymax, bool islog );

int drawMllPlot(){

  Float_t ratio_ymin = 0.5;
  Float_t ratio_ymax = 1.5;

  Float_t ymin = 1e-2;
  Float_t ymax = 1e5;

  Float_t xmin = 1e-2;
  Float_t xmax = 1e5;

  Float_t binwidth = 5.0;

  string plotVariable = "";

  vector <string> channel;
  channel.push_back("ee");
  channel.push_back("mm");
  channel.push_back("em");
  channel.push_back("all");

  makeAndSavePlot( "mll"  , 10.0, 0.0, 350.0, 0.0, 5e-1, true );
  makeAndSavePlot( "mjj"  , 10.0, 0.0, 350.0, 0.0, 5e-1, true );
  makeAndSavePlot( "pfmet", 25.0, 0.0, 100.0, 0.0, 5e-1, false );
  makeAndSavePlot( "zpt"  , 25.0, 0.0, 350.0, 0.0, 5e-1, true );
  makeAndSavePlot( "bbpt" , 25.0, 0.0, 350.0, 0.0, 5e-1, false );
  makeAndSavePlot( "njets", 1.0 , 2.0, 10.0 , 0.0, 5e-1, true );

  return 0; 

}


void makeAndSavePlot( string variable, Float_t binwidth, Float_t xmin, Float_t xmax, Float_t ymin, Float_t ymax, bool islog )
{

  Float_t ratio_ymin = 0.5;
  Float_t ratio_ymax = 1.5;

  TCanvas * c1 = new TCanvas("canvas1", "", 1000, 1000 );
  c1->Divide(2,2);

  c1->cd(1);
  drawPlot(  variable, "ee", binwidth, xmin, xmax, ymin, ymax, islog );
  c1->cd(1);
  drawRatio( variable, "ee", binwidth, xmin, xmax, ratio_ymin, ratio_ymax);

  c1->cd(2);
  drawPlot(  variable, "mm", binwidth, xmin, xmax, ymin, ymax, islog );
  c1->cd(2);
  drawRatio( variable, "mm", binwidth, xmin, xmax, ratio_ymin, ratio_ymax);

  c1->cd(3);
  drawPlot(  variable, "em", binwidth, xmin, xmax, ymin, ymax, islog );
  c1->cd(3);
  drawRatio( variable, "em", binwidth, xmin, xmax, ratio_ymin, ratio_ymax);

  c1->cd(4);
  drawPlot(  variable, "all", binwidth, xmin, xmax, ymin, ymax, islog );
  c1->cd(4);
  drawRatio( variable, "all", binwidth, xmin, xmax, ratio_ymin, ratio_ymax);

  c1->SaveAs(Form( "~/Desktop/ZH_Plots/%s_plot.pdf", variable.c_str() ));

			 return;

}

void drawRatio( string variable, string sample, Float_t binwidth, Float_t xmin, Float_t xmax, Float_t ymin, Float_t ymax ){

  TPad *pad = new TPad("p_hist", "p_hist", 0.0, 0.8, 1.0, 1.0);
  pad->SetBottomMargin(0.12);
  pad->SetRightMargin(0.07);
  pad->SetLeftMargin(0.18);
  pad->Draw();
  pad->cd();

  TFile * file = NULL;
  file = TFile::Open("photon_template_MET_data_2jetbins_all.root","READ");

  // TH1F * h_data = NULL;
  TH1F * h_mc   = NULL;
  TH1F * ratio  = NULL;

  // h_data  = (TH1F*)file->Get(Form("h_mll_%s_data_tar", variable.c_str() ));
  h_mc    = (TH1F*)file->Get(Form("h_%s_%s_all_tar" , variable.c_str(), sample.c_str() ));
  ratio   = (TH1F*)file->Get(Form("h_%s_%s_data_tar", variable.c_str(), sample.c_str() ));

  ratio -> Rebin(binwidth);
  h_mc  -> Rebin(binwidth);

  ratio -> SetLineColor(kBlack);
  ratio -> SetMarkerStyle(20);
  ratio -> SetMarkerSize(0.5);

  ratio -> GetXaxis() ->SetRangeUser( xmin, xmax );
  h_mc  -> GetXaxis() ->SetRangeUser( xmin, xmax );

  ratio -> SetStats(0);
  h_mc  -> SetStats(0);

  ratio->Divide(h_mc);

  ratio->GetXaxis()->SetRangeUser( xmin, xmax );
  ratio->GetYaxis()->SetRangeUser( ymin, ymax );
  ratio->GetXaxis()->SetLabelSize(0);

  pad->SetGridy(1);

  // ratio->GetXaxis()->SetLabelSize(0);
  // drawAxes( xmin, xmax, ymin, ymax, false);
  // ratio->GetYaxis()->SetRangeUser(0.,2.);
  ratio->GetYaxis()->SetNdivisions(5);
  ratio->SetTitle("");
  // ratio->GetXaxis()->SetLabelSize(0);
  ratio->GetYaxis()->SetLabelSize(0.075);

  ratio->Draw();

  pad->cd()->RedrawAxis();
  // drawRatioAxes( xmin, xmax, ymin, ymax, false);

  return;
}

void drawPlot( string variable, string sample, Float_t binwidth, Float_t xmin, Float_t xmax, Float_t ymin, Float_t ymax, bool islog ){

  TPad *pad2 = new TPad("p_ratio", "p_ratio", 0.0, 0.0, 1.0, 0.8);
  pad2->SetBottomMargin(0.12);
  pad2->SetRightMargin(0.07);
  pad2->SetLeftMargin(0.18);
  pad2->Draw();

  pad2->cd();
  pad2->cd()->SetLogy(islog);

  TFile * file = NULL;
  file = TFile::Open("photon_template_MET_data_2jetbins_all.root","READ");

  TH1F * h_data  = NULL;
  TH1F * h_allmc = NULL;
  TH1F * h_zjets = NULL;
  TH1F * h_wz    = NULL;
  TH1F * h_zz    = NULL;
  TH1F * h_ttbar = NULL;
  TH1F * h_st    = NULL;
  TH1F * h_ww    = NULL;
  TH1F * h_ttv   = NULL;
  TH1F * h_vvv   = NULL;

  h_data  = (TH1F*)file->Get(Form("h_%s_%s_data_tar" , variable.c_str(), sample.c_str() ));
  h_zjets = (TH1F*)file->Get(Form("h_%s_%s_zjets_tar", variable.c_str(), sample.c_str() ));
  h_wz    = (TH1F*)file->Get(Form("h_%s_%s_wz_tar"   , variable.c_str(), sample.c_str() ));
  h_zz    = (TH1F*)file->Get(Form("h_%s_%s_zz_tar"   , variable.c_str(), sample.c_str() ));
  h_ttbar = (TH1F*)file->Get(Form("h_%s_%s_ttbar_tar", variable.c_str(), sample.c_str() ));
  h_st    = (TH1F*)file->Get(Form("h_%s_%s_st_tar"   , variable.c_str(), sample.c_str() ));
  h_ww    = (TH1F*)file->Get(Form("h_%s_%s_ww_tar"   , variable.c_str(), sample.c_str() ));
  h_ttv   = (TH1F*)file->Get(Form("h_%s_%s_ttv_tar"  , variable.c_str(), sample.c_str() ));
  h_vvv   = (TH1F*)file->Get(Form("h_%s_%s_vvv_tar"  , variable.c_str(), sample.c_str() ));

  h_allmc = (TH1F*) h_ttbar -> Clone("allmc_hists");
  h_allmc -> Add(h_wz);
  h_allmc -> Add(h_zz);
  h_allmc -> Add(h_zjets);
  h_allmc -> Add(h_st);
  h_allmc -> Add(h_ww);
  h_allmc -> Add(h_ttv);
  h_allmc -> Add(h_vvv);

  if(variable == "mll")  h_data->GetXaxis()  -> SetTitle( "M_{ll} GeV" );
  if(variable == "mjj")  h_data->GetXaxis()  -> SetTitle( "M_{jj} GeV" );
  if(variable == "pfmet")  h_data->GetXaxis()-> SetTitle( "#slash{E}_{T} GeV" );

  h_data->SetTitle("");

  h_data  -> Rebin(binwidth);
  h_allmc -> Rebin(binwidth);
  h_zjets -> Rebin(binwidth); 
  h_wz    -> Rebin(binwidth);
  h_zz    -> Rebin(binwidth);
  h_ttbar -> Rebin(binwidth);
  h_st    -> Rebin(binwidth);
  h_ww    -> Rebin(binwidth);
  h_ttv   -> Rebin(binwidth);
  h_vvv   -> Rebin(binwidth);

  Double_t maxy = 0.0;
  if ( h_data  -> GetMaximum() > maxy ) maxy = h_data  -> GetMaximum();
  if ( h_allmc -> GetMaximum() > maxy ) maxy = h_allmc -> GetMaximum();
  // if ( h_sig_250 -> GetMaximum() > maxy ) maxy = h_sig_250 -> GetMaximum();
  // if ( h_allmc   -> GetMaximum() > maxy ) maxy = h_allmc   -> GetMaximum();

  if ( islog ){
	ymax = maxy*1e2;
	if ( variable == "mjj" ) ymax = maxy*3e2;
  }else{
	ymax = maxy*1.5;
  }

  if ( islog && fabs( ymin ) < 1e-6 ) ymin = 1e-2;


  h_data  -> GetXaxis() ->SetRangeUser( xmin, xmax );
  h_zjets -> GetXaxis() ->SetRangeUser( xmin, xmax ); 
  h_wz    -> GetXaxis() ->SetRangeUser( xmin, xmax );
  h_zz    -> GetXaxis() ->SetRangeUser( xmin, xmax );
  h_ttbar -> GetXaxis() ->SetRangeUser( xmin, xmax );
  h_st    -> GetXaxis() ->SetRangeUser( xmin, xmax );
  h_ww    -> GetXaxis() ->SetRangeUser( xmin, xmax );
  h_ttv   -> GetXaxis() ->SetRangeUser( xmin, xmax );
  h_vvv   -> GetXaxis() ->SetRangeUser( xmin, xmax );

  h_data  -> GetYaxis() ->SetRangeUser( ymin, ymax );
  h_zjets -> GetYaxis() ->SetRangeUser( ymin, ymax ); 
  h_wz    -> GetYaxis() ->SetRangeUser( ymin, ymax );
  h_zz    -> GetYaxis() ->SetRangeUser( ymin, ymax );
  h_ttbar -> GetYaxis() ->SetRangeUser( ymin, ymax );
  h_st    -> GetYaxis() ->SetRangeUser( ymin, ymax );
  h_ww    -> GetYaxis() ->SetRangeUser( ymin, ymax );
  h_ttv   -> GetYaxis() ->SetRangeUser( ymin, ymax );
  h_vvv   -> GetYaxis() ->SetRangeUser( ymin, ymax );

  h_data -> SetLineColor(   kBlack );
  h_data -> SetMarkerStyle( 20     );
  h_data -> SetMarkerSize(  0.5    );

  h_data  -> SetStats(0);
  h_zjets -> SetStats(0); 
  h_wz    -> SetStats(0);
  h_zz    -> SetStats(0);
  h_ttbar -> SetStats(0);
  h_st    -> SetStats(0);
  h_ww    -> SetStats(0);
  h_ttv   -> SetStats(0);
  h_vvv   -> SetStats(0);

  h_vvv   -> SetFillColor( kGray + 3  );//kGray + 3
  h_zz    -> SetFillColor( kGray + 1  );//kRed
  h_wz    -> SetFillColor( kBlue + 1  );//kBlue + 1
  h_ww    -> SetFillColor( kGreen + 2 );//kBlue - 3
  h_ttv   -> SetFillColor( kRed       );//kGray + 1
  h_st    -> SetFillColor( kBlue - 3  );//kGreen + 2
  h_ttbar -> SetFillColor( kYellow    );//kYellow
  h_zjets -> SetFillColor( kCyan      );//kCyan

  h_zjets -> SetFillStyle(1001); 
  h_wz    -> SetFillStyle(1001);
  h_zz    -> SetFillStyle(1001);
  h_ttbar -> SetFillStyle(1001);
  h_st    -> SetFillStyle(1001);
  h_ww    -> SetFillStyle(1001);
  h_ttv   -> SetFillStyle(1001);
  h_vvv   -> SetFillStyle(1001);

  h_zjets -> SetLineColor(1); 
  h_wz    -> SetLineColor(1);
  h_zz    -> SetLineColor(1);
  h_ttbar -> SetLineColor(1);
  h_st    -> SetLineColor(1);
  h_ww    -> SetLineColor(1);
  h_ttv   -> SetLineColor(1);
  h_vvv   -> SetLineColor(1);

  THStack * stack = NULL;

  stack = new THStack ("All_MC", "" );

  stack->Add( h_vvv   );
  stack->Add( h_zz    );
  stack->Add( h_wz    );
  stack->Add( h_ww    );
  stack->Add( h_ttv   );
  stack->Add( h_st    );
  stack->Add( h_ttbar );
  stack->Add( h_zjets );

  h_data -> Draw(            );
  stack  -> Draw( "samehist" );
  h_data -> Draw( "same"     );

  // drawAxes( xmin, xmax, ymin, ymax, islog);

  //Draw Legend
  // TLegend *l1 = new TLegend(0.65, 0.55, 0.85, 0.85);    
  TLegend *l1 = new TLegend(0.70, 0.60, 0.90, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry(h_data , "data"      , "lp");
  l1->AddEntry(h_zjets, "Z+jets"    , "f" );    
  l1->AddEntry(h_ttbar, "t#bar{t}"  , "f" );    
  l1->AddEntry(h_st   , "Single Top", "f" );    
  l1->AddEntry(h_ttv  , "ttV"       , "f" );    
  l1->AddEntry(h_ww   , "WW"        , "f" );    
  l1->AddEntry(h_wz   , "WZ"        , "f" );    
  l1->AddEntry(h_zz   , "ZZ"        , "f" );    
  l1->AddEntry(h_vvv  , "VVV"       , "f" );    
  l1->Draw();

  if(sample == "ee"  ) drawTex( 0.25, 0.85, false, "Events with ee"     );
  if(sample == "mm"  ) drawTex( 0.25, 0.85, false, "Events with #mu#mu" );
  if(sample == "em"  ) drawTex( 0.25, 0.85, false, "Events with e#mu"   );
  if(sample == "all" ) drawTex( 0.25, 0.85, false, "All Events"         );

  pad2->cd()->RedrawAxis();

  return;

}
