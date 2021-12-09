/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:21:10 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/09 12:06:23 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_memcpy(char *a, char *b, size_t l)
{
	size_t	i;

	i = -1;
	while (++i < l)
		a[i] = b[i];
}

void	draw(t_state *s, int x, int y, int color)
{
	ft_memcpy(s->arr + (y * 4 * WIDTH) + (x * 4), (char *)&color, sizeof(int));
}

void	draw_all(t_state *s, int (*drawer)(t_state *, double, double))
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			draw(s, x, y, drawer(s, x, y));
			y++;
		}
		x++;
	}
}

int	colorize(double i)
{
	double	x;
	int		y;

	x = i / 100;
	y = x * 0xFFFF;
	return (0xFF << 16 | y);
}
