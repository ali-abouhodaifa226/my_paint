/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** buttons functions
*/

#include "../include/my.h"

static void edit_buttons(toolbar_t *toolbar, sfRenderWindow *window)
{
    if (toolbar->first_but->state == 0) {
        sfRenderWindow_drawSprite(window, toolbar->first_but->sprite, NULL);
        sfRenderWindow_drawSprite(window, toolbar->sec_but->sprite, NULL);
    }
    printf("je passe la %d\n", toolbar->first_but->state);
    if (toolbar->first_but->state == 2) {
        sfRenderWindow_drawSprite(window, toolbar->first_but->sprite, NULL);
        sfRenderWindow_drawSprite(window, toolbar->sec_but->sprite, NULL);
        sfRenderWindow_drawSprite(window, toolbar->third_but->sprite, NULL);
        sfRenderWindow_drawSprite(window, toolbar->fourth_but->sprite, NULL);
    }
}

static void help_buttons(toolbar_t *toolbar, sfRenderWindow *window)
{
    sfVector2f vec;

    vec.x = 0.02;
    vec.y = 0.02;
    if (toolbar->first_but->state == 0) {
        sfSprite_setScale(toolbar->first_but->sprite, vec);
        sfRenderWindow_drawSprite(window, toolbar->first_but->sprite, NULL);
    }
}

void display_buttons(paint_t *main_struct)
{
    edit_buttons(main_struct->edit, main_struct->window->window);
    help_buttons(main_struct->help, main_struct->window->window);
}
