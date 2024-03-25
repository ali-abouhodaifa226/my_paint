/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** functions relate to image where draw on
*/

#include "../include/my.h"


static void pencil_drawing(paint_t *main_struct, sfVector2f *mouse)
{
    sfCircleShape_setPosition(main_struct->pencil->shape, *mouse);
    sfRenderWindow_drawCircleShape(main_struct->window->window,
    main_struct->pencil->shape, NULL);
}

static void eraser(paint_t *main_struct)
{
    sfConvexShape *shape = NULL;
    sfShape *test = NULL;

    test = sfShape_create(NULL, NULL, NULL);
    shape = sfConvexShape_create();
    sfRenderWindow_drawShape(main_struct->window->window, test, NULL);
    sfRenderWindow_drawConvexShape(main_struct->window->window, shape, NULL);
    sfRenderWindow_drawRectangleShape(main_struct->window->window,
    main_struct->eraser->rectangle, NULL);
}

void draw(paint_t *main_struct, sfVector2f *mouse)
{
    if (main_struct->edit->first_but->state == 200)
        pencil_drawing(main_struct, mouse);
    if (main_struct->edit->first_but->state == 90)
        eraser(main_struct);
}
