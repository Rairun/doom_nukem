/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:55:55 by psaprono          #+#    #+#             */
/*   Updated: 2018/10/27 15:55:59 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/dn_inc.h"

void	set_ceiling(t_sdl *sdl, const int k[5], unsigned int *pixels, int col)
{
	if (pixels[k[0] + SCREEN_WIDTH *
								(SCREEN_HEIGHT + sdl->up_down - k[1])] == BACK)
		pixels[k[0] + SCREEN_WIDTH * (SCREEN_HEIGHT + sdl->up_down - k[1])] =
		fade_to_black(col, sdl->render.current_dist, sdl->floor_shade);
}

int		fade_to_black(int col, double curr, double max)
{
	double	rgb[3];
	double	amount;

	if (curr < 0)
		return (curr);
	if (curr >= max)
		return (0x0);
	rgb[0] = col & 255;
	rgb[1] = (col >> 8) & 255;
	rgb[2] = (col >> 16) & 255;
	amount = (max - curr) / max;
	rgb[0] *= amount;
	rgb[1] *= amount;
	rgb[2] *= amount;
	return ((((int)rgb[2]) << 16) + ((int)rgb[1] << 8) + rgb[0]);
}

double	line_length(double ax, double ay, double bx, double by)
{
	return (sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)));
}

double	dist_to_camera(t_sdl *sdl, t_enemy *en)
{
	if (en == NULL)
	{
		return (line_length(sdl->map.player.pos_x, sdl->map.player.pos_y,
		sdl->map.map[sdl->render.map_y][sdl->render.map_x].sprite.x,
		sdl->map.map[sdl->render.map_y][sdl->render.map_x].sprite.y));
	}
	return (line_length(sdl->map.player.pos_x, sdl->map.player.pos_y,
		en->pos_x, en->pos_y));
}
