# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 15:01:32 by aschenk           #+#    #+#              #
#    Updated: 2025/05/02 15:54:34 by aschenk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			FragTrap

# SOURCE FILES
SRCS_DIR :=		src
SRCS_FILES :=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp \
				DiamondTrap.cpp
				
SRCS :=			$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
				
# OBJECT FILES
OBJS_DIR :=		obj
OBJS :=			$(SRCS:%.cpp=$(OBJS_DIR)/%.o)
DEPS :=			$(OBJS:.o=.d)

# HEADER FILES
HDRS_DIR :=		include

# COMPILER
CXX :=			c++
CFLAGS :=		-std=c++98
CFLAGS +=		-Werror -Wextra -Wall
CFLAGS +=		-I$(HDRS_DIR)
CFLAGS +=		-Wshadow
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
# Compiles and links all o. files into the final binary.
# Print out l once program is compiled.
$(NAME):	$(OBJS)
	@$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BOLD)$(YELLOW)\n$(NAME) successfully compiled.$(RESET)"

## COMPILATION PROGRESS BAR ##
# Compiles individual .cpp files into .o object files without linking.
# Last line:
# -c:		Generates o. files without linking.
# -$<:		Represents the first prerequisite (the c. file).
# -o $@:	Output file name;  '$@' is replaced with target name (the o. file).
# -MMD:		Generates a dependency file for each source file.
# -MP:		Prevents make from failing if the header file is deleted.
$(OBJS_DIR)/%.o:	%.cpp
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
	@$(CXX) $(CFLAGS) -c -MMD -MP $< -o $@

# Rule to remove all generated object files.
clean:
	@rm -rf $(OBJS_DIR)
	@rm -f *.gch 
	@echo "$(BOLD)$(RED)$(NAME) object files removed.$(RESET)"

# Rule to remove all generated object files and the program executable.
fclean:	clean
	@rm -f $(NAME)
	@echo "$(BOLD)$(RED)$(NAME) removed.$(RESET)"

# Rule to remove all generated object files, the program executable,
# and then rebuild the program.
re:	fclean all

# Makes that make rules are invoked even if files of the same name happen to be in the directory.
.PHONY: all clean fclean re

# Include dependency files if they exist
-include $(DEPS)
