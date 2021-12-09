/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:50:44 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/09 17:36:14 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_state *s)
{
	s->mousex = -4.6;
	s->mousey = -2.5;
}

int	julia_calc1(t_state *s, double x, double y)
{
	size_t	i;
	t_cnum	c;
	t_cnum	z;
	double	tmp;

	i = 0;
	c.r = 0.3;
	c.i = 0.5;
	z.r = x / s->zoom + s->mousex;
	z.i = y / s->zoom + s->mousey;
	while ((z.r * z.r) + (z.i * z.i) < 4 && i < 100)
	{
		tmp = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	if (i == 100)
		return (0x000000);
	else
		return (colorize(i));
}

int	julia_calc2(t_state *s, double x, double y)
{
	size_t	i;
	t_cnum	c;
	t_cnum	z;
	double	tmp;

	i = 0;
	c.r = 0.285;
	c.i = 0.01;
	z.r = x / s->zoom + s->mousex;
	z.i = y / s->zoom + s->mousey;
	while ((z.r * z.r) + (z.i * z.i) < 4 && i < 100)
	{
		tmp = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	if (i == 100)
		return (0x000000);
	else
		return (colorize(i));
}
