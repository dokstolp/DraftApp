#define myEvent_cxx
#include "myEvent.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <bitset>
#include <string>
#include "TLorentzVector.h"
#include <climits>
#include <cstring>
#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"
using namespace std;

int main(int argc, const char* argv[]){
  double Pt =atof(argv[3]);
  double Met=atof(argv[4]);
  double JetPt=atof(argv[5]);
  double TrackPt=atof(argv[6]);
  float pvalue=atof(argv[7]);
  float minmet = atof(argv[8]);
  float dphi = atof(argv[9]);
  double  Mupt = atof(argv[10]);
  double  Elept = atof(argv[11]);
  int isMonteCarlo = atoi(argv[12]);
  const char* pileupfile = argv[13];
  int runner=atoi(argv[14]);
  myEvent t(argv[1],argv[2],runner);
  t.Loop(Pt,Met,JetPt,TrackPt,pvalue,minmet,dphi,Mupt,Elept,isMonteCarlo,pileupfile);
  return 0;
}


void myEvent::Loop(double Pt, double Met,double JetPt, double TrackPt, float pvalue,float minmet,float dphi,double Mupt,double Elept,int isMonteCarlo, const char* pileupfile){
  pt_cut   = Pt;
  met_cut  = Met;
  jet_ptcut = JetPt;
  track_ptcut = TrackPt;
  pvalue_cut =  pvalue;
  minmet_cut = minmet;
  dphi_cut  = dphi;
  mu_ptcut= Mupt;
  ele_ptcut =Elept;
  isMC = to_bool(isMonteCarlo);

  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntries();
  Long64_t nbytes = 0, nb = 0;
  int nTotal = nentries;
  int before = 0;
  cout<<"first"<<endl; 
  if(isMC){
	TFile *f2 = TFile::Open("/uscms_data/d3/bhawna/CMSSW_5_2_3_patch3/src/ADDmonophoton/Analyzer/test/Pfiso_MC_plots_pileup/pu_data_1948_bin60_25June.root");
	TH1F* dataPU = (TH1F*)f2->Get("true_pileup");
  	TString dir = "/uscms_data/d3/dokstolp/darkphoton/Analysis/CMSSW_5_3_22_patch1/src/forPileup/";
  	TFile *fmc = TFile::Open(dir+pileupfile);
  	TH1F* mcPU = (TH1F*)fmc->Get("h_pileup");
  	for(int i=0; i<60; i++){
	       MCpileup.push_back(mcPU->GetBinContent(i+1));
	       datapileup.push_back(dataPU->GetBinContent(i+1));
	} 
  	LumiReWeighting(MCpileup,datapileup);
  }
   
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
     
     bool scrapingdecision, vertexdecision, noncosmicdecision, trackisodecision, trackvetodecision, tightphotoniddecision, mediumphotoniddecision, kinphodecision; 
     
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
    

     int pho_index = -1, kinpho_index = -1;
     int foundVertex = 0;
     std::vector<int> jetveto;
     jetveto.clear();

     kinphodecision = PassingKinematics(kinpho_index);
     mediumphotoniddecision = MediumPhotonIdDecision(pho_index);
//     tightphotoniddecision = TightPhotonIdDecision(pho_index);
         
      
     if(pho_index>=0){
         vertexdecision        = VertexDecision(foundVertex);
         scrapingdecision      = Scraping_isScrapingEvent;
	 jetveto    = JetVetoDecision(pho_index);
     }
     zero = 0;
     vertex = 0;
     phokinematic = 0;
     phoidentification = 0;
     jetkinematic = 0;
     jetchf = 0;
     jetnch = 0;
     showershape = 0;
     double event_weight=1.0;
     if(isMC) event_weight = puweight(int(trueInteractions));
     
     zero+=event_weight;
     //if(nhardphotons > 1) cout<<"nhardphotons: "<<nhardphotons <<endl;
     //if(is_diphoton_event) cout<<"nhardphotons: "<<nhardphotons <<endl;

     //h_genphoton_pt->Fill(gen_photonpt[0],event_weight);
     //h_genphoton_eta->Fill(gen_photoneta[0],event_weight);
     //h_genphoton_phi->Fill(gen_photonphi[0],event_weight);
     if(vertexdecision){
	if(!scrapingdecision){
	   vertex+=event_weight;
	   if(kinphodecision != true) continue;
	   phokinematic+=event_weight;
	   if(mediumphotoniddecision!=true) continue;
	   phoidentification+=event_weight;
	   if(jetveto.size() == 0) continue;
	   if(pfJet_pt[jetveto[0]] < 140.0) continue;
	   jetkinematic+=event_weight;
	   if(pfjet_CHF[jetveto[0]]<0.2){
		   jetchf+=event_weight;
	   	   if(pfjet_NCH[jetveto[0]]<16){
			   jetnch+=event_weight;
			   if(MVACalc(pfjet_n60[jetveto[0]],pfjet_n90[jetveto[0]],pfjet_NConstituents[jetveto[0]],pfjet_NHF[jetveto[0]],pfjet_phoEFrac[jetveto[0]]) < 84) showershape+=event_weight;
		   }
	   }
	   //if(DeltaPhi(Photon_phi[pho_index],pfJet_phi[jetveto[0]])) deltaphi+=event_weight;
	   //if(TMath::Max((PFWorstiso_Charged03[pho_index]-rho*EAPFWorstElectroncharged(Photon_sc_eta[pho_index])),0.0)  >= 1.5) continue;
	   //if(jetveto.size() < 1) continue;
	   //if(pfjet_CHF[jetveto[0]]>=0.2) continue;
	   //if(pfjet_NCH[jetveto[0]]>=16) continue;
	   //if(ChiSquare(pfjet_CHF[jetveto[0]],pfjet_n60[jetveto[0]],pfjet_n90[jetveto[0]],pfjet_NCH[jetveto[0]],pfjet_NConstituents[jetveto[0]],pfjet_Ndaughters[jetveto[0]],pfjet_NHF[jetveto[0]],pfjet_phoEFrac[jetveto[0]],pfJet_pt[jetveto[0]]) > 53) continue;
	   //if(pfjet_n90[jetveto[0]]>=5) continue;
	   //if(pfjet_n60[jetveto[0]]>=3) continue;
	   //if(pfjet_Ndaughters[jetveto[0]]>=17) continue;
	   eve_weight = event_weight;
	   Pho_pt = Photon_pt[pho_index];
	   Pho_eta = Photon_eta[pho_index];
	   Met = PFMetPt[pho_index];
	   JetPho_DeltaPhi = DeltaPhi(Photon_phi[pho_index],pfJet_phi[jetveto[0]]);
	   JetPho_DeltaR = DeltaR(pfJet_eta[jetveto[0]],Photon_eta[pho_index],pfJet_phi[jetveto[0]],Photon_phi[pho_index]);
	   JetPho_pt = (Photon_pt[pho_index]/pfJet_pt[jetveto[0]]);
	   IsPhoton = isPho(pho_index);
	   Jet_Pt = pfJet_pt[jetveto[0]];
	   Jet_Eta = pfJet_eta[jetveto[0]];
	   Jet_CEF = pfjet_CEF[jetveto[0]];
	   Jet_NEF = pfjet_NEF[jetveto[0]];
	   Jet_CHF = pfjet_CHF[jetveto[0]];
	   Jet_NHF = pfjet_NHF[jetveto[0]];
	   Jet_NCH = pfjet_NCH[jetveto[0]];
	   Jet_NConst = pfjet_NConstituents[jetveto[0]];
	   Jet_Ndau = pfjet_Ndaughters[jetveto[0]];
	   Jet_n60 = pfjet_n60[jetveto[0]];
	   Jet_n90 = pfjet_n90[jetveto[0]];
	   Jet_PEF = pfjet_phoEFrac[jetveto[0]];
	   nJet = jetveto.size();
	   nInteractions = int(trueInteractions);
	   Jet_trackIso = JetTrackIso(jetveto[0]);
	   //cout<<"Photon PT "<<Photon_pt[pho_index]<<endl;
	   if(isMC){   
		   DarkPho_eta = gen_gravitoneta;
		   DarkPho_pt = gen_gravitonpt;
		   GenPhoton_pt = gen_hardphotonpt[0];
		   GenPhoton_eta = gen_hardphotoneta[0];
	   }
	   Jet_mva      = MVACalc(pfjet_n60[jetveto[0]],pfjet_n90[jetveto[0]],pfjet_NConstituents[jetveto[0]],pfjet_NHF[jetveto[0]],pfjet_phoEFrac[jetveto[0]]);
	   Jet_Chi2 = ChiSquare(pfjet_CHF[jetveto[0]],pfjet_n60[jetveto[0]],pfjet_n90[jetveto[0]],pfjet_NCH[jetveto[0]],pfjet_NConstituents[jetveto[0]],pfjet_Ndaughters[jetveto[0]],pfjet_NHF[jetveto[0]],pfjet_phoEFrac[jetveto[0]],pfJet_pt[jetveto[0]]);
	   //if(nhardphotons >=2) cout<<"diPhoton"<<endl;
	   tree->Fill();
        }
     }
  }
}

void myEvent::BookHistos(const char* file2){
   Float_t PtBins[7]={145., 160., 190., 250., 400., 700.0,1000.0};
   Float_t MetBins[8]={130., 150., 170., 190., 250., 400., 700.0,1000.0};
   fileName = new TFile(file2, "RECREATE");
   fileName->cd();  
   tree = new TTree("ADD","ADD");
   tree->Branch("zero",&zero,"zero/D");
   tree->Branch("vertex",&vertex,"vertex/D");
   tree->Branch("phokinematic",&phokinematic,"phokinematic/D");
   tree->Branch("phoidentification",&phoidentification,"phoidentification/D");
   tree->Branch("jetkinematic",&jetkinematic,"jetkinematic/D");
   tree->Branch("jetchf",&jetchf,"jetchf/D");
   tree->Branch("jetnch",&jetnch,"jetnch/D");
   tree->Branch("showershape",&showershape,"showershape/D");
   tree->Branch("eve_weight",&eve_weight,"eve_weight/D");
   tree->Branch("Pho_pt",&Pho_pt,"Pho_pt/D");
   tree->Branch("Pho_eta",&Pho_eta,"Pho_eta/D");
   tree->Branch("IsPhoton",&IsPhoton,"IsPhoton/B");
   tree->Branch("Met",&Met,"Met/D");
   tree->Branch("JetPho_DeltaPhi",&JetPho_DeltaPhi,"JetPho_DeltaPhi/D");
   tree->Branch("JetPho_DeltaR",&JetPho_DeltaR,"JetPho_DetlaR/D");
   tree->Branch("JetPho_pt",&JetPho_pt,"JetPho_pt/D");
   tree->Branch("nJet",&nJet,"nJet/I");
   tree->Branch("nInteractions",&nInteractions,"nInteractions/I");
   tree->Branch("Jet_trackIso",&Jet_trackIso,"Jet_trackIso/D");
   tree->Branch("Jet_Pt",&Jet_Pt,"Jet_Pt/D");
   tree->Branch("Jet_Eta",&Jet_Eta,"Jet_Eta/D");
   tree->Branch("Jet_CEF",&Jet_CEF,"Jet_CEF/D");
   tree->Branch("Jet_NEF",&Jet_NEF,"Jet_NEF/D");
   tree->Branch("Jet_CHF",&Jet_CHF,"Jet_CHF/D");
   tree->Branch("Jet_NHF",&Jet_NHF,"Jet_NHF/D");
   tree->Branch("Jet_NCH",&Jet_NCH,"Jet_NCH/D");
   tree->Branch("Jet_NConst",&Jet_NConst,"Jet_NConst/I");
   tree->Branch("Jet_Ndau",&Jet_Ndau,"Jet_Ndau/I");
   tree->Branch("Jet_n60",&Jet_n60,"Jet_n60/I");
   tree->Branch("Jet_n90",&Jet_n90,"Jet_n90/I");
   tree->Branch("Jet_PEF",&Jet_PEF,"Jet_PEF/D");
   tree->Branch("DarkPho_pt",&DarkPho_pt,"DarkPho_pt/D");
   tree->Branch("DarkPho_eta",&DarkPho_eta,"DarkPho_eta/D");
   tree->Branch("GenPhoton_pt",&GenPhoton_pt,"GenPhoton_pt/D");
   tree->Branch("GenPhoton_eta",&GenPhoton_eta,"GenPhoton_eta/D");
   tree->Branch("Jet_Chi2",&Jet_Chi2,"Jet_Chi2/D");
   tree->Branch("Jet_mva",&Jet_mva,"Jet_mva/D");
 }

//*********Dark Photon Functions*************************
bool myEvent::to_bool(int s){
	bool rets = (s == 1);
	return rets;
}

double myEvent::JetShowerPhi(int jet, double size){
   double ratio;
   for(int t;t<Track_n;t++){
       Float_t dR = DeltaR(pfJet_eta[jet],Track_eta[t], pfJet_phi[jet],Track_phi[t]);
       if(dR<size){
	       ratio += Track_pt[t];
       }
       ratio = ratio/pfJet_pt[jet];
   }
   return ratio;
}

double myEvent::ChiSquare(double CHF,int n60,int n90,int NCH,int nconst,int ndau, double NHF, double eFrac, double jpt){
	double apps[8];
	double chis;
	apps[0] = (CHF/0.01)*(CHF/0.01);
	apps[1] = (n60/1)*(n60/1);
	apps[2] = (n90/1)*(n90/1);
	apps[3] = (NCH/8)*(NCH/8);
	apps[4] = (nconst/12)*(nconst/12);
	apps[5] = (ndau/10)*(ndau/10);
	apps[6] = ((1-NHF)/0.05)*((1-NHF)/0.05);
	apps[7] = ((1-eFrac)/0.05)*((1-eFrac)/0.05);
	for(int i=0;i<8;i++){
		chis+=apps[i];
	}
	return chis/8;
}

double myEvent::MVACalc(int n60,int n90,int nconst, double NHF, double eFrac){
	double apps[5];
	double chis;
	apps[0] = (n60/1)*(n60/1);
	apps[1] = (n90/1)*(n90/1);
	apps[2] = (nconst/12)*(nconst/12);
	apps[3] = ((1-NHF)/0.05)*((1-NHF)/0.05);
	apps[4] = ((1-eFrac)/0.05)*((1-eFrac)/0.05);
	for(int i=0;i<5;i++){
		chis+=apps[i];
	}
	return chis/5;
}


bool myEvent::isPho(int jet){
	double mdR = 9999;
	for(int p=0;p<Photon_n;p++){
		if(DeltaR(Photon_eta[p],pfJet_eta[jet],Photon_phi[p],pfJet_phi[jet])<mdR){
			mdR = DeltaR(Photon_eta[p],pfJet_eta[jet],Photon_phi[p],pfJet_phi[jet]);
		}
	}
	if(mdR<0.5) return true;
	return false;
}

bool myEvent::IsPhoPho(int &phopho){
	double phoeta = gen_hardphotoneta[0];
	double phophi = gen_hardphotonphi[0];
	double mdR = 999;
	for(int p=0;p<Photon_n;p++){
		if(DeltaR(phoeta,Photon_eta[p],phophi,Photon_phi[p])<mdR){
			mdR=DeltaR(phoeta,Photon_eta[p],phophi,Photon_phi[p]);
			phopho = p;
		}
	}
	if(mdR<0.5) return true;
	return false;
}

bool myEvent::IsPhoJet(int &jetpho){
	double jeteta = gen_hardphotoneta[0];
	double jetphi = gen_hardphotonphi[0];
	double mdR = 999;
	for(int p=0;p<Photon_n;p++){
		if(DeltaR(jeteta,Photon_eta[p],jetphi,Photon_phi[p])<mdR){
			mdR=DeltaR(jeteta,Photon_eta[p],jetphi,Photon_phi[p]);
			jetpho = p;
		}
	}
	if(mdR<0.5) return true;
	return false;
}

bool myEvent::IsDarkPho(int &phodark){
   double darketa = gen_gravitoneta;
   double darkphi = gen_gravitonphi;
   double mdR = 999;
   for(int p=0;p<Photon_n;p++){
//	   if(DeltaR(darketa,Photon_eta[p],darkphi,Photon_phi[p]) < 0.5){
//		   phodark = p;
//		   return true;
//	   }
           if(DeltaR(darketa,Photon_eta[p],darkphi,Photon_phi[p])<mdR){
	       mdR=DeltaR(darketa,Photon_eta[p],darkphi,Photon_phi[p]);
	       phodark = p;
           }
   }
   if(mdR<0.5) return true;
   return false;
}

bool myEvent::IsDarkJet(int &jetdark){
   double darketa = gen_gravitoneta;
   double darkphi = gen_gravitonphi;
   double mdRj = 999;
   for(int j=0;j<pfJet_n;j++){
       if(DeltaR(darketa,pfJet_eta[j],darkphi,pfJet_phi[j])<mdRj){
	       mdRj=DeltaR(darketa,pfJet_eta[j],darkphi,pfJet_phi[j]);
	       jetdark = j;
       }
   }
   if(mdRj<0.5) return true;
   return false;
}

//**********************End Dark Photon Functions***************************
double myEvent::JetTrackIso(int jet){
   double tempSSPT = 0;
   for (int iiii=0;iiii<Track_n;++iiii){
       Float_t dz = fabs(Track_vz[iiii] - pfJet_vz[jet]);
       Float_t dR = DeltaR(pfJet_eta[jet],Track_eta[iiii], 
			   pfJet_phi[jet],
			   Track_phi[iiii]);
       if (dz<0.1 && dR < 0.3 && dR > 0.04){
	 tempSSPT+=Track_pt[iiii];
       }
   }
   return tempSSPT;
}

bool myEvent::VertexDecision(int &foundVertex){
   bool vtxAccepted=false;
   for(int i=0;i<Vertex_n;i++){
       if((fabs(Vertex_z[i]) <= 24.0) && (Vertex_ndof[i] >= 4)  && (!Vertex_isFake[i]) && (fabs(Vertex_d0[i])<= 2.0))
	 foundVertex++;
     }
   if(foundVertex>0)vtxAccepted=true;
   return vtxAccepted;
 }

  
//*********************BEGIN IDs***********************
//#####################PHOTON###################
//medium
bool  myEvent::MediumPhotonIdDecision(int &pho_index) {
   bool tightPhotonID=false;
   for(int i=0; i< Photon_n  ;i++) {
       bool ResSpikeCut     = Seed_LICTD_Decision(i) < 5.  && Photon_timing_xtal[i][0] <3. &&  (Photon_SigmaIetaIeta[i]>0.001) && (Photon_SigmaIphiIphi[i]>0.001) && (Photon_mipTotEnergy[i]<6.3);
       bool KinematicCutEta    = fabs(Photon_sc_eta[i])<1.4442;
       bool KinematicCutPt    = Photon_pt[i]> pt_cut;
       bool ID =(TMath::Max(((PFiso_Charged03[i])-rho*EAElectroncharged(Photon_sc_eta[i])),0.0)  < 1.5 )&&
	 (Photon_HoEnew[i]  < 0.05)                                          &&
	 (TMath::Max(((PFiso_Photon03[i]) - rho*EAElectronphoton(Photon_sc_eta[i])) ,0.0) < 0.7+0.005*Photon_pt[i] )&&
	 (TMath::Max(((PFiso_Neutral03[i])- rho*EAElectronneutral(Photon_sc_eta[i])) ,0.0) < 1.0+0.04*Photon_pt[i] )&&
	 (Photon_SigmaIetaIeta[i]  < 0.011)                                 &&
	 //(Photon_Electronveto[i]  == 1)   &&
	 (TMath::Max((PFWorstiso_Charged03[i]-rho*EAPFWorstElectroncharged(Photon_sc_eta[i])),0.0) < 1.5) &&
	 (Photon_hasPixelSeed[i]  == 0)   &&
	 (Photonr9[i]<1.0);
       if(KinematicCutPt && KinematicCutEta && ResSpikeCut && ID){ 
	       tightPhotonID = true;
	       pho_index = i;
	       break;
       }
     }
     return tightPhotonID;
 }

//tight
bool myEvent::TightPhotonIdDecision(int &pho_index) {
   bool tightPhotonID=false;


   for(int i=0; i< Photon_n  ;i++) {
     bool ResSpikeCut     = Seed_LICTD_Decision(i) < 5.  && Photon_timing_xtal[i][0] <3. &&  (Photon_SigmaIetaIeta[i]>0.001) && (Photon_SigmaIphiIphi[i]>0.001);
     bool KinematicCut    = Photon_pt[i]> 165.   &&    fabs(Photon_sc_eta[i])<1.4442 ;
     bool ID =((PFiso_Charged03[i]* Photon_pt[i])  < 0.7 )&&
	(Photon_HoEnew[i]  < 0.05)                                          &&
       (TMath::Max(((PFiso_Photon03[i]*Photon_pt[i]) - rho*EAElectronphoton(Photon_sc_eta[i])) ,0.0) < 0.5+0.005*Photon_pt[i] )&&
       (TMath::Max(((PFiso_Neutral03[i]*Photon_pt[i])- rho*EAElectronneutral(Photon_sc_eta[i])) ,0.0) < 0.4+0.04*Photon_pt[i] )&&
       (Photon_SigmaIetaIeta[i]  < 0.011)                                 &&
       (Photon_Electronveto[i]  == 1)   &&
       (Photonr9[i]<1.0);


     if(ResSpikeCut && KinematicCut && ID)
       {
	 tightPhotonID = true;
	 pho_index = i;
       }
   }

   return tightPhotonID;
}

bool myEvent::PassingKinematics(int &passPho){
   bool willpass = false;
   bool KinematicCut = false;
   for(int i=0;i<Photon_n;i++){
       KinematicCut    = (Photon_pt[i]> pt_cut   &&    fabs(Photon_sc_eta[i])<1.4442);
       if(KinematicCut == true){ 
	       willpass = KinematicCut;
	       passPho = i;
       }
   }
   return willpass;
}

//####################JET#################
std::vector<int> myEvent::JetVetoDecision(int pho_index) {
  bool jetVeto=true;
  std::vector<int> jetindex;
  for(int i = 0; i < pfJet_n; i++)
    {
      //std::cout<<"Jet size: "<<pfJet_n<<std::endl;
      double dR = 0.0 ;
      double dRsub= 3.0;
      //std::cout<<"Jet no:"<<i<<"coming here pujetid: "<<pfJet_pt[i]<<std::endl;
      if(OverlapWithMuon(pfJet_eta[i],pfJet_phi[i]))     continue;
      //std::cout<<"Jet no:"<<i<<"coming here OverlapWithMuon: "<<pfJet_pt[i]<<std::endl;
      if(OverlapWithElectron(pfJet_eta[i],pfJet_phi[i]))   continue;
      if(pho_index>=0){
        dR= DeltaR(pfJet_eta[i],Photon_eta[pho_index],pfJet_phi[i],Photon_phi[pho_index]);
      }
      //if(dR >0.5 && pfJet_pt[i] >140.0 && pujetIdCutBased_loose[i]==1 && TMath::Abs(pfJet_eta[i])<2.4)
      if(dR >0.5 && pfJet_pt[i] >30.0 && pujetIdCutBased_loose[i]==1 && TMath::Abs(pfJet_eta[i])<2.4){
          jetindex.push_back(i);
      }
    }

  //std::cout<<"Jet size: "<< jetindex.size()<<std::endl;
  return jetindex;
}
//*************END IDs*********************************

double myEvent::Seed_LICTD_Decision(int pho_index) {
   bool LICTD_Decision=false;
   Float_t SeedTime = -999;
   Float_t SeedE    = -999;

   Int_t crysIdx = -1;

   for (int k=0;k<Photon_ncrys[pho_index]&&k<100;++k)
	{
	   Float_t crysE = Photon_energy_xtal[pho_index][k];
	   if (crysE > SeedE){
	     SeedE = crysE;
	     SeedTime = Photon_timing_xtal[pho_index][k];
	     crysIdx = k;
	   }
	 }


   Float_t LICTD   = 99.;

   if (fabs(SeedTime)< 3.)
     {
       LICTD   = 0;
       Int_t crysCrys  =-1;
       Int_t crysThresh= 0;

       for (int k=0;k<Photon_ncrys[pho_index]&&k<100;++k)
	 {
	   if (crysIdx==k) continue;
	   Float_t crysE = Photon_energy_xtal[pho_index][k];

	   if (crysE > 1.)
	   {
	     crysThresh++;
	     Float_t tdiff = Photon_timing_xtal[pho_index][crysIdx] -
			     Photon_timing_xtal[pho_index][k];
	     if (fabs(tdiff) > fabs(LICTD))
	       {
		 LICTD = tdiff;
		 crysCrys=k;
	       }
	   }
	 }
     }


   if(fabs(LICTD)<5)
     LICTD_Decision = true;
   //return LICTD_Decision;
   return fabs(LICTD);
}

bool myEvent::OverlapWithMuon(double eta, double phi){
  bool overlap = false;
  for(int k=0;k<Muon_n;++k){
    if((Muon_trackIso[k]/Muon_pt[k])<0.10 && (Muon_isGlobalMuon[k]==1 || Muon_isTrackerMuon[k]==1) && Muon_normChi2[k] < 10. && Muon_validHits[k] > 0 && Muon_pixHits[k] > 0){
      float dRJetMu = DeltaR(Muon_eta[k],eta,Muon_phi[k],phi);
      if(dRJetMu<0.5 && Muon_pt[k]>mu_ptcut) {
         overlap = true;
        break;
      }

    }
  }
  return overlap;
}

bool myEvent::OverlapWithElectron(double eta, double phi){
  bool overlap = false;
  // std::cout<<"No of electrons:"<<Electron_n<<std::endl;
  for(int i=0;i<Electron_n;++i){
    bool ElectronIdPasses = false;
    bool ElectronIsoPasses = false;
    if(fabs(Electron_sc_eta[i]) < 1.442){
      if(Electron_SigmaIetaIeta[i] < 0.01  && fabs(Electron_dEtaIn[i]) <  0.007   && fabs(Electron_dPhiIn[i]) <  0.15 && Electron_HoE[i] <  0.12 ) ElectronIdPasses = true;
    }
    if(fabs(Electron_sc_eta[i]) > 1.566 && fabs(Electron_sc_eta[i]) < 2.5 ){
      if(Electron_SigmaIetaIeta[i] < 0.03 && fabs(Electron_dEtaIn[i]) < 0.009  && fabs(Electron_dPhiIn[i]) <  0.10  && Electron_HoE[i] < 0.10 ) ElectronIdPasses = true;
    }


    if(Electron_trkIso[i]/Electron_pt[i] < 0.2 && Electron_ecalIso[i]/Electron_pt[i] < 0.2 && Electron_hcalIso[i]/Electron_pt[i] < 0.2) ElectronIsoPasses = true;

    if(ElectronIdPasses && ElectronIsoPasses && Electron_pt[i]>ele_ptcut){
      float dRJetEle = DeltaR( Electron_eta[i],eta,Electron_phi[i],phi);
      if(dRJetEle<0.5){
        overlap = true;
	//std::cout<<" index of ele :"<<i<<std::endl;
        break;
      }
    }
  }
  return overlap;
}

double myEvent::DeltaR(double eta1, double eta2, double phi1,double phi2){
   double dPhi = fabs(phi1-phi2);
   Double_t pi =3.141592654;
   Double_t twopi =2.0*pi;

   if(dPhi<0) dPhi=-dPhi;
   if(dPhi>=(2*pi-dPhi))dPhi= 2.0*pi-dPhi;

   double dEta = fabs(eta1-eta2);

   double DR =1.0; 
   DR= pow((dPhi*dPhi + dEta*dEta),0.5);
   return DR;
}

double myEvent::DeltaPhi(double phi1,double phi2)
{
  double result = -999.;
  result=(phi1-phi2);
  if(result > M_PI) result -= 2*M_PI;
  if(result <= -M_PI) result += 2*M_PI;
  return result;

}

double myEvent::EAElectroncharged(double eta){
   float EffectiveArea=0.;
   if (fabs(eta) < 1.0 )   EffectiveArea = 0.012;
   if (fabs(eta) >= 1.0   && fabs(eta) < 1.4442 ) EffectiveArea = 0.010;

   return EffectiveArea;
}

double myEvent::EAPFWorstElectroncharged(double eta){
  float EffectiveArea=0.;
  if (fabs(eta) < 1.0 )   EffectiveArea = 0.075;
  if (fabs(eta) >= 1.0   && fabs(eta) < 1.4442 ) EffectiveArea = 0.062;

  return EffectiveArea;
}

double myEvent::EAElectronneutral(double eta){
   float EffectiveArea=0.;
   if (fabs(eta) < 1.0 )   EffectiveArea = 0.030;
   if (fabs(eta) >= 1.0   && fabs(eta) < 1.479 ) EffectiveArea = 0.057;

   return EffectiveArea;
}

double myEvent::EAElectronphoton(double eta){
   float EffectiveArea=0.;
   if (fabs(eta) < 1.0 )   EffectiveArea = 0.148;
   if (fabs(eta) >= 1.0   && fabs(eta) < 1.479 ) EffectiveArea = 0.130;

   return EffectiveArea;
}

//------------------------ PU Weight Computation ------------------//
void myEvent::LumiReWeighting( std::vector< float > MC_distr, std::vector< float > Lumi_distr)
 {
   // no histograms for input: use vectors
   // now, make histograms out of them:

   // first, check they are the same size...

   if( MC_distr.size() != Lumi_distr.size() ){

     std::cerr <<"ERROR: LumiReWeighting: input vectors have different sizes. Quitting... \n";
     return;

   }
   
   Int_t NBins = MC_distr.size();
   
     MC_distr_ = new TH1F("MC_distr","MC dist",NBins,0.0, 60.0);
     Data_distr_ = new TH1F("Data_distr","Data dist",NBins,0.0, 60.0);
     
     weights_ = new TH1F("luminumer","luminumer",NBins,0.0,60.0);
     den = new TH1F("lumidenom","lumidenom",NBins,0.0,60.0);

     for(int ibin = 1; ibin<NBins+1; ++ibin ) {
       weights_->SetBinContent(ibin, Lumi_distr[ibin-1]);
       Data_distr_->SetBinContent(ibin, Lumi_distr[ibin-1]);
       den->SetBinContent(ibin,MC_distr[ibin-1]);
       MC_distr_->SetBinContent(ibin,MC_distr[ibin-1]);
     }

     // check integrals, make sure things are normalized
     float deltaH = weights_->Integral();
     if(fabs(1.0 - deltaH) > 0.02 ) { //*OOPS*...
       weights_->Scale( 1.0/ deltaH );
       Data_distr_->Scale( 1.0/ deltaH );
     }
     float deltaMC = den->Integral();
     if(fabs(1.0 - deltaMC) > 0.02 ) {
       den->Scale(1.0/ deltaMC );
       MC_distr_->Scale(1.0/ deltaMC );
     }
     weights_->Divide( den );  // so now the average weight should be 1.0
     //std::cout << " Lumi/Pileup Reweighting: Computed Weights per In-Time Nint " << std::endl;

     //for(int ibin = 1; ibin<NBins+1; ++ibin){
     //  std::cout << "   " << ibin-1 << " " << weights_->GetBinContent(ibin) << std::endl;
     //}
}

 double myEvent::puweight(float npv)
{
  int bin = weights_->GetXaxis()->FindBin( npv );
  return weights_->GetBinContent( bin );
}
//------------------------ PU Weight Computation ------------------//



