/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:14:28 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/09 12:21:39 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningship_init(t_state *s)
{
	s->mousex = -4.6;
	s->mousey = -2.5;
}

int	burningship_calc(t_state *s, double x, double y)
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
	while ((z.r * z.r) + (z.i * z.i) < 4 && i < 100)
	{
		tmp = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = fabs(2 * z.i * tmp) + c.i;
		i++;
	}
	if (i == 100)
		return (0x000000);
	else
		return (colorize(i));
}
