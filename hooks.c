/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:04:01 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/09 17:33:43 by hgicquel         ###   ########.fr       */
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
	if (code == KEY_ESC)
		return (on_close(s));
	if (code == KEY_LEFT)
		s->mousex -= 100 / s->zoom;
	if (code == KEY_RIGHT)
		s->mousex += 100 / s->zoom;
	if (code == KEY_UP)
		s->mousey -= 100 / s->zoom;
	if (code == KEY_DOWN)
		s->mousey += 100 / s->zoom;
	on_draw(s);
	return (0);
}

int	on_draw(t_state *s)
{
	if (s->type == 1)
		draw_all(s, mandelbrot_calc);
	if (s->type == 3)
		draw_all(s, burningship_calc);
	if (s->type == 2 && s->type2 == 1)
		draw_all(s, julia_calc1);
	if (s->type == 2 && s->type2 == 2)
		draw_all(s, julia_calc2);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	return (0);
}

int	on_mouse(int code, int x, int y, t_state *s)
{
	static bool	lock = false;

	if (lock)
		return (0);
	lock = true;
	if (code == 4 || code == 1)
		zoom(s, x, y);
	if (code == 5 || code == 2)
		unzoom(s, x, y);
	on_draw(s);
	lock = false;
	return (0);
}
