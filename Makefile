all:
	gcc -Wall -Wextra -Werror -I minilibx *.c -Lminilibx -lm -lmlx -lXext -lX11