/*
** EPITECH PROJECT, 2023
** mylist
** File description:
** struct of a linked list
*/


#ifndef MYLIST
    #define MYLIST
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Vector2.h>
    #include <unistd.h>

typedef struct pencil_s {
    int size;
    sfCircleShape *shape;
    sfColor *color;
} pencil_t;

typedef struct eraser_s {
    int size;
    int state;
    sfCircleShape *circle;
    sfRectangleShape *rectangle;
    sfColor *color;
} eraser_t;

typedef struct button_s {
    sfVector2f *size;
    sfVector2f *position;
    sfSprite *sprite;
    int state;
} buttons_t;

typedef struct toolbar_s {
    buttons_t *first_but;
    buttons_t *sec_but;
    buttons_t *third_but;
    buttons_t *fourth_but;
} toolbar_t;

typedef struct image_s {
    sfImage *paint_place;
    sfVector2i *size;
    sfVector2f *position;
    sfTexture *texture;
    sfSprite *sprite;
} image_t;

typedef struct window_s {
    sfRenderWindow *window;
    sfClock *clock;
    sfEvent *event;
    image_t *image;
} window_t;

typedef struct paint_s {
    window_t *window;
    pencil_t *pencil;
    eraser_t *eraser;
    toolbar_t *file;
    toolbar_t *edit;
    toolbar_t *help;
} paint_t;

//str functions

int cmp(char *str, char *str2);
void my_putstr(char *str);

//init struct functions

paint_t *init_main_struct(char **env);
void init_button_position(paint_t *main_struct);

//destroy functions

void destroy_main_struct(paint_t *main_struct);

//core function

void check_mouse_position(paint_t *main_struct);
void check_window_size(paint_t *main_struct);
void display_buttons(paint_t *main_struct);
void render_main_window(paint_t *main_struct);
void draw(paint_t *main_struct, sfVector2f *mouse);

#endif
