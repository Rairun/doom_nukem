/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbors_diag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:50:48 by aziabkin          #+#    #+#             */
/*   Updated: 2018/09/20 17:50:50 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	diag_l_r(t_all *all)
{
	t_points	*head;
	t_points	*tmp;
	int			i;

	head = all->points;
	i = 0;
	while (all->points)
	{
		if (all->points->down && all->points->right)
		{
			tmp = all->points;
			i = 0;
			while (tmp && i++ < all->h + 1)
				tmp = tmp->next;
			all->points->diag1 = tmp;
		}
		all->points = all->points->next;
	}
	all->points = head;
}

void	neighbors(t_all *all)
{
	int			i;
	int			j;
	t_points	*head;
	t_points	*tmp;

	head = all->points;
	i = 1;
	j = 0;
	while (all->points)
	{
		if (i % all->h != 0)
			all->points->down = all->points->next;
		if (i < all->h * (all->w - 1) + 1)
		{
			tmp = all->points;
			j = 0;
			while (tmp && j++ < all->h)
				tmp = tmp->next;
			all->points->right = tmp;
		}
		all->points = all->points->next;
		i++;
	}
	all->points = head;
	diag_l_r(all);
}
