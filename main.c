#include "Functions.h"
#include "Functions.c"

// -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
// Main

int main(void){
    // Creation of Pokedex node
    Pokedex *pokedex = NULL;                // Create pokedex pointer and set to NULL.
    pokedex = malloc(sizeof(pokedex));      // Create pokedex node in memory and assign pokedex pointer to this node.
    pokedex->Poke_head = NULL;              // Within pokedex node: Set the head pointers for each list to NULL.
    pokedex->Player_head = NULL;            // ^

    // Populate Pokemon List
    AddPokemonToList(&pokedex, "Charizard", "Fire", "Flameblast", "");
    AddPokemonToList(&pokedex, "Charmellian", "Fire", "Flamethrower", "Charizard");         
    AddPokemonToList(&pokedex, "Charmander", "Fire", "Flame", "Charmellian");
    AddPokemonToList(&pokedex, "Squirtle", "Water", "Water Gun", "Wartortle");
    AddPokemonToList(&pokedex, "Bulbasaur", "Grass", "Grass Knot", "Ivysaur");
    AddPokemonToList(&pokedex, "Pidgy", "Flying", "Arial Ace", "Pidgeotto");
    AddPokemonToList(&pokedex, "Caterpie", "Bug", "String Shot", "Metapod");
    AddPokemonToList(&pokedex, "Pikachu", "Electric", "Thunderbolt", "Raichu");
    AddPokemonToList(&pokedex, "Nidoran", "Grass", "Poison Shot", "Nidorina");
    AddPokemonToList(&pokedex, "Zubat", "Dark", "Bite", "Golbat");
    AddPokemonToList(&pokedex, "Diglet", "Ground", "Dig", "Dugtrio");
    AddPokemonToList(&pokedex, "Abra", "Psychic", "Hidden Power", "Kadabra");

    // Populate Player List
    AddPlayerToList(&pokedex, "Billy");         
    AddPlayerToList(&pokedex, "Beth");
    AddPlayerToList(&pokedex, "Jim");

    // Populate Player Pokemon
    AddPokemonToPlayer(pokedex, "Billy", "Charmander");
    AddPokemonToPlayer(pokedex, "Billy", "Abra");
    AddPokemonToPlayer(pokedex, "Billy", "Pikachu");
    AddPokemonToPlayer(pokedex, "Beth", "Bulbasaur");
    AddPokemonToPlayer(pokedex, "Beth", "Nidoran");
    AddPokemonToPlayer(pokedex, "Beth", "Abra");
    AddPokemonToPlayer(pokedex, "Jim", "Squirtle");
    AddPokemonToPlayer(pokedex, "Jim", "Pidgy");
    AddPokemonToPlayer(pokedex, "Jim", "Zubat");

    // Evolve Player Pokemon
    EvolvePlayerPokemon(pokedex, "Billy", "Charmander");
    EvolvePlayerPokemon(pokedex, "Billy", "Charmellian");

    // Function Calls
    ListPokemon(pokedex);
    ListPlayers(pokedex);

    DisplayPlayerDetails(pokedex, "Billy");
    DisplayPlayerDetails(pokedex, "Beth");
    DisplayPlayerDetails(pokedex, "Jim");

    DisplayPokemonDetails(pokedex, "Charmander");
    DisplayPokemonDetails(pokedex, "Squirtle");
    DisplayPokemonDetails(pokedex, "Bulbasaur");

   return 0;
}