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
/// \file B2aDetectorMessenger.cc
/// \brief Implementation of the B2aDetectorMessenger class


#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"

#include "G4UIdirectory.hh"

#include "G4UIcmdWithADoubleAndUnit.hh"

namespace B1{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorMessenger::DetectorMessenger(DetectorConstruction* Det)
 : fDetectorConstruction(Det)
{
  fB1Directory = new G4UIdirectory("/B1/");
  fB1Directory->SetGuidance("UI commands specific to this example.");

  fDetDirectory = new G4UIdirectory("/B1/det/");
  fDetDirectory->SetGuidance("Detector construction control");

  fColsCmd = new G4UIcmdWithADoubleAndUnit("/B1/det/setCols",this);
  fColsCmd->SetGuidance("Define   Cols ");
  fColsCmd->SetParameterName("Cols",false);

  fColsCmd->SetUnitCategory("Length");//长度单位
  fColsCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorMessenger::~DetectorMessenger()
{

  delete fColsCmd;
  delete fB1Directory;
  delete fDetDirectory;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{

  if( command == fColsCmd ) {
    fDetectorConstruction
      ->SetCols(fColsCmd->GetNewDoubleValue(newValue));
  }   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
}