

//$583

//$283
//echelon
//34 works
//32
//22
//#define SIZE 22
// why does define not need a type?
//alternate global var
class Board{
  public:
      Board();
      ~Board();
      void display();
      
      friend ostream & operator<<(ostream & out, Board object);

      void placeCharacter(int characterNumber);
      void newCharacter(string name,int attkDamage,int health,string species);
      void displayName(int characterNum);
      void itemFound(int characterNum, string itemName);
      void displayItems(int characterNum);
      void displayCharCoord(int characterNum)const;
      void displaySpells(int characterNum);
      boolean inWoods;
      void displayStats(int characterNumber);
      void updatePosition(int characterNum, char directionMoved);
      void displayAllChars()const;
      void castSpell(int characterNum, int selectionValue);
      void takeDamage(int characterNum, int damageAmount);
    
      boolean inWater;
      
  private:
      vector<Character*> Monsters;
      static const int SIZE = 28;
      char theBoardGraphics[SIZE][SIZE];
      char theBoardGraphicsChar[SIZE][SIZE];
      int theBoard[SIZE][SIZE];
      boolean counterSwitch; 
};

ostream & operator<<(ostream & out,const Board object){
  out << object.SIZE;
  
  return out;
}

Board::Board(){
    counterSwitch = 0;
    boolean inWoods = false;
    boolean inWater = false;
    
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < SIZE; j++){
            theBoard[i][j] = 0;
        }
    }
    for(int i =0;i < 5; i ++){
        for(int j = 0; j < 6; j++){
         theBoard[j][i] = 7;
        } 
    }
    for(int i =4;i < 10; i ++){
        for(int j = 20; j < SIZE-4; j++){
            theBoard[j][i] = 7;
        }
    }
    for(int i =4;i < 10; i ++){
        for(int j = 20; j < SIZE-4; j++){
            theBoard[i][j] = 7;
        }
    }
    for(int i =15;i < SIZE-7; i ++){
        for(int j = 0; j < 6; j++){
            theBoard[i][j] = 7;
        }
    }
    int colDiag  = 15;
    for(int i =colDiag;i < SIZE; i ++){
            theBoard[i][colDiag] = 6;
        colDiag++;
    }
    colDiag  = 0;
    for(int i =colDiag;i < SIZE-18; i ++){
        
        theBoard[0][colDiag] = 6;
        colDiag++;

        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                theBoardGraphics[i][j] = ' ';  
            }
        }
        for(int i =0;i < 5; i ++){
            for(int j = 0; j < 6; j++){
                theBoardGraphics[j][i] = '^';
            }
        }
        for(int i =4;i < 10; i ++){
            for(int j = 20; j < 28; j++){
                theBoardGraphics[j][i] = '^';
            }
            
        }
        for(int i =4;i < 10; i ++){
            for(int j = 20; j < 28; j++){
                theBoardGraphics[i][j] = '^';
            }
        }
        for(int i =15;i < 25; i ++){
            for(int j = 0; j < 6; j++){
                theBoardGraphics[i][j] = '^';
            }
        }
        int colDiag  = 15;
        for(int i =colDiag;i < 32; i ++){
            theBoardGraphics[i][colDiag] = 'W';
            colDiag++;
        }
        colDiag  = 0;
        for(int i =colDiag;i < 14; i ++){
            theBoardGraphics[0][colDiag] = 'W';
            colDiag++;
        }
    }
    //full circle
    //22 is clouds
    //9 is water
    //0 is earth
    //5 is item
    //8 is player
    //7 is tree if player in 7'z "Trees all around, feelzz at home";
    //if next to tree there is a the dark wood to the west. skin prickles
    //at the sound of dire wolves
    //winter hoar frost etched into every crack in our armor. Contracting the
    // metal tight around our shivering frames.
    //fluid oozed from [name]'s wounds pustuls still raw from, the trek accross the grand scheme
    //leather doesn't make a good travel companion..
}


void Board::takeDamage(int characterNum, int damageAmount){
 Monsters[characterNum]->takeDamage(damageAmount); 
}

void Board::displayItems(int characterNum){
  Monsters[characterNum] -> displayItems();
  
}

void Board::displayName(int characterNum){
  Monsters[characterNum]->displayName();

}

void Board::displaySpells(int characterNum){
  Monsters[characterNum] -> displaySpells();
}

void Board::castSpell(int characterNum, int selectionValue){
  cout << endl;
  Monsters[characterNum] -> displayName();
  cout << " casts " << Monsters[characterNum]->castSpell(selectionValue) << "!"<< endl;
  cout << "-----------------------" << endl;
  delay(2000);
  cout << "An eerie green light creeps from the book and hangs in the air about you.." << endl;
  delay(3000);
  cout << "You feel strange..." << endl;
  delay(3000);
  cout << "..did you always have horns?" << endl;
  delay(3000);
  this -> display();
}
void Board::placeCharacter(int characterNumber){
    long randRow;
    long randCol;
    inWoods = false;
    randomSeed(analogRead(0));
    randRow = random(0, SIZE);
    randCol = random(0, SIZE);
    theBoard[randRow][randCol] = 1;
    Monsters[characterNumber] -> setCoord(randRow,randCol);
    /*
    for(int i = randCol-1; i <= randCol+1; i++){
        if (theBoard[randRow-1][i] == 7)
            inWoods = true;
        if (theBoard[randRow-1][i] == 6)
            inWater = true;
        //#############
        //what your character encounters is in the elements imidiatly around them
        //this checks all the surrounding elements
        //#############
        //theBoard[randRow-1][i] = 3;
    }
    for(int i = randCol-1; i <= randCol+1; i++){
        if (theBoard[randRow][i] == 7)
            inWoods = true;
        if (theBoard[randRow][i] == 6)
            inWater = true;
        if (theBoard[randRow][i] == 1);
        //else
    }
    for(int i = randCol-1; i <= randCol+1; i++){
        
        if (theBoard[randRow+1][i] == 7)
            inWoods = true;
        if (theBoard[randRow+1][i] == 6)
            inWater = true;
        //theBoard[randRow+1][i] = 3;
    } */
}
void Board::displayStats(int characterNumber){
  Monsters[characterNumber]->displayStats();
}

void Board::display(){
  
   for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                theBoardGraphics[i][j] = ' ';    
            }
        }
        for(int i =0;i < 5; i ++){
            for(int j = 0; j < 6; j++){
                theBoardGraphics[j][i] = '^';
            }
        }
        for(int i =4;i < 10; i ++){
            for(int j = 20; j < 28; j++){
                theBoardGraphics[j][i] = '^';
            }  
        }
        for(int i =4;i < 10; i ++){
            for(int j = 20; j < 28; j++){
                theBoardGraphics[i][j] = '^';
            }  
        }
        for(int i =15;i < 25; i ++){
            for(int j = 0; j < 6; j++){
                theBoardGraphics[i][j] = '^';
            }
        }
        int colDiag  = 15;
        for(int i =colDiag;i < 32; i ++){
            
            theBoardGraphics[i][colDiag] = 'W';
            colDiag++;
        }
        colDiag  = 0;
        for(int i =colDiag;i < 14; i ++){
            theBoardGraphics[0][colDiag] = 'W';
            colDiag++;
        }
  /*
    cout << endl;
    cout << endl;
    
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout << theBoard[i][j] << " ";
        }
        cout << endl;
        }
        
        */
    cout << endl;
    cout << endl;
    
    char tempSymbol = 'å';
    //this is not setting the board just outputing graphics
    for(int i; i< Monsters.size();i++){
      int newRow = Monsters[i]-> returnRow();
      int newCol= Monsters[i]-> returnCol();
    
    
      if ( (*Monsters[0]).areWeSheep() ){
        tempSymbol ='g';
      }
      
      else{
        switch(i){
          case 0:
             tempSymbol='T';
            break;
          case 1:
            tempSymbol='D';
            break;
          case 2:
             tempSymbol='K';
            break;
          case 3:
            tempSymbol='R';
            break;
          case 4:
            tempSymbol = 'G';
            break;
          case 5:
            tempSymbol = 'V';
            break;
          case 6:
            tempSymbol = 'M';
            break;  
      }
      
      }
      theBoardGraphics[newRow][newCol] = tempSymbol;
    }
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout << theBoardGraphics[i][j] << " "; 
        }
        cout << endl;
    }
    
      if((*Monsters[0]).areWeSheep() && counterSwitch == 0){
    for(int i = 0; i < Monsters.size(); i++){
        Monsters[i]->displayName();
        cout << " is now a goat" << endl;
    }
    cout << endl;
     counterSwitch++;
  }

    if (inWoods == true)
        cout << "The woods are near..";
    
    if (inWater == true)
        cout << "A Brook gurgles nearby..spirits are lifted";
     cout << endl;
     inWater = false;
     inWoods = false;
            
    }
void Board::newCharacter(string name,int attkDamage, int health, string species){
    Monsters.push_back(new Character (name,attkDamage, health, species));
}


Board:: ~Board(){
  for(int i = 0; i < Monsters.size(); i++)
      delete Monsters[i];
      Monsters.clear();
}

void Board::displayCharCoord(int characterNum)const{
  //Monsters[characterNum]-> displayName();
  cout << " ";
  cout << "[";
  cout << Monsters[characterNum]-> returnRow();
  cout << ",";
  cout << Monsters[characterNum]-> returnCol();
  cout << "]";
}
void Board::displayAllChars()const{
  for(int i = 0; i<Monsters.size(); i++){
  cout << "[" << i << "] ";
  Monsters[i]-> displayName();
  cout << " ";
  cout << "[";
  cout << Monsters[i]-> returnRow();
  cout << ",";
  cout << Monsters[i]-> returnCol();
  cout << "]";
  cout << endl;
  }
}



void Board::updatePosition(int characterNum, char directionMoved){
  switch(directionMoved){
    case'w': 
      Monsters[characterNum] -> updatePos('r', -1);
      //row -1 set new position
      break;
    case 'd':
       Monsters[characterNum] -> updatePos('c', 1); 
      //col +1 set new position
    break;
    case 's':
    case 'x':
    Monsters[characterNum] -> updatePos('r', 1); 
    //row +1 set new position
    break;
    case 'a':
    Monsters[characterNum] -> updatePos('c', -1); 
      //col -1 set new position
    break;
  }
  int threatLevelPerecent = 10;
  int surpriseAttack = random(1, 100);

  int randRow = Monsters[characterNum]-> returnRow();

  int randCol = Monsters[characterNum]-> returnCol();
  for(int i = randCol-1; i <= randCol+1; i++){
        if (theBoard[randRow-1][i] == 7){
            threatLevelPerecent = 30;
            inWoods = true;
        }
        if (theBoard[randRow-1][i] == 6){
            inWater = true;
            threatLevelPerecent = 0;
        }
        //#############
        //what your character encounters is in the elements imidiatly around them
        //this checks all the surrounding elements
        //#############
        //theBoard[randRow-1][i] = 3;
    }
    for(int i = randCol-1; i <= randCol+1; i++){
        if (theBoard[randRow][i] == 7){
            threatLevelPerecent = 30;
            inWoods = true;
        }
        if (theBoard[randRow][i] == 6){
            inWater = true;
            threatLevelPerecent = 0;
        }
        if (theBoard[randRow][i] == 1);
        //else
    }
    for(int i = randCol-1; i <= randCol+1; i++){
        
        if (theBoard[randRow+1][i] == 7){
            threatLevelPerecent = 30;
            inWoods = true;
        }
        if (theBoard[randRow+1][i] == 6){
            inWater = true;
            threatLevelPerecent = 0;
        }
        //theBoard[randRow+1][i] = 3;
    } 

  this -> display();
  
  if(surpriseAttack > 100-threatLevelPerecent){
    cout << endl;
    cout << "\"Guard up travler, wolves are upon you\"" << endl;
    unsigned char damageAmount = random(1, 20);
    int health = Monsters[characterNum]->takeDamage(damageAmount);
    Monsters[characterNum]->displayName();
    cout << " takes " << (int)damageAmount << " damage." << endl;
    cout << "Health is at " << health << endl;
    
    cout << endl;
  }
  int tempMonsterR;
  int tempMonsterC;
  for(int i = 0; i < Monsters.size(); i++){
     tempMonsterR = Monsters[i]-> returnRow();
     tempMonsterC = Monsters[i]-> returnCol();
     if(characterNum == i);
     else if(tempMonsterR == randRow && tempMonsterC == randCol){
       Monsters[i]-> displayName();
       cout << " says, ";
       if((*Monsters[0]).areWeSheep()){
         cout << "\"Baah bahh baah!\"" << endl << endl;
         cout << "\"baa..";  
       }
       else{
         cout << "\"What's up bro!\"" << endl << endl;
         cout << "\"What's the deal ";
       }
       Monsters[characterNum]-> displayName();
       cout << "?\"";
       cout << endl << endl;
     }
  } 
}

void Board::itemFound(int characterNum, string itemName){
    Monsters[characterNum] -> recieveItem(itemName);
}

//start of main due to compiler errors..grr

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

Board theBoard;



void displayOptions(){
  //cout << "[x] to attack" << endl;
  cout << "[c] cast a spell" << endl;
  cout << "[i] to view inventory" << endl;
  cout << "[v] to display stats" << endl;
  cout << "[n] choose new character" << endl;
}



void setup(){

  Serial.begin(57600);
  
  //cout << theBoard;
  // when instantiating a constructor with no
  // arguments you must remember NO () so Character moon() is fail..
  /*
  single address variable
  Character * monsterT;
  Character moon;
  monsterT = &moon;
  
  */
  string item = "Golden Chalice";
  string item2 = "Red Heart";
  //string item3 = "Brain Weavle";
  //string item4 = "Hex Weavle";
  string item5 = "Dream Weavle";
  string item6 = "Violin String";
  //string item7 = "Instrument, Oud";
  theBoard.newCharacter("Thom",13, 100, "Gawker");
  theBoard.newCharacter("Dr. Hearts",14, 100, "MD(Terror)");
  theBoard.newCharacter("Kitty Attack",13, 100, "Dread-Kitten");
  //theBoard.newCharacter("Mr. Red",28, 50, "Angry-Heart");
  theBoard.newCharacter("Gohst Rider",14, 100, "Spirit");
  //theBoard.newCharacter("Mona",12, 100, "Primate");
  theBoard.newCharacter("Violet",12, 100, "Troglydyte");
  theBoard.itemFound(0, item);
  theBoard.itemFound(1, item2);
  theBoard.itemFound(0, item5);
  theBoard.itemFound(1, item6);
  
  
  //theBoard.newCharacter("Camile",12, 100, "veija");
  //theBoard.newCharacter("Mr. Grr",13, 100, "Dread-Kitten");
  //theBoard.newCharacter("Violet",12, 100, "Troglydyte");
  int character1Num = 0;//Thom
  int character2Num = 1;//Dr. Hearts
  //cout << SIZE;
  int delayCount = 4;
  theBoard.placeCharacter(0);
  delay(delayCount);
  theBoard.placeCharacter(1);
  delay(delayCount);
  theBoard.placeCharacter(2);
  delay(delayCount);
  theBoard.placeCharacter(3);
  delay(delayCount);
  theBoard.placeCharacter(4);
  delay(delayCount);
  theBoard.placeCharacter(5);
  delay(delayCount);
  theBoard.placeCharacter(6);
  cout << "Loading..";
  delay(2000);
  cout << "Intializing vectors.." << endl;
  delay(2000);
  cout << "Loading maps.." << endl;
  delay(2000);
  cout << "Restocking goat pens.." << endl;
  delay(2000);
  cout << "Clearing harlots and hounds.." << endl;
  delay(2000);
  cout << "Continuing to clear harlots and hounds.." << endl;
  delay(2000);
  cout << "..This may take a while.." << endl;
  delay(2000);
  //cout << "He who knows when he can fight and when he cannot, will be victorious." << endl;
  //delay(4000);
  cout << "Welcome to \"ECHELON\"" << endl << endl;
  delay(2000);
  
  theBoard.display();

  cout << "Starting map as, Thom" << endl;
  cout << endl;
  displayOptions();
  /*
  cout << "-----------------------" << endl;
  theBoard.displayAllChars();
  cout << "-----------------------";
  */
 
  //theBoard.itemFound(0, item2);
  //theBoard.itemFound(1, item5);
}/*
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
  cout << "[s] to surrender" << endl;}
*/
//by setting the type of what Serial.read() is
//You can control the type of input that is comming in.
// thus setting incomingByte to int or char or double will effect the var comming in.
//why the hell should it have worked at all!!!!
char incomingByteChar;
char characterId = 1;
int tempVal = 0;
boolean characterMenu = false;
int selectionVal;
boolean spellMenu = false;




void loop(){
  if(Serial.available() > 0){
    incomingByteChar = Serial.read();
    //cout << "Data recieved" << endl;
    //cout << incomingByteChar << endl; 
    if ((incomingByteChar == 'w' || incomingByteChar == 'd' || incomingByteChar == 's' || incomingByteChar == 'a') && !characterMenu && !spellMenu){
      theBoard.updatePosition(tempVal,incomingByteChar);

      theBoard.displayName(tempVal);
      cout << " moves to";
      theBoard.displayCharCoord(tempVal);
      cout << " enjoy the new scenery..";
      cout << endl;
      cout << endl;
      displayOptions();
     
    }
    
    else if(incomingByteChar =='i' && !characterMenu && !spellMenu){
      theBoard.displayItems(tempVal);
      
    }
    else if(incomingByteChar =='c' && !characterMenu && !spellMenu){
      cout << endl;
      cout << "Retrieving spell book.." << endl;
      cout << endl;
      delay(1000);
      theBoard.displaySpells(tempVal);
      spellMenu = true;
      
    }
    
    else if(incomingByteChar =='v' && !characterMenu && !spellMenu){
      theBoard.displayStats(tempVal);
      
    }
    else if(incomingByteChar == 'n' && !characterMenu && !spellMenu){
     cout << endl;
     cout << endl;
     cout << "Which character do you wish to move?" << endl;
     cout << "------------------------------------" << endl;
     theBoard.displayAllChars(); 
     cout << "------------------------------------" << endl;
     characterMenu = true;
    }
    
    
    if(!spellMenu && characterMenu == true && (incomingByteChar == '0' ||incomingByteChar == '1' ||incomingByteChar == '2' ||incomingByteChar == '3'||incomingByteChar == '4'||incomingByteChar == '5'||incomingByteChar == '6')){
      switch(incomingByteChar){
         case '0':
             tempVal = 0;
             break;
         case '1':
             tempVal =1;
             break;            
         case '2':
             tempVal = 2;
             break;
         case '3':
             tempVal = 3;
             break;
         case '4':
             tempVal = 4;
             break;
         case '5':
             tempVal = 5;
             break;     
         case '6':
             tempVal = 6;
             break;  
     }
     theBoard.display();
     cout << "You chose ";
     theBoard.displayName(tempVal);
     theBoard.displayCharCoord(tempVal);
     cout << " proceed with care..." << endl << endl;
     
     displayOptions();
    
     characterMenu = false;
     }//end character select if statement
     
     
      if(!characterMenu && spellMenu == true && (incomingByteChar == '0' ||incomingByteChar == '1' ||incomingByteChar == '2' ||incomingByteChar == '3'||incomingByteChar == '4'||incomingByteChar == '5'||incomingByteChar == '6')){
      switch(incomingByteChar){
         case '0':
             selectionVal = 0;
             break;
         case '1':
             selectionVal =1;
             break;            
         case '2':
             selectionVal = 2;
             break;
         case '3':
             selectionVal = 3;
             break;
         case '4':
             selectionVal = 4;
             break;
         case '5':
             selectionVal = 5;
             break;     
         case '6':
             selectionVal = 6;
             break;  
     }
     theBoard.castSpell(tempVal, selectionVal);
     
     displayOptions();

     
     spellMenu = false;
     
     }
       
  } // end Serial.avrailable();
}
