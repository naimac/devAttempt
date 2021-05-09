# MULTI COMMENTAIRE EN MAKEFILE \
API SHM

.PHONY: clean fclean clean-all re all

#directories: \
	@mkdir -p ./obj/

## COMPILER
CC		:= clang++
CFLAGS		:= -Wall -Wextra -Werror -pthread -g -O0
INCFLAGS	:= -I$(INC_DIR)

## DIRECTORIES
SRC_DIR		:= ./src/
INC_DIR		:= ./include/
OBJ_DIR		:= ./obj/
LIB_DIR		:= ./lib/

## PROJECT FILES
LIB_NAME	:= $(LIB_DIR)libshm.a

#FIND_SRCS	:= $(shell find $(SRC_DIR) -name "*.cpp")
#SRC 		:= $(subst $(SRC_FILES),,$(if $(SRC), $(SRC), $(FIND_SRCS)))

FILES		:= visionFun.cpp
SRCS		:= $(addprefix $(SRC_DIR), $(FILES))

OBJS		:= $(patsubst %.cpp, %.o, $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS)))
#OBJS		:= $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS))

## RULES
all: $(OBJ_DIR) $(LIB_DIR) $(LIB_NAME)


$(OBJ_DIR):
	@echo "creating $(OBJ_DIR)"
	@mkdir -p $@

$(LIB_DIR):
	@echo "creating $(LIB_DIR)"
	@mkdir -p $@

$(LIB_NAME): $(OBJS)
	@echo "creation du libshm.a"
	@ar rc $@ $^
#	@echo "generation de l index"
#	@ranlib @

# construire un .o à partir d'un .cpp
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@echo "creation des objets .o"
##	@$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $(OBJ_DIR)$@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -fR $(OBJ_DIR) $(LIB_DIR)

fclean: clean
	@rm -f $(LIB_NAME)

re: fclean all
