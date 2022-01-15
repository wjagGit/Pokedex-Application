#include "Functions.h"

// Pokemon_List Functions

PokemonNode* NewPokemonNode(Pokedex* pokedex, char name[11], char type[8], char ability[15], char evolution_name[11]){ // Creates a Pokemon Node.

    PokemonNode *new_node = NULL;                                           // Creates PokemonNode pointer and sets it to NULL.
    new_node = malloc(sizeof(PokemonNode));                                 // Creates a PokemonNode in memory and connects it to the "new_node" pointer.

    if (new_node != NULL){                                                  // Check for success of node/pointer creation.
        strcpy(new_node->name, name);                                       // Uses string.h library to copy inputted strings into the node.
        strcpy(new_node->type, type);                                       // ^
        strcpy(new_node->ability, ability);                                 // ^

        new_node->next = NULL;                                              // Sets "next" to NULL.
        new_node->evolution = FindPokemon(pokedex, evolution_name);         // Sets "evolution" pointer to PokemonNode with matching name. Else sets "evolution" to NULL.
    }

    return new_node;                                                        // The Created PokemonNode is returned.
}

void AddPokemonToList(Pokedex** pokedex_ref, char name[11], char type[8], char ability[15], char evolution_name[11]){ // Adds a new pokemon Node to the Pokemon list.

    PokemonNode *jumper = (*pokedex_ref)->Poke_head;            // Creates temporary head pointer "jumper" for itterating through Pokemon linked list.
    
    bool duplicate = false;                                     // Boolean "duplicate" variable. Default value of False.

    while(jumper != NULL){                                      // Loops over Pokemon list.
        if(strcmp(jumper->name, name) == 0){                    // Checks if input_name exists in Pokemon linked list.                             
            duplicate = true;                                   // If a duplicate exists, dupicate variable is set to "True".
        }
        jumper = jumper->next;                                  // Sets "jumper" value to the address of the next node in the linked list.
    }

    if(duplicate){                                              // If dupicate boolean is true the function exits.
        return;                                                 // ^
    }

    PokemonNode *new_node = NewPokemonNode(*pokedex_ref, name, type, ability, evolution_name);          // Creates a PokemonNode pointer "new_node" and links it to the node returned from NewPokemonNOde().

    if((*pokedex_ref)->Poke_head == NULL){                      // Checks if pokemon list is empty.           
        (*pokedex_ref)->Poke_head = new_node;                   // If the list is empty, sets the head of the pokemon list to point to the new_node.
    } else{
        new_node->next = (*pokedex_ref)->Poke_head;             // If PokemonList is not empty, New_node points to the previous first node.
        (*pokedex_ref)->Poke_head = new_node;                   // Head of the list points to the New_node.
    }
}


PokemonNode* FindPokemon(Pokedex* pokedex, char name[11]){ // Returns a pointer to a pokemon Node in the Pokemon_List.

    PokemonNode *jumper = pokedex->Poke_head;                   // Creates temporary head pointer "jumper" for itterating through Pokemon linked list.

    while(jumper != NULL){                                      // Loops over Pokemon list.
        if(strcmp(jumper->name, name) == 0){                    // checks to see if any node names match the inputted name.
            return jumper;                                      // if node->name matches inputted name, a pointer to this node is returned.
        }
        jumper = jumper->next;                                  // Sets "jumper" value to the address of the next node in the linked list.
    }
    return NULL;                                                // If no names match the inputted string, NULL pointer is returned.
}

// Player_List Functions

PlayerNode* NewPlayerNode(char name[15]){ // Creates a new Player Node.

    PlayerNode *new_node = NULL;                                // creates PlayerNode pointer and sets it to NULL.
    new_node = malloc(sizeof(PlayerNode));                      // creates a PlayerNode in memory and connects it to the "new_node" pointer.

    if (new_node != NULL){                                      // Check for success of node/pointer creation
        strcpy(new_node->PlayerName, name);                     // uses string.h library to copy inputted string into the node.
        new_node->PokemonCount = 0;                             // sets the playercount of a node to 0.
        new_node->next = NULL;                                  // sets "next" to NULL.                                  
    }

    return new_node;                                            // The Created PokemonNode is returned.
}

void AddPlayerToList(Pokedex** pokedex_ref, char name[15]){ // Adds a new player Node to the Players list.
    
    PlayerNode *jumper = (*pokedex_ref)->Player_head;           // Creates temporary head pointer "jumper" for itterating through Player linked list.
    
    bool duplicate = false;                                     // Boolean "duplicate" variable. Default value of False.

    while(jumper != NULL){                                      // Loops over nodes in Pokemon linked list.
        if(strcmp(jumper->PlayerName, name) == 0){              // If input_name exists in list, "duplicate" variable is set to "true".                                     
            duplicate = true;                                   // ^
        }
        jumper = jumper->next;                                  // Sets "jumper" value to the address of the next node in the player linked list.
    }

    if(duplicate){                                              // If dupicate boolean is true, the function exits.
        return;                                                 // ^
    }

    PlayerNode *new_node = NewPlayerNode(name);                 // Creates a PlayerNode pointer "new_node" and links it to the node returned from NewPlayerNode().

    if((*pokedex_ref)->Player_head == NULL){                    // Checks if Player list is empty  
        (*pokedex_ref)->Player_head = new_node;                 // If the list is empty, sets the head of the Player list to point to the new_node.
    } else{
        new_node->next = (*pokedex_ref)->Player_head;           // If Player list is not empty, New_node points to the previous first node.
        (*pokedex_ref)->Player_head = new_node;                 // Head of the list points to the New_node.
    }
}

PlayerNode* FindPlayer(Pokedex* pokedex, char name[15]){ // Returns a pointer to a Player Node in the Player_List.
    
    PlayerNode *jumper = pokedex->Player_head;                  // Creates temporary head pointer "jumper" for itterating through Player linked list.

    while(jumper != NULL){                                      // Loops through nodes of Pokemon list.
        if(strcmp(jumper->PlayerName, name) == 0){              // Checks if input_name matches node->name.   
            return jumper;                                      // If the names match, a pointer to the node is returned.
        }
        jumper = jumper->next;                                  // Sets "jumper" value to the address of the next node in the player linked list.
    }
    return NULL;                                                // If node name does not match inputted name, Returns a NULL pointer.
}

void AddPokemonToPlayer(Pokedex* pokedex, char player_name[15], char pokemon_name[11]){ // Adds a pointer to a pokemon to a player node.

    PlayerNode *player = FindPlayer(pokedex, player_name);                      // If a PlayerNode name matches the inputted name, creates pointer linking to that node.

    if(player == NULL){                                                         // Checks if a node was returned.
        return;                                                                 // If node was not returned, function exits.
    }

    if(player->PokemonCount >= 20){                                             // Checks if the PlayerPokemon array is full in the node.
        return;                                                                 // If PlayerPokemon is full, function exits.
    }
    
    bool duplicate = false;                                                     // Boolean "duplicate" variable. Default value of False.

    for (int i = 0; i < player->PokemonCount; i++){                             // loops through nodes of Pokemon list.
        if(strcmp((player->PlayerPokemon[i])->name, pokemon_name) == 0){        // If input_name exists in list, "duplicate" variable is set to true.
            duplicate = true;                                                   // ^
        }
    }

    if(duplicate){                                                              // If duplicate is true, function exits.
        return;                                                                 // ^
    }

    PokemonNode *pokemon = FindPokemon(pokedex, pokemon_name);                  // If a PokemonNode name matches inputted name, creates a pointer linked to that node.

    if (pokemon == NULL){                                                       // Checks if a node was returned.
        return;                                                                 // If node was not returned, function exits.
    }

    player->PlayerPokemon[player->PokemonCount] = pokemon;                      // Adds pointer to the pokemon node at the end of the PlayerPokemon array.
    player->PokemonCount++;                                                     // Increments the number of pokemon the player possesses by 1.
}

// Pokedex Functions

void DisplayPokemonDetails(Pokedex* pokedex, char name[11]){ // Outputs data from a selected PokemonNode.                 

    PokemonNode *jumper = pokedex->Poke_head;                                   // Creates temporary head pointer "jumper" for itterating through Player linked list.

    while(jumper != NULL){                                                      // Loops through nodes of Pokemon list.
        if(strcmp(jumper->name, name) == 0){                                    // If a node name matches the inputted name, the data of that pokemon are printed to the screen.
            printf("\nPokemon Name: %s\n", jumper->name);                       // ^
            printf("Pokemon Type: %s\n", jumper->type);                         // ^
            printf("Pokemon Ability: %s\n", jumper->ability);                   // ^
            return;
        }
        jumper = jumper->next;                                                  // Sets "jumper" value to the address of the next node in the linked list.
    }
}

void DisplayPlayerDetails(Pokedex* pokedex, char name[11]){ // Outputs data from a selected PlayerNode.

    PlayerNode *jumper = pokedex->Player_head;                                  // Creates temporary head pointer "jumper" for itterating through Player linked list.

    while(jumper != NULL){                                                      // Loops through nodes of Pokemon list.
        if(strcmp(jumper->PlayerName, name) == 0){                              // If a node name matches the inputted name, the data of that player are printed to the screen.
            printf("\nPlayer Name: %s\n", jumper->PlayerName);                  // ^
            printf("Pokemon Count: %d\n", jumper->PokemonCount);                // ^

            if(jumper->PokemonCount > 0){                                       // Checks if player owns Pokemon.
            printf("\n%s's Pokemon:\n", jumper->PlayerName);                    

                for(int i = 0; i < jumper->PokemonCount; i++){                  // If Player has pokemon, PlayerPokemon is looped.
                printf("\t-%s\n", (jumper->PlayerPokemon[i])->name);            // The names of the the nodes pointed to in the PlayerPokemon array are printed.
                }   
            }
            return;
        }
        jumper = jumper->next;                                                  // Sets "jumper" value to the address of the next node in the linked list.
    }
}

void ListPokemon(Pokedex* pokedex){ // Outputs name from each PokemonNode.

    PokemonNode *jumper = pokedex->Poke_head;                                   // Creates temporary head pointer "jumper" for itterating through Pokemon linked list.
    int i = 1;

    printf("\nAll Pokemon registed on this pokedex:");

    while(jumper != NULL){                                                      // Loops through nodes of Pokemon linked list.
        printf("\n\t%d : %s", i, jumper->name);                                 // Prints the name of the pokemon stored in each node.
        jumper = jumper->next;                                                  // Sets "jumper" value to the address of the next node in the linked list.
        i++;        
    }

    printf("\n");
}

void ListPlayers (Pokedex* pokedex){ // Outputs name from each PlayerNode.
   
    PlayerNode *jumper = pokedex->Player_head;                                  // Creates temporary head pointer "jumper" for itterating through Player linked list.
    int i = 1;

    printf("\n\nAll Players registered on this Pokedex:");

    while(jumper != NULL){                                                      // Loops through nodes of Player linked list.
        printf("\n\t%d : %s", i, jumper->PlayerName);                           // Prints the name of the pokemon in each node.
        jumper = jumper->next;                                                  // Sets "jumper" value to the address of the next node in the linked list.
        i++;
    }

    printf("\n");
}
// OPTIONAL Evolution Function

void EvolvePlayerPokemon(Pokedex* pokedex, char player_name[15], char pokemon_name[11]){ // Evolves a player owned pokemon by replacing the player pointer to the evolved pokemon node.

    PlayerNode *player = FindPlayer(pokedex, player_name);                              // If a PlayerNode name matches inputted name, creates pointer linked to that node.

    if (player == NULL){                                                                // Checks if a node was returned.
        return;                                                                         // If node was not returned, function exits.
    }

    for (int i = 0; i < player->PokemonCount; i++){                                     // Loops through the player owned pokemon (PlayerPokemon pointer array).
        if(strcmp((player->PlayerPokemon[i])->name, pokemon_name) == 0){                // Checks if any of the PlayerPokemon node->names match the inputted name.
            player->PlayerPokemon[i] = player->PlayerPokemon[i]->evolution;             // If a node->name matches the inputted name, the pointer to to that node is replaced by it's "evolution" pointer address
        }
    }

    return;

}