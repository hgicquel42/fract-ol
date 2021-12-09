/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:28:16 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/09 12:22:55 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *a, char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}

void	init(t_state *s)
{
	s->zoom = 200;
	if (s->type == 1)
		mandelbrot_init(s);
	if (s->type == 2)
		julia_init(s);
	if (s->type == 3)
		burningship_init(s);
}

int	print_help(void)
{
	printf("julia, mandelbrot\n");
	return (1);
}

int	main(int argc, char **argv)
{
	int		depth;
	int		size;
	int		endian;
	t_state	state;

	if (argc < 2)
		return (print_help());
	state.type = 0;
	if (!ft_strcmp(argv[1], "mandelbrot"))
		state.type = 1;
	if (!ft_strcmp(argv[1], "julia"))
		state.type = 2;
	if (!ft_strcmp(argv[1], "burningship"))
		state.type = 3;
	if (!state.type)
		return (print_help());
	init(&state);
	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, WIDTH, HEIGHT, "Hello world!");
	state.img = mlx_new_image(state.mlx, WIDTH, HEIGHT);
	state.arr = mlx_get_data_addr(state.img, &depth, &size, &endian);
	mlx_hook(state.win, 17, 0, on_close, &state);
	mlx_key_hook(state.win, on_key, &state);
	mlx_mouse_hook(state.win, on_mouse, &state);
	mlx_do_key_autorepeaton(state.mlx);
	on_draw(&state);
	mlx_loop(state.mlx);
	return (0);
}
