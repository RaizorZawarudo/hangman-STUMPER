/*
** EPITECH PROJECT, 2020
** helper.h
** File description:
** header file containing prototypes and definitions from all project files
*/

#ifndef HELPER_H_
#define HELPER_H_

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

#define FAIL_RETURN  84

typedef struct board {
    char *file;
    int word_count;
    int r;
    char *word;
    char *starword;
    int tries;
    int win;
    size_t len;
} board;

char *load_file_in_mem(char const *filepath);

int check_args(int ac, char **av);

int getrows(char *buffer);

int gameloop(char *word, char *starword, board *hangman);

int amount_of_tries(char **av);

void free_everything(board *hangman);

#endif /* !HELPER_H_ */
