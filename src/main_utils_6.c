/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:44:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:44:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/dn_inc.h"

void		animate_gun(t_sdl *sdl)
{
	if (sdl->gui.gun_type != G_NOTHING && sdl->map.has_guns)
	{
		if (!sdl->gui.fire)
		{
			SDL_BlitScaled(sdl->gui.texture, sdl->gui.walk_anim, sdl->screen,
			&(SDL_Rect) {sdl->gui.x_draw, sdl->gui.y_draw + sdl->gui.gr_r,
			sdl->gui.x_draw_m, sdl->gui.y_draw_m});
		}
		else
		{
			Mix_PlayChannel(-1, sdl->gui.fire_sound, 0);
			SDL_BlitScaled(sdl->gui.texture,
			&sdl->gui.fire_anim[(SDL_GetTicks() / 100) % 2], sdl->screen,
			&(SDL_Rect) {sdl->gui.x_draw, sdl->gui.y_draw + sdl->gui.gr_r,
			sdl->gui.x_draw_m, sdl->gui.y_draw_m});
			sdl->gui.fire = 0;
		}
	}
}

int			check_exit(t_sdl *sdl)
{
	return ((int)sdl->map.player.pos_x == sdl->gui.x_go_to &&
			(int)sdl->map.player.pos_y == sdl->gui.y_go_to);
}

SDL_Surface	*create_surface(SDL_Surface *walls, int i, int j)
{
	SDL_Surface	*en;
	SDL_Surface	*ret;

	en = SDL_CreateRGBSurface(0, 64, 64, 32, 0, 0, 0, 0);
	SDL_BlitSurface(walls, &(SDL_Rect){j * 64, i * 64, 64, 64},
					en, &(SDL_Rect){0, 0, 64, 64});
	ret = SDL_DuplicateSurface(en);
	SDL_FreeSurface(en);
	return (ret);
}
