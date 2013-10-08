#include <iostream>
#include "TFile.h"
#include "TH1F.h"

using namespace std;

//______________________________________________________________________________
// returns the error on C = A*B (or C = A/B)
float err_mult(float A, float B, float errA, float errB, float C) {
  return sqrt(C*C*(pow(errA/A,2) + pow(errB/B,2)));
}

int gethighMETtable( string searchRegion = "" )
{

  cout<<"Getting yields for: "<<searchRegion<<endl;

  TFile * file = TFile::Open( "photon_template_MET_data_2jetbins_all.root", "READ" );
  
  TH1F    * h_data  = NULL;
  TH1F    * h_zjets = NULL;
  TH1F    * h_wz    = NULL;
  TH1F    * h_zz    = NULL;
  TH1F    * h_ttbar = NULL;
  TH1F    * h_fsbg  = NULL;
  TH1F    * h_st    = NULL;
  TH1F    * h_ww    = NULL;
  TH1F    * h_ttv   = NULL;
  TH1F    * h_vvv   = NULL;
  TH1F    * h_smzh  = NULL;
  TH1F    * h_tbz   = NULL;
  TH1F    * h_allmc = NULL;

  string sample = "ll";

  bool dofsprediction = true;

  string variable = "mll";
  // searchRegion = "met120";

  // string variable = "mll";
  // string searchRegion = "dilep";

  // searchRegion = "2btag1_met120";
  // searchRegion = "bveto3_met120";


  //get histos from file
  h_data  =     (TH1F*)file->Get(Form("h_%s_%s_data_%s"  , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_data");
  h_zjets =     (TH1F*)file->Get(Form("h_%s_%s_zjets_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_zjets");
  h_wz    =     (TH1F*)file->Get(Form("h_%s_%s_wz_%s"    , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_wz");
  h_zz    =     (TH1F*)file->Get(Form("h_%s_%s_zz_%s"    , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_zz");
  h_ttbar =     (TH1F*)file->Get(Form("h_%s_%s_ttbar_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_ttbar");
  h_fsbg  =     (TH1F*)file->Get(Form("h_%s_em_data_%s"  , variable.c_str(),                 searchRegion.c_str() )) -> Clone("h_fsbg");
  h_st    =     (TH1F*)file->Get(Form("h_%s_%s_st_%s"    , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_st");
  h_ww    =     (TH1F*)file->Get(Form("h_%s_%s_ww_%s"    , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_ww");
  h_ttv   =     (TH1F*)file->Get(Form("h_%s_%s_ttv_%s"   , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_ttv");
  h_vvv   =     (TH1F*)file->Get(Form("h_%s_%s_vvv_%s"   , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_vvv");
  h_smzh  =     (TH1F*)file->Get(Form("h_%s_%s_smzh_%s"  , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_smzh");
  h_tbz   =     (TH1F*)file->Get(Form("h_%s_%s_tbz_%s"   , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_tbz");

  h_allmc =     (TH1F*)file->Get(Form("h_%s_%s_zjets_%s" , variable.c_str(), sample.c_str(), searchRegion.c_str() )) -> Clone("h_allmc");



  if( variable == "mll" ){
	if( dofsprediction && sample == "ll" && searchRegion == "met120" ){
	  h_allmc -> Scale( 4.0 / 5.3 );
	  h_zjets -> Scale( 4.0 / 5.3 );
	}
	if( dofsprediction && sample == "ll" && searchRegion == "2btag1_met120" ){
	  h_allmc -> Scale( 3.8 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)));
	  h_zjets -> Scale( 3.8 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)));
	  h_fsbg  -> Scale( 12.7 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "2btag2_met120" ){
	  h_allmc -> Scale( 0.9 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)));
	  h_zjets -> Scale( 0.9 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)));
	  h_fsbg  -> Scale( 1.2 / h_fsbg  -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)));
	  h_data -> Scale(0);
	}
	if( dofsprediction && sample == "ll" && searchRegion == "2btag3_met120" ){
	  h_allmc -> Scale( 0.9 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)));
	  h_zjets -> Scale( 0.9 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)));
	  h_fsbg  -> Scale( 44.2 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "2btag4_met120" ){
	  h_allmc -> Scale( 1.6 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)));
	  h_zjets -> Scale( 1.6 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)));
	  h_fsbg  -> Scale( 88.9 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)));
	}


	if( dofsprediction && sample == "ll" && searchRegion == "bveto1_met120" ){
	  h_allmc -> Scale( 34.8 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)));
	  h_zjets -> Scale( 34.8 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)));
	  h_fsbg  -> Scale( 12.2 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "bveto2_met120" ){
	  h_allmc -> Scale( 3.7 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)));
	  h_zjets -> Scale( 3.7 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)));
	  h_fsbg  -> Scale( 2.2 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "bveto3_met120" ){
	  h_allmc -> Scale( 4.1 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)));
	  h_zjets -> Scale( 4.1 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)));
	  h_fsbg  -> Scale( 6.2 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)));
	}
	if( dofsprediction && sample == "ll" && searchRegion == "bveto4_met120" ){
	  h_allmc -> Scale( 16.9 / h_allmc -> Integral(h_allmc->FindBin(81), h_allmc->FindBin(101)));
	  h_zjets -> Scale( 16.9 / h_zjets -> Integral(h_zjets->FindBin(81), h_zjets->FindBin(101)));
	  h_fsbg  -> Scale( 14.3 / h_fsbg -> Integral(h_fsbg ->FindBin(81), h_fsbg ->FindBin(101)));
	}
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

  vector <Double_t> yields;
  vector <string> samplename;

  if( dofsprediction && sample != "em" ){
  samplename.push_back("Z+Jets");
  samplename.push_back("WZ");
  samplename.push_back("ZZ");
  samplename.push_back("FS Bkg");
  samplename.push_back("Z+H");
  samplename.push_back("ttv");
  samplename.push_back("vvv");
  samplename.push_back("tbz");
  samplename.push_back("total bg");
  samplename.push_back("Data");
  samplename.push_back("ratio");
  }else{
  samplename.push_back("Z+Jets");
  samplename.push_back("WZ");
  samplename.push_back("ZZ");
  samplename.push_back("$t\\bar{t}$");
  samplename.push_back("Z+H");
  samplename.push_back("single top");
  samplename.push_back("WW");
  samplename.push_back("ttv");
  samplename.push_back("vvv");
  samplename.push_back("tbz");
  samplename.push_back("total bg");
  samplename.push_back("Data");
  samplename.push_back("ratio");
  }
  Double_t errors[samplename.size()];
  Int_t lowcut = 81;
  Int_t highcut = 101;

  Float_t zjetssys = 0.0;
  Float_t fsbkgsys = 0.0;
  Float_t mcbkgsys = 0.0;

  if( dofsprediction && sample != "em" ){
	yields.push_back(h_zjets -> IntegralAndError( h_data->FindBin(lowcut), h_data->FindBin(highcut), errors[0]));
	yields.push_back(h_wz    -> IntegralAndError( h_data->FindBin(lowcut), h_data->FindBin(highcut), errors[1]));
	yields.push_back(h_zz    -> IntegralAndError( h_data->FindBin(lowcut), h_data->FindBin(highcut), errors[2]));
	yields.push_back(h_fsbg  -> IntegralAndError( h_data->FindBin(lowcut), h_data->FindBin(highcut), errors[3]));
	yields.push_back(h_smzh  -> IntegralAndError( h_data->FindBin(lowcut), h_data->FindBin(highcut), errors[4]));
	yields.push_back(h_ttv   -> IntegralAndError( h_data->FindBin(lowcut), h_data->FindBin(highcut), errors[5]));
	yields.push_back(h_vvv   -> IntegralAndError( h_data->FindBin(lowcut), h_data->FindBin(highcut), errors[6]));
	yields.push_back(h_tbz   -> IntegralAndError( h_data->FindBin(lowcut), h_data->FindBin(highcut), errors[7]));
	yields.push_back(h_allmc -> IntegralAndError( h_data->FindBin(lowcut), h_data->FindBin(highcut), errors[8]));
	yields.push_back(h_data  -> IntegralAndError( h_data->FindBin(lowcut), h_data->FindBin(highcut), errors[9]));
	yields.push_back(yields.at(9)/yields.at(8));

	//calculate systematic uncertainties
	errors[0] = sqrt(pow(errors[0],2) + yields.at(0)*zjetssys );

	errors[3] = sqrt(pow(errors[3],2) + yields.at(3)*fsbkgsys );

	errors[1] = sqrt(pow(errors[1],2) + yields.at(1)*mcbkgsys );
	errors[2] = sqrt(pow(errors[2],2) + yields.at(2)*mcbkgsys );
	errors[4] = sqrt(pow(errors[4],2) + yields.at(4)*mcbkgsys );
	errors[5] = sqrt(pow(errors[5],2) + yields.at(5)*mcbkgsys );
	errors[6] = sqrt(pow(errors[6],2) + yields.at(6)*mcbkgsys );
	errors[7] = sqrt(pow(errors[7],2) + yields.at(7)*mcbkgsys );
	
	errors[8] = sqrt(pow(errors[8],2) 
					 + yields.at(0)*zjetssys 
					 + yields.at(3)*fsbkgsys
					 + yields.at(1)*mcbkgsys 
					 + yields.at(2)*mcbkgsys 
					 + yields.at(4)*mcbkgsys 
					 + yields.at(5)*mcbkgsys 
					 + yields.at(6)*mcbkgsys 
					 + yields.at(7)*mcbkgsys 
					 );
	
	errors[10] = err_mult( yields.at(9), yields.at(8), errors[9], errors[8], yields.at(9)/yields.at(8));

  }else{
	yields.push_back(h_zjets -> IntegralAndError( lowcut, highcut, errors[0]));
	yields.push_back(h_wz    -> IntegralAndError( lowcut, highcut, errors[1]));
	yields.push_back(h_zz    -> IntegralAndError( lowcut, highcut, errors[2]));
	yields.push_back(h_ttbar -> IntegralAndError( lowcut, highcut, errors[3]));
	yields.push_back(h_smzh  -> IntegralAndError( lowcut, highcut, errors[4]));
	yields.push_back(h_st    -> IntegralAndError( lowcut, highcut, errors[5]));
	yields.push_back(h_ww    -> IntegralAndError( lowcut, highcut, errors[6]));
	yields.push_back(h_ttv   -> IntegralAndError( lowcut, highcut, errors[7]));
	yields.push_back(h_vvv   -> IntegralAndError( lowcut, highcut, errors[8]));
	yields.push_back(h_tbz   -> IntegralAndError( lowcut, highcut, errors[9]));
	yields.push_back(h_allmc -> IntegralAndError( lowcut, highcut, errors[10]));
	yields.push_back(h_data  -> IntegralAndError( h_data->FindBin(81.0), h_data->FindBin(101.0), errors[11]));
	yields.push_back(yields.at(11)/yields.at(10));
  errors[12] = err_mult( yields.at(11), yields.at(10), errors[11], errors[10], yields.at(11)/yields.at(10));
  }
  
  cout<<"\\begin{table}[htb]"<<endl;
cout<<"\\begin{center}"<<endl;
cout<<"\\footnotesize"<<endl;
cout<<"\\begin{tabular}{l|c}"<<endl;
cout<<"\\hline"<<endl;
cout<<"\\hline"<<endl;

  cout<<"     & "<<"$81 < M_{\\ell\\ell} < 101 GeV$" << "\\\\"<<endl;
  cout<<"\\hline"<<endl;
  for( size_t i = 0; i < samplename.size()-1; i++ ){
	cout<<samplename.at(i)<<" & "<<Form(" %.1f $\\pm$ %.1f \\\\", yields.at(i), errors[i] )<<endl;
  if( dofsprediction && sample != "em" ){

	// if( i == 0) cout<<"\\hline"<<endl;
	if( i == 7) cout<<"\\hline"<<endl;
	if( i == 8) cout<<"\\hline"<<endl;
  }

  }
  cout<<"\\hline"<<endl;
  if( dofsprediction && sample != "em" ){
	cout<<samplename.at(10)<<" & "<<Form(" %.2f $\\pm$ %.2f \\\\", yields.at(10), errors[10] )<<endl;
  }else{
	cout<<samplename.at(12)<<" & "<<Form(" %.2f $\\pm$ %.2f \\\\", yields.at(12), errors[12] )<<endl;
  }

  cout<<"\\hline"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"\\end{tabular}"<<endl;
  cout<<"\\end{center}"<<endl;
  cout<<"\\end{table}"<<endl;

  return 0;

}
