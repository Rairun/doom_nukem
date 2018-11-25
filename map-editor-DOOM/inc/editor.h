/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:38:40 by aziabkin          #+#    #+#             */
/*   Updated: 2018/10/04 19:30:02 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include <SDL.h>
# include "SDL_image.h"
# include "libft.h"
# include "stdbool.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define SCR_W 1200
# define SCR_H 1000
# define CHECK_RIGHT 0
# define CHECK_LEFT 1
# define CHECK_DIAG1 2
# define CHECK_DIAG2 3

typedef struct		s_rect
{
	SDL_Rect		sdl_rect;
	int				x;
	int				y;
	int				r;
	int				g;
	int				b;
	int				index;
	int				on_screen;
	int				is_player;
	struct s_rect	*next;
}					t_rect;

typedef struct		s_points
{
	int				x;
	int				y;
	struct s_points	*right;
	struct s_points	*down;
	struct s_points	*diag1;
	struct s_points	*end_right;
	struct s_points	*end_down;
	struct s_points	*end_diag1;
	struct s_points	*next;
}					t_points;

typedef struct		s_all
{
	SDL_Window		*wind;
	SDL_Renderer	*rend;
	SDL_Texture		*texture;
	SDL_Surface		*temp;
	SDL_Rect		menu;
	SDL_Event		e;
	SDL_Rect		r_walls;
	SDL_Rect		r_player;
	t_points		*points;
	t_rect			*rects;
	t_rect			*r_start;
	t_rect			*sdl_player;
	char			**dogs;
	int				w;
	int				h;
	int				scale;
	int				half_step;
	int				fd;
	int				r;
	int				g;
	int				b;
	char			bukva;
	int				tmp_len;
	int				emptyness_flag;
	bool			quit;
}					t_all;

void				f_close(t_all *all);
void				neighbors(t_all *all);
void				diag_l_r(t_all *all);
void				draw(t_all *all, int x, int y);
int					check(int x_mouse, int y_mouse, t_all *all, int half_step);
int					check_r(int x_mouse, int y_mouse, t_all *all, int h_st);
t_points			*new_elem(void);
void				exit_error(int n);
void				init_sdl(t_all *all);
void				set_render(t_all *all, t_points *start);
void				work(t_all *all, t_points *start);
void				color_rects(int x_mouse, int y_mouse, t_all *all);
void				write_map(t_all *all);
int					pos_player(int x_mouse, int y_mouse, t_all *all, int h_st);
t_rect				*new_rect(void);
void				put_rect(t_all *all, int ix, int iy);
void				create_list_rects(t_all *all);
void				load_rects(t_all *all);
void				valid_file(char *argv);
void				read_map(char *way, t_all *all);
void				write_map(t_all *all);
void				color_walls(int x_mouse, int y_mouse, t_all *all);
void				color_walls_2(int x_mouse, int y_mouse, t_all *all);
void				color_walls_3(int x_mouse, int y_mouse, t_all *all);
void				color_walls_4(int x_mouse, int y_mouse, t_all *all);
void				color_walls_5(int x_mouse, int y_mouse, t_all *all);
void				color_walls_6(int x_mouse, int y_mouse, t_all *all);
void				color_walls_7(int x_mouse, int y_mouse, t_all *all);
void				color_walls_8(int x_mouse, int y_mouse, t_all *all);
void				draw_points(t_all *all, t_points *start);
char				**load_dogs(int w, int h);
void				create_list2(int x, int *iterations, t_all *all);
void				read_file(t_all *all, char *way);
void				init(t_all *all, char *way);
void				general_draw(t_all *all, t_points *start, char *way);
void				sdl_event(t_all *all, int x_mouse, int y_mouse, char *way);
void				sdl_event_1(t_all *all, int x_mouse, int y_mouse);
void				draw_r_pl(t_all *all);
void				init_1(t_all *all, char *way);
void				load_rects(t_all *all);
void				load_rects_walls_1(t_all *all);
void				load_rects_walls_2(t_all *all);
void				load_rects_walls_3(t_all *all);
void				load_rects_walls_4(t_all *all);
void				load_rects_walls_5(t_all *all);
void				load_rects_walls_6(t_all *all);
void				load_rects_walls_7(t_all *all);
void				load_rects_walls_8(t_all *all);
void				load_rects_walls_9(t_all *all);
void				load_rects_walls_10(t_all *all);
void				load_rects_walls_11(t_all *all);
void				load_rects_walls_12(t_all *all);
void				load_rects_walls_13(t_all *all);
void				load_rects_walls_14(t_all *all);
void				load_rects_walls_15(t_all *all);
void				load_rects_walls_16(t_all *all);
void				load_rects_walls_17(t_all *all);
void				load_rects_pos(t_all *all);
void				color_sprites_1(int x_mouse, int y_mouse, t_all *all);
void				color_sprites_2(int x_mouse, int y_mouse, t_all *all);
void				color_sprites_3(int x_mouse, int y_mouse, t_all *all);
void				color_sprites_4(int x_mouse, int y_mouse, t_all *all);
void				color_sprites_5(int x_mouse, int y_mouse, t_all *all);
void				color_sprites_6(int x_mouse, int y_mouse, t_all *all);
void				create_list_rects_1(t_all *all, int *ix, int *iy, int *ind);
void				create_list1(t_all *all);

#endif
