#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

ssize_t lire_commande(char **commande, size_t *taille);
void executer_commande(char *commande);
void simple_shell(void);
int betty_checks(void);

#endif
