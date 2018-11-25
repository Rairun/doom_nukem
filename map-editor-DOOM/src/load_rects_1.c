/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_rects_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 10:50:14 by aziabkin          #+#    #+#             */
/*   Updated: 2018/10/19 10:50:27 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	load_rects_pos(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == '~')
	{
		all->rects->is_player = 1;
		free(all->sdl_player);
		all->sdl_player = new_rect();
		all->sdl_player->x = all->rects->sdl_rect.x + (all->half_step / 2);
		all->sdl_player->y = all->rects->sdl_rect.y + (all->half_step / 2);
	}
	else
	{
		all->rects->on_screen = 1;
	}
}

void	load_rects_walls_8(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'C')
	{
		all->rects->r = 255;
		all->rects->g = 99;
		all->rects->b = 71;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'A')
	{
		all->rects->r = 0;
		all->rects->g = 255;
		all->rects->b = 0;
	}
	load_rects_pos(all);
}

void	load_rects_walls_7(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'F')
	{
		all->rects->r = 47;
		all->rects->g = 79;
		all->rects->b = 79;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'E')
	{
		all->rects->r = 128;
		all->rects->g = 0;
		all->rects->b = 128;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'D')
	{
		all->rects->r = 0;
		all->rects->g = 0;
		all->rects->b = 0;
	}
	load_rects_pos(all);
}

void	load_rects_walls_6(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'J')
	{
		all->rects->r = 255;
		all->rects->g = 0;
		all->rects->b = 0;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'H')
	{
		all->rects->r = 85;
		all->rects->g = 107;
		all->rects->b = 47;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'G')
	{
		all->rects->r = 105;
		all->rects->g = 105;
		all->rects->b = 105;
	}
	load_rects_pos(all);
}

void	load_rects_walls_5(t_all *all)
{
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'M')
	{
		all->rects->r = 128;
		all->rects->g = 128;
		all->rects->b = 0;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'L')
	{
		all->rects->r = 0;
		all->rects->g = 100;
		all->rects->b = 0;
	}
	if (all->dogs[all->rects->y][all->rects->x + 1] == 'K')
	{
		all->rects->r = 189;
		all->rects->g = 183;
		all->rects->b = 107;
	}
	load_rects_pos(all);
}
