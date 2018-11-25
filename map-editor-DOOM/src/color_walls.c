/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:13:53 by aziabkin          #+#    #+#             */
/*   Updated: 2018/10/18 15:13:55 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	color_walls_4(int x_mouse, int y_mouse, t_all *all)
{
	if (y_mouse >= 114 && y_mouse <= 187 && x_mouse >= 1143 && x_mouse <= 1184)
	{
		all->r = 0;
		all->g = 0;
		all->b = 128;
		all->bukva = 'X';
	}
	if (y_mouse >= 188 && y_mouse <= 261 && x_mouse >= 965 && x_mouse <= 1004)
	{
		all->r = 124;
		all->g = 252;
		all->b = 0;
		all->bukva = 'O';
	}
	if (y_mouse >= 188 && y_mouse <= 261 && x_mouse >= 1008 && x_mouse <= 1045)
	{
		all->r = 255;
		all->g = 215;
		all->b = 0;
		all->bukva = 'N';
	}
}

void	color_walls_3(int x_mouse, int y_mouse, t_all *all)
{
	if (y_mouse >= 114 && y_mouse <= 187 && x_mouse >= 1008 && x_mouse <= 1045)
	{
		all->r = 188;
		all->g = 31;
		all->b = 31;
		all->bukva = 'R';
	}
	if (y_mouse >= 114 && y_mouse <= 187 && x_mouse >= 1051 && x_mouse <= 1093)
	{
		all->r = 0;
		all->g = 0;
		all->b = 205;
		all->bukva = 'B';
	}
	if (y_mouse >= 114 && y_mouse <= 187 && x_mouse >= 1096 && x_mouse <= 1139)
	{
		all->r = 165;
		all->g = 42;
		all->b = 42;
		all->bukva = 'T';
	}
}

void	color_walls_2(int x_mouse, int y_mouse, t_all *all)
{
	if (y_mouse >= 33 && y_mouse <= 112 && x_mouse >= 1096 && x_mouse <= 1139)
	{
		all->r = 25;
		all->g = 25;
		all->b = 112;
		all->bukva = 'V';
	}
	if (y_mouse >= 33 && y_mouse <= 112 && x_mouse >= 1143 && x_mouse <= 1184)
	{
		all->r = 63;
		all->g = 45;
		all->b = 33;
		all->bukva = 'W';
	}
	if (y_mouse >= 114 && y_mouse <= 187 && x_mouse >= 965 && x_mouse <= 1004)
	{
		all->r = 180;
		all->g = 173;
		all->b = 153;
		all->bukva = 'U';
	}
}

void	color_walls_1(int x_mouse, int y_mouse, t_all *all)
{
	if (y_mouse >= 33 && y_mouse <= 111 && x_mouse >= 965 && x_mouse <= 1004)
	{
		all->r = 128;
		all->g = 96;
		all->b = 2;
		all->bukva = 'Z';
	}
	if (y_mouse >= 33 && y_mouse <= 112 && x_mouse >= 1008 && x_mouse <= 1045)
	{
		all->r = 35;
		all->g = 33;
		all->b = 29;
		all->bukva = 'Y';
	}
	if (y_mouse >= 33 && y_mouse <= 112 && x_mouse >= 1051 && x_mouse <= 1093)
	{
		all->r = 82;
		all->g = 0;
		all->b = 50;
		all->bukva = 'P';
	}
}

void	color_walls(int x_mouse, int y_mouse, t_all *all)
{
	color_walls_1(x_mouse, y_mouse, all);
	color_walls_2(x_mouse, y_mouse, all);
	color_walls_3(x_mouse, y_mouse, all);
	color_walls_4(x_mouse, y_mouse, all);
	color_walls_5(x_mouse, y_mouse, all);
	color_walls_6(x_mouse, y_mouse, all);
	color_walls_7(x_mouse, y_mouse, all);
	color_walls_8(x_mouse, y_mouse, all);
	color_sprites_1(x_mouse, y_mouse, all);
	color_sprites_2(x_mouse, y_mouse, all);
	color_sprites_3(x_mouse, y_mouse, all);
	color_sprites_4(x_mouse, y_mouse, all);
	color_sprites_5(x_mouse, y_mouse, all);
	color_sprites_6(x_mouse, y_mouse, all);
}
