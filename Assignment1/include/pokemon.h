//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Adil Mahmudlu
//---Student Number: 150200915
//--------------------------//

#ifndef _H
#define _H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//-------------Do Not Add Any New Class(es)-------------//

class pokemon{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        int hpValue;
        int atkValue;
    public:
       pokemon(); //default constructor
       pokemon(string, int); //constructor with argumemt
       pokemon(const pokemon &); //copy constructor
       void decreaseHealth(int damage) {
           hpValue = (hpValue>damage? hpValue-damage : 0); //change hp in a fight 
       };
       void renewHP() {
           hpValue = 100; //set HP to 100 at the end of fight
       };
       string getName() const; //getters
       int getHP() const;
       int getAtk() const;
};

class pokedex{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        pokemon pokedexArray[100];
        int value;
    public:
       pokedex(); //constructer
       void updatePokedex(const pokemon &); //pass by reference so that memory is not wasted 
       bool isNewPokemon(const pokemon &); //checks for duplicates
       void printPokedex();
};

class player{
    private:
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
        string name;
        int pokemonNumber;
        int pokeballNumber;
        int badgeNumber;
        pokemon playerPokemon;
    public:
        pokedex playerPokedex;
        player();
        player(string, pokemon);
        int showPokemonNumber();
        int showPokeballNumber();
        int showBadgeNumber();
        pokemon& getPokemon(); //return by reference so as to do changes on the original object
        void battleWon();
        void catchPokemon(const pokemon&);
};

class enemy{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        pokemon enemyPokemon;
    public:
        enemy();
        enemy(string, pokemon);
        pokemon& getPokemon(); //return by reference so as to do changes on the original object
        string getName();
};

#endif