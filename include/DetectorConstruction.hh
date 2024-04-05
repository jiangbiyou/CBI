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
/// \file DetectorConstruction.hh
/// \brief Definition of the B1::DetectorConstruction class

#ifndef B1DetectorConstruction_h
#define B1DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Element.hh"
#include "G4MaterialPropertiesTable.hh"


/// Detector construction class to define materials and geometry.

namespace B1
{

class DetectorMessenger;


class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction();

    ~DetectorConstruction() override;

    G4VPhysicalVolume* Construct() ;

    void SetCols(G4int);



   private:

    DetectorMessenger*  fMessenger = nullptr;   // messenger
    //virtual void ConstructSDandField();//sentitave detector

    void DefineMaterials();
    //G4int nCols,nRows;
    G4int cols = 1;
    G4Box *solidWorld, *solidHome, *solidRadiator, *solidDetector, *solidCllimator, *solidDB , *solidRadiator0;
    G4Tubs *solidRadiator1, *solidRadiator2, *solidRadiator3, *solidRadiator4, *solidRadiator5;
    G4LogicalVolume *logicWorld, *logicHome, *logicRadiator, *logicDetector, *logicCllimator,*logicDB , *logicRadiator1, *logicRadiator2, *logicRadiator3, *logicRadiator4, *logicRadiator5;
    G4VPhysicalVolume *physWorld, *physHome, *physRadiator, *physDetector, *physCllimator, *physDB, *physRadiator1, *physRadiator2, *physRadiator3, *physRadiator4, *physRadiator5;
    G4Material* SiO2, * H2O, * Aerogel ,* world_mat , *W , *Fe, *CsI_Tl, *G4_C , *Al , *Cu, *STEEL, *BRASS, *object_mat;
    G4Element * C;
    G4double xRad , yRad , zRad ;
    G4ThreeVector pos;
    G4int a = 5;//碳块距离mm
    G4int b = 40;//铁板厚度mm
    
};

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
