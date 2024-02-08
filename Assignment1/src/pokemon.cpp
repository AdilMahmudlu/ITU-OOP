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

#include "pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//
pokemon::pokemon() {
    name = "";
    hpValue = 100;
    atkValue = 0;
}

pokemon::pokemon(string n, int a) {
    name = n;
    hpValue = 100;
    atkValue = a;
}

pokemon::pokemon(const pokemon & p) {
    name = p.name;
    hpValue = p.hpValue;
    atkValue = p.atkValue;
}

string pokemon::getName() const {
    return name;
}

int pokemon::getHP() const {
    return hpValue;
}

int pokemon::getAtk() const {
    return atkValue;
}

pokedex::pokedex() {
    value = 0;
}

bool pokedex::isNewPokemon(const pokemon& p) { //check if the pokemon is on pokedex or not
    for (int i = 0; i < value; i++) {
        if (pokedexArray[i].getName() == p.getName()) {
            return false;
        }
    }
    return true;
}

void pokedex::updatePokedex(const pokemon& p) {
    if (isNewPokemon(p)) {
        pokedexArray[value] = p;
        value++;
    }
}

void pokedex::printPokedex() {
    for (int i = 0; i < value; i++) {
        cout << pokedexArray[i].getName() << "\n";
    }
}

player::player() {
    name = "";
    pokemonNumber = 0;
    pokeballNumber = 10;
    badgeNumber = 0;
}

player::player(string n, pokemon p) {
    name = n;
    playerPokemon = p;
    pokemonNumber = 0;
    pokeballNumber = 10;
    badgeNumber = 0;
}

int player::showPokemonNumber() {
    return pokemonNumber;
}

int player::showPokeballNumber() {
    return pokeballNumber;
}

int player::showBadgeNumber() {
    return badgeNumber;
}

pokemon& player::getPokemon() {
    return playerPokemon;
}

void player::battleWon() {
    badgeNumber++;
    pokeballNumber+=3;
}

void player::catchPokemon(const pokemon& p) {
    pokemonNumber++;
    pokeballNumber--;
}

enemy::enemy() {
    name = "";
}

enemy::enemy(string n, pokemon p) {
    name = n;
    enemyPokemon = p;
}

pokemon& enemy::getPokemon() {
    return enemyPokemon;
}

string enemy::getName(){
    return name;
}