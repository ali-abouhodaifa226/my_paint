/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** check mousse position
*/

#include "../include/my.h"

static int is_in(sfVector2i mouse, sfVector2f pos, sfVector2i size)
{
    if ((mouse.x >= pos.x && mouse.x <= pos.x + size.x) &&
    (mouse.y >= pos.y && mouse.y <= pos.y + size.y))
        return 1;
    return -1;
}

static sfVector2i *convert(sfVector2f *vec)
{
    sfVector2i *new = NULL;

    new = malloc(sizeof(sfVector2i));
    new->x = (float)vec->x;
    new->y = (float)vec->y;
    return new;
}

void check_button(paint_t *main_struct, sfVector2i *mouse)
{
    sfVector2i *vec = convert(main_struct->edit->first_but->size);

    if (is_in(*mouse, *main_struct->edit->first_but->position, *vec)) {
        printf("je suis dedans\n");
        if (main_struct->window->event->type == sfEvtMouseButtonPressed)
            main_struct->edit->first_but->state = 2;
    }
}

static sfVector2f *convert_mouse(sfVector2i *mouse)
{
    sfVector2f *new = NULL;

    new = malloc(sizeof(sfVector2f));
    new->x = (int)mouse->x;
    new->y = (int)mouse->y;
    return new;
}

void check_mouse_position(paint_t *main_struct)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow
    (main_struct->window->window);
    sfVector2f image_p = *(main_struct->window->image->position);
    sfVector2i image_s = *(main_struct->window->image->size);
    sfVector2f *mouse_f = convert_mouse(&mouse);

    if (is_in(mouse, image_p, image_s) == 1) {
        draw(main_struct, mouse_f);
    }
    check_button(main_struct, &mouse);
    return;
}
