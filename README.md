# SIMPLE SHELL

## Description
 
Le projet "Simple Shell" en langage C consiste à développer un interpréteur de commandes basique qui permet à l'utilisateur d'exécuter des commandes système depuis un terminal. Il doit être capable de lire et d'analyser les commandes saisies, de créer des processus pour exécuter les commandes via des appels système tels que fork(), exec() et wait(), et de gérer des commandes internes comme cd et exit. Ce shell doit également gérer les erreurs d'exécution et supporter des arguments ainsi que des redirections de flux d'entrée et de sortie. L'objectif principal est de recréer un environnement de shell simple mais fonctionnel, tout en explorant la gestion des processus et des entrées/sorties en langage C.

## The language used

![C](https://img.shields.io/badge/language-C-blue)

```
#include <stdio.h>

int main()
{
    printf("Hello world");
}
```
## Installation

Clone the repository and compile the code with `gcc` :

```
$ git clone https://github.com/lilripzoa/holbertonschool-simple_shell.git
$ cd holbertonschool-simple_shell
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
$ ./holbertonschool-simple_shell
```

## Authorized functions

Dans ce projet, toutes les fonctions autorisées sont:

- toutes les fonctions de string.h
- `acces` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `_exit` (man 2 _exit)
- `fflush` (man 3)
- `fork` (man 2)
- `free` (man 3)
- `getcwd` (man 3)
- `getline` (man 3)
- `getpid` (man 2)
- `isatty` (man 3)
- `kill` (man 2)
- `malloc` (man 3)
- `open` (man 2)
- `opendir` (man 3)
- `perror` (man 3)
- `printf` (man 3)
- `fprintf` (man 3)
- `vfprintf` (man 3)
- `sprintf` (man 3)
- `putchar` (man 3)
- `read` (man 2)
- `readdir` (man 3)
- `signal` (man 2)
- `stat` (man 2)
- `lstat` (man 2)
- `fstat` (man 2)
- `strtok` (man 3)
- `wait` (man 2)
- `waitpid` (man 2)
- `wait3` (man 2)
- `wait4` (man 2)
- `write` (man 2)
## TEST

```
julien@ubuntu:/# ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
julien@ubuntu:/#
```

```
julien@ubuntu:/# echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
julien@ubuntu:/# cat test_ls_2
/bin/ls
/bin/ls
julien@ubuntu:/# cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
julien@ubuntu:/#
```
