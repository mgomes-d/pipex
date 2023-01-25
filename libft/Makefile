# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 17:01:49 by mgomes-d          #+#    #+#              #
#    Updated: 2023/01/05 10:19:45 by mgomes-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar
ARFLAGS	= -rcs
RM		= rm
RMFLAGS	= -rf

# HEADERS
HEADERS_LIST = libft.h \
				ft_printf.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))
INCLUDES = -I$(HEADERS_DIRECTORY)

# SOURCES
SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = ft_atoi.c \
		  ft_isalpha.c \
		  ft_memset.c \
		  ft_strlcpy.c \
		  ft_bzero.c \
		  ft_isascii.c \
		  ft_strchr.c \
		  ft_strlen.c \
		  ft_tolower.c \
		  ft_calloc.c \
		  ft_isdigit.c \
		  ft_strdup.c \
		  ft_strncmp.c \
		  ft_toupper.c \
		  ft_isalnum.c \
		  ft_isprint.c \
		  ft_memmove.c \
		  ft_strlcat.c \
		  ft_strnstr.c \
		  ft_memcpy.c \
		  ft_strrchr.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_itoa.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_strmapi.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_lstnew_bonus.c \
		  ft_lstadd_front_bonus.c \
		  ft_lstsize_bonus.c \
		  ft_lstlast_bonus.c \
		  ft_lstadd_back_bonus.c \
		  ft_lstdelone_bonus.c \
		  ft_lstclear_bonus.c \
		  ft_lstiter_bonus.c \
		  ft_lstmap_bonus.c \
		  convert_base.c \
		  ft_printf.c \
		  ft_utilsfct.c \
		  ft_issymbol.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

# OBJECTS
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLOR FLAGS
CLR_BLACK   = \033[0;30m
CLR_RED		= \033[0;31m
CLR_GREEN	= \033[0;32m
CLR_LBLUE   = \033[0;94m
CLR_YELLOW  = \033[0;33m
CLR_MAGENTA = \033[0;35m
CLR_RESET	= \033[0m

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(CLR_GREEN)objects were created$(CLR_RESET)"
	@echo "$(NAME): $(CLR_GREEN)$(NAME) was created$(CLR_RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(CLR_GREEN)$(OBJECTS_DIRECTORY) was created$(CLR_RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(CLR_GREEN).$(CLR_RESET)\c"

clean:
	@$(RM) $(RMFLAGS) $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(CLR_RED)$(OBJECTS_DIRECTORY) was deleted$(CLR_RESET)"
	@echo "$(NAME): $(CLR_RED)objects were deleted$(CLR_RESET)"

fclean: clean
	@$(RM) $(RMFLAGS) $(NAME)
	@echo "$(NAME): $(CLR_RED)$(NAME) was deleted$(CLR_RESET)"

re: fclean all

.PHONY: all clean fclean re
