/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:29:43 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/08 12:35:13 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <time.h>
# include <stdlib.h>

# define WIDTH 1920
# define HEIGHT 1080

# define KEY_ESC 65307

extern void	*g_mlx;
extern void	*g_win;
extern void	*g_img;
extern char	*g_arr;

void	draw(int x, int y, int color);

void	draw_all(int (*drawer)(int, int));

int		mandelbrot(int x, int y);

#endif