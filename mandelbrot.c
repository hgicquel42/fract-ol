/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:46:47 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/08 13:16:37 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_cnum
{
	double r;
	double i;
}	t_cnum;

void	mandelbrot_init(t_state *s)
{
	s->zoom = 300;
	s->mousex = -2.05;
	s->mousey = -1.3;
	s->imax = 50;
}

int	mandelbrot(t_state *s, double x, double y)
{
	size_t	i;
	t_cnum	c;
	t_cnum	z;
	double	tmp;

	i = 0;
	c.r = x / s->zoom + s->mousex;
	c.i = y / s->zoom + s->mousey;
	z.i = 0;
	z.r = 0;
	while ((z.r * z.r) + (z.i * z.i) < 4 && i < s->imax)
	{
		tmp = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	if (i == s->imax)
		return (0x000000);
	else
		return (265 * i);
}