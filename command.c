/*
 * @file command.c
  * @author Guillermo Ríos y Marcos Valle
  * @version 1.0
  * @date 13-01-2018
  * @copyright GNU Public License
  */


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "command.h"

#define CMD_LENGHT 36
#define N_CMD 7

char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "Following","Take","Drop", "Previous"};
char *short_cmd_to_str[N_CMD] = {"","","e","f","t","d","p"};

T_Command get_user_input() {
    T_Command cmd = NO_CMD;
    char input[CMD_LENGHT] = "";
    int i=UNKNOWN- NO_CMD + 1;

    if (scanf("%s", input) > 0){
      cmd = UNKNOWN;while(cmd == UNKNOWN && i < N_CMD){
        if (!strcasecmp(input,short_cmd_to_str[i]) || !strcasecmp(input,cmd_to_str[i])){
          cmd = i + NO_CMD;
        }
        else
        {
          i++;
        }
      }
    }
    return cmd;
}
