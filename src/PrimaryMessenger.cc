

#include "PrimaryGeneratorAction.hh"
#include "PrimaryMessenger.hh"

#include "G4UIdirectory.hh"

#include "G4UIcmdWithADoubleAndUnit.hh"

namespace B1{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryMessenger::PrimaryMessenger(PrimaryGeneratorAction* Det)
 : fPrimaryGeneratorAction(Det)
{
  fB1Directory = new G4UIdirectory("/B1/");
  fB1Directory->SetGuidance("UI commands specific to this example.");

  fDetDirectory = new G4UIdirectory("/B1/det/");
  fDetDirectory->SetGuidance("PrimaryGenerator  control");

  fRowsCmd = new G4UIcmdWithADoubleAndUnit("/B1/det/setRows",this);
  fRowsCmd->SetGuidance("Define   rows ");
  fRowsCmd->SetParameterName("Rows",false);

  fRowsCmd->SetUnitCategory("Length");//长度单位
  fRowsCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryMessenger::~PrimaryMessenger()
{
  delete fRowsCmd;
  delete fB1Directory;
  delete fDetDirectory;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{
  if( command == fRowsCmd ) {
    fPrimaryGeneratorAction
      ->SetRows(fRowsCmd->GetNewDoubleValue(newValue));
  }   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
}