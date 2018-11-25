/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:46:41 by aziabkin          #+#    #+#             */
/*   Updated: 2018/10/04 19:56:26 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	exit_error(int n)
{
	if (n == 1)
	{
		ft_putendl("Two arguments required!: ./editor maps/[map_name.file]");
	}
	else if (n == 2)
	{
		ft_putstr("SDL couldn't initialize! SDL Error: ");
		ft_putendl(SDL_GetError());
	}
	else if (n == 3)
	{
		ft_putendl("Error! File does not open!");
	}
	exit(0);
}
