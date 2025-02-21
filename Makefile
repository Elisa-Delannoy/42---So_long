# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelanno <edelanno@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 11:33:24 by edelanno          #+#    #+#              #
#    Updated: 2025/02/21 16:10:30 by edelanno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = mlx_linux

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRC = main.c get_next_line.c get_next_line_utils.c parse.c parse2.c utils.c \
	printmap.c event.c event2.c init.c free.c animation.c animation2.c \
	stockimage.c
OBJ = $(SRC:.c=.o)

all : $(NAME)
	@echo "\033[32mCompilation successful !\033[0m"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "Compilating $@"

$(NAME) : $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT)

%.o: %.c
	@echo "Compilating $@"
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	@$(MAKE) -s clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)
	@echo "\033[32mClean ok\033[0m"

fclean : clean
	@$(MAKE) -s fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re : fclean all
