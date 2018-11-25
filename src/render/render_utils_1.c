/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:00:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 10:00:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/dn_inc.h"

void	put_pixel(t_sdl *sdl, SDL_Surface *floor,
					SDL_Surface *ceiling, const int k[5])
{
	unsigned int	*pixels;
	unsigned int	*floor_pixels;
	unsigned int	*ceiling_pixels;
	int				col;

	pixels = sdl->screen->pixels;
	if (floor)
	{
		floor_pixels = floor->pixels;
		col = floor_pixels[k[2] * k[3] + k[4]];
		if (pixels[k[0] + SCREEN_WIDTH * k[1]] == 0x00FFFF)
			pixels[k[0] + SCREEN_WIDTH * k[1]] = fade_to_black(col,
			sdl->render.current_dist, sdl->floor_shade);
	}
	if (ceiling && sdl->map.has_ceiling)
	{
		ceiling_pixels = ceiling->pixels;
		col = ceiling_pixels[k[2] * k[3] + k[4]];
		if ((SCREEN_HEIGHT + sdl->up_down - k[1]) >= 0 &&
		(SCREEN_HEIGHT + sdl->up_down - k[1]) < (sdl->render.draw_start))
			set_ceiling(sdl, k, pixels, col);
	}
}

void	put_pixels_in_line(t_sdl *sdl, const int k[6], SDL_Surface *texture)
{
	unsigned int	*pixels;
	unsigned int	*texture_pixels;
	int				id;
	int				tex_y;
	int				col;

	pixels = sdl->screen->pixels;
	id = k[1] - 1;
	while (++id < k[2])
	{
		texture_pixels = texture->pixels;
		tex_y = (((id * 2 - (SCREEN_HEIGHT + sdl->up_down) + k[4]) * 64) /
			k[4]) / 2;
		while (tex_y < 0)
			tex_y += 64;
		col = texture_pixels[64 * tex_y + k[3]];
		if (pixels[k[0] + SCREEN_WIDTH * id] == 0x00FFFF)
		{
			if (k[5] == 1)
				col = fade_to_black(col, 3, FOG_DIST);
			pixels[k[0] + SCREEN_WIDTH * id] = (unsigned int)fade_to_black(col,
			sdl->render.perp_wall_dist, FOG_DIST);
		}
	}
}

void	draw_sprite(t_sdl *sdl, SDL_Surface *texture, int x, t_enemy *en)
{
	unsigned int	*pixels;
	unsigned int	*texture_pixels;
	int				tex[2];
	int				i;
	double			dist_to_cam;

	dist_to_cam = dist_to_camera(sdl, en);
	pixels = (unsigned int *)sdl->screen->pixels + (sdl->render.draw_start_y
														* SCREEN_WIDTH) + x;
	texture_pixels = texture->pixels;
	tex[0] = (int)(256 * (x - (-fabs(SCREEN_HEIGHT / sdl->render.tr_y) / 2.0 +
	(int)((SCREEN_WIDTH / 2) * (1 + sdl->render.tr_x / sdl->render.tr_y)))) *
	texture->w / fabs(SCREEN_HEIGHT / sdl->render.tr_y)) / 256;
	i = sdl->render.draw_start_y - 1;
	while (++i < sdl->render.draw_start_x)
	{
		tex[1] = (((i * 2 - SCREEN_HEIGHT + sdl->render.sprite_height -
		sdl->up_down) * texture->h) / sdl->render.sprite_height) / 2;
		if (*pixels == 0x00FFFF && tex[0] >= 0 && tex[1] >= 0 && tex[0] <
		texture->w && tex[1] < texture->w && texture_pixels[texture->w * tex[1]
		+ tex[0]] != 0x000000)
			*pixels = fade_to_black(texture_pixels[texture->w * tex[1] +
			tex[0]], dist_to_cam, FOG_DIST);
		pixels += SCREEN_WIDTH;
	}
}

void	sprite_rend_utils(t_sdl *sdl)
{
	sdl->render.sprite_x = sdl->map.map[sdl->render.map_y]
	[sdl->render.map_x].sprite.x + 0.5 - sdl->map.player.pos_x;
	sdl->render.sprite_y = sdl->map.map[sdl->render.map_y]
	[sdl->render.map_x].sprite.y + 0.5 - sdl->map.player.pos_y;
	sdl->render.inv_det = 1.0 / (sdl->map.plane_x * sdl->map.player.dir_y -
	sdl->map.player.dir_x * sdl->map.plane_y);
	sdl->render.tr_x = sdl->render.inv_det * (sdl->map.player.dir_y *
	sdl->render.sprite_x - sdl->map.player.dir_x * sdl->render.sprite_y);
	sdl->render.tr_y = sdl->render.inv_det * (-sdl->map.plane_y *
	sdl->render.sprite_x + sdl->map.plane_x * sdl->render.sprite_y);
	sdl->render.sprite_height = abs((int)(SCREEN_HEIGHT / sdl->render.tr_y));
	sdl->render.draw_start_y = -sdl->render.sprite_height / 2 + (SCREEN_HEIGHT
	+ sdl->up_down) / 2;
	sdl->render.draw_start_y = sdl->render.draw_start_y < 0 ? 0 :
	sdl->render.draw_start_y;
	sdl->render.draw_start_x = sdl->render.sprite_height / 2 + (SCREEN_HEIGHT
	+ sdl->up_down) / 2;
	sdl->render.draw_start_x = sdl->render.draw_start_x >= SCREEN_HEIGHT ?
	SCREEN_HEIGHT - 1 : sdl->render.draw_start_x;
}

void	sprite_rend(t_sdl *sdl, int j)
{
	sprite_rend_utils(sdl);
	if (sdl->map.map[sdl->render.map_y][sdl->render.map_x].sprite.type ==
		T_PICKABLE && !sdl->map.map[sdl->render.map_y]
	[sdl->render.map_x].sprite.picked)
		draw_sprite(sdl, sdl->map.map[sdl->render.map_y]
		[sdl->render.map_x].texture, j, NULL);
	else if (sdl->map.map[sdl->render.map_y][sdl->render.map_x].sprite.type
			!= T_PICKABLE)
		draw_sprite(sdl, sdl->map.map[sdl->render.map_y]
		[sdl->render.map_x].texture, j, NULL);
}
