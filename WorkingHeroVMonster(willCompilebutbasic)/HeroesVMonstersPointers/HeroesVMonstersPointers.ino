
#include "CharacterClass.h"
#include "TheBoard.h"
#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <serstream>
#include <vector>
#include <string>
#include <iterator>
#include<iomanip>





int led = 9;
int led2 = 10;
string incomingByte = 0; 

vector<CharacterClass*> Monsters;
Board theBoard;

//vector<CharacterClass> Monsters;

//using pointers saves memory by not creating coppies
//of the monsters
//with pointers addressed to newly allocated memory
//less memory is used.

//once you begin using a vector of pointers you can no longer use the . operator
// to refer to your member functions of that pointer array of objects.
// the correct protocol is ->
// another way is (*pointervecorts).memberfunction;
void setup(){

  delay(10);
  
  
  Serial.begin(57600);
  




  
  // I want to pass in heros as arguments into the board.
  //Then call a member function of the board that accesses the vector of character objects
  //display stats will also be easily refered to in the board.
  
  
  //when place character is called a random number on the array will be found 
  // at that point a member variable of that character will be set to keep that chars coordinates.
  
  //vector<CharacterClass> Heroes;
  

  // when instantiating a constructor with no
  // arguments you must remember NO () so Character moon() is fail..
  
  
  /*
  single address variable
  CharacterClass * monsterT;
  CharacterClass moon;
  
  
  monsterT = &moon;
  
  */
  
  
  
  cout << "Starting Map" << endl << endl;
  theBoard.display();
  
  
  
  
  theBoard.placeCharacter();
  
  theBoard.display();
  
  
  
  theBoard.placeCharacter();
  theBoard.display();
  
  
  theBoard.placeCharacter();
  theBoard.display();
  
  
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
  
  string item7 = "Instrument, Oud";
  
  
  //cout << "Thom recieved a " << item << endl;
  Monsters[0]->recieveItem(item);
  Monsters[1]->recieveItem(item2);
  
  Monsters[1]->recieveItem(item7);
  
  Monsters[1]->recieveItem(item3);
  Monsters[4]->recieveItem(item4);
  Monsters[4]->recieveItem(item6);
  
  //Monsters[0]->displayItems(); 
  //Monsters[1]->displayItems();  
  //Monsters[4]->displayItems();  
 
 cout << "Choose Your Monster:" << endl;
 cout << "-------------------" <<endl;

 for(int i = 0; i < Monsters.size(); i ++){
    cout << "["<< i << "] "<< Monsters[i]->name << endl;
 }
 cout << "-------------------" <<endl;
 /*
 
 cout << endl;
 cout << endl;
 cout << "  |------|" << endl;
 cout << "|--\\----/--|" << endl;
 cout << "|__O____O__|" << endl;
 cout << " |--^  ^--| " << endl;
 cout << "  |--==--|" << endl;
 cout << endl;
 cout << endl;*/
}

void monsterFight(){
  delay(500);
  analogWrite(led,255);
  delay(500);
  analogWrite(led,0);
  delay(500);
  analogWrite(led,255);
  delay(500);
  analogWrite(led,0);
  delay(500);
  
  cout << "Which two monsters will fight!!" << endl;
  cout << "---------------------------------" << endl;
  cout << "[r] to retreat" << endl;
  cout << "[a] to attack" << endl;
  cout << "[d] to defend" << endl;
  cout << "[n] to negotiate" << endl;
  cout << "[s] to surrender" << endl;
}

void loop(){
    string incomingByte1;
 if (Serial.available() > 0) {
       
    incomingByte = Serial.read();
    int b = atoi(incomingByte.c_str());
    if(b >=0 && b < Monsters.size()){
      Monsters[b]->displayStats();
    cout << endl;
    cout << endl;
    Serial.flush();
    cout << "[0] for item list" << endl << endl;
    cout << "(e to exit)";
    
    
    
    while(!(Serial.available())){
      
      if (Serial.available() > 0){
        
        
        incomingByte1 = Serial.read();
        
        if(incomingByte1 == "0"){
          Monsters[b]->displayItems();
          Serial.flush();
          break;
        }
        else if(incomingByte =="e"){
            Serial.flush();
            break;
        }
      }
      
     
      
      
      
      
    }
    
    }
    
        
    if(incomingByte == "f"){

       monsterFight();
                     
        }
        
        
     if(incomingByte == "d"){

       theBoard.display();
                     
        }
        
        cout << endl;
        }
Serial.flush();
}




