/*
** EPITECH PROJECT, 2021
** B-CPE-210-BER-2-1-stumper5-eduard.popp
** File description:
** load_file
*/

#include "../include/helper.h"
#include "../include/my.h"

char *load_file_in_mem(char const *filepath)
{
    int filedescriptor = 0;
    int size;
    struct stat stats;
    char *buffer;

    filedescriptor = open(filepath, O_RDONLY);
    if (filedescriptor == -1) {
        my_putstr("No such file");
        exit (FAIL_RETURN);
    }
    stat(filepath, &stats);
    size = stats.st_size;
    buffer = malloc(sizeof(char) * size + 1);
    if (buffer == NULL)
        exit (FAIL_RETURN);
    read(filedescriptor, buffer, size);
    close(filedescriptor);
    return (buffer);
}

int getrows(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            count++;
        }
    }
    return (count);
}