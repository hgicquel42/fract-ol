/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:28:16 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/09 17:31:36 by hgicquel         ###   ########.fr       */
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
	int		depth;
	int		size;
	int		endian;

	s->zoom = 200;
	if (s->type == 1)
		mandelbrot_init(s);
	if (s->type == 2)
		julia_init(s);
	if (s->type == 3)
		burningship_init(s);
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, WIDTH, HEIGHT, "Hello world!");
	s->img = mlx_new_image(s->mlx, WIDTH, HEIGHT);
	s->arr = mlx_get_data_addr(s->img, &depth, &size, &endian);
	mlx_hook(s->win, 17, 0, on_close, s);
	mlx_key_hook(s->win, on_key, s);
	mlx_mouse_hook(s->win, on_mouse, s);
	mlx_do_key_autorepeaton(s->mlx);
	on_draw(s);
	mlx_loop(s->mlx);
}

int	print_help(void)
{
	printf("julia, mandelbrot, burningship\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_state	s;

	if (argc < 2)
		return (print_help());
	s.type = 0;
	if (!ft_strcmp(argv[1], "mandelbrot"))
		s.type = 1;
	if (!ft_strcmp(argv[1], "burningship"))
		s.type = 3;
	if (!ft_strcmp(argv[1], "julia"))
	{
		s.type = 2;
		if (argc > 2 && !ft_strcmp(argv[2], "1"))
			s.type2 = 1;
		else if (argc > 2 && !ft_strcmp(argv[2], "2"))
			s.type2 = 2;
		else
			s.type2 = 1;
	}
	if (!s.type)
		return (print_help());
	init(&s);
	return (0);
}
