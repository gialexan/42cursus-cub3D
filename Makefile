# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 10:11:35 by gialexan          #+#    #+#              #
#    Updated: 2023/07/25 14:27:49 by gialexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################
##                                CUB3D                                       ##
################################################################################

NAME  := cub3D

RESET := \033[0m
CYAN  := \033[1;36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

################################################################################
##                                DIRECTORIES                                 ##
################################################################################

OBJ_DIR   := obj
LIB_DIR   := lib
LIBFT_DIR := $(LIB_DIR)/libft
MLX_DIR   := $(LIB_DIR)/mlx_linux
INC_DIRS  := include $(LIBFT_DIR) $(MLX_DIR)
SRC_DIRS  := player draw render window raycast wall
#SRC_DIRS  += camera parser patterns
SRC_DIRS  := $(addprefix src/, $(SRC_DIRS))
SRC_DIRS  += src

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

LIBFT   := $(LIBFT_DIR)/libft.a
MLX     := $(MLX_DIR)/libmlx_Linux.a

HEADERS := cub3d.h constants.h draw.h player.h raycast.h wall.h
#HEADERS += world.h helpers.h camera.h mlx.h parser.h patterns.h

SOURCES := main.c window.c gen3d_env.c
SOURCES += player.c key_hook.c move_player.c
SOURCES += draw_line.c draw_pixel.c draw_rectangle.c
SOURCES += render_background.c render_game.c render_player.c render_rays.c render_map.c
SOURCES += raycast.c vertical_intersection.c horizontal_intersection.c calculate_rays.c set_rays.c

OBJS := $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

################################################################################
##                                 COMPILATION                                ##
################################################################################

CFLAGS  := -g $(addprefix -I,$(INC_DIRS))
#CFLAGS  := -Wall -Werror -Wextra $(addprefix -I,$(INC_DIRS))
LDFLAGS := -L $(LIBFT_DIR) -L $(MLX_DIR)
LDLIBS  := -lft -lmlx -lXext -lX11 -lm

ifdef DEBUG
	CFLAGS += -g
else
	CFLAGS += -Ofast
endif

all: $(NAME)

run: all
	./cub3D

#$@ -> variável automática para NAME.
#$^ -> variável automática para o todos elementos da lista de requisitos.
#$< -> variável automática para somente o primeiro elemento da lista de requisitos.

# | -> significa para colocar prioridade na compilação, no caso abaixo primeiro a libft e mlx depois o restante
$(NAME): $(OBJS) | $(LIBFT) $(MLX)
	@$(LOG) "Building $@"
	@$(CC) $^ $(LDFLAGS) $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	@$(LOG) "Compiling $(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@$(LOG) "Creating objects directory"
	@mkdir $@

$(LIBFT):
	@$(LOG) "Building $(notdir $@)"
	@make bonus -C $(LIBFT_DIR) --no-print-directory --silent

$(MLX):
	@$(LOG) "Building $(notdir $@)"
	@make -C $(MLX_DIR) --no-print-directory --silent >/dev/null 2>&1

checks: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

clean:
	@$(RM) -r $(OBJS)
	@$(LOG) "Removing objects"
	@$(RM) -r $(OBJ_DIR)
	@$(LOG) "Removing objects directory"

fclean: clean
	@$(RM) -r $(NAME)
	@$(LOG) "Removing $(NAME)"
	@$(LOG) "Removing libft"
	@make fclean -C $(LIBFT_DIR) --no-print-directory --silent
	@$(LOG) "Removing mlx"
	@make clean -C $(MLX_DIR) --no-print-directory --silent >/dev/null 2>&1

re: clean all

.PHONY: all clean fclean re