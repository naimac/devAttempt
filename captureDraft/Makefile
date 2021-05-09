# MULTI COMMENTAIRE EN MAKEFILE \
MAKEFILE QUI MARCHE

.PHONY: directories exedraft clean fclean clean-all re all

## COMPILER
CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror -g -O0
LDLIBS		:= -lpcap
# CPPFLAGS 	:= -I$(LTST_HDR)
# LDFLAGS	:= -L$(LTST_DIR)

#directories: \
	@mkdir -p ./obj/

## DIRECTORIES
SRC_DIR		:= ./src/
INC_DIR		:= ./include/
OBJ_DIR		:= ./obj/

## PROJECT FILES
NAME			:= exeDraft
#SRCS			:= $(wildcard $(SRC_DIR)*.c) # marche mal ici
SRCS			:= main.c
OBJS     		:= $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
#OBJS			:= $(SRCS:.c=.o) # marche pas ici
#OBJS			:= $(SRCS:.c=$(OBJ_DIR).o) # marche pas ici

## RULES
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@echo "creating OBJ_DIR"
	@mkdir -p $@

$(NAME): $(OBJS)
	@echo "creation de l'executable"
	@$(CC) $(LDLIBS) -o $@ $^

# construire un .o à partir d'un .c
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "creation des objets .o"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -fR $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

clean-all: fclean
	$(MAKE) fclean -C $(LTST_DIR)

re: fclean all
