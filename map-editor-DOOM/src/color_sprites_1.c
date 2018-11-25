/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sprites_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:58:59 by aziabkin          #+#    #+#             */
/*   Updated: 2018/10/19 11:59:01 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	color_sprites_6(int x_mouse, int y_mouse, t_all *all)
{
	if (y_mouse >= 804 && y_mouse <= 879 && x_mouse >= 1120 && x_mouse <= 1199)
	{
		all->r = 255;
		all->g = 153;
		all->b = 51;
		all->bukva = 'w';
	}
	if (y_mouse >= 887 && y_mouse <= 966 && x_mouse >= 951 && x_mouse <= 999)
	{
		all->r = 153;
		all->g = 76;
		all->b = 0;
		all->bukva = 'g';
	}
}
