//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file PhysicsList.cc
/// \brief Implementation of the B3::PhysicsList class

#include "PhysicsList.hh"

// #include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4SystemOfUnits.hh"
// #include "G4RadioactiveDecayPhysics.hh"

// namespace B1
// {

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicsList::PhysicsList()
{
  //指定输出信息的复杂度，越高越复杂，一般设置为1即可
  //SetVerboseLevel(1);
  //设置粒子的截断，一般默认
  defaultCutValue = 0.1*mm;

  // EM physics//指定电磁相互作用物理过程
  RegisterPhysics(new G4EmStandardPhysics());

  //G4OpticalPhysics类包括：闪烁光子产生、切伦科夫辐射、伯克吸收、瑞利散射和一些边界过程（反射，折射，吸收）
  G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
  RegisterPhysics(opticalPhysics);
  

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicsList::~PhysicsList()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsList::SetCuts()
{
  G4VUserPhysicsList::SetCuts();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......













//
// Created by wangm on 17-8-7.
//


// #include <G4ProcessManager.hh>
// #include "PhysicsList.hh"

// #include "G4SystemOfUnits.hh"
// #include "G4UnitsTable.hh"

// // particles

// #include "G4BosonConstructor.hh"
// #include "G4LeptonConstructor.hh"
// #include "G4MesonConstructor.hh"
// #include "G4BaryonConstructor.hh"
// #include "G4IonConstructor.hh"
// #include "G4ShortLivedConstructor.hh"
// #include "G4StoppingPhysics.hh"


// //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// PhysicsList::PhysicsList() :G4VUserPhysicsList()
// {
//     SetVerboseLevel(1);

//     //add new units
//     //
//     new G4UnitDefinition( "millielectronVolt", "meV", "Energy", 1.e-3*eV);
//     new G4UnitDefinition( "mm2/g",  "mm2/g", "Surface/Mass", mm2/g);
//     new G4UnitDefinition( "um2/mg", "um2/mg","Surface/Mass", um*um/mg);

// }

// //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// PhysicsList::~PhysicsList()
// { }

// //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// void PhysicsList::ConstructParticle()
// {
//     //玻色子、轻子、介子、重子、离子、短寿命-全部六大类粒子
//     G4BosonConstructor  pBosonConstructor;
//     pBosonConstructor.ConstructParticle();

//     G4LeptonConstructor pLeptonConstructor;
//     pLeptonConstructor.ConstructParticle();

//     G4MesonConstructor pMesonConstructor;
//     pMesonConstructor.ConstructParticle();

//     G4BaryonConstructor pBaryonConstructor;
//     pBaryonConstructor.ConstructParticle();

//     G4IonConstructor pIonConstructor;
//     pIonConstructor.ConstructParticle();

//     G4ShortLivedConstructor pShortLivedConstructor;
//     pShortLivedConstructor.ConstructParticle();
// }
// //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// void PhysicsList::ConstructProcess(){
//     G4int verb = 1;
//     SetVerboseLevel(verb);

//     AddTransportation();
//     ConstructDecay();
//     ConstructEM();
//     ConstructOp();
//     ConstructHadron();
//     ConstructNuclear();
// }

// void PhysicsList::SetCuts()
// {
//     SetCutValue(0*mm, "proton");
// }

// //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// #include "G4ComptonScattering.hh"
// #include "G4GammaConversion.hh"
// #include "G4PhotoElectricEffect.hh"
// #include "G4RayleighScattering.hh"

// #include "G4eMultipleScattering.hh"
// #include "G4hMultipleScattering.hh"

// #include "G4eIonisation.hh"
// #include "G4eBremsstrahlung.hh"
// #include "G4eplusAnnihilation.hh"

// #include "G4MuIonisation.hh"
// #include "G4MuBremsstrahlung.hh"
// #include "G4MuPairProduction.hh"

// #include "G4hIonisation.hh"
// #include "G4hBremsstrahlung.hh"
// #include "G4hPairProduction.hh"

// #include "G4ionIonisation.hh"
// #include "G4EmStandardPhysics_option3.hh"

// void PhysicsList::ConstructEM() {

//     auto emPhysicsList = new G4EmStandardPhysics_option3();
//     emPhysicsList->ConstructProcess();

//     /*
//     auto particleIterator=GetParticleIterator();
//     particleIterator->reset();

//     while( (*particleIterator)() )
//     {
//         G4ParticleDefinition* particle = particleIterator->value();
//         G4ProcessManager* pmanager = particle->GetProcessManager();
//         G4String particleName = particle->GetParticleName();

//         if (particleName == "gamma")
//         {
//             //gamma
//             pmanager->AddDiscreteProcess(new G4PhotoElectricEffect());
//             pmanager->AddDiscreteProcess(new G4ComptonScattering());
//             pmanager->AddDiscreteProcess(new G4GammaConversion());
//             pmanager->AddDiscreteProcess(new G4RayleighScattering);
//         }
//         else if (particleName == "e-")
//         {
//             //electron
//             pmanager->AddProcess(new G4eMultipleScattering(),-1, 1,1);
//             pmanager->AddProcess(new G4eIonisation(),       -1, 2,2);
//             pmanager->AddProcess(new G4eBremsstrahlung(),   -1, 3,3);

//         } else if (particleName == "e+") {

//             //positron
//             pmanager->AddProcess(new G4eMultipleScattering(),-1, 1,1);
//             pmanager->AddProcess(new G4eIonisation(),       -1, 2,2);
//             pmanager->AddProcess(new G4eBremsstrahlung(),   -1, 3,3);
//             pmanager->AddProcess(new G4eplusAnnihilation(),  0,-1,4);

//         } else if( particleName == "mu-" ||
//                    particleName == "mu+" ) {

//             //muon
//             pmanager->AddProcess(new G4hMultipleScattering, -1, 1, 1);
//             pmanager->AddProcess(new G4MuIonisation,        -1, 2, 2);
//             pmanager->AddProcess(new G4MuBremsstrahlung,    -1, 3, 3);
//             pmanager->AddProcess(new G4MuPairProduction,    -1, 4, 4);

//         } else if( particleName == "pi-" ||
//                    particleName == "pi+" ) {

//             //pions
//             pmanager->AddProcess(new G4hMultipleScattering, -1, 1, 1);
//             pmanager->AddProcess(new G4hIonisation,         -1, 2, 2);
//             pmanager->AddProcess(new G4hBremsstrahlung,     -1, 3, 3);
//             pmanager->AddProcess(new G4hPairProduction,     -1, 4, 4);

//         } else if( particleName == "proton" ) {

//             //proton
//             pmanager->AddProcess(new G4hMultipleScattering, -1, 1, 1);
//             pmanager->AddProcess(new G4hIonisation,         -1, 2, 2);
//             pmanager->AddProcess(new G4hBremsstrahlung,     -1, 3, 3);
//             pmanager->AddProcess(new G4hPairProduction,     -1, 4, 4);

//         } else if( particleName == "alpha" ||
//                    particleName == "He3" ||
//                    particleName == "GenericIon" ) {

//             //Ions
//             pmanager->AddProcess(new G4hMultipleScattering, -1, 1, 1);
//             pmanager->AddProcess(new G4ionIonisation,       -1, 2, 2);

//         } else if ((!particle->IsShortLived()) &&
//                    (particle->GetPDGCharge() != 0.0) &&
//                    (particle->GetParticleName() != "chargedgeantino")) {

//             //all others charged particles except geantino
//             pmanager->AddProcess(new G4hMultipleScattering, -1, 1, 1);
//             pmanager->AddProcess(new G4hIonisation,         -1, 2, 2);

//         }
//     }
//     */
// }

// #include "G4Decay.hh"

// void PhysicsList::ConstructDecay() {
//     G4Decay* theDecayProcess = new G4Decay();
//     auto particleIterator=GetParticleIterator();
//     particleIterator->reset();
//     while( (*particleIterator)() ){
//         G4ParticleDefinition* particle = particleIterator->value();
//         G4ProcessManager* pmanager = particle->GetProcessManager();
//         if (theDecayProcess->IsApplicable(*particle)) {
//             pmanager ->AddProcess(theDecayProcess);
//             pmanager ->SetProcessOrdering(theDecayProcess, idxPostStep);
//             pmanager ->SetProcessOrdering(theDecayProcess, idxAtRest);
//         }
//     }
// }

// #include "G4HadronPhysicsFTFP_BERT_HP.hh"

// #include "G4HadronElasticPhysicsHP.hh"






// void PhysicsList::ConstructHadron() {
//     //G4int verb=1;
//     auto theHadronElasticList = new G4HadronElasticPhysicsHP;
//     theHadronElasticList->ConstructProcess();
//     auto theHadronFTFPList = new G4HadronPhysicsFTFP_BERT_HP;
//     theHadronFTFPList->ConstructProcess();
//     //RegisterPhysics(new G4HadronPhysicsFTFP_BERT_HP());
//     //RegisterPhysics(new G4HadronElasticPhysicsHP());
// }

// #include "G4EmExtraPhysics.hh"

// void PhysicsList::ConstructNuclear(){
//     auto extraPhysicsList = new G4EmExtraPhysics();
//     extraPhysicsList->ConstructProcess();
//     //RegisterPhysics(new G4EmExtraPhysics());
// }


// #include "G4SynchrotronRadiation.hh"
// #include "G4TransitionRadiation.hh"
// #include "G4Cerenkov.hh"
// #include "G4Scintillation.hh"
// #include "G4OpAbsorption.hh"
// #include "G4OpRayleigh.hh"
// #include "G4OpMieHG.hh"
// #include "G4OpBoundaryProcess.hh"
// #include "G4MaterialPropertiesTable.hh"

// void PhysicsList::ConstructOp() {

//     //发光：契伦科夫和闪烁体
//     G4Cerenkov* theCerenkovProcess = new G4Cerenkov("Cerenkov");
//     G4int MaxNumPhotons = 20;
//     theCerenkovProcess->SetTrackSecondariesFirst(true);
//     theCerenkovProcess->SetMaxBetaChangePerStep(10.0);
//     theCerenkovProcess->SetMaxNumPhotonsPerStep(MaxNumPhotons);

//     auto theParticleIterator=GetParticleIterator();
//     theParticleIterator->reset();
//     while( (*theParticleIterator)() ){
//         G4ParticleDefinition* particle = theParticleIterator->value();
//         G4ProcessManager* pmanager = particle->GetProcessManager();
//         G4String particleName = particle->GetParticleName();
//         if (theCerenkovProcess->IsApplicable(*particle)) {
//             pmanager->AddProcess(theCerenkovProcess);
//             pmanager->SetProcessOrdering(theCerenkovProcess,idxPostStep);
//         }
//     }

//     G4Scintillation* theScintillation = new G4Scintillation("Scintillation");
//     theScintillation->SetTrackSecondariesFirst(true);
//     //theScintillation->SetScintillationYieldFactor(1.0);
    
//     theParticleIterator->reset();
//     while( (*theParticleIterator)() ){
//         G4ParticleDefinition* particle = theParticleIterator->value();
//         G4ProcessManager* pmanager = particle->GetProcessManager();
//         G4String particleName = particle->GetParticleName();
//         if (theScintillation->IsApplicable(*particle)) {
//                 pmanager->AddProcess(theScintillation);
//                 pmanager->SetProcessOrderingToLast(theScintillation, idxAtRest);
//                 pmanager->SetProcessOrderingToLast(theScintillation, idxPostStep);
//         }
//     }

//     //追迹：吸收、瑞利散射、米氏散射、边界
//     auto theAbsorptionProcess = new G4OpAbsorption();
//     auto theRayleighScatteringProcess = new G4OpRayleigh();
//     auto theMieHGScatteringProcess = new G4OpMieHG();
//     auto theBoundaryProcess = new G4OpBoundaryProcess();
//     theParticleIterator->reset();
//     while( (*theParticleIterator)() ) {
//         G4ParticleDefinition* particle = theParticleIterator->value();
//         G4ProcessManager* pmanager = particle->GetProcessManager();
//         G4String particleName = particle->GetParticleName();
//         if (particleName == "opticalphoton") {
//             G4cout << " AddDiscreteProcess to OpticalPhoton " << G4endl;
//             pmanager->AddDiscreteProcess(theAbsorptionProcess);
//             pmanager->AddDiscreteProcess(theRayleighScatteringProcess);
//             pmanager->AddDiscreteProcess(theMieHGScatteringProcess);
//             pmanager->AddDiscreteProcess(theBoundaryProcess);
//         }
//     }
// }
