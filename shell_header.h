#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>

/*Constants*/
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

/*helpers*/
void print(char *);
char **tokenizer(char *, char *);
void remove_newline(char *);
int _strlen(char *);
void _strcpy(char *, char*);

/*helpers2*/
int _strcmp(char *, char *);
char *_strcat(char *, char *);

/*utils*/
int parse_command(char *);
void execute_command(char **, int);
char *check_path(char *);

#endif /*SHELL_H*/
