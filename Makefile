# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 11:21:21 by bgolding          #+#    #+#              #
#    Updated: 2024/08/07 11:11:27 by bgolding         ###   ########.fr        #
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
LIBRT_DIR		=	$(LIB)librt/

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
					$(LIBRT_DIR)librt.a

INC_PATHS		=	$(addprefix -I, $(INC_DIR) \
									$(LIBFT_DIR)inc \
									$(MINILIBX_DIR) \
									$(LIBRT_DIR)inc)

SRCS			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
AR				=	ar -r

DEF_COLOR		=	\033[0;39m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m

all:			$(STATIC_LIBS) $(NAME)

$(STATIC_LIBS):
				@echo "$(YELLOW)Creating archives...$(DEF_COLOR)"
				@make -C $(LIBFT_DIR)
				@make -C $(MINILIBX_DIR)
				@make -C $(LIBRT_DIR)
				@echo "$(GREEN)Minilibx ready! $(DEF_COLOR)"

$(NAME):		$(OBJ_DIR) $(OBJS) $(STATIC_LIBS)
				@echo "OS detected: $(UNAME_S)"
				@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -L$(LIBRT_DIR) -lrt $(OS_FLAGS) -o $@
				@echo "$(GREEN)Successfully created program: $(NAME) $(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(INC_PATHS) -c $< -o $@

$(OBJ_DIR):
				@mkdir -p $@

clean:			
				@$(RM) -rf $(OBJ_DIR)
				@make clean -C $(LIBFT_DIR)
				@make clean -C $(LIBRT_DIR)
				@echo "$(GREEN)clean complete $(DEF_COLOR)"

fclean:			clean
				@$(RM) $(NAME)
				@make clean -C $(MINILIBX_DIR)
				@make fclean -C $(LIBFT_DIR)
				@make fclean -C $(LIBRT_DIR)
				@echo "$(GREEN)fclean complete $(DEF_COLOR)"

re:				fclean all

.PHONY:			all clean fclean re