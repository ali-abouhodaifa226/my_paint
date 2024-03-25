/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** init button position and sprites at the start of the program
*/

#include "../include/my.h"

static sfSprite *create_sprite(char *textur)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile(textur, NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
    return sprite;
}

static void init_button(buttons_t *but, char *path)
{
    but->sprite = create_sprite(path);
    sfSprite_setPosition(but->sprite, *but->position);
    sfSprite_setScale(but->sprite, *(but->size));
}

static void set_eraser_buttons_position(toolbar_t *toolbar)
{
    toolbar->first_but->position->x = 100;
    toolbar->first_but->position->y = 50;
    toolbar->sec_but->position->x = 200;
    toolbar->sec_but->position->y = 50;
    toolbar->third_but->position->x = 100;
    toolbar->third_but->position->y = 100;
    toolbar->fourth_but->position->x = 100;
    toolbar->fourth_but->position->y = 100;
}

static void set_help_button_position(toolbar_t *toolbar)
{
    toolbar->first_but->position->x = 400;
    toolbar->first_but->position->y = 50;
}

static void init_file_buttons(toolbar_t *toolbar)
{
    init_button(toolbar->first_but, "sprites/pencil.jpg");
    return;
}

static void init_edit_buttons(toolbar_t *toolbar)
{
    set_eraser_buttons_position(toolbar);
    init_button(toolbar->first_but, "sprites/eraser.jpg");
    init_button(toolbar->sec_but, "sprites/pencil.jpg");
    init_button(toolbar->sec_but, "sprites/plus.jpg");
    init_button(toolbar->sec_but, "sprites/minus.jpg");
    return;
}

static void init_help_buttons(toolbar_t *toolbar)
{
    set_help_button_position(toolbar);
    init_button(toolbar->first_but, "sprites/help.jpg");
    return;
}

void init_button_position(paint_t *main_struct)
{
    init_file_buttons(main_struct->file);
    init_edit_buttons(main_struct->edit);
    init_help_buttons(main_struct->help);
}
