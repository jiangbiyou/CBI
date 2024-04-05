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
/// \file SteppingAction.cc
/// \brief Implementation of the B1::SteppingAction class

#include "SteppingAction.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
using std::ofstream;
ofstream data_step_energy("./data_step_energy.txt");


namespace B1
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(EventAction* eventAction)
: fEventAction(eventAction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* step)
{
    //统计每一步的光子数
      G4String ParticleName = step->GetTrack()->GetParticleDefinition()->GetParticleName();
     
      //G4int ParentID = step->GetTrack()->GetParentID();
      // G4int PEDE = step->GetTrack()->GetDefinition()->GetPDGEncoding();"Envelope"
      G4String opticalphoton = "gamma";
      G4ThreeVector pos;
      //判断是否是测得的物体背散射信号
      if( ParticleName == opticalphoton && step->GetTrack()->GetParentID() == 0 )
      {
        G4double edepStep = step->GetPreStepPoint()->GetKineticEnergy();
        // G4cout<< "edepStep:" << edepStep <<G4endl;
        // 判断是否背散射信号是否进入探测器
          if(step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume()->GetName()== "logicHome"){
              if(step->GetPostStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume()->GetName() == "logicDetector"){
                    //计数
                    fEventAction->AddNum();
                    // G4cout<< "number+1" <<G4endl;
                    //pos = step->GetPostStepPoint()->GetPosition();
                    //data_step_energy << pos[0]<< G4endl;                
                    //data_step_energy << edepStep << G4endl;
                    //能量沉积
                    //fEventAction->AddEdep(edepStep);
                    //G4cout<< "edepStep:" << edepStep <<G4endl;
                }
              }
      }


return ;
  }

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


