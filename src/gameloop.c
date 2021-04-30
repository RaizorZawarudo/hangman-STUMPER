/*
** EPITECH PROJECT, 2021
** B-CPE-210-BER-2-1-stumper5-eduard.popp
** File description:
** gameloop
*/

#include "../include/my.h"
#include "../include/helper.h"

int compare_input(char *word, char *starword, char *userline)
{
    char letter = userline[0];
    int match = -1;

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == letter) {
            starword[i] = letter;
            match = 1;
        }
    }
    return match;
}

void loop_prompt(char *starword, int tries)
{
    printf("%s\n", starword);
    printf("Tries: %d\n\n", tries);
    printf("Your letter: ");
}

int gameloop(char *word, char *starword, board *hangman)
{
    char *userline = NULL;

    while (hangman->tries > 0) {
        loop_prompt(starword, hangman->tries);
        getline(&userline, &hangman->len, stdin);
        if (strlen(userline) > 2) {
            continue;
        }
        if (compare_input(word, starword, userline) == -1) {
            printf("%c is not in the word\n", userline[0]);
            hangman->tries--;
        }
        if (strcmp(starword, word) == 0) {
            printf("%s\n", starword);
            printf("Tries: %d\n\n", hangman->tries);
            return (1);
        }
    }
    return hangman->tries;
}