#include "CharacterClass.h"



namespace std

{
    
    ohserialstream cout(Serial);
    
}






CharacterClass::CharacterClass(){
    
    
    health = 100;
    damage = 2;
    breathLimit = 5.0;
    name = "John";
    attackMoves[0] = "Leaches";
    attackMoves[1] = "Gasper Gun";
    attackMoves[2] = "Pow-wow";
    attackMoves[3] = "Rock Fight";
    
    
    }


CharacterClass::CharacterClass(string monsterName, double damageCapable, double healthPoints, string species){
    
    name = monsterName;
    damage = damageCapable;
    health = healthPoints;
    this->species = species;
    // is there a better way to add these to the attackMoves array??
    attackMoves[0] = "Leaches";
    attackMoves[1] = "Gasper Glider Gun";
    attackMoves[2] = "Pow-wow";
    attackMoves[3] = "Rock Fight";
    
    
    
    
}



void CharacterClass::recieveItem(string itemName){
    items.push_back(itemName);
    
    
    
    
    
}

void CharacterClass::displayItems()const{
    cout << name << " Item list: \n";
    
    
    for(int i= 0; i < items.size(); i ++)
        cout << " "<< items[i] << endl;
    
    cout << endl;
    
    
}
    
    
void CharacterClass::displayStats()const{

    cout << endl;
    cout << "Monster name: \"" << name << "\" "<<endl;
    cout << "Attack Damage: " << (int)damage << endl;
    cout << "Health: " << (int)health << endl;
    cout << "Species: " << species << endl;
    cout << "Attack Moves:" << endl;
    cout << "-------------" << endl;
    for(int i = 0; i < 4; i++){
        cout <<"    "<< attackMoves[i] << endl;
        
    }
    
    
    
}
