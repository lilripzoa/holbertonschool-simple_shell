#ifndef MAIN_H
#define MAIN_H

extern char **environ;

char **splitter(char *str, char *delim);
char *_getline(void);
char **pathfinder(void);
void executer(char *command, char **array);
void environ_printer(void);
void array_cleaner(char **array);
void exit_shell(int status);
void env_shell(char *env_var);

#endif
