#include <iostream>
#include <fstream>
#include <sstream>
#include "robot_part.h"
#include "utility.h"
using namespace std;

int main() {
   
  Head *head;
  Arm *arm;
  Torso *torso;
  Locomotor *locomotor;
  Battery *battery;

  ifstream ist{"robot_part_test_vectors.txt"};
  int object = 0;  // count test objects for error msgs

  while(!ist.eof()) {
    ++object;
    string expected;
    ostringstream oss;
    switch (get_int(ist)) {
      case 0: // Exit
        exit(0);
      case 1: // Head
        head = new Head{
          get_string(ist),
          get_int(ist),
          get_double(ist),
          get_string(ist),
          get_double(ist)
        };
        expected = get_string(ist) + '\n' + get_string(ist); 
        oss << *head;
        if (oss.str() != expected) {
          cerr << "FAIL: (Head) Object " << object << endl;
          cerr << "Expected:" << endl << expected << endl;
          cerr << "Created:" << endl << oss.str() << endl;
        }
        break;
      case 2:
        arm = new Arm{
          get_string(ist),
          get_int(ist),
          get_double(ist),
          get_string(ist),
          get_double(ist)
        };
        expected = get_string(ist) + '\n' + get_string(ist); 
        oss << *arm;
        if (oss.str() != expected) {
          cerr << "FAIL: (Arm) Object " << object << endl;
          cerr << "Expected:" << endl << expected << endl;
          cerr << "Created:" << endl << oss.str() << endl;
        }
        break;
      case 3:
        torso = new Torso{
          get_string(ist),
          get_int(ist),
          get_double(ist),
          get_string(ist),
          get_int(ist),
          get_int(ist)
        };
        expected = get_string(ist) + '\n' + get_string(ist); 
        oss << *torso;
        if (oss.str() != expected) {
          cerr << "FAIL: (Torso) Object " << object << endl;
          cerr << "Expected:" << endl << expected << endl;
          cerr << "Created:" << endl << oss.str() << endl;
        }
        break;
      case 4:
        locomotor = new Locomotor{
          get_string(ist),
          get_int(ist),
          get_double(ist),
          get_string(ist),
          get_double(ist),
        };
        expected = get_string(ist) + '\n' + get_string(ist); 
        oss << *locomotor;
        if (oss.str() != expected) {
          cerr << "FAIL: (Locomotor) Object " << object << endl;
          cerr << "Expected:" << endl << expected << endl;
          cerr << "Created:" << endl << oss.str() << endl;
        }
        break;
      case 5:
        battery = new Battery{
          get_string(ist),
          get_int(ist),
          get_double(ist),
          get_string(ist),
          get_double(ist),
          get_double(ist),
        };
        expected = get_string(ist) + '\n' + get_string(ist); 
        oss << *battery;
        if (oss.str() != expected) {
          cerr << "FAIL: (Battery) Object " << object << endl;
          cerr << "Expected:" << endl << expected << endl;
          cerr << "Created:" << endl << oss.str() << endl;
        }
        break;
      default:
        cerr << "Impossible menu selection ===" << endl << endl;
    }
  }
}
