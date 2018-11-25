/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_rects_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:07:40 by aziabkin          #+#    #+#             */
/*   Updated: 2018/10/19 14:07:41 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	load_rects_walls_17(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'g')
	{
		all->rects->r = 153;
		all->rects->g = 76;
		all->rects->b = 0;
	}
	load_rects_pos(all);
}

void	load_rects_walls_16(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == '*')
	{
		all->rects->r = 255;
		all->rects->g = 225;
		all->rects->b = 204;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'w')
	{
		all->rects->r = 255;
		all->rects->g = 153;
		all->rects->b = 51;
	}
	load_rects_pos(all);
}

void	load_rects_walls_15(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'y')
	{
		all->rects->r = 102;
		all->rects->g = 102;
		all->rects->b = 255;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'q')
	{
		all->rects->r = 32;
		all->rects->g = 32;
		all->rects->b = 32;
	}
	load_rects_pos(all);
}

void	load_rects_walls_14(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'p')
	{
		all->rects->r = 176;
		all->rects->g = 168;
		all->rects->b = 150;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'f')
	{
		all->rects->r = 64;
		all->rects->g = 59;
		all->rects->b = 48;
	}
	load_rects_pos(all);
}
