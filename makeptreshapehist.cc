#include <vector>
#include <iostream>

#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"

using namespace std;
TH1F* setbinning(TH1F * hist, vector <Double_t> bins);

int makeptreshapehist()
{
  TFile * openfile = TFile::Open("photon_template_MET_data_2jetbins_all.root","READ");
  // TFile * reweightfile = new TFile("pTreshape.root");

  // string variable = "met_ll";
  string variable = "zpt_ll";
  string isgen = "";

  TH1F * h_zjets_0b   = NULL;
  TH1F * h_zjets_2b   = NULL;

  h_zjets_0b = (TH1F*)openfile->Get( Form("h_%s_0%sb_inc", variable.c_str(), isgen.c_str() ) )->Clone("h_zjets_0b");
  h_zjets_2b = (TH1F*)openfile->Get( Form("h_%s_2%sb_inc", variable.c_str(), isgen.c_str() ) )->Clone("h_zjets_2b");

  h_zjets_0b->Scale(1.0/h_zjets_0b->GetSumOfWeights());
  h_zjets_2b->Scale(1.0/h_zjets_2b->GetSumOfWeights());

  vector <Double_t> binning;
  binning.push_back(0.0);
  binning.push_back(10.0);
  binning.push_back(20.0);
  binning.push_back(30.0);
  binning.push_back(40.0);
  binning.push_back(50.0);
  binning.push_back(60.0);
  binning.push_back(70.0);
  binning.push_back(80.0);
  binning.push_back(90.0);
  binning.push_back(100.0);
  binning.push_back(125.0);
  binning.push_back(150.0);
  binning.push_back(200.0);
  binning.push_back(250.0);

  TH1F * h_zjets_0b_rebinned = NULL;  
  TH1F * h_zjets_2b_rebinned = NULL;

  h_zjets_0b_rebinned = setbinning(h_zjets_0b, binning);
  h_zjets_2b_rebinned = setbinning(h_zjets_2b, binning);

  h_zjets_0b_rebinned->Scale(1.0/h_zjets_0b_rebinned->GetSumOfWeights());
  h_zjets_2b_rebinned->Scale(1.0/h_zjets_2b_rebinned->GetSumOfWeights());

  h_zjets_0b_rebinned->SetLineColor(1);
  h_zjets_2b_rebinned->SetLineColor(2);

  h_zjets_0b->SetLineColor(1);
  h_zjets_2b->SetLineColor(2);

  h_zjets_0b->Rebin(10);
  h_zjets_2b->Rebin(10);

  TH1F * ratio = (TH1F*) h_zjets_2b_rebinned->Clone("numerator");
  TH1F * ratio2 = (TH1F*) h_zjets_2b->Clone("numerator");
  
  ratio->Divide(h_zjets_0b_rebinned);
  ratio2->Divide(h_zjets_0b);

  // h_zjets_0b_rebinned->Scale(1.0/h_zjets_0b_rebinned->GetSumOfWeights());
  // h_zjets_0b->Scale(1.0/h_zjets_0b->GetSumOfWeights());
  // h_zjets_2b_rebinned->SetLineColor(1.0/h_zjets_2b_rebinned->GetSumOfWeights());

  TCanvas * c1 = new TCanvas("can1");

  h_zjets_0b->Draw("hist");
  h_zjets_2b->Draw("histsame");
  h_zjets_0b_rebinned->Draw("histsame");
  h_zjets_2b_rebinned->Draw("histsame");

  c1->SetLogy();

  TCanvas * c2 = new TCanvas("can2");
  c2->cd();

  ratio->Draw();
  // ratio2->Draw("same");

  c2->SetLogy();

  return 0;
}

// TH1F* makeratio(TH1F * numerator, TH1F * denominator)
// {
// numerator
// }

TH1F* setbinning(TH1F * hist, vector <Double_t> bins)
{
  Int_t nbins = bins.size()+1;
  Double_t xbins[nbins];
  for( size_t bini = 0; bini < bins.size(); bini++ ){
	xbins[bini] = bins.at(bini);
  }
  xbins[nbins-1] = hist->GetNbinsX();
	// cout<<xbins[nbins-1]<<endl;

  TH1F* hist_rebinned = new TH1F(Form("%s_rebinned",hist->GetName() ),"", nbins-1, xbins );

  Int_t   bin[nbins];
  Float_t binval[nbins];
  Double_t binerr[nbins];

  for( size_t bini = 0; bini < nbins; bini++ ){
	bin[bini] = hist->FindBin(xbins[bini]);
  }

  for( size_t bini = 1; bini < nbins; bini++ ){
	binval[bini] = hist->IntegralAndError( bin[bini-1], bin[bini]-1, binerr[bini] );
	hist_rebinned->SetBinContent(bini, binval[bini]);
	hist_rebinned->SetBinError(bini, binerr[bini]);
  }

  return hist_rebinned;
}
