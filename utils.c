/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:21:10 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/07 18:18:28 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_memcpy(char *a, char *b, size_t l)
{
	size_t	i;

	i = -1;
	while (++i < l)
		a[i] = b[i];
}

void	ft_putpxl(char *p, int color)
{
	ft_memcpy(p, (char *)&color, sizeof(int));
}

void	draw(int x, int y, int color)
{
	ft_putpxl(g_arr + (y * 4 * WIDTH) + (x * 4), color);
}

void	draw_all(int (*drawer)(int, int))
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			draw(x, y, drawer(x, y));
			y++;
		}
		x++;
	}
}
