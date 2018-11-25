/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_rects_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:07:30 by aziabkin          #+#    #+#             */
/*   Updated: 2018/10/19 14:07:31 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	load_rects_walls_13(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'c')
	{
		all->rects->r = 102;
		all->rects->g = 51;
		all->rects->b = 0;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'b')
	{
		all->rects->r = 97;
		all->rects->g = 69;
		all->rects->b = 5;
	}
	load_rects_pos(all);
}

void	load_rects_walls_12(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'd')
	{
		all->rects->r = 0;
		all->rects->g = 102;
		all->rects->b = 0;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'z')
	{
		all->rects->r = 153;
		all->rects->g = 76;
		all->rects->b = 0;
	}
	load_rects_pos(all);
}

void	load_rects_walls_11(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'r')
	{
		all->rects->r = 153;
		all->rects->g = 153;
		all->rects->b = 255;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'n')
	{
		all->rects->r = 0;
		all->rects->g = 51;
		all->rects->b = 102;
	}
	load_rects_pos(all);
}

void	load_rects_walls_10(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'a')
	{
		all->rects->r = 82;
		all->rects->g = 0;
		all->rects->b = 50;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'm')
	{
		all->rects->r = 255;
		all->rects->g = 255;
		all->rects->b = 153;
	}
	load_rects_pos(all);
}

void	load_rects_walls_9(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'l')
	{
		all->rects->r = 0;
		all->rects->g = 255;
		all->rects->b = 60;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 't')
	{
		all->rects->r = 224;
		all->rects->g = 224;
		all->rects->b = 224;
	}
	load_rects_pos(all);
}
