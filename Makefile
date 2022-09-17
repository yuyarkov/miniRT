# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merlich <merlich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 22:45:06 by merlich           #+#    #+#              #
#    Updated: 2022/09/16 21:50:47 by merlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	miniRT

OBJ_PATH = ./obj
SRC_PATH = ./src
INC_PATH = ./includes
MLIBX_PATH = ./mlx
LIB_PATH =   ./libft/

SRC_FILES =	main.c 					draw_utils.c\
			error_parser.c  		map_parser.c\
			check_colour.c 			check_vector.c\
			check_geometry.c		matrix_utils.c\
			ray_utils.c				vector_operations.c\
			debug_utils.c\
			get_next_line.c			get_next_line_utils.c\
			light_utils_1.c			light_utils_2.c\
			camera_utils_1.c		camera_utils_2.c\
			ambient_utils_1.c		ambient_utils_2.c\
			plane_utils_1.c			plane_utils_2.c\
			sphere_utils_1.c		sphere_utils_2.c\
			cylinder_utils_1.c		cylinder_utils_2.c\
			ft_atof.c\
			ft_check_params_1.c		ft_check_params_2.c\
			scene_utils.c			sphere_utils.c\
			
			


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
