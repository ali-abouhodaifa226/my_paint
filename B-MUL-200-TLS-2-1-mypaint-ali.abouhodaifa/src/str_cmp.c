/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** str_cmp
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

int cmp(char *str, char *str2)
{
    int size_str = my_strlen(str);
    int size_str2 = my_strlen(str2);
    int i = 0;

    while (str[i] != '\0' && str2[i] != '\0') {
        if (str[i] < str2[i]) {
            return -1;
        }
        if (str[i] > str2[i]) {
            return 1;
        }
        i++;
    }
    if (size_str > size_str2)
        return 1;
    if (size_str < size_str2)
        return -1;
    return 0;
}
