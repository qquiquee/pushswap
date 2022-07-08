NAME_CHECKER = checker
NAME_PUSH_SWAP = push_swap
LIBFT = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -lft
RMF = rm -rf

INC_DIR = include
LIB_DIR = libft
SRC_DIR_CHECKER = src/checker
SRC_DIR_PUSH_SWAP = src/push_swap
OBJ_DIR_CHECKER = obj/checker
OBJ_DIR_PUSH_SWAP = obj/push_swap

LIBS = $(LIB_DIR)/$(LIBFT)

_OBJS_CHECKER =	main.o\
				commands.o\
				execute_commands.o\
				utils.o\
				utils2.o
_OBJS_PUSH_SWAP =	main.o\
					alg_operations.o\
					checks.o\
					commands_2.o\
					commands.o\
					find_min_max.o\
					mod_QS_alg_utils.o\
					mod_QS_alg.o\
					operation_commands_2.o\
					operation_commands.o\
					operation_utils.o\
					operations.o\
					utils.o

OBJ_CHECKER := $(patsubst %, $(OBJ_DIR_CHECKER)/%, $(_OBJS_CHECKER))
OBJ_PUSH_SWAP := $(patsubst %, $(OBJ_DIR_PUSH_SWAP)/%, $(_OBJS_PUSH_SWAP))

_DEPS_CHECKER = checker.h \
				libft.h 
_DEPS_PUSH_SWAP = 	push_swap.h \
					libft.h 

DEPS_CHECKER := $(patsubst %, $(INC_DIR)/%, $(_DEPS_CHECKER))
DEPS_PUSH_SWAP := $(patsubst %, $(INC_DIR)/%, $(_DEPS_PUSH_SWAP))

.PHONY: all
all: make_library $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(OBJ_DIR_CHECKER)/%.o: $(SRC_DIR_CHECKER)/%.c $(DEPS_CHECKER)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c -o $@ $<
$(OBJ_DIR_PUSH_SWAP)/%.o: $(SRC_DIR_PUSH_SWAP)/%.c $(DEPS_PUSH_SWAP)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c -o $@ $<

$(OBJ_CHECKER): | $(OBJ_DIR_CHECKER)
$(OBJ_PUSH_SWAP): | $(OBJ_DIR_PUSH_SWAP)

$(OBJ_DIR_CHECKER):
	mkdir -p $(OBJ_DIR_CHECKER)
$(OBJ_DIR_PUSH_SWAP):
	mkdir -p $(OBJ_DIR_PUSH_SWAP)

.PHONY: make_library
make_library:
	make -C $(LIB_DIR)

$(LIB_DIR)/$(LIBFT):
	make -C $(LIB_DIR)

$(NAME_CHECKER): $(LIBS) $(OBJ_CHECKER)
	$(CC) $(CFLAGS) -o $(NAME_CHECKER) $(OBJ_CHECKER) -I$(INC_DIR) -L$(LIB_DIR) $(LDFLAGS)
$(NAME_PUSH_SWAP): $(LIBS) $(OBJ_PUSH_SWAP)
	$(CC) $(CFLAGS) -o $(NAME_PUSH_SWAP) $(OBJ_PUSH_SWAP) -I$(INC_DIR) -L$(LIB_DIR) $(LDFLAGS)

.PHONY: fsanitize
fsanitize: CFLAGS += -fsanitize=address
fsanitize: debuginfo
	ASAN_OPTIONS=detect_leaks=1 ./$(NAME_CHECKER) 4 2 1 3 5
	ASAN_OPTIONS=detect_leaks=1 ./$(NAME_PUSH_SWAP) 4 2 1 3 5

.PHONY: debuginfo
debuginfo: CFLAGS += -g3
debuginfo: fclean $(OBJ_CHECKER) $(OBJ_PUSH_SWAP)
	make CFLAGS="$(CFLAGS)" -C $(LIB_DIR)
	$(CC) $(CFLAGS) -o $(NAME_CHECKER) $(OBJ_CHECKER) -I$(INC_DIR) -L$(LIB_DIR) $(LDFLAGS)
	$(CC) $(CFLAGS) -o $(NAME_PUSH_SWAP) $(OBJ_PUSH_SWAP) -I$(INC_DIR) -L$(LIB_DIR) $(LDFLAGS)

.PHONY: leaks
leaks: debuginfo
	valgrind --leak-check=full --track-fds=yes --show-leak-kinds=all ./$(NAME_CHECKER) 4 2 1 3 5
#	valgrind --leak-check=full --track-fds=yes --show-leak-kinds=all ./$(NAME_PUSH_SWAP) 4 2 1 3 5

.PHONY: clean
clean:
	make -C $(LIB_DIR) fclean
	$(RMF) $(OBJ_DIR_CHECKER) $(OBJ_DIR_PUSH_SWAP)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME_CHECKER) $(NAME_PUSH_SWAP)

.PHONY: re
re: fclean all
