/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 00:05:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/12 00:05:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/dn_inc.h"

void	menu_loop_util_1(t_sdl *sdl, char *map)
{
	if (!ft_strcmp(map, TEST_C))
	{
		sdl->map.map_type = NOTHING;
		sdl->map.has_ceiling = TRUE;
		sdl->map.has_guns = FALSE;
		sdl->map.ceiling = sdl->textures.bluestone;
		sdl->map.floor = sdl->textures.wood;
		parse_map(sdl, map);
	}
	else if (!ft_strcmp(map, WOLF_C))
	{
		sdl->map.map_type = KILL_ALL;
		sdl->map.has_ceiling = TRUE;
		sdl->map.has_guns = TRUE;
		sdl->map.ceiling = sdl->textures.bluestone;
		sdl->map.floor = sdl->textures.wood;
		parse_map(sdl, map);
		Mix_PlayMusic(sdl->media.wolf_map_music, -1);
	}
}

void	menu_loop_util_2(t_sdl *sdl, char *map)
{
	if (!ft_strcmp(map, LABYRINTH_C))
	{
		sdl->map.map_type = FIND_EXIT;
		sdl->map.has_ceiling = FALSE;
		sdl->map.has_guns = FALSE;
		sdl->map.floor = sdl->textures.grass;
		sdl->map.bg = sdl->textures.maze_bg;
		sdl->gui.x_go_to = 1;
		sdl->gui.y_go_to = 1;
		parse_map(sdl, map);
	}
	else if (!ft_strcmp(map, DOOM_C))
	{
		sdl->map.map_type = KILL_ALL;
		sdl->map.has_ceiling = TRUE;
		sdl->map.has_guns = TRUE;
		sdl->map.floor = sdl->textures.metal_wall_3;
		sdl->map.ceiling = sdl->textures.metal_wall_3;
		parse_map(sdl, map);
		Mix_PlayMusic(sdl->media.doom_map_music, -1);
	}
}

void	menu_loop_util_3(t_sdl *sdl, char *map)
{
	if (!ft_strcmp(map, UNIT_C))
	{
		sdl->map.map_type = PICK_ALL;
		sdl->map.has_ceiling = TRUE;
		sdl->map.has_guns = FALSE;
		sdl->map.floor = sdl->textures.unit_floor;
		sdl->map.ceiling = sdl->textures.unit_ceiling;
		parse_map(sdl, map);
	}
}

void	menu_loop_util_4(t_sdl *sdl, char *map)
{
	sdl->map.has_ceiling = TRUE;
	sdl->map.has_guns = TRUE;
	sdl->map.ceiling = sdl->textures.bluestone;
	sdl->map.floor = sdl->textures.wood;
	parse_map(sdl, map);
	if (!sdl->map.enemy_count)
		sdl->map.map_type = NOTHING;
	else
		sdl->map.map_type = KILL_ALL;
}

void	menu_loop(t_sdl *sdl, char *map)
{
	default_player(sdl);
	sdl->map.map_type = 666;
	menu_loop_util_1(sdl, map);
	menu_loop_util_2(sdl, map);
	menu_loop_util_3(sdl, map);
	if (sdl->map.map_type == 666)
		menu_loop_util_4(sdl, map);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	while (!sdl->quit)
		main_loop(sdl);
}
