
#include "TheBoard.h"
//#include <CharacterClass.h>






Board::Board(){
    
    
    //vector<CharacterClass*> MonstersT;
    
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            theBoard[i][j] = 0;
            
        }
  
    }
    
    
    
    
   theBoard[32][32];
    
    
    
    
}

void Board::placeCharacter(){
    long randNumber1;
    long randNumber2;
    
    
    randomSeed(analogRead(0));
    randNumber1 = random(0, 32);
    //cout << randNumber1 << endl;
    
    randNumber2 = random(0, 32);
    //cout << randNumber2;
    
    theBoard[randNumber1][randNumber2] = 1;
    
    
    
    
}
void Board::display()const{
    cout << endl;
    cout << endl;
    
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            cout << theBoard[i][j] << " ";
            
            
        }
        cout << endl;
        }
    
     cout << endl;
     cout << endl;
            
    }
 