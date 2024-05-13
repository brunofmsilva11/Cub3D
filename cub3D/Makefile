# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 11:46:40 by bmota-si          #+#    #+#              #
#    Updated: 2024/05/08 18:06:35 by bmota-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lX11 -lXext
RM = rm -rf

LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a

SRCS = 	./main.c mandatory/error/error.c mandatory/error/error2.c \
			mandatory/init/init.c mandatory/init/init2.c \
			mandatory/map_file/check_file.c \
			mandatory/map_file/check_textures.c \
			mandatory/map_file/direc_color.c mandatory/map_file/rgb_check.c mandatory/map_file/rgb_check2.c \
			mandatory/utils.c mandatory/free.c mandatory/exit_command.c \
			mandatory/window/win_color.c mandatory/window/win_utils.c \
			mandatory/test_map_validation/test.c mandatory/xpm_files.c \
			mandatory/start/start.c mandatory/start/direction.c mandatory/start/draw.c \
			mandatory/start/move.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MINILIBX):
	@$(MAKE) -C ./minilibx-linux

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MFLAGS) -o $(NAME) -lm

game:
		./cub3D maps/map.cub

leaks:
		valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/map.cub

leaks2:
		valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/teste.cub

gdb:
		gdb --tui --args ./cub3D maps/map.cub

gdb2:
		gdb --tui --args ./cub3D maps/teste.cub

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS)
	clear
	echo "$(RED)Object files have been deleted!$(RESET)"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(RM) map_temp.map
	clear
	echo "$(RED)Object and Executable files have been deleted!$(RESET)"

re: fclean all
