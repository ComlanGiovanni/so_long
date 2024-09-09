# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 03:25:21 by gicomlan          #+#    #+#              #
#    Updated: 2024/09/09 17:51:15 by gicomlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#‧₊˚✩ { ŝ̵̨̝̣̩̔ő̶͙̙̪̖̉̔_̵̱̯̙͑͘ͅĺ̷̟̼̌͠͝ǫ̶͇̑̋̕͜n̶͖̯͓̳̓̂̾͐g̷̡̿ } •. 。　.
# 																  (Library name)
MANDATORY_NAME			= so_long
BONUS_NAME				= so_long_bonus
LIB_SO_LONG_NAME		= lib_so_long.a
MLX_NAME				= libmlx.a
# ---------------------------------------------------------------- [ DIRECTORY ]
#												 (Directory for inclusion files)
INCLUDES_DIR			= includes/
# 													(Directory for object files)
OBJS_DIR				= objects/
MANDATORY_OBJS_DIR      = $(OBJS_DIR)mandatory/sources/
BONUS_OBJS_DIR          = $(OBJS_DIR)bonus/sources/
# 												(Directory for dependency files)
DEPS_DIR 				= dependencies/
MANDATORY_DEPS_DIR 		= $(DEPS_DIR)mandatory/sources/
BONUS_DEPS_DIR			= $(DEPS_DIR)bonus/sources/
# 											   	   (Directory for sources files)
SRCS_DIR				= sources/
MANDATORY_DIR			= mandatory/
BONUS_DIR				= bonus/
MANDATORY_PATH 			= $(MANDATORY_DIR)$(SRCS_DIR)
BONUS_PATH	 			= $(BONUS_DIR)$(SRCS_DIR)
# 														 	   	  (Paths to lib)
LIBS_DIR				= libraries/
MINI_LIB_DIR			= mini-libft/
MLX_DIR					= mlx/
MLX_PATH				= $(LIBS_DIR)$(MLX_DIR)
MINI_LIB_PATH			= $(LIBS_DIR)$(MINI_LIB_DIR)
# 									     	   	  (Paths to subdir sources files)
BONUS_SUBDIRS			+= animation
BONUS_SUBDIRS			+= check
BONUS_SUBDIRS			+= display
BONUS_SUBDIRS			+= gameplay
BONUS_SUBDIRS			+= init
BONUS_SUBDIRS			+= load
BONUS_SUBDIRS			+= parsing
BONUS_SUBDIRS			+= printing
BONUS_SUBDIRS			+= camera
BONUS_SUBDIRS			+= debug
BONUS_SUBDIRS			+= free
BONUS_SUBDIRS			+= hud
BONUS_SUBDIRS			+= input
BONUS_SUBDIRS			+= mlx
BONUS_SUBDIRS			+= path-founding
BONUS_SUBDIRS			+= update
BONUS_SUBDIRS			+= perlin-noise
BONUS_SUBDIRS			+= math
BONUS_SUBDIRS			+= menu
BONUS_SUBDIRS			+= levels
# -------------------------------------------------------------------------- []
# 							   (Calculation of the total number of source files)
#TOTAL_SRCS_FILES 	:= $(words $(BONUS_SRCS_FILES))----------------------------
#SRC_FILE_NAMES 		:= $(filter-out %main.c ,$(SRCS))
# 										            (Full paths to source files)
# Fichiers objets correspondants
#MANDATORY_SRCS_FILES	+= $(shell find $(MANDATORY_DIR) -name '*.c')
MANDATORY_SRCS_FILES	= mandatory/main.c \
						mandatory/sources/ft_check_map_finishable.c \
						mandatory/sources/ft_check_map_format_linux.c \
						mandatory/sources/ft_debug.c \
						mandatory/sources/ft_input_linux.c \
						mandatory/sources/ft_map_linux.c \
						mandatory/sources/ft_so_long_linux.c \
						mandatory/sources/ft_sprite_linux.c \
						mandatory/sources/ft_tools_linux.c \
						mandatory/sources/ft_utils_map_finishable.c

#BONUS_SRCS_FILES		+= $(BONUS_DIR)main.c
#BONUS_SRCS_FILES		+= $(foreach dir,$(BONUS_SUBDIRS),$(shell find $(BONUS_PATH)$(dir) -name '*.c'))
BONUS_SRCS_FILES	+= $(BONUS_DIR)main.c \
                    $(BONUS_DIR)sources/animation/ft_animation_alphabet_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_border_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_border_one_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_border_three_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_border_two_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_digits_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_door_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_even_alphabet_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_even_alphabet_one_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_even_alphabet_two_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_even_digits_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_gameplay_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_odd_alphabet_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_odd_alphabet_one_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_odd_alphabet_two_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_odd_digits_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_player_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_utils.c \
                    $(BONUS_DIR)sources/animation/ft_animation_wall_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_wall_utils_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_wall_utils_one_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_wall_utils_tree_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_wall_utils_two_bonus.c \
                    $(BONUS_DIR)sources/animation/ft_animation_world_bonus.c \
                    $(BONUS_DIR)sources/camera/ft_camera_bonus.c \
                    $(BONUS_DIR)sources/check/ft_check_bonus.c \
                    $(BONUS_DIR)sources/check/ft_check_utils_bonus.c \
                    $(BONUS_DIR)sources/debug/ft_debug_utils_one.c \
                    $(BONUS_DIR)sources/display/ft_display_assets_bonus.c \
                    $(BONUS_DIR)sources/display/ft_display_assets_borders_bonus.c \
                    $(BONUS_DIR)sources/display/ft_display_assets_borders_one_bonus.c \
                    $(BONUS_DIR)sources/display/ft_display_assets_borders_tree_bonus.c \
                    $(BONUS_DIR)sources/display/ft_display_assets_borders_two_bonus.c \
                    $(BONUS_DIR)sources/display/ft_display_assets_enemies_bonus.c \
                    $(BONUS_DIR)sources/display/ft_display_assets_gameplay_bonus.c \
                    $(BONUS_DIR)sources/display/ft_display_assets_gameplay_one_bonus.c \
                    $(BONUS_DIR)sources/display/ft_display_assets_one_bonus.c \
                    $(BONUS_DIR)sources/display/ft_display_assets_player_bonus.c \
                    $(BONUS_DIR)sources/display/ft_display_assets_utils_bonus.c \
                    $(BONUS_DIR)sources/display/ft_display_assets_utils_one_bonus.c \
                    $(BONUS_DIR)sources/display/ft_display_assets_wall_bit_mask_bonus.c \
                    $(BONUS_DIR)sources/display/ft_display_keke_assets_bonus.c \
                    $(BONUS_DIR)sources/free/ft_free_a_star_utils_bonus.c \
                    $(BONUS_DIR)sources/free/ft_free_bonus.c \
                    $(BONUS_DIR)sources/free/ft_free_parsing_bonus.c \
                    $(BONUS_DIR)sources/free/ft_free_utils_bonus.c \
                    $(BONUS_DIR)sources/gameplay/ft_monster_a_star_bonus.c \
                    $(BONUS_DIR)sources/gameplay/ft_monster_a_star_one_utils_bonus.c \
                    $(BONUS_DIR)sources/gameplay/ft_monster_a_star_utils_bonus.c \
                    $(BONUS_DIR)sources/gameplay/ft_monster_behaviour_bonus.c \
                    $(BONUS_DIR)sources/gameplay/ft_monster_behaviour_utils_bonus.c \
                    $(BONUS_DIR)sources/gameplay/ft_monster_event_bonus.c \
                    $(BONUS_DIR)sources/gameplay/ft_monster_movement.c \
                    $(BONUS_DIR)sources/gameplay/ft_pawn_patrolling.c \
                    $(BONUS_DIR)sources/gameplay/ft_pawn_patrolling_utils_bonus.c \
                    $(BONUS_DIR)sources/gameplay/ft_pawn_patrolling_utils_one_bonus.c \
                    $(BONUS_DIR)sources/gameplay/ft_pawn_patrolling_utils_tree_bonus.c \
                    $(BONUS_DIR)sources/gameplay/ft_pawn_patrolling_utils_two_bonus.c \
                    $(BONUS_DIR)sources/gameplay/ft_player_behaviour_bonus.c \
                    $(BONUS_DIR)sources/gameplay/ft_player_event_bonus.c \
                    $(BONUS_DIR)sources/hud/ft_hud_bonus.c \
                    $(BONUS_DIR)sources/hud/ft_hud_utils_bonus.c \
                    $(BONUS_DIR)sources/init/ft_init_a_star_bonus.c \
                    $(BONUS_DIR)sources/init/ft_init_bit_masking_frames.c \
                    $(BONUS_DIR)sources/init/ft_init_bonus.c \
                    $(BONUS_DIR)sources/init/ft_init_buttons_menu_state_bonus.c \
                    $(BONUS_DIR)sources/init/ft_init_frames_bonus.c \
                    $(BONUS_DIR)sources/init/ft_init_frames_one_bonus.c \
                    $(BONUS_DIR)sources/init/ft_init_hud_bonus.c \
                    $(BONUS_DIR)sources/init/ft_init_map_bonus.c \
                    $(BONUS_DIR)sources/init/ft_init_map_info_bonus.c \
                    $(BONUS_DIR)sources/init/ft_init_mlx_bonus.c \
                    $(BONUS_DIR)sources/init/ft_init_pawn_bonus.c \
                    $(BONUS_DIR)sources/init/ft_init_so_long_bonus.c \
                    $(BONUS_DIR)sources/input/ft_input_player_bonus.c \
                    $(BONUS_DIR)sources/input/ft_input_player_gameplay_bonus.c \
                    $(BONUS_DIR)sources/input/ft_input_player_utils_bonus.c \
                    $(BONUS_DIR)sources/input/ft_input_play_konami_bonus.c \
                    $(BONUS_DIR)sources/input/ft_input_utils_bonus.c \
                    $(BONUS_DIR)sources/levels/ft_levels_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_alphabet_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_alphabet_even_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_alphabet_even_one_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_alphabet_even_two_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_alphabet_odd_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_alphabet_odd_one_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_alphabet_odd_two_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_assets_utils_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_border_four_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_border_one_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_border_tree_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_border_two_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_buttons_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_buttons_assets_one_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_digits_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_door_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_even_digits_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_gameplay_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_gameplay_portal_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_monster_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_odd_digts_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_player_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_wall_direction_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_wall_no_plus_all_direction_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_wall_north_direction_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_wall_north_tree_direction_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_wall_south_direction_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_wall_west_direction_assets_bonus.c \
                    $(BONUS_DIR)sources/load/ft_load_world_assets_bonus.c \
                    $(BONUS_DIR)sources/math/ft_math_utils_one_bonus.c \
                    $(BONUS_DIR)sources/math/ft_math_utils_zero_bonus.c \
                    $(BONUS_DIR)sources/menu/ft_menu_system_action_bonus.c \
                    $(BONUS_DIR)sources/menu/ft_menu_system_bonus.c \
                    $(BONUS_DIR)sources/menu/ft_menu_system_draw_button_bonus.c \
                    $(BONUS_DIR)sources/menu/ft_menu_system_mouse_bonus.c \
                    $(BONUS_DIR)sources/mlx/ft_mlx_hook_loop_bonus.c \
                    $(BONUS_DIR)sources/parsing/ft_parsing_bonus.c \
                    $(BONUS_DIR)sources/parsing/ft_parsing_border_map_bonus.c \
                    $(BONUS_DIR)sources/parsing/ft_parsing_utils_bonus.c \
                    $(BONUS_DIR)sources/path-founding/ft_path_founding_bonus.c \
                    $(BONUS_DIR)sources/path-founding/ft_path_founding_utils_bonus.c \
                    $(BONUS_DIR)sources/perlin-noise/ft_perlin_noise_bonus.c \
                    $(BONUS_DIR)sources/perlin-noise/ft_perlin_noise_borders_fill_bonus.c \
                    $(BONUS_DIR)sources/perlin-noise/ft_perlin_noise_theme_bonus.c \
                    $(BONUS_DIR)sources/perlin-noise/ft_perlin_noise_theme_one_bonus.c \
                    $(BONUS_DIR)sources/perlin-noise/ft_perlin_noise_theme_two_bonus.c \
                    $(BONUS_DIR)sources/perlin-noise/ft_perlin_noise_utils_bonus.c \
                    $(BONUS_DIR)sources/perlin-noise/ft_perlin_noise_utils_math__bonus.c \
                    $(BONUS_DIR)sources/printing/ft_print_bonus.c \
                    $(BONUS_DIR)sources/printing/ft_print_console_bonus.c \
                    $(BONUS_DIR)sources/printing/ft_print_console_one_bonus.c \
                    $(BONUS_DIR)sources/printing/ft_print_game_state_bonus.c \
                    $(BONUS_DIR)sources/update/ft_update_bonus.c \
                    $(BONUS_DIR)sources/update/ft_update_loop_fonction_bonus.c \
                    $(BONUS_DIR)sources/update/ft_update_utils_bonus.c

# ---------------------------------------------------------------- [ OBJECTS ]
#OBJS_MANDATORY			= $(patsubst $(MANDATORY_DIR)%.c,$(MANDATORY_OBJS_DIR)%.o,$(MANDATORY_SRCS_FILES))
OBJS_MANDATORY			= $(MANDATORY_SRCS_FILES:mandatory/%.c=objects/mandatory/%.o)

#OBJS_BONUS				= $(patsubst $(BONUS_PATH)%.c,$(BONUS_OBJS_DIR)%.o,$(BONUS_SRCS_FILES))
OBJS_BONUS				= $(BONUS_SRCS_FILES:bonus/%.c=objects/bonus/%.o)
# ---------------------------------------------------------------- [ DEPENDENCIES ]
#DEPS_BONUS				= $(patsubst $(BONUS_PATH)%.c,$(BONUS_DEPS_DIR)%.d,$(BONUS_SRCS_FILES))
DEPS_BONUS				= $(BONUS_SRCS_FILES:bonus/%.c=dependencies/bonus/%.d)
#DEPS_MANDATORY			= $(patsubst $(MANDATORY_DIR)%.c,$(MANDATORY_DEPS_DIR)%.d,$(MANDATORY_SRCS_FILES))
DEPS_MANDATORY			= $(MANDATORY_SRCS_FILES:mandatory/%.c=dependencies/mandatory/%.d)
# ----------------------------------------------------------- ---------- [VPATH]
# 																  (virtual path)
vpath %.c $(MANDATORY_DIR)$(BONUS_DIR)
vpath %.o $(OBJS_DIR)
vpath %.d $(DEPS_DIR)
vpath %.h $(INCLUDES_DIR)
# ============================================================== [ COMPILATION ]
# 					   (Definition of variables and flags for compilation tools)
CC						:= cc
CFLAGS 					+= -Werror
CFLAGS 					+= -Wextra
CFLAGS 					+= -Wall -g3
#CFLAGS 				+= -fPIE
#CFLAGS 					+= -MMD
#CFLAGS 					+= -g
#CFLAGS 					+= -I $(INCLUDES_DIR)
#CFLAGS 				+= -lbsd
#CFLAGS 				+= -fsanitize=address
#CFLAGS 				+= -fsanitize=undefined
#CFLAGS 					+= -MP -MF $(DEPS_DIR)/$*.define
#CFLAGS 					+= -MP
#CFLAGS			+=	-O3
#CFLAGS			+=	-Ofast
#C_DEBUG_CFLAGS	+=	-g3

MAKE_NO_PRINT	:=	--no-print-directory
MAKE_FLAGS		+=	--silent
MAKE_FLAGS		+=	-C

VALGRIND				:=	valgrind
VALGRIND_FLAGES			+= --leak-check=full
VALGRIND_FLAGES			+= --show-leak-kinds=all
VALGRIND_FLAGES			+= --track-fds=yes
VALGRIND_FLAGES			+= --track-origins=yes
VALGRIND_FLAGES			+= --show-reachable=yes
VALGRIND_FLAGES			+= --error-limit=no
VALGRIND_FLAGES			+= --tool=memcheck

MLX_FLAGS				+= -L $(MLX_PATH)
MLX_FLAGS				+= -lmlx
MLX_FLAGS				+= -lXext
MLX_FLAGS				+= -lX11
MLX_FLAGS				+= -lm
MLX_FLAGS				+= -lz
# ------------------------------------------ [ Patterns of files to be removed ]
# ------------------------------------------- (Temporary,Objs,dependency files)
USELESS_FILES 			:= *~ *\# *.o *.d
DEPS_FILES				= $(DIR_DEPS)/*.d
# ----------------------------------------------------- (Defautl gcc executable)
ASSEMBLER_OUTPUT		:= a.out
# ==================================================================== [ TOOLS ]
# 								   		  (Tool for creating the static library)
ARFLAGS 				= rcs
# 														(Tool for file deletion)
RM						:= /bin/rm
RMFLAGS					:= -f
RMFLAGS					+= -r
# 												   (Tool for directory creation)
# Outil pour la création de répertoires
COPY					:= /bin/cp
MKDIR					:= mkdir
MKDIRFLAGS				:= -p
NULL_FILE				:= /dev/null
REDIRECT_STDERR			:= 2>&1
# =============================================================== [ NORMINETTE ]
# 												 (Command to run the norminette)
NORM				:=	norminette
NORM_FLAG			:=	-R CheckForbiddenSourceHeader
NORM_DEF_FLAG		:=	-R CheckDefine
NORM_SRC			:= "$(NORM) $(FULL_SRCS_SUBDIRS)"
NORM_HEAD			:= "$(NORM) $(NORM_FLAG) $(FULL_SRCS_SUBDIRS)"
NORM_DEFINE			:= "$(NORM) $(NORM_DEF_FLAG) $(DIR_INCLUDES)"
# =============================================================== [  ]
# 												 ()
#ifeq ($(OS),Darwin)
##	SHELL = /bin/bash
#	FLAGS_MLX 	= -lmlx -framework OpenGL -framework AppKit
#else ifeq ($(OS),Linux)
#	SHELL = /usr/bin/bash
#	FLAGS_MLX = -lmlx -lXext -lX11 -lm -lz
#else
#	$(error Incompatable OS Detected Linux and Mac os only)
#endif
# =================================================================== [ COLORS ]
# 														   (Colors for messages)
BLACK					=	\e[0;30m
RED						=	\e[0;31m
GREEN					=	\e[0;32m
ORANGE					=	\e[0;33m
BLUE					=	\e[0;34m
PURPLE					=	\e[0;35m
CYAN					=	\e[0;36m
LIGHT_GRAY				=	\e[0;37m
DARK_GRAY				=	\e[1;30m
LIGHT_RED				=	\e[1;31m
LIGHT_GREEN				=	\e[1;32m
YELLOW					=	\e[1;33m
LIGHT_BLUE				=	\e[1;34m
LIGHT_PURPLE			=	\e[1;35m
LIGHT_CYAN				=	\e[1;36m
WHITE					=	\e[1;37m
NO_COLOR				=	\e[0m
# =================================================================== [  ANSI  ]
# 		en angalis	 (Définir les séquences d'échappement ANSI)
BOLD 					= \e[1m
DIM 					= \e[2m
ITALIC					= \e[3m
UNDERLINE 				= \e[4m
BLINK					= \e[5m
REVERSE					= \e[7m
HIDDEN					= \e[8m
STRIKE					= \e[9m
RESET 					= \e[0m
# ================================================================= [ Messages ]
#												 (Colored display + emoji etc..)
COMPILE					=	"Starting the compilation of "
COMPILE_DONE			=	"compilation of "
MAKING					=	" Making of "
CLEANNING				=	" Cleanning of "
FCLEANNING				=	" Fcleanning of "
SO_LONG_COMP			=	echo "🚧$(BOLD)$(MAKING)$(RESET)$(YELLOW)$(ITALIC)$(MANDATORY_NAME)$(RESET): $(NO_COLOR)$(COMPILE_DONE)$(UNDERLINE)*.o$(RESET) done"
SO_LONG_BONUS_COMP		=	echo "🚧$(BOLD)$(MAKING)$(RESET)$(YELLOW)$(ITALIC)$(BONUS_NAME)$(RESET): $(NO_COLOR)$(COMPILE_DONE)$(UNDERLINE)*.o$(RESET) done"
MLX_COMP				=	echo "\n🚧$(BOLD)$(MAKING)$(RESET)$(PURPLE)$(MLX_NAME)$(NO_COLOR): $(COMPILE)$(UNDERLINE)*.o$(RESET) ..."
SO_LONG_READY			=	echo "\n🧮 $(RED)$(REVERSE)Mandatory$(RESET): $(RED) $(MANDATORY_NAME) ready!\n"
BONUS_READY				=	echo "\n🎯 $(CYAN)$(REVERSE)Bonus$(RESET): $(CYAN) $(BONUS_NAME) ready!\n"
CLEANED					=	echo "\n💧$(BOLD)$(CLEANNING)$(RESET)$(GREEN)$(ITALIC)$(UNDERLINE)$(MANDATORY_NAME)$(RESET)$(NO_COLOR) && $(GREEN)$(ITALIC)$(UNDERLINE)$(BONUS_NAME)$(RESET)$(NO_COLOR): $(DIM)Removed$(RESET) all the $(STRIKE)\".o\"$(RESET) files 🗑\\n"
FCLEANED				=	echo "\n🧼$(BOLD)$(FCLEANNING)$(RESET)$(GREEN)$(ITALIC)$(UNDERLINE)$(MANDATORY_NAME)$(RESET)$(NO_COLOR) && $(GREEN)$(ITALIC)$(UNDERLINE)$(BONUS_NAME)$(NO_COLOR): $(DIM)Removed$(RESET) the $(UNDERLINE)executables$(RESET) 🗑\\n"
MLX_CLEANED				=	echo "\n💧$(BOLD)$(CLEANNING)$(RESET)$(GREEN)$(ITALIC)$(UNDERLINE)$(MLX_NAME)$(RESET)$(NO_COLOR): $(DIM)Removed$(RESET) all the $(STRIKE)\".o\"$(RESET) files 🗑\\n"
MLX_FCLEANED			=	echo "\n🧼$(BOLD)$(FCLEANNING)$(RESET)$(GREEN)$(ITALIC)$(UNDERLINE)$(MLX_NAME)$(RESET)$(NO_COLOR): $(DIM)Removed$(RESET) the $(STRIKE)executables$(RESET) 🗑\\n"
NEW_LINE				=	echo "\n"
# ==================================================================== [ Rules ]
# 										  (Default rule for library compilation)
PROGRESS_BAR_SIZE	:= 50
COMPILED_SRCS_FILES	:= 0
PROGRESS_UNICODE	:= █
REMAINING_UNICODE	:= ▒

all : $(MANDATORY_NAME)
bonus : $(BONUS_NAME)
# 									(Compilation of object files into a library)
$(MANDATORY_NAME) : $(OBJS_MANDATORY)
	@$(NEW_LINE)
	@$(MAKE) $(MAKE_FLAGS) $(MINI_LIB_PATH)
	@$(COPY) $(MINI_LIB_PATH)$(LIB_SO_LONG_NAME) .
	@$(SO_LONG_COMP)
	@$(MLX_COMP)
	@$(loading_loop) & LOADING_PID=$$!; \
	$(MAKE) $(MAKE_NO_PRINT) $(MAKE_FLAGS) $(MLX_PATH) > $(NULL_FILE) $(REDIRECT_STDERR); \
	kill $$LOADING_PID; \
	printf "\r\033[0K";
	@$(COPY) $(MLX_PATH)$(MLX_NAME) .
	@$(CC) $(CFLAGS) -o $(MANDATORY_NAME) $(OBJS_MANDATORY) $(MLX_FLAGS) -L. $(MLX_NAME) -L. $(LIB_SO_LONG_NAME)
	@$(SO_LONG_READY)
	@echo "$$ASCII_MANDATORY"

$(BONUS_NAME) : $(OBJS_BONUS)
	@$(NEW_LINE)
	@$(MAKE) $(MAKE_NO_PRINT) $(MAKE_FLAGS) $(MINI_LIB_PATH)
	@$(COPY) $(MINI_LIB_PATH)$(LIB_SO_LONG_NAME) .
	@$(SO_LONG_BONUS_COMP)
	@$(MLX_COMP)
	@$(loading_loop) & LOADING_PID=$$!; \
	$(MAKE) $(MAKE_NO_PRINT) $(MAKE_FLAGS) $(MLX_PATH) > $(NULL_FILE) $(REDIRECT_STDERR); \
	kill $$LOADING_PID; \
	printf "\r\033[0K";
	@$(COPY) $(MLX_PATH)$(MLX_NAME) .
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJS_BONUS) $(MLX_FLAGS) -L. $(MLX_NAME) -L. $(LIB_SO_LONG_NAME)
	@$(BONUS_READY)
	@echo "$$ASCII_BONUS"
# 							   (Rule for creating object files and dependencies)

objects/mandatory/%.o: mandatory/%.c
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEPS_MANDATORY))
	@$(eval TOTAL_SRCS_FILES := $(words $(MANDATORY_SRCS_FILES)))
	@$(call progress_bar)
	@$(CC) $(CFLAGS) -MMD -c -I $(INCLUDES_DIR) -MP $< -o $@ -MF dependencies/mandatory/$(patsubst mandatory/%.c,%.d,$<)

objects/bonus/%.o: bonus/%.c
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEPS_BONUS))
	@$(eval TOTAL_SRCS_FILES := $(words $(BONUS_SRCS_FILES)))
	@$(call progress_bar)
	@$(CC) $(CFLAGS) -MMD -c -I $(INCLUDES_DIR) -MP $< -o $@ -MF dependencies/bonus/$(patsubst bonus/%.c,%.d,$<)

clean :
	$(RM) $(RMFLAGS) $(OBJS_DIR) > $(NULL_FILE)
	$(RM) $(RMFLAGS) $(DEPS_DIR) > $(NULL_FILE)
	$(MAKE) $(MAKE_NO_PRINT) $(MAKE_FLAGS) $(MINI_LIB_PATH) clean
	$(MLX_CLEANED)
	$(MAKE) $(MAKE_NO_PRINT) $(MAKE_FLAGS) $(MLX_PATH) clean > $(NULL_FILE)
	$(CLEANED)
# 													(Rule for complete cleaning)
fclean : clean
	$(RM) $(RMFLAGS) $(MANDATORY_NAME) > $(NULL_FILE)
	$(RM) $(RMFLAGS) $(BONUS_NAME) > $(NULL_FILE)
	$(RM) $(RMFLAGS) $(LIB_SO_LONG_NAME) > $(NULL_FILE)
	$(RM) $(RMFLAGS) $(MLX_NAME) > $(NULL_FILE)
	$(MLX_FCLEANED)
	$(MAKE) $(MAKE_NO_PRINT) $(MAKE_FLAGS) $(MINI_LIB_PATH) fclean
	$(FCLEANED)

# 												(Rule for rebuilding everything)
re : fclean all

debug_make:
	@echo "MANDATORY_PATH = $(MANDATORY_PATH)"
	@echo "MANDATORY_SRCS_FILES = $(MANDATORY_SRCS_FILES)"

info:
	@echo "$$INFO_MSG"

norminette :
	$(NORM) $(INCLUDES_DIR)
	$(NORM) $(MANDATORY_DIR)
	$(NORM) $(BONUS_DIR)

# 								(Rule for checking compliance with the standard)

define INFO_MSG
Usage: make [TARGET]

all         - Build the main program
clean       - Remove object file(s)
fclean      - Remove object file(s) and binary file(s)
re          - Rebuild the program
bonus       - Build the bonus part of the program
norm        - Run norminette checks
help        - Display this help message

Summary:
This project is a very small 2D game.
Its purpose is to make you work with textures, sprites,
and some other very basic gameplay elements.
Version: 3
endef
export INFO_MSG

norm :
	@ALL_NORM_CHECK=0; \
	for cmd in $(NORM_SRC) $(NORM_HEAD) $(NORM_DEFINE); do \
		if ! eval $$cmd 2>&1; then \
			ALL_NORM_CHECK=1; \
			$(NORM_KO); \
		else \
			$(NORM_OK); \
		fi; \
	done; \
	if [ $$ALL_NORM_CHECK -eq 0 ]; then \
		$(GLOBAL_NORM_OK); \
	else \
		$(GLOBAL_NORM_KO); \
	fi
# ============================================================= [ PROGRESS BAR ]
# 									  (Function to display compilation progress)
define progress_bar
    @$(eval COMPILED_SRCS_FILES := $(shell expr $(COMPILED_SRCS_FILES) + 1))
    @printf "⚙️  "
    @$(eval PROGRESS := $(shell expr $(COMPILED_SRCS_FILES) \* $(PROGRESS_BAR_SIZE) / $(TOTAL_SRCS_FILES)))
    @$(eval REMAINING := $(shell expr $(PROGRESS_BAR_SIZE) - $(PROGRESS)))
    @printf "$(RED)%$(PROGRESS)s$(NO_COLOR)" | sed 's/ /$(PROGRESS_UNICODE)/g'
    @printf "$(BLUE)%$(REMAINING)s$(NO_COLOR)" | sed 's/ /$(REMAINING_UNICODE)/g'
    @printf " (%.2f%%) [%d/%d] %s" \
        $(shell echo "scale=2; $(COMPILED_SRCS_FILES)/$(TOTAL_SRCS_FILES) * 100" | bc) \
        $(COMPILED_SRCS_FILES) $(TOTAL_SRCS_FILES) $(notdir $<)
    @printf "\033[0K\r"
endef

define loading_loop
	while true; do \
		for i in / - \\ \|; do \
			printf "\r[$(CYAN)%s$(NO_COLOR)]" "$$i"; \
			sleep 0.1; \
		done \
	done
endef

# =============================================================== [ DEPENDENCY ]
# 													(Including dependency files)
-include $(DEPS_MANDATORY)
-include $(DEPS_BONUS)
# ==================================================================== [ ASCII ]
# 							 (Ascii are to diplay at the end of the compilation)
coffee:
	@./coffee.sh

# ==================================================================== [ ASCII ]
# 							 (Ascii are to diplay at the end of the compilation)

define ASCII_MANDATORY
$(RED)                       ,         $(NO_COLOR)
$(RED)       ❤            .:/          $(NO_COLOR)
$(RED)         o      ,,///;,   ,;/    $(NO_COLOR)
$(RED)           o   o)::::::;;///     $(NO_COLOR)
$(RED)              >::::::::;;\\\     $(NO_COLOR)
$(RED)                ''\\\\\'" ';\    $(NO_COLOR)
$(RED)                   ';\           $(NO_COLOR)
endef
export ASCII_MANDATORY

define ASCII_BONUS
$(CYAN) o									$(NO_COLOR)
$(CYAN)o      ______/~/~/~/__           /((	$(NO_COLOR)
$(CYAN)  o  // __            ====__    /_((	$(NO_COLOR)
$(CYAN) o  //  @))       ))))      ===/__((	$(NO_COLOR)
$(CYAN)    ))           )))))))        __((	$(NO_COLOR)
$(CYAN)    \\     \)     ))))    __===\ _((	$(NO_COLOR)
$(CYAN)     \\_______________====      \_((	$(NO_COLOR)
$(CYAN)                                 \((	$(NO_COLOR)
endef
export ASCII_BONUS

.PHONY: all clean fclean re bonus coffee info debug_make help norm coffee loading_loop progress_bar
.SILENT: re clean fclean
# ‧₊˚✩ { E̶̩̹̽ṉ̸̂d̷̰̫̉͊ ̷̖̀Ọ̴͆͝f̴͎̒ ̸̡͈̀̊M̵̞͘a̷͓̞͂͝ḳ̶̚é̴̹̈f̸̞̟̀́i̵̤͆l̷͔̐ḛ̵̥̎̓  •. 。　.
