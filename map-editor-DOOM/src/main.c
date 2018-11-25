/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:47:45 by aziabkin          #+#    #+#             */
/*   Updated: 2018/10/04 20:02:08 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	read_file(t_all *all, char *way)
{
	char	*str;
	int		max_l_h[2];

	all->tmp_len = 0;
	max_l_h[0] = 0;
	max_l_h[1] = 0;
	str = NULL;
	while (get_next_line(all->fd, &str) > 0)
	{
		all->emptyness_flag = 0;
		all->tmp_len = ft_strlen(str);
		if (all->tmp_len > max_l_h[0])
			max_l_h[0] = all->tmp_len;
		max_l_h[1]++;
		free(str);
	}
	if (all->emptyness_flag == -1)
		all->tmp_len = 30;
	else
	{
		all->tmp_len = (max_l_h[1] - 5 > max_l_h[0] - 4) ?\
							max_l_h[1] - 5 : max_l_h[0] - 4;
		close(all->fd);
		all->fd = open(way, O_RDWR);
	}
}

void	init_1(t_all *all, char *way)
{
	char	**dogs;

	if (!(dogs = load_dogs(all->w - 1, all->h - 1)))
		return ;
	all->dogs = dogs;
	all->scale = (all->w > all->h) ?\
			(SCR_W - 300) / all->w : (SCR_H - 80) / all->h;
	all->half_step = (all->scale) / 2;
	all->r = 0;
	all->g = 0;
	all->b = 0;
	all->bukva = 'D';
	read_map(way, all);
}

void	init(t_all *all, char *way)
{
	all->texture = NULL;
	if ((all->fd = open(way, O_RDWR)) == -1)
		exit_error(3);
	valid_file(way);
	all->emptyness_flag = -1;
	read_file(all, way);
	all->w = all->tmp_len + 1;
	all->h = all->tmp_len + 1;
	all->points = new_elem();
	all->rects = new_rect();
	all->r_start = all->rects;
	init_sdl(all);
	all->temp = IMG_Load("walls.png");
	IMG_Init(IMG_INIT_PNG);
	all->texture = SDL_CreateTextureFromSurface(all->rend, all->temp);
	SDL_FreeSurface(all->temp);
	all->menu.x = SCR_W - 250;
	all->menu.y = 0;
	all->menu.w = 250;
	all->menu.h = 1000;
}

int		main(int argc, char **argv)
{
	t_all		*all;
	t_points	*start;

	if (argc != 2)
		exit_error(1);
	if (!(all = (t_all *)malloc(sizeof(t_all))))
		return (0);
	init(all, argv[1]);
	init_1(all, argv[1]);
	create_list1(all);
	start = all->points;
	neighbors(all);
	all->points = start;
	create_list_rects(all);
	all->rects = all->r_start;
	all->points = start;
	all->sdl_player = NULL;
	if (all->emptyness_flag == 0)
	{
		load_rects(all);
		all->rects = all->r_start;
	}
	general_draw(all, start, argv[1]);
	return (1);
}
