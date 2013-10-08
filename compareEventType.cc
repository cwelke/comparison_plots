#include <string>
#include <vector>
#include <iostream>

#include "TLegend.h"
#include "TH1F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TPad.h"

int compareEventType ()
{

  TCanvas * c1 = new TCanvas( "eventtype", "", 600, 600 );
  TFile * file = TFile::Open("photon_template_MET_data_2jetbins_all.root","READ");

  TH1F * h_zjets_mlb    = NULL;
  TH1F * h_zjets_mt2j   = NULL;

  h_zjets_mlb    = (TH1F*)file->Get( "h_eventtypemlbsr_ll_2b_inc"  )->Clone("h_zjets_mlb" );
  h_zjets_mt2j   = (TH1F*)file->Get( "h_eventtypemt2jsr_ll_2b_inc" )->Clone("h_zjets_mt2j");

  h_zjets_mlb ->SetLineColor(1);
  h_zjets_mt2j->SetLineColor(2);

  h_zjets_mlb  -> GetXaxis()->SetRangeUser(0,4);
  h_zjets_mt2j -> GetXaxis()->SetRangeUser(0,4);

  h_zjets_mt2j -> GetXaxis()->SetTitle("MCFA of jet1, jet2");
  h_zjets_mt2j -> GetYaxis()->SetTitle("\# of Events");
  h_zjets_mt2j -> GetYaxis()->SetTitleOffset(1.2);

  h_zjets_mt2j -> GetXaxis()->SetBinLabel( 2, "jj");
  h_zjets_mt2j -> GetXaxis()->SetBinLabel( 3, "bj");
  h_zjets_mt2j -> GetXaxis()->SetBinLabel( 4, "jb");
  h_zjets_mt2j -> GetXaxis()->SetBinLabel( 5, "bb");

  h_zjets_mt2j -> GetXaxis()->CenterLabels();

  TPad *padh = new TPad("p_hist", "p_hist", 0.0, 0.0, 1.0, 1.0);
  padh->SetBottomMargin(0.12);
  padh->SetRightMargin(0.07);
  padh->SetLeftMargin(0.18);
  padh->Draw();
  padh->cd();

  h_zjets_mt2j-> Draw("histE1");
  h_zjets_mlb -> Draw("histsameE1");


  //Draw Legend
  TLegend *l1 = new TLegend(0.20, 0.60, 0.60, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry(h_zjets_mlb  , "min(m_{l,b}) > 120 GeV"      , "l");
  l1->AddEntry(h_zjets_mt2j , "M_{T}^{2J} > 200 GeV"      , "l");
  l1->Draw();

  c1->SaveAs("~/Desktop/eventtype.pdf");

  return 0;
}
