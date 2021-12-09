/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:04:31 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/09 12:04:43 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_state *s, double x, double y)
{
	double	zoom;

	zoom = s->zoom;
	s->zoom *= 2;
	s->mousex = (x / zoom + s->mousex) - (x / (s->zoom));
	s->mousey = (y / zoom + s->mousey) - (y / (s->zoom));
}

void	unzoom(t_state *s, double x, double y)
{
	double	zoom;

	zoom = s->zoom;
	s->zoom /= 2;
	s->mousex = (x / zoom + s->mousex) - (x / (s->zoom));
	s->mousey = (y / zoom + s->mousey) - (y / (s->zoom));
}
