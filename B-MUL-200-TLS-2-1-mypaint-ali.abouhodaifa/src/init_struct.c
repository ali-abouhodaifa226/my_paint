/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** init struct functions
*/

#include "../include/my.h"

static sfColor *create_color(int r, int g, int b, int a)
{
    sfColor *color = NULL;

    color = malloc(sizeof(sfColor));
    color->r = r;
    color->g = g;
    color->b = b;
    color->a = a;
    return color;
}

static sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window =
    sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);

    return window;
}

static image_t *create_image(void)
{
    image_t *image = NULL;

    image = malloc(sizeof(image_t));
    image->position = malloc(sizeof(sfVector2f));
    image->size = malloc(sizeof(sfVector2i));
    image->size->x = 1500;
    image->size->y = 800;
    image->position->x = 150.0;
    image->position->y = 150.0;
    image->paint_place = sfImage_createFromColor(image->size->x,
    image->size->y, sfGreen);
    image->texture = sfTexture_create(image->size->x, image->size->y);
    image->sprite = sfSprite_create();
    return image;
}

static window_t *create_main_window(void)
{
    window_t *window = NULL;

    window = malloc(sizeof(window_t));
    window->window = create_window();
    window->clock = sfClock_create();
    window->image = create_image();
    window->event = malloc(sizeof(sfEvent));
    return window;
}

static pencil_t *create_pencil(void)
{
    pencil_t *pencil = NULL;

    pencil = malloc(sizeof(pencil_t));
    pencil->color = create_color(0, 0, 0, 0);
    pencil->size = 1;
    pencil->shape = sfCircleShape_create();
    sfCircleShape_setRadius(pencil->shape, 1.0);
    sfCircleShape_setFillColor(pencil->shape, *pencil->color);
    return pencil;
}

static eraser_t *create_eraser(void)
{
    eraser_t *eraser = NULL;

    eraser = malloc(sizeof(eraser_t));
    eraser->size = 1;
    eraser->state = 0;
    eraser->circle = sfCircleShape_create();
    eraser->rectangle = sfRectangleShape_create();
    eraser->color = create_color(257, 257, 257, 257);
    return eraser;
}

static buttons_t *create_button(void)
{
    buttons_t *button = NULL;

    button = malloc(sizeof(buttons_t));
    button->size = malloc(sizeof(sfVector2i));
    button->position = malloc(sizeof(sfVector2f));
    button->position->x = 100;
    button->position->y = 50;
    button->size->x = 0.4;
    button->size->y = 0.4;
    button->state = 0;
    return button;
}

static toolbar_t *create_toolbar(int nb_but)
{
    toolbar_t *toolbar = NULL;

    toolbar = malloc(sizeof(toolbar_t));
    toolbar->first_but = create_button();
    toolbar->sec_but = create_button();
    if (nb_but >= 3)
        toolbar->third_but = create_button();
    else
        toolbar->third_but = NULL;
    if (nb_but >= 4)
        toolbar->fourth_but = create_button();
    else
        toolbar->fourth_but = NULL;
    return toolbar;
}

paint_t *init_main_struct(char **env)
{
    paint_t *main_struct = NULL;

    main_struct = malloc(sizeof(paint_t));
    main_struct->window = create_main_window();
    main_struct->pencil = create_pencil();
    main_struct->eraser = create_eraser();
    main_struct->edit = create_toolbar(4);
    main_struct->file = create_toolbar(4);
    main_struct->help = create_toolbar(4);
    init_button_position(main_struct);
    return main_struct;
}
