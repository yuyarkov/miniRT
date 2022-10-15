# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merlich <merlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 22:45:06 by merlich           #+#    #+#              #
#    Updated: 2022/10/15 22:07:03 by merlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	miniRT

OBJ_PATH = ./obj
SRC_PATH = ./src
INC_PATH = ./includes
MLIBX_PATH = ./mlx
LIB_PATH =   ./libft/

SRC_FILES =	main.c 							draw_utils.c\
			ray_utils.c\
			intersect_utils_1.c				intersect_utils_2.c\
			light_utils.c\
			vector_operations_1.c			vector_operations_2.c\
			vector_operations_3.c			vectors_rotation.c\
			color_utils_1.c					color_utils_2.c\
			scene_utils.c\
			ft_clean_map_data.c\
			./parser/check_geometry.c\
			./parser/check_colour.c 		./parser/check_vector.c\
			./parser/error_parser.c  		./parser/map_parser.c\
			./parser/get_next_line.c		./parser/get_next_line_utils.c\
			./parser/light_utils_1.c		./parser/light_utils_2.c\
			./parser/camera_utils_1.c		./parser/camera_utils_2.c\
			./parser/ambient_utils_1.c		./parser/ambient_utils_2.c\
			./parser/ft_atof.c\
			./parser/ft_check_params_1.c	./parser/ft_check_params_2.c\
			./parser/figures_utils_1.c		./parser/figures_utils_2.c\
			./parser/figures_utils_3.c\
			./buttons/ft_handle_buttons_1.c	./buttons/ft_handle_buttons_2.c\
			./buttons/ft_handle_buttons_3.c	./buttons/ft_handle_buttons_4.c

LIBFT =   libft.a
			

OBJS = ${addprefix ${OBJ_PATH}/,${SRC_FILES:.c=.o}}

INCLUDES = -I${INC_PATH} -I${MLIBX_PATH}

CFLAGS = -Wall -Werror -Wextra -MMD -O2 -fsanitize=address
LFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all : libmake $(NAME)

libmake :	
	@make -C $(LIB_PATH) 

$(NAME) : $(OBJS) Makefile
	@cp $(LIB_PATH)$(LIBFT) $(LIBFT)
	@make -C $(MLIBX_PATH) all
	gcc $(OBJS) $(LIBFT) $(CFLAGS) $(LFLAGS) -o $(NAME)

${OBJ_PATH}/%.o : ${SRC_PATH}/%.c
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) ${INCLUDES} -c $< -o $@

-include $(addprefix ${OBJ_PATH}/,${SRC_FILES:.c=.d})

clean:
	@rm -rf $(OBJ_PATH)
	@make -C $(LIB_PATH) clean
	@make -C ${MLIBX_PATH} clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

run:	all
		MallocNanoZone=0 ./$(NAME)

.PHONY: all clean fclean re run
