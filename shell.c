#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

/**
 * lire_commande - function qui lit la commande entré par l'utilisateur
 * @commande: commmande
 * @taille: taille
 * Return: la ligne de commande
 */

ssize_t lire_commande(char **commande, size_t *taille)
{
	printf("simple_shell> "); /*prompt*/
	return (getline(commande, taille, stdin)); /*lit ce que l'user a entré*/
}

/**
 * executer_commande - fonction qui execute la commande
 * @commande: commande.
 * Return: void.
 */

void executer_commande(char *commande)
{
	pid_t pid = fork(); /*créer un processus fils*/

	if (pid == -1)
	{
		perror("Erreur de fork"); /*si fork echoue, afficher une erreur*/
		return;
	}

	if (pid == 0)
	{
		char *args[100]; /*tableau*/
		char *token = strtok(commande, " "); /*separe commande des arguements*/
		int i = 0;

		args[i++] = token; /*premier argument (commande)*/

		/*ajout autres arguemnts*/
		while ((token = strtok(NULL, " ")) != NULL)
		{
			args[i++] = token;
		}

		args[i] = NULL; /*termine avec NULL*/

		if (strcmp(args[0], "ls") == 0)
		{
			args[0] = "/bin/ls"; /*remplace ls par son chemin*/
		}

		if (execvp(args[0], args) == -1) /*essaie d'executer la commande*/
		{
			perror("Erreur d'execution");
			exit(1); /*quitte avec un code erreur*/
		}
	}

	else
	{
		waitpid(pid, NULL, 0); /*attend la fin du processus fils*/
	}
}

/**
 * simple_shell - fonction principal
 * Return: void
 */

void simple_shell(void)
{
	char *commande = NULL;
	size_t taille = 0;
	ssize_t ncl;

	while (1)
	{
		ncl = lire_commande(&commande, &taille); /*lit la commande de l'user*/

		if (ncl == -1) /*si l'user appuie sur ctrl+d*/
		{
			printf("\n");
			continue;
		}

		commande[strcspn(commande, "\n")] = 0; /*enleve '\n'*/

		if (strcmp(commande, "exit") == 0)
		{
			free(commande);
			exit(0);
		}

		executer_commande(commande); /*execute la commande*/
	}

	free(commande); /*libere memoire allouée*/
}

/**
 * main - fonction principal du programme
 * Return: le shell
 */

int main(void)
{
	simple_shell();
	return (0); /*le programme s'est terminé correctement*/
}
