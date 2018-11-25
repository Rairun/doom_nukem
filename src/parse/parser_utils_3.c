/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 09:56:00 by mtupikov          #+#    #+#             */
/*   Updated: 2018/06/27 09:56:00 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/dn_inc.h"

int		check_player(t_map *map)
{
	if ((int)map->player.pos_y < 1 ||
		(int)map->player.pos_y >= map->map_height ||
		(int)map->player.pos_x == map->map[(int)map->player.pos_y][0].len - 1 ||
		(int)map->player.pos_x > map->map[(int)map->player.pos_y - 1][0].len ||
		(int)map->player.pos_x > map->map[(int)map->player.pos_y + 1][0].len)
		return (FALSE);
	return (TRUE);
}

void	check_map_wall(t_sdl *sdl, int i, int j, const char *line)
{
	sdl->map.map[i][j].type = WALL;
	sdl->map.map[i][j].texture = sdl->textures.wood;
	parse_map_textures_util_1(sdl, i, j, line);
	parse_map_textures_util_2(sdl, i, j, line);
}

void	check_map_sprite(t_sdl *sdl, int i, int j, const char *line)
{
	sdl->map.map[i][j].type = SPRITE;
	parse_map_textures_util_3(sdl, i, j, line);
	parse_map_textures_util_4(sdl, i, j, line);
	parse_map_textures_util_5(sdl, i, j, line);
	parse_map_textures_util_6(sdl, i, j, line);
	parse_map_textures_util_7(sdl, i, j, line);
}

void	check_map_enemy(t_sdl *sdl, int i, int j, const char *line)
{
	sdl->map.map[i][j].type = ENEMY;
	parse_map_textures_util_8(sdl, i, j, line);
	parse_map_textures_util_9(sdl, i, j, line);
	parse_map_textures_util_10(sdl, i, j, line);
}

void	check_map_info_start(char *line)
{
	if (ft_strcmp(line, "info {"))
		error("Map info error.");
}
