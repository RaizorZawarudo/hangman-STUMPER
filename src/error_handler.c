/*
** EPITECH PROJECT, 2021
** error_handler.c
** File description:
** error_handler
*/

#include "../include/my.h"
#include "../include/helper.h"

int check_args(int ac, char **av)
{
    if (ac < 2 || ac > 3) {
        return -1;
    }
    if (av[2] == NULL) {
        return 0;
    }
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] < 48 || av[2][i] > 57) {
            return -1;
        }
    }
    return 0;
}