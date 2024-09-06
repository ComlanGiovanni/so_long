/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_structs_bonus.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:28:13 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:44:13 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_STRUCTS_BONUS_H
# define FT_SO_LONG_STRUCTS_BONUS_H

struct						s_point
{
	int						x;
	int						y;
};

//fps management bad you have a time struct separate don't know how yet
struct						s_fps
{
	struct timespec			last_time;
	struct timespec			current_time;
	int						frame_count;
	double					fps;
	double					elapsed;
	double					elapsed_time;
};

struct						s_animation
{
	int						frames;
	void					*current;
	void					*frame_0;
	void					*frame_1;
	void					*frame_2;
};

struct						s_lava
{
	t_animation				animation;
	char					move;
};

struct						s_key
{
	t_animation				animation;
};

struct						s_grass
{
	t_animation				animation;
};

struct						s_wall
{
	t_animation				east;
	t_animation				south;
	t_animation				no_neighbors_four_direction;
	t_animation				south_plus_east;
	t_animation				north;
	t_animation				south_plus_west;
	t_animation				north_plus_east;
	t_animation				south_plus_west_plus_east;
	t_animation				north_plus_south;
	t_animation				north_plus_south_plus_east;
	t_animation				north_plus_south_plus_west;
	t_animation				north_plus_south_plus_west_plus_east;
	t_animation				west;
	t_animation				north_plus_west_plus_east;
	t_animation				west_plus_east;
	t_animation				north_west;
};

struct						s_water
{
	t_animation				animation;
};

struct						s_pawn_movement
{
	t_point					initial_position;
	t_point					current_position;
	t_point					target_position;
	char					*direction;
	t_bool					is_returning;
	t_bool					is_active;
	t_bool					is_available;
	int						steps_taken;
	int						steps_need;
};

struct						s_direction_map
{
	const char				*name;
	t_point					delta;
};

struct						s_direction_evaluation
{
	size_t					max_steps;
	t_point					best_position;
	const char				*best_dir;
};

struct						s_pawn
{
	t_animation				animation;
	t_pawn_movement			*pawns_array;
};

struct						s_anim_door
{
	int						frames;
	void					*current;
	void					*frame_0;
	void					*frame_1;
	void					*frame_2;
};

struct						s_door
{
	t_anim_door				closed;
	t_anim_door				open;
};

struct						s_love_icon
{
	t_animation				animation;
};

//void					*icon;
struct						s_love
{
	t_animation				animation;
	void					*nope;
	t_love_icon				icon;
};

struct s_menu_state
{
	int						num_buttons;
	void					(*button_actions[0x4])(t_game *);
};

struct						s_anim_player
{
	void					*current;
	void					*frame_0;
	void					*frame_1;
	void					*frame_2;
	void					*frame_move;
};

struct						s_movement
{
	t_point					current_position;
	t_point					target_position;
	t_bool					moved;
	char					direction;
};

struct						s_player
{
	t_anim_player			up_anim;
	t_anim_player			down_anim;
	t_anim_player			left_anim;
	t_anim_player			right_anim;
	t_movement				movement;
	int						frames;
	long long int			life;
	long long int			storage;
	long long int			step;
};

struct						s_info
{
	long long int			nbr_key;
	long long int			nbr_exit;
	long long int			nbr_player;
	long long int			nbr_lava;
	long long int			nbr_love;
	long long int			nbr_wall;
	long long int			nbr_pawn;
	long long int			nbr_void;
	long long int			nbr_box;
	long long int			nbr_grass;
	long long int			nbr_monster;
	long long int			nbr_portal_1;
	long long int			nbr_portal_2;
};

struct						s_img_size
{
	int						width;
	int						height;
};

struct						s_img
{
	char					*data;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
};

struct						s_map
{
	t_point					size;
	t_point					start;
	t_point					end;
	t_point					portal_1_pos;
	t_point					portal_2_pos;
	t_info					info;
	char					*map_name;
	char					*map_str;
	char					**matrice;
	char					**grid;
	char					**original;
	void					*ground;
	long long int			len;
	long long int			border_width;
};

struct						s_uv_params
{
	int						hash;
	float					x;
	float					y;
	float					*fade_x;
	float					*fade_y;
};

struct						s_perlin_vars
{
	int						grid_position_x;
	int						grid_position_y;
	float					relative_position_x;
	float					relative_position_y;
	float					fade_x;
	float					fade_y;
	int						permutation_index_lower_left;
	int						permutation_index_upper_left;
	float					gradient_lower_left;
	float					gradient_lower_right;
	float					gradient_upper_left;
	float					gradient_upper_right;
	float					interpolation_x_lower;
	float					interpolation_x_upper;
};

struct						s_window
{
	int						bpp;
	int						size_line;
	int						endian;
	void					*img;
	char					*img_data;
	int						width;
	int						height;
};

struct						s_digits
{
	t_animation				zero;
	t_animation				one;
	t_animation				two;
	t_animation				three;
	t_animation				four;
	t_animation				five;
	t_animation				six;
	t_animation				seven;
	t_animation				eight;
	t_animation				nine;
};

struct						s_alphabet
{
	t_animation				a;
	t_animation				b;
	t_animation				c;
	t_animation				d;
	t_animation				e;
	t_animation				f;
	t_animation				g;
	t_animation				h;
	t_animation				i;
	t_animation				j;
	t_animation				k;
	t_animation				l;
	t_animation				m;
	t_animation				n;
	t_animation				o;
	t_animation				p;
	t_animation				q;
	t_animation				r;
	t_animation				s;
	t_animation				t;
	t_animation				u;
	t_animation				v;
	t_animation				w;
	t_animation				x;
	t_animation				y;
	t_animation				z;
};

struct						s_hud_position
{
	t_point					fps;
	t_point					step;
	t_point					direction;
	t_point					keys;
	t_point					storage;
	t_point					pause;
};

struct						s_hud
{
	char					*str_step;
	char					*str_storage;
	char					*str_fps;
	char					*str_key_remain;
	t_digits				digits;
	t_alphabet				alphabet;
	t_hud_position			position;
};

struct						s_camera
{
	t_point					current;
	t_point					target;
	double					shake_intensity;
	double					shake_speed;
	double					lerp_speed;
};

struct						s_sprite_node
{
	void					*frame;
	struct s_sprite_node	*next;
};

struct						s_line_error_data
{
	int						curr_height;
	int						height;
	int						fd;
	t_game					*game;
};

struct						s_box
{
	t_animation				animation;
};

struct						s_portal
{
	t_animation				z;
	t_animation				n;
};

struct						s_anim_monster
{
	void					*current;
	void					*frame_0;
	void					*frame_1;
	void					*frame_2;
	void					*frame_move_0;
	void					*frame_move_1;
};

struct						s_a_star_node
{
	t_point					pos;
	int						cost_from_start;
	int						total_cost;
	struct s_a_star_node	*parent;
};
struct						s_lists
{
	t_a_star_node			**open;
	t_a_star_node			**closed;
	int						open_count;
	int						closed_count;
};

struct				s_button_info
{
	t_button				*button;
	void					(*action)(t_game *);
};

struct						s_neighbor
{
	t_point					goal;
	t_point					directions[FANTASTIC];
	char					dir_char[FANTASTIC];
};

struct						s_a_star
{
	t_lists					lists;
	t_neighbor				neighbor;
};

struct						s_monster
{
	t_anim_monster			up_anim;
	t_anim_monster			down_anim;
	t_anim_monster			left_anim;
	t_anim_monster			right_anim;
	t_bool					moved;
	t_a_star				a_star;
	int						frames;
	char					direction;
	long long int			step;
};

struct						s_tree
{
	t_animation				animation;
};

struct						s_trees
{
	t_animation				animation;
};

struct						s_reed
{
	t_animation				animation;
};

struct						s_husks
{
	t_animation				animation;
};

struct						s_fungus
{
	t_animation				animation;
};

struct						s_fungi
{
	t_animation				animation;
};

struct						s_flower
{
	t_animation				animation;
};

struct						s_algae
{
	t_animation				animation;
};

struct						s_crab
{
	t_animation				animation;
};

struct						s_foliage
{
	t_animation				animation;
};

struct						s_bog
{
	t_animation				animation;
};

struct						s_snail
{
	t_animation				animation;
};

struct						s_pillar
{
	t_animation				animation;
};

struct						s_hedge
{
	t_animation				animation;
};

struct						s_flood_fill_data
{
	t_bool					exit_found;
	int						coins;
};

struct						s_mouse
{
	t_point					mouse_position;
	char					*button_name;
	int						mouse_button_key_code;
};

struct						s_fill_char_state
{
	const char				*selected_fill_chars;
	int						selected_fill_chars_size;
};

struct						s_button
{
	void		*img_normal;
	void		*img_hover;
	void		*img_clicked;
	t_point		position;
	int			width;
	int			height;
	int			is_hovered;
};

//int			last_input_type;
struct						s_menu
{
	t_button	start_button;
	t_button	resume_button;
	t_button	restart_button;
	t_button	levels_button;
	t_button	main_menu_button;
	t_button	quit_button;
	void		*game_welcome;
	void		*game_win;
	void		*game_over;
	int			selected_button;
};

//can put all in a different struct like
//t_border border
struct						s_game
{
	t_menu					menu;
	t_mouse					mouse;
	t_game_state			state;
	t_bool					paused;
	t_bool					key_collected;
	t_flood_fill_data		flood_fill;
	t_player				player;
	t_love					love;
	t_map					map;
	t_lava					lava;
	t_key					key;
	t_wall					wall;
	t_pawn					pawn;
	t_water					water;
	t_grass					grass;
	t_tree					tree;
	t_trees					trees;
	t_reed					reed;
	t_husks					husks;
	t_fungus				fungus;
	t_fungi					fungi;
	t_flower				flower;
	t_algae					algae;
	t_crab					crab;
	t_foliage				foliage;
	t_bog					bog;
	t_snail					snail;
	t_pillar				pillar;
	t_hedge					hedge;
	t_door					door;
	t_box					box;
	t_portal				portal;
	t_camera				camera;
	t_sprite_node			*node;
	t_point					screen;
	t_monster				monster;
	t_fps					fps;
	t_window				window;
	t_hud					hud;
	void					*mlx;
	void					*win;
	long long int			width;
	long long int			height;
	long long int			empty_line;
};

#endif // !FT_SO_LONG_STRUCTS_BONUS_H
