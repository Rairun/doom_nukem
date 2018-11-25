/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:25:29 by aziabkin          #+#    #+#             */
/*   Updated: 2018/10/18 14:25:33 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	valid_file(char *argv)
{
	if (ft_strstr(argv, "/dev/"))
		exit_error(1);
	if (!ft_strstr(argv, "maps/"))
		exit_error(1);
}

void	read_map(char *way, t_all *all)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	all->fd = open(way, O_RDWR);
	while (i++ < 4 && get_next_line(all->fd, &str))
		free(str);
	while (get_next_line(all->fd, &str) > 0 && str[0] != '}')
	{
		i = 4;
		while (str[i] != '\0')
		{
			all->dogs[j][i - 4] = str[i];
			i++;
		}
		j++;
		free(str);
	}
	if (str && str[0] == '}')
		free(str);
	close(all->fd);
}

void	write_map(t_all *all)
{
	int i;

	i = -1;
	ft_putendl_fd("info {", all->fd);
	ft_putstr_fd("    height = ", all->fd);
	ft_putnbr_fd(all->tmp_len, all->fd);
	ft_putstr_fd("\n", all->fd);
	ft_putendl_fd("}", all->fd);
	ft_putendl_fd("map {", all->fd);
	while (++i < all->tmp_len)
	{
		ft_putstr_fd("    ", all->fd);
		ft_putendl_fd(all->dogs[i], all->fd);
	}
	ft_putstr_fd("}", all->fd);
}

void	draw_points(t_all *all, t_points *start)
{
	while (all->points)
	{
		draw(all, all->points->x, all->points->y);
		all->points = all->points->next;
	}
	all->points = start;
}

char	**load_dogs(int w, int h)
{
	char	**dogs;
	int		x;
	int		y;

	x = -1;
	y = -1;
	if (!(dogs = (char **)malloc(sizeof(dogs) * h + 1)))
		return (NULL);
	dogs[h] = 0;
	while (++y < h)
	{
		if (!(dogs[y] = (char *)malloc(sizeof(dogs[y]) * w + 1)))
			return (NULL);
	}
	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
		{
			dogs[y][x] = ' ';
		}
		dogs[y][x] = '\0';
	}
	return (dogs);
}
