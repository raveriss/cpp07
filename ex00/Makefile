# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 10:21:16 by raveriss          #+#    #+#              #
#    Updated: 2024/06/03 23:30:18 by raveriss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Utilise bash pour les commandes Makefile (nécessaire pour certaines syntaxes comme if, else if)
SHELL := /bin/bash

# Nom du projet
NAME = whatever
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = incs

# Compiler and flags
CXX = c++

# -Wall: turns on most, but not all, compiler warnings
# -Wconversion : Warn for implicit conversions that may alter a value
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -I$(INC_DIR)

# Source files and objects
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

# Directory creation command
DIR_GUARD = @mkdir -p $(@D)

# Total number of files
TOTAL_FILES := $(words $(SRCS))

# Currently compiled files count
CURRENT_FILE = 0

# Main targets
all: $(NAME)

# Rule for the executable
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo ""
	@echo "Compilation of $(NAME): Complete"

# Rule for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(DIR_GUARD)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@$(eval PERCENT=$(shell echo $$((($(CURRENT_FILE)*100)/$(TOTAL_FILES)))))
	@printf "\rCompiling $(NAME): ["
	@printf "%-50s" "$$(printf '#%.0s' $$(seq 1 $$(($(PERCENT)/2))))"
	@printf "] %d%%" $(PERCENT)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependencies
-include $(DEPS)

# Nettoie les objets et dépendances générés par le build
clean:
	@if [ -d $(OBJ_DIR) ]; then \
		echo "Cleaning..."; \
		rm -f $(OBJS) $(DEPS); \
		rm -rf $(OBJ_DIR); \
		echo "Objects and dependencies cleaned."; \
	else \
		echo "No objects or dependencies to clean."; \
	fi

# Nettoie les objets, dépendances et exécutable générés par le build
fclean: clean
	@if [ -f $(NAME) ]; then \
		echo "Removing $(NAME)..."; \
		rm -f $(NAME); \
		echo "$(NAME) removed."; \
	else \
		echo "$(NAME) not present."; \
	fi

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re