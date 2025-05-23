# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 11:21:21 by bgolding          #+#    #+#              #
#    Updated: 2024/11/26 08:53:40 by bgolding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	project_name

LIB				=	lib/
INC				=	inc/
SRC_DIR			=	src/
OBJ_DIR			=	obj/
INC_DIR			=	inc/
LIBFT_DIR 		=	$(LIB)libft/
MINILIBX_DIR	=	$(LIB)mlx/
LIBGRAPHIC_DIR	=	$(LIB)libgraphic/

TEMPLATE_FILES	=	main error init_data init_mlx destroy_data \
					hooks keypress mouse draw_utils render

PROJECT_FILES	=	

SRC_FILES		=	$(TEMPLATE_FILES) $(PROJECT_FILES)

# OS specific settings
UNAME_S			=	$(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MINILIBX_DIR	:=	$(addsuffix Linux/, $(MINILIBX_DIR))
	OS_FLAGS		:=	-lXext -lX11 -lm
	TEMPLATE_FILES	+=	destroy_mlx_linux close_linux
else ifeq ($(UNAME_S), Darwin)
	MINILIBX_DIR	:=	$(addsuffix MacOS/, $(MINILIBX_DIR))
	OS_FLAGS		:=	-framework OpenGL -framework AppKit
	TEMPLATE_FILES	+=	destroy_mlx_macos close_macos
else
	$(error OS not supported)
	exit 1
endif


STATIC_LIBS		=	$(LIBFT_DIR)libft.a \
					$(MINILIBX_DIR)libmlx.a \
					$(LIBGRAPHIC_DIR)libgraphic.a

INC_PATHS		=	$(addprefix -I, $(INC_DIR) \
									$(LIBFT_DIR)inc \
									$(MINILIBX_DIR) \
									$(LIBGRAPHIC_DIR)inc)

SRCS			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

LIB_LINK		=	-L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -L$(LIBGRAPHIC_DIR) -lgraphic $(OS_FLAGS)

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
AR				=	ar -r

MAKEFLAGS		=	--no-print-directory

DEF_COLOR		=	\033[0;39m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
CLEAR_LINE		=	\033[2K

TOTAL_FILES		=	$(words $(SRCS))
COMPILED_COUNT	=	0


all:			$(STATIC_LIBS) $(NAME)

$(STATIC_LIBS):
				@echo "$(YELLOW)Compiling static libraries...$(DEF_COLOR)"
				@make libft
				@make mlx
				@make libgraphic
				@echo "$(GREEN)All static libraries compiled$(DEF_COLOR)"

$(NAME):		$(OBJ_DIR) $(OBJS) $(STATIC_LIBS)
				@printf "$(CLEAR_LINE)"
				@$(CC) $(CFLAGS) $(OBJS) $(LIB_LINK) -o $@
				@echo "\r$(GREEN)Successfully created executable: $(NAME) $(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
				@$(eval COMPILED_COUNT=$(shell echo $$(($(COMPILED_COUNT) + 1))))
				@printf "\r$(YELLOW)[$(COMPILED_COUNT)/$(TOTAL_FILES)] Compiling $(NAME) files$(DEF_COLOR)"
				@$(CC) $(CFLAGS) $(INC_PATHS) -c $< -o $@

$(OBJ_DIR):
				@mkdir -p $@

clean:			
				@$(RM) -rf $(OBJ_DIR)
				@make clean -C $(LIBFT_DIR)
				@make clean -C $(LIBGRAPHIC_DIR)
				@echo "$(YELLOW)clean complete $(DEF_COLOR)"

fclean:			clean
				@$(RM) $(NAME)
				@make clean -C $(MINILIBX_DIR)
				@make fclean -C $(LIBFT_DIR)
				@make fclean -C $(LIBGRAPHIC_DIR)
				@echo "$(YELLOW)fclean complete $(DEF_COLOR)"

re:				fclean all

libft:
				@make -C $(LIBFT_DIR)

libgraphic:
				@make -C $(LIBGRAPHIC_DIR)

mlx:
				@make -C $(MINILIBX_DIR)

.PHONY:			all clean fclean re