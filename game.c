/**
 * @brief It implements the game interface and all the associated callbacks
 * for each command
 *
 * @author Guillermo Ríos y Marcos Valle
 * @version 1.0
 * @date 13-01-2018
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "game.h"
#include "gamereader.h"

#define N_CALLBACK 6

/**
   Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game* game);

/**
   List of callbacks for each command in the game
*/
void game_callback_unknown(Game* game);
void game_callback_exit(Game* game);
void game_callback_following(Game* game);
void game_callback_take(Game* game);
void game_callback_drop(Game* game);
void game_callback_previous(Game* game);


static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_following,
  game_callback_take,
  game_callback_drop,
  game_callback_previous};

/*
   Private functions
*/

/*STATUS game_load_spaces(Game* game, char* filename);*/
/*STATUS game_add_space(Game* game, Space* space); */
Id     game_get_space_id_at(Game* game, int position);
STATUS game_set_player_location(Game* game, Id id);
STATUS game_set_object_location(Game* game, Id id);

/*
   Game interface implementation
*/

STATUS game_create(Game* game) {

  for (int i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  if ((game->player=player_create(1)) == NULL) return ERROR;
  if ((game->object=object_create(2)) == NULL){
    player_destroy(game->player);
    return ERROR;
  }

  game->last_cmd = NO_CMD;

  return OK;
}

STATUS game_create_from_file(Game* game, char* filename) {

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_load_spaces(game, filename) == ERROR){
    game_destroy(game);
    return ERROR;
  }

  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}

STATUS game_destroy(Game* game) {
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
  }
  player_destroy(game->player);
  object_destroy(game->object);

  return OK;
}

STATUS game_add_space(Game* game, Space* space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

Id game_get_space_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

Space* game_get_space(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      return game->spaces[i];
    }
  }

  return NULL;
}
/* @brief Funciones que hemos implementado : player_location y object_location
player_location cambia la posicion de un jugador */
STATUS game_set_player_location(Game* game, Id id) {

    if (id == NO_ID){
        return ERROR;
      }

    player_set_space(game->player, id);

    return OK;
}
/* @brief object_location cambia la posicion de un objeto*/
STATUS game_set_object_location(Game* game, Id id) {

  int i = 0;

  if (id == NO_ID) {
    return ERROR;
  }

  space_set_object(game_get_space(game, id), object_get_id(game->object));

  return OK;
}



Id game_get_player_location(Game* game) {
  return player_get_space(game->player);
}
/*@brief indica la localizacion del objecto
@param puntero game de tipo Game
@param2 funcion basada en game_get_space_id */
Id game_get_object_location(Game* game) {

	Id id;

	for ( int i=0; i<MAX_SPACES; i++){
		id = game_get_space_id_at(game, i);
		if(space_get_object (game_get_space(game, id)) != NO_ID){
			return id;
    }
	}


    return NO_ID;
}

STATUS game_update(Game* game, T_Command cmd) {
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game);
  return OK;
}

T_Command game_get_last_command(Game* game){
  return game->last_cmd;
}


void game_print_data(Game* game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }
/* Sustituimos la dirección de object_location por game_get_object como hemos cambiado
en las funciones e igual con el player . */
  printf("=> Object location: %d\n", (int) game_get_object_location(game));
  printf("=> Player location: %d\n", (int) game_get_player_location(game));
  printf("prompt:> ");
}

BOOL game_is_over(Game* game) {
  return FALSE;
}

/*
   Callbacks implementation for each action
*/

void game_callback_unknown(Game* game) {
}

void game_callback_exit(Game* game) {
}

void game_callback_following(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID) {
	         game_set_player_location(game, current_id);
      }
      return;
    }
  }
}
/*
@brief Permite que el jugador pueda coger un objeto

@param1 con el puntero space vemos si tiene espacio suficiente para coger el objetos
@param2 tiene un puntero game de tipo Game
@param3 con game_get_player_location cogemos la posicion donde se encuentra el jugador
@param4 space_get_object nos da el objecto que esta en ese espacio

 */
void game_callback_take(Game* game){

 Id current_id = NO_ID;
 Id space_id = NO_ID;
 Space * space = NULL;

 space_id = game_get_player_location(game);
 if (space_id == NO_ID){
   return;
}

 space = game_get_space(game, space_id);
 if (space == NULL){
   return;
}

 current_id = space_get_object(space);

 if (current_id == NO_ID){
   return;
}

 if (player_get_object(game->player) == NO_ID){
   player_set_object (game->player, current_id);
   space_set_object (space, NO_ID);
   return;
 }

 return;



}



/*
@brief Permite que el jugador pueda dejar un objeto

@param1 puntero game tipo Game
@param2 game_get_player_location nos indica la posicion del jugador
@param3 space de tipo Space nos indica si el jugador tiene el espacio ocupado para que deje el objetos
@param4 currend_id si no tiene objecto no hace nada return.
 */
void game_callback_drop(Game* game){
    Id current_id = NO_ID;
    Id space_id = NO_ID;
    Space *space = NULL;

    space_id = game_get_player_location(game);

    if (NO_ID == space_id){
        return;
}
	current_id = player_get_object(game->player);

	if (current_id == NO_ID){
		return;
}
    space = game_get_space(game, space_id);
    if (!space){
        return;
}
	if (space_get_object(space) != NO_ID){
		return;
}
	space_set_object(space, current_id);
	player_set_object (game->player, NO_ID);

	return;
}

void game_callback_previous(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID) {
	        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

/* De esta funcion se encarga el módulo gamereader
STATUS game_load_spaces(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space* space = NULL;
  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL) {
	space_set_name(space, name);
	space_set_north(space, north);
	space_set_east(space, east);
	space_set_south(space, south);
	space_set_west(space, west);
	game_add_space(game, space);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}*/
