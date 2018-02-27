/*Con este modulo conseguimos implementar los jugadores

* @author Guillermo Ríos y Marcos Valle
* @version 1.0
* @date 13-01-2018
* @copyright GNU Public License */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"


struct _Player {
    Id id;
    char name[WORD_SIZE + 1];
    Id idspace;
    Id idobject;

};

Player* player_create(Id id) {

  Player *newPlayer = NULL;

  if (id == NO_ID)
    return NULL;

  newPlayer = (Player *) malloc(sizeof (Player));

  if (newPlayer == NULL) {
    return NULL;
  }

  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->idobject = NO_ID;/*Sería lo mismo que poner -1 */
  newPlayer->idspace = NO_ID;

  return newPlayer;
}

STATUS player_destroy(Player* player) {
  if (!player) {
    return ERROR;
  }

  free(player);
  player = NULL;

  return OK;
}

STATUS player_set_name(Player* player, char* name) {
  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }

  return OK;
}



STATUS player_set_object(Player* player, Id id) {
  if (!player) {
    return ERROR;
  }
  player->idobject = id;
  return OK;
}

STATUS player_set_space(Player* player, Id id) {
  if (!player || id == -1) {
    return ERROR;
  }
  player->idspace = id;
  return OK;
}
Id player_get_space(Player* player) {
  if (!player) {
    return -1;
  }
  return player->idspace;
}

const char * player_get_name(Player* player) {
  if (!player) {
    return NULL;
  }
  return player->name;
}

Id player_get_id(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->id;
}


Id player_get_object(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->idobject;
}

STATUS player_print(Player* player) {
  Id idaux = NO_ID;

  if (!player) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", player->id, player->name);


  return OK;
}
