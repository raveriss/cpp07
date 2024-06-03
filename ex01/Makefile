# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 10:21:16 by raveriss          #+#    #+#              #
#    Updated: 2024/05/28 11:25:07 by raveriss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for the Zombie project with progress bar and separate object directory

NAME = serializer
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = incs

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wconversion -std=c++98 -MMD -I$(INC_DIR)

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

# Function to display the progress bar
define progress_bar
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@$(eval PERCENT=$(shell echo $$((100 * $(CURRENT_FILE) / $(TOTAL_FILES)))))
	@printf "\r%s [%-50s] %d%%" "$(1)" "$$(printf '#%.0s' $$(seq 1 $$(($(PERCENT) / 2))))" $(PERCENT)
endef

# Function to reset the progress variables
define reset_progress
	@$(eval CURRENT_FILE=0)
	@$(eval TOTAL_FILES=$(1))
endef

clean:
	@echo "Cleaning..."
	@$(foreach obj,$(OBJS) $(DEPS),rm -f $(obj);)
	@rm -rf obj 
	@echo "Objects and dependencies cleaned."


fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
	@echo "$(NAME) removed."


# Rebuild everything
re: fclean all

.PHONY: all clean fclean re