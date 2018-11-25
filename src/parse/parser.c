/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 14:09:01 by psaprono          #+#    #+#             */
/*   Updated: 2018/10/27 14:09:09 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/dn_inc.h"

void	get_map_info(t_sdl *sdl, const int fd, char *line, int has_end)
{
	char	**split;

	get_next_line(fd, &line);
	check_map_info_start(line);
	ft_strdel(&line);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, "height ="))
		{
			split = ft_strsplit(line, '=');
			if (ft_strsplit_count(split) != 2 || (sdl->map.map_height =
				(int)ft_atoi(split[1])) <= 0)
				error("Height map error.");
			ft_splitdel(&split);
		}
		else if (!ft_strcmp(line, "}"))
			has_end = 1;
		else if (ft_strlen(line) != 0)
			error("Map info error.");
		ft_strdel(&line);
		if (has_end)
			break ;
	}
	if (!has_end)
		error("Map info error.");
}

void	check_map_cell(t_sdl *sdl, const int ij[2], int l_s, const char *line)
{
	sdl->map.map[ij[0]][ij[1]].texture = NULL;
	if (ft_strchr(WALL_SYMB, line[ij[1]]) || ij[1] == 0 ||
		ij[0] == 0 || ij[0] == sdl->map.map_height - 1)
		check_map_wall(sdl, ij[0], ij[1], line);
	else if (line[ij[1]] == PLAYER_SYMB &&
			sdl->map.map[ij[0] - 1][ij[1]].len > 0)
	{
		sdl->map.player.pos_x = ij[1] + 0.5;
		sdl->map.player.pos_y = ij[0] + 0.5;
		sdl->map.map[ij[0]][ij[1]].type = NOTHING;
	}
	else if (ft_strchr(SPRITE_SYMB, line[ij[1]]))
		check_map_sprite(sdl, ij[0], ij[1], line);
	else if (ft_strchr(ENEMY_SYMB, line[ij[1]]))
		check_map_enemy(sdl, ij[0], ij[1], line);
	else
		sdl->map.map[ij[0]][ij[1]].type = NOTHING;
	sdl->map.map[ij[0]][ij[1]].end = FALSE;
	sdl->map.map[ij[0]][ij[1]].len = l_s;
}

void	verify_map_rows_cells(t_sdl *sdl, const int i, char *line)
{
	t_var a;

	initt(&a, line);
	sdl->map.map[i] = (t_map_cell *)malloc(sizeof(t_map_cell) * (a.l_s + 1));
	while (++(a.j) < a.l_s)
		check_map_cell(sdl, (int[]){i, (a.j)}, a.l_s, line);
	ft_strdel(&line);
	if (i > 0 && sdl->map.map[i][0].len > sdl->map.map[i - 1][0].len)
	{
		a.k = sdl->map.map[i - 1][0].len - 1;
		while (++(a.k) < sdl->map.map[i][0].len)
			(sdl->map.map[i][a.k].type = WALL) &&
			(sdl->map.map[i][a.k].texture = sdl->textures.wood);
	}
	if (i > 0 && sdl->map.map[i][0].len < sdl->map.map[i - 1][0].len)
	{
		a.k = sdl->map.map[i][0].len - 1;
		while (++(a.k) < sdl->map.map[i - 1][0].len)
			(sdl->map.map[i - 1][a.k].type = WALL) &&
			(sdl->map.map[i - 1][a.k].texture = sdl->textures.wood);
	}
	sdl->map.map[i][a.j - 1].type = WALL;
	sdl->map.map[i][a.j - 1].texture = sdl->textures.wood;
	sdl->map.map[i][a.j].end = TRUE;
}

void	read_map(t_sdl *sdl, const int fd)
{
	char	*line;
	int		i;
	int		has_end;

	has_end = 0;
	get_next_line(fd, &line);
	if (ft_strcmp(line, "map {"))
		error("Parse map error.");
	ft_strdel(&line);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strcmp(line, "}"))
		{
			has_end = TRUE;
			ft_strdel(&line);
			break ;
		}
		verify_map_rows_cells(sdl, i, line);
		if (++i >= sdl->map.map_height + 1)
			break ;
	}
	if (i != sdl->map.map_height || sdl->map.player.pos_x < 0 ||
		!check_player(&(sdl->map)) || !has_end)
		error("Parse map error.");
}

void	parse_map(t_sdl *sdl, const char *name)
{
	int fd;

	if ((fd = open(name, O_RDONLY)) < 0)
		error("Parse map error.");
	sdl->map.map = NULL;
	get_map_info(sdl, fd, NULL, 0);
	sdl->map.map = (t_map_cell **)malloc(sizeof(t_map_cell *) *
	sdl->map.map_height);
	read_map(sdl, fd);
}
