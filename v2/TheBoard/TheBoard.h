
//

#ifndef ____TheBoard__
#define ____TheBoard__

#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <serstream>
#include <vector>
#include <string>
#include <iterator>
#include<iomanip>


#include <CharacterClass.h>


#include "Arduino.h"





#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <serstream>

#include <vector>
#include <string>
#include <iterator>
using namespace std;




class Board{
    public:
    Board();
    void display()const;
    void placeCharacter();
    void newCharacter(string name,int attack, int health, string species);
    
    
    
    private:
    int theBoard[32][32];
    CharacterClass foo;
    //vector<CharacterClass*> Monsters;
    //int theBoard[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    
    
    //how many data players are in game?? vector of players?

    
};













#endif /* defined(____TheBoard__) */
