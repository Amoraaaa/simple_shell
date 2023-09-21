#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

#include <dirent.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

#define BUFF_SIZE 1024
#define PATH "PATH"
#define PROMPT "($) "

#define PERM_DENIED 126
#define DIR_NOT_FOUND 2

#define ERROR_NO_EXEC -5
#define ERROR_NO_SPLIT -6
#define ERROR_NO_WAIT -7
#define ERROR_NO_FORK -8
#define ERROR_NOT_FOUND 127


extern char **Myenv;
int EXIT_STATUS;

int main_shell(char *);
int shell_handler(char []);
char *full_path(char *, char *);
int fork_process(char *[], char *[], char *);

void free_arr(char **);

char *_memcpy(char *, char *, unsigned int);
char *_memset(char *, char, unsigned int);

void *_realloc(void *, unsigned int, unsigned int);
void *_calloc(unsigned int, unsigned int);

int _isdigit(int);
int _isalpha(int);

char **split_args(char *);
void perm_denied_err(char *, char *, unsigned int);
unsigned int count_words(char *);
int check_command(char *, char *[]);
void _exit(int);

void not_found_err(char *, char *, unsigned int);
void sigint_handler(int);
void invalid_exit(char *, char *, unsigned int);
char *trim_string(char *);

char *_strdup(char *);
int _strcmp(char *, char *);
char *_strrchr(char *, char);
char *_strstr(char *, char *);
char *_strpbrk(char *, char *);

void print_env(void);
char *_get_env(char *);
int check_command(char *, char *[]);

int starts_with(char *, char *);
char *to_str(unsigned int);
char *_strcat(char *, char *);
char *_strncat(char *, char *, int);
char *_strcpy(char *, char *);
char *_strncpy(char *, char *, int);

int _strlen(char *);
void _puts(char *);
void _puts_err(char *);
void reverse_string(char *);
int _putchar(char);
int _atoi(char *);
int _putchar_err(char);

#endif

