#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
// STRUCTS 

// Pokemon_Node Struct.
typedef struct PokemonNode{
    char name[12];
    char type[9];
    char ability[15];
    struct PokemonNode* evolution;     
    struct PokemonNode* next;
}PokemonNode;

// PlayerNode Struct.
typedef struct PlayerNode{
    char PlayerName[15];
    int PokemonCount;
    PokemonNode* PlayerPokemon[20];
    struct PlayerNode* next;
}PlayerNode;

// Pokedex Struct.
typedef struct Pokedex{
    PokemonNode* Poke_head;
    PlayerNode* Player_head;
}Pokedex;

// -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
// FUNCTION DECLARATIONS

// Pokemon_List Functions
PokemonNode* NewPokemonNode(Pokedex* pokedex, char name[11], char type[8], char ability[15], char evolution_name[11]);      // Creates a Pokemon Node.
void AddPokemonToList(Pokedex** pokedex_ref, char name[11], char type[8], char ability[15], char evolution_name[11]);       // Adds a new pokemon Node to the Pokemon list.
PokemonNode* FindPokemon(Pokedex* pokedex, char name[11]);                                                                  // Returns a pointer to a pokemon Node in the Pokemon_List.

// Player_List Functions
PlayerNode* NewPlayerNode(char name[15]);                                                   // Creates a new Player Node.
void AddPlayerToList(Pokedex** pokedex_ref, char name[15]);                                 // Adds a new player Node to the Players list.
PlayerNode* FindPlayer(Pokedex* pokedex, char name[15]);                                    // Returns a pointer to a Player Node in the Player_List.
void AddPokemonToPlayer(Pokedex* pokedex, char player_name[15], char pokemon_name[11]);     // Adds a pointer to a pokemon to a player node.

// Pokedex Functions
void DisplayPokemonDetails(Pokedex* pokedex, char name[11]);        // Outputs data from a selected PokemonNode.
void DisplayPlayerDetails(Pokedex* pokedex, char name[11]);         // Outputs data from a selected PlayerNode.
void ListPokemon(Pokedex* pokedex);                                 // Outputs name from each PokemonNode.
void ListPlayers (Pokedex* pokedex);                                // Outputs name from each PlayerNode.

// OPTIONAL Evolution Function
void EvolvePlayerPokemon(Pokedex* pokedex, char player_name[15], char pokemon_name[11]);    // Evolves a player owned pokemon by replacing the player pointer to the evolved pokemon node.

#endif