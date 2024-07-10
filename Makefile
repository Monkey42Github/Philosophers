
TARGET		= philo
SRCS		= check.c main.c simulation.c ft_time.c one_philo.c
HEADERS		=
CC			= gcc
C_FLAGS		= -Wall -Wextra -Werror
LD			= $(CC)
OBJS		= $(SRCS:%.c=%.o)
RM			= rm -rf

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(LD) $(OBJS) -o $(TARGET)
	@printf "LD $(TARGET)\n"

%.o: %.c $(HEADERS)
	@$(CC) -c $(C_FLAGS) $< -o $@
	@printf "CC $<\n"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re

