/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rects.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:25:45 by aziabkin          #+#    #+#             */
/*   Updated: 2018/10/18 14:25:46 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_rect	*new_rect(void)
{
	t_rect		*rectangle;
	SDL_Rect	sdl_rect;

	if (!(rectangle = (t_rect *)malloc(sizeof(t_rect))))
		return (NULL);
	sdl_rect.x = 0;
	sdl_rect.y = 0;
	sdl_rect.w = 0;
	sdl_rect.h = 0;
	rectangle->r = 255;
	rectangle->g = 0;
	rectangle->b = 255;
	rectangle->x = 0;
	rectangle->y = 0;
	rectangle->sdl_rect = sdl_rect;
	rectangle->index = 0;
	rectangle->is_player = 0;
	rectangle->on_screen = 0;
	rectangle->next = NULL;
	return (rectangle);
}

void	put_rect(t_all *all, int ix, int iy)
{
	all->rects->sdl_rect.x = all->points->x;
	all->rects->sdl_rect.y = all->points->y;
	all->rects->sdl_rect.w = all->half_step * 2;
	all->rects->sdl_rect.h = all->half_step * 2;
	all->rects->x = ix;
	all->rects->y = iy;
}

void	create_list_rects_1(t_all *all, int *ix, int *iy, int *ind)
{
	if (all->points->right && all->points->down &&\
				all->points->diag1 && (*ind)++ < (all->w - 1) * (all->h - 1))
	{
		if (++(*iy) == all->h - 1)
		{
			if (*iy == all->h - 1)
				(*ix)++;
			*iy = 0;
		}
		put_rect(all, *ix, *iy);
		if (*ind < (all->w - 1) * (all->h - 1))
		{
			all->rects->next = new_rect();
			all->rects = all->rects->next;
		}
	}
}

void	create_list_rects(t_all *all)
{
	t_rect	*start;
	int		index;
	int		iy;
	int		ix;

	index = 0;
	iy = -1;
	ix = -1;
	start = all->rects;
	while (all->points)
	{
		create_list_rects_1(all, &ix, &iy, &index);
		all->points = all->points->next;
	}
	all->rects->next = NULL;
	all->rects = start;
	while (all->rects)
	{
		all->rects = all->rects->next;
	}
}
