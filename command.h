/**
 * @brief It implements the command interpreter
 *
 * @author Guillermo Ríos y Marcos Valle
 * @version 1.0
 * @date 13-01-2018
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

typedef enum enum_Command {
  NO_CMD = -1,
  UNKNOWN,
  EXIT,
  FOLLOWING,
  TAKE,
  DROP,
  PREVIOUS
} T_Command;


T_Command get_user_input();

#endif
