/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:10:08 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/13 21:13:28 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_player_sprites(t_game *game)
{
	ft_load_player_up_sprites(game);
	ft_load_player_down_sprites(game);
	ft_load_player_left_sprites(game);
	ft_load_player_right_sprites(game);
	ft_load_player_current(game);
}

void	ft_load_keke_sprites(t_game *game)
{
	ft_load_keke_up_sprites(game);
	ft_load_keke_down_sprites(game);
	ft_load_keke_left_sprites(game);
	ft_load_keke_right_sprites(game);
	ft_load_keke_current(game);
}

void	ft_load_gameplay_sprites(t_game *game)
{
	ft_load_love_sprites(game);
	ft_load_key_sprites(game);
	ft_load_portal_n_sprites(game);
	ft_load_portal_z_sprites(game);
	ft_load_door_closed_sprites(game);
	ft_load_door_open_sprites(game);
}

void	ft_load_enemies_sprites(t_game *game)
{
	ft_load_lava_sprites(game);
	ft_load_pawn_sprites(game);
}

void	ft_load_tree_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"tree/tree_frame_0.xpm",
		PATH_ASSET"tree/tree_frame_1.xpm",
		PATH_ASSET"tree/tree_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic messaqge change soon",
		"Generic messagwe change soon",
		"Generic messaege change soon"};

	ft_load_animation_sprites(&(game->tree.animation), game, paths,
		error_messages);
}

void	ft_load_trees_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"trees/trees_frame_0.xpm",
		PATH_ASSET"trees/trees_frame_1.xpm",
		PATH_ASSET"trees/trees_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic messgage change soon",
		"Generic messarge change soon",
		"Generic messagye change soon"};

	ft_load_animation_sprites(&(game->trees.animation), game, paths,
		error_messages);
}

void	ft_load_reed_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"reed/reed_frame_0.xpm",
		PATH_ASSET"reed/reed_frame_1.xpm",
		PATH_ASSET"reed/reed_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic messauge change soon",
		"Generic meossage change soon",
		"Generic mepssage change soon"};

	ft_load_animation_sprites(&(game->reed.animation), game, paths,
		error_messages);
}

void	ft_load_husks_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"husks/husks_frame_0.xpm",
		PATH_ASSET"husks/husks_frame_1.xpm",
		PATH_ASSET"husks/husks_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message changbbe soon",
		"Generic message cbbhange soon",
		"Generic messaffge change soon"};

	ft_load_animation_sprites(&(game->husks.animation), game, paths,
		error_messages);
}

void	ft_load_fungus_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"fungus/fungus_frame_0.xpm",
		PATH_ASSET"fungus/fungus_frame_1.xpm",
		PATH_ASSET"fungus/fungus_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic messxxage change soon",
		"Generic messxxage change soon",
		"Generic messaxxge change soon"};

	ft_load_animation_sprites(&(game->fungus.animation), game, paths,
		error_messages);
}

void	ft_load_fungi_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"fungi/fungi_frame_0.xpm",
		PATH_ASSET"fungi/fungi_frame_1.xpm",
		PATH_ASSET"fungi/fungi_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic messagwwe change soon",
		"Generic message change soon",
		"Generic message change soon"};

	ft_load_animation_sprites(&(game->fungi.animation), game, paths,
		error_messages);
}

void	ft_load_flower_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"flower/flower_frame_0.xpm",
		PATH_ASSET"flower/flower_frame_1.xpm",
		PATH_ASSET"flower/flower_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message caahange soon",
		"Generic message cddhange soon",
		"Generic message cdfdfhange soon"};

	ft_load_animation_sprites(&(game->flower.animation), game, paths,
		error_messages);
}

void	ft_load_algae_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"algae/algae_frame_0.xpm",
		PATH_ASSET"algae/algae_frame_1.xpm",
		PATH_ASSET"algae/algae_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic messayuyiyge change soon",
		"Generic messiyiyiage change soon",
		"Generic messayiyge change soon"};

	ft_load_animation_sprites(&(game->algae.animation), game, paths,
		error_messages);
}

void	ft_load_water_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"water/water_frame_0.xpm",
		PATH_ASSET"water/water_frame_1.xpm",
		PATH_ASSET"water/water_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic messayuyiyge change soon",
		"Generic messiyiyiage change soon",
		"Generic messayiyge change soon"};

	ft_load_animation_sprites(&(game->water.animation), game, paths,
		error_messages);
}

void	ft_load_crab_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"crab/crab_frame_0.xpm",
		PATH_ASSET"crab/crab_frame_1.xpm",
		PATH_ASSET"crab/crab_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message be clean please",
		"Generic message be clean please",
		"Generic message be clean please"};

	ft_load_animation_sprites(&(game->crab.animation), game, paths,
		error_messages);
}

void	ft_load_foliage_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"foliage/foliage_frame_0.xpm",
		PATH_ASSET"foliage/foliage_frame_1.xpm",
		PATH_ASSET"foliage/foliage_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message be clean please",
		"Generic message be clean please",
		"Generic message be clean please"};

	ft_load_animation_sprites(&(game->foliage.animation), game, paths,
		error_messages);
}

void	ft_load_bog_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"bog/bog_frame_0.xpm",
		PATH_ASSET"bog/bog_frame_1.xpm",
		PATH_ASSET"bog/bog_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message be clean please",
		"Generic message be clean please",
		"Generic message be clean please"};

	ft_load_animation_sprites(&(game->bog.animation), game, paths,
		error_messages);
}

void	ft_load_snail_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"snail/snail_frame_0.xpm",
		PATH_ASSET"snail/snail_frame_1.xpm",
		PATH_ASSET"snail/snail_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message be clean please",
		"Generic message be clean please",
		"Generic message be clean please"};

	ft_load_animation_sprites(&(game->snail.animation), game, paths,
		error_messages);
}

void	ft_load_pillar_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"pillar/pillar_frame_0.xpm",
		PATH_ASSET"pillar/pillar_frame_1.xpm",
		PATH_ASSET"pillar/pillar_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message be clean please",
		"Generic message be clean please",
		"Generic message be clean please"};

	ft_load_animation_sprites(&(game->pillar.animation), game, paths,
		error_messages);
}

void	ft_load_hedge_sprites(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"hedge/hedge_frame_0.xpm",
		PATH_ASSET"hedge/hedge_frame_1.xpm",
		PATH_ASSET"hedge/hedge_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message be clean please",
		"Generic message be clean please",
		"Generic message be clean please"};

	ft_load_animation_sprites(&(game->hedge.animation), game, paths,
		error_messages);
}

void	ft_load_borders_sprite(t_game *game)
{
	ft_load_grass_sprites(game);
	ft_load_tree_sprites(game);
	ft_load_trees_sprites(game);
	ft_load_reed_sprites(game);
	ft_load_husks_sprites(game);
	ft_load_fungus_sprites(game);
	ft_load_fungi_sprites(game);
	ft_load_flower_sprites(game);
	ft_load_algae_sprites(game);
	ft_load_water_sprites(game);
	ft_load_crab_sprites(game);
	ft_load_foliage_sprites(game);
	ft_load_bog_sprites(game);
	ft_load_snail_sprites(game);
	ft_load_pillar_sprites(game);
	ft_load_hedge_sprites(game);
}

void	ft_load_alphabet_a(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/a/a_frame_0.xpm",
		PATH_ASSET"alphabet/a/a_frame_1.xpm",
		PATH_ASSET"alphabet/a/a_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.a), game, paths,
		error_messages);
}

void	ft_load_alphabet_c(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/c/c_frame_0.xpm",
		PATH_ASSET"alphabet/c/c_frame_1.xpm",
		PATH_ASSET"alphabet/c/c_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.c), game, paths,
		error_messages);
}

void	ft_load_alphabet_e(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/e/e_frame_0.xpm",
		PATH_ASSET"alphabet/e/e_frame_1.xpm",
		PATH_ASSET"alphabet/e/e_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.e), game, paths,
		error_messages);
}

void	ft_load_alphabet_g(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/g/g_frame_0.xpm",
		PATH_ASSET"alphabet/g/g_frame_1.xpm",
		PATH_ASSET"alphabet/g/g_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.g), game, paths,
		error_messages);
}

void	ft_load_alphabet_i(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/i/i_frame_0.xpm",
		PATH_ASSET"alphabet/i/i_frame_1.xpm",
		PATH_ASSET"alphabet/i/i_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.i), game, paths,
		error_messages);
}

void	ft_load_alphabet_k(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/k/k_frame_0.xpm",
		PATH_ASSET"alphabet/k/k_frame_1.xpm",
		PATH_ASSET"alphabet/k/k_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.k), game, paths,
		error_messages);
}

void	ft_load_alphabet_m(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/m/m_frame_0.xpm",
		PATH_ASSET"alphabet/m/m_frame_1.xpm",
		PATH_ASSET"alphabet/m/m_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.m), game, paths,
		error_messages);
}

void	ft_load_alphabet_o(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/o/o_frame_0.xpm",
		PATH_ASSET"alphabet/o/o_frame_1.xpm",
		PATH_ASSET"alphabet/o/o_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.o), game, paths,
		error_messages);
}

void	ft_load_alphabet_q(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/q/q_frame_0.xpm",
		PATH_ASSET"alphabet/q/q_frame_1.xpm",
		PATH_ASSET"alphabet/q/q_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.q), game, paths,
		error_messages);
}

void	ft_load_alphabet_s(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/s/s_frame_0.xpm",
		PATH_ASSET"alphabet/s/s_frame_1.xpm",
		PATH_ASSET"alphabet/s/s_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.s), game, paths,
		error_messages);
}

void	ft_load_alphabet_u(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/u/u_frame_0.xpm",
		PATH_ASSET"alphabet/u/u_frame_1.xpm",
		PATH_ASSET"alphabet/u/u_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.u), game, paths,
		error_messages);
}

void	ft_load_alphabet_w(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/w/w_frame_0.xpm",
		PATH_ASSET"alphabet/w/w_frame_1.xpm",
		PATH_ASSET"alphabet/w/w_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.w), game, paths,
		error_messages);
}

void	ft_load_alphabet_y(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/y/y_frame_0.xpm",
		PATH_ASSET"alphabet/y/y_frame_1.xpm",
		PATH_ASSET"alphabet/y/y_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.y), game, paths,
		error_messages);
}

void	ft_load_alphabet_b(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/b/b_frame_0.xpm",
		PATH_ASSET"alphabet/b/b_frame_1.xpm",
		PATH_ASSET"alphabet/b/b_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.b), game, paths,
		error_messages);
}

void	ft_load_alphabet_d(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/d/d_frame_0.xpm",
		PATH_ASSET"alphabet/d/d_frame_1.xpm",
		PATH_ASSET"alphabet/d/d_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.d), game, paths,
		error_messages);
}

void	ft_load_alphabet_f(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/f/f_frame_0.xpm",
		PATH_ASSET"alphabet/f/f_frame_1.xpm",
		PATH_ASSET"alphabet/f/f_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.f), game, paths,
		error_messages);
}

void	ft_load_alphabet_h(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/h/h_frame_0.xpm",
		PATH_ASSET"alphabet/h/h_frame_1.xpm",
		PATH_ASSET"alphabet/h/h_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.h), game, paths,
		error_messages);
}

void	ft_load_alphabet_j(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/j/j_frame_0.xpm",
		PATH_ASSET"alphabet/j/j_frame_1.xpm",
		PATH_ASSET"alphabet/j/j_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.j), game, paths,
		error_messages);
}

void	ft_load_alphabet_l(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/l/l_frame_0.xpm",
		PATH_ASSET"alphabet/l/l_frame_1.xpm",
		PATH_ASSET"alphabet/l/l_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.l), game, paths,
		error_messages);
}

void	ft_load_alphabet_n(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/n/n_frame_0.xpm",
		PATH_ASSET"alphabet/n/n_frame_1.xpm",
		PATH_ASSET"alphabet/n/n_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.n), game, paths,
		error_messages);
}

void	ft_load_alphabet_p(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/p/p_frame_0.xpm",
		PATH_ASSET"alphabet/p/p_frame_1.xpm",
		PATH_ASSET"alphabet/p/p_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.p), game, paths,
		error_messages);
}

void	ft_load_alphabet_r(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/r/r_frame_0.xpm",
		PATH_ASSET"alphabet/r/r_frame_1.xpm",
		PATH_ASSET"alphabet/r/r_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.r), game, paths,
		error_messages);
}

void	ft_load_alphabet_t(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/t/t_frame_0.xpm",
		PATH_ASSET"alphabet/t/t_frame_1.xpm",
		PATH_ASSET"alphabet/t/t_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.t), game, paths,
		error_messages);
}

void	ft_load_alphabet_v(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/v/v_frame_0.xpm",
		PATH_ASSET"alphabet/v/v_frame_1.xpm",
		PATH_ASSET"alphabet/v/v_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.v), game, paths,
		error_messages);
}

void	ft_load_alphabet_x(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/x/x_frame_0.xpm",
		PATH_ASSET"alphabet/x/x_frame_1.xpm",
		PATH_ASSET"alphabet/x/x_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.x), game, paths,
		error_messages);
}

void	ft_load_alphabet_z(t_game *game)
{
	const char	*paths[] = {
		PATH_ASSET"alphabet/z/z_frame_0.xpm",
		PATH_ASSET"alphabet/z/z_frame_1.xpm",
		PATH_ASSET"alphabet/z/z_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.alphabet.z), game, paths,
		error_messages);
}

void	ft_load_odd_alphabet_sprite(t_game *game)
{
	ft_load_alphabet_a(game);
	ft_load_alphabet_c(game);
	ft_load_alphabet_e(game);
	ft_load_alphabet_g(game);
	ft_load_alphabet_i(game);
	ft_load_alphabet_k(game);
	ft_load_alphabet_m(game);
	ft_load_alphabet_o(game);
	ft_load_alphabet_q(game);
	ft_load_alphabet_s(game);
	ft_load_alphabet_u(game);
	ft_load_alphabet_w(game);
	ft_load_alphabet_y(game);
}

void	ft_load_even_alphabet_sprite(t_game *game)
{
	ft_load_alphabet_b(game);
	ft_load_alphabet_d(game);
	ft_load_alphabet_f(game);
	ft_load_alphabet_h(game);
	ft_load_alphabet_j(game);
	ft_load_alphabet_l(game);
	ft_load_alphabet_n(game);
	ft_load_alphabet_p(game);
	ft_load_alphabet_r(game);
	ft_load_alphabet_t(game);
	ft_load_alphabet_v(game);
	ft_load_alphabet_x(game);
	ft_load_alphabet_z(game);
}
void	ft_load_alphabet_sprites(t_game *game)
{
	ft_load_odd_alphabet_sprite(game);
	ft_load_even_alphabet_sprite(game);
}

void	ft_load_sprites(t_game *game)
{
	game->node = NULL;
	ft_load_enemies_sprites(game);
	ft_load_wall_sprites(game);
	ft_load_ground_sprites(game);
	ft_load_borders_sprite(game);
	ft_load_player_sprites(game);
	ft_load_keke_sprites(game);
	ft_load_gameplay_sprites(game);
	ft_load_digits_sprites(game);
	ft_load_box_sprites(game);
	ft_load_alphabet_sprites(game);
}

void	ft_add_sprite_to_list(t_sprite_node **head, void *frame)
{
	t_sprite_node	*new_node;

	new_node = (t_sprite_node *)malloc(sizeof(t_sprite_node));
	if (!new_node)
		return ;
	new_node->frame = frame;
	new_node->next = *head;
	*head = new_node;
}

void	ft_load_sprite_frame(void **frame, t_game *game, const char *path,
		const char *error_message)
{
	int	width;
	int	height;

	*frame = mlx_xpm_file_to_image(game->mlx, (char *)path, &width, &height);
	if (*frame == NULL)
		ft_print_error((char *)error_message, game);
	ft_add_sprite_to_list(&game->node, *frame);
}

void	ft_load_animation_sprites(t_animation *animation, t_game *game,
		const char **paths, const char **error_messages)
{
	ft_load_sprite_frame(&(animation->frame_0), game, paths[0],
		error_messages[0]);
	ft_load_sprite_frame(&(animation->frame_1), game, paths[1],
		error_messages[1]);
	ft_load_sprite_frame(&(animation->frame_2), game, paths[2],
		error_messages[2]);
	animation->current = animation->frame_0;
	if (animation->current == NULL)
		ft_print_error((char *)error_messages[0], game);
}
