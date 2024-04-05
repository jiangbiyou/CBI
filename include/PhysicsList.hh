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
/// \file PhysicsList.hh
/// \brief Definition of the B3::PhysicsList class

#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VModularPhysicsList.hh"

// namespace B1
// {

/// Modular physics list
///
/// It includes the folowing physics builders
/// - G4DecayPhysics
/// - G4RadioactiveDecayPhysics
/// - G4EmStandardPhysics

class PhysicsList: public G4VModularPhysicsList
{
public:
  PhysicsList();
  ~PhysicsList() override;

  void SetCuts() override;
};



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif








//
// Created by wangm on 17-8-7.
//

// #ifndef PHYSICSLIST_h
// #define PHYSICSLIST_h 1

// #include "G4VUserPhysicsList.hh"
// #include "globals.hh"

// class OpNovicePhysicsListMessenger;

// class G4Cerenkov;
// class G4Scintillation;
// class G4OpAbsorption;
// class G4OpRayleigh;
// class G4OpMieHG;
// class G4OpBoundaryProcess;

// class PhysicsList: public G4VUserPhysicsList
// {
// public:
//     PhysicsList();
//     ~PhysicsList();

// public:
//     virtual void ConstructParticle();
//     virtual void ConstructProcess();
//     virtual void SetCuts();
//     void ConstructDecay();
//     void ConstructEM();
//     void ConstructOp();
//     void ConstructHadron();
//     void ConstructNuclear();
// };

// #endif
