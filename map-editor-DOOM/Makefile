# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 13:18:16 by aziabkin          #+#    #+#              #
#    Updated: 2018/10/25 13:18:20 by aziabkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ../editor

LIB_DIR := ./libft/
SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/

SRC :=	main.c\
		editor.c\
		points.c\
		neighbors_diag.c\
		draw.c\
		check_end.c\
		errors.c\
		rects.c\
		file_management.c\
		color_walls.c\
		color_walls_1.c\
		load_rects.c\
		load_rects_1.c\
		load_rects_2.c\
		load_rects_3.c\
		color_sprites.c\
		color_sprites_1.c

SDL_CFLAGS = $(shell sdl2-config --cflags)

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
CGFLAGS = -framework OpenGL -framework AppKit
INCLUDES	=	-I../frameworks/SDL2.framework/Versions/A/Headers \
				-I../frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I../frameworks/SDL2_image.framework/Versions/A/Headers \
				-I../frameworks/SDL2_mixer.framework/Headers \
				-I../frameworks/SDL2_net.framework/Headers \
				-F../frameworks
FRAMEWORKS	=	-F../frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer -framework SDL2_net
CC := gcc
FLAGS := -Wall -Wextra -Werror -O3
LIBFT = $(LIB_DIR)libft.a 
LIBFT_FLAGS := -L $(LIB_DIR) -lft
LIBFT_INC := $(LIB_DIR)incs

HDR_FLAGS := -I $(LIBFT_INC) -I $(INC_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(CGFLAGS) $(FRAMEWORKS) $(HDR_FLAGS) -o $(NAME) -g $(LIBFT) -D_THREAD_SAFE

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< -o $@ -g -I./$(SDL_PATH)/include $(FLAGS) $(HDR_FLAGS) $(INCLUDES)

$(LIBFT):
	make -C $(LIB_DIR)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean:
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all
