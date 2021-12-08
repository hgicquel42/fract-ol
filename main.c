/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:28:16 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/08 12:35:35 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*g_mlx;
void	*g_win;
void	*g_img;
char	*g_arr;

int	on_close(void)
{
	mlx_destroy_image(g_mlx, g_img);
	mlx_destroy_window(g_mlx, g_win);
	mlx_loop_end(g_mlx);
	return (0);
}

int	on_key(int keycode)
{
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		return (on_close());
	return (0);
}

int	randomxy(int x, int y)
{
	(void)x;
	(void)y;
	return (rand());
}

int	on_draw(void)
{
	draw(0, 0, 0xFFFFFF);
	draw_all(mandelbrot);
	mlx_put_image_to_window(g_mlx, g_win, g_img, 0, 0);
	return (0);
}

int	mandelbrot(int x, int y)
{
	size_t	i;
	double	zoom;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;

	i = 0;
	zoom = 300;
	c_r = ((double)x) / zoom + (-2.05);
	c_i = ((double)y) / zoom + (-1.3);
	z_i = 0;
	z_r = 0;
	while ((z_r * z_r) + (z_i * z_i) < 4 && i < 50)
	{
		tmp = z_r;
		z_r = (z_r * z_r) - (z_i * z_i) + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	if (i == 50)
		return (0x000000);
	else
		return (265 * i);
}

int	main(void)
{
	int	depth;
	int	size;
	int	endian;

	g_mlx = mlx_init();
	g_win = mlx_new_window(g_mlx, WIDTH, HEIGHT, "Hello world!");
	g_img = mlx_new_image(g_mlx, WIDTH, HEIGHT);
	g_arr = mlx_get_data_addr(g_img, &depth, &size, &endian);
	mlx_hook(g_win, 17, 0, on_close, 0);
	mlx_key_hook(g_win, on_key, 0);
	mlx_do_key_autorepeaton(g_mlx);
	on_draw();
	mlx_loop(g_mlx);
	return (0);
}
