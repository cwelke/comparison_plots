#include <string>
#include <vector>
#include <iostream>

#include "TLegend.h"
#include "TH1F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TPad.h"

using namespace std;

void drawHist( TFile * file, string variable = "zpt", string isgen = "gen", 
			   Float_t binwidth = 10.0, Float_t xmin = 0.0, Float_t xmax = 350.0, bool islog = true );
void drawRatio( TFile * file, string variable = "zpt", string isgen = "gen", 
				Float_t binwidth = 10.0, Float_t xmin = 0.0, Float_t xmax = 350.0 );
int drawPlot( string variable, string isgen, Float_t binwidth, Float_t xmin, Float_t xmax, bool islog );

int compareMETShape()
{

  vector <string> channel;
  channel.push_back("ll");
  channel.push_back("ll2jets");
  channel.push_back("ll3jets");

  vector <string> variable;
  variable.push_back("met");
  variable.push_back("genmet");
  variable.push_back("zpt");

  Float_t binwidth = 0.0;
  Float_t xmin = 0.0;
  Float_t xmax = 0.0;

  for( size_t channeli = 0; channeli < channel.size(); channeli++ ){

	  drawPlot( Form( "zpt_%s", channel.at(channeli).c_str() ),"", 10.0, 0.0, 290.0, true );
	  drawPlot( Form( "zpt_%s", channel.at(channeli).c_str() ),"gen", 10.0, 0.0, 290.0, true );
	  drawPlot( Form( "vecjetpt_%s", channel.at(channeli).c_str() ),"", 10.0, 0.0, 290.0, true );
	  drawPlot( Form( "vecjetpt_%s", channel.at(channeli).c_str() ),"gen", 10.0, 0.0, 290.0, true );
	  drawPlot( Form( "realmetzpt_%s", channel.at(channeli).c_str() ),"", 10.0, 0.0, 290.0, true );
	  drawPlot( Form( "realmetzpt_%s", channel.at(channeli).c_str() ),"gen", 10.0, 0.0, 290.0, true );
	  drawPlot( Form( "fakemetzpt_%s", channel.at(channeli).c_str() ),"", 10.0, 0.0, 290.0, true );
	  drawPlot( Form( "fakemetzpt_%s", channel.at(channeli).c_str() ),"gen", 10.0, 0.0, 290.0, true );
	  // drawPlot( Form( "zpt_%s", channel.at(channeli).c_str() ),"stat3gen", 10.0, 0.0, 290.0, true );

	  drawPlot( Form( "ht_%s", channel.at(channeli).c_str() ),"", 25.0, 0.0, 500.0, true );
	  drawPlot( Form( "ht_%s", channel.at(channeli).c_str() ),"gen", 25.0, 0.0, 500.0, true );
	  drawPlot( Form( "realmetht_%s", channel.at(channeli).c_str() ),"", 25.0, 0.0, 500.0, true );
	  drawPlot( Form( "realmetht_%s", channel.at(channeli).c_str() ),"gen", 25.0, 0.0, 500.0, true );
	  drawPlot( Form( "fakemetht_%s", channel.at(channeli).c_str() ),"", 25.0, 0.0, 500.0, true );
	  drawPlot( Form( "fakemetht_%s", channel.at(channeli).c_str() ),"gen", 25.0, 0.0, 500.0, true );
	  // drawPlot( Form( "ht_%s", channel.at(channeli).c_str() ),"stat3gen", 10.0, 0.0, 290.0, true );

	  drawPlot( Form( "met_%s", channel.at(channeli).c_str() ),"", 10.0, 0.0, 140.0, true );
	  drawPlot( Form( "met_%s", channel.at(channeli).c_str() ),"gen", 10.0, 0.0, 140.0, true );
	  drawPlot( Form( "metsr_%s", channel.at(channeli).c_str() ),"", 10.0, 0.0, 140.0, true );
	  drawPlot( Form( "metsr_%s", channel.at(channeli).c_str() ),"gen", 10.0, 0.0, 140.0, true );
	  drawPlot( Form( "metmlbsr_%s", channel.at(channeli).c_str() ),"", 10.0, 0.0, 140.0, true );
	  drawPlot( Form( "metmlbsr_%s", channel.at(channeli).c_str() ),"gen", 10.0, 0.0, 140.0, true );
	  drawPlot( Form( "metmt2jsr_%s", channel.at(channeli).c_str() ),"", 10.0, 0.0, 140.0, true );
	  drawPlot( Form( "metmt2jsr_%s", channel.at(channeli).c_str() ),"gen", 10.0, 0.0, 140.0, true );
	  drawPlot( Form( "realmet_%s", channel.at(channeli).c_str() ),"", 10.0, 0.0, 140.0, true );
	  drawPlot( Form( "realmet_%s", channel.at(channeli).c_str() ),"gen", 10.0, 0.0, 140.0, true );
	  drawPlot( Form( "fakemet_%s", channel.at(channeli).c_str() ),"", 10.0, 0.0, 140.0, true );
	  drawPlot( Form( "fakemet_%s", channel.at(channeli).c_str() ),"gen", 10.0, 0.0, 140.0, true );
	  // drawPlot( Form( "met_%s", channel.at(channeli).c_str() ),"stat3gen", 10.0, 0.0, 140.0, true );
	  drawPlot( Form( "genmet_%s", channel.at(channeli).c_str() ),"", 10.0, 0.0, 140.0, true );
	  drawPlot( Form( "genmet_%s", channel.at(channeli).c_str() ),"gen", 10.0, 0.0, 140.0, true );
	  // drawPlot( Form( "genmet_%s", channel.at(channeli).c_str() ),"stat3gen", 10.0, 0.0, 140.0, true );

	  drawPlot( Form( "metht150200_%s", channel.at(channeli).c_str() ),"", 10.0, 0.0, 140.0, true );
	  drawPlot( Form( "metht150200_%s", channel.at(channeli).c_str() ),"gen", 10.0, 0.0, 140.0, true );

  }

  variable.clear();
  variable.push_back("njets");
  variable.push_back("eventtype");
  variable.push_back("nltags");
  variable.push_back("mcfa1");
  variable.push_back("mcfa2");
  variable.push_back("mcfa3");
  variable.push_back("csv1");
  variable.push_back("csv2");
  variable.push_back("csv3");

  for( size_t channeli = 0; channeli < channel.size(); channeli++ ){
	for( size_t variablei = 0; variablei < variable.size(); variablei++ ){

	  if(variable.at(variablei) == "njets"){ binwidth = 1.0; xmin = 2.0; xmax = 4.0; }
	  if(variable.at(variablei) == "eventtype"){ binwidth = 1.0; xmin = -1.0; xmax = 4.0; }
	  if(variable.at(variablei) == "nltags"){ binwidth = 1.0; xmin = 0.0; xmax = 4.0; }
	  if(variable.at(variablei) == "mcfa1"){ binwidth = 1.0; xmin = 0.0; xmax = 25.0; }
	  if(variable.at(variablei) == "mcfa2"){ binwidth = 1.0; xmin = 0.0; xmax = 25.0; }
	  if(variable.at(variablei) == "mcfa3"){ binwidth = 1.0; xmin = 0.0; xmax = 25.0; }
	  if(variable.at(variablei) == "csv1"){ binwidth = 5; xmin = 0.0; xmax = 1.0; }
	  if(variable.at(variablei) == "csv2"){ binwidth = 5; xmin = 0.0; xmax = 1.0; }
	  if(variable.at(variablei) == "csv3"){ binwidth = 5; xmin = 0.0; xmax = 1.0; }

	  drawPlot( Form( "%s_%s", variable.at(variablei).c_str(), channel.at(channeli).c_str() ),"",         binwidth, xmin, xmax, false );
	  drawPlot( Form( "%s_%s", variable.at(variablei).c_str(), channel.at(channeli).c_str() ),"gen",      binwidth, xmin, xmax, false );
	  // drawPlot( Form( "%s_%s", variable.at(variablei).c_str(), channel.at(channeli).c_str() ),"stat3gen", binwidth, xmin, xmax, false );

	}
  }

  return 0;
}

int drawPlot( string variable, string isgen, Float_t binwidth, Float_t xmin, Float_t xmax, bool islog )
{

  TCanvas * c1 = new TCanvas( (variable+isgen).c_str(), (variable+isgen).c_str(), 600, 600 );

  TFile * openfile = TFile::Open("photon_template_MET_data_2jetbins_all.root","READ");

  c1->cd();
  drawHist( openfile, variable, isgen, binwidth, xmin, xmax, islog );
  c1->cd();
  drawRatio( openfile, variable, isgen, binwidth, xmin, xmax );

  c1->SaveAs(Form("~/Desktop/b_studies/%s_%s_shape.pdf", variable.c_str(), isgen.c_str() ) );
  openfile->Close();

  return 0;
}

void drawHist( TFile * file, string variable, string isgen, Float_t binwidth, Float_t xmin, Float_t xmax, bool islog )
{

  TH1F * h_zjets_0b   = NULL;
  TH1F * h_zjets_2b   = NULL;

  h_zjets_0b   = (TH1F*)file->Get( Form("h_%s_0%sb_inc", variable.c_str(), isgen.c_str() ) )->Clone("h_zjets_0b");
  h_zjets_2b   = (TH1F*)file->Get( Form("h_%s_2%sb_inc", variable.c_str(), isgen.c_str() ) )->Clone("h_zjets_2b");

  h_zjets_0b   -> Rebin(binwidth); 
  h_zjets_2b   -> Rebin(binwidth); 

  h_zjets_0b->SetLineColor(1);
  h_zjets_2b->SetLineColor(2);

  h_zjets_0b->Scale( 1.0/h_zjets_0b->GetSumOfWeights() );
  h_zjets_2b->Scale( 1.0/h_zjets_2b->GetSumOfWeights() );

  h_zjets_0b->GetXaxis()->SetRangeUser(xmin,xmax);

  for ( unsigned int bini = (unsigned int)xmax/binwidth+1; bini < h_zjets_0b->GetNbinsX() + 1; bini++ ){	
	h_zjets_0b->AddBinContent( (unsigned int)xmax/binwidth+1, h_zjets_0b->GetBinContent(bini) );
	h_zjets_2b->AddBinContent( (unsigned int)xmax/binwidth+1, h_zjets_2b->GetBinContent(bini) );
  }

  TPad *padh = new TPad("p_hist", "p_hist", 0.0, 0.0, 1.0, 0.8);
  padh->SetBottomMargin(0.12);
  padh->SetRightMargin(0.07);
  padh->SetLeftMargin(0.18);
  padh->Draw();
  padh->cd();

  if ( !islog ){
	h_zjets_0b->GetYaxis()->SetRangeUser( 0.0, h_zjets_0b->GetYaxis()->GetXmax() );
  }

  // h_zjets_0b->GetYaxis()->SetTitle(Form("#frac{Events}{%.0f GeV}", binwidth ) );
  // h_zjets_0b->GetYaxis()->SetTitleOffset(1.5);

  // cout<<variable<<endl;
  vector <string> suffix;
  suffix.push_back("_ll");
  suffix.push_back("_ll2jets");
  suffix.push_back("_ll3jets");

  vector <string> prefix;
  prefix.push_back("");
  prefix.push_back("realmet");
  prefix.push_back("fakemet");

  for( size_t suffixi = 0; suffixi < suffix.size(); suffixi++ ){

	for( size_t prefixi = 0; prefixi < prefix.size(); prefixi++ ){
	  if (variable == Form("%szpt%s", prefix.at(prefixi).c_str(), 
						   suffix.at(suffixi).c_str() ) ) h_zjets_0b -> GetXaxis() -> SetTitle( "Z P_{T} GeV"        );
	  if (variable == Form("%svecjetpt%s", prefix.at(prefixi).c_str(), 
						   suffix.at(suffixi).c_str() ) ) h_zjets_0b -> GetXaxis() -> SetTitle( "Jet System P_{T} GeV"        );
	  if (variable == Form("%sht%s", prefix.at(prefixi).c_str(),
						   suffix.at(suffixi).c_str() ) ) h_zjets_0b -> GetXaxis() -> SetTitle( "H_{T} GeV"        );
	}

	if (variable == Form("met%s", suffix.at(suffixi).c_str() )     ) h_zjets_0b -> GetXaxis() -> SetTitle( "MET GeV"            );
	if (variable == Form("metht150200%s", suffix.at(suffixi).c_str() )     ) h_zjets_0b -> GetXaxis() -> SetTitle( "MET GeV"            );
	if (variable == Form("realmet%s", suffix.at(suffixi).c_str() )     ) h_zjets_0b -> GetXaxis() -> SetTitle( "MET GeV"            );
	if (variable == Form("fakemet%s", suffix.at(suffixi).c_str() )     ) h_zjets_0b -> GetXaxis() -> SetTitle( "MET GeV"            );

	if (variable == Form("genmet%s", suffix.at(suffixi).c_str() )  ) h_zjets_0b -> GetXaxis() -> SetTitle( "gen MET GeV"        );
	if (variable == Form("njets%s", suffix.at(suffixi).c_str() )   ) h_zjets_0b -> GetXaxis() -> SetTitle( "\# of jets"         );
	if (variable == Form("nltags%s", suffix.at(suffixi).c_str() )  ) h_zjets_0b -> GetXaxis() -> SetTitle( "\# of loose b tags" );
	
  }
  
  h_zjets_0b->Draw("histE1");
  h_zjets_2b->Draw("samehistE1");

  if ( islog ){
	padh->SetLogy();
  }

  //Draw Legend
  TLegend *l1 = new TLegend(0.60, 0.60, 0.90, 0.90);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  if( isgen == "" ){  
	l1->AddEntry(h_zjets_0b , "0 tagged b's"      , "l");
	l1->AddEntry(h_zjets_2b , "2 tagged b's"      , "l");
  }else  if( isgen == "gen" ){  
	l1->AddEntry(h_zjets_0b , "0 MCFA b's"      , "l");
	l1->AddEntry(h_zjets_2b , "2 MCFA b's"      , "l");
  }else  if( isgen == "stat3gen" ){  
	l1->AddEntry(h_zjets_0b , "0 status 3 b's"      , "l");
	l1->AddEntry(h_zjets_2b , "2 status 3 b's"      , "l");
  }
  l1->Draw();

}

void drawRatio( TFile * file, string variable, string isgen, Float_t binwidth, Float_t xmin, Float_t xmax )
{

  TPad *pad = new TPad("p_hist", "p_hist", 0.0, 0.8, 1.0, 1.0);
  pad->SetBottomMargin(0.12);
  pad->SetRightMargin(0.07);
  pad->SetLeftMargin(0.18);
  pad->Draw();
  pad->cd();

  // TH1F * h_data = NULL;
  TH1F * h_zjets_2b   = NULL;
  TH1F * h_zjets_0b  = NULL;

  h_zjets_0b   = (TH1F*)file->Get( Form("h_%s_0%sb_inc", variable.c_str(), isgen.c_str() ) );
  h_zjets_2b   = (TH1F*)file->Get( Form("h_%s_2%sb_inc", variable.c_str(), isgen.c_str() ) );
  // h_zjets_2b    = (TH1F*)file->Get( Form("h_%s_ll_2genb_inc", variable.c_str() ) );
  // h_zjets_0b   = (TH1F*)file->Get( Form("h_%s_ll_0genb_inc", variable.c_str() ) );

  // h_zjets_2b    ->Add ((TH1F*)file->Get( Form("h_%s_mm_2genb_inc", variable.c_str() ) ));
  // h_zjets_0b   ->Add ((TH1F*)file->Get( Form("h_%s_mm_0genb_inc", variable.c_str() ) ));

  h_zjets_0b->Scale( 1.0/h_zjets_0b->GetSumOfWeights() );
  h_zjets_2b->Scale( 1.0/h_zjets_2b->GetSumOfWeights() );

  h_zjets_0b -> Rebin(binwidth);
  h_zjets_2b  -> Rebin(binwidth);

  h_zjets_0b->GetXaxis()->SetRangeUser(xmin,xmax);

  for ( unsigned int bini = (unsigned int)xmax/binwidth+1; bini < h_zjets_0b->GetNbinsX() + 1; bini++ ){
	
	h_zjets_0b->AddBinContent( (unsigned int)xmax/binwidth+1, h_zjets_0b->GetBinContent(bini) );
	h_zjets_2b->AddBinContent( (unsigned int)xmax/binwidth+1, h_zjets_2b->GetBinContent(bini) );
	
  }

  h_zjets_0b -> SetLineColor(kBlack);
  h_zjets_0b -> SetMarkerStyle(20);
  h_zjets_0b -> SetMarkerSize(0.5);

  h_zjets_0b -> GetXaxis() ->SetRangeUser( xmin, xmax );
  h_zjets_2b -> GetXaxis() ->SetRangeUser( xmin, xmax );

  h_zjets_0b -> SetStats(0);
  h_zjets_2b -> SetStats(0);

  h_zjets_0b->Divide(h_zjets_2b);

  h_zjets_0b->GetXaxis()->SetLabelSize(0);

  pad->SetGridy(1);


  if( isgen == "" )  h_zjets_0b->GetYaxis()->SetTitle("#frac{0 b-tags}{2 b-tags}");
  if( isgen == "stat3gen" )  h_zjets_0b->GetYaxis()->SetTitle("#frac{0 status 3 b's}{2 status 3 b's}");
  if( isgen == "gen" )  h_zjets_0b->GetYaxis()->SetTitle("#frac{0 MCFlavAlgo b's}{2 MCFlavAlgo b's}");

  // h_zjets_0b->GetXaxis()->SetLabelSize(0);
  h_zjets_0b->GetYaxis()->SetRangeUser(0.,2.);
  h_zjets_0b->GetYaxis()->SetNdivisions(5);
  h_zjets_0b->GetYaxis()->SetTitleSize(0.1);
  h_zjets_0b->GetYaxis()->SetTitleOffset(0.5);
  h_zjets_0b->GetYaxis()->SetLabelSize(0.1);


  h_zjets_0b->SetTitle("");
  // h_zjets_0b->GetXaxis()->SetLabelSize(0);
  // h_zjets_0b->GetYaxis()->SetLabelSize(0.075);

  h_zjets_0b->Draw();

}
