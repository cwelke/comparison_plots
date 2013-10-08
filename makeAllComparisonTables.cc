#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "TGaxis.h"
#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TPad.h"
#include "TLine.h"
#include "TLatex.h"

using namespace std;

void makeTable( string variable, vector <Double_t> metlow );
void makeAndSaveTable( string variable, vector <Double_t> metlow );

int makeAllComparisonTables()
{

  vector <Double_t> metlow;
  metlow.push_back(0.0);
  metlow.push_back(81.0);
  metlow.push_back(91.0);
  metlow.push_back(101.0);

  makeAndSaveTable( "mt2", metlow );
  metlow.clear();

  metlow.push_back(0.0);
  metlow.push_back(121.0);
  metlow.push_back(141.0);
  metlow.push_back(161.0);
  metlow.push_back(181.0);
  makeAndSaveTable( "mlb", metlow );
  metlow.clear();

  metlow.push_back(0.0);
  metlow.push_back(201.0);
  metlow.push_back(226.0);
  metlow.push_back(251.0);
  makeAndSaveTable( "mt2j", metlow );
  metlow.clear();

  metlow.push_back(0.0);
  metlow.push_back(51.0);
  metlow.push_back(76.0);
  metlow.push_back(101.0);
  makeAndSaveTable( "pfmet", metlow );
  metlow.clear();

  return 0; 

}

void makeAndSaveTable( string variable, vector <Double_t> metlow )
{

  makeTable( variable, metlow );

			 return;

}

void makeTable( string variable, vector <Double_t> metlow )
{

  TFile * file = NULL;
  file = TFile::Open("photon_template_MET_data_2jetbins_all.root","READ");

  string sample = "";

  TH1F    * h_zjets   = NULL;
  TH1F    * h_ttbar   = NULL;
  TH1F    * h_allelse = NULL;
  TH1F    * h_allofmc = NULL;
  TH1F    * h_sig_150 = NULL;
  TH1F    * h_sig_200 = NULL;
  TH1F    * h_sig_250 = NULL;

  sample = "ee";
  h_sig_150 = (TH1F*)file->Get(Form("h_%s_%s_tchizh_150_tar" , variable.c_str(), sample.c_str() ));
  h_sig_200 = (TH1F*)file->Get(Form("h_%s_%s_tchizh_200_tar" , variable.c_str(), sample.c_str() ));
  h_sig_250 = (TH1F*)file->Get(Form("h_%s_%s_tchizh_250_tar" , variable.c_str(), sample.c_str() ));
	
  h_zjets   =       (TH1F*)file->Get(Form("h_%s_%s_zjets_tar", variable.c_str(), sample.c_str() ));
  h_ttbar   =       (TH1F*)file->Get(Form("h_%s_%s_ttbar_tar", variable.c_str(), sample.c_str() ));
  h_allelse = new TH1F("allelse", "", h_ttbar->GetXaxis()->GetNbins(), h_ttbar->GetXaxis()->GetXmin(), h_ttbar->GetXaxis()->GetXmax() );
  h_allelse->Sumw2();
  h_allelse -> Add( (TH1F*)file->Get(Form("h_%s_%s_st_tar"   , variable.c_str(), sample.c_str() )) );
  h_allelse -> Add( (TH1F*)file->Get(Form("h_%s_%s_zz_tar"   , variable.c_str(), sample.c_str() )) );
  h_allelse -> Add( (TH1F*)file->Get(Form("h_%s_%s_ww_tar"   , variable.c_str(), sample.c_str() )) );
  h_allelse -> Add( (TH1F*)file->Get(Form("h_%s_%s_wz_tar"   , variable.c_str(), sample.c_str() )) );
  h_allelse -> Add( (TH1F*)file->Get(Form("h_%s_%s_ttv_tar"  , variable.c_str(), sample.c_str() )) );
  h_allelse -> Add( (TH1F*)file->Get(Form("h_%s_%s_vvv_tar"  , variable.c_str(), sample.c_str() )) );

  sample = "mm";
  h_sig_150 -> Add((TH1F*)file->Get(Form("h_%s_%s_tchizh_150_tar" , variable.c_str(), sample.c_str() )));
  h_sig_200 -> Add((TH1F*)file->Get(Form("h_%s_%s_tchizh_200_tar" , variable.c_str(), sample.c_str() )));
  h_sig_250 -> Add((TH1F*)file->Get(Form("h_%s_%s_tchizh_250_tar" , variable.c_str(), sample.c_str() )));

  h_zjets   -> Add( (TH1F*)file->Get(Form("h_%s_%s_zjets_tar", variable.c_str(), sample.c_str() )) );
  h_ttbar   -> Add( (TH1F*)file->Get(Form("h_%s_%s_ttbar_tar", variable.c_str(), sample.c_str() )) );
  h_allelse -> Add( (TH1F*)file->Get(Form("h_%s_%s_st_tar"   , variable.c_str(), sample.c_str() )) );
  h_allelse -> Add( (TH1F*)file->Get(Form("h_%s_%s_zz_tar"   , variable.c_str(), sample.c_str() )) );
  h_allelse -> Add( (TH1F*)file->Get(Form("h_%s_%s_ww_tar"   , variable.c_str(), sample.c_str() )) );
  h_allelse -> Add( (TH1F*)file->Get(Form("h_%s_%s_wz_tar"   , variable.c_str(), sample.c_str() )) );
  h_allelse -> Add( (TH1F*)file->Get(Form("h_%s_%s_ttv_tar"  , variable.c_str(), sample.c_str() )) );
  h_allelse -> Add( (TH1F*)file->Get(Form("h_%s_%s_vvv_tar"  , variable.c_str(), sample.c_str() )) );

  sample = "em";
  h_allofmc =      (TH1F*)file->Get(Form("h_%s_%s_all_tar"        , variable.c_str(), sample.c_str() ));
  h_allofmc -> Add((TH1F*)file->Get(Form("h_%s_%s_tchizh_150_tar" , variable.c_str(), sample.c_str() )));
  h_allofmc -> Add((TH1F*)file->Get(Form("h_%s_%s_tchizh_200_tar" , variable.c_str(), sample.c_str() )));
  h_allofmc -> Add((TH1F*)file->Get(Form("h_%s_%s_tchizh_250_tar" , variable.c_str(), sample.c_str() )));

  ofstream fout(Form("yield_tables_%s.txt", variable.c_str()));

  const unsigned int ncuts = metlow.size();
  const unsigned int methigh = h_zjets->GetXaxis()->GetNbins() + 1;

  Double_t zval[ncuts];
  Double_t zerr[ncuts];

  Double_t tval[ncuts];
  Double_t terr[ncuts];

  Double_t oval[ncuts];
  Double_t oerr[ncuts];

  Double_t ofval[ncuts];
  Double_t oferr[ncuts];

  Double_t sval[3][ncuts];
  Double_t serr[3][ncuts];

  vector <string> samplename;
  samplename.push_back("Z + jets");
  samplename.push_back("ttbar");
  samplename.push_back("Other");
  samplename.push_back("OF Prediction");
  samplename.push_back("Total bg");
  samplename.push_back("150 ");
  samplename.push_back("200 ");
  samplename.push_back("250 ");

  for ( unsigned int i = 0; i < ncuts; i++ ){

	for ( unsigned int j = 0; j < 3; j++ ){

	  sval[j][i] = 0.0;
	  sval[j][i] = 0.0;

	}

	zval[i]  = 0.0;
	zerr[i]  = 0.0;
	tval[i]  = 0.0;
	terr[i]  = 0.0;
	oval[i]  = 0.0;
	oerr[i]  = 0.0;
	ofval[i] = 0.0;
	oferr[i] = 0.0;

  }

  for ( unsigned int i = 0; i < ncuts; i++ ){

	for ( unsigned int j = 0; j < 3; j++ ){

	  if (j == 0 ) sval[j][i] = h_sig_150   -> IntegralAndError( metlow[i], methigh, serr[j][i]);
	  if (j == 1 ) sval[j][i] = h_sig_200   -> IntegralAndError( metlow[i], methigh, serr[j][i]);
	  if (j == 2 ) sval[j][i] = h_sig_250   -> IntegralAndError( metlow[i], methigh, serr[j][i]);

	}

	zval[i]  = h_zjets   -> IntegralAndError( metlow[i], methigh, zerr[i]  );
	tval[i]  = h_ttbar   -> IntegralAndError( metlow[i], methigh, terr[i]  );
	oval[i]  = h_allelse -> IntegralAndError( metlow[i], methigh, oerr[i]  );
	ofval[i] = h_allofmc -> IntegralAndError( metlow[i], methigh, oferr[i] );

  }

  fout<<fixed;

  fout<<
	"\\begin{table}[htb]"<<endl<<
	"\\begin{center}"<<endl<<
	"\\footnotesize"<<endl<<
	"\\begin{tabular}{l|";
  for ( unsigned int i = 0; i < ncuts-1; i++ ){
	fout<<"c|";
  }
  fout<<
	"c}"<<endl<<
	"\\hline"<<endl<<
	"\\hline"<<endl;

  fout<<setw(18)<<Form("%s & ", variable.c_str());
  for ( unsigned int i = 0; i < ncuts; i++ ){
	if (i != ncuts - 1) fout<<setw(18)<<Form(" $> %.0f$~$GeV$ & ", max(metlow[i] - 1.0, 0.0));
	if (i == ncuts - 1) fout<<setw(18)<<Form(" $> %.0f$~$GeV$ ", max(metlow[i] - 1.0, 0.0));
  }

  fout<<" \\\\"<<endl;
  fout<<"\\hline"<<endl;
	
  for (size_t j = 0; j < samplename.size(); j ++){

	fout<<setw(18)<<Form("%s & ", samplename.at(j).c_str());

	for ( unsigned int i = 0; i < ncuts; i++ ){

	  if(i != ncuts - 1){ 
		if ( j == 0 )       {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f & ", zval[i],    zerr[i]);
		}else if ( j == 1 ) {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f & ", tval[i],    terr[i]);
		}else if ( j == 2 ) {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f & ", oval[i],    oerr[i]);
		}else if ( j == 3 ) {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f & ", ofval[i],   oferr[i]);
		}else if ( j == 4 ) {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f & ", zval[i] + tval[i] + oval[i], sqrt( pow(zerr[i],2) + pow(terr[i],2) + pow(oerr[i],2)));
		}else if ( j == 5 ) {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f & ", sval[0][i], serr[0][i]);
		}else if ( j == 6 ) {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f & ", sval[1][i], serr[1][i]);
		}else if ( j == 7 ) {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f & ", sval[2][i], serr[2][i]);
		}
	  }
	  if(i == ncuts - 1){ 
		if ( j == 0 )       {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f  ", zval[i],    zerr[i]);
		}else if ( j == 1 ) {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f  ", tval[i],    terr[i]);
		}else if ( j == 2 ) {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f  ", oval[i],    oerr[i]);
		}else if ( j == 3 ) {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f  ", ofval[i],   oferr[i]);
		}else if ( j == 4 ) {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f  ", zval[i] + tval[i] + oval[i], sqrt( pow(zerr[i],2) + pow(terr[i],2) + pow(oerr[i],2)));
		}else if ( j == 5 ) {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f  ", sval[0][i], serr[0][i]);
		}else if ( j == 6 ) {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f  ", sval[1][i], serr[1][i]);
		}else if ( j == 7 ) {fout<<setw(18)<<Form( "%.1f $\\pm$ %.1f  ", sval[2][i], serr[2][i]);
		}
	  }
	}

	fout<<" \\\\"<<endl;
	if(j == 2){        fout<<"\\hline"<<endl;
	}else if(j == 3){  fout<<"\\hline"<<endl;
	}else if(j == 4){  fout<<"\\hline"<<endl;
	}
	  	 
  }

  samplename.clear();
  samplename.push_back("{\\ensuremath{\\frac{Signal}{\\sqrt{Background}}}}");
  samplename.push_back("150 ");
  samplename.push_back("200 ");
  samplename.push_back("250 ");

  fout<<
	"\\hline"<<
	"\\hline"<<
	endl;

  for (size_t j = 0; j < samplename.size(); j ++){
	
	fout<<setw(18)<<Form("%s & ", samplename.at(j).c_str());

	for ( unsigned int i = 0; i < ncuts; i++ ){

	  if(i != ncuts - 1){ 
		
		if ( j == 0 )       {fout<<setw(18)<<" & ";
		}else if ( j == 1 ) {fout<<setw(18)<<Form( "%.1f & ", sval[0][i]/sqrt( zval[i] + tval[i] + oval[i] ));
		}else if ( j == 2 ) {fout<<setw(18)<<Form( "%.1f & ", sval[1][i]/sqrt( zval[i] + tval[i] + oval[i] ));
		}else if ( j == 3 ) {fout<<setw(18)<<Form( "%.1f & ", sval[2][i]/sqrt( zval[i] + tval[i] + oval[i] ));
		} 
	  }
	  if(i == ncuts - 1){ 
		
		if ( j == 0 )       {fout<<setw(18)<<" ";
		}else if ( j == 1 ) {fout<<setw(18)<<Form( "%.1f  ", sval[0][i]/sqrt( zval[i] + tval[i] + oval[i] ));
		}else if ( j == 2 ) {fout<<setw(18)<<Form( "%.1f  ", sval[1][i]/sqrt( zval[i] + tval[i] + oval[i] ));
		}else if ( j == 3 ) {fout<<setw(18)<<Form( "%.1f  ", sval[2][i]/sqrt( zval[i] + tval[i] + oval[i] ));
		}
	  }
	}	  
	fout<<" \\\\"<<endl;
	if(j == 0)fout<<"\\hline"<<endl;

  }
  
  
  fout<<
	"\\hline"<<endl<<
	"\\hline"<<endl<<
	"\\end{tabular}"<<endl<<
	"\\end{center}"<<endl<<
	"\\end{table}"<<
	endl;
  
  

  fout.close();

  return;

}

