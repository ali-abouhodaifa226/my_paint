/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** render everything functions
*/

#include "../include/my.h"

static void render_paint_place(image_t *image, sfRenderWindow *window)
{
    sfColor *color = NULL;

    color = malloc(sizeof(color));
    color->a = 255;
    color->r = 255;
    color->g = 255;
    color->b = 255;
    image->texture = sfTexture_createFromImage(image->paint_place, NULL);
    sfSprite_setTexture(image->sprite, image->texture, 0);
    sfSprite_setColor(image->sprite, *color);
    sfSprite_setPosition(image->sprite, *(image->position));
    sfRenderWindow_drawSprite(window, image->sprite, NULL);
}

void render_main_window(paint_t *main_struct)
{
    render_paint_place(main_struct->window->image,
    main_struct->window->window);
}
