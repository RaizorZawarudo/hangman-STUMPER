/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** utils
*/

#include "../include/my.h"
#include "../include/helper.h"

int amount_of_tries(char **av)
{
    int retval = 0;

    if (av[2] == NULL) {
        return 10;
    } else {
        retval = my_getnbr(av[2]);
        return retval;
    }
}

void free_everything(board *hangman)
{
    free(hangman->starword);
    free(hangman->word);
    free(hangman->file);
    free(hangman);
}