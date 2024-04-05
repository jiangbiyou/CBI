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
/// \file DetectorConstruction.cc
/// \brief Implementation of the B1::DetectorConstruction class

#include "DetectorMessenger.hh"
#include "DetectorConstruction.hh"


#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4Torus.hh"

#include "G4SystemOfUnits.hh"
#include "G4SubtractionSolid.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalBorderSurface.hh"

using namespace B1;

namespace B1
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
{
    fMessenger = new DetectorMessenger(this);

    DefineMaterials();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{
    delete fMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


void DetectorConstruction::DefineMaterials()

{
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
  //
  //material
  //
  SiO2 = new G4Material("SiO2", 2.201*g/cm3, 2);
  SiO2->AddElement(nist->FindOrBuildElement("Si"), 1);
  SiO2->AddElement(nist->FindOrBuildElement("O"), 2);

  H2O = new G4Material("H2O", 1.000*g/cm3, 2);
  H2O->AddElement(nist->FindOrBuildElement("H"), 2);
  H2O->AddElement(nist->FindOrBuildElement("O"), 1);

  C = nist->FindOrBuildElement("C");

  Aerogel = new G4Material("Aerogel", 0.200*g/cm3, 3);
  Aerogel->AddMaterial(SiO2, 62.5*perCent);
  Aerogel->AddMaterial(H2O, 37.4*perCent);
  Aerogel->AddElement(C, 0.1*perCent);

  world_mat = nist->FindOrBuildMaterial("G4_AIR");

  W = nist->FindOrBuildMaterial("G4_W");
  Fe = nist->FindOrBuildMaterial("G4_Fe");
  G4_C = nist->FindOrBuildMaterial("G4_C");
  Cu = nist->FindOrBuildMaterial("G4_Cu");
  Al = nist->FindOrBuildMaterial("G4_Al");
  STEEL = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");//不锈钢
  BRASS = nist->FindOrBuildMaterial("G4_BRASS");//黄铜
  
  // G4_CONCRETE  混凝土

//自定义爆炸物
G4String name1 = "PETN";
G4double density1 = 1.803 * g/cm3;
G4int nel = 4;
G4Material* mat = new G4Material(name1, density1, nel);
mat->AddElement(G4Element::GetElement("H"), 5);
mat->AddElement(G4Element::GetElement("C"), 7);
mat->AddElement(G4Element::GetElement("N"), 5);
mat->AddElement(G4Element::GetElement("O"), 8);
object_mat = Fe;




//
//
//
  G4String name, symbol;
  G4double a, z, density, fractionmass;
  G4int ncomponents;
  //物理信息
  a = 132.9 *g/mole;
  G4Element* elCs = new G4Element(name = "Cesium", symbol = "Cs", z = 55, a);
  a = 126.9 *g/mole;
  G4Element* elI = new G4Element(name = "Iodine", symbol = "I", z = 53, a);
  a = 204.38 *g/mole;
  G4Element* elTl = new G4Element(name = "Thallium", symbol = "Tl", z = 81, a);
  density = 4.51 *g/cm3;

  CsI_Tl = new G4Material(name = "CsI_Tl", density, ncomponents = 3);
  CsI_Tl->AddElement(elCs, fractionmass = 48.8* perCent);
  CsI_Tl->AddElement(elI, fractionmass = 51.1* perCent);
  CsI_Tl->AddElement(elTl, fractionmass = 0.1* perCent);
  //光学信息
  const G4int n = 6 ;

  G4double csl_Energy[n] = {2.4081 *eV, 2.5835 *eV, 2.6783 *eV, 2.7557 *eV, 2.9178 *eV, 3.0847 *eV};
  G4double csl_SCINT_Fast[n] = {1.00, 1.00, 1.00, 1.00, 1.00, 1.00};
  //G4double csl_SCINT_Slow[n] = {};
  G4double csl_RIND[n] = {1.79, 1.79, 1.79, 1.79, 1.79, 1.79};
  G4double csl_ABSL[n] = {1.86*cm, 1.86*cm, 1.86*cm, 1.86*cm, 1.86*cm, 1.86*cm};


  G4MaterialPropertiesTable* csl_mat = new G4MaterialPropertiesTable;

  //AddProperty（）添加随波长变化的光学属性
  csl_mat->AddProperty("SCINTILLATIONCOMPONENT1", csl_Energy, csl_SCINT_Fast, n );  
  //csl_mat->AddProperty("SCINTILLATIONCOMPONENT2", csl_Energy, csl_SCINT);
  csl_mat->AddProperty("RINDEX", csl_Energy, csl_RIND, n );
  csl_mat->AddProperty("ABSLENGTH", csl_Energy, csl_ABSL, n );

  
  //添加本征属性
  csl_mat->AddConstProperty("SCINTILLATIONYIELD", 54./keV);//光产额 
  csl_mat->AddConstProperty("RESOLUTIONSCALE",1.0);//晶体本征分辨（宽度）
  csl_mat->AddConstProperty("SCINTILLATIONTIMECONSTANT1", 1000*ns);//时间常数


  CsI_Tl->SetMaterialPropertiesTable(csl_mat);


//
  G4double energy[2] = {1.239841939*eV/0.9, 1.239841939*eV/0.2};
  G4double rindexAerogel[2] = {1.1, 1.1};
  G4double rindexWorld[2] = {1.0, 1.0};

  G4MaterialPropertiesTable* mptAerogel = new G4MaterialPropertiesTable();
  mptAerogel->AddProperty("RINDEX", energy, rindexAerogel, 2) ;

  Aerogel->SetMaterialPropertiesTable(mptAerogel);
  
  G4MaterialPropertiesTable * mptWorld = new G4MaterialPropertiesTable();
  mptWorld->AddProperty("RINDEX", energy, rindexWorld,2);
  world_mat->SetMaterialPropertiesTable(mptWorld);


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{


//定义世界为正方体
  G4double xWorld = 0.8*m;//x方向半长
  G4double yWorld = 0.8*m;//y方向半长
  G4double zWorld = 0.8*m;//z方向半长

  solidWorld =
    new G4Box("solidWorld",                       //its name
       xWorld,  yWorld,  zWorld);     //its size


//逻辑体
  logicWorld =
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "logicWorld");            //its name
//物理体
  physWorld =
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(0.,0.,0.),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "physWorld",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      true);                 //overlaps checking

//
//定义世界中实验室为正方体
//

  G4double xHome = 0.5*m;
  G4double yHome = 0.5*m;
  G4double zHome = 0.5*m;

  solidHome =
    new G4Box("solidHome",                       //its name
       xHome,  yHome,  zHome);     //its size



  logicHome =
    new G4LogicalVolume(solidHome,          //its solid
                        world_mat,           //its material
                        "logicHome");            //its name

  physHome =
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(0.,0.,0.),       //at (0,0,0)
                      logicHome,            //its logical volume
                      "physHome",               //its name
                      logicWorld,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      true);                 //overlaps checking






  //
  // 定义碳块为正方体
  // 

   xRad = 160*mm/2;
   yRad = 40*mm/2;
   zRad = 60*mm/2;

  solidRadiator =
    new G4Box("solidRadiator",                       //its name
       xRad, yRad, zRad);     //its size

  logicRadiator =
    new G4LogicalVolume(solidRadiator,          //its solid
                        G4_C,           //its material
                        "logicRadiator");            //its name
//物体坐标
pos = G4ThreeVector(-80*mm+1*(cols*2-1)*mm, 0*mm, zRad);
physRadiator =
    new G4PVPlacement(0,                     //no rotation
                      pos,       //at (0,0,0)
                      logicRadiator,            //its logical volume
                      "physRadiator",               //its name
                      logicHome,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      true);                 //overlaps checking
  


  
//定义碳块中有四个圆环状铁环

//   G4Box* solidRadiator1 =
//     new G4Box("solidRadiator1",                       //its name
//        32*mm/2, 32*mm/2, 32*mm/2);     //its size

//圆环的内经6mm，外径14mm，厚度20mm，0～360度圆环，其它圆环定义类似
solidRadiator1 = new G4Tubs("solidRadiator1",10*mm,18*mm,b/2*mm,0,360*degree);

//逻辑体
  logicRadiator1 =
    new G4LogicalVolume(solidRadiator1,          //its solid
                        object_mat,           //its material
                        "logicRadiator1");            //its name

//可定义旋转角度
// G4RotationMatrix *rm = new G4RotationMatrix();
// G4double angle = -45 *deg;
// rm->rotateX(angle);

//物理体
physRadiator1 =
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(60*mm, 0, -zRad+b/2*mm+a*mm),       //29*mm
                      logicRadiator1,            //its logical volume
                      "physRadiator1",               //its name
                      logicRadiator,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      true);                 //overlaps checking



//2

solidRadiator2 = new G4Tubs("solidRadiator2",12*mm,18*mm,b/2*mm,0,360*degree);


  logicRadiator2 =
    new G4LogicalVolume(solidRadiator2,          //its solid
                        object_mat,           //its material
                        "logicRadiator2");            //its name


// G4RotationMatrix *rm = new G4RotationMatrix();
// G4double angle = -45 *deg;
// rm->rotateX(angle);

physRadiator2 =
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(20*mm, 0, -zRad+b/2*mm+a*mm ),       //-5*mm,
                      logicRadiator2,            //its logical volume
                      "physRadiator2",               //its name
                      logicRadiator,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      true);                 //overlaps checking







//3

solidRadiator3 = new G4Tubs("solidRadiator3",14*mm,18*mm,b/2*mm,0,360*degree);


  logicRadiator3 =
    new G4LogicalVolume(solidRadiator3,          //its solid
                        object_mat,           //its material
                        "logicRadiator3");            //its name


physRadiator3 =
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(-20*mm, 0, -zRad+b/2*mm+a*mm ),       //-27*mm
                      logicRadiator3,            //its logical volume
                      "physRadiator3",               //its name
                      logicRadiator,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      true);                 //overlaps checking



//4

solidRadiator4 = new G4Tubs("solidRadiator4",16*mm,18*mm,b/2*mm,0,360*degree);


  logicRadiator4 =
    new G4LogicalVolume(solidRadiator4,          //its solid
                        object_mat,           //its material
                        "logicRadiator4");            //its name

physRadiator4 =
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(-60*mm, 0, -zRad+b/2*mm+a*mm ),       //-43*mm
                      logicRadiator4,            //its logical volume
                      "physRadiator4",               //its name
                      logicRadiator,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      true);                 //overlaps checking


//
//Detector
//

  G4double xDet = 50*mm/2;
  G4double yDet = 100*mm/2;
  G4double zDet = 15*mm/2;

solidDetector = new G4Box("solidDetector", 
                            // xWorld/ nRows, 
                            // yWorld/ nCols,
                            xDet,
                            yDet,
                            zDet);

logicDetector = new G4LogicalVolume(solidDetector, 
                                      CsI_Tl,
                                      "logicDetector"); 

for(G4int i = 0; i<1; i++)
{
  G4int X = 1;
  for(G4int j = 0; j<2; j++)
  {
    X *= -1;

    physDetector = new G4PVPlacement(0,
                                    G4ThreeVector(X*(5*mm+xDet), 0, -20*mm+zDet),
                                    logicDetector,
                                    "physDetector",
                                    logicHome,
                                    false,
                                    j,
                                    true);
  }
}

  //always return the physical World
  //
  return physWorld;



}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetCols(G4int Cols)
{
  cols = Cols;
  pos = G4ThreeVector(-80*mm + 1*(cols*2-1)*mm, 0*mm, zRad );
  physRadiator->SetTranslation(pos);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
