/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:45:12 by aziabkin          #+#    #+#             */
/*   Updated: 2018/09/20 17:45:14 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	init_sdl(t_all *all)
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;

	window = NULL;
	renderer = NULL;
	all->wind = window;
	all->rend = renderer;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		exit_error(2);
	all->wind = SDL_CreateWindow("Map Editor for Doom Nukem",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCR_W, SCR_H, SDL_WINDOW_SHOWN);
	if (all->wind == NULL)
		exit(0);
	all->rend = SDL_CreateRenderer(all->wind, -1, SDL_RENDERER_ACCELERATED);
	if (all->rend == NULL)
		exit(0);
}

void	f_close(t_all *all)
{
	SDL_DestroyRenderer(all->rend);
	SDL_DestroyWindow(all->wind);
	all->wind = NULL;
	all->rend = NULL;
	SDL_Quit();
}
