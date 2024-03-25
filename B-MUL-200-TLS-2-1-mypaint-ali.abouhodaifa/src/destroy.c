/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** destroy and free functions
*/

#include "../include/my.h"

static void destroy_image(image_t *image)
{
    sfImage_destroy(image->paint_place);
    sfSprite_destroy(image->sprite);
    sfTexture_destroy(image->texture);
    free(image->size);
    free(image->position);
    free(image);
}

static void destroy_window(window_t *window)
{
    sfRenderWindow_destroy(window->window);
    sfClock_destroy(window->clock);
    destroy_image(window->image);
    free(window->event);
    free(window);
}

static void destroy_pencil(pencil_t *pencil)
{
    sfCircleShape_destroy(pencil->shape);
    free(pencil->color);
    free(pencil);
}

static void destroy_eraser(eraser_t *eraser)
{
    sfCircleShape_destroy(eraser->circle);
    sfRectangleShape_destroy(eraser->rectangle);
    free(eraser->color);
    free(eraser);
}

static void destroy_button(buttons_t *button)
{
    if (button != NULL) {
        free(button->size);
        free(button->position);
        free(button);
    }
}

static void destroy_tool_bar(toolbar_t *toolbar)
{
    destroy_button(toolbar->first_but);
    destroy_button(toolbar->sec_but);
    destroy_button(toolbar->third_but);
    destroy_button(toolbar->fourth_but);
    free(toolbar);
}

void destroy_main_struct(paint_t *main_struct)
{
    destroy_window(main_struct->window);
    destroy_pencil(main_struct->pencil);
    destroy_eraser(main_struct->eraser);
    destroy_tool_bar(main_struct->file);
    destroy_tool_bar(main_struct->edit);
    destroy_tool_bar(main_struct->help);
    free(main_struct);
}
