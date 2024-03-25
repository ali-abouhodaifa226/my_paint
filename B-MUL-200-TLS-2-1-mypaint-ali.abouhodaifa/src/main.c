/*
** EPITECH PROJECT, 2024
** My_paint
** File description:
** main
*/

#include "../include/my.h"

static int h_option(void)
{
    my_putstr("USAGE\n\t./my_paint\n");
    my_putstr("DESCRIPTION\n\tmy_paint is a remake of a classic paint\n");
    my_putstr("\tYou can open, create and save file\n\t");
    my_putstr("The only limit is your creativity\n");
}

static void close_window(sfEvent *event, sfRenderWindow *window)
{
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}

static int my_paint(char **env)
{
    paint_t *main_struct = NULL;
    sfTime tmp;

    main_struct = init_main_struct(env);
    while (sfRenderWindow_isOpen(main_struct->window->window)) {
        close_window(main_struct->window->event, main_struct->window->window);
        tmp = sfClock_getElapsedTime(main_struct->window->clock);
        if (tmp.microseconds > 300000) {
            check_window_size(main_struct);
            check_mouse_position(main_struct);
            sfRenderWindow_clear(main_struct->window->window, sfWhite);
            display_buttons(main_struct);
            render_main_window(main_struct);
            sfRenderWindow_display(main_struct->window->window);
            sfClock_restart(main_struct->window->clock);
        }
    }
    destroy_main_struct(main_struct);
    return 0;
}

int main(int argc, char **argv, char **env)
{
    if (argc == 1)
        return my_paint(env);
    if (argc == 2 && cmp(argv[1], "-h") == 0)
        return h_option();
    return 84;
}
