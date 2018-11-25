# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 19:28:55 by mnoskov           #+#    #+#              #
#    Updated: 2018/08/14 17:06:23 by mnoskov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRCS_DIR := ./srcs/
O_DIR := ./objs/
HDR_DIR := ./incs/

FLAGS := -Wall -Wextra -Werror
CC := gcc

SRCS := get_next_line.c ft_count_char.c ft_delimiter.c ft_swap.c ft_isuppercase.c ft_islowercase.c ft_strrev.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c
O_FILES = $(addprefix $(O_DIR), $(SRCS:.c=.o))
HDR_FLAGS := -I $(HDR_DIR)

all: ef $(NAME)

$(NAME): $(O_FILES)
	@ ar rc $(NAME) $(O_FILES)
$(O_FILES): | $(O_DIR)

$(O_DIR):
	@ mkdir $(O_DIR)

$(O_DIR)%.o: $(SRCS_DIR)%.c
	@ $(CC) -c $< -o $@ $(FLAGS) $(HDR_FLAGS)

clean:
	@ rm -f $(O_FILES)
ef:
	@ printf "✅ Compiling libft\n"
fclean: clean
	@ rm -f $(NAME) 
	@ rm -rf $(O_DIR)

re: fclean all