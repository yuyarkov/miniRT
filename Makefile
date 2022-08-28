NAME =	miniRT

OBJ_PATH = ./obj
SRC_PATH = ./src
INC_PATH = ./includes
MLIBX_PATH = ./mlx
LIB_PATH =   ./libft/

SRC_FILES =	main.c 		draw_utils.c


LIBFT =   libft.a
			

OBJS = ${addprefix ${OBJ_PATH}/,${SRC_FILES:.c=.o}}

INCLUDES = -I${INC_PATH} -I${MLIBX_PATH}

CFLAGS = -Wall -Werror -Wextra -MMD -O2 -fsanitize=address
LFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all : libmake $(NAME)

libmake :	
	@make -C $(LIB_PATH) 

$(NAME) : $(OBJS)
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
