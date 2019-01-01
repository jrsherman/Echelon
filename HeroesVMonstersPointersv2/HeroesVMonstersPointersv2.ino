#include <TheBoard.h>


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
int led = 9;
int led2 = 10;
string incomingByte = 0; 




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
  
  
  Board theBoard;
  
  theBoard.display();
  theBoard.placeCharacter();
  
  theBoard.display();
  
  
  
  theBoard.placeCharacter();
  theBoard.display();
  
  
  theBoard.placeCharacter();
  theBoard.display();
  


 
 cout << endl;
 cout << endl;
 cout << "  |------|" << endl;
 cout << "|--\\----/--|" << endl;
 cout << "|__O____O__|" << endl;
 cout << " |--^  ^--| " << endl;
 cout << "  |--==--|" << endl;
 cout << endl;
 cout << endl;
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

 if (Serial.available() > 0) {
       
    incomingByte = Serial.read();
    int b = atoi(incomingByte.c_str());
    /*
    if(b >=0 && b < Monsters.size())
      Monsters[b]->displayStats();
    
    */
        
    if(incomingByte == "f"){

       monsterFight();
                     
        }
        
        cout << endl;
        }

}




