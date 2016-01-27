/////////////////////////////////////////////////////////
// T_his class has been automatically generated on
// Tue Jun 21 01:49:06 2011 by ROOT version 5.26/00e
// from TTree myEvent/a tree with histograms
// found on file: Histo_Wmunu_240_1_GIb.root
//////////////////////////////////////////////////////////

#ifndef myEvent_h
#define myEvent_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <TCanvas.h>
#include <TSystem.h>
#include <TPostScript.h>
#include <TH2.h>
#include <TH1.h>
#include <TF1.h>
#include <TMath.h>
#include <TLegend.h>
#include <TProfile.h>
#include <TGraph.h>
#include <TRef.h>
#include <TList.h>
#include <TSystemFile.h>
#include <TSystemDirectory.h>
#include <TDCacheFile.h>
#include <TLorentzVector.h>
using namespace std;
#ifdef __MAKECINT__
#pragma link C++ class vector<std::bool>;
#pragma link C++ class vector<std::string>+;
#pragma link C++ class vector<UInt_t>+;
#pragma link C++ class vector<int>+;
#pragma link C++ class vector<TLorentzVector>+;                                                                                                                                    
#pragma extra_include "vector";
#endif
 


class myEvent {
public :
  //TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   TChain          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   double pt_cut,  met_cut , jet_ptcut, track_ptcut,pvalue_cut,minmet_cut,dphi_cut,mu_ptcut,ele_ptcut;
   bool isSignal;
   bool isMC;
   std::vector<unsigned int> event_;
   std::vector<double> event_info;
   std::vector<float> MCpileup;
   std::vector<float> datapileup;

   double eve_weight;
   double Pho_pt;
   double Pho_eta;
   double Met;
   double JetPho_DeltaPhi;
   double JetPho_DeltaR;
   double JetPho_pt;
   double Jet_Pt;
   double Jet_Eta;
   double Jet_NCH;
   double Jet_CEF;
   double Jet_NEF;
   double Jet_NHF;
   double Jet_CHF;
   double Jet_trackIso;
   int Jet_NConst;
   int Jet_Ndau;
   int Jet_n60;
   int Jet_n90;
   int nJet;
   int nInteractions;
   double Jet_PEF;
   double DarkPho_pt;
   double DarkPho_eta;
   double GenPhoton_pt;
   double GenPhoton_eta;
   double Jet_mva; 
   double Jet_Chi2; 
   bool IsPhoton;
   double zeroPt;
   double vertexPt;
   double phokinematicPt;
   double phoidentificationPt;
   double jetkinematicPt;
   double jetchfPt;
   double jetnchPt;
   double showershapePt;

   double zero, vertex, phokinematic, phoidentification, jetkinematic, jetchf, jetnch, showershape;


   TFile *fileName ;
   TTree *tree;
   TH1F *weights_, *MC_distr_, *Data_distr_, *den; 
   
  // Declaration of leaf types
   Int_t           nevents;
   UInt_t          run;
   UInt_t          event;
   UInt_t          luminosityBlock;
   UInt_t          beamCrossing;
   UInt_t          totalIntensityBeam1;
   UInt_t          totalIntensityBeam2;
   Float_t         avgInsDelLumi;
   Float_t         avgInsDelLumiErr;
   Float_t         avgInsRecLumi;
   Float_t         avgInsRecLumiErr;
   Int_t           ntriggers;
   vector<string>  *triggernames;

   vector<int>     *triggerprescales;
   vector<bool>    *ifTriggerpassed;
   Float_t         trobjpt[100][100][10];   //[ntriggers]
   Float_t         trobjeta[100][100][10];   //[ntriggers]
   Float_t         trobjphi[100][100][10];   //[ntriggers]
   Int_t           Vertex_n;
   Float_t         Vertex_x[200];   //[Vertex_n]
   Float_t         Vertex_y[200];   //[Vertex_n]
   Float_t         Vertex_z[200];   //[Vertex_n]
   Int_t           Vertex_tracksize[200];   //[Vertex_n]
   Int_t           Vertex_ndof[200];   //[Vertex_n]
   Float_t         Vertex_chi2[200];   //[Vertex_n]
   Float_t         Vertex_d0[200];   //[Vertex_n]
   Bool_t          Vertex_isFake[200];   //[Vertex_n]
   Int_t           npuVertices;
   Int_t           ootnpuVertices;
   Int_t           Scraping_numOfTracks;
   Float_t         Scraping_fractionOfGoodTracks;
   Int_t           npuVerticesp1;
   Int_t           npuVerticesm1;
   Float_t         trueInteractions;
   Int_t           Track_n;
   Float_t         Track_px[1000];   //[Track_n]
   Float_t         Track_py[1000];   //[Track_n]
   Float_t         Track_pz[1000];   //[Track_n]
   Float_t         Track_vx[1000];   //[Track_n]
   Float_t         Track_vy[1000];   //[Track_n]
   Float_t         Track_vz[1000];   //[Track_n]
   Float_t         Track_pt[1000];   //[Track_n]
   Float_t         Track_eta[1000];   //[Track_n]
   Float_t         Track_phi[1000];   //[Track_n]
   Int_t           Jet_n;
   Float_t         Jet_px[200];   //[Jet_n]
   Float_t         Jet_py[200];   //[Jet_n]
   Float_t         Jet_E[200];   //[Jet_n]
   Float_t         Jet_pz[200];   //[Jet_n]
   Float_t         Jet_vx[200];   //[Jet_n]
   Float_t         Jet_vy[200];   //[Jet_n]
   Float_t         Jet_vz[200];   //[Jet_n]
   Float_t         Jet_pt[200];   //[Jet_n]
   Float_t         Jet_eta[200];   //[Jet_n]
   Float_t         Jet_phi[200];   //[Jet_n]
   Float_t         Jet_emEnergyFraction[200];   //[Jet_n]
   Float_t         Jet_energyFractionHadronic[200];   //[Jet_n]
   Int_t           Jet_hitsInN90[200];   //[Jet_n]
   Int_t           Jet_n90Hits[200];   //[Jet_n]
   Int_t           Jet_nTowers[200];   //[Jet_n]
   Float_t         Jet_fHPD[200];   //[Jet_n]
   Float_t         Jet_fRBX[200];   //[Jet_n]
   Float_t         Jet_RHF[200];   //[Jet_n]
   Float_t         Jet_jecCorr[200];   //[Jet_n]
   Float_t         ucJet_px[200];   //[Jet_n]
   Float_t         ucJet_py[200];   //[Jet_n]
   Float_t         ucJet_E[200];   //[Jet_n]
   Float_t         ucJet_pz[200];   //[Jet_n]
   Float_t         ucJet_pt[200];   //[Jet_n]
   Float_t         ucJet_eta[200];   //[Jet_n]
   Float_t         ucJet_phi[200];   //[Jet_n]
   Int_t           pfJet_n;
   Float_t         pfJet_px[200];   //[pfJet_n]
   Float_t         pfJet_py[200];   //[pfJet_n]
   Float_t         pfJet_E[200];   //[pfJet_n]
   Float_t         pfJet_pz[200];   //[pfJet_n]
   Float_t         pfJet_vx[200];   //[pfJet_n]
   Float_t         pfJet_vy[200];   //[pfJet_n]
   Float_t         pfJet_vz[200];   //[pfJet_n]
   Float_t         pfJet_pt[200];   //[pfJet_n]
   Float_t         pfJet_eta[200];   //[pfJet_n]
   Float_t         pfJet_phi[200];   //[pfJet_n]
   Float_t         pfjet_CEF[200];   //[pfJet_n]
   Float_t         pfjet_CHF[200];   //[pfJet_n]
   Float_t         pfjet_NEF[200];   //[pfJet_n]
   Float_t         pfjet_NHF[200];   //[pfJet_n]
   Int_t           pfjet_NCH[200];   //[pfJet_n]
   Float_t         pfjet_HFHAE[200];   //[pfJet_n]
   Float_t         pfjet_HFEME[200];   //[pfJet_n]
   Int_t           pfjet_NConstituents[200];   //[pfJet_n]
   Int_t           pfjet_Ndaughters[200];
   Int_t	   pfjet_towersArea[200];
   Char_t	   pfjet_isBasicJet[200];
   Int_t	   pfjet_n60[200];
   Int_t	   pfjet_n90[200];
   Float_t	   pfjet_phoEFrac[200];
   Int_t	   pfjet_partonFlav[200];
   Float_t         pujetIdFull_mva[200];   //[pfJet_n]                                                                                                                
   Float_t         pujetIdSimple_mva[200];   //[pfJet_n] 
   Float_t         pujetIdCutBased_mva[200];   //[pfJet_n]                                                                                                            
   Int_t           pujetIdFull_loose[200];   //[pfJet_n]     
   Int_t           pujetIdFull_medium[200];   //[pfJet_n]
   Int_t           pujetIdFull_tight[200];   //[pfJet_n]   
   Int_t           pujetIdSimple_loose[200];   //[pfJet_n] 
   Int_t           pujetIdSimple_medium[200];   //[pfJet_n] 
   Int_t           pujetIdSimple_tight[200];   //[pfJet_n] 
   Int_t           pujetIdCutBased_loose[200];   //[pfJet_n]  
   Int_t           pujetIdCutBased_medium[200];   //[pfJet_n] 
   Int_t           pujetIdCutBased_tight[200];   //[pfJet_n] 
   Float_t         pfjet_TrackCountHiEffBJetTags[200];   //[pfJet_n]
   Float_t         pfjet_TrackCountHiPurBJetTags[200];   //[pfJet_n]
   Float_t         pfjet_SimpleSVHiEffBJetTags[200];   //[pfJet_n]
   Float_t         pfjet_SimpleSVHiPurBJetTags[200];   //[pfJet_n]
   Float_t         pfJet_jecUncer[200];   //[pfJet_n]
   Float_t         pfJet_jecCorr[200];   //[pfJet_n]
   Float_t         ucpfJet_px[200];   //[pfJet_n]
   Float_t         ucpfJet_py[200];   //[pfJet_n]
   Float_t         ucpfJet_E[200];   //[pfJet_n]
   Float_t         ucpfJet_pz[200];   //[pfJet_n]
   Float_t         ucpfJet_pt[200];   //[pfJet_n]
   Float_t         ucpfJet_eta[200];   //[pfJet_n]
   Float_t         ucpfJet_phi[200];   //[pfJet_n]
   /*Int_t           genJet_n;
   Float_t         genJet_px[200];   //[genJet_n]
   Float_t         genJet_py[200];   //[genJet_n]
   Float_t         genJet_E[200];   //[genJet_n]
   Float_t         genJet_pz[200];   //[genJet_n]
   Float_t         genJet_pt[200];   //[genJet_n]
   Float_t         genJet_eta[200];   //[genJet_n]
   Float_t         genJet_phi[200];  */  //[genJet_n]
   Int_t           Electron_n;
   Float_t         Electron_px[200];   //[Electron_n]
   Float_t         Electron_py[200];   //[Electron_n]
   Float_t         Electron_pz[200];   //[Electron_n]
   Float_t         Electron_vx[200];   //[Electron_n]
   Float_t         Electron_vy[200];   //[Electron_n]
   Float_t         Electron_vz[200];   //[Electron_n]
   Float_t         Electron_pt[200];   //[Electron_n]
   Float_t         Electron_eta[200];   //[Electron_n]
   Float_t         Electron_phi[200];   //[Electron_n]
   Float_t         Electron_energy[200];   //[Electron_n]
   Float_t         Electron_charge[200];   //[Electron_n]
   Float_t         Electron_trkIso[200];   //[Electron_n]
   Float_t         Electron_ecalIso[200];   //[Electron_n]
   Float_t         Electron_hcalIso[200];   //[Electron_n]
   Float_t         Electron_SigmaIetaIeta[200];   //[Electron_n]
   Float_t         Electron_dEtaIn[200];   //[Electron_n]
   Float_t         Electron_dPhiIn[200];   //[Electron_n]
   Float_t         Electron_HoE[200];   //[Electron_n]
   Float_t         Electron_sc_energy[200];   //[Electron_n]
   Float_t         Electron_sc_eta[200];   //[Electron_n]
   Float_t         Electron_sc_phi[200];   //[Electron_n]
   Int_t           Muon_n;
   Float_t         Muon_px[200];   //[Muon_n]
   Float_t         Muon_py[200];   //[Muon_n]
   Float_t         Muon_pz[200];   //[Muon_n]
   Float_t         Muon_vx[200];   //[Muon_n]
   Float_t         Muon_vy[200];   //[Muon_n]
   Float_t         Muon_vz[200];   //[Muon_n]
   Float_t         Muon_pt[200];   //[Muon_n]
   Float_t         Muon_eta[200];   //[Muon_n]
   Float_t         Muon_phi[200];   //[Muon_n]
   Float_t         Muon_energy[200];   //[Muon_n]
   Float_t         Muon_charge[200];   //[Muon_n]
   Bool_t          Muon_isGlobalMuon[200];   //[Muon_n]
   Bool_t          Muon_isTrackerMuon[200];   //[Muon_n]
   Bool_t          Muon_isStandAloneMuon[200];   //[Muon_n]
   Bool_t          Muon_InnerTrack_isNonnull[200];   //[Muon_n]
   Bool_t          Muon_OuterTrack_isNonnull[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_x[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_y[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_z[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_px[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_py[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_InnerPoint_pz[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_x[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_y[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_z[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_px[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_py[200];   //[Muon_n]
   Float_t         Muon_OuterTrack_OuterPoint_pz[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_x[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_y[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_z[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_px[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_py[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_InnerPoint_pz[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_x[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_y[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_z[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_px[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_py[200];   //[Muon_n]
   Float_t         Muon_InnerTrack_OuterPoint_pz[200];   //[Muon_n]
   Float_t         Muon_OuterPoint_x[200];   //[Muon_n]
   Float_t         Muon_OuterPoint_y[200];   //[Muon_n]
   Float_t         Muon_OuterPoint_z[200];   //[Muon_n]
   Float_t         Muon_InnerPoint_x[200];   //[Muon_n]
   Float_t         Muon_InnerPoint_y[200];   //[Muon_n]
   Float_t         Muon_InnerPoint_z[200];   //[Muon_n]
   Float_t         Muon_trackIso[200];
   Float_t         Muon_ecalIso[200];
   Float_t         Muon_hcalIso[200];
   Float_t         Muon_relIso[200];
   Int_t           Muon_normChi2[200];
   Int_t           Muon_validHits[200]; 
   Int_t           Muon_numberOfMatches[200];
   Int_t           Muon_tkHits[200];
   Int_t           Muon_pixHits[200];
   Int_t           CosmicMuon_n;
   Float_t         CosmicMuon_px[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_py[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_pz[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_pt[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_eta[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_phi[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_energy[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_charge[200];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_isGlobalMuon[200];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_isTrackerMuon[200];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_isStandAloneMuon[200];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_InnerTrack_isNonnull[200];   //[CosmicMuon_n]
   Bool_t          CosmicMuon_OuterTrack_isNonnull[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_x[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_y[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_z[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_px[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_py[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_InnerPoint_pz[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_x[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_y[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_z[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_px[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_py[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterTrack_OuterPoint_pz[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_x[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_y[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_z[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_px[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_py[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_InnerPoint_pz[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_x[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_y[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_z[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_px[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_py[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_InnerTrack_OuterPoint_pz[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterPoint_x[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterPoint_y[200];   //[CosmicMuon_n]
   Float_t         CosmicMuon_OuterPoint_z[200];   //[CosmicMuon_n]
   Int_t           Tau_n;
   Float_t         Tau_px[100];   //[Tau_n]
   Float_t         Tau_py[100];   //[Tau_n]
   Float_t         Tau_pz[100];   //[Tau_n]
   Float_t         Tau_vx[100];   //[Tau_n]
   Float_t         Tau_vy[100];   //[Tau_n]
   Float_t         Tau_vz[100];   //[Tau_n]
   Float_t         Tau_pt[100];   //[Tau_n]
   Float_t         Tau_eta[100];   //[Tau_n]
   Float_t         Tau_phi[100];   //[Tau_n]
   Float_t         Tau_energy[100];   //[Tau_n]
   /*Float_t         Tau_charge[100];   //[Tau_n]
   Bool_t          Tau_DeltaBeta[100];
   Bool_t          Tau_tightDeltaBeta[100];
   Bool_t          Tau_DecayMode[100];
   Bool_t          Tau_AgainstEle[100];
   Bool_t          Tau_AgainstMuon[100];
   Int_t           Tau_1ProngPass[100];                                                                                                                            
   Int_t           Tau_2ProngPass[100];
   Int_t           Tau_3ProngPass[100];*/
   vector<string>  *genTauDecayMode1;
   Int_t           oneProng0Pi0[100];   //[Tau_n]
   Int_t           oneProng1Pi0[100];   //[Tau_n]
   Int_t           oneProng2Pi0[100];   //[Tau_n]
   Int_t           threeProng0Pi0[100];   //[Tau_n]
   Int_t           threeProng1Pi0[100];   //[Tau_n]
   Int_t           tauelectron[100];   //[Tau_n]
   Int_t           taumuon[100];   //[Tau_n]
   Int_t           nthreeProng1Pi0;
   Int_t           ntauelectron;
   Int_t           ntaumuon;
   Double_t        genHadTauPt[100];   //[Tau_n]
   Double_t        genHadTauEta[100];   //[Tau_n]
   Double_t        genHadTauPhi[100];   //[Tau_n]
   Int_t           nPions[100];   //[Tau_n]
   Int_t           PionPdgId[100][5];   //[Tau_n]
   Double_t        PionPt[100][5];   //[Tau_n]
   Double_t        PionEta[100][5];   //[Tau_n]
   Double_t        PionPhi[100][5];   //[Tau_n]
   Int_t           nPi0[100];   //[Tau_n]
   Int_t           Pi0PdgId[100][5];   //[Tau_n]
   Double_t        Pi0Pt[100][5];   //[Tau_n]
   Double_t        Pi0Eta[100][5];   //[Tau_n]
   Double_t        Pi0Phi[100][5];   //[Tau_n]
   Int_t           nPhotons[100];   //[Tau_n]
   Double_t        PhotonPt[100][5];   //[Tau_n]
   Double_t        PhotonEta[100][5];   //[Tau_n]
   Double_t        PhotonPhi[100][5];   //[Tau_n]
   Int_t           PhotonPdgId[100][5];   //[Tau_n]
   Bool_t          is_diphoton_event;
   Float_t         gen_pthat;
   Int_t           ngenphotons;
   Float_t         gen_photonpt[1000];   //[ngenphotons]
   
   Float_t         gen_photoneta[1000];   //[ngenphotons]
   Float_t         gen_photonphi[1000];   //[ngenphotons]
   
   Float_t         gen_photonpx[1000];   //[ngenphotons]
   Float_t         gen_photonpy[1000];   //[ngenphotons]
   Float_t         gen_photonpz[1000];   //[ngenphotons]
   Float_t         gen_photonE[1000];   //[ngenphotons]
   Int_t           gen_photonstatus[1000];   //[ngenphotons]
   
   Int_t           gen_photonMotherID[1000];   //[ngenphotons]
   
   Float_t         gen_photonMotherPt[1000];   //[ngenphotons]
   Float_t         gen_photonMotherEta[1000];   //[ngenphotons]
   Float_t         gen_photonMotherPhi[1000];   //[ngenphotons]
   Int_t           gen_photonMotherStatus[1000];   //[ngenphotons]
   
   Int_t           gen_photonGrandmotherID[1000];   //[ngenphotons]
   
   Float_t         gen_photonGrandmotherPt[1000];   //[ngenphotons]
   Float_t         gen_photonGrandmotherEta[1000];   //[ngenphotons]
   Float_t         gen_photonGrandmotherPhi[1000];   //[ngenphotons]
   Int_t           gen_photonGrandmotherStatus[1000];   //[ngenphotons]
   Int_t           nhardphotons;
   Float_t         gen_hardphotonpt[2];   //[nhardphotons]
   Float_t         gen_hardphotoneta[2];   //[nhardphotons]
   Float_t         gen_hardphotonphi[2];   //[nhardphotons]
   Float_t         gen_hardphotonpx[2];   //[nhardphotons]
   Float_t         gen_hardphotonpy[2];   //[nhardphotons]
   Float_t         gen_hardphotonpz[2];   //[nhardphotons]
   Float_t         gen_hardphotonE[2];   //[nhardphotons]
   Float_t         gen_gravitonpt;
   Float_t         gen_gravitoneta;
   Float_t         gen_gravitonphi;
   Float_t         gen_gravitonpx;
   Float_t         gen_gravitonpy;
   Float_t         gen_gravitonpz;
   Float_t         gen_gravitonE;
   
   Float_t         gen_Wdaughterpt[2];
   Float_t         gen_Wdaughtereta[2];
   Float_t         gen_Wdaughterphi[2];
   Float_t         gen_Wdaughterpx[2];
   Float_t         gen_Wdaughterpy[2];
   Float_t         gen_Wdaughterpz[2];
   Float_t         gen_WdaughterE[2];
   Int_t           gen_Wdaughter_charge[2];
   Int_t           gen_WdaughterID[2];
   Float_t         gen_Wbosonpt;
   Float_t         gen_Wbosoneta;
   Float_t         gen_Wbosonphi;
   Float_t         gen_Wbosonpx;
   Float_t         gen_Wbosonpy;
   Float_t         gen_Wbosonpz;
   Float_t         gen_WbosonE;
   Int_t           gen_Wbosoncharge;
   Int_t           gen_WbosonID;
   Float_t         gen_Zdaughterpt[2];
   Float_t         gen_Zdaughtereta[2];
   Float_t         gen_Zdaughterphi[2];
   Float_t         gen_Zdaughterpx[2];
   Float_t         gen_Zdaughterpy[2];
   Float_t         gen_Zdaughterpz[2];
   Float_t         gen_ZdaughterE[2];
   Int_t           gen_Zdaughter_charge[2];
   Int_t           gen_ZdaughterID[2];
   Float_t         gen_Zbosonpt;
   Float_t         gen_Zbosoneta;
   Float_t         gen_Zbosonphi;
   Float_t         gen_Zbosonpx;
   Float_t         gen_Zbosonpy;
   Float_t         gen_Zbosonpz;
   Float_t         gen_ZbosonE;
   Bool_t          is_signal_event;
   Bool_t          is_Z_event;
   Bool_t          is_W_event;
   Bool_t          is_Znunu_event;
   Bool_t          is_Zelec_event;
   Bool_t          is_Zmu_event;
   Bool_t          is_Ztau_event;
   Bool_t          is_Welec_event;
   Bool_t          is_Wmu_event;
   Bool_t          is_Wtau_event;
   Bool_t          is_isr_photon_event;
   Bool_t          is_SingleHardPhoton_event;
   Int_t           n_signal_events;
   Int_t           n_Z_events;
   Int_t           n_W_events;
   Int_t           n_Znunu_events;
   Int_t           n_Zelec_events;
   Int_t           n_Zmu_events;
   Int_t           n_Ztau_events;
   Int_t           n_Welec_events;
   Int_t           n_Wmu_events;
   Int_t           n_Wtau_events;
   Int_t           n_SingleHardPhoton_events;
   Int_t           n_diphoton_events;
   Float_t         gen_MuonID[200];
   Float_t         gen_MuonStatus[200];
   Float_t         gen_MuonPt[200];
   Float_t         gen_MuonDaughterpt[200];
   Float_t         gen_MuonDaughtereta[200];
   Float_t         gen_MuonDaughterphi[200];
   Float_t         gen_MuonDaughterpx[200];
   Float_t         gen_MuonDaughterpy[200];
   Float_t         gen_MuonDaughterpz[200];
   Float_t         gen_MuonDaughterE[200];
   Int_t           gen_MuonDaughterCharge[200];
   Int_t           gen_MuonDaughterStatus[200];
   Int_t           gen_MuonDaughterID[200];
   Float_t         gen_tauID[200];
   Float_t         gen_tauStatus[200];
   Float_t         gen_tauPt[200];
   Float_t         gen_tauDaughterpt[200];
   Float_t         gen_tauDaughtereta[200];
   Float_t         gen_tauDaughterphi[200];
   Float_t         gen_tauDaughterpx[200];
   Float_t         gen_tauDaughterpy[200];
   Float_t         gen_tauDaughterpz[200];
   Float_t         gen_tauDaughterE[200];
   Int_t           gen_tauDaughterCharge[200];
   Int_t           gen_tauDaughterStatus[200];
   Int_t           gen_tauDaughterID[200];
   Bool_t          Scraping_isScrapingEvent;
   Int_t           Photon_n;
   Float_t         Photon_E[200];   //[Photon_n]
   Float_t         Photon_pt[200];   //[Photon_n]
   Float_t         Photon_eta[200];   //[Photon_n]
   Float_t         Photon_phi[200];   //[Photon_n]
   Float_t         Photon_theta[200];   //[Photon_n]
   Float_t         Photon_et[200];   //[Photon_n]
   Float_t         Photon_swissCross[200];   //[Photon_n]
   Float_t         Photon_e6e2[200];   //[Photon_n]
   Float_t         Photon_e4e1[200];   //[Photon_n]
   Float_t         Photonr9[200];   //[Photon_n]
   Float_t         Photon_e1x5[200];   //[Photon_n]
   Float_t         Photon_e2x5[200];   //[Photon_n]
   Float_t         Photon_e3x3[200];   //[Photon_n]
   Float_t         Photon_e5x5[200];   //[Photon_n]
   Float_t         Photon_r1x5[200];   //[Photon_n]
   Float_t         Photon_r2x5[200];   //[Photon_n]
   Float_t         Photon_maxEnergyXtal[200];   //[Photon_n]
   Float_t         Photon_SigmaEtaEta[200];   //[Photon_n]
   Float_t         Photon_SigmaIetaIeta[200];   //[Photon_n]
   Float_t         Photon_SigmaEtaPhi[200];   //[Photon_n]
   Float_t         Photon_SigmaIetaIphi[200];   //[Photon_n]
   Float_t         Photon_SigmaPhiPhi[200];   //[Photon_n]
   Float_t         Photon_SigmaIphiIphi[200];   //[Photon_n]
   Float_t         Photon_Roundness[200];   //[Photon_n]
   Float_t         Photon_Angle[200];   //[Photon_n]
   Float_t         Photon_ecalRecHitSumEtConeDR03[200];   //[Photon_n]
   Float_t         Photon_hcalTowerSumEtConeDR03[200];   //[Photon_n]
   Float_t         Photon_trkSumPtSolidConeDR03[200];   //[Photon_n]
   Float_t         Photon_trkSumPtHollowConeDR03[200];   //[Photon_n]
   Int_t           Photon_nTrkSolidConeDR03[200];   //[Photon_n]
   Int_t           Photon_nTrkHollowConeDR03[200];   //[Photon_n]
   Float_t         Photon_hcalDepth1TowerSumEtConeDR03[200];   //[Photon_n]
   Float_t         Photon_hcalDepth2TowerSumEtConeDR03[200];   //[Photon_n]
   Float_t         Photon_ecalRecHitSumEtConeDR04[200];   //[Photon_n]
   Float_t         Photon_hcalTowerSumEtConeDR04[200];   //[Photon_n]
   Float_t         Photon_trkSumPtSolidConeDR04[200];   //[Photon_n]
   Float_t         Photon_trkSumPtHollowConeDR04[200];   //[Photon_n]
   Int_t           Photon_nTrkSolidConeDR04[200];   //[Photon_n]
   Int_t           Photon_nTrkHollowConeDR04[200];   //[Photon_n]
   Float_t         Photon_hcalDepth1TowerSumEtConeDR04[200];   //[Photon_n]
   Float_t         Photon_hcalDepth2TowerSumEtConeDR04[200];   //[Photon_n]
   Bool_t          Photon_hasPixelSeed[200];   //[Photon_n]
   Bool_t          Photon_isEB[200];   //[Photon_n]
   Bool_t          Photon_isEE[200];   //[Photon_n]
   Bool_t          Photon_isEBGap[200];   //[Photon_n]
   Bool_t          Photon_isEEGap[200];   //[Photon_n]
   Bool_t          Photon_isEBEEGap[200];   //[Photon_n]
   Float_t         Photon_e2e9[200];   //[Photon_n]
   Float_t         Photon_HoE[200];   //[Photon_n]
   Float_t         Photon_HoEnew[200];   //[Photon_n]
   Float_t         Photon_px[200];   //[Photon_n]
   Float_t         Photon_py[200];   //[Photon_n]
   Float_t         Photon_pz[200];   //[Photon_n]
   Float_t         Photon_vx[200];   //[Photon_n]
   Float_t         Photon_vy[200];   //[Photon_n]
   Float_t         Photon_vz[200];   //[Photon_n]
   Int_t           Photon_no_of_basic_clusters[200];   //[Photon_n]
   Float_t         Photon_sc_energy[200];   //[Photon_n]
   Float_t         Photon_sc_eta[200];   //[Photon_n]
   Float_t         Photon_sc_phi[200];   //[Photon_n]
   Float_t         Photon_sc_x[200];   //[Photon_n]
   Float_t         Photon_sc_y[200];   //[Photon_n]
   Float_t         Photon_sc_z[200];   //[Photon_n]
   Float_t         Photon_etaWidth[200];   //[Photon_n]
   Float_t         Photon_phiWidth[200];   //[Photon_n]
   Float_t         Photon_sc_et[200];   //[Photon_n]
   Float_t         matchphotonE[200];   //[Photon_n]
   Float_t         matchphotonpt[200];   //[Photon_n]
   Float_t         matchphotoneta[200];   //[Photon_n]
   Float_t         matchphotonphi[200];   //[Photon_n]
   Float_t         matchphotonpx[200];   //[Photon_n]
   Float_t         matchphotonpy[200];   //[Photon_n]
   Float_t         matchphotonpz[200];   //[Photon_n]
   Bool_t          ismatchedphoton[200];   //[Photon_n]
   Bool_t          Photon_hasConvTrk[200];   //[Photon_n]
   Int_t           Photon_ntracks[200];   //[Photon_n]
   Bool_t          Photon_isconverted[200];   //[Photon_n]
   Float_t         Photon_pairInvmass[200];   //[Photon_n]
   Float_t         Photon_pairCotThetaSeperation[200];   //[Photon_n]
   Float_t         Photon_pairmomentumX[200];   //[Photon_n]
   Float_t         Photon_pairmomentumY[200];   //[Photon_n]
   Float_t         Photon_pairmomentumZ[200];   //[Photon_n]
   Float_t         Photon_EoverP[200];   //[Photon_n]
   Float_t         Photon_ConvVx[200];   //[Photon_n]
   Float_t         Photon_ConvVy[200];   //[Photon_n]
   Float_t         Photon_ConvVz[200];   //[Photon_n]
   Float_t         Photon_ZOfPrimaryVertex[200];   //[Photon_n]
   Float_t         Photon_distOfMinimumApproach[200];   //[Photon_n]
   Float_t         Photon_dPhiTracksAtVtx[200];   //[Photon_n]
   Float_t         Photon_dPhiTracksAtEcal[200];   //[Photon_n]
   Float_t         Photon_dEtaTracksAtEcal[200];   //[Photon_n]
   Int_t           npho_;
   Bool_t          Photon_Electronveto[200];   //[npho_]
   Float_t         PFiso_Charged03[200];   //[npho_]
   Float_t         PFiso_Photon03[200];   //[npho_]
   Float_t         PFiso_Neutral03[200];   //[npho_]
   Float_t         PFiso_Sum03[200];   //[npho_]
   Float_t         PFWorstiso_Charged03[200];
   Int_t           Photon_ncrys[200];   //[Photon_n]
   Float_t         Photon_timing_xtal[200][100];   //[Photon_n]
   Float_t         Photon_timingavg_xtal[200];   //[Photon_n]
   Float_t         Photon_energy_xtal[200][100];   //[Photon_n]
   Int_t           Photon_ieta_xtalEB[200][100];   //[Photon_n]
   Int_t           Photon_iphi_xtalEB[200][100];   //[Photon_n]
   Int_t           Photon_recoFlag_xtalEB[200][100];   //[Photon_n]
   Float_t         Photon_timeError_xtal[200][100];   //[Photon_n]
   Float_t         Photon_s9[200];   //[Photon_n]
   Int_t           HERecHit_subset_n;
   UInt_t          HERecHit_subset_detid[10000];   //[HERecHit_subset_n]
   Float_t         HERecHit_subset_energy[10000];   //[HERecHit_subset_n]
   Float_t         HERecHit_subset_time[10000];   //[HERecHit_subset_n]
   Int_t           HERecHit_subset_depth[10000];   //[HERecHit_subset_n]
   Float_t         HERecHit_subset_phi[10000];   //[HERecHit_subset_n]
   Float_t         HERecHit_subset_eta[10000];   //[HERecHit_subset_n]
   Float_t         HERecHit_subset_x[10000];   //[HERecHit_subset_n]
   Float_t         HERecHit_subset_y[10000];   //[HERecHit_subset_n]
   Float_t         HERecHit_subset_z[10000];   //[HERecHit_subset_n]
   Float_t         Photon_mipChi2[10000];   //[Photon_n]                
   Float_t         Photon_mipTotEnergy[10000];   //[Photon_n] 
   Float_t         Photon_mipSlope[10000];   //[Photon_n]   
   Float_t         Photon_mipIntercept[10000];   //[Photon_n] 
   Int_t           Photon_mipNhitCone[10000];   //[Photon_n]                      
   Bool_t          Photon_mipIsHalo[10000];   //[Photon_n] 
   Int_t           EBRecHit_size;
   Float_t         EBRecHit_eta[10000];   //[EBRecHit_size]
   Float_t         EBRecHit_phi[10000];   //[EBRecHit_size]
   Int_t           EBRecHit_ieta[10000];   //[EBRecHit_size]
   Int_t           EBRecHit_iphi[10000];   //[EBRecHit_size]
   Float_t         EBRecHit_e[10000];   //[EBRecHit_size]
   Float_t         EBRecHit_et[10000];   //[EBRecHit_size]
   Int_t           EBRecHit_flag[10000];   //[EBRecHit_size]
   Float_t         EBRecHit_time[10000];   //[EBRecHit_size]
   Int_t           EERecHit_size;
   Float_t         EERecHit_eta[10000];   //[EERecHit_size]
   Float_t         EERecHit_phi[10000];   //[EERecHit_size]
   Int_t           EERecHit_ieta[10000];   //[EERecHit_size]
   Int_t           EERecHit_iphi[10000];   //[EERecHit_size]
   Float_t         EERecHit_e[10000];   //[EERecHit_size]
   Float_t         EERecHit_et[10000];   //[EERecHit_size]
   Int_t           EERecHit_flag[10000];   //[EERecHit_size]
   Float_t         EERecHit_time[10000];   //[EERecHit_size]
   Bool_t          isBeamHaloGlobalLoosePass;
   Bool_t          isBeamHaloGlobalTightPass;
   Bool_t          isBeamHaloHcalLoosePass;
   Bool_t          isBeamHaloHcalTightPass;
   Bool_t          isBeamHaloCSCLoosePass;
   Bool_t          isBeamHaloCSCTightPass;
   Bool_t          isBeamHaloEcalLoosePass;
   Bool_t          isBeamHaloEcalTightPass;
   Bool_t          isBeamHaloIDTightPass;
   Bool_t          isBeamHaloIDLoosePass;
   Bool_t          isSmellsLikeHalo_Tag;
   Bool_t          isLooseHalo_Tag;
   Bool_t          isTightHalo_Tag;
   Bool_t          isExtremeTightHalo_Tag;
   Float_t         CaloMetSigma;
   Float_t         CaloMetEz;
   Float_t         CaloEtFractionHadronic;
   Float_t         CaloEmEtFraction;
   Float_t         CaloHadEtInHB;
   Float_t         CaloHadEtInHE;
   Float_t         CaloHadEtInHO;
   Float_t         CaloHadEtInHF;
   Float_t         CaloEmEtInEB;
   Float_t         CaloEmEtInEE;
   Float_t         CaloEmEtInHF;
   Float_t         CaloMaxEtInEmTowers;
   Float_t         CaloMaxEtInHadTowers;
   Float_t         CaloMetPt[6];
   Float_t         CaloMetPx[6];
   Float_t         CaloMetPy[6];
   Float_t         CaloMetPhi[6];
   Float_t         CaloMetSumEt[6];
   Float_t         genMetPt;
   /*Float_t         genMetPx;
   Float_t         genMetPy;
   Float_t         genMetPhi;
   Float_t         genMetSumEt;*/
   Float_t         Delta_phi;
   //Float_t         Delta_phiGEN;
   Float_t         PFMetPt[6];
   Float_t         PFMetPx[6];
   Float_t         PFMetPy[6];
   Float_t         PFMetPhi[6];
   Float_t         PFMetSumEt[6];
   Float_t         Delta_phiPF;
   Float_t         TCMetPt[6];
   Float_t         TCMetPx[6];
   Float_t         TCMetPy[6];
   Float_t         TCMetPhi[6];
   Float_t         TCMetSumEt[6];
   Float_t         Delta_phiTC;
   Int_t           CaloTower_n;
   Float_t         CaloTower_eta[5000];   //[CaloTower_n]
   Float_t         CaloTower_phi[5000];   //[CaloTower_n]
   Float_t         CaloTower_E[5000];   //[CaloTower_n]
   Float_t         CaloTower_Et[5000];   //[CaloTower_n]
   Float_t         CaloTower_emEnergy[5000];   //[CaloTower_n]
   Float_t         CaloTower_hadEnergy[5000];   //[CaloTower_n]
   Float_t         CaloTower_p[5000];   //[CaloTower_n]
   Float_t         CaloTower_EMEt[5000];   //[CaloTower_n]
   Float_t         CaloTower_HadEt[5000];   //[CaloTower_n]
   Float_t         CaloTower_HadPhi[5000];   //[CaloTower_n]
   Float_t         CaloTower_HadEta[5000];   //[CaloTower_n]
   Float_t         CaloTower_EMPhi[5000];   //[CaloTower_n]
   Float_t         CaloTower_EMEta[5000];   //[CaloTower_n]
   Float_t         CaloTower_HadX[5000];   //[CaloTower_n]
   Float_t         CaloTower_HadY[5000];   //[CaloTower_n]
   Float_t         CaloTower_HadZ[5000];   //[CaloTower_n]
   Float_t         CaloTower_HE_E[5000];   //[CaloTower_n]
   Float_t         CaloTower_HB_E[5000];   //[CaloTower_n]
   Float_t         CaloTower_EMTime[5000];   //[CaloTower_n]
   Float_t         CaloTower_HadTime[5000];   //[CaloTower_n]
   Float_t         rho;
   Float_t         sigma;
   Float_t         rho44;
   Float_t         sigma44;


   // List of branches
   TBranch        *b_nevents;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_LumiNumber;   //!
   TBranch        *b_BXNumber;   //!
   TBranch        *b_totalIntensityBeam1;   //!
   TBranch        *b_totalIntensityBeam2;   //!
   TBranch        *b_avgInsDelLumi;   //!
   TBranch        *b_avgInsDelLumiErr;   //!
   TBranch        *b_avgInsRecLumi;   //!
   TBranch        *b_avgInsRecLumiErr;   //!
   TBranch        *b_ntriggers;   //!
   TBranch        *b_triggernames;   //!
   TBranch        *b_event_met_UncdownPhi;   //!        
   TBranch        *b_triggerprescales;   //!
   TBranch        *b_ifTriggerpassed;   //!
   TBranch        *b_trobjpt;   //!
   TBranch        *b_trobjeta;   //!
   TBranch        *b_trobjphi;   //!
   TBranch        *b_Vertex_n;   //!
   TBranch        *b_Vertex_x;   //!
   TBranch        *b_Vertex_y;   //!
   TBranch        *b_Vertex_z;   //!
   TBranch        *b_Vertex_tracksize;   //!
   TBranch        *b_Vertex_ndof;   //!
   TBranch        *b_Vertex_chi2;   //!
   TBranch        *b_Vertex_d0;   //!
   TBranch        *b_Vertex_isFake;   //!
   TBranch        *b_npuVertices;   //!
   TBranch        *b_ootnpuVertices;   //!
   TBranch        *b_Scraping_numOfTracks;   //!
   TBranch        *b_Scraping_fractionOfGoodTracks;   //!
   TBranch        *b_npuVerticesp1;   //!
   TBranch        *b_npuVerticesm1;   //!
   TBranch        *b_trueInteractions;   //!
   TBranch        *b_Track_n;   //!
   TBranch        *b_Track_px;   //!
   TBranch        *b_Track_py;   //!
   TBranch        *b_Track_pz;   //!
   TBranch        *b_Track_vx;   //!
   TBranch        *b_Track_vy;   //!
   TBranch        *b_Track_vz;   //!
   TBranch        *b_Track_pt;   //!
   TBranch        *b_Track_eta;   //!
   TBranch        *b_Track_phi;   //!
   TBranch        *b_Jet_n;   //!
   TBranch        *b_Jet_px;   //!
   TBranch        *b_Jet_py;   //!
   TBranch        *b_Jet_E;   //!
   TBranch        *b_Jet_pz;   //!
   TBranch        *b_Jet_vx;   //!
   TBranch        *b_Jet_vy;   //!
   TBranch        *b_Jet_vz;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_emEnergyFraction;   //!
   TBranch        *b_Jet_energyFractionHadronic;   //!
   TBranch        *b_Jet_hitsInN90;   //!
   TBranch        *b_Jet_n90Hits;   //!
   TBranch        *b_Jet_nTowers;   //!
   TBranch        *b_Jet_fHPD;   //!
   TBranch        *b_Jet_fRBX;   //!
   TBranch        *b_Jet_RHF;   //!
   TBranch        *b_Jet_jecCorr;   //!
   TBranch        *b_ucJet_px;   //!
   TBranch        *b_ucJet_py;   //!
   TBranch        *b_ucJet_E;   //!
   TBranch        *b_ucJet_pz;   //!
   TBranch        *b_ucJet_pt;   //!
   TBranch        *b_ucJet_eta;   //!
   TBranch        *b_ucJet_phi;   //!
   TBranch        *b_pfJet_n;   //!
   TBranch        *b_pfJet_px;   //!
   TBranch        *b_pfJet_py;   //!
   TBranch        *b_pfJet_E;   //!
   TBranch        *b_pfJet_pz;   //!
   TBranch        *b_pfJet_vx;   //!
   TBranch        *b_pfJet_vy;   //!
   TBranch        *b_pfJet_vz;   //!
   TBranch        *b_pfJet_pt;   //!
   TBranch        *b_pfJet_eta;   //!
   TBranch        *b_pfJet_phi;   //!
   TBranch        *b_pfjet_CEF;   //!
   TBranch        *b_pfjet_CHF;   //!
   TBranch        *b_pfjet_NEF;   //!
   TBranch        *b_pfjet_NHF;   //!
   TBranch        *b_pfjet_NCH;   //!
   TBranch        *b_pfjet_HFHAE;   //!
   TBranch        *b_pfjet_HFEME;   //!
   TBranch        *b_pfjet_NConstituents;   //!
   TBranch        *b_pfjet_Ndaughters;   //!
   TBranch        *b_pfjet_towersArea;   //!
   TBranch        *b_pfjet_isBasicJet;   //!
   TBranch        *b_pfjet_n60;   //!
   TBranch        *b_pfjet_n90;   //!
   TBranch        *b_pfjet_phoEFrac;   //!
   TBranch        *b_pfjet_partonFlav;   //!
   TBranch        *b_pujetIdFull_mva;   //! 
   TBranch        *b_pujetIdSimple_mva;   //! 
   TBranch        *b_pujetIdCutBased_mva;   //!
   TBranch        *b_pujetIdFull_loose;   //!
   TBranch        *b_pujetIdFull_medium;   //!
   TBranch        *b_pujetIdFull_tight;   //! 
   TBranch        *b_pujetIdSimple_loose;   //! 
   TBranch        *b_pujetIdSimple_medium;   //!   
   TBranch        *b_pujetIdSimple_tight;   //!  
   TBranch        *b_pujetIdCutBased_loose;   //! 
   TBranch        *b_pujetIdCutBased_medium;   //!    
   TBranch        *b_pujetIdCutBased_tight;   //!    
   TBranch        *b_pfjet_TrackCountHiEffBJetTags;   //!
   TBranch        *b_pfjet_TrackCountHiPurBJetTags;   //!
   TBranch        *b_pfjet_SimpleSVHiEffBJetTags;   //!
   TBranch        *b_pfjet_SimpleSVHiPurBJetTags;   //!
   TBranch        *b_pfJet_jecUncer;   //!
   TBranch        *b_pfJet_jecCorr;   //!
   TBranch        *b_ucpfJet_px;   //!
   TBranch        *b_ucpfJet_py;   //!
   TBranch        *b_ucpfJet_E;   //!
   TBranch        *b_ucpfJet_pz;   //!
   TBranch        *b_ucpfJet_pt;   //!
   TBranch        *b_ucpfJet_eta;   //!
   TBranch        *b_ucpfJet_phi;   //!
   /*TBranch        *b_genJet_n;   //!
   TBranch        *b_genJet_px;   //!
   TBranch        *b_genJet_py;   //!
   TBranch        *b_genJet_E;   //!
   TBranch        *b_genJet_pz;   //!
   TBranch        *b_genJet_pt;   //!
   TBranch        *b_genJet_eta;   //!
   TBranch        *b_genJet_phi;  */ //!
   TBranch        *b_Electron_n;   //!
   TBranch        *b_Electron_px;   //!
   TBranch        *b_Electron_py;   //!
   TBranch        *b_Electron_pz;   //!
   TBranch        *b_Electron_vx;   //!
   TBranch        *b_Electron_vy;   //!
   TBranch        *b_Electron_vz;   //!
   TBranch        *b_Electron_pt;   //!
   TBranch        *b_Electron_eta;   //!
   TBranch        *b_Electron_phi;   //!
   TBranch        *b_Electron_energy;   //!
   TBranch        *b_Electron_charge;   //!
   TBranch        *b_Electron_trkIso;   //!
   TBranch        *b_Electron_ecalIso;   //!
   TBranch        *b_Electron_hcalIso;   //!
   TBranch        *b_Electron_SigmaIetaIeta;   //!
   TBranch        *b_Electron_dEtaIn;   //!
   TBranch        *b_Electron_dPhiIn;   //!
   TBranch        *b_Electron_HoE;   //!
   TBranch        *b_Electron_sc_energy;   //!
   TBranch        *b_Electron_sc_eta;   //!
   TBranch        *b_Electron_sc_phi;   //!
   TBranch        *b_Muon_n;   //!
   TBranch        *b_Muon_px;   //!
   TBranch        *b_Muon_py;   //!
   TBranch        *b_Muon_pz;   //!
   TBranch        *b_Muon_vx;   //!
   TBranch        *b_Muon_vy;   //!
   TBranch        *b_Muon_vz;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_energy;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_isGlobalMuon;   //!
   TBranch        *b_Muon_isTrackerMuon;   //!
   TBranch        *b_Muon_isStandAloneMuon;   //!
   TBranch        *b_Muon_InnerTrack_isNonnull;   //!
   TBranch        *b_Muon_OuterTrack_isNonnull;   //!
   TBranch        *b_Muon_OuterTrack_InnerPoint_x;   //!
   TBranch        *b_Muon_OuterTrack_InnerPoint_y;   //!
   TBranch        *b_Muon_OuterTrack_InnerPoint_z;   //!
   TBranch        *b_Muon_OuterTrack_InnerPoint_px;   //!
   TBranch        *b_Muon_OuterTrack_InnerPoint_py;   //!
   TBranch        *b_Muon_OuterTrack_InnerPoint_pz;   //!
   TBranch        *b_Muon_OuterTrack_OuterPoint_x;   //!
   TBranch        *b_Muon_OuterTrack_OuterPoint_y;   //!
   TBranch        *b_Muon_OuterTrack_OuterPoint_z;   //!
   TBranch        *b_Muon_OuterTrack_OuterPoint_px;   //!
   TBranch        *b_Muon_OuterTrack_OuterPoint_py;   //!
   TBranch        *b_Muon_OuterTrack_OuterPoint_pz;   //!
   TBranch        *b_Muon_InnerTrack_InnerPoint_x;   //!
   TBranch        *b_Muon_InnerTrack_InnerPoint_y;   //!
   TBranch        *b_Muon_InnerTrack_InnerPoint_z;   //!
   TBranch        *b_Muon_InnerTrack_InnerPoint_px;   //!
   TBranch        *b_Muon_InnerTrack_InnerPoint_py;   //!
   TBranch        *b_Muon_InnerTrack_InnerPoint_pz;   //!
   TBranch        *b_Muon_InnerTrack_OuterPoint_x;   //!
   TBranch        *b_Muon_InnerTrack_OuterPoint_y;   //!
   TBranch        *b_Muon_InnerTrack_OuterPoint_z;   //!
   TBranch        *b_Muon_InnerTrack_OuterPoint_px;   //!
   TBranch        *b_Muon_InnerTrack_OuterPoint_py;   //!
   TBranch        *b_Muon_InnerTrack_OuterPoint_pz;   //!
   TBranch        *b_Muon_OuterPoint_x;   //!
   TBranch        *b_Muon_OuterPoint_y;   //!
   TBranch        *b_Muon_OuterPoint_z;   //!
   TBranch        *b_Muon_InnerPoint_x;   //!
   TBranch        *b_Muon_InnerPoint_y;   //!
   TBranch        *b_Muon_InnerPoint_z;   //!
   TBranch        *b_Muon_trackIso;   //!
   TBranch        *b_Muon_ecalIso;   //!
   TBranch        *b_Muon_hcalIso;   //!
   TBranch        *b_Muon_relIso;   //!
   TBranch        *b_Muon_normChi2;
   TBranch        *b_Muon_validHits; 
   TBranch        *b_Muon_numberOfMatches;
   TBranch        *b_Muon_tkHits;
   TBranch        *b_Muon_pixHits;
   TBranch        *b_CosmicMuon_n;   //!
   TBranch        *b_CosmicMuon_px;   //!
   TBranch        *b_CosmicMuon_py;   //!
   TBranch        *b_CosmicMuon_pz;   //!
   TBranch        *b_CosmicMuon_pt;   //!
   TBranch        *b_CosmicMuon_eta;   //!
   TBranch        *b_CosmicMuon_phi;   //!
   TBranch        *b_CosmicMuon_energy;   //!
   TBranch        *b_CosmicMuon_charge;   //!
   TBranch        *b_CosmicMuon_isGlobalMuon;   //!
   TBranch        *b_CosmicMuon_isTrackerMuon;   //!
   TBranch        *b_CosmicMuon_isStandAloneMuon;   //!
   TBranch        *b_CosmicMuon_InnerTrack_isNonnull;   //!
   TBranch        *b_CosmicMuon_OuterTrack_isNonnull;   //!
   TBranch        *b_CosmicMuon_OuterTrack_InnerPoint_x;   //!
   TBranch        *b_CosmicMuon_OuterTrack_InnerPoint_y;   //!
   TBranch        *b_CosmicMuon_OuterTrack_InnerPoint_z;   //!
   TBranch        *b_CosmicMuon_OuterTrack_InnerPoint_px;   //!
   TBranch        *b_CosmicMuon_OuterTrack_InnerPoint_py;   //!
   TBranch        *b_CosmicMuon_OuterTrack_InnerPoint_pz;   //!
   TBranch        *b_CosmicMuon_OuterTrack_OuterPoint_x;   //!
   TBranch        *b_CosmicMuon_OuterTrack_OuterPoint_y;   //!
   TBranch        *b_CosmicMuon_OuterTrack_OuterPoint_z;   //!
   TBranch        *b_CosmicMuon_OuterTrack_OuterPoint_px;   //!
   TBranch        *b_CosmicMuon_OuterTrack_OuterPoint_py;   //!
   TBranch        *b_CosmicMuon_OuterTrack_OuterPoint_pz;   //!
   TBranch        *b_CosmicMuon_InnerTrack_InnerPoint_x;   //!
   TBranch        *b_CosmicMuon_InnerTrack_InnerPoint_y;   //!
   TBranch        *b_CosmicMuon_InnerTrack_InnerPoint_z;   //!
   TBranch        *b_CosmicMuon_InnerTrack_InnerPoint_px;   //!
   TBranch        *b_CosmicMuon_InnerTrack_InnerPoint_py;   //!
   TBranch        *b_CosmicMuon_InnerTrack_InnerPoint_pz;   //!
   TBranch        *b_CosmicMuon_InnerTrack_OuterPoint_x;   //!
   TBranch        *b_CosmicMuon_InnerTrack_OuterPoint_y;   //!
   TBranch        *b_CosmicMuon_InnerTrack_OuterPoint_z;   //!
   TBranch        *b_CosmicMuon_InnerTrack_OuterPoint_px;   //!
   TBranch        *b_CosmicMuon_InnerTrack_OuterPoint_py;   //!
   TBranch        *b_CosmicMuon_InnerTrack_OuterPoint_pz;   //!
   TBranch        *b_CosmicMuon_OuterPoint_x;   //!
   TBranch        *b_CosmicMuon_OuterPoint_y;   //!
   TBranch        *b_CosmicMuon_OuterPoint_z;   //!
   TBranch        *b_Tau_n;   //!
   TBranch        *b_Tau_px;   //!
   TBranch        *b_Tau_py;   //!
   TBranch        *b_Tau_pz;   //!
   TBranch        *b_Tau_vx;   //!
   TBranch        *b_Tau_vy;   //!
   TBranch        *b_Tau_vz;   //!
   TBranch        *b_Tau_pt;   //!
   TBranch        *b_Tau_eta;   //!
   TBranch        *b_Tau_phi;   //!
   TBranch        *b_Tau_energy;   //!
   /*TBranch        *b_Tau_charge;   //!
   TBranch        *b_Tau_DeltaBeta;
   TBranch        *b_Tau_tightDeltaBeta;
   TBranch        *b_Tau_DecayMode;
   TBranch        *b_Tau_AgainstEle; 
   TBranch        *b_Tau_AgainstMuon; 
   TBranch        *b_Tau_1ProngPass; 
   TBranch        *b_Tau_2ProngPass;  
   TBranch        *b_Tau_3ProngPass; */ 
   TBranch        *b_genTauDecayMode1;   //!
   TBranch        *b_oneProng0Pi0;   //!
   TBranch        *b_oneProng1Pi0;   //!
   TBranch        *b_oneProng2Pi0;   //!
   TBranch        *b_threeProng0Pi0;   //!
   TBranch        *b_threeProng1Pi0;   //!
   TBranch        *b_tauelectron;   //!
   TBranch        *b_taumuon;   //!
   TBranch        *b_nthreeProng1Pi0;   //!
   TBranch        *b_ntauelectron;   //!
   TBranch        *b_ntaumuon;   //!
   TBranch        *b_genHadTauPt;   //!
   TBranch        *b_genHadTauEta;   //!
   TBranch        *b_genHadTauPhi;   //!
   TBranch        *b_nPions;   //!
   TBranch        *b_PionPdgId;   //!
   TBranch        *b_PionPt;   //!
   TBranch        *b_PionEta;   //!
   TBranch        *b_PionPhi;   //!
   TBranch        *b_nPi0;   //!
   TBranch        *b_Pi0PdgId;   //!
   TBranch        *b_Pi0Pt;   //!
   TBranch        *b_Pi0Eta;   //!
   TBranch        *b_Pi0Phi;   //!
   TBranch        *b_nPhotons;   //!
   TBranch        *b_PhotonPt;   //!
   TBranch        *b_PhotonEta;   //!
   TBranch        *b_PhotonPhi;   //!
   TBranch        *b_PhotonPdgId;   //!
   TBranch        *b_gen_photonpt;   //!
   TBranch        *b_gen_photonMotherID;   //!
   TBranch        *b_gen_photonGrandmotherID;   //!
   TBranch        *b_is_diphoton_event;   //!
  
   TBranch        *b_gen_pthat;   //!
   TBranch        *b_ngenphotons;   //!

   TBranch        *b_gen_photoneta;   //!
   TBranch        *b_gen_photonphi;   //!
   
   TBranch        *b_gen_photonpx;   //!
   TBranch        *b_gen_photonpy;   //!
   TBranch        *b_gen_photonpz;   //!
   TBranch        *b_gen_photonE;   //!
   TBranch        *b_gen_photonstatus;   //!

   TBranch        *b_gen_photonMotherPt;   //!
   TBranch        *b_gen_photonMotherEta;   //!
   TBranch        *b_gen_photonMotherPhi;   //!
   TBranch        *b_gen_photonMotherStatus;   //!

   TBranch        *b_gen_photonGrandmotherPt;   //!
   TBranch        *b_gen_photonGrandmotherEta;   //!
   TBranch        *b_gen_photonGrandmotherPhi;   //!
   TBranch        *b_gen_photonGrandmotherStatus;   //!
   TBranch        *b_nhardphotons;   //!
   TBranch        *b_gen_hardphotonpt;   //!
   TBranch        *b_gen_hardphotoneta;   //!
   TBranch        *b_gen_hardphotonphi;   //!
   TBranch        *b_gen_hardphotonpx;   //!
   TBranch        *b_gen_hardphotonpy;   //!
   TBranch        *b_gen_hardphotonpz;   //!
   TBranch        *b_gen_hardphotonE;   //!
   TBranch        *b_gen_gravitonpt;   //!
   TBranch        *b_gen_gravitoneta;   //!
   TBranch        *b_gen_gravitonphi;   //!
   TBranch        *b_gen_gravitonpx;   //!
   TBranch        *b_gen_gravitonpy;   //!
   TBranch        *b_gen_gravitonpz;   //!
   TBranch        *b_gen_gravitonE;   //!
   
   TBranch        *b_gen_Wdaughter_pt;   //!
   TBranch        *b_gen_Wdaughter_eta;   //!
   TBranch        *b_gen_Wdaughter_phi;   //!
   TBranch        *b_gen_Wdaughter_px;   //!
   TBranch        *b_gen_Wdaughter_py;   //!
   TBranch        *b_gen_Wdaughter_pz;   //!
   TBranch        *b_gen_Wdaughter_E;   //!
   TBranch        *b_gen_Wdaughter_charge;   //!
   TBranch        *b_gen_Wdaughter_ID;   //!
   TBranch        *b_gen_Wboson_pt;   //!
   TBranch        *b_gen_Wboson_eta;   //!
   TBranch        *b_gen_Wboson_phi;   //!
   TBranch        *b_gen_Wboson_px;   //!
   TBranch        *b_gen_Wboson_py;   //!
   TBranch        *b_gen_Wboson_pz;   //!
   TBranch        *b_gen_Wboson_E;   //!
   TBranch        *b_gen_Wboson_charge;   //!
   TBranch        *b_gen_Wboson_ID;   //!
   TBranch        *b_gen_Zdaughter_pt;   //!
   TBranch        *b_gen_Zdaughter_eta;   //!
   TBranch        *b_gen_Zdaughter_phi;   //!
   TBranch        *b_gen_Zdaughter_px;   //!
   TBranch        *b_gen_Zdaughter_py;   //!
   TBranch        *b_gen_Zdaughter_pz;   //!
   TBranch        *b_gen_Zdaughter_E;   //!
   TBranch        *b_gen_Zdaughter_charge;   //!
   TBranch        *b_gen_Zdaughter_ID;   //!
   TBranch        *b_gen_Zboson_pt;   //!
   TBranch        *b_gen_Zboson_eta;   //!
   TBranch        *b_gen_Zboson_phi;   //!
   TBranch        *b_gen_Zboson_px;   //!
   TBranch        *b_gen_Zboson_py;   //!
   TBranch        *b_gen_Zboson_pz;   //!
   TBranch        *b_gen_Zboson_E;   //!
   TBranch        *b_is_signal_event;   //!
   TBranch        *b_is_Z_event;   //!
   TBranch        *b_is_W_event;   //!
   TBranch        *b_is_Znunu_event;   //!
   TBranch        *b_is_Zelec_event;   //!
   TBranch        *b_is_Zmu_event;   //!
   TBranch        *b_is_Ztau_event;   //!
   TBranch        *b_is_Welec_event;   //!
   TBranch        *b_is_Wmu_event;   //!
   TBranch        *b_is_Wtau_event;   //!
   TBranch        *b_is_SingleHardPhoton_event;   //!
   TBranch        *b_is_isr_photon_event;   //!
   TBranch        *b_n_signal_events;   //!
   TBranch        *b_n_Z_events;   //!
   TBranch        *b_n_W_events;   //!
   TBranch        *b_n_Znunu_events;   //!
   TBranch        *b_n_Zelec_events;   //!
   TBranch        *b_n_Zmu_events;   //!
   TBranch        *b_n_Ztau_events;   //!
   TBranch        *b_n_Welec_events;   //!
   TBranch        *b_n_Wmu_events;   //!
   TBranch        *b_n_Wtau_events;   //!
   TBranch        *b_n_SingleHardPhoton_events;   //!
   TBranch        *b_n_diphoton_events;   //!
   TBranch        *b_gen_Muon_ID;   //!
   TBranch        *b_gen_Muon_Status;   //!
   TBranch        *b_gen_Muon_Pt;   //!
   TBranch        *b_gen_MuonDaughter_pt;   //!
   TBranch        *b_gen_MuonDaughter_eta;   //!
   TBranch        *b_gen_MuonDaughter_phi;   //!
   TBranch        *b_gen_MuonDaughter_px;   //!
   TBranch        *b_gen_MuonDaughter_py;   //!
   TBranch        *b_gen_MuonDaughter_pz;   //!
   TBranch        *b_gen_MuonDaughter_E;   //!
   TBranch        *b_gen_MuonDaughter_charge;   //!
   TBranch        *b_gen_MuonDaughter_status;   //!
   TBranch        *b_gen_MuonDaughter_ID;   //!
   TBranch        *b_gen_tau_ID;   //!
   TBranch        *b_gen_tau_Status;   //!
   TBranch        *b_gen_tau_Pt;   //!
   TBranch        *b_gen_tauDaughter_pt;   //!
   TBranch        *b_gen_tauDaughter_eta;   //!
   TBranch        *b_gen_tauDaughter_phi;   //!
   TBranch        *b_gen_tauDaughter_px;   //!
   TBranch        *b_gen_tauDaughter_py;   //!
   TBranch        *b_gen_tauDaughter_pz;   //!
   TBranch        *b_gen_tauDaughter_E;   //!
   TBranch        *b_gen_tauDaughter_charge;   //!
   TBranch        *b_gen_tauDaughter_status;   //!
   TBranch        *b_gen_tauDaughter_ID;    //!
   TBranch        *b_Scraping_isScrapingEvent;//!
   TBranch        *b_Photon_n;   //!
   TBranch        *b_Photon_E;   //!
   TBranch        *b_Photon_pt;   //!
   TBranch        *b_Photon_eta;   //!
   TBranch        *b_Photon_phi;   //!
   TBranch        *b_Photon_theta;   //!
   TBranch        *b_Photon_et;   //!
   TBranch        *b_Photon_swissCross;   //!
   TBranch        *b_Photon_e6e2;   //!
   TBranch        *b_Photon_e4e1;   //!
   TBranch        *b_Photonr9;   //!
   TBranch        *b_Photon_e1x5;   //!
   TBranch        *b_Photon_e2x5;   //!
   TBranch        *b_Photon_e3x3;   //!
   TBranch        *b_Photon_e5x5;   //!
   TBranch        *b_Photon_r1x5;   //!
   TBranch        *b_Photon_r2x5;   //!
   TBranch        *b_Photon_maxEnergyXtal;   //!
   TBranch        *b_Photon_SigmaEtaEta;   //!
   TBranch        *b_Photon_SigmaIetaIeta;   //!
   TBranch        *b_Photon_SigmaEtaPhi;   //!
   TBranch        *b_Photon_SigmaIetaIphi;   //!
   TBranch        *b_Photon_SigmaPhiPhi;   //!
   TBranch        *b_Photon_SigmaIphiIphi;   //!
   TBranch        *b_Photon_Roundness;   //!
   TBranch        *b_Photon_Angle;   //!
   TBranch        *b_Photon_ecalRecHitSumEtConeDR03;   //!
   TBranch        *b_Photon_hcalTowerSumEtConeDR03;   //!
   TBranch        *b_Photon_trkSumPtSolidConeDR03;   //!
   TBranch        *b_Photon_trkSumPtHollowConeDR03;   //!
   TBranch        *b_Photon_nTrkSolidConeDR03;   //!
   TBranch        *b_Photon_nTrkHollowConeDR03;   //!
   TBranch        *b_Photon_hcalDepth1TowerSumEtConeDR03;   //!
   TBranch        *b_Photon_hcalDepth2TowerSumEtConeDR03;   //!
   TBranch        *b_Photon_ecalRecHitSumEtConeDR04;   //!
   TBranch        *b_Photon_hcalTowerSumEtConeDR04;   //!
   TBranch        *b_Photon_trkSumPtSolidConeDR04;   //!
   TBranch        *b_Photon_trkSumPtHollowConeDR04;   //!
   TBranch        *b_Photon_nTrkSolidConeDR04;   //!
   TBranch        *b_Photon_nTrkHollowConeDR04;   //!
   TBranch        *b_Photon_hcalDepth1TowerSumEtConeDR04;   //!
   TBranch        *b_Photon_hcalDepth2TowerSumEtConeDR04;   //!
   TBranch        *b_Photon_hasPixelSeed;   //!
   TBranch        *b_Photon_isEB;   //!
   TBranch        *b_Photon_isEE;   //!
   TBranch        *b_Photon_isEBGap;   //!
   TBranch        *b_Photon_isEEGap;   //!
   TBranch        *b_Photon_isEBEEGap;   //!
   TBranch        *b_Photon_e2e9;   //!
   TBranch        *b_Photon_HoE;   //!
   TBranch        *b_Photon_HoEnew;   //!
   TBranch        *b_Photon_px;   //!
   TBranch        *b_Photon_py;   //!
   TBranch        *b_Photon_pz;   //!
   TBranch        *b_Photon_vx;   //!
   TBranch        *b_Photon_vy;   //!
   TBranch        *b_Photon_vz;   //!
   TBranch        *b_Photon_no_of_basic_clusters;   //!
   TBranch        *b_Photon_sc_energy;   //!
   TBranch        *b_Photon_sc_eta;   //!
   TBranch        *b_Photon_sc_phi;   //!
   TBranch        *b_Photon_sc_x;   //!
   TBranch        *b_Photon_sc_y;   //!
   TBranch        *b_Photon_sc_z;   //!
   TBranch        *b_Photon_etaWidth;   //!
   TBranch        *b_Photon_phiWidth;   //!
   TBranch        *b_Photon_sc_et;   //!
   TBranch        *b_matchphotonE;   //!
   TBranch        *b_matchphotonpt;   //!
   TBranch        *b_matchphotoneta;   //!
   TBranch        *b_matchphotonphi;   //!
   TBranch        *b_matchphotonpx;   //!
   TBranch        *b_matchphotonpy;   //!
   TBranch        *b_matchphotonpz;   //!
   TBranch        *b_ismatchedphoton;   //!
   TBranch        *b_Photon_hasConvTrk;   //!
   TBranch        *b_Photon_ntracks;   //!
   TBranch        *b_Photon_isconverted;   //!
   TBranch        *b_Photon_pairInvmass;   //!
   TBranch        *b_Photon_pairCotThetaSeperation;   //!
   TBranch        *b_Photon_pairmomentumX;   //!
   TBranch        *b_Photon_pairmomentumY;   //!
   TBranch        *b_Photon_pairmomentumZ;   //!
   TBranch        *b_Photon_EoverP;   //!
   TBranch        *b_Photon_ConvVx;   //!
   TBranch        *b_Photon_ConvVy;   //!
   TBranch        *b_Photon_ConvVz;   //!
   TBranch        *b_Photon_ZOfPrimaryVertex;   //!
   TBranch        *b_Photon_distOfMinimumApproach;   //!
   TBranch        *b_Photon_dPhiTracksAtVtx;   //!
   TBranch        *b_Photon_dPhiTracksAtEcal;   //!
   TBranch        *b_Photon_dEtaTracksAtEcal;   //!
   TBranch        *b_npho_;   //!
   TBranch        *b_Photon_Electronveto;   //!
   TBranch        *b_PFiso_Charged03;   //!
   TBranch        *b_PFiso_Photon03;   //!
   TBranch        *b_PFiso_Neutral03;   //!
   TBranch        *b_PFiso_Sum03;   //!
   TBranch        *b_PFWorstiso_Charged03; 
   TBranch        *b_Photon_ncrys;   //!
   TBranch        *b_Photon_timing_xtal;   //!
   TBranch        *b_Photon_timingavg_xtal;   //!
   TBranch        *b_Photon_energy_xtal;   //!
   TBranch        *b_Photon_ieta_xtalEB;   //!
   TBranch        *b_Photon_iphi_xtalEB;   //!
   TBranch        *b_Photon_recoFlag_xtalEB;   //!
   TBranch        *b_Photon_timeError_xtal;   //!
   TBranch        *b_Photon_s9;   //!
   TBranch        *b_HERecHit_subset_n;   //!
   TBranch        *b_HERecHit_subset_detid;   //!
   TBranch        *b_HERecHit_subset_energy;   //!
   TBranch        *b_HERecHit_subset_time;   //!
   TBranch        *b_HERecHit_subset_depth;   //!
   TBranch        *b_HERecHit_subset_phi;   //!
   TBranch        *b_HERecHit_subset_eta;   //!
   TBranch        *b_HERecHit_subset_x;   //!
   TBranch        *b_HERecHit_subset_y;   //!
   TBranch        *b_HERecHit_subset_z;   //!
   TBranch        *b_Photon_mipChi2;   //!
   TBranch        *b_Photon_mipTotEnergy;   //!
   TBranch        *b_Photon_mipSlope;   //!
   TBranch        *b_Photon_mipIntercept;   //!
   TBranch        *b_Photon_mipNhitCone;   //!
   TBranch        *b_Photon_mipIsHalo;   //! 
   TBranch        *b_EBRecHit_size;   //!
   TBranch        *b_EBRecHit_eta;   //!
   TBranch        *b_EBRecHit_phi;   //!
   TBranch        *b_EBRecHit_ieta;   //!
   TBranch        *b_EBRecHit_iphi;   //!
   TBranch        *b_EBRecHit_e;   //!
   TBranch        *b_EBRecHit_et;   //!
   TBranch        *b_EBRecHit_flag;   //!
   TBranch        *b_EBRecHit_time;   //!
   TBranch        *b_EERecHit_size;   //!
   TBranch        *b_EERecHit_eta;   //!
   TBranch        *b_EERecHit_phi;   //!
   TBranch        *b_EERecHit_ieta;   //!
   TBranch        *b_EERecHit_iphi;   //!
   TBranch        *b_EERecHit_e;   //!
   TBranch        *b_EERecHit_et;   //!
   TBranch        *b_EERecHit_flag;   //!
   TBranch        *b_EERecHit_time;   //!
   TBranch        *b_isBeamHaloGlobalLoosePass;   //!
   TBranch        *b_isBeamHaloGloablTightPass;   //!
   TBranch        *b_isBeamHaloHcalLoosePass;   //!
   TBranch        *b_isBeamHaloHcalTightPass;   //!
   TBranch        *b_isBeamHaloCSCLoosePass;   //!
   TBranch        *b_isBeamHaloCSCTightPass;   //!
   TBranch        *b_isBeamHaloEcalLoosePass;   //!
   TBranch        *b_isBeamHaloEcalTightPass;   //!
   TBranch        *b_isBeamHaloIDTightPass;   //!
   TBranch        *b_isBeamHaloIDLoosePass;   //!
   TBranch        *b_isSmellsLikeHalo_Tag;   //!
   TBranch        *b_isLooseHalo_Tag;   //!
   TBranch        *b_isTightHalo_Tag;   //!
   TBranch        *b_isExtremeTightHalo_Tag;   //!
   TBranch        *b_CaloMetSig;   //!
   TBranch        *b_CaloMetEz;   //!
   TBranch        *b_CaloEtFractionHadronic;   //!
   TBranch        *b_CaloEmEtFraction;   //!
   TBranch        *b_CaloHadEtInHB;   //!
   TBranch        *b_CaloHadEtInHE;   //!
   TBranch        *b_CaloHadEtInHO;   //!
   TBranch        *b_CaloHadEtInHF;   //!
   TBranch        *b_CaloEmEtInEB;   //!
   TBranch        *b_CaloEmEtInEE;   //!
   TBranch        *b_CaloEmEtInHF;   //!
   TBranch        *b_CaloMaxEtInEmTowers;   //!
   TBranch        *b_CaloMaxEtInHadTowers;   //!
   TBranch        *b_CaloMetPt;   //!
   TBranch        *b_CaloMetPx;   //!
   TBranch        *b_CaloMetPy;   //!
   TBranch        *b_CaloMetPhi;   //!
   TBranch        *b_CaloMetSumEt;   //!
   /*TBranch        *b_genMetPt;   //!
   TBranch        *b_genMetPx;   //!
   TBranch        *b_genMetPy;   //!
   TBranch        *b_genMetPhi;   //!
   TBranch        *b_genMetSumEt; */  //!
   TBranch        *b_Delta_phi;   //!
   //TBranch        *b_Delta_phiGEN;   //!
   TBranch        *b_PFMetPt;   //!
   TBranch        *b_PFMetPx;   //!
   TBranch        *b_PFMetPy;   //!
   TBranch        *b_PFMetPhi;   //!
   TBranch        *b_PFMetSumEt;   //!
   TBranch        *b_Delta_phiPF;   //!
   TBranch        *b_TCMetPt;   //!
   TBranch        *b_TCMetPx;   //!
   TBranch        *b_TCMetPy;   //!
   TBranch        *b_TCMetPhi;   //!
   TBranch        *b_TCMetSumEt;   //!
   TBranch        *b_Delta_phiTC;   //!
   TBranch        *b_CaloTower_n;   //!
   TBranch        *b_CaloTower_eta;   //!
   TBranch        *b_CaloTower_phi;   //!
   TBranch        *b_CaloTower_E;   //!
   TBranch        *b_CaloTower_Et;   //!
   TBranch        *b_CaloTower_emEnergy;   //!
   TBranch        *b_CaloTower_hadEnergy;   //!
   TBranch        *b_CaloTower_p;   //!
   TBranch        *b_CaloTower_EMEt;   //!
   TBranch        *b_CaloTower_HadEt;   //!
   TBranch        *b_CaloTower_HadPhi;   //!
   TBranch        *b_CaloTower_HadEta;   //!
   TBranch        *b_CaloTower_EMPhi;   //!
   TBranch        *b_CaloTower_EMEta;   //!
   TBranch        *b_CaloTower_HadX;   //!
   TBranch        *b_CaloTower_HadY;   //!
   TBranch        *b_CaloTower_HadZ;   //!
   TBranch        *b_CaloTower_HE_E;   //!
   TBranch        *b_CaloTower_HB_E;   //!
   TBranch        *b_CaloTower_EMTime;   //!
   TBranch        *b_CaloTower_HadTime;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_sigma;   //!
   TBranch        *b_rho44;   //!
   TBranch        *b_sigma44;   //!



   //myEvent(TTree *tree=0);
   myEvent(const char* file1, const char* file2, const int runner);
   virtual ~myEvent();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   //virtual void     Init(TTree *tree);
   virtual void     Init(TChain *tree);
   virtual void     Loop(double Pt,double Met,double JetPt, double TrackPt, float pvalue,float minmet,float dphi,double Mupt,double Elept,int isMonteCarlo,const char* pileupfile);
   //virtual Bool_t     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual void     BookHistos(const char* file2);
   bool  isPho(int jet);
   bool  IsPhoPho(int &pho1);
   bool  IsPhoJet(int &jet1);
   bool  IsDarkPho(int &pho1);
   bool  IsDarkJet(int &jet1);
   bool to_bool(int atta);
   double ChiSquare(double CHF,int n60, int n90, int NCH, int nconst, int ndaught, double NHF, double phoEFrac, double jetPt);
   double MVACalc(int n60, int n90, int nconst, double NHF, double phoEFrac);

   bool  VertexDecision(int &foundVertex);
   bool  NonCosmicDecision();
   double JetShowerPhi(int jet, double size);
   double JetTrackIso(int jet);
   bool  MediumPhotonIdDecision(int &pho_index);
   bool  TightPhotonIdDecision(int &pho_index);
   bool  PassingKinematics(int &passPho);
   bool OverlapWithMuon(double eta, double phi);
   bool OverlapWithElectron(double eta, double phi);
   double  Seed_LICTD_Decision(int pho_index);
   double  EAElectroncharged(double eta);
   double  EAPFWorstElectroncharged(double eta);
   double  EAElectronneutral(double eta);
   double  EAElectronphoton(double eta);
   std::vector<int>  JetVetoDecision(int pho_index);   
   double DeltaR(double eta1, double eta2, double phi1,double phi2);
   double DeltaPhi(double phi1,double phi2);
   void LumiReWeighting( std::vector< float > MC_distr, std::vector< float > Lumi_distr);
   double puweight(float npv);


};
#endif

#ifdef myEvent_cxx
//myEvent::myEvent()
myEvent::myEvent(const char* file1, const char* file2, const int runner)
{
  gErrorIgnoreLevel = kError;
  TChain *chain = new TChain("myEvent");
  
  
  //TString location = "dcap://cmsgridftp.fnal.gov:24125";
  TString location = "";
  
  //TString path1= "/pnfs/cms/WAX/11/store/user/lpcgg/sushil/Summer12/MC/53X_MC/";
  //TString path2 = "/pnfs/fnal.gov/usr/cms/WAX/11/store/user/lpcgg/sushil/Summer12/MC/53X_MC/";
  //TString path1= "/eos/uscms/store/user/dokstolp/CRAB_UserFiles";
  TString path1= "/eos/uscms/store";
  //TString path1= "/eos/uscms/store/user";
  //TString path1= "/eos/uscms/store/user/lpcgg/sushil/Summer12/MC/53X_MC/WTolnu/";
  //TString path2 = "/eos/uscms/store/user/lpcgg/sushil/Summer12/MC/53X_MC/WTolnu/";
  //TString path = "/eos/uscms/store/user/dokstolp/CRAB_UserFiles/crab_ntuples_df1/150302_192318/0000/ntuples_df1_10.root";
  TString short_path =path1+file1;
  TString fileOut = file2;
  
  TSystemDirectory sourceDir("hi",short_path);
  TList* fileList = sourceDir.GetListOfFiles();
  TIter next(fileList);
  TSystemFile* filename;
  int fileNumber = 0;
  int maxFiles = -1;
  int runNumber =0;
  TString out = "output";
/*
  TString  FullPathInputFile = path;
  std::cout<<FullPathInputFile<<std::endl;
  chain->Add(FullPathInputFile);
  std::cout<<chain->GetEntries()<<std::endl;
*/
  while ((filename = (TSystemFile*)next()) && fileNumber >  maxFiles){
    //cout<<"filename\t"<<filename->GetName()<<endl;
    if(fileNumber > 1 && runNumber==runner)
      {
        TString  FullPathInputFile = (location+short_path+filename->GetName());
        TString name = filename->GetName();
        TString dataset = "outputfile_photonHad_run2012A_06Aug";
        TString dataset1 = "outputfile_photon_run2012A_06Aug";
        //if(name.Contains(dataset) || name.Contains(dataset1))                                                                                                     
        //{                                                                                                                                                         
	std::cout<<FullPathInputFile<<std::endl;
        chain->Add(FullPathInputFile);
	std::cout<<chain->GetEntries()<<std::endl;
        //}                                                                                                                                                         
      }
    //if(!fileOut.Contains(out) && fileNumber % 1 ==0) runNumber++;
    if(!fileOut.Contains(out) && fileNumber % 5 ==0) runNumber++;
    fileNumber++;
  }//loop over while      
  //std::cout<<chain->GetEntries()<<std::endl;
  cout<<runNumber<<endl;
 

  /*
  TString location = "";
  TString path = file1;
  TString short_path =file1;
  TSystemDirectory sourceDir("hi",path);
  TList* fileList = sourceDir.GetListOfFiles();
  TIter next(fileList);
  TSystemFile* filename;
  int fileNumber = 0;
  int maxFiles = -1;
  while ((filename = (TSystemFile*)next()) && fileNumber >  maxFiles){
    if(fileNumber > 1)
      {
        TString  FullPathInputFile = (location+short_path+filename->GetName());
        TString name = filename->GetName();
        TString dataset = "outputfile_photonHad_run2012A_06Aug";
        TString dataset1 = "outputfile_photon_run2012A_06Aug";
        //if(name.Contains(dataset) || name.Contains(dataset1))                                                                                                                            
        //{                                                                                                                                                                                
	std::cout<<FullPathInputFile<<std::endl;
        chain->Add(FullPathInputFile);
	std::cout<<chain->GetEntries()<<std::endl;
        //}                                                                                                                                                                                
      }
    fileNumber++;
  }//loop over while                                                                                                                                                                       


  
  TString location = "dcap://cmsgridftp.fnal.gov:24125";
  //TString location = "";
  TString path = "/pnfs/cms/WAX/11/store/user/lpcgg/sushil/Summer12/MC/53X_MC/ADD//ADDmonoPhoton_MD1_d3/";
  TString short_path ="/pnfs/fnal.gov/usr/cms/WAX/11/store/user/lpcgg/sushil/Summer12/MC/53X_MC/ADD//ADDmonoPhoton_MD1_d3/";

  //TString path = "/pnfs/cms/WAX/11/store/user/lpcgg/sushil/Summer12/MC/53X_MC/DM/DM_M_300_VectorUNI/";
  //TString short_path ="/pnfs/fnal.gov/usr/cms/WAX/11/store/user/lpcgg/sushil/Summer12/MC/53X_MC/DM/DM_M_300_VectorUNI/";
  
  // TString path = "/pnfs/cms/WAX/11/store/user/sushil/Summer11/MC/W_ENu_Large/";
  // TString short_path ="/pnfs/fnal.gov/usr/cms/WAX/11/store/user/sushil/Summer11/MC/W_ENu_Large/";
 
  
  //TString path = "/pnfs/cms/WAX/11/store/user/carley/Summer11/MC/W_TauNu/";
  // TString short_path ="/pnfs/fnal.gov/usr/cms/WAX/11/store/user/carley/Summer11/MC/W_TauNu/";
 
  
 //TString path = "/pnfs/cms/WAX/11/store/user/carley/Summer11/MC/W_MuNu/";
 //TString short_path ="/pnfs/fnal.gov/usr/cms/WAX/11/store/user/carley/Summer11/MC/W_MuNu/";
  
  TSystemDirectory sourceDir("hi",path);
  TList* fileList = sourceDir.GetListOfFiles();
  TIter next(fileList);
  TSystemFile* filename;
  int fileNumber = 0;
  int maxFiles = -1;
  while ((filename = (TSystemFile*)next()) && fileNumber >  maxFiles){
    if(fileNumber > 1)
      {
	TString  FullPathInputFile = (location+short_path+filename->GetName());
	std::cout<<FullPathInputFile<<std::endl;
	chain->Add(FullPathInputFile); 
	std::cout<<chain->GetEntries()<<std::endl;
      }
    fileNumber++;
  }//loop over while
  */
  
  
  //chain->Add(file1);
  //chain->Add("/uscmst1b_scratch/lpc1/3DayLifetime/sushil/Histo_AOD.root");
  //chain->Add("/eos/uscms/store/user/bhawna/2012Data_pfiso_condor/Histo_AOD_17_1_o1Z.root");
  //chain->Add("/eos/uscms/store/user/bhawna/2012Data_pfiso_condor/Histo_AOD_192_1_dzV.root");
  //chain->Add("/eos/uscms/store/user/bhawna/2012Data_pfiso_condor/Histo_AOD_18_1_jgS.root");
  //chain->Add("/eos/uscms/store/user/bhawna/ntuples/Monontuples_marc.root");
  //chain->Add("/eos/uscms/store/user/bhawna/DYJetsToLL_M-50_pfiso/Histo_AOD_209_1_KV9.root");
  //chain->Add("/uscmst1b_scratch/lpc1/lpceg/miceli/diPhoTuples11Nov2011/outputfile_dipho3535_v1_2761.root");
  //chain->Add("dcap://cmsgridftp.fnal.gov:24125/pnfs/fnal.gov/usr/cms/WAX/11/store/user/lpcgg/sushil/Summer12/MC/53X_MC/ADD//ADDmonoPhoton_MD1_d3/Ntuples_ADDmonoPhoton_MD1_d3_10_1_BzT.root");
  //chain->Add("dcap://cmsgridftp.fnal.gov:24125/pnfs/fnal.gov/usr/cms/WAX/11/store/user/weinberg/monoPhoton/ntuples/outputfile_singlePhoton_run2012B_promptReco_v1_219.root");
  ///chain->Add("dcap://cmsgridftp.fnal.gov:24125/pnfs/fnal.gov/usr/cms/WAX/11/store/user/lpcgg/askew/42Mono/AllPostTS/outputfile_V1b_16.root");
  //chain->Add("dcap://cmsgridftp.fnal.gov:24125/pnfs/fnal.gov/usr/cms/WAX/11/store/user/lpcgg/askew/42Mono/AllPostTS/outputfile_V1b4_89.root");
  //chain->Add("dcap://cmsgridftp.fnal.gov:24125/pnfs/fnal.gov/usr/cms/WAX/11/store/user/lpcgg/askew/42Mono/AllPostTS/outputfile_V1b4_78.root");
  //chain->Add("dcap://cmsgridftp.fnal.gov:24125/pnfs/fnal.gov/usr/cms/WAX/11/store/user/lpcgg/askew/42Mono/AllPostTS/outputfile_V1b4_72.root");
  //chain->Add("dcap://cmsgridftp.fnal.gov:24125/pnfs/fnal.gov/usr/cms/WAX/11/store/user/lpcgg/askew/42Mono/AllPostTS/outputfile_V1b4_73.root");
  //chain->Add("dcap://cmsgridftp.fnal.gov:24125/pnfs/fnal.gov/usr/cms/WAX/11/store/user/lpcgg/sushil/Summer11/MC/ZNuNuGa/Histo_Znunu_Gamma_1.root");
  //  chain->Add("dcap://cmsgridftp.fnal.gov:24125/pnfs/fnal.gov/usr/cms/WAX/11/store/user/sushil/Summer11/MC/W_ENu_Large/Histo_Wenu_258_1_jaN.root");
  //chain->Add("dcap://cmsgridftp.fnal.gov:24125/pnfs/fnal.gov/usr/cms/WAX/11/store/user/jdamgov/MonoPhoton/ZinvGamma130_AOD.root");

  Init(chain);
  cout<<"ADDED files:"<<endl;
  
  BookHistos(file2);

}

myEvent::~myEvent()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
   fileName->cd();
   fileName->Write();
   tree->Write();
   //weights_->Write();
   //den->Write();
   //MC_distr_->Write();
   //Data_distr_->Write();
   fileName->Close();
}

Int_t myEvent::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t myEvent::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void myEvent::Init(TChain *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   triggernames = 0;
   triggerprescales = 0;
   ifTriggerpassed = 0;
   genTauDecayMode1 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nevents", &nevents, &b_nevents);
   fChain->SetBranchAddress("run", &run, &b_RunNumber);
   fChain->SetBranchAddress("event", &event, &b_EventNumber);
   fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_LumiNumber);
   fChain->SetBranchAddress("beamCrossing", &beamCrossing, &b_BXNumber);
   fChain->SetBranchAddress("totalIntensityBeam1", &totalIntensityBeam1, &b_totalIntensityBeam1);
   fChain->SetBranchAddress("totalIntensityBeam2", &totalIntensityBeam2, &b_totalIntensityBeam2);
   fChain->SetBranchAddress("avgInsDelLumi", &avgInsDelLumi, &b_avgInsDelLumi);
   fChain->SetBranchAddress("avgInsDelLumiErr", &avgInsDelLumiErr, &b_avgInsDelLumiErr);
   fChain->SetBranchAddress("avgInsRecLumi", &avgInsRecLumi, &b_avgInsRecLumi);
   fChain->SetBranchAddress("avgInsRecLumiErr", &avgInsRecLumiErr, &b_avgInsRecLumiErr);
   fChain->SetBranchAddress("ntriggers", &ntriggers, &b_ntriggers);
   fChain->SetBranchAddress("triggernames", &triggernames, &b_triggernames);
   fChain->SetBranchAddress("triggerprescales", &triggerprescales, &b_triggerprescales);
   fChain->SetBranchAddress("ifTriggerpassed", &ifTriggerpassed, &b_ifTriggerpassed);
   fChain->SetBranchAddress("trobjpt", trobjpt, &b_trobjpt);
   fChain->SetBranchAddress("trobjeta", trobjeta, &b_trobjeta);
   fChain->SetBranchAddress("trobjphi", trobjphi, &b_trobjphi);
   fChain->SetBranchAddress("Vertex_n", &Vertex_n, &b_Vertex_n);
   fChain->SetBranchAddress("Vertex_x", Vertex_x, &b_Vertex_x);
   fChain->SetBranchAddress("Vertex_y", Vertex_y, &b_Vertex_y);
   fChain->SetBranchAddress("Vertex_z", Vertex_z, &b_Vertex_z);
   fChain->SetBranchAddress("Vertex_tracksize", Vertex_tracksize, &b_Vertex_tracksize);
   fChain->SetBranchAddress("Vertex_ndof", Vertex_ndof, &b_Vertex_ndof);
   fChain->SetBranchAddress("Vertex_chi2", Vertex_chi2, &b_Vertex_chi2);
   fChain->SetBranchAddress("Vertex_d0", Vertex_d0, &b_Vertex_d0);
   fChain->SetBranchAddress("Vertex_isFake", Vertex_isFake, &b_Vertex_isFake);
   fChain->SetBranchAddress("npuVertices", &npuVertices, &b_npuVertices);
   fChain->SetBranchAddress("ootnpuVertices", &ootnpuVertices, &b_ootnpuVertices);
   fChain->SetBranchAddress("Scraping_numOfTracks", &Scraping_numOfTracks, &b_Scraping_numOfTracks);
   fChain->SetBranchAddress("Scraping_fractionOfGoodTracks", &Scraping_fractionOfGoodTracks, &b_Scraping_fractionOfGoodTracks);
   fChain->SetBranchAddress("npuVerticesp1", &npuVerticesp1, &b_npuVerticesp1);
   fChain->SetBranchAddress("npuVerticesm1", &npuVerticesm1, &b_npuVerticesm1);
   fChain->SetBranchAddress("trueInteractions", &trueInteractions, &b_trueInteractions);
   fChain->SetBranchAddress("Track_n", &Track_n, &b_Track_n);
   fChain->SetBranchAddress("Track_px", Track_px, &b_Track_px);
   fChain->SetBranchAddress("Track_py", Track_py, &b_Track_py);
   fChain->SetBranchAddress("Track_pz", Track_pz, &b_Track_pz);
   fChain->SetBranchAddress("Track_vx", Track_vx, &b_Track_vx);
   fChain->SetBranchAddress("Track_vy", Track_vy, &b_Track_vy);
   fChain->SetBranchAddress("Track_vz", Track_vz, &b_Track_vz);
   fChain->SetBranchAddress("Track_pt", Track_pt, &b_Track_pt);
   fChain->SetBranchAddress("Track_eta", Track_eta, &b_Track_eta);
   fChain->SetBranchAddress("Track_phi", Track_phi, &b_Track_phi);
   fChain->SetBranchAddress("Jet_n", &Jet_n, &b_Jet_n);
   fChain->SetBranchAddress("Jet_px", Jet_px, &b_Jet_px);
   fChain->SetBranchAddress("Jet_py", Jet_py, &b_Jet_py);
   fChain->SetBranchAddress("Jet_E", Jet_E, &b_Jet_E);
   fChain->SetBranchAddress("Jet_pz", Jet_pz, &b_Jet_pz);
   fChain->SetBranchAddress("Jet_vx", Jet_vx, &b_Jet_vx);
   fChain->SetBranchAddress("Jet_vy", Jet_vy, &b_Jet_vy);
   fChain->SetBranchAddress("Jet_vz", Jet_vz, &b_Jet_vz);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_emEnergyFraction", Jet_emEnergyFraction, &b_Jet_emEnergyFraction);
   fChain->SetBranchAddress("Jet_energyFractionHadronic", Jet_energyFractionHadronic, &b_Jet_energyFractionHadronic);
   fChain->SetBranchAddress("Jet_hitsInN90", Jet_hitsInN90, &b_Jet_hitsInN90);
   fChain->SetBranchAddress("Jet_n90Hits", Jet_n90Hits, &b_Jet_n90Hits);
   fChain->SetBranchAddress("Jet_nTowers", Jet_nTowers, &b_Jet_nTowers);
   fChain->SetBranchAddress("Jet_fHPD", Jet_fHPD, &b_Jet_fHPD);
   fChain->SetBranchAddress("Jet_fRBX", Jet_fRBX, &b_Jet_fRBX);
   fChain->SetBranchAddress("Jet_RHF", Jet_RHF, &b_Jet_RHF);
   fChain->SetBranchAddress("Jet_jecCorr", Jet_jecCorr, &b_Jet_jecCorr);
   fChain->SetBranchAddress("ucJet_px", ucJet_px, &b_ucJet_px);
   fChain->SetBranchAddress("ucJet_py", ucJet_py, &b_ucJet_py);
   fChain->SetBranchAddress("ucJet_E", ucJet_E, &b_ucJet_E);
   fChain->SetBranchAddress("ucJet_pz", ucJet_pz, &b_ucJet_pz);
   fChain->SetBranchAddress("ucJet_pt", ucJet_pt, &b_ucJet_pt);
   fChain->SetBranchAddress("ucJet_eta", ucJet_eta, &b_ucJet_eta);
   fChain->SetBranchAddress("ucJet_phi", ucJet_phi, &b_ucJet_phi);
   fChain->SetBranchAddress("pfJet_n", &pfJet_n, &b_pfJet_n);
   fChain->SetBranchAddress("pfJet_px", pfJet_px, &b_pfJet_px);
   fChain->SetBranchAddress("pfJet_py", pfJet_py, &b_pfJet_py);
   fChain->SetBranchAddress("pfJet_E", pfJet_E, &b_pfJet_E);
   fChain->SetBranchAddress("pfJet_pz", pfJet_pz, &b_pfJet_pz);
   fChain->SetBranchAddress("pfJet_vx", pfJet_vx, &b_pfJet_vx);
   fChain->SetBranchAddress("pfJet_vy", pfJet_vy, &b_pfJet_vy);
   fChain->SetBranchAddress("pfJet_vz", pfJet_vz, &b_pfJet_vz);
   fChain->SetBranchAddress("pfJet_pt", pfJet_pt, &b_pfJet_pt);
   fChain->SetBranchAddress("pfJet_eta", pfJet_eta, &b_pfJet_eta);
   fChain->SetBranchAddress("pfJet_phi", pfJet_phi, &b_pfJet_phi);
   fChain->SetBranchAddress("pfjet_CEF", pfjet_CEF, &b_pfjet_CEF);
   fChain->SetBranchAddress("pfjet_CHF", pfjet_CHF, &b_pfjet_CHF);
   fChain->SetBranchAddress("pfjet_NEF", pfjet_NEF, &b_pfjet_NEF);
   fChain->SetBranchAddress("pfjet_NHF", pfjet_NHF, &b_pfjet_NHF);
   fChain->SetBranchAddress("pfjet_NCH", pfjet_NCH, &b_pfjet_NCH);
   fChain->SetBranchAddress("pfjet_HFHAE", pfjet_HFHAE, &b_pfjet_HFHAE);
   fChain->SetBranchAddress("pfjet_HFEME", pfjet_HFEME, &b_pfjet_HFEME);
   fChain->SetBranchAddress("pfjet_NConstituents", pfjet_NConstituents, &b_pfjet_NConstituents);
   fChain->SetBranchAddress("pfjet_Ndaughters", pfjet_Ndaughters, &b_pfjet_Ndaughters);
   fChain->SetBranchAddress("pfjet_towersArea", pfjet_towersArea, &b_pfjet_towersArea);
   fChain->SetBranchAddress("pfjet_isBasicJet", pfjet_isBasicJet, &b_pfjet_isBasicJet);
   fChain->SetBranchAddress("pfjet_n60", pfjet_n60, &b_pfjet_n60);
   fChain->SetBranchAddress("pfjet_n90", pfjet_n90, &b_pfjet_n90);
   fChain->SetBranchAddress("pfjet_phoEFrac", pfjet_phoEFrac, &b_pfjet_phoEFrac);
   fChain->SetBranchAddress("pfjet_partonFlav", pfjet_partonFlav, &b_pfjet_partonFlav);
   fChain->SetBranchAddress("pujetIdFull_mva", pujetIdFull_mva, &b_pujetIdFull_mva);
   fChain->SetBranchAddress("pujetIdSimple_mva", pujetIdSimple_mva, &b_pujetIdSimple_mva);
   fChain->SetBranchAddress("pujetIdCutBased_mva", pujetIdCutBased_mva, &b_pujetIdCutBased_mva);
   fChain->SetBranchAddress("pujetIdFull_loose", pujetIdFull_loose, &b_pujetIdFull_loose);
   fChain->SetBranchAddress("pujetIdFull_medium", pujetIdFull_medium, &b_pujetIdFull_medium);
   fChain->SetBranchAddress("pujetIdFull_tight", pujetIdFull_tight, &b_pujetIdFull_tight);
   fChain->SetBranchAddress("pujetIdSimple_loose", pujetIdSimple_loose, &b_pujetIdSimple_loose);
   fChain->SetBranchAddress("pujetIdSimple_medium", pujetIdSimple_medium, &b_pujetIdSimple_medium);
   fChain->SetBranchAddress("pujetIdSimple_tight", pujetIdSimple_tight, &b_pujetIdSimple_tight);
   fChain->SetBranchAddress("pujetIdCutBased_loose", pujetIdCutBased_loose, &b_pujetIdCutBased_loose);
   fChain->SetBranchAddress("pujetIdCutBased_medium", pujetIdCutBased_medium, &b_pujetIdCutBased_medium);
   fChain->SetBranchAddress("pujetIdCutBased_tight", pujetIdCutBased_tight, &b_pujetIdCutBased_tight);
   fChain->SetBranchAddress("pfjet_TrackCountHiEffBJetTags", pfjet_TrackCountHiEffBJetTags, &b_pfjet_TrackCountHiEffBJetTags);
   fChain->SetBranchAddress("pfjet_TrackCountHiPurBJetTags", pfjet_TrackCountHiPurBJetTags, &b_pfjet_TrackCountHiPurBJetTags);
   fChain->SetBranchAddress("pfjet_SimpleSVHiEffBJetTags", pfjet_SimpleSVHiEffBJetTags, &b_pfjet_SimpleSVHiEffBJetTags);
   fChain->SetBranchAddress("pfjet_SimpleSVHiPurBJetTags", pfjet_SimpleSVHiPurBJetTags, &b_pfjet_SimpleSVHiPurBJetTags);
   fChain->SetBranchAddress("pfJet_jecUncer", pfJet_jecUncer, &b_pfJet_jecUncer);
   fChain->SetBranchAddress("pfJet_jecCorr", pfJet_jecCorr, &b_pfJet_jecCorr);
   fChain->SetBranchAddress("ucpfJet_px", ucpfJet_px, &b_ucpfJet_px);
   fChain->SetBranchAddress("ucpfJet_py", ucpfJet_py, &b_ucpfJet_py);
   fChain->SetBranchAddress("ucpfJet_E", ucpfJet_E, &b_ucpfJet_E);
   fChain->SetBranchAddress("ucpfJet_pz", ucpfJet_pz, &b_ucpfJet_pz);
   fChain->SetBranchAddress("ucpfJet_pt", ucpfJet_pt, &b_ucpfJet_pt);
   fChain->SetBranchAddress("ucpfJet_eta", ucpfJet_eta, &b_ucpfJet_eta);
   fChain->SetBranchAddress("ucpfJet_phi", ucpfJet_phi, &b_ucpfJet_phi);
   /*fChain->SetBranchAddress("genJet_n", &genJet_n, &b_genJet_n);
   fChain->SetBranchAddress("genJet_px", genJet_px, &b_genJet_px);
   fChain->SetBranchAddress("genJet_py", genJet_py, &b_genJet_py);
   fChain->SetBranchAddress("genJet_E", genJet_E, &b_genJet_E);
   fChain->SetBranchAddress("genJet_pz", genJet_pz, &b_genJet_pz);
   fChain->SetBranchAddress("genJet_pt", genJet_pt, &b_genJet_pt);
   fChain->SetBranchAddress("genJet_eta", genJet_eta, &b_genJet_eta);
   fChain->SetBranchAddress("genJet_phi", genJet_phi, &b_genJet_phi);*/
   fChain->SetBranchAddress("Electron_n", &Electron_n, &b_Electron_n);
   fChain->SetBranchAddress("Electron_px", Electron_px, &b_Electron_px);
   fChain->SetBranchAddress("Electron_py", Electron_py, &b_Electron_py);
   fChain->SetBranchAddress("Electron_pz", Electron_pz, &b_Electron_pz);
   fChain->SetBranchAddress("Electron_vx", Electron_vx, &b_Electron_vx);
   fChain->SetBranchAddress("Electron_vy", Electron_vy, &b_Electron_vy);
   fChain->SetBranchAddress("Electron_vz", Electron_vz, &b_Electron_vz);
   fChain->SetBranchAddress("Electron_pt", Electron_pt, &b_Electron_pt);
   fChain->SetBranchAddress("Electron_eta", Electron_eta, &b_Electron_eta);
   fChain->SetBranchAddress("Electron_phi", Electron_phi, &b_Electron_phi);
   fChain->SetBranchAddress("Electron_energy", Electron_energy, &b_Electron_energy);
   fChain->SetBranchAddress("Electron_charge", Electron_charge, &b_Electron_charge);
   fChain->SetBranchAddress("Electron_trkIso", Electron_trkIso, &b_Electron_trkIso);
   fChain->SetBranchAddress("Electron_ecalIso", Electron_ecalIso, &b_Electron_ecalIso);
   fChain->SetBranchAddress("Electron_hcalIso", Electron_hcalIso, &b_Electron_hcalIso);
   fChain->SetBranchAddress("Electron_SigmaIetaIeta", Electron_SigmaIetaIeta, &b_Electron_SigmaIetaIeta);
   fChain->SetBranchAddress("Electron_dEtaIn", Electron_dEtaIn, &b_Electron_dEtaIn);
   fChain->SetBranchAddress("Electron_dPhiIn", Electron_dPhiIn, &b_Electron_dPhiIn);
   fChain->SetBranchAddress("Electron_HoE", Electron_HoE, &b_Electron_HoE);
   fChain->SetBranchAddress("Electron_sc_energy", Electron_sc_energy, &b_Electron_sc_energy);
   fChain->SetBranchAddress("Electron_sc_eta", Electron_sc_eta, &b_Electron_sc_eta);
   fChain->SetBranchAddress("Electron_sc_phi", Electron_sc_phi, &b_Electron_sc_phi);
   fChain->SetBranchAddress("Muon_n", &Muon_n, &b_Muon_n);
   fChain->SetBranchAddress("Muon_px", Muon_px, &b_Muon_px);
   fChain->SetBranchAddress("Muon_py", Muon_py, &b_Muon_py);
   fChain->SetBranchAddress("Muon_pz", Muon_pz, &b_Muon_pz);
   fChain->SetBranchAddress("Muon_vx", Muon_vx, &b_Muon_vx);
   fChain->SetBranchAddress("Muon_vy", Muon_vy, &b_Muon_vy);
   fChain->SetBranchAddress("Muon_vz", Muon_vz, &b_Muon_vz);
   fChain->SetBranchAddress("Muon_pt", Muon_pt, &b_Muon_pt);
   fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("Muon_energy", Muon_energy, &b_Muon_energy);
   fChain->SetBranchAddress("Muon_charge", Muon_charge, &b_Muon_charge);
   fChain->SetBranchAddress("Muon_isGlobalMuon", Muon_isGlobalMuon, &b_Muon_isGlobalMuon);
   fChain->SetBranchAddress("Muon_isTrackerMuon", Muon_isTrackerMuon, &b_Muon_isTrackerMuon);
   fChain->SetBranchAddress("Muon_isStandAloneMuon", Muon_isStandAloneMuon, &b_Muon_isStandAloneMuon);
   fChain->SetBranchAddress("Muon_InnerTrack_isNonnull", Muon_InnerTrack_isNonnull, &b_Muon_InnerTrack_isNonnull);
   fChain->SetBranchAddress("Muon_OuterTrack_isNonnull", Muon_OuterTrack_isNonnull, &b_Muon_OuterTrack_isNonnull);
   fChain->SetBranchAddress("Muon_OuterTrack_InnerPoint_x", Muon_OuterTrack_InnerPoint_x, &b_Muon_OuterTrack_InnerPoint_x);
   fChain->SetBranchAddress("Muon_OuterTrack_InnerPoint_y", Muon_OuterTrack_InnerPoint_y, &b_Muon_OuterTrack_InnerPoint_y);
   fChain->SetBranchAddress("Muon_OuterTrack_InnerPoint_z", Muon_OuterTrack_InnerPoint_z, &b_Muon_OuterTrack_InnerPoint_z);
   fChain->SetBranchAddress("Muon_OuterTrack_InnerPoint_px", Muon_OuterTrack_InnerPoint_px, &b_Muon_OuterTrack_InnerPoint_px);
   fChain->SetBranchAddress("Muon_OuterTrack_InnerPoint_py", Muon_OuterTrack_InnerPoint_py, &b_Muon_OuterTrack_InnerPoint_py);
   fChain->SetBranchAddress("Muon_OuterTrack_InnerPoint_pz", Muon_OuterTrack_InnerPoint_pz, &b_Muon_OuterTrack_InnerPoint_pz);
   fChain->SetBranchAddress("Muon_OuterTrack_OuterPoint_x", Muon_OuterTrack_OuterPoint_x, &b_Muon_OuterTrack_OuterPoint_x);
   fChain->SetBranchAddress("Muon_OuterTrack_OuterPoint_y", Muon_OuterTrack_OuterPoint_y, &b_Muon_OuterTrack_OuterPoint_y);
   fChain->SetBranchAddress("Muon_OuterTrack_OuterPoint_z", Muon_OuterTrack_OuterPoint_z, &b_Muon_OuterTrack_OuterPoint_z);
   fChain->SetBranchAddress("Muon_OuterTrack_OuterPoint_px", Muon_OuterTrack_OuterPoint_px, &b_Muon_OuterTrack_OuterPoint_px);
   fChain->SetBranchAddress("Muon_OuterTrack_OuterPoint_py", Muon_OuterTrack_OuterPoint_py, &b_Muon_OuterTrack_OuterPoint_py);
   fChain->SetBranchAddress("Muon_OuterTrack_OuterPoint_pz", Muon_OuterTrack_OuterPoint_pz, &b_Muon_OuterTrack_OuterPoint_pz);
   fChain->SetBranchAddress("Muon_InnerTrack_InnerPoint_x", Muon_InnerTrack_InnerPoint_x, &b_Muon_InnerTrack_InnerPoint_x);
   fChain->SetBranchAddress("Muon_InnerTrack_InnerPoint_y", Muon_InnerTrack_InnerPoint_y, &b_Muon_InnerTrack_InnerPoint_y);
   fChain->SetBranchAddress("Muon_InnerTrack_InnerPoint_z", Muon_InnerTrack_InnerPoint_z, &b_Muon_InnerTrack_InnerPoint_z);
   fChain->SetBranchAddress("Muon_InnerTrack_InnerPoint_px", Muon_InnerTrack_InnerPoint_px, &b_Muon_InnerTrack_InnerPoint_px);
   fChain->SetBranchAddress("Muon_InnerTrack_InnerPoint_py", Muon_InnerTrack_InnerPoint_py, &b_Muon_InnerTrack_InnerPoint_py);
   fChain->SetBranchAddress("Muon_InnerTrack_InnerPoint_pz", Muon_InnerTrack_InnerPoint_pz, &b_Muon_InnerTrack_InnerPoint_pz);
   fChain->SetBranchAddress("Muon_InnerTrack_OuterPoint_x", Muon_InnerTrack_OuterPoint_x, &b_Muon_InnerTrack_OuterPoint_x);
   fChain->SetBranchAddress("Muon_InnerTrack_OuterPoint_y", Muon_InnerTrack_OuterPoint_y, &b_Muon_InnerTrack_OuterPoint_y);
   fChain->SetBranchAddress("Muon_InnerTrack_OuterPoint_z", Muon_InnerTrack_OuterPoint_z, &b_Muon_InnerTrack_OuterPoint_z);
   fChain->SetBranchAddress("Muon_InnerTrack_OuterPoint_px", Muon_InnerTrack_OuterPoint_px, &b_Muon_InnerTrack_OuterPoint_px);
   fChain->SetBranchAddress("Muon_InnerTrack_OuterPoint_py", Muon_InnerTrack_OuterPoint_py, &b_Muon_InnerTrack_OuterPoint_py);
   fChain->SetBranchAddress("Muon_InnerTrack_OuterPoint_pz", Muon_InnerTrack_OuterPoint_pz, &b_Muon_InnerTrack_OuterPoint_pz);
   fChain->SetBranchAddress("Muon_OuterPoint_x", Muon_OuterPoint_x, &b_Muon_OuterPoint_x);
   fChain->SetBranchAddress("Muon_OuterPoint_y", Muon_OuterPoint_y, &b_Muon_OuterPoint_y);
   fChain->SetBranchAddress("Muon_OuterPoint_z", Muon_OuterPoint_z, &b_Muon_OuterPoint_z);
   fChain->SetBranchAddress("Muon_InnerPoint_x", Muon_InnerPoint_x, &b_Muon_InnerPoint_x);
   fChain->SetBranchAddress("Muon_InnerPoint_y", Muon_InnerPoint_y, &b_Muon_InnerPoint_y);
   fChain->SetBranchAddress("Muon_InnerPoint_z", Muon_InnerPoint_z, &b_Muon_InnerPoint_z);
   fChain->SetBranchAddress("Muon_trackIso", Muon_trackIso, &b_Muon_trackIso);
   fChain->SetBranchAddress("Muon_ecalIso", Muon_ecalIso, &b_Muon_ecalIso);
   fChain->SetBranchAddress("Muon_hcalIso", Muon_hcalIso, &b_Muon_hcalIso);
   fChain->SetBranchAddress("Muon_relIso", Muon_relIso, &b_Muon_relIso);
   fChain->SetBranchAddress("Muon_normChi2",Muon_normChi2, &b_Muon_normChi2);
   fChain->SetBranchAddress("Muon_validHits",Muon_validHits, &b_Muon_validHits);
   fChain->SetBranchAddress("Muon_numberOfMatches",Muon_numberOfMatches, &b_Muon_numberOfMatches);
   fChain->SetBranchAddress("Muon_tkHits",Muon_tkHits, &b_Muon_tkHits);
   fChain->SetBranchAddress("Muon_pixHits",Muon_pixHits, &b_Muon_pixHits);

   fChain->SetBranchAddress("CosmicMuon_n", &CosmicMuon_n, &b_CosmicMuon_n);
   fChain->SetBranchAddress("CosmicMuon_px", CosmicMuon_px, &b_CosmicMuon_px);
   fChain->SetBranchAddress("CosmicMuon_py", CosmicMuon_py, &b_CosmicMuon_py);
   fChain->SetBranchAddress("CosmicMuon_pz", CosmicMuon_pz, &b_CosmicMuon_pz);
   fChain->SetBranchAddress("CosmicMuon_pt", CosmicMuon_pt, &b_CosmicMuon_pt);
   fChain->SetBranchAddress("CosmicMuon_eta", CosmicMuon_eta, &b_CosmicMuon_eta);
   fChain->SetBranchAddress("CosmicMuon_phi", CosmicMuon_phi, &b_CosmicMuon_phi);
   fChain->SetBranchAddress("CosmicMuon_energy", CosmicMuon_energy, &b_CosmicMuon_energy);
   fChain->SetBranchAddress("CosmicMuon_charge", CosmicMuon_charge, &b_CosmicMuon_charge);
   fChain->SetBranchAddress("CosmicMuon_isGlobalMuon", CosmicMuon_isGlobalMuon, &b_CosmicMuon_isGlobalMuon);
   fChain->SetBranchAddress("CosmicMuon_isTrackerMuon", CosmicMuon_isTrackerMuon, &b_CosmicMuon_isTrackerMuon);
   fChain->SetBranchAddress("CosmicMuon_isStandAloneMuon", CosmicMuon_isStandAloneMuon, &b_CosmicMuon_isStandAloneMuon);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_isNonnull", CosmicMuon_InnerTrack_isNonnull, &b_CosmicMuon_InnerTrack_isNonnull);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_isNonnull", CosmicMuon_OuterTrack_isNonnull, &b_CosmicMuon_OuterTrack_isNonnull);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_InnerPoint_x", CosmicMuon_OuterTrack_InnerPoint_x, &b_CosmicMuon_OuterTrack_InnerPoint_x);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_InnerPoint_y", CosmicMuon_OuterTrack_InnerPoint_y, &b_CosmicMuon_OuterTrack_InnerPoint_y);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_InnerPoint_z", CosmicMuon_OuterTrack_InnerPoint_z, &b_CosmicMuon_OuterTrack_InnerPoint_z);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_InnerPoint_px", CosmicMuon_OuterTrack_InnerPoint_px, &b_CosmicMuon_OuterTrack_InnerPoint_px);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_InnerPoint_py", CosmicMuon_OuterTrack_InnerPoint_py, &b_CosmicMuon_OuterTrack_InnerPoint_py);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_InnerPoint_pz", CosmicMuon_OuterTrack_InnerPoint_pz, &b_CosmicMuon_OuterTrack_InnerPoint_pz);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_OuterPoint_x", CosmicMuon_OuterTrack_OuterPoint_x, &b_CosmicMuon_OuterTrack_OuterPoint_x);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_OuterPoint_y", CosmicMuon_OuterTrack_OuterPoint_y, &b_CosmicMuon_OuterTrack_OuterPoint_y);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_OuterPoint_z", CosmicMuon_OuterTrack_OuterPoint_z, &b_CosmicMuon_OuterTrack_OuterPoint_z);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_OuterPoint_px", CosmicMuon_OuterTrack_OuterPoint_px, &b_CosmicMuon_OuterTrack_OuterPoint_px);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_OuterPoint_py", CosmicMuon_OuterTrack_OuterPoint_py, &b_CosmicMuon_OuterTrack_OuterPoint_py);
   fChain->SetBranchAddress("CosmicMuon_OuterTrack_OuterPoint_pz", CosmicMuon_OuterTrack_OuterPoint_pz, &b_CosmicMuon_OuterTrack_OuterPoint_pz);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_InnerPoint_x", CosmicMuon_InnerTrack_InnerPoint_x, &b_CosmicMuon_InnerTrack_InnerPoint_x);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_InnerPoint_y", CosmicMuon_InnerTrack_InnerPoint_y, &b_CosmicMuon_InnerTrack_InnerPoint_y);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_InnerPoint_z", CosmicMuon_InnerTrack_InnerPoint_z, &b_CosmicMuon_InnerTrack_InnerPoint_z);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_InnerPoint_px", CosmicMuon_InnerTrack_InnerPoint_px, &b_CosmicMuon_InnerTrack_InnerPoint_px);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_InnerPoint_py", CosmicMuon_InnerTrack_InnerPoint_py, &b_CosmicMuon_InnerTrack_InnerPoint_py);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_InnerPoint_pz", CosmicMuon_InnerTrack_InnerPoint_pz, &b_CosmicMuon_InnerTrack_InnerPoint_pz);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_OuterPoint_x", CosmicMuon_InnerTrack_OuterPoint_x, &b_CosmicMuon_InnerTrack_OuterPoint_x);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_OuterPoint_y", CosmicMuon_InnerTrack_OuterPoint_y, &b_CosmicMuon_InnerTrack_OuterPoint_y);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_OuterPoint_z", CosmicMuon_InnerTrack_OuterPoint_z, &b_CosmicMuon_InnerTrack_OuterPoint_z);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_OuterPoint_px", CosmicMuon_InnerTrack_OuterPoint_px, &b_CosmicMuon_InnerTrack_OuterPoint_px);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_OuterPoint_py", CosmicMuon_InnerTrack_OuterPoint_py, &b_CosmicMuon_InnerTrack_OuterPoint_py);
   fChain->SetBranchAddress("CosmicMuon_InnerTrack_OuterPoint_pz", CosmicMuon_InnerTrack_OuterPoint_pz, &b_CosmicMuon_InnerTrack_OuterPoint_pz);
   fChain->SetBranchAddress("CosmicMuon_OuterPoint_x", CosmicMuon_OuterPoint_x, &b_CosmicMuon_OuterPoint_x);
   fChain->SetBranchAddress("CosmicMuon_OuterPoint_y", CosmicMuon_OuterPoint_y, &b_CosmicMuon_OuterPoint_y);
   fChain->SetBranchAddress("CosmicMuon_OuterPoint_z", CosmicMuon_OuterPoint_z, &b_CosmicMuon_OuterPoint_z);
   fChain->SetBranchAddress("Tau_n", &Tau_n, &b_Tau_n);
   fChain->SetBranchAddress("Tau_px", Tau_px, &b_Tau_px);
   fChain->SetBranchAddress("Tau_py", Tau_py, &b_Tau_py);
   fChain->SetBranchAddress("Tau_pz", Tau_pz, &b_Tau_pz);
   fChain->SetBranchAddress("Tau_vx", Tau_vx, &b_Tau_vx);
   fChain->SetBranchAddress("Tau_vy", Tau_vy, &b_Tau_vy);
   fChain->SetBranchAddress("Tau_vz", Tau_vz, &b_Tau_vz);
   fChain->SetBranchAddress("Tau_pt", Tau_pt, &b_Tau_pt);
   fChain->SetBranchAddress("Tau_eta", Tau_eta, &b_Tau_eta);
   fChain->SetBranchAddress("Tau_phi", Tau_phi, &b_Tau_phi);
   fChain->SetBranchAddress("Tau_energy", Tau_energy, &b_Tau_energy);
   /*fChain->SetBranchAddress("Tau_charge", Tau_charge, &b_Tau_charge);
   fChain->SetBranchAddress("Tau_DeltaBeta", Tau_DeltaBeta, &b_Tau_DeltaBeta);
   fChain->SetBranchAddress("Tau_tightDeltaBeta", Tau_tightDeltaBeta, &b_Tau_tightDeltaBeta);
   fChain->SetBranchAddress("Tau_DecayMode", Tau_DecayMode, &b_Tau_DecayMode);
   fChain->SetBranchAddress("Tau_AgainstEle", Tau_AgainstEle, &b_Tau_AgainstEle);
   fChain->SetBranchAddress("Tau_AgainstMuon", Tau_AgainstMuon, &b_Tau_AgainstMuon);
   fChain->SetBranchAddress("Tau_1ProngPass", Tau_1ProngPass, &b_Tau_1ProngPass);
   fChain->SetBranchAddress("Tau_2ProngPass", Tau_2ProngPass, &b_Tau_2ProngPass);
   fChain->SetBranchAddress("Tau_3ProngPass", Tau_3ProngPass, &b_Tau_3ProngPass);
   fChain->SetBranchAddress("genTauDecayMode1", &genTauDecayMode1, &b_genTauDecayMode1);*/
   fChain->SetBranchAddress("oneProng0Pi0", oneProng0Pi0, &b_oneProng0Pi0);
   fChain->SetBranchAddress("oneProng1Pi0", oneProng1Pi0, &b_oneProng1Pi0);
   fChain->SetBranchAddress("oneProng2Pi0", oneProng2Pi0, &b_oneProng2Pi0);
   fChain->SetBranchAddress("threeProng0Pi0", threeProng0Pi0, &b_threeProng0Pi0);
   fChain->SetBranchAddress("threeProng1Pi0", threeProng1Pi0, &b_threeProng1Pi0);
   fChain->SetBranchAddress("tauelectron", tauelectron, &b_tauelectron);
   fChain->SetBranchAddress("taumuon", taumuon, &b_taumuon);
   fChain->SetBranchAddress("nthreeProng1Pi0", &nthreeProng1Pi0, &b_nthreeProng1Pi0);
   fChain->SetBranchAddress("ntauelectron", &ntauelectron, &b_ntauelectron);
   fChain->SetBranchAddress("ntaumuon", &ntaumuon, &b_ntaumuon);
   fChain->SetBranchAddress("genHadTauPt", genHadTauPt, &b_genHadTauPt);
   fChain->SetBranchAddress("genHadTauEta", genHadTauEta, &b_genHadTauEta);
   fChain->SetBranchAddress("genHadTauPhi", genHadTauPhi, &b_genHadTauPhi);
   fChain->SetBranchAddress("nPions", nPions, &b_nPions);
   fChain->SetBranchAddress("PionPdgId", PionPdgId, &b_PionPdgId);
   fChain->SetBranchAddress("PionPt", PionPt, &b_PionPt);
   fChain->SetBranchAddress("PionEta", PionEta, &b_PionEta);
   fChain->SetBranchAddress("PionPhi", PionPhi, &b_PionPhi);
   fChain->SetBranchAddress("nPi0", nPi0, &b_nPi0);
   fChain->SetBranchAddress("Pi0PdgId", Pi0PdgId, &b_Pi0PdgId);
   fChain->SetBranchAddress("Pi0Pt", Pi0Pt, &b_Pi0Pt);
   fChain->SetBranchAddress("Pi0Eta", Pi0Eta, &b_Pi0Eta);
   fChain->SetBranchAddress("Pi0Phi", Pi0Phi, &b_Pi0Phi);
   fChain->SetBranchAddress("nPhotons", nPhotons, &b_nPhotons);
   fChain->SetBranchAddress("PhotonPt", PhotonPt, &b_PhotonPt);
   fChain->SetBranchAddress("PhotonEta", PhotonEta, &b_PhotonEta);
   fChain->SetBranchAddress("PhotonPhi", PhotonPhi, &b_PhotonPhi);
   fChain->SetBranchAddress("PhotonPdgId", PhotonPdgId, &b_PhotonPdgId);
   fChain->SetBranchAddress("gen_photonpt", gen_photonpt, &b_gen_photonpt);
   fChain->SetBranchAddress("gen_photonMotherID", gen_photonMotherID, &b_gen_photonMotherID);
   fChain->SetBranchAddress("gen_photonGrandmotherID", gen_photonGrandmotherID, &b_gen_photonGrandmotherID);
   fChain->SetBranchAddress("is_diphoton_event", &is_diphoton_event, &b_is_diphoton_event);
   fChain->SetBranchAddress("gen_pthat", &gen_pthat, &b_gen_pthat);
   fChain->SetBranchAddress("ngenphotons", &ngenphotons, &b_ngenphotons);

   fChain->SetBranchAddress("gen_photoneta", gen_photoneta, &b_gen_photoneta);
   fChain->SetBranchAddress("gen_photonphi", gen_photonphi, &b_gen_photonphi);
   
   fChain->SetBranchAddress("gen_photonpx", gen_photonpx, &b_gen_photonpx);
   fChain->SetBranchAddress("gen_photonpy", gen_photonpy, &b_gen_photonpy);
   fChain->SetBranchAddress("gen_photonpz", gen_photonpz, &b_gen_photonpz);
   fChain->SetBranchAddress("gen_photonE", gen_photonE, &b_gen_photonE);
   fChain->SetBranchAddress("gen_photonstatus", gen_photonstatus, &b_gen_photonstatus);

   fChain->SetBranchAddress("gen_photonMotherPt", gen_photonMotherPt, &b_gen_photonMotherPt);
   fChain->SetBranchAddress("gen_photonMotherEta", gen_photonMotherEta, &b_gen_photonMotherEta);
   fChain->SetBranchAddress("gen_photonMotherPhi", gen_photonMotherPhi, &b_gen_photonMotherPhi);
   fChain->SetBranchAddress("gen_photonMotherStatus", gen_photonMotherStatus, &b_gen_photonMotherStatus);

   fChain->SetBranchAddress("gen_photonGrandmotherPt", gen_photonGrandmotherPt, &b_gen_photonGrandmotherPt);
   fChain->SetBranchAddress("gen_photonGrandmotherEta", gen_photonGrandmotherEta, &b_gen_photonGrandmotherEta);
   fChain->SetBranchAddress("gen_photonGrandmotherPhi", gen_photonGrandmotherPhi, &b_gen_photonGrandmotherPhi);
   fChain->SetBranchAddress("gen_photonGrandmotherStatus", gen_photonGrandmotherStatus, &b_gen_photonGrandmotherStatus);
   fChain->SetBranchAddress("nhardphotons", &nhardphotons, &b_nhardphotons);
   fChain->SetBranchAddress("gen_hardphotonpt", &gen_hardphotonpt, &b_gen_hardphotonpt);
   fChain->SetBranchAddress("gen_hardphotoneta", &gen_hardphotoneta, &b_gen_hardphotoneta);
   fChain->SetBranchAddress("gen_hardphotonphi", &gen_hardphotonphi, &b_gen_hardphotonphi);
   fChain->SetBranchAddress("gen_hardphotonpx", &gen_hardphotonpx, &b_gen_hardphotonpx);
   fChain->SetBranchAddress("gen_hardphotonpy", &gen_hardphotonpy, &b_gen_hardphotonpy);
   fChain->SetBranchAddress("gen_hardphotonpz", &gen_hardphotonpz, &b_gen_hardphotonpz);
   fChain->SetBranchAddress("gen_hardphotonE", &gen_hardphotonE, &b_gen_hardphotonE);
   fChain->SetBranchAddress("gen_gravitonpt", &gen_gravitonpt, &b_gen_gravitonpt);
   fChain->SetBranchAddress("gen_gravitoneta", &gen_gravitoneta, &b_gen_gravitoneta);
   fChain->SetBranchAddress("gen_gravitonphi", &gen_gravitonphi, &b_gen_gravitonphi);
   fChain->SetBranchAddress("gen_gravitonpx", &gen_gravitonpx, &b_gen_gravitonpx);
   fChain->SetBranchAddress("gen_gravitonpy", &gen_gravitonpy, &b_gen_gravitonpy);
   fChain->SetBranchAddress("gen_gravitonpz", &gen_gravitonpz, &b_gen_gravitonpz);
   fChain->SetBranchAddress("gen_gravitonE", &gen_gravitonE, &b_gen_gravitonE);
   
   fChain->SetBranchAddress("gen_Wdaughterpt", gen_Wdaughterpt, &b_gen_Wdaughter_pt);
   fChain->SetBranchAddress("gen_Wdaughtereta", gen_Wdaughtereta, &b_gen_Wdaughter_eta);
   fChain->SetBranchAddress("gen_Wdaughterphi", gen_Wdaughterphi, &b_gen_Wdaughter_phi);
   fChain->SetBranchAddress("gen_Wdaughterpx", gen_Wdaughterpx, &b_gen_Wdaughter_px);
   fChain->SetBranchAddress("gen_Wdaughterpy", gen_Wdaughterpy, &b_gen_Wdaughter_py);
   fChain->SetBranchAddress("gen_Wdaughterpz", gen_Wdaughterpz, &b_gen_Wdaughter_pz);
   fChain->SetBranchAddress("gen_WdaughterE", gen_WdaughterE, &b_gen_Wdaughter_E);
   fChain->SetBranchAddress("gen_Wdaughter_charge", gen_Wdaughter_charge, &b_gen_Wdaughter_charge);
   fChain->SetBranchAddress("gen_WdaughterID", gen_WdaughterID, &b_gen_Wdaughter_ID);
   fChain->SetBranchAddress("gen_Wbosonpt", &gen_Wbosonpt, &b_gen_Wboson_pt);
   fChain->SetBranchAddress("gen_Wbosoneta", &gen_Wbosoneta, &b_gen_Wboson_eta);
   fChain->SetBranchAddress("gen_Wbosonphi", &gen_Wbosonphi, &b_gen_Wboson_phi);
   fChain->SetBranchAddress("gen_Wbosonpx", &gen_Wbosonpx, &b_gen_Wboson_px);
   fChain->SetBranchAddress("gen_Wbosonpy", &gen_Wbosonpy, &b_gen_Wboson_py);
   fChain->SetBranchAddress("gen_Wbosonpz", &gen_Wbosonpz, &b_gen_Wboson_pz);
   fChain->SetBranchAddress("gen_WbosonE", &gen_WbosonE, &b_gen_Wboson_E);
   fChain->SetBranchAddress("gen_Wbosoncharge", &gen_Wbosoncharge, &b_gen_Wboson_charge);
   fChain->SetBranchAddress("gen_WbosonID", &gen_WbosonID, &b_gen_Wboson_ID);
   fChain->SetBranchAddress("gen_Zdaughterpt", gen_Zdaughterpt, &b_gen_Zdaughter_pt);
   fChain->SetBranchAddress("gen_Zdaughtereta", gen_Zdaughtereta, &b_gen_Zdaughter_eta);
   fChain->SetBranchAddress("gen_Zdaughterphi", gen_Zdaughterphi, &b_gen_Zdaughter_phi);
   fChain->SetBranchAddress("gen_Zdaughterpx", gen_Zdaughterpx, &b_gen_Zdaughter_px);
   fChain->SetBranchAddress("gen_Zdaughterpy", gen_Zdaughterpy, &b_gen_Zdaughter_py);
   fChain->SetBranchAddress("gen_Zdaughterpz", gen_Zdaughterpz, &b_gen_Zdaughter_pz);
   fChain->SetBranchAddress("gen_ZdaughterE", gen_ZdaughterE, &b_gen_Zdaughter_E);
   fChain->SetBranchAddress("gen_Zdaughter_charge", gen_Zdaughter_charge, &b_gen_Zdaughter_charge);
   fChain->SetBranchAddress("gen_ZdaughterID", gen_ZdaughterID, &b_gen_Zdaughter_ID);
   fChain->SetBranchAddress("gen_Zbosonpt", &gen_Zbosonpt, &b_gen_Zboson_pt);
   fChain->SetBranchAddress("gen_Zbosoneta", &gen_Zbosoneta, &b_gen_Zboson_eta);
   fChain->SetBranchAddress("gen_Zbosonphi", &gen_Zbosonphi, &b_gen_Zboson_phi);
   fChain->SetBranchAddress("gen_Zbosonpx", &gen_Zbosonpx, &b_gen_Zboson_px);
   fChain->SetBranchAddress("gen_Zbosonpy", &gen_Zbosonpy, &b_gen_Zboson_py);
   fChain->SetBranchAddress("gen_Zbosonpz", &gen_Zbosonpz, &b_gen_Zboson_pz);
   fChain->SetBranchAddress("gen_ZbosonE", &gen_ZbosonE, &b_gen_Zboson_E);
   fChain->SetBranchAddress("is_signal_event", &is_signal_event, &b_is_signal_event);
   fChain->SetBranchAddress("is_Z_event", &is_Z_event, &b_is_Z_event);
   fChain->SetBranchAddress("is_W_event", &is_W_event, &b_is_W_event);
   fChain->SetBranchAddress("is_Znunu_event", &is_Znunu_event, &b_is_Znunu_event);
   fChain->SetBranchAddress("is_Zelec_event", &is_Zelec_event, &b_is_Zelec_event);
   fChain->SetBranchAddress("is_Zmu_event", &is_Zmu_event, &b_is_Zmu_event);
   fChain->SetBranchAddress("is_Ztau_event", &is_Ztau_event, &b_is_Ztau_event);
   fChain->SetBranchAddress("is_Welec_event", &is_Welec_event, &b_is_Welec_event);
   fChain->SetBranchAddress("is_Wmu_event", &is_Wmu_event, &b_is_Wmu_event);
   fChain->SetBranchAddress("is_Wtau_event", &is_Wtau_event, &b_is_Wtau_event);
   fChain->SetBranchAddress("is_SingleHardPhoton_event", &is_SingleHardPhoton_event, &b_is_SingleHardPhoton_event);
   fChain->SetBranchAddress("is_isr_photon_event", &is_isr_photon_event, &b_is_isr_photon_event);
   fChain->SetBranchAddress("n_signal_events", &n_signal_events, &b_n_signal_events);
   fChain->SetBranchAddress("n_Z_events", &n_Z_events, &b_n_Z_events);
   fChain->SetBranchAddress("n_W_events", &n_W_events, &b_n_W_events);
   fChain->SetBranchAddress("n_Znunu_events", &n_Znunu_events, &b_n_Znunu_events);
   fChain->SetBranchAddress("n_Zelec_events", &n_Zelec_events, &b_n_Zelec_events);
   fChain->SetBranchAddress("n_Zmu_events", &n_Zmu_events, &b_n_Zmu_events);
   fChain->SetBranchAddress("n_Ztau_events", &n_Ztau_events, &b_n_Ztau_events);
   fChain->SetBranchAddress("n_Welec_events", &n_Welec_events, &b_n_Welec_events);
   fChain->SetBranchAddress("n_Wmu_events", &n_Wmu_events, &b_n_Wmu_events);
   fChain->SetBranchAddress("n_Wtau_events", &n_Wtau_events, &b_n_Wtau_events);
   fChain->SetBranchAddress("n_SingleHardPhoton_events", &n_SingleHardPhoton_events, &b_n_SingleHardPhoton_events);
   fChain->SetBranchAddress("n_diphoton_events", &n_diphoton_events, &b_n_diphoton_events);
   fChain->SetBranchAddress("gen_MuonID", gen_MuonID, &b_gen_Muon_ID);
   fChain->SetBranchAddress("gen_MuonStatus", gen_MuonStatus, &b_gen_Muon_Status);
   fChain->SetBranchAddress("gen_MuonPt", gen_MuonPt, &b_gen_Muon_Pt);
   fChain->SetBranchAddress("gen_MuonDaughterpt", gen_MuonDaughterpt, &b_gen_MuonDaughter_pt);
   fChain->SetBranchAddress("gen_MuonDaughtereta", gen_MuonDaughtereta, &b_gen_MuonDaughter_eta);
   fChain->SetBranchAddress("gen_MuonDaughterphi", gen_MuonDaughterphi, &b_gen_MuonDaughter_phi);
   fChain->SetBranchAddress("gen_MuonDaughterpx", gen_MuonDaughterpx, &b_gen_MuonDaughter_px);
   fChain->SetBranchAddress("gen_MuonDaughterpy", gen_MuonDaughterpy, &b_gen_MuonDaughter_py);
   fChain->SetBranchAddress("gen_MuonDaughterpz", gen_MuonDaughterpz, &b_gen_MuonDaughter_pz);
   fChain->SetBranchAddress("gen_MuonDaughterE", gen_MuonDaughterE, &b_gen_MuonDaughter_E);
   fChain->SetBranchAddress("gen_MuonDaughterCharge", gen_MuonDaughterCharge, &b_gen_MuonDaughter_charge);
   fChain->SetBranchAddress("gen_MuonDaughterStatus", gen_MuonDaughterStatus, &b_gen_MuonDaughter_status);
   fChain->SetBranchAddress("gen_MuonDaughterID", gen_MuonDaughterID, &b_gen_MuonDaughter_ID);
   fChain->SetBranchAddress("gen_tauID", gen_tauID, &b_gen_tau_ID);
   fChain->SetBranchAddress("gen_tauStatus", gen_tauStatus, &b_gen_tau_Status);
   fChain->SetBranchAddress("gen_tauPt", gen_tauPt, &b_gen_tau_Pt);
   fChain->SetBranchAddress("gen_tauDaughterpt", gen_tauDaughterpt, &b_gen_tauDaughter_pt);
   fChain->SetBranchAddress("gen_tauDaughtereta", gen_tauDaughtereta, &b_gen_tauDaughter_eta);
   fChain->SetBranchAddress("gen_tauDaughterphi", gen_tauDaughterphi, &b_gen_tauDaughter_phi);
   fChain->SetBranchAddress("gen_tauDaughterpx", gen_tauDaughterpx, &b_gen_tauDaughter_px);
   fChain->SetBranchAddress("gen_tauDaughterpy", gen_tauDaughterpy, &b_gen_tauDaughter_py);
   fChain->SetBranchAddress("gen_tauDaughterpz", gen_tauDaughterpz, &b_gen_tauDaughter_pz);
   fChain->SetBranchAddress("gen_tauDaughterE", gen_tauDaughterE, &b_gen_tauDaughter_E);
   fChain->SetBranchAddress("gen_tauDaughterCharge", gen_tauDaughterCharge, &b_gen_tauDaughter_charge);
   fChain->SetBranchAddress("gen_tauDaughterStatus", gen_tauDaughterStatus, &b_gen_tauDaughter_status);
   fChain->SetBranchAddress("gen_tauDaughterID", gen_tauDaughterID, &b_gen_tauDaughter_ID);
   fChain->SetBranchAddress("Scraping_isScrapingEvent", &Scraping_isScrapingEvent, &b_Scraping_isScrapingEvent);
   fChain->SetBranchAddress("Photon_n", &Photon_n, &b_Photon_n);
   fChain->SetBranchAddress("Photon_E", Photon_E, &b_Photon_E);
   fChain->SetBranchAddress("Photon_pt", Photon_pt, &b_Photon_pt);
   fChain->SetBranchAddress("Photon_eta", Photon_eta, &b_Photon_eta);
   fChain->SetBranchAddress("Photon_phi", Photon_phi, &b_Photon_phi);
   fChain->SetBranchAddress("Photon_theta", Photon_theta, &b_Photon_theta);
   fChain->SetBranchAddress("Photon_et", Photon_et, &b_Photon_et);
   fChain->SetBranchAddress("Photon_swissCross", Photon_swissCross, &b_Photon_swissCross);
   fChain->SetBranchAddress("Photon_e6e2", Photon_e6e2, &b_Photon_e6e2);
   fChain->SetBranchAddress("Photon_e4e1", Photon_e4e1, &b_Photon_e4e1);
   fChain->SetBranchAddress("Photonr9", Photonr9, &b_Photonr9);
   fChain->SetBranchAddress("Photon_e1x5", Photon_e1x5, &b_Photon_e1x5);
   fChain->SetBranchAddress("Photon_e2x5", Photon_e2x5, &b_Photon_e2x5);
   fChain->SetBranchAddress("Photon_e3x3", Photon_e3x3, &b_Photon_e3x3);
   fChain->SetBranchAddress("Photon_e5x5", Photon_e5x5, &b_Photon_e5x5);
   fChain->SetBranchAddress("Photon_r1x5", Photon_r1x5, &b_Photon_r1x5);
   fChain->SetBranchAddress("Photon_r2x5", Photon_r2x5, &b_Photon_r2x5);
   fChain->SetBranchAddress("Photon_maxEnergyXtal", Photon_maxEnergyXtal, &b_Photon_maxEnergyXtal);
   fChain->SetBranchAddress("Photon_SigmaEtaEta", Photon_SigmaEtaEta, &b_Photon_SigmaEtaEta);
   fChain->SetBranchAddress("Photon_SigmaIetaIeta", Photon_SigmaIetaIeta, &b_Photon_SigmaIetaIeta);
   fChain->SetBranchAddress("Photon_SigmaEtaPhi", Photon_SigmaEtaPhi, &b_Photon_SigmaEtaPhi);
   fChain->SetBranchAddress("Photon_SigmaIetaIphi", Photon_SigmaIetaIphi, &b_Photon_SigmaIetaIphi);
   fChain->SetBranchAddress("Photon_SigmaPhiPhi", Photon_SigmaPhiPhi, &b_Photon_SigmaPhiPhi);
   fChain->SetBranchAddress("Photon_SigmaIphiIphi", Photon_SigmaIphiIphi, &b_Photon_SigmaIphiIphi);
   fChain->SetBranchAddress("Photon_Roundness", Photon_Roundness, &b_Photon_Roundness);
   fChain->SetBranchAddress("Photon_Angle", Photon_Angle, &b_Photon_Angle);
   fChain->SetBranchAddress("Photon_ecalRecHitSumEtConeDR03", Photon_ecalRecHitSumEtConeDR03, &b_Photon_ecalRecHitSumEtConeDR03);
   fChain->SetBranchAddress("Photon_hcalTowerSumEtConeDR03", Photon_hcalTowerSumEtConeDR03, &b_Photon_hcalTowerSumEtConeDR03);
   fChain->SetBranchAddress("Photon_trkSumPtSolidConeDR03", Photon_trkSumPtSolidConeDR03, &b_Photon_trkSumPtSolidConeDR03);
   fChain->SetBranchAddress("Photon_trkSumPtHollowConeDR03", Photon_trkSumPtHollowConeDR03, &b_Photon_trkSumPtHollowConeDR03);
   fChain->SetBranchAddress("Photon_nTrkSolidConeDR03", Photon_nTrkSolidConeDR03, &b_Photon_nTrkSolidConeDR03);
   fChain->SetBranchAddress("Photon_nTrkHollowConeDR03", Photon_nTrkHollowConeDR03, &b_Photon_nTrkHollowConeDR03);
   fChain->SetBranchAddress("Photon_hcalDepth1TowerSumEtConeDR03", Photon_hcalDepth1TowerSumEtConeDR03, &b_Photon_hcalDepth1TowerSumEtConeDR03);
   fChain->SetBranchAddress("Photon_hcalDepth2TowerSumEtConeDR03", Photon_hcalDepth2TowerSumEtConeDR03, &b_Photon_hcalDepth2TowerSumEtConeDR03);
   fChain->SetBranchAddress("Photon_ecalRecHitSumEtConeDR04", Photon_ecalRecHitSumEtConeDR04, &b_Photon_ecalRecHitSumEtConeDR04);
   fChain->SetBranchAddress("Photon_hcalTowerSumEtConeDR04", Photon_hcalTowerSumEtConeDR04, &b_Photon_hcalTowerSumEtConeDR04);
   fChain->SetBranchAddress("Photon_trkSumPtSolidConeDR04", Photon_trkSumPtSolidConeDR04, &b_Photon_trkSumPtSolidConeDR04);
   fChain->SetBranchAddress("Photon_trkSumPtHollowConeDR04", Photon_trkSumPtHollowConeDR04, &b_Photon_trkSumPtHollowConeDR04);
   fChain->SetBranchAddress("Photon_nTrkSolidConeDR04", Photon_nTrkSolidConeDR04, &b_Photon_nTrkSolidConeDR04);
   fChain->SetBranchAddress("Photon_nTrkHollowConeDR04", Photon_nTrkHollowConeDR04, &b_Photon_nTrkHollowConeDR04);
   fChain->SetBranchAddress("Photon_hcalDepth1TowerSumEtConeDR04", Photon_hcalDepth1TowerSumEtConeDR04, &b_Photon_hcalDepth1TowerSumEtConeDR04);
   fChain->SetBranchAddress("Photon_hcalDepth2TowerSumEtConeDR04", Photon_hcalDepth2TowerSumEtConeDR04, &b_Photon_hcalDepth2TowerSumEtConeDR04);
   fChain->SetBranchAddress("Photon_hasPixelSeed", Photon_hasPixelSeed, &b_Photon_hasPixelSeed);
   fChain->SetBranchAddress("Photon_isEB", Photon_isEB, &b_Photon_isEB);
   fChain->SetBranchAddress("Photon_isEE", Photon_isEE, &b_Photon_isEE);
   fChain->SetBranchAddress("Photon_isEBGap", Photon_isEBGap, &b_Photon_isEBGap);
   fChain->SetBranchAddress("Photon_isEEGap", Photon_isEEGap, &b_Photon_isEEGap);
   fChain->SetBranchAddress("Photon_isEBEEGap", Photon_isEBEEGap, &b_Photon_isEBEEGap);
   fChain->SetBranchAddress("Photon_e2e9", Photon_e2e9, &b_Photon_e2e9);
   fChain->SetBranchAddress("Photon_HoE", Photon_HoE, &b_Photon_HoE);
   fChain->SetBranchAddress("Photon_HoEnew", Photon_HoEnew, &b_Photon_HoEnew);
   fChain->SetBranchAddress("Photon_px", Photon_px, &b_Photon_px);
   fChain->SetBranchAddress("Photon_py", Photon_py, &b_Photon_py);
   fChain->SetBranchAddress("Photon_pz", Photon_pz, &b_Photon_pz);
   fChain->SetBranchAddress("Photon_vx", Photon_vx, &b_Photon_vx);
   fChain->SetBranchAddress("Photon_vy", Photon_vy, &b_Photon_vy);
   fChain->SetBranchAddress("Photon_vz", Photon_vz, &b_Photon_vz);
   fChain->SetBranchAddress("Photon_no_of_basic_clusters", Photon_no_of_basic_clusters, &b_Photon_no_of_basic_clusters);
   fChain->SetBranchAddress("Photon_sc_energy", Photon_sc_energy, &b_Photon_sc_energy);
   fChain->SetBranchAddress("Photon_sc_eta", Photon_sc_eta, &b_Photon_sc_eta);
   fChain->SetBranchAddress("Photon_sc_phi", Photon_sc_phi, &b_Photon_sc_phi);
   fChain->SetBranchAddress("Photon_sc_x", Photon_sc_x, &b_Photon_sc_x);
   fChain->SetBranchAddress("Photon_sc_y", Photon_sc_y, &b_Photon_sc_y);
   fChain->SetBranchAddress("Photon_sc_z", Photon_sc_z, &b_Photon_sc_z);
   fChain->SetBranchAddress("Photon_etaWidth", Photon_etaWidth, &b_Photon_etaWidth);
   fChain->SetBranchAddress("Photon_phiWidth", Photon_phiWidth, &b_Photon_phiWidth);
   fChain->SetBranchAddress("Photon_sc_et", Photon_sc_et, &b_Photon_sc_et);
   fChain->SetBranchAddress("matchphotonE", matchphotonE, &b_matchphotonE);
   fChain->SetBranchAddress("matchphotonpt", matchphotonpt, &b_matchphotonpt);
   fChain->SetBranchAddress("matchphotoneta", matchphotoneta, &b_matchphotoneta);
   fChain->SetBranchAddress("matchphotonphi", matchphotonphi, &b_matchphotonphi);
   fChain->SetBranchAddress("matchphotonpx", matchphotonpx, &b_matchphotonpx);
   fChain->SetBranchAddress("matchphotonpy", matchphotonpy, &b_matchphotonpy);
   fChain->SetBranchAddress("matchphotonpz", matchphotonpz, &b_matchphotonpz);
   fChain->SetBranchAddress("ismatchedphoton", ismatchedphoton, &b_ismatchedphoton);
   fChain->SetBranchAddress("Photon_hasConvTrk", Photon_hasConvTrk, &b_Photon_hasConvTrk);
   fChain->SetBranchAddress("Photon_ntracks", Photon_ntracks, &b_Photon_ntracks);
   fChain->SetBranchAddress("Photon_isconverted", Photon_isconverted, &b_Photon_isconverted);
   fChain->SetBranchAddress("Photon_pairInvmass", Photon_pairInvmass, &b_Photon_pairInvmass);
   fChain->SetBranchAddress("Photon_pairCotThetaSeperation", Photon_pairCotThetaSeperation, &b_Photon_pairCotThetaSeperation);
   fChain->SetBranchAddress("Photon_pairmomentumX", Photon_pairmomentumX, &b_Photon_pairmomentumX);
   fChain->SetBranchAddress("Photon_pairmomentumY", Photon_pairmomentumY, &b_Photon_pairmomentumY);
   fChain->SetBranchAddress("Photon_pairmomentumZ", Photon_pairmomentumZ, &b_Photon_pairmomentumZ);
   fChain->SetBranchAddress("Photon_EoverP", Photon_EoverP, &b_Photon_EoverP);
   fChain->SetBranchAddress("Photon_ConvVx", Photon_ConvVx, &b_Photon_ConvVx);
   fChain->SetBranchAddress("Photon_ConvVy", Photon_ConvVy, &b_Photon_ConvVy);
   fChain->SetBranchAddress("Photon_ConvVz", Photon_ConvVz, &b_Photon_ConvVz);
   fChain->SetBranchAddress("Photon_ZOfPrimaryVertex", Photon_ZOfPrimaryVertex, &b_Photon_ZOfPrimaryVertex);
   fChain->SetBranchAddress("Photon_distOfMinimumApproach", Photon_distOfMinimumApproach, &b_Photon_distOfMinimumApproach);
   fChain->SetBranchAddress("Photon_dPhiTracksAtVtx", Photon_dPhiTracksAtVtx, &b_Photon_dPhiTracksAtVtx);
   fChain->SetBranchAddress("Photon_dPhiTracksAtEcal", Photon_dPhiTracksAtEcal, &b_Photon_dPhiTracksAtEcal);
   fChain->SetBranchAddress("Photon_dEtaTracksAtEcal", Photon_dEtaTracksAtEcal, &b_Photon_dEtaTracksAtEcal);
   fChain->SetBranchAddress("npho_", &npho_, &b_npho_);
   fChain->SetBranchAddress("Photon_Electronveto", Photon_Electronveto, &b_Photon_Electronveto);
   fChain->SetBranchAddress("PFiso_Charged03", PFiso_Charged03, &b_PFiso_Charged03);
   fChain->SetBranchAddress("PFiso_Photon03", PFiso_Photon03, &b_PFiso_Photon03);
   fChain->SetBranchAddress("PFiso_Neutral03", PFiso_Neutral03, &b_PFiso_Neutral03);
   fChain->SetBranchAddress("PFiso_Sum03", PFiso_Sum03, &b_PFiso_Sum03);
   fChain->SetBranchAddress("Photon_ncrys", Photon_ncrys, &b_Photon_ncrys);
   fChain->SetBranchAddress("PFWorstiso_Charged03", PFWorstiso_Charged03, &b_PFWorstiso_Charged03);
   fChain->SetBranchAddress("Photon_timing_xtal", Photon_timing_xtal, &b_Photon_timing_xtal);
   fChain->SetBranchAddress("Photon_timingavg_xtal", Photon_timingavg_xtal, &b_Photon_timingavg_xtal);
   fChain->SetBranchAddress("Photon_energy_xtal", Photon_energy_xtal, &b_Photon_energy_xtal);
   fChain->SetBranchAddress("Photon_ieta_xtalEB", Photon_ieta_xtalEB, &b_Photon_ieta_xtalEB);
   fChain->SetBranchAddress("Photon_iphi_xtalEB", Photon_iphi_xtalEB, &b_Photon_iphi_xtalEB);
   fChain->SetBranchAddress("Photon_recoFlag_xtalEB", Photon_recoFlag_xtalEB, &b_Photon_recoFlag_xtalEB);
   fChain->SetBranchAddress("Photon_timeError_xtal", Photon_timeError_xtal, &b_Photon_timeError_xtal);
   fChain->SetBranchAddress("Photon_s9", Photon_s9, &b_Photon_s9);
   fChain->SetBranchAddress("HERecHit_subset_n", &HERecHit_subset_n, &b_HERecHit_subset_n);
   fChain->SetBranchAddress("HERecHit_subset_detid", &HERecHit_subset_detid, &b_HERecHit_subset_detid);
   fChain->SetBranchAddress("HERecHit_subset_energy", &HERecHit_subset_energy, &b_HERecHit_subset_energy);
   fChain->SetBranchAddress("HERecHit_subset_time", &HERecHit_subset_time, &b_HERecHit_subset_time);
   fChain->SetBranchAddress("HERecHit_subset_depth", &HERecHit_subset_depth, &b_HERecHit_subset_depth);
   fChain->SetBranchAddress("HERecHit_subset_phi", &HERecHit_subset_phi, &b_HERecHit_subset_phi);
   fChain->SetBranchAddress("HERecHit_subset_eta", &HERecHit_subset_eta, &b_HERecHit_subset_eta);
   fChain->SetBranchAddress("HERecHit_subset_x", &HERecHit_subset_x, &b_HERecHit_subset_x);
   fChain->SetBranchAddress("HERecHit_subset_y", &HERecHit_subset_y, &b_HERecHit_subset_y);
   fChain->SetBranchAddress("HERecHit_subset_z", &HERecHit_subset_z, &b_HERecHit_subset_z);
   fChain->SetBranchAddress("Photon_mipChi2", Photon_mipChi2, &b_Photon_mipChi2);
   fChain->SetBranchAddress("Photon_mipTotEnergy", Photon_mipTotEnergy, &b_Photon_mipTotEnergy);
   fChain->SetBranchAddress("Photon_mipSlope", Photon_mipSlope, &b_Photon_mipSlope);
   fChain->SetBranchAddress("Photon_mipIntercept", Photon_mipIntercept, &b_Photon_mipIntercept);
   fChain->SetBranchAddress("Photon_mipNhitCone", Photon_mipNhitCone, &b_Photon_mipNhitCone);
   fChain->SetBranchAddress("Photon_mipIsHalo", Photon_mipIsHalo, &b_Photon_mipIsHalo);
   fChain->SetBranchAddress("EBRecHit_size", &EBRecHit_size, &b_EBRecHit_size);
   fChain->SetBranchAddress("EBRecHit_eta", EBRecHit_eta, &b_EBRecHit_eta);
   fChain->SetBranchAddress("EBRecHit_phi", EBRecHit_phi, &b_EBRecHit_phi);
   fChain->SetBranchAddress("EBRecHit_ieta", EBRecHit_ieta, &b_EBRecHit_ieta);
   fChain->SetBranchAddress("EBRecHit_iphi", EBRecHit_iphi, &b_EBRecHit_iphi);
   fChain->SetBranchAddress("EBRecHit_e", EBRecHit_e, &b_EBRecHit_e);
   fChain->SetBranchAddress("EBRecHit_et", EBRecHit_et, &b_EBRecHit_et);
   fChain->SetBranchAddress("EBRecHit_flag", EBRecHit_flag, &b_EBRecHit_flag);
   fChain->SetBranchAddress("EBRecHit_time", EBRecHit_time, &b_EBRecHit_time);
   fChain->SetBranchAddress("EERecHit_size", &EERecHit_size, &b_EERecHit_size);
   fChain->SetBranchAddress("EERecHit_eta", EERecHit_eta, &b_EERecHit_eta);
   fChain->SetBranchAddress("EERecHit_phi", EERecHit_phi, &b_EERecHit_phi);
   fChain->SetBranchAddress("EERecHit_ieta", EERecHit_ieta, &b_EERecHit_ieta);
   fChain->SetBranchAddress("EERecHit_iphi", EERecHit_iphi, &b_EERecHit_iphi);
   fChain->SetBranchAddress("EERecHit_e", EERecHit_e, &b_EERecHit_e);
   fChain->SetBranchAddress("EERecHit_et", EERecHit_et, &b_EERecHit_et);
   fChain->SetBranchAddress("EERecHit_flag", EERecHit_flag, &b_EERecHit_flag);
   fChain->SetBranchAddress("EERecHit_time", EERecHit_time, &b_EERecHit_time);
   fChain->SetBranchAddress("isBeamHaloGlobalLoosePass", &isBeamHaloGlobalLoosePass, &b_isBeamHaloGlobalLoosePass);
   fChain->SetBranchAddress("isBeamHaloGlobalTightPass", &isBeamHaloGlobalTightPass, &b_isBeamHaloGloablTightPass);
   fChain->SetBranchAddress("isBeamHaloHcalLoosePass", &isBeamHaloHcalLoosePass, &b_isBeamHaloHcalLoosePass);
   fChain->SetBranchAddress("isBeamHaloHcalTightPass", &isBeamHaloHcalTightPass, &b_isBeamHaloHcalTightPass);
   fChain->SetBranchAddress("isBeamHaloCSCLoosePass", &isBeamHaloCSCLoosePass, &b_isBeamHaloCSCLoosePass);
   fChain->SetBranchAddress("isBeamHaloCSCTightPass", &isBeamHaloCSCTightPass, &b_isBeamHaloCSCTightPass);
   fChain->SetBranchAddress("isBeamHaloEcalLoosePass", &isBeamHaloEcalLoosePass, &b_isBeamHaloEcalLoosePass);
   fChain->SetBranchAddress("isBeamHaloEcalTightPass", &isBeamHaloEcalTightPass, &b_isBeamHaloEcalTightPass);
   fChain->SetBranchAddress("isBeamHaloIDTightPass", &isBeamHaloIDTightPass, &b_isBeamHaloIDTightPass);
   fChain->SetBranchAddress("isBeamHaloIDLoosePass", &isBeamHaloIDLoosePass, &b_isBeamHaloIDLoosePass);
   fChain->SetBranchAddress("isSmellsLikeHalo_Tag", &isSmellsLikeHalo_Tag, &b_isSmellsLikeHalo_Tag);
   fChain->SetBranchAddress("isLooseHalo_Tag", &isLooseHalo_Tag, &b_isLooseHalo_Tag);
   fChain->SetBranchAddress("isTightHalo_Tag", &isTightHalo_Tag, &b_isTightHalo_Tag);
   fChain->SetBranchAddress("isExtremeTightHalo_Tag", &isExtremeTightHalo_Tag, &b_isExtremeTightHalo_Tag);
   fChain->SetBranchAddress("CaloMetSigma", &CaloMetSigma, &b_CaloMetSig);
   fChain->SetBranchAddress("CaloMetEz", &CaloMetEz, &b_CaloMetEz);
   fChain->SetBranchAddress("CaloEtFractionHadronic", &CaloEtFractionHadronic, &b_CaloEtFractionHadronic);
   fChain->SetBranchAddress("CaloEmEtFraction", &CaloEmEtFraction, &b_CaloEmEtFraction);
   fChain->SetBranchAddress("CaloHadEtInHB", &CaloHadEtInHB, &b_CaloHadEtInHB);
   fChain->SetBranchAddress("CaloHadEtInHE", &CaloHadEtInHE, &b_CaloHadEtInHE);
   fChain->SetBranchAddress("CaloHadEtInHO", &CaloHadEtInHO, &b_CaloHadEtInHO);
   fChain->SetBranchAddress("CaloHadEtInHF", &CaloHadEtInHF, &b_CaloHadEtInHF);
   fChain->SetBranchAddress("CaloEmEtInEB", &CaloEmEtInEB, &b_CaloEmEtInEB);
   fChain->SetBranchAddress("CaloEmEtInEE", &CaloEmEtInEE, &b_CaloEmEtInEE);
   fChain->SetBranchAddress("CaloEmEtInHF", &CaloEmEtInHF, &b_CaloEmEtInHF);
   fChain->SetBranchAddress("CaloMaxEtInEmTowers", &CaloMaxEtInEmTowers, &b_CaloMaxEtInEmTowers);
   fChain->SetBranchAddress("CaloMaxEtInHadTowers", &CaloMaxEtInHadTowers, &b_CaloMaxEtInHadTowers);
   fChain->SetBranchAddress("CaloMetPt", CaloMetPt, &b_CaloMetPt);
   fChain->SetBranchAddress("CaloMetPx", CaloMetPx, &b_CaloMetPx);
   fChain->SetBranchAddress("CaloMetPy", CaloMetPy, &b_CaloMetPy);
   fChain->SetBranchAddress("CaloMetPhi", CaloMetPhi, &b_CaloMetPhi);
   fChain->SetBranchAddress("CaloMetSumEt", CaloMetSumEt, &b_CaloMetSumEt);
   /*fChain->SetBranchAddress("genMetPt", &genMetPt, &b_genMetPt);
   fChain->SetBranchAddress("genMetPx", &genMetPx, &b_genMetPx);
   fChain->SetBranchAddress("genMetPy", &genMetPy, &b_genMetPy);
   fChain->SetBranchAddress("genMetPhi", &genMetPhi, &b_genMetPhi);
   fChain->SetBranchAddress("genMetSumEt", &genMetSumEt, &b_genMetSumEt);*/
   fChain->SetBranchAddress("Delta_phi", &Delta_phi, &b_Delta_phi);
   //fChain->SetBranchAddress("Delta_phiGEN", &Delta_phiGEN, &b_Delta_phiGEN);
   fChain->SetBranchAddress("PFMetPt", PFMetPt, &b_PFMetPt);
   fChain->SetBranchAddress("PFMetPx", PFMetPx, &b_PFMetPx);
   fChain->SetBranchAddress("PFMetPy", PFMetPy, &b_PFMetPy);
   fChain->SetBranchAddress("PFMetPhi", PFMetPhi, &b_PFMetPhi);
   fChain->SetBranchAddress("PFMetSumEt", PFMetSumEt, &b_PFMetSumEt);
   fChain->SetBranchAddress("Delta_phiPF", &Delta_phiPF, &b_Delta_phiPF);
   fChain->SetBranchAddress("TCMetPt", TCMetPt, &b_TCMetPt);
   fChain->SetBranchAddress("TCMetPx", TCMetPx, &b_TCMetPx);
   fChain->SetBranchAddress("TCMetPy", TCMetPy, &b_TCMetPy);
   fChain->SetBranchAddress("TCMetPhi", TCMetPhi, &b_TCMetPhi);
   fChain->SetBranchAddress("TCMetSumEt", TCMetSumEt, &b_TCMetSumEt);
   fChain->SetBranchAddress("Delta_phiTC", &Delta_phiTC, &b_Delta_phiTC);
   fChain->SetBranchAddress("CaloTower_n", &CaloTower_n, &b_CaloTower_n);
   fChain->SetBranchAddress("CaloTower_eta", CaloTower_eta, &b_CaloTower_eta);
   fChain->SetBranchAddress("CaloTower_phi", CaloTower_phi, &b_CaloTower_phi);
   fChain->SetBranchAddress("CaloTower_E", CaloTower_E, &b_CaloTower_E);
   fChain->SetBranchAddress("CaloTower_Et", CaloTower_Et, &b_CaloTower_Et);
   fChain->SetBranchAddress("CaloTower_emEnergy", CaloTower_emEnergy, &b_CaloTower_emEnergy);
   fChain->SetBranchAddress("CaloTower_hadEnergy", CaloTower_hadEnergy, &b_CaloTower_hadEnergy);
   fChain->SetBranchAddress("CaloTower_p", CaloTower_p, &b_CaloTower_p);
   fChain->SetBranchAddress("CaloTower_EMEt", CaloTower_EMEt, &b_CaloTower_EMEt);
   fChain->SetBranchAddress("CaloTower_HadEt", CaloTower_HadEt, &b_CaloTower_HadEt);
   fChain->SetBranchAddress("CaloTower_HadPhi", CaloTower_HadPhi, &b_CaloTower_HadPhi);
   fChain->SetBranchAddress("CaloTower_HadEta", CaloTower_HadEta, &b_CaloTower_HadEta);
   fChain->SetBranchAddress("CaloTower_EMPhi", CaloTower_EMPhi, &b_CaloTower_EMPhi);
   fChain->SetBranchAddress("CaloTower_EMEta", CaloTower_EMEta, &b_CaloTower_EMEta);
   fChain->SetBranchAddress("CaloTower_HadX", CaloTower_HadX, &b_CaloTower_HadX);
   fChain->SetBranchAddress("CaloTower_HadY", CaloTower_HadY, &b_CaloTower_HadY);
   fChain->SetBranchAddress("CaloTower_HadZ", CaloTower_HadZ, &b_CaloTower_HadZ);
   fChain->SetBranchAddress("CaloTower_HE_E", CaloTower_HE_E, &b_CaloTower_HE_E);
   fChain->SetBranchAddress("CaloTower_HB_E", CaloTower_HB_E, &b_CaloTower_HB_E);
   fChain->SetBranchAddress("CaloTower_EMTime", CaloTower_EMTime, &b_CaloTower_EMTime);
   fChain->SetBranchAddress("CaloTower_HadTime", CaloTower_HadTime, &b_CaloTower_HadTime);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("sigma", &sigma, &b_sigma);
   fChain->SetBranchAddress("rho44", &rho44, &b_rho44);
   fChain->SetBranchAddress("sigma44", &sigma44, &b_sigma44);
   Notify();

}

Bool_t myEvent::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void myEvent::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t myEvent::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef myEvent_cxx
