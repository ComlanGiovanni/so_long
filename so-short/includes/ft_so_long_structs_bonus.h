/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_structs_bonus.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:28:13 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/15 16:32:39 by gicomlan         ###   ########.fr       */
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
	t_animation				animation;
};

struct						s_water
{
	t_animation				animation;
};

struct s_pawn_movement
{
	t_point initial_position;
	t_point current_position;
	t_point target_position;
	//char	dir_char[4];
	char	*direction;
	//t_point *path;
	t_bool		is_returning;
	t_bool 	is_active;
	t_bool 	is_available;
	int		steps_taken;
	int		steps_need;
};

struct s_direction_map
{
	const char	*name;
	t_point		delta;
};

struct s_direction_evaluation
{
	size_t		max_steps;
	t_point		best_position;
	const char	*best_dir;
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
	//int				frames;
	t_anim_door				closed;
	t_anim_door				open;
};

struct						s_love
{
	t_animation				animation;
	void					*nope;
	void					*icon;
};

struct						s_anim_player
{
	void					*current;
	void					*frame_0;
	void					*frame_1;
	void					*frame_2;
	void					*frame_move;
};

// typedef struct s_point_visual
// {
// 	float x;
//     float y;
// } t_point_visual;

struct						s_movement
{
	//t_point_visual	visual;
	t_point					current_position;
	t_point					target_position;
	t_bool					moved;
	char					direction;
	//float			speed;
};

struct						s_player
{
	t_anim_player			up_anim;
	t_anim_player			down_anim;
	t_anim_player			left_anim;
	t_anim_player			right_anim;
	//t_point			position;
	t_movement				movement;
	// t_point			target_position;
	// float			speed;
	//t_movement	movement
	//t_bool			moved;
	int						frames;
	long long int			life;
	long long int			storage;
	long long int			step;
	//char			direction;
	// double			x_speed;
	// double			y_speed;
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
	long long int			nbr_keke;
	long long int			nbr_portal_1;
	long long int			nbr_portal_2;
};

struct s_img_size
{
	int		width;
	int		height;
};

struct s_img
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
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
	void					*ground;
	//void			*grass;
	//void			*borders;
	long long int			len;
	// long long int	nbr_key;
	// long long int	nbr_exit;
	// long long int	nbr_player;
	// long long int	nbr_lava;
	// long long int	nbr_love;
	// long long int	nbr_wall;
	// long long int	nbr_void;
	long long int			border_width;
};

struct s_uv_params
{
	int			hash;
	float		x;
	float		y;
	float		*fade_x;
	float		*fade_y;
};

struct s_perlin_vars
{
	int			grid_position_x;
	int			grid_position_y;
	float		relative_position_x;
	float		relative_position_y;
	float		fade_x;
	float		fade_y;
	int			permutation_index_lower_left;
	int			permutation_index_upper_left;
	float		gradient_lower_left;
	float		gradient_lower_right;
	float		gradient_upper_left;
	float		gradient_upper_right;
	float		interpolation_x_lower;
	float		interpolation_x_upper;
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
	//void					*tab[10];
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
	void					*tab[26];
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

struct						s_hud
{
	char					*str_step;
	char					*str_storage;
	char					*str_fps;
	char					*str_key_remain;
	//int				frame;
	t_digits				digits;
	t_alphabet				alphabet;
	t_point					fps;
	t_point					step;
	t_point					direction;
	t_point					keys;
	t_point					storage;
};

struct						s_camera
{
	t_point current; // faire une struct camera
	t_point					target;
	double					shake_intensity;
	double					shake_speed;
	double					lerp_speed;
	double					angle;
	//float			zoom_factor;
};

struct						s_sprite_node
{
	void					*frame;
	struct s_sprite_node	*next;
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

struct						s_anim_keke
{
	void					*current;
	void					*frame_0;
	void					*frame_1;
	void					*frame_2;
	void					*frame_move_0;
	void					*frame_move_1;
};


struct s_a_star_node
{
	t_point							pos;
	int								cost_from_start; // Cost from start to this node
	int								total_cost; // Total cost (g + h)
	struct s_a_star_node			*parent;
};
struct s_lists
{
	t_a_star_node		**open;
	t_a_star_node		**closed;
	int 			open_count;
	int				closed_count;
};

struct s_neighbor
{
	t_point		goal;
	t_point		directions[4];
	char		dir_char[4];
};

struct s_a_star
{
	t_lists					lists;
    t_neighbor				neighbor;
};

struct						s_keke
{
	t_anim_keke				up_anim;
	t_anim_keke				down_anim;
	t_anim_keke				left_anim;
	t_anim_keke				right_anim;
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


typedef struct s_flood_fill_data {
    t_bool exit_found;
    int coins;
} t_flood_fill_data;

//can put all in a different struct like
//t_border border
struct						s_game
{
	t_game_state 			state;
	t_bool					paused;//state replaced
	t_bool					key_collected;
	t_flood_fill_data		flood_fill;
	t_player				player;
	t_love					love;
	t_map					map;
	t_lava					lava;
	t_key					key;
	t_wall					wall;
	t_pawn					pawn;
	//t_border				border
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
	//t_border				border
	t_door					door;
	t_box					box;
	t_portal				portal;
	t_camera				camera;
	t_sprite_node			*node;
	t_point					screen;
	t_keke					keke;
	t_fps					fps;
	t_window				window;
	t_hud					hud;
	void					*mlx;
	void					*win;
	//void			*img;
	//char			*img_data;
	// char			*str_step;
	// char			*str_storage;
	// char			*str_fps;
	// float 			distance_camera;
	// float			zoom_factor;
	// double			last_time;
	long long int width;
	long long int height;
	long long int empty_line; //mettre dans map information
};

#endif // !FT_SO_LONG_STRUCTS_BONUS_H
