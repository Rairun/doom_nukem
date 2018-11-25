/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:42:41 by aziabkin          #+#    #+#             */
/*   Updated: 2018/09/20 17:42:43 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	draw(t_all *all, int x, int y)
{
	SDL_RenderDrawPoint(all->rend, x + 1, y + 1);
	SDL_RenderDrawPoint(all->rend, x + 1, y);
	SDL_RenderDrawPoint(all->rend, x + 1, y - 1);
	SDL_RenderDrawPoint(all->rend, x, y + 1);
	SDL_RenderDrawPoint(all->rend, x, y - 1);
	SDL_RenderDrawPoint(all->rend, x, y);
	SDL_RenderDrawPoint(all->rend, x - 1, y + 1);
	SDL_RenderDrawPoint(all->rend, x - 1, y);
	SDL_RenderDrawPoint(all->rend, x - 1, y - 1);
}

void	draw_r_pl(t_all *all)
{
	while (all->rects)
	{
		if (all->rects->on_screen == 1)
		{
			all->r_walls.x = all->rects->sdl_rect.x;
			all->r_walls.y = all->rects->sdl_rect.y;
			all->r_walls.w = all->half_step * 2;
			all->r_walls.h = all->half_step * 2;
			SDL_SetRenderDrawColor(all->rend, all->rects->r,\
								all->rects->g, all->rects->b, 0);
			SDL_RenderFillRect(all->rend, &all->r_walls);
		}
		all->rects = all->rects->next;
	}
	all->rects = all->r_start;
	if (all->sdl_player != NULL)
	{
		SDL_SetRenderDrawColor(all->rend, 255, 0, 127, 0);
		all->r_player.x = all->sdl_player->x;
		all->r_player.y = all->sdl_player->y;
		all->r_player.w = (all->half_step * 2) * 0.5;
		all->r_player.h = (all->half_step * 2) * 0.5;
		SDL_RenderFillRect(all->rend, &all->r_player);
	}
}

void	sdl_event_1(t_all *all, int x_mouse, int y_mouse)
{
	if (all->e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (all->e.button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&x_mouse, &y_mouse);
			check_r(x_mouse, y_mouse, all, all->half_step);
		}
		if (all->e.button.button == SDL_BUTTON_RIGHT)
		{
			SDL_GetMouseState(&x_mouse, &y_mouse);
			pos_player(x_mouse, y_mouse, all, all->half_step);
		}
	}
}

void	sdl_event(t_all *all, int x_mouse, int y_mouse, char *way)
{
	while (SDL_PollEvent(&all->e) != 0)
	{
		if (all->e.type == SDL_QUIT || all->e.key.keysym.scancode ==\
			SDL_SCANCODE_ESCAPE)
		{
			all->quit = true;
		}
		else if (all->e.type == SDL_MOUSEBUTTONDOWN)
		{
			SDL_GetMouseState(&x_mouse, &y_mouse);
			color_walls(x_mouse, y_mouse, all);
		}
		else if (all->e.type == SDL_KEYDOWN)
		{
			if (all->e.key.keysym.sym == SDLK_RETURN)
			{
				close(all->fd);
				all->fd = open(way, O_RDWR);
				write_map(all);
			}
		}
		sdl_event_1(all, x_mouse, y_mouse);
	}
}

void	general_draw(t_all *all, t_points *start, char *way)
{
	int	x_mouse;
	int	y_mouse;

	all->quit = false;
	x_mouse = 0;
	y_mouse = 0;
	while (!all->quit)
	{
		sdl_event(all, x_mouse, y_mouse, way);
		SDL_SetRenderDrawColor(all->rend, 255, 233, 168, 0);
		SDL_RenderClear(all->rend);
		SDL_SetRenderDrawColor(all->rend, 0x00, 0x00, 0x00, 0x00);
		draw_points(all, start);
		draw_r_pl(all);
		SDL_RenderCopy(all->rend, all->texture, NULL, &all->menu);
		SDL_RenderPresent(all->rend);
	}
	SDL_DestroyTexture(all->texture);
	IMG_Quit();
	f_close(all);
}
