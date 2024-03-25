##
## EPITECH PROJECT, 2023
## makefile
## File description:
## Make File
##


SRC	=		src/main.c 						\
			src/init_struct.c 				\
			src/str_cmp.c 					\
			src/window_scaling.c 			\
			src/tool_bar.c 					\
			src/buttons_functions.c 		\
			src/check_mousse_position.c 	\
			src/drawing_functions.c 		\
			src/destroy.c 					\
			src/init_button_position.c      \
			src/render_window.c             \
			src/painting_place_function.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_paint

WARN_FLAG := -g3 -Wall -Wextra -Werror

CSFML_FLAG := -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(WARN_FLAG) $(CSFML_FLAG)

clean:
	rm -f *.o

re:	fclean all

fclean:	clean
	rm -f $(OBJ)
	rm -f $(NAME)
	rm -f *.gcda
	rm -f *.gcno
