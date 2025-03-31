NAME        := so_long
NAME_B        := so_long_bonus
CC          := cc
FLAGS       := -Wall -Wextra -Werror
LFLAGS      := -lft -lmlx -lmlx_Linux -lX11 -lXext -lm

MLX_PATH    := lib/minilibx
LIBFT_PATH  := lib/libft
PATH_LIBS 	:= -L$(LIBFT_PATH) -L$(MLX_PATH)
RM          := rm -rf
SRCS      := 	src/init_obj.c \
               src/init_map.c \
               src/validate_map.c \
               src/graphics.c \
               src/so_long.c \
               src/validate_map_util.c\
               src/events.c
              
               
SRCS_B       := src_bonus/init_obj_bonus.c \
               src_bonus/init_map_bonus.c \
               src_bonus/validate_map_bonus.c \
               src_bonus/graphics_bonus.c \
               src_bonus/so_long_bonus.c \
               src_bonus/validate_map_util_bonus.c\
               src_bonus/enemi_mov.c\
               src_bonus/util_mov.c\
               src_bonus/player_mov.c\
              
OBJS        := $(SRCS:.c=.o)
OBJS_B        := $(SRCS_B:.c=.o)

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

CLR_RMV     := \033[0m
RED         := \033[1;31m
GREEN       := \033[1;32m
YELLOW      := \033[1;33m
BLUE        := \033[1;34m
CYAN        := \033[1;36m

$(NAME): ${OBJS}
	@echo "$(GREEN)Compiling${CLR_RMV} of ${YELLOW}$(NAME) ${CLR_RMV}..."
	@make -C $(LIBFT_PATH) 
	@make -C $(MLX_PATH)
	@${CC} ${FLAGS} $(OBJS) -o $(NAME) $(PATH_LIBS) $(LFLAGS)
	@echo "$(GREEN)$(NAME) created${CLR_RMV} ✔️"
bonus: ${OBJS_B}
	@echo "$(GREEN)Compiling${CLR_RMV} of ${YELLOW}$(NAME_B) ${CLR_RMV}..."
	@make -C $(LIBFT_PATH)
	@make -C $(MLX_PATH)
	@${CC} ${FLAGS} $(OBJS_B) -o $(NAME_B) $(PATH_LIBS) $(LFLAGS)
	@echo "$(GREEN)$(NAME) created${CL_R_RMV} ✔️"
all: ${NAME} clean

clean:
	@${RM} ${OBJS} ${OBJS_B}
	@rm -rf $(NAME).dSYM >/dev/null 2>&1
	@echo "$(RED)Deleting $(CYAN)$(NAME) ${CLR_RMV}objs ✔️"

fclean: clean
	@${RM} ${NAME} ${NAME_B}
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(MLX_PATH)
	@echo "$(RED)Deleting $(CYAN)$(NAME) ${CLR_RMV}binary ✔️"

re: fclean all

.PHONY: all clean fclean re
