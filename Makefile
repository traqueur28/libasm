#    Colors
GREY = \e[90m
RED = \e[91m
GREEN = \e[92m
YELLOW = \e[93m
BLUE = \e[34m
PURPLE = \e[95m
CYAN = \e[96m
END = \e[39m

#    Showing command
DISP = TRUE

ifeq ($(DISP),TRUE)
    HIDE =
else
    HIDE = @
endif

#    Includes
INC_PATH	=	inc/

INC_FILES	=	libasm.h

INC			=	$(addprefix $(INC_PATH), $(INC_FILES))

#    Files
SRCS_PATH = src

FILES = ft_read.s \
		ft_strcmp.s	\
		ft_strcpy.s \
		ft_strdup.s \
		ft_strlen.s \
	 	ft_write.s

SRCS = $(addprefix $(SRCS_PATH)/, $(FILES))

#    Compilation
NAME = libasm.a

MAIN = tester.c

TEST = tester

CC = nasm -f elf64

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

OBJS_PATH = objs/

OBJS = $(patsubst $(SRCS_PATH)%.s,    $(OBJS_PATH)%.o,    $(SRCS))

#    Rules
all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	@ echo "$(BLUE)\n         ***Make $(NAME) ***\n$(END)"
	$(HIDE) ar rcs $(NAME) $(OBJS)
	@ echo "$(GREEN)\n        ---$(NAME) created ---\n$(END)"

$(OBJS_PATH):
	$(HIDE) mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.s Makefile $(INC)
	$(HIDE) $(CC) -s $< -o $@
	@ echo "$(GREEN)[ OK ]$(END) $(CYAN)${<:.s=.o}$(END)"

tester: $(NAME) $(INC) $(MAIN)
	$(HIDE) gcc $(FLAGS) $(MAIN) -L. -lasm -o $(TEST)
	$(HIDE) ./$(TEST)

clean:
	$(HIDE) $(RM) $(OBJS_PATH)
	@ echo "$(PURPLE)\n        *** Clean objects ***\n$(END)"

fclean: clean
	$(HIDE) $(RM) $(NAME) $(TEST)
	@ echo "$(RED)\n        *** Remove $(NAME) and $(TEST) ***\n$(END)"

re: fclean all

hello:
	@ nasm -f elf64 -o hello.o hello.s
	@ ld -o hello hello.o
	@ ./hello
	@ rm -rf hello.o hello

.PHONY: all clean fclean re hello tester