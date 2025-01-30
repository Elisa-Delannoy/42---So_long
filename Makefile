# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelanno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 11:33:24 by edelanno          #+#    #+#              #
#    Updated: 2025/01/30 11:33:25 by edelanno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = mlx_linux

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRC = main.c
OBJ = $(SRC:.c=.o)

# SRCBONUS = main_bonus.c
# OBJBONUS = $(SRCBONUS:.c=.o)

all : $(NAME)
	@echo "\033[32mCompilation successful !\033[0m"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "Compilating $@"

$(NAME) : $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT)

%.o: %.c
	@echo "Compilating $@"
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

# bonus : $(OBJBONUS) $(LIBFT)
# 	@$(CC) $(OBJBONUS) -o $(NAME) $(LIBFT) 

clean :
	@$(MAKE) -s clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)
	@echo "\033[32mClean ok\033[0m"

fclean : clean
	@$(MAKE) -s fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re : fclean all
