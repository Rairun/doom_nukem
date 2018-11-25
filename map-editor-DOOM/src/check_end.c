/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:39:36 by aziabkin          #+#    #+#             */
/*   Updated: 2018/10/04 18:36:06 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	pos_player_1(t_all *all)
{
	if (all->sdl_player == NULL && all->rects->on_screen == 0)
	{
		all->rects->is_player = 1;
		all->sdl_player = new_rect();
		all->sdl_player->x = all->rects->sdl_rect.x + (all->half_step / 2);
		all->sdl_player->y = all->rects->sdl_rect.y + (all->half_step / 2);
		all->dogs[all->rects->y][all->rects->x + 1] = '~';
	}
	else if (all->rects->is_player == 1)
	{
		all->rects->is_player = 0;
		free(all->sdl_player);
		all->sdl_player = NULL;
		all->dogs[all->rects->y][all->rects->x + 1] = ' ';
	}
}

int		pos_player(int x_mouse, int y_mouse, t_all *all, int h_st)
{
	while (all->rects)
	{
		if (y_mouse > all->rects->sdl_rect.y && y_mouse <=\
			all->rects->sdl_rect.y + (h_st * 2)\
			&& x_mouse > all->rects->sdl_rect.x && x_mouse <=\
			all->rects->sdl_rect.x + (h_st * 2))
		{
			pos_player_1(all);
			all->rects = all->r_start;
			return (1);
		}
		all->rects = all->rects->next;
	}
	all->rects = all->r_start;
	return (0);
}

void	check_r_1(t_all *all)
{
	if (all->rects->on_screen == 0 && all->rects->is_player == 0)
	{
		all->rects->on_screen = 1;
		all->rects->r = all->r;
		all->rects->g = all->g;
		all->rects->b = all->b;
		all->dogs[all->rects->y][all->rects->x + 1] = all->bukva;
	}
	else if (all->rects->is_player == 0)
	{
		all->rects->on_screen = 0;
		all->dogs[all->rects->y][all->rects->x + 1] = ' ';
	}
}

int		check_r(int x_mouse, int y_mouse, t_all *all, int h_st)
{
	t_rect *start;

	start = all->rects;
	while (all->rects)
	{
		if (y_mouse > all->rects->sdl_rect.y && y_mouse <=\
			all->rects->sdl_rect.y + (h_st * 2)
			&& x_mouse > all->rects->sdl_rect.x && x_mouse <=\
			all->rects->sdl_rect.x + (h_st * 2))
		{
			check_r_1(all);
			all->rects = start;
			return (1);
		}
		all->rects = all->rects->next;
	}
	all->rects = start;
	return (0);
}
