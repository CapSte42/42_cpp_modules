# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 12:10:05 by smontuor          #+#    #+#              #
#    Updated: 2024/08/04 09:17:41 by smontuor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----Program name---------------------------------------------#
NAME = ex02
DEBUG_NAME = $(NAME)_debug
#-------------------------------------------------------------#

#----Compiler-------------------------------------------------#
CC = g++
#-------------------------------------------------------------#

#----Compiler flags (standard, extra, memory) and includes----#
STANDARD_FLAGS = -Wall -Wextra -Werror
EXTRA_FLAGS = -std=c++98 -pedantic-errors
DEBUG_FLAGS = -g -O0 -no-pie -rdynamic -fdiagnostics-color=auto
INCLUDES = -I./includes
FLAGS = $(STANDARD_FLAGS) $(EXTRA_FLAGS) $(INCLUDES)
#-------------------------------------------------------------#

#----Source files and object files----------------------------#
#--------Class files--------------------------------------#
CLASS_PATH = ./class
CLASS_SRC = $(wildcard $(CLASS_PATH)/*.cpp)
#---------------------------------------------------------#

#--------Source files-------------------------------------#
SRC_PATH = ./src
SRC_SRC = $(wildcard $(SRC_PATH)/*.cpp)
#---------------------------------------------------------#

#--------All source files---------------------------------#
SRC = $(CLASS_SRC) $(SRC_SRC)
#---------------------------------------------------------#

#--------Object files-------------------------------------#
OBJ = $(patsubst $(SRC_PATH)/%.cpp,.build/%.o,$(SRC_SRC)) \
      $(patsubst $(CLASS_PATH)/%.cpp,.build/%.o,$(CLASS_SRC))
#---------------------------------------------------------#
#-------------------------------------------------------------#

#----Rules----------------------------------------------------#
all: .build $(NAME)

#--------Compile program----------------------------------#
$(NAME): $(OBJ)
	@clear
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
	@echo
	@echo "${BOLD}${GREEN}Compiled -> ${BLUE}${NAME}${NO_COLOR}"
	@$(MAKE) signature
#---------------------------------------------------------#

#--------Compile program with debug flags-----------------#
$(DEBUG_NAME): $(OBJ)
	@clear
	@$(CC) $(FLAGS) $(DEBUG_FLAGS) -o $(DEBUG_NAME) $(OBJ)
	@echo
	@echo "${BOLD}${GREEN}Compiled -> ${BLUE}${DEBUG_NAME}${NO_COLOR}"
#---------------------------------------------------------#

#--------Compile object files-----------------------------#
.build/%.o: $(SRC_PATH)/%.cpp | .build
	$(CC) $(FLAGS) -c $< -o $@

.build/%.o: $(CLASS_PATH)/%.cpp | .build
	$(CC) $(FLAGS) -c $< -o $@
#---------------------------------------------------------#

#--------Create build directory---------------------------#
.build:
	mkdir -p $@
#---------------------------------------------------------#

#--------Clean object files-------------------------------#
clean:
	@clear
	@if [ -d .build ]; then \
		rm -rf .build \
		echo ; \
		echo "${BOLD}${YELLOW}Removed -> ${RED}.build${NO_COLOR}"; \
		echo "${BOLD}${YELLOW}Cleaned object files${NO_COLOR}"; \
	else \
		echo ; \
		echo "${BOLD}${GREEN}Nothing to be done for clean${NO_COLOR}"; \
	fi
#---------------------------------------------------------#

#--------Clean program------------------------------------#
fclean: clean
	@if [ -e $(NAME) ]; then \
		rm -f $(NAME); \
		echo; \
		echo "${BOLD}${YELLOW}Removed -> ${RED}${NAME}${NO_COLOR}"; \
	fi
	@if [ -e $(DEBUG_NAME) ]; then \
		rm -f $(DEBUG_NAME); \
		echo; \
		echo "${BOLD}${YELLOW}Removed -> ${RED}${DEBUG_NAME}${NO_COLOR}"; \
	else \
		echo; \
		echo "${BOLD}${GREEN}Nothing to be done for fclean${NO_COLOR}"; \
	fi
#---------------------------------------------------------#

#--------Recompile program--------------------------------#
re: fclean all
#---------------------------------------------------------#

#--------Run program--------------------------------------#
run: $(NAME)
	@./$(NAME) $(filter-out $@,$(MAKECMDGOALS))
#---------------------------------------------------------#

#--------Compile with debug flags-------------------------#
debug: $(DEBUG_NAME)
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(DEBUG_NAME) $(filter-out $@,$(MAKECMDGOALS))
#---------------------------------------------------------#

#--------Default rule-------------------------------------#
%:
	@:
#---------------------------------------------------------#

#-------------------------------------------------------------#

#----Phony rules----------------------------------------------#
.PHONY: all clean fclean re run debug
.SILENT:
#-------------------------------------------------------------#

#----Colors---------------------------------------------------#
NO_COLOR		=	\033[0m
BOLD			=	\033[1m
YELLOW			=	\033[33m
GREEN			=	\033[32m
BLUE			=	\033[34m
RED				=	\033[31m
#-------------------------------------------------------------#

#----Additional rule to print my signature--------------------#
signature:
	@echo "Made by ${BOLD}${GREEN}"
	@echo "┏┓                     "
	@echo "┗┓┏┳┓┏┓┏┓╋┓┏┏┓┏┓       "
	@echo "┗┛┛┗┗┗┛┛┗┗┗┻┗┛┛        "
	@echo "            ${NO_COLOR}"
#-------------------------------------------------------------#

#----End of file----------------------------------------------#
