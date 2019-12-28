.PHONY: all, $(NAME), norm, clean, fclean, re

NAME = cyuriko.filler

FRAMEDIR = /Users/$(USER)/Library/Frameworks

SRC_PATH = ./sources/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
LIB_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
INC_SDL = 		-I Frameworks/SDL2.framework/Versions/A/Headers 		\
				-I Frameworks/SDL2_image.framework/Versions/A/Headers 	\
				-I Frameworks/SDL2_ttf.framework/Versions/A/Headers 	\
				-I Frameworks/SDL2_mixer.framework/Versions/A/Headers/ 	\
				-F Frameworks/

FRAME = 	-F Frameworks/ -framework SDL2 -framework SDL2_image 		\
            -framework SDL2_ttf -framework SDL2_mixer -rpath Frameworks/

FLAGS = 	-Wall -Werror -Wextra -Ofast -g

SRC_NAME =	free_things.c		\
			main.c				\
			init.c				\
			parse_player.c		\
			ft_get_line.c		\
			count_heatmap.c		\
			skip_line.c			\
			work_with_heatmap.c	\
			read_map.c			\
			parse_piece.c		\
			ft_free.c			\
			put_piece.c			\
			cropped_map.c		\


OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make lib_refresh
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -lft -L $(LIB_PATH) $(FRAME)
	 
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC_PATH)filler.h
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)$(GUI_PATH)
	@echo "\033[31m"
	@gcc $(INC) $(INC_SDL) -o $@ -c $<
	@echo "\033[0m"

$(FRAMEDIR):
		@mkdir -p $(FRAMEDIR)
		@rm -rf $(FRAMEDIR)/*

lib_refresh:
	@make -C $(LIB_PATH)

clean:
	@find . -name ".DS_Store" -delete
	@clear
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)

re: fclean all