#==============================================================================#
#                               PUSH_SWAP PROJECT                              #
#==============================================================================#

# Main target names
NAME = push_swap
NAME_BONUS = checker

#------------------------------------------------------------------------------#
#                                COLORS & STYLES                               #
#------------------------------------------------------------------------------#

# ANSI color codes for prettier output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Text style codes
BOLD = \033[1m
DIM = \033[2m
ITALIC = \033[3m
UNDERLINE = \033[4m

# Emojis for visual feedback
CHECK = ✓
CLEAN = 🧹
BUILD = 🔨
ROCKET = 🚀
BOOK = 📚
SPARKLES = ✨

#------------------------------------------------------------------------------#
#                            	  NAMES AND PATHS                              #
#------------------------------------------------------------------------------#

# Directory structure
BUILD_PATH = .build
SRC_PATH = .
BONUS_PATH = .
INC_PATH = .
HEADERS = ${INC_PATH}/push_swap.h
LIBFT_PATH = libft
LIBFT_ARC = ${LIBFT_PATH}/libft.a

# Source files for main library
SRCS = ${addprefix ${SRC_PATH}/, errors.c phase_two.c sorts.c stack_utils.c \
	main.c push_commands.c sorts_init.c swap_commands.c optimization.c \
	reverse_rotate_commands.c sorts_init_utils.c phase_one.c \
	rotate_commands.c sorts_utils.c phase_three.c set_indices.c stack_init.c}
SRCS_BONUS = ${addprefix ${BONUS_PATH}/, }

# Object files derived from source files
OBJS = ${addprefix ${BUILD_PATH}/, ${notdir ${SRCS:.c=.o}}}
OBJS_BONUS = ${addprefix ${BUILD_PATH}/, ${notdir ${SRCS_BONUS:.c=.o}}}

#------------------------------------------------------------------------------#
#                            	   FLAGS & COMMANDS                            #
#------------------------------------------------------------------------------#

CC = cc                           # Compiler to use
CCFLAGS = -Wall -Wextra -Werror -g # Compiler flags for warnings/errors/debugging
LDFLAGS = -L${LIBFT_PATH} -lft
AR = ar rcs                       # Archive command to create static libraries
RM = rm -fr                       # Command to remove files/directories forcefully
MKDIR_P = mkdir -p                # Command to create directories (with parent)
INC = -I ${INC_PATH}              # Include path for header file
MAKE = make --no-print-directory -C
MAKE_EXTRA = make extra --no-print-directory -C

VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

#------------------------------------------------------------------------------#
#                                    RULES                                     #
#------------------------------------------------------------------------------#

##  Compilation Rules for push_swap  ##

all: deps ${NAME}                 

${NAME}: ${BUILD_PATH} ${OBJS} ${LIBFT_ARC}
	@printf "${CYAN}${DIM}Compiling main.c for running the program...${RESET}\n"
	@${CC} ${CCFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}
	@printf "${GREEN}${BOLD}${CHECK} push_swap executable compiled successfully!${RESET}\n"
	@printf "${YELLOW}${BOLD}To run program type: ./push_swap followed by the arguments.${RESET}\n"

${BUILD_PATH}:
	@printf "\n${BLUE}${BOLD}Creating build directory...${RESET}\n"
	@${MKDIR_P} ${BUILD_PATH}
	@printf "${GREEN}${BOLD}${CHECK} Build directory created successfully!${RESET}\n"

${LIBFT_ARC}: deps
	@printf "${CYAN}${BOLD}${DIM} Compiling Libft..${RESET}\n"
	@${MAKE_EXTRA} ${LIBFT_PATH}
	@printf "${BLUE}${BOLD}${BUILD} ${WHITE}${LIBFT_ARC}${GREEN} compiled! ${RESET}\n"

${BUILD_PATH}/%.o: ${SRC_PATH}/%.c ${HEADERS} | ${BUILD_PATH}
	@printf "${CYAN}${DIM}Compiling: ${WHITE}%-30s${RESET}\r" ${notdir $<}
	@${CC} ${CCFLAGS} ${INC} -c $< -o $@

${BUILD_PATH}/%.o: ${BONUS_PATH}/%.c ${HEADERS} | ${BUILD_PATH}
	@printf "${CYAN}${DIM}Compiling: ${WHITE}%-30s${RESET}\r" ${notdir $<}
	@${CC} ${CCFLAGS} ${INC} -c $< -o $@

deps:
	@if test ! -d "${LIBFT_PATH}"; then make get_libft; \
		else printf "${GREEN}${BOLD}${ROCKET} ${WHITE}${LIBFT_ARC}${GREEN} folder found!${RESET}\n"; fi

get_libft:
	@printf "${CYAN}${BOLD}${BOOK} Getting Libft..${RESET}\n"
	@git clone git@github.com:melaniereis/libft.git ${LIBFT_PATH}
	@printf "${GREEN}${BOLD}${ROCKET} ${WHITE}${LIBFT_ARC}${GREEN} successfully downloaded!${RESET}\n"



##bonus: ${BUILD_PATH} ${OBJS} ${LIBFT_ARC}
##	@printf "${CYAN}${DIM}Compiling main.c for test...${RESET}\n"
##	@${CC} ${CCFLAGS} main.c ${OBJS} ${LDFLAGS} -o ${EXEC}
##	@printf "${GREEN}${BOLD}${CHECK} Test executable compiled successfully!${RESET}\n"
##	@printf "${YELLOW}${BOLD}Running test...${RESET}\n"
##	@./${EXEC}
##	@printf "${GREEN}${BOLD}${CHECK} Test completed!${RESET}\n"
##	@${RM} ${EXEC}

##  Norms Rules  ##

norm:                # Check norms for mandatory sources 
	@printf "\n${BLUE}${BOLD}${TEST} Checking Norminette...${RESET}\n"
	@norminette_output=$$(norminette *.c *.h | grep -v "OK!" || true); \
	if [ -z "$$norminette_output" ]; then \
		printf "${GREEN}${BOLD}${CHECK} No norminette errors found!${RESET}\n"; \
	else \
		printf "$$norminette_output\n"; \
		printf "${RED}${BOLD}❌ Norminette errors found.${RESET}\n"; \
	fi
	@printf "${GREEN}${BOLD}${CHECK} Norminette check completed!${RESET}\n"

##   Check for forbidden functions  ##
check_forbidden_functions: ${NAME}
	@printf "\n${BLUE}${BOLD}Checking for forbidden functions...${RESET}\n"
	@nm ${NAME} | grep "U " | grep -E "malloc|free|printf|write" || true
	@if [ $$? -eq 0 ]; then \
		printf "${RED}${BOLD}❌ Forbidden functions detected${RESET}\n"; \
		exit 1; \
	else \
		printf "${GREEN}${BOLD}${CHECK} No forbidden functions found${RESET}\n"; \
	fi

##  Check for leaks  ##

test_valgrind: ${NAME}
	@printf "${YELLOW}${BOLD}Running tests with Valgrind...${RESET}\n"
	@printf "\n${PURPLE}${BOLD}Testing file with Valgrind: ${NAME}${RESET}\n"
	@VALGRIND_OUTPUT="$$(${VALGRIND} ${VALGRIND_FLAGS} ./${NAME} 2>&1)"
	@if echo "$$VALGRIND_OUTPUT" | grep -q "definitely lost" || \
		echo "$$VALGRIND_OUTPUT" | grep -q "indirectly lost" || \
		echo "$$VALGRIND_OUTPUT" | grep -q "possibly lost" || \
		echo "$$VALGRIND_OUTPUT" | grep -q "still reachable"; then \
		printf "${RED}${BOLD}Memory leak detected!${RESET}\n"; \
		echo "$$VALGRIND_OUTPUT" | grep -E "definitely|indirectly|possibly|still reachable"; \
	else \
		printf "${GREEN}${BOLD}No leaks detected.${RESET}\n"; \
	fi

##  Cleaning Rules  ##

clean:                       # Clean up object files and temporary build files 
	@printf "\n${YELLOW}${BOLD}${CLEAN} Cleaning object files...${RESET}\n"
	@${RM} ${OBJS} ${OBJS_BONUS}
	@printf "${GREEN}${BOLD}${CHECK} Object files cleaned!${RESET}\n"

fclean: clean               # Fully clean up by removing executables and build directories 
	@printf "${YELLOW}${BOLD}${CLEAN} Removing executable, libft.a and build files...${RESET}\n"
	@${RM} ${NAME}
	@${RM} ${BUILD_PATH}
	@${MAKE} ${LIBFT_PATH} fclean
	@printf "${GREEN}${BOLD}${CHECK} All files cleaned!${RESET}\n"

re: fclean ${NAME}          # Rebuild everything from scratch 

.PHONY: all clean fclean re norm get_libft deps check_forbidden_functions
# Declare phony targets
