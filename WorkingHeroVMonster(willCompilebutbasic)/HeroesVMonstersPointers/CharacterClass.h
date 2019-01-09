

#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <serstream>

#include <vector>
#include <string>
#include <iterator>
using namespace std;








#include "Arduino.h"


class CharacterClass{
    
    public:
        CharacterClass();
        CharacterClass(string monsterName,double damageCapable,double healthPoints,string species);
        void recieveItem(string itemName);
        //const in the initializer list to keep this from being altered in that member function.
        void displayItems()const;
        void displayStats()const;
        string name;
    
        
        
        
    
    
    
    private:
        
        double health;
        double damage;
        double breathLimit;
        string attackMoves[4];
    
        string species;
    
        
    
        string slots[5];
        vector <string> items;
        
      
    
    
};
