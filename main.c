/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:28:16 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/08 13:17:36 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_close(t_state *s)
{
	mlx_destroy_image(s->mlx, s->img);
	mlx_destroy_window(s->mlx, s->win);
	mlx_loop_end(s->mlx);
	return (0);
}

int	on_key(int code, t_state *s)
{
	printf("%d\n", code);
	if (code == KEY_ESC)
		return (on_close(s));
	return (0);
}

int	on_draw(t_state *s)
{
	draw_all(s, mandelbrot);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	return (0);
}

void	zoom(t_state *s, double x, double y)
{
	s->mousex = (x / s->zoom + s->mousex) - (x / (s->zoom * 1.3));
	s->mousey = (y / s->zoom + s->mousey) - (y / (s->zoom * 1.3));
	s->zoom *= 1.3;
	s->imax++;
}

void	unzoom(t_state *s, double x, double y)
{
	s->mousex = (x / s->zoom + s->mousex) - (x / (s->zoom / 1.3));
	s->mousey = (y / s->zoom + s->mousey) - (y / (s->zoom / 1.3));
	s->zoom /= 1.3;
	s->imax--;
}

int	on_mouse(int code, int x, int y, t_state *s)
{
	(void)x;
	(void)y;
	if (code == 4 || code == 1)
		zoom(s, x, y);
	if (code == 5 || code == 2)
		unzoom(s, x, y);
	on_draw(s);
	return (0);
}

int	main(void)
{
	int		depth;
	int		size;
	int		endian;
	t_state	state;

	state.mlx = mlx_init();
	state.win = mlx_new_window(state.mlx, WIDTH, HEIGHT, "Hello world!");
	state.img = mlx_new_image(state.mlx, WIDTH, HEIGHT);
	state.arr = mlx_get_data_addr(state.img, &depth, &size, &endian);
	mandelbrot_init(&state);
	mlx_hook(state.win, 17, 0, on_close, &state);
	mlx_key_hook(state.win, on_key, &state);
	mlx_mouse_hook(state.win, on_mouse, &state);
	mlx_do_key_autorepeaton(state.mlx);
	on_draw(&state);
	mlx_loop(state.mlx);
	return (0);
}
