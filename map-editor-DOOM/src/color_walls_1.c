/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_walls_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:21:47 by aziabkin          #+#    #+#             */
/*   Updated: 2018/10/18 15:21:50 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	color_walls_8(int x_mouse, int y_mouse, t_all *all)
{
	if (y_mouse >= 341 && y_mouse <= 411 && x_mouse >= 1008 && x_mouse <= 1045)
	{
		all->r = 255;
		all->g = 99;
		all->b = 71;
		all->bukva = 'C';
	}
	if (y_mouse >= 341 && y_mouse <= 411 && x_mouse >= 1051 && x_mouse <= 1093)
	{
		all->r = 0;
		all->g = 255;
		all->b = 0;
		all->bukva = 'A';
	}
}

void	color_walls_7(int x_mouse, int y_mouse, t_all *all)
{
	if (y_mouse >= 264 && y_mouse <= 335 && x_mouse >= 1096 && x_mouse <= 1139)
	{
		all->r = 47;
		all->g = 79;
		all->b = 79;
		all->bukva = 'F';
	}
	if (y_mouse >= 264 && y_mouse <= 335 && x_mouse >= 1143 && x_mouse <= 1184)
	{
		all->r = 128;
		all->g = 0;
		all->b = 128;
		all->bukva = 'E';
	}
	if (y_mouse >= 341 && y_mouse <= 411 && x_mouse >= 965 && x_mouse <= 1004)
	{
		all->r = 0;
		all->g = 0;
		all->b = 0;
		all->bukva = 'D';
	}
}

void	color_walls_6(int x_mouse, int y_mouse, t_all *all)
{
	if (y_mouse >= 264 && y_mouse <= 335 && x_mouse >= 965 && x_mouse <= 1004)
	{
		all->r = 255;
		all->g = 0;
		all->b = 0;
		all->bukva = 'J';
	}
	if (y_mouse >= 264 && y_mouse <= 335 && x_mouse >= 1008 && x_mouse <= 1045)
	{
		all->r = 85;
		all->g = 107;
		all->b = 47;
		all->bukva = 'H';
	}
	if (y_mouse >= 264 && y_mouse <= 335 && x_mouse >= 1051 && x_mouse <= 1093)
	{
		all->r = 105;
		all->g = 105;
		all->b = 105;
		all->bukva = 'G';
	}
}

void	color_walls_5(int x_mouse, int y_mouse, t_all *all)
{
	if (y_mouse >= 188 && y_mouse <= 261 && x_mouse >= 1051 && x_mouse <= 1093)
	{
		all->r = 128;
		all->g = 128;
		all->b = 0;
		all->bukva = 'M';
	}
	if (y_mouse >= 188 && y_mouse <= 261 && x_mouse >= 1096 && x_mouse <= 1139)
	{
		all->r = 0;
		all->g = 100;
		all->b = 0;
		all->bukva = 'L';
	}
	if (y_mouse >= 188 && y_mouse <= 261 && x_mouse >= 1143 && x_mouse <= 1184)
	{
		all->r = 189;
		all->g = 183;
		all->b = 107;
		all->bukva = 'K';
	}
}
