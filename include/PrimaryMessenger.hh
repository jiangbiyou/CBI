

#ifndef B1PrimaryMessenger_h
#define B1PrimaryMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"



class G4UIdirectory;

class G4UIcmdWithADoubleAndUnit;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

/// Messenger class that defines commands for B2aDetectorConstruction.
///
/// It implements commands:
/// - /B2/det/setTargetMaterial name
/// - /B2/det/setChamberMaterial name
/// - /B2/det/stepMax value unit
namespace B1{

class PrimaryGeneratorAction;

class PrimaryMessenger: public G4UImessenger
{
  public:
    PrimaryMessenger(PrimaryGeneratorAction* );
    ~PrimaryMessenger() override;

    void SetNewValue(G4UIcommand*, G4String) override;
    
  private:
    PrimaryGeneratorAction*  fPrimaryGeneratorAction =nullptr;

    G4UIdirectory*           fB1Directory =nullptr;
    G4UIdirectory*           fDetDirectory =nullptr;

    // G4UIcmdWithAString*      fTargMatCmd;
    // G4UIcmdWithAString*      fChamMatCmd;

    G4UIcmdWithADoubleAndUnit* fRowsCmd =nullptr;


};

}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

