/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_rects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 10:34:06 by aziabkin          #+#    #+#             */
/*   Updated: 2018/10/19 10:34:07 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	load_rects_walls_4(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'X')
	{
		all->rects->r = 0;
		all->rects->g = 0;
		all->rects->b = 128;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'O')
	{
		all->rects->r = 124;
		all->rects->g = 252;
		all->rects->b = 0;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'N')
	{
		all->rects->r = 255;
		all->rects->g = 215;
		all->rects->b = 0;
	}
	load_rects_pos(all);
}

void	load_rects_walls_3(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'R')
	{
		all->rects->r = 188;
		all->rects->g = 31;
		all->rects->b = 31;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'B')
	{
		all->rects->r = 0;
		all->rects->g = 0;
		all->rects->b = 205;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'T')
	{
		all->rects->r = 165;
		all->rects->g = 42;
		all->rects->b = 42;
	}
	load_rects_pos(all);
}

void	load_rects_walls_2(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'V')
	{
		all->rects->r = 25;
		all->rects->g = 25;
		all->rects->b = 112;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'W')
	{
		all->rects->r = 63;
		all->rects->g = 45;
		all->rects->b = 33;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'U')
	{
		all->rects->r = 180;
		all->rects->g = 173;
		all->rects->b = 153;
	}
	load_rects_pos(all);
}

void	load_rects_walls_1(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'Z')
	{
		all->rects->r = 128;
		all->rects->g = 96;
		all->rects->b = 2;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'Y')
	{
		all->rects->r = 35;
		all->rects->g = 33;
		all->rects->b = 29;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'P')
	{
		all->rects->r = 82;
		all->rects->g = 0;
		all->rects->b = 50;
	}
	load_rects_pos(all);
}

void	load_rects(t_all *all)
{
	while (all->rects)
	{
		if (all->dogs[all->rects->y][all->rects->x + 1] != ' ')
		{
			load_rects_walls_1(all);
			load_rects_walls_2(all);
			load_rects_walls_3(all);
			load_rects_walls_4(all);
			load_rects_walls_5(all);
			load_rects_walls_6(all);
			load_rects_walls_7(all);
			load_rects_walls_8(all);
			load_rects_walls_9(all);
			load_rects_walls_10(all);
			load_rects_walls_11(all);
			load_rects_walls_12(all);
			load_rects_walls_13(all);
			load_rects_walls_14(all);
			load_rects_walls_15(all);
			load_rects_walls_16(all);
			load_rects_walls_17(all);
		}
		all->rects = all->rects->next;
	}
}
