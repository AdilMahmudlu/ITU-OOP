//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Adil Mahmudlu
//---Student Number: 150200915
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "pokemon.h" 

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it
//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---// 
// 
//
//
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string* readEnemyNames(const char*);
string* readPokemonNames(const char*);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player*, string*, string*);
void catchPokemon(player*, string*);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---// 
//
//
//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
int main(int argc, char* argv[]){
	system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string* enemyNames = readEnemyNames(argv[1]);         
    string* pokemonNames = readPokemonNames(argv[2]);

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n" << endl;
    cout << "Please enter your name: ";
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);
    
    int menuChoice;

    while(true){
        mainMenu(); 
        cin>>menuChoice;

        switch (menuChoice){
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout<<newPlayer.showPokemonNumber()<<endl;
            break;
        case 4:
            cout<<newPlayer.showPokeballNumber()<<endl;
            break;
        case 5:
            cout<<newPlayer.showBadgeNumber()<<endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" <<endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;
  
        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readEnemyNames(const char* argv){
    int number;
    ifstream enemiesFile(argv);
    enemiesFile >> number;
    string* enemyNames = new string[number];
    for (int i = 0; i < number; i++) {
        enemiesFile >> enemyNames[i];
    }
    enemiesFile.close();
    return enemyNames;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readPokemonNames(const char* argv){
    int number;
    ifstream pokemonsFile(argv);
    pokemonsFile >> number;
    string* pokemonNames = new string[number];
    for (int i = 0; i < number; i++) {
        pokemonsFile >> pokemonNames[i];
    }
    pokemonsFile.close();
    return pokemonNames;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice){
    if (pokemonChoice == 1) {
        pokemon A("Bulbasaur", PLAYER_POKEMON_ATTACK);
        return player(playerName, A);
    }
    else if (pokemonChoice == 2) {
        pokemon A("Charmender", PLAYER_POKEMON_ATTACK);
        return player(playerName, A);
    }
    else {
        pokemon A("Squirtle", PLAYER_POKEMON_ATTACK);
        return player(playerName, A);
    }
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu(){
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames){
    int choice;
    pokemon enemyPok(pokemonNames[POK_COUNTER], ENEMY_POKEMON_ATTACK); //create enemy pokemon
    enemy newEnemy(enemyNames[NAME_COUNTER], enemyPok); //create enemy
    newPlayer->playerPokedex.updatePokedex(newEnemy.getPokemon()); //add pokemon to pokedex
    cout << "You encounter with " << newEnemy.getName() << " and his/hers pokemon " << newEnemy.getPokemon().getName() << "\n";
    cout << pokemonNames[POK_COUNTER] << " Health: " << newEnemy.getPokemon().getHP() << " Attack: " << newEnemy.getPokemon().getAtk() << "\n"; 
    do {
        cout << "1- Fight \n2- Runaway \nChoice: ";
        cin >> choice;
        if (choice == 1) {
            newPlayer->getPokemon().decreaseHealth(newEnemy.getPokemon().getAtk());
            newEnemy.getPokemon().decreaseHealth(newPlayer->getPokemon().getAtk());
            cout << "Your Pokemons Health: " << newPlayer->getPokemon().getHP() << "\n" << enemyNames[NAME_COUNTER] << " Pokemons Health: " << newEnemy.getPokemon().getHP() << "\n";
        }
        else if (choice == 2) {
            break;
        }
    } while (newPlayer->getPokemon().getHP() > 0 && newEnemy.getPokemon().getHP() > 0);
    
    NAME_COUNTER++;
    POK_COUNTER++;
    newPlayer->getPokemon().renewHP(); //hp to 100
    
    if (choice == 2) { //if in the do-while loop choice was 2, this statement is executed
        return;
    }
    if (newPlayer->getPokemon().getHP() == 0) {
        cout << "You Lost!\n";
        return;
    }
    else {
        cout << "You Won!\n";
        newPlayer->battleWon();
        return;
    }
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player* newPlayer, string* pokemonNames){
    int choice;
    const pokemon PokToBeCathced(pokemonNames[POK_COUNTER], ENEMY_POKEMON_ATTACK); //create pokemon
    newPlayer->playerPokedex.updatePokedex(PokToBeCathced); //add pokemon to pokedex
    cout << "You encounter with " << PokToBeCathced.getName() << " Health: " << PokToBeCathced.getHP() << " Attack: " << PokToBeCathced.getAtk() << "\n";
    cout << "1- Catch \n2- Runaway \nChoice: ";
    cin >> choice;
    if (choice == 1) {
        cout << "You catch " << PokToBeCathced.getName() << "\n";
        newPlayer->catchPokemon(PokToBeCathced);
    }
    POK_COUNTER++;
    return;
};
//--------------------------------------------//