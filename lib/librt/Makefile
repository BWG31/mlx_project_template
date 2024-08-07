# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 12:49:52 by bgolding          #+#    #+#              #
#    Updated: 2024/08/06 16:19:14 by bgolding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	librt.a

SRC_DIR	=	src/
OBJ_DIR	=	obj/
INC_DIR	=	inc/

TPL_SRC =	tp_error vector point equal add subtract negate multiply divide \
			fsquaref magnitude normalize dot_product cross_product

CLR_SRC =	rgb_add rgb_subtract rgb_multiply rgb_blend rgb_conversion

MX_SRC	=	mx_error init equal multiply identity transpose submatrices \
			determinant adjugate inversion translation reflection rotation \
			shearing unit_conversions
			
SRCS	=	$(addprefix $(SRC_DIR)tuples/, $(addsuffix .c, $(TPL_SRC))) \
			$(addprefix $(SRC_DIR)colors/, $(addsuffix .c, $(CLR_SRC))) \
			$(addprefix $(SRC_DIR)matrix/, $(addsuffix .c, $(MX_SRC)))
OBJS	=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
AR		=	ar -rc

DEF_COLOR		=	\033[0;39m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $@ $(OBJS)
			@echo "$(GREEN)librt ready! $(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(dir $@)
					@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
			@$(RM) -rf $(OBJ_DIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re