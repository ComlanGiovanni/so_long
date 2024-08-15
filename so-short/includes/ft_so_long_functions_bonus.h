/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_functions_bonus.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:24:23 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 17:10:01 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_FUNCTIONS_BONUS_H
# define FT_SO_LONG_FUNCTIONS_BONUS_H

//=============================== [ ft_animation_alphabet_bonus.c ]

void	ft_alphabet_animation(t_game *game);
void	ft_odd_alphabet_animation(t_game *game);
void	ft_even_alphabet_animation(t_game *game);

//============ [ ft_animation_bonus.c ]

void	ft_play_animation(t_game *game);

//============ [ ft_animation_border_bonus.c ]

void	ft_borders_animation(t_game *game);

//============ [ ft_animation_border_one_bonus.c ]

void	ft_tree_animation(t_animation *animation);
void	ft_trees_animation(t_animation *animation);
void	ft_reed_animation(t_animation *animation);
void	ft_husks_animation(t_animation *animation);
void	ft_fungus_animation(t_animation *animation);

//============ [ ft_animation_border_three_bonus.c ]

void	ft_foliage_animation(t_animation *animation);
void	ft_bog_animation(t_animation *animation);
void	ft_snail_animation(t_animation *animation);
void	ft_pillar_animation(t_animation *animation);
void	ft_hedge_animation(t_animation *animation);

//============ [ ft_animation_border_two_bonus.c ]

void	ft_fungi_animation(t_animation *animation);
void	ft_flower_animation(t_animation *animation);
void	ft_algae_animation(t_animation *animation);
void	ft_water_animation(t_animation *animation);
void	ft_crab_animation(t_animation *animation);

//============ [ ft_animation_digits_bonus.c ]

void	ft_digits_animation(t_game *game);

//============ [ ft_animation_door_bonus.c ]

void	ft_door_open_animation(t_anim_door *animation);
void	ft_door_closed_animation(t_anim_door *animation);

//============ [ ft_animation_even_alphabet_bonus.c ]

void	ft_alphabet_b_animation(t_animation *animation);
void	ft_alphabet_d_animation(t_animation *animation);
void	ft_alphabet_f_animation(t_animation *animation);
void	ft_alphabet_h_animation(t_animation *animation);
void	ft_alphabet_j_animation(t_animation *animation);

//============ [ ft_animation_even_alphabet_one_bonus.c ]

void	ft_alphabet_l_animation(t_animation *animation);
void	ft_alphabet_n_animation(t_animation *animation);
void	ft_alphabet_p_animation(t_animation *animation);
void	ft_alphabet_r_animation(t_animation *animation);
void	ft_alphabet_t_animation(t_animation *animation);

//============ [ ft_animation_even_alphabet_two_bonus.c ]

void	ft_alphabet_v_animation(t_animation *animation);
void	ft_alphabet_x_animation(t_animation *animation);
void	ft_alphabet_z_animation(t_animation *animation);

//============ [ ft_animation_utils.c ]

void	ft_five_animation(t_animation *animation);
void	ft_six_animation(t_animation *animation);
void	ft_seven_animation(t_animation *animation);
void	ft_eight_animation(t_animation *animation);
void	ft_nine_animation(t_animation *animation);

//============ [ ft_animation_gameplay_bonus.c ]

void	ft_box_animation(t_animation *animation);
void	ft_portal_n_animation(t_animation *animation);
void	ft_portal_z_animation(t_animation *animation);
void	ft_grass_animation(t_animation *animation);

//============ [ ft_animation_odd_alphabet_bonus.c ]

void	ft_alphabet_a_animation(t_animation *animation);
void	ft_alphabet_c_animation(t_animation *animation);
void	ft_alphabet_e_animation(t_animation *animation);
void	ft_alphabet_g_animation(t_animation *animation);
void	ft_alphabet_i_animation(t_animation *animation);

//============ [ ft_animation_odd_alphabet_one_bonus.c ]

void	ft_alphabet_k_animation(t_animation *animation);
void	ft_alphabet_m_animation(t_animation *animation);
void	ft_alphabet_o_animation(t_animation *animation);
void	ft_alphabet_q_animation(t_animation *animation);
void	ft_alphabet_s_animation(t_animation *animation);

//============ [ ft_animation_odd_alphabet_two_bonus.c ]

void	ft_alphabet_u_animation(t_animation *animation);
void	ft_alphabet_w_animation(t_animation *animation);
void	ft_alphabet_y_animation(t_animation *animation);

//============ [ ft_animation_odd_digits_bonus.c ]

void	ft_zero_animation(t_animation *animation);
void	ft_one_animation(t_animation *animation);
void	ft_two_animation(t_animation *animation);
void	ft_three_animation(t_animation *animation);
void	ft_four_animation(t_animation *animation);

//============ [ ft_animation_player_bonus.c ]

void	ft_player_animation(t_player *player);
void	ft_keke_animation(t_keke *keke);

//============ [ ft_animation_utils.c ]

void	ft_generic_animation(t_animation *animation, int *frame);

//============ [ ft_animation_world_bonus.c ]

void	ft_wall_animation(t_animation *animation);
void	ft_pawn_animation(t_animation *animation);
void	ft_lava_animation(t_animation *animation);
void	ft_key_animation(t_animation *animation);
void	ft_love_animation(t_animation *animation);

//============ [ ft_camera_bonus.c  ]

void	ft_camera_shake(t_game *game);
void	ft_update_camera(t_game *game);

//============ [ ft_check_bonus.c ]

void	ft_check_map(t_game *game);
void	ft_map_fit_screen(t_game *game);
int		ft_check_extension(char *map_name, char *extension);
void	ft_check_env(char **envp);

//============ [ check/ft_debug_bonus.c ]

//============ [ check/ft_check_bonus.c ]

void	ft_check_valid_char(t_game *game);
void	ft_check_sealed(t_game *game);
void	ft_check_rectangular(t_game *game);
void	ft_check_playability(t_game *game);

//============ [ ft_debug_utils_one.c ]

void	ft_display_sprites_addr(t_game *game);
void	ft_print_game_info(t_game *game);

//============ [ ft_display_assets_bonus.c ]

void	ft_put_sprites_by_line(t_game *game);
void	ft_put_all_sprites_to_line(t_game *game, int width, int height, \
			t_point sprite_position);
void ft_handle_borders_sprites(t_game *game, char tile, t_point sprite_position);
void ft_handle_other_borders_sprites(t_game *game, char tile, t_point sprite_position);
void ft_handle_key_love_box_sprites(t_game *game, char tile, t_point sprite_position);

//============ [ ft_display_assets_borders_bonus.c ]

void	ft_grass_sprite(t_game *game, t_point position);
void	ft_tree_sprite(t_game *game, t_point position);
void	ft_trees_sprite(t_game *game, t_point position);
void	ft_reed_sprite(t_game *game, t_point position);
void	ft_pillar_sprite(t_game *game, t_point position);

//============ [ ft_display_assets_borders_one_bonus.c ]

void	ft_husks_sprite(t_game *game, t_point position);
void	ft_fungus_sprite(t_game *game, t_point position);
void	ft_fungi_sprite(t_game *game, t_point position);
void	ft_flower_sprite(t_game *game, t_point position);
void	ft_algae_sprite(t_game *game, t_point position);

//============ [ ft_display_assets_borders_tree_bonus.c ]

void	ft_hedge_sprite(t_game *game, t_point position);

//============ [ ft_display_assets_borders_two_bonus.c ]

void	ft_water_sprite(t_game *game, t_point position);
void	ft_crab_sprite(t_game *game, t_point position);
void	ft_foliage_sprite(t_game *game, t_point position);
void	ft_bog_sprite(t_game *game, t_point position);
void	ft_snail_sprite(t_game *game, t_point position);

//============ [ ft_display_assets_enemies_bonus.c ]

void	ft_lava_sprite(t_game *game, t_point position);
void	ft_pawn_sprite(t_game *game, t_point position);

//============ [ ft_display_assets_gameplay_bonus.c ]

void	ft_key_sprite(t_game *game, t_point position);
void	ft_exit_sprite(t_game *game, t_point position);
void	ft_box_sprite(t_game *game, t_point position);
void	ft_portal_z_sprite(t_game *game, t_point position);
void	ft_portal_n_sprite(t_game *game, t_point position);

//============ [ ft_display_assets_gameplay_one_bonus.c ]

void	ft_love_sprite(t_game *game, t_point position);
void	ft_ground_sprite(t_game *game, t_point position);
void	ft_wall_sprite(t_game *game, t_point position);

//============ [ ft_display_assets_one_bonus.c ]

void ft_handle_exit_portals_sprites(t_game *game, char tile, t_point sprite_position);
void ft_handle_enemies_sprites(t_game *game, char tile, t_point sprite_position);

//============ [ ft_display_assets_player_bonus.c ]

void	ft_player_sprite_call(t_game *game, int width, int height, \
		t_point sprite_position);
void	ft_player_down_sprite(t_game *game, int draw_x, int draw_y);
void	ft_player_up_sprite(t_game *game, int draw_x, int draw_y);
void	ft_player_left_sprite(t_game *game, int draw_x, int draw_y);
void	ft_player_right_sprite(t_game *game, int draw_x, int draw_y);

//============ [ ft_display_assets_utils_bonus.c ]

t_bool ft_is_key_love_box_sprites(char tile);
t_bool ft_is_exit_portals_sprites(char tile);
t_bool ft_is_enemies_sprites(char tile);
t_bool ft_is_borders_sprites(char tile);
t_bool ft_is_other_borders_sprites(char tile);

//============ [ ft_display_assets_utils_one_bonus.c ]

void	ft_put_sprite(t_game *game, void *sprite, t_point position);

//============ [ ft_display_assets_wall_bit_mask_bonus.c ]
//============ [ ft_display_assets_wall_simple_bonus.c ]
//============ [ ft_display_keke_assets_bonus.c ]

void	ft_keke_sprites(t_game *game, int width, int height, \
		t_point sprite_position);
void	ft_keke_down_sprite(t_game *game, int draw_x, int draw_y);
void	ft_keke_up_sprite(t_game *game, int draw_x, int draw_y);
void	ft_keke_left_sprite(t_game *game, int draw_x, int draw_y);
void	ft_keke_right_sprite(t_game *game, int draw_x, int draw_y);

//============ [ ft_free_a_star_utils_bonus.c ]

void ft_free_a_star_lists_nodes_elements(t_a_star_node **list, int count);

void ft_free_a_star_lists_nodes(t_a_star_node **open_list,
	int open_count, t_a_star_node **closed_list, int closed_count);

//============ [ ft_free_bonus.c ]

int		ft_exit_game(t_game *game);
int		ft_win_game(t_game *game);
int		ft_lose_game(t_game *game);
void	ft_free_all(t_game *game);
void	ft_free_mlx(t_game *game);

//============ [ ft_free_parsing_bonus.c ]

void	ft_clean_fail_malloc_split_map(t_game *game, char **grid, int row);
void	ft_clean_grid_map(char **grid, int row);

//============ [ ft_free_utils_bonus.c ]

void	ft_free_pawns_array(t_game *game);
void	ft_free_sprites_list(t_sprite_node **head, void *mlx);
void	ft_free_step_and_storage(t_game *game);

//============ [ ft_keke_a_star_bonus.c ]

void ft_check_neighbor_node(t_game *game, t_a_star_node *current, t_point pos);
void ft_explore_neighbors_node(t_game *game, t_a_star_node *current);
void ft_process_a_star_node(t_game *game);

//============ [ ft_keke_a_star_one_utils_bonus.c ]

t_bool ft_check_if_point_is_in_list(t_a_star_node **list, \
	int count, t_point pos);
int ft_node_is_valid_neighbor(t_game *game, int x, int y);
void ft_check_if_current_node_is_player_position(t_game *game, \
	t_a_star_node *current);

//============ [ ft_keke_a_star_utils_bonus.c ]

t_point ft_get_neighbor_position(t_game *game, t_a_star_node *current, \
	int index);
t_bool ft_node_is_valid_and_not_in_closed(t_game *game, t_point pos);
int ft_is_keke_walkable_point(char **grid, int x, int y);

//============ [ ft_keke_behaviour_bonus.c ]

void	ft_direction_keke_after_launch(t_game *game);
int	ft_is_keke_obstacle(char tile);

//============ [ ft_keke_behaviour_utils_bonus.c ]

void	ft_keke_move_up(t_game *game);
void	ft_keke_move_down(t_game *game);
void	ft_keke_move_left(t_game *game);
void	ft_keke_move_right(t_game *game);

//============ [ ft_keke_event_bonus.c ]

void ft_a_star_keke_movement(t_game *game);
void ft_add_to_open_list(t_a_star_node **open_list, int *open_count, \
	t_a_star_node *new_node);
void ft_sort_open_list(t_a_star_node **open_list, int open_count);
void ft_find_keke_direction(t_game *game, t_a_star_node *current, t_point start);
void ft_remove_from_open_list(t_a_star_node **open_list, int *open_count);

//============ [ ft_keke_movement.c ]


void	ft_move_keke(t_game *game);
void	ft_move_keke_up(t_game *game, int row, int col);
void	ft_move_keke_down(t_game *game, int row, int col);
void	ft_move_keke_left(t_game *game, int row, int col);
void	ft_move_keke_right(t_game *game, int row, int col);

//============ [ file.c ]
//============ [ ft_pawn_patrolling_utils_bonus.c ]

int	ft_is_pawn_position_valid(t_game *game, t_point pos, t_pawn_movement *pawn);
int ft_is_position_free_for_pawn(char **grid, t_point pos);
int	ft_is_pawn_obstacle(char **grid, t_point pos);
t_bool ft_is_position_within_bounds_for_pawn(t_point pos, t_point size);
t_bool ft_pawn_can_move_to_position(t_game *game, t_point pos);

//============ [ ft_pawn_patrolling_utils_one_bonus.c ]

t_point ft_calculate_farthest_position(t_point start_position, \
	const char *direction, t_game *game);
size_t ft_calculate_steps(t_point start, t_point end, const char *direction);
t_point ft_get_pawn_next_position(t_point current, const char *direction);
t_point	ft_get_pawn_direction_delta(const char *direction);
void ft_find_best_direction_for_pawn(t_game *game, t_pawn_movement *pawn);


//============ [ ft_pawn_patrolling_utils_two_bonus.c ]

void ft_update_pawn_target(t_pawn_movement *pawn, t_point best_position, \
	const char *best_dir, size_t max_steps);
void	ft_find_farthest_position_for_pawn(t_game *game);
void ft_update_pawn_best_direction(t_pawn_movement *pawn, \
	t_direction_evaluation *eval);
void ft_evaluate_pawn_direction(t_game *game, t_pawn_movement *pawn, \
	const char *direction, t_direction_evaluation *eval);
void	ft_find_pawn_positions(t_game *game);

//============ [ ft_pawn_patrolling_utils_two_bonus.c ]

void	ft_check_valid_map_for_pawn_positions(t_game *game);
void	ft_check_row_for_pawn_positions(char *row, t_game *game);
void	ft_update_pawn_grid(t_game *game, t_point old_position, t_point new_position);


//============ [ ft_pawn_patrolling.c ]

void	ft_move_pawn(t_game *game);
t_bool ft_handle_pawn_collision(t_game *game, \
	t_pawn_movement *pawn, t_point next_pos);
void	ft_handle_pawn_returning(t_game *game, t_pawn_movement *pawn);
void	ft_handle_pawn_movement(t_game *game, t_pawn_movement *pawn);
const char	*ft_get_pawn_reverse_direction(const char *direction);

//============ [ file.c ]

void	ft_dir_player_by_pos_exit_after_launch(t_game *game);
void	ft_move_box(t_game *game, t_point new_pos, int dir_y, int dir_x);
void	ft_teleport_player(t_game *game, int y, int x);

//============ [ file.c ]

void	ft_play_movement_sound(t_game *game);
void	ft_player_take_coin(t_game *game);
void	ft_player_take_life(t_game *game);
void	ft_player_get_hit(t_game *game);
void	ft_baba_forbidden(t_game *game);
void	ft_pawn_movement(t_game *game);

//============ [ file.c ]

void	ft_print_info_on_window(t_game *game);
void	ft_display_digits_sprites(t_game *game, char *digits_str, \
			t_point position);
void	ft_display_life_on_windows(t_game *game);

//============ [ ft_init_a_star_bonus.c ]

t_a_star_node *ft_init_keke_start_node(t_point start, t_point goal);
t_a_star_node *ft_init_create_neighbor_node(t_game *game,
	t_a_star_node *current, t_point pos);
void	ft_init_neighbor_data(t_game *game, t_point goal);
void ft_init_a_star_lists(t_game *game);
void ft_init_a_star_data(t_game *game, t_point *start, \
	t_point *goal, t_a_star_node **start_node);

void	ft_init_camera(t_game *game);
void	ft_init_hud_sprites_position(t_game *game);
void	ft_init_frames(t_game *game);
void	ft_init_fps(t_game *game);
void	ft_init_map_info(t_game *game, char *line);
void	ft_init_game_info(t_game *game);
void	ft_init_pawns_array(t_game *game);


//============ [ ft_init_hud_bonus.c ]

void	init_even_letter_images(t_game *game, void **letter_images);
void	init_odd_letter_images(t_game *game, void **letter_images);

//============ [ file.c ]

void	ft_setup_map(t_game *game);
void	ft_get_info_map(t_game *game);
void	ft_play_random_theme(void);

//============ [ ft_init_mlx_bonus.c ]

void	ft_init_mlx(t_game *game);
void	ft_create_window(t_game *game);

//============ [ ft_init_pawn_bonus.c ]

void	ft_init_pawns_array(t_game *game);
void	ft_initialize_pawn(t_game *game, long long int index, int x, int y);

//============ [ file.c ]

void	ft_init_game(t_game *game, char *map_name);
void	ft_init_player_info(t_game *game);
void	ft_init_map_info(t_game *game, char *line);
void	ft_init_keke_info(t_game *game);

//============ [ file.c ]

int		ft_input_manager(int key_code, t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);

//============ [ file.c ]

void	ft_handle_tile_action(t_game *game, char next_tile);
void	ft_input_up(t_game *game);
void	ft_input_down(t_game *game);
void	ft_input_left(t_game *game);
void	ft_input_right(t_game *game);

//============ [ file.c ]

void	ft_load_sprites(t_game *game);
void	ft_add_sprite_to_list(t_sprite_node **head, void *frame);
void	ft_load_sprite_frame(void **frame, t_game *game, const char *path, \
			const char *error_message);
void	ft_load_animation_sprites(t_animation *animation, t_game *game,
			const char **paths, const char **error_messages);

//============ [ file.c ]

void	ft_load_digits_sprites(t_game *game);
void	ft_load_digit_tab(t_game *game);

//============ [ file.c ]

void	ft_load_door_closed_sprites(t_game *game);
void	ft_load_door_open_sprites(t_game *game);

//============ [ file.c ]

void	ft_load_digit_zero(t_game *game);
void	ft_load_digit_two(t_game *game);
void	ft_load_digit_four(t_game *game);
void	ft_load_digit_six(t_game *game);
void	ft_load_digit_eight(t_game *game);

//============ [ file.c ]

void	ft_load_lava_sprites(t_game *game);
void	ft_load_key_sprites(t_game *game);
void	ft_load_love_sprites(t_game *game);
void	ft_load_box_sprites(t_game *game);

//============ [ file.c ]

void	ft_load_portal_z_sprites(t_game *game);
void	ft_load_portal_n_sprites(t_game *game);
void	ft_load_digit_one(t_game *game);
void	ft_load_digit_tree(t_game *game);
void	ft_load_digit_five(t_game *game);
void	ft_load_digit_seven(t_game *game);
void	ft_load_digit_nine(t_game *game);

//============ [ file.c ]

void	ft_load_player_up_sprites(t_game *game);
void	ft_load_player_down_sprites(t_game *game);
void	ft_load_player_left_sprites(t_game *game);
void	ft_load_player_right_sprites(t_game *game);
void	ft_load_player_current(t_game *game);

//============ [ file.c ]

void	ft_load_keke_up_sprites(t_game *game);
void	ft_load_keke_down_sprites(t_game *game);
void	ft_load_keke_left_sprites(t_game *game);
void	ft_load_keke_right_sprites(t_game *game);
void	ft_load_keke_current(t_game *game);

//============ [ file.c ]

void	ft_load_ground_sprites(t_game *game);
void	ft_load_grass_sprites(t_game *game);
void	ft_load_wall_sprites(t_game *game);
void	ft_load_pawn_sprites(t_game *game);

//============ [ file.c ]

float	ft_linear_interpolation(float interpolation_factor, float start, \
		float end);
double	ft_sin(double x);
double	ft_fmod(double x, double y);
int ft_absolute_value(int value);
int ft_manhattan_heuristic_distance(t_point a, t_point b);

//============ [ file.c ]

int ft_is_same_point(t_point a, t_point b);

//============ [ file.c ]

void	ft_mlx_hook_loop(t_game *game);

//============ [ file.c ]

void	ft_read_map(t_game *game, char *map_name);

int		ft_get_map_height(char *map_name, t_game *game);

void	ft_check_ber_format(char *map_name, int height, t_game *game);

//============ [ file.c ]

char	**ft_allocate_new_map(int new_height, int new_width, t_game *game);
void	ft_fill_map_row(char **new_map, int row, t_game *game, int new_width);
char	**ft_create_map_with_border(t_game *game);

//============ [ file.c ]

char	*ft_custom_strdup(char *s1);
int		ft_custom_strlcpy(char *dst, char *src, int dst_size);
char	*ft_custom_strjoin(char *s1, char *s2);

//============ [ file.c ]
void	ft_check_map_finishable(t_game *game);
void ft_flood_fill(char **tab, t_game *game, t_point start);
char	**ft_split_map(t_game *game);
t_point	ft_find_pos_char(char **tab, t_point size, char c);

//============ [ file.c ]

float	ft_perlin_noise(float x, float y);
void	ft_calculate_relatives_positions(t_perlin_vars *vars, float x, float y);
void	ft_calculate_fades_values(t_perlin_vars *vars);
void	ft_calculate_permutation_indices(t_perlin_vars *vars, int *perm);
void	ft_calculate_gradients(t_perlin_vars *vars, int *perm);
void	ft_calculate_interpolation_x(t_perlin_vars *vars);
char	ft_determine_fill_char(float noise_value);
float	ft_fade(float relative_position_fade_factor);
int		ft_floor(float value);
float	ft_gradient(int hash, float x, float y);

//============ [ file.c ]

void	ft_print_error(char *error_msg, t_game *game);
void	ft_print_no_arg(void);
void	ft_free_and_print(char **map, t_game *game, char *str);
void	ft_print_error_empty_and_free(char *error_msg, t_game *game);

//============ [ file.c ]

void	ft_print_fill_grid(char **map);
void	ft_print_display_grid(char **res);
void	ft_display_position(t_point start, t_point end, t_point z, t_point n);
void	ft_print_map_info(t_game *game);
void	ft_print_initial_positions(t_game *game);

//============ [ ft_print_console_one_bonus.c ]

void	ft_print_pawn_info(int index, t_pawn_movement *pawn);

//============ [ ft_print_game_state_bonus.c ]

void	ft_ascii_exit(void);
void	ft_ascii_win(t_game *game);
void	ft_ascii_loose(t_game *game);

//============ [ file.c ]

int		ft_update(t_game *game);
void	ft_update_fps(t_game *game);
void	ft_update_map_matrice(t_game *game);
void	ft_update_player_position(t_game *game);
void	ft_update_map_positions(t_game *game);

//============ [ file.c ]

#endif // !FT_SO_LONG_FUNCTIONS_BONUS_H
