/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "../include/my.h"
#include "../include/helper.h"

char *copy_word(char *file, int i, int r)
{
    int size = 0;
    char *word = NULL;
    int n = 0;
    int b = 1;

    if (r == 0)
        b = 0;
    for (int a = i + b; file[a] != '\n'; a++)
        size++;
    word = malloc(sizeof(char) * (size + 1));
    if (word == NULL)
        exit (84);
    for (int a = i + b; file[a] != '\n'; a++) {
        word[n] = file[a];
        n++;
    }
    word[n] = '\0';
    return word;
}

char *find_word(char *file, int r)
{
    char *word = NULL;
    int pos = 0;

    for (int i = 0; file[i]; i++) {
        if (file[i] == '\n')
            pos++;
        if (pos == r) {
            word = copy_word(file , i, r);
            return word;
        }
    }
}

void replace_with_stars(char *starword)
{
    for (int i = 0; starword[i]; i++) {
        starword[i] = '*';
    }
}

board *init_game(char **av)
{
    board *hangman = malloc(sizeof(board));

    if (hangman == NULL)
        exit (84);
    hangman->file = NULL;
    hangman->word_count = 0;
    hangman->file = load_file_in_mem(av[1]);
    hangman->word_count = getrows(hangman->file);
    hangman->r = 0;
    hangman->word = NULL;
    hangman->starword = NULL;
    hangman->tries = 0;
    hangman->win = 0;
    hangman->len = 0;
    return hangman;
}

int main(int ac, char **av)
{
    board *hangman = init_game(av);

    if (check_args(ac, av) == -1)
        return 84;
    hangman->tries = amount_of_tries(av);
    srand(time(0));
    hangman->r = rand() % hangman->word_count;
    hangman->word = find_word(hangman->file, hangman->r);
    hangman->starword = strdup(hangman->word);
    replace_with_stars(hangman->starword);
    hangman->win = gameloop(hangman->word, hangman->starword, hangman);
    if (hangman->win == 1)
        printf("Congratulations!");
    else if (hangman->win == 0)
        printf("You lost!");
    free_everything(hangman);
    return 0;
}