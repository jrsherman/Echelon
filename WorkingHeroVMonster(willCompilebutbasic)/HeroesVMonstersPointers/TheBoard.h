
//

#ifndef ____TheBoard__
#define ____TheBoard__


#include "Arduino.h"
//#include <CharacterClass.h>




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
    
    
    
    private:
    int theBoard[32][32];
    
    //vector<CharacterClass*> MonstersT;
    //int theBoard[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    
    
    //how many data players are in game?? vector of players?

    
};













#endif /* defined(____TheBoard__) */
