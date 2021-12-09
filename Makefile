NAME = fractol

INPUT = \
	main.c \
	utils.c \
	hooks.c \
	zoom.c \
	julia.c \
	mandelbrot.c \
	burningship.c \

OUTPUT = ${INPUT:.c=.o}

all:	${NAME}

.c.o:
	gcc -Wall -Wextra -Werror -I minilibx -c $< -o ${<:.c=.o}

$(NAME): ${OUTPUT}
	gcc -Wall -Wextra -Werror ${OUTPUT} -o ${NAME} -Lminilibx -lm -lmlx -lXext -lX11

clean:
	rm -f ${OUTPUT}

fclean:	clean
	rm -f ${NAME}

re:		fclean all