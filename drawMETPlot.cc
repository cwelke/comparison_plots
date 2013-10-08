#include <vector>
#include <string>

#include "TGaxis.h"
#include "TFile.h"
#include "TH1F.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TPad.h"
#include "TLine.h"
#include "TLatex.h"



void drawPlot( string variable, string sample, Float_t binwidth, Float_t xmin, Float_t xmax, Float_t ymin, Float_t ymax, bool islog );
void makeAndSavePlot( string variable, Float_t binwidth, Float_t xmin, Float_t xmax, Float_t ymin, Float_t ymax, bool islog );
void drawTex(Float_t bottomleft, Float_t topright, bool istargeted, string thirdline);

int drawMETPlot()
{

  // plotVariable = "mll";
  makeAndSavePlot( "mll"   , 10.0, 0.0, 350.0, 0.0, 5e-1, true  );
  makeAndSavePlot( "mjj"   , 10.0, 0.0, 350.0, 0.0, 5e-1, true  );
  makeAndSavePlot( "pfmet" , 25.0, 0.0, 350.0, 0.0, 5e-1, true  );
  makeAndSavePlot( "pfmeta", 25.0, 0.0, 350.0, 0.0, 5e-1, true  );
  makeAndSavePlot( "zpt"   , 25.0, 0.0, 350.0, 0.0, 5e-1, true  );
  makeAndSavePlot( "bbpt"  , 25.0, 0.0, 350.0, 0.0, 5e-1, false );
  makeAndSavePlot( "njets" , 1.0 , 2.0, 10.0 , 0.0, 5e-1, true  );

  return 0; 

}

void drawTex(Float_t bottomleft, Float_t topright, bool istargeted, string thirdline)
{

  // TLatex *tex = new TLatex(bottomleft, topright - 0.05, Form("#sqrt{s}=8 TeV, #int Ldt = %2.1f fb^{-1}", float(intlumi)));    
  TLatex *tex = new TLatex(bottomleft,topright-0.05, "Simulation" );    
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

void makeAndSavePlot( string variable, Float_t binwidth, Float_t xmin, Float_t xmax, Float_t ymin, Float_t ymax, bool islog )
{

  TCanvas * c1 = new TCanvas("canvas1", "", 1000, 1000 );
  c1->Divide(2,2);

  c1->cd(1);
  drawPlot( variable, "ee", binwidth, xmin, xmax, ymin, ymax, islog );
  c1->cd(2);
  drawPlot( variable, "mm", binwidth, xmin, xmax, ymin, ymax, islog );
  c1->cd(3);
  drawPlot( variable, "em", binwidth, xmin, xmax, ymin, ymax, islog );
  c1->cd(4);
  drawPlot( variable, "all", binwidth, xmin, xmax, ymin, ymax, islog );

  c1->cd(1)->SaveAs(Form( "~/Desktop/ZH_Plots/single_events/%s_ee_comparison_plot.pdf", variable.c_str() ));
  c1->cd(2)->SaveAs(Form( "~/Desktop/ZH_Plots/single_events/%s_mm_comparison_plot.pdf", variable.c_str() ));
  c1->cd(3)->SaveAs(Form( "~/Desktop/ZH_Plots/single_events/%s_ll_comparison_plot.pdf", variable.c_str() ));
  c1->cd(4)->SaveAs(Form( "~/Desktop/ZH_Plots/single_events/%s_all_comparison_plot.pdf", variable.c_str() ));
  c1->SaveAs(Form( "~/Desktop/ZH_Plots/%s_comparison_plot.pdf", variable.c_str() ));

			 return;

}

void drawPlot( string variable, string sample, Float_t binwidth, Float_t xmin, Float_t xmax, Float_t ymin, Float_t ymax, bool islog )
{

  TPad *pad = new TPad("p_main", "p_main", 0.0, 0.0, 1.0, 0.8);
  pad->SetBottomMargin(0.12);
  pad->SetRightMargin(0.07);
  pad->SetLeftMargin(0.18);
  pad->Draw();

  pad->cd();
  pad->cd()->SetLogy(islog);

  TFile * file = NULL;
  file = TFile::Open("photon_template_MET_data_2jetbins_all.root","READ");

  TH1F * h_sig_150 = NULL;
  TH1F * h_sig_200 = NULL;
  TH1F * h_sig_250 = NULL;
  TH1F * h_allmc   = NULL;

  // if ( sample != "em" || sample != "all" ){ 
  if ( sample != "em" ){ 
	
	h_sig_150 = (TH1F*)file->Get(Form("h_%s_%s_tchizh_150_tar" , variable.c_str(), sample.c_str() ));
	h_sig_200 = (TH1F*)file->Get(Form("h_%s_%s_tchizh_200_tar" , variable.c_str(), sample.c_str() ));
	h_sig_250 = (TH1F*)file->Get(Form("h_%s_%s_tchizh_250_tar" , variable.c_str(), sample.c_str() ));
	h_allmc   = (TH1F*)file->Get(Form("h_%s_%s_all_tar"        , variable.c_str(), sample.c_str() ));


	
  }else if ( sample == "em" ){
	
	sample = "ee";
	h_sig_150 = (TH1F*)file->Get(Form("h_%s_%s_tchizh_150_tar" , variable.c_str(), sample.c_str() ));
	h_sig_200 = (TH1F*)file->Get(Form("h_%s_%s_tchizh_200_tar" , variable.c_str(), sample.c_str() ));
	h_sig_250 = (TH1F*)file->Get(Form("h_%s_%s_tchizh_250_tar" , variable.c_str(), sample.c_str() ));
	h_allmc   = (TH1F*)file->Get(Form("h_%s_%s_all_tar"        , variable.c_str(), sample.c_str() ));
	
	sample = "mm";
	h_sig_150 -> Add((TH1F*)file->Get(Form("h_%s_%s_tchizh_150_tar" , variable.c_str(), sample.c_str() )));
	h_sig_200 -> Add((TH1F*)file->Get(Form("h_%s_%s_tchizh_200_tar" , variable.c_str(), sample.c_str() )));
	h_sig_250 -> Add((TH1F*)file->Get(Form("h_%s_%s_tchizh_250_tar" , variable.c_str(), sample.c_str() )));
	h_allmc   -> Add((TH1F*)file->Get(Form("h_%s_%s_all_tar"        , variable.c_str(), sample.c_str() )));
	sample = "em";
}

  if(variable == "mll")    h_allmc -> GetXaxis() -> SetTitle( "M_{ll} GeV" );
  if(variable == "mjj")    h_allmc -> GetXaxis() -> SetTitle( "M_{jj} GeV" );
  if(variable == "pfmet")  h_allmc -> GetXaxis() -> SetTitle( "#slash{E}_{T} GeV" );
  if(variable == "zpt")    h_allmc -> GetXaxis() -> SetTitle( "Z p_{T} GeV" );
  if(variable == "bbpt")   h_allmc -> GetXaxis() -> SetTitle( "H p_{T} GeV" );
  if(variable == "njets")  h_allmc -> GetXaxis() -> SetTitle( "# of b-jets" );

  h_allmc->SetTitle("");

  h_sig_150 -> Rebin(binwidth); 
  h_sig_200 -> Rebin(binwidth); 
  h_sig_250 -> Rebin(binwidth); 
  h_allmc   -> Rebin(binwidth); 

  // h_allmc   -> Scale( 1.0/h_allmc->GetSumOfWeights());
  // h_sig_150 -> Scale( 1.0/h_sig_150->GetSumOfWeights());
  // h_sig_200 -> Scale( 1.0/h_sig_200->GetSumOfWeights());
  // h_sig_250 -> Scale( 1.0/h_sig_250->GetSumOfWeights());

  Double_t maxy = 0.0;
  if ( h_sig_150 -> GetMaximum() > maxy ) maxy = h_sig_150 -> GetMaximum();
  if ( h_sig_200 -> GetMaximum() > maxy ) maxy = h_sig_200 -> GetMaximum();
  if ( h_sig_250 -> GetMaximum() > maxy ) maxy = h_sig_250 -> GetMaximum();
  if ( h_allmc   -> GetMaximum() > maxy ) maxy = h_allmc   -> GetMaximum();

  if ( islog ){
	ymax = maxy*1e2;
	if ( variable == "mjj" ) ymax = maxy*3e2;
  }else{
	ymax = maxy*1.2;
  }

  if ( islog && fabs( ymin ) < 1e-6 ) ymin = 1e-2;

  h_sig_150 -> GetXaxis() ->SetRangeUser( xmin, xmax );
  h_sig_200 -> GetXaxis() ->SetRangeUser( xmin, xmax );
  h_sig_250 -> GetXaxis() ->SetRangeUser( xmin, xmax );
  h_allmc   -> GetXaxis() ->SetRangeUser( xmin, xmax );

  // h_sig_150 -> GetYaxis() ->SetRangeUser( ymin, ymax );
  // h_sig_200 -> GetYaxis() ->SetRangeUser( ymin, ymax );
  // h_sig_250 -> GetYaxis() ->SetRangeUser( ymin, ymax );
  h_allmc   -> GetYaxis() ->SetRangeUser( ymin, ymax );

  h_allmc   -> SetLineColor(1);
  h_sig_150 -> SetLineColor(2);
  h_sig_200 -> SetLineColor(3);
  h_sig_250 -> SetLineColor(4);

  h_sig_150 -> SetLineWidth(2);
  h_sig_200 -> SetLineWidth(2);
  h_sig_250 -> SetLineWidth(2);
  h_allmc   -> SetLineWidth(3);

  h_sig_150 -> SetStats(0);
  h_sig_200 -> SetStats(0);
  h_sig_250 -> SetStats(0);
  h_allmc   -> SetStats(0);

  // h_allmc -> GetXaxis()->SetTitle();

  h_allmc->Draw("hist");
  h_sig_150->Draw("samehist");
  h_sig_200->Draw("samehist");
  h_sig_250->Draw("samehist");

  //Draw Legend
  TLegend *l1 = new TLegend(0.70, 0.60, 0.90, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry(h_allmc , "MC"      , "l");
  l1->AddEntry(h_sig_150, "150 1"    , "l" );    
  l1->AddEntry(h_sig_200, "200 1"  , "l" );    
  l1->AddEntry(h_sig_250, "250 1", "l" );    
  l1->Draw();

  if(sample == "ee"  ) drawTex( 0.25, 0.85, false, "Events with ee"     );
  if(sample == "mm"  ) drawTex( 0.25, 0.85, false, "Events with #mu#mu" );
  if(sample == "em"  ) drawTex( 0.25, 0.85, false, "Events with ee + #mu#mu"   );
  if(sample == "all" ) drawTex( 0.25, 0.85, false, "All Events"         );

  pad->cd()->RedrawAxis();

  return;

}

