/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:29:43 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/09 11:20:38 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080

# define KEY_ESC 65307

typedef struct s_state
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*arr;
	double	zoom;
	double	mousex;
	double	mousey;
}	t_state;

void	draw(t_state *s, int x, int y, int color);

void	draw_all(t_state *s, int (*drawer)(t_state *, double, double));

void	mandelbrot_init(t_state *s);

int		mandelbrot(t_state *s, double x, double y);

int		colorize(double i);

#endif