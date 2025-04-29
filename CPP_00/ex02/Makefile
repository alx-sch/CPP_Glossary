# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 12:24:25 by aschenk           #+#    #+#              #
#    Updated: 2025/04/29 20:03:55 by aschenk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			test_accounts

# SOURCE FILES
SRCS :=			Account.cpp \
				tests.cpp

# OBJECT FILES
OBJS_DIR :=		obj
OBJS :=			$(SRCS:%.cpp=$(OBJS_DIR)/%.o)

# HEADER FILES
HDRS :=			Account.hpp

# COMPILER
CC :=			c++
CFLAGS :=		-std=c++98
CFLAGS +=		-Werror -Wextra -Wall
CFLAGS +=		-I$(HDRS_DIR)
CFLAGS +=		-Wpedantic
#CFLAGS +=		-g

# Used for progress bar
TOTAL_SRCS :=	$(words $(SRCS))
SRC_NUM :=		0

# ANSI escape codes for colors and styles
RESET =			\033[0m
BOLD =			\033[1m
GREEN =			\033[32m
YELLOW =		\033[33m
RED :=			\033[91m

###########
## RULES ##
###########

# Default target
all:		$(NAME)

# Target $(NAME) depends on object files $(OBJS)
# Print out logo once program is compiled.
$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BOLD)$(YELLOW)\n$(NAME) successfully compiled.$(RESET)"

	@echo -n "$(BOLD)$(GREEN)"
	@echo "   _   ___ ___ ___  _   _ _  _ _____ ___"
	@echo "  /_\ / __/ __/ _ \| | | | \| |_   _/ __| "
	@echo " / _ \ (_| (_| (_) | |_| | .\` | | | \__ \ "
	@echo "/_/ \_\___\___\___/ \___/|_|\_| |_| |___/"
	@echo -n "$(RESET)"

	@echo "\n$(BOLD)$(YELLOW)Usage: './$(NAME)'$(RESET)"
	@echo "$(BOLD)$(YELLOW)The output will be saved to '[timestamp].log'.$(RESET)"

## COMPILATION PROGRESS BAR ##
# Rule to define how to generate object files (%.o) from corresponding
# source files (%.c). Each .o file depends on the associated .c file and the
# project header files.
# Last line:
# -c:		Generates o. files without linking.
# -$<:		Represents the first prerequisite (the c. file).
# -o $@:	Output file name;  '$@' is replaced with target name (the o. file).
$(OBJS_DIR)/%.o:	%.cpp $(HDRS)
	@mkdir -p $(@D)
	@$(eval SRC_NUM := $(shell expr $(SRC_NUM) + 1))
	@$(eval PERCENT := $(shell printf "%.0f" $(shell echo "scale=4; $(SRC_NUM) / $(TOTAL_SRCS) * 100" | bc)))
	@printf "$(BOLD)\rCompiling $(NAME): ["
	@$(eval PROGRESS := $(shell expr $(PERCENT) / 5))
	@printf "$(GREEN)%0.s#$(RESET)$(BOLD)" $(shell seq 1 $(PROGRESS))
	@if [ $(PERCENT) -lt 100 ]; then printf "%0.s-" $(shell seq 1 $(shell expr 20 - $(PROGRESS))); fi
	@printf "] "
	@if [ $(PERCENT) -eq 100 ]; then printf "$(GREEN)"; fi
	@printf "%d/%d - " $(SRC_NUM) $(TOTAL_SRCS)
	@printf "%d%% $(RESET)" $(PERCENT)
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to remove all generated object files.
clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(BOLD)$(RED)$(NAME) object files removed.$(RESET)"

# Rule to remove all generated object files, the program executable, and log files.
fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME) *.log
	@echo "$(BOLD)$(RED)$(NAME) and .log files removed.$(RESET)"

# Rule to remove all generated object files, the program executable,
# and then rebuild the program.
re:	fclean all

# Makes that make rules are invoked even if files of the same name happen to be in the directory.
.PHONY: all clean fclean re
