
#include "TheBoard.h"







Board::Board(){
    
    
    //vector<CharacterClass*> MonstersT;
    
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            theBoard[i][j] = 0;
            
        }
  
    }
    
    
    
    
   theBoard[32][32];
    
    
    
    
}


void Board::newCharacter(string name,int attack, health, string species){
    
    
    
    Monsters.push_back(new CharacterClass ("Thom",13, 100, "Gawker"));
    Monsters.push_back(new CharacterClass ("Monique",12, 100, "Primate"));
    Monsters.push_back(new CharacterClass ("Dr. Hearts",14, 100, "MD(Terror)"));
    Monsters.push_back(new CharacterClass ("Kitty Attack",13, 100, "Dread-Kitten"));
    Monsters.push_back(new CharacterClass ("Mr. Red",28, 50, "Angry-Heart"));
    Monsters.push_back(new CharacterClass ("Gohst Rider",14, 100, "Spirit"));
    Monsters.push_back(new CharacterClass ("Mona",12, 100, "Primate"));
    Monsters.push_back(new CharacterClass ("Mr. Grr",13, 100, "Dread-Kitten"));
    
    
    
    
    string item = "Golden Chalice";
    string item2 = "Red Heart";
    string item3 = "Brain Weavle";
    string item4 = "Hex Weavle";
    string item5 = "Dream Weavle";
    
    string item6 = "Violin String";
    cout << "Thom recieved a " << item << endl;
    Monsters[0]->recieveItem(item);
    Monsters[1]->recieveItem(item2);
    Monsters[1]->recieveItem(item3);
    Monsters[4]->recieveItem(item4);
    Monsters[4]->recieveItem(item6);
    
    Monsters[0]->displayItems();
    Monsters[1]->displayItems();
    Monsters[4]->displayItems();
    
    
    
    
    
    
    
    cout << "Choose Your Monster:" << endl;
    cout << "-------------------" <<endl;
    
    for(int i = 0; i < Monsters.size(); i ++){
        cout << "["<< i << "] "<< Monsters[i]->name << endl;
    }
    cout << "-------------------" <<endl;
    
    
    
    
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
 