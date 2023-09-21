#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>


#define BUFF_SIZE 1024
#define PATH "PATH"
#define PROMPT "($) "

#define ERR_NO_SPLIT -6
#define ERR_NOT_FOUND 127
#define ERR_NO_WAIT -7
#define PERM_DENIED 126
#define ERR_NO_EXEC -5
#define DIR_NOT_FOUND 2
#define ERR_NO_FORK -8

extern char **environ;
int EXIT_ST;


int shell(char *);
int shell_handler(char []);
char *full_path(char *, char *);
int run_command(char *[], char *[], char *);


char *trim_string(char *);
char **args_split(char *);
void _puts_invalid_exit(char *, char *, unsigned int);
unsigned int count_words(char *);
char *_getenv(char *);
void _puts_denied(char *, char *, unsigned int);
void print_env(void);
void sigint_handler(int);
void builtin_exit(int);
int check_command(char *, char *[]);
void _puts_not_found(char *, char *, unsigned int);


void afree(char **);
void *_calloc(unsigned int, unsigned int);
char *_memcpy(char *, char *, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
char *_memset(char *, char, unsigned int);


char *_strncat(char *, char *, int);
int _atoi(char *);
int _strlen(char *);
char *_strcat(char *, char *);
char *_strrchr(char *, char);
char *_strpbrk(char *, char *);

void _puts(char *);
void rev_string(char *);
int _eputchar(char);
void _eputs(char *);
int starts_with(char *, char *);
char *_strcpy(char *, char *);
char *to_str(unsigned int);
char *_strncpy(char *, char *, int);
int _strcmp(char *, char *);
char *_strdup(char *);

char *_strstr(char *, char *);
int _putchar(char);
int _isdigit(int);
int _isalpha(int);


#endif

