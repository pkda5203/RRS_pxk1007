#include <iostream>
#include "robot_part.h"
#include "utility.h"
using namespace std;

int main() {
   
  Head *head;
  Arm *arm;
  Torso *torso;
  Locomotor *locomotor;
  Battery *battery;

  while(true) {
    switch (get_int(R"(
   Testing Robot Parts

(1) Create Head
(2) Create Arm
(3) Create Torso
(4) Create Locomotor
(5) Create Battery
(0) Exit

Selection? )", 0, 5)) {

      case 0: // Exit
        exit(0);
      case 1: // Head
        head = new Head{
          get_string("Enter this head's name: "),
          get_int("Enter this head's model number: "),
          get_double("Enter this head's cost: "),
          get_string("Enter description: "),
          get_double("Enter this head's power: ")
        };
        cout << *head << endl;
        break;
      case 2:
        arm = new Arm{
          get_string("Enter this arm's name: "),
          get_int("Enter this arm's model number: "),
          get_double("Enter this arm's cost: "),
          get_string("Enter description: "),
          get_double("Enter maximum power: ")
        };
        cout << *arm << endl;
        break;
      case 3:
        torso = new Torso{
          get_string("Enter this torso's name: "),
          get_int("Enter this torso's model number: "),
          get_double("Enter this torso's cost: "),
          get_string("Enter description: "),
          get_int("Enter maximum # of arms (0 to 2): ", 0, 2),
          get_int("Enter maximum # of batteries (1 to 3): ", 1, 3)
        };
        cout << *torso << endl;
        break;
      case 4:
        locomotor = new Locomotor{
          get_string("Enter this locomotor's name: "),
          get_int("Enter this locomotor's model number: "),
          get_double("Enter this locomotor's cost: "),
          get_string("Enter description: "),
          get_double("Enter maximum power: ")
        };
        cout << *locomotor << endl;
        break;
      case 5:
        battery = new Battery{
          get_string("Enter this battery's name: "),
          get_int("Enter this battery's model number: "),
          get_double("Enter this battery's cost: "),
          get_string("Enter description: "),
          get_double("Enter maximum energy: "),
          get_double("Enter power available: ")
        };
        cout << *battery << endl;
        break;
      default:
        cerr << "Impossible menu selection ===" << endl << endl;
    }
  }
}
