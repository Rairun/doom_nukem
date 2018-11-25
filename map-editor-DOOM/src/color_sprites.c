/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:38:01 by aziabkin          #+#    #+#             */
/*   Updated: 2018/10/19 11:38:03 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	color_sprites_5(int x_mouse, int y_mouse, t_all *all)
{
	if (y_mouse >= 804 && y_mouse <= 879 && x_mouse >= 951 && x_mouse <= 999)
	{
		all->r = 102;
		all->g = 102;
		all->b = 255;
		all->bukva = 'y';
	}
	if (y_mouse >= 804 && y_mouse <= 879 && x_mouse >= 1000 && x_mouse <= 1061)
	{
		all->r = 32;
		all->g = 32;
		all->b = 32;
		all->bukva = 'q';
	}
	if (y_mouse >= 804 && y_mouse <= 879 && x_mouse >= 1062 && x_mouse <= 1119)
	{
		all->r = 255;
		all->g = 255;
		all->b = 204;
		all->bukva = '*';
	}
}

void	color_sprites_4(int x_mouse, int y_mouse, t_all *all)
{
	if (y_mouse >= 717 && y_mouse <= 7990 && x_mouse >= 1000 && x_mouse <= 1061)
	{
		all->r = 97;
		all->g = 69;
		all->b = 5;
		all->bukva = 'b';
	}
	if (y_mouse >= 717 && y_mouse <= 799 && x_mouse >= 1062 && x_mouse <= 1119)
	{
		all->r = 176;
		all->g = 168;
		all->b = 150;
		all->bukva = 'p';
	}
	if (y_mouse >= 717 && y_mouse <= 799 && x_mouse >= 1120 && x_mouse <= 1199)
	{
		all->r = 64;
		all->g = 59;
		all->b = 48;
		all->bukva = 'f';
	}
}

void	color_sprites_3(int x_mouse, int y_mouse, t_all *all)
{
	if (y_mouse >= 642 && y_mouse <= 698 && x_mouse >= 1062 && x_mouse <= 1119)
	{
		all->r = 0;
		all->g = 102;
		all->b = 0;
		all->bukva = 'd';
	}
	if (y_mouse >= 642 && y_mouse <= 698 && x_mouse >= 1120 && x_mouse <= 1199)
	{
		all->r = 153;
		all->g = 76;
		all->b = 0;
		all->bukva = 'z';
	}
	if (y_mouse >= 717 && y_mouse <= 799 && x_mouse >= 951 && x_mouse <= 999)
	{
		all->r = 102;
		all->g = 51;
		all->b = 0;
		all->bukva = 'c';
	}
}

void	color_sprites_2(int x_mouse, int y_mouse, t_all *all)
{
	if (y_mouse >= 529 && y_mouse <= 570 && x_mouse >= 1120 && x_mouse <= 1199)
	{
		all->r = 255;
		all->g = 255;
		all->b = 153;
		all->bukva = 'm';
	}
	if (y_mouse >= 642 && y_mouse <= 698 && x_mouse >= 951 && x_mouse <= 999)
	{
		all->r = 153;
		all->g = 153;
		all->b = 255;
		all->bukva = 'r';
	}
	if (y_mouse >= 642 && y_mouse <= 698 && x_mouse >= 1000 && x_mouse <= 1061)
	{
		all->r = 0;
		all->g = 51;
		all->b = 102;
		all->bukva = 'n';
	}
}

void	color_sprites_1(int x_mouse, int y_mouse, t_all *all)
{
	if (y_mouse >= 529 && y_mouse <= 570 && x_mouse >= 951 && x_mouse <= 999)
	{
		all->r = 0;
		all->g = 255;
		all->b = 60;
		all->bukva = 'l';
	}
	if (y_mouse >= 529 && y_mouse <= 570 && x_mouse >= 1000 && x_mouse <= 1061)
	{
		all->r = 224;
		all->g = 224;
		all->b = 224;
		all->bukva = 't';
	}
	if (y_mouse >= 529 && y_mouse <= 570 && x_mouse >= 1062 && x_mouse <= 1119)
	{
		all->r = 82;
		all->g = 0;
		all->b = 50;
		all->bukva = 'a';
	}
}
