/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:50:44 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/09 12:08:20 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_state *s)
{
	s->zoom = 300;
	s->mousex = -3;
	s->mousey = -1.5;
}

int	julia_calc(t_state *s, double x, double y)
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
