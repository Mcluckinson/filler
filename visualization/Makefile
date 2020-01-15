# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 01:12:20 by sleonia           #+#    #+#              #
#    Updated: 2020/01/16 01:56:03 by sleonia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

NAME = vs

FRAMEDIR = /Users/$(USER)/Library/Frameworks

SRC_PATH = ./sources/
OBJ_PATH = ./objects/
INC_PATH = ./includes/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
HEADERS = $(addprefix, $(INC_PATH), $(HEADERS_NAME))
INC_SDL = 		-I Frameworks/SDL2.framework/Versions/A/Headers 		\
				-I Frameworks/SDL2_image.framework/Versions/A/Headers 	\
				-I Frameworks/SDL2_ttf.framework/Versions/A/Headers 	\
				-I Frameworks/SDL2_mixer.framework/Versions/A/Headers/ 	\
				-F Frameworks/

FRAME = 	-F Frameworks/ -framework SDL2 -framework SDL2_image 		\
            -framework SDL2_ttf -framework SDL2_mixer -rpath Frameworks/

FLAGS = 	-Wall -Werror -Wextra -Ofast -g

HEADERS_NAME =	vs_define_value.h		\
				vs_function.h			\
				vs_rt.h					\
				vs_struct.h				\

SRC_NAME =		ft_exit.c				\
				init.c					\
				main.c					\
				sdl_loop.c				\

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(FRAME)
	 
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
	@mkdir -p $(OBJ_PATH)
	@echo "\033[31m"
	@gcc $(FLAGS) $(INC) $(INC_SDL) -o $@ -c $<
	@echo "\033[0m"

$(FRAMEDIR):
		@mkdir -p $(FRAMEDIR)
		@rm -rf $(FRAMEDIR)/*

visualization_refresh:
	@make -C $(LIB_PATH)

clean:
	@find . -name ".DS_Store" -delete
	@clear
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all
