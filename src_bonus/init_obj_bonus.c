/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:11:36 by pgomes            #+#    #+#             */
/*   Updated: 2024/08/17 16:34:28 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	ft_check_img(t_game *game, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(game->mlxptr, path, &width, &height);
	if (!*image)
		exit_point(game);
}

static void	ft_img_init(t_game *game)
{
	if (game->enemi_one)
		ft_check_img(game, &game->enemi_one->enemi, ENEMI_RED);
	if (game->enemi_two)
		ft_check_img(game, &game->enemi_two->enemi, ENEMI_BLUE);
	if (game->enemi_tree)
		ft_check_img(game, &game->enemi_tree->enemi, ENEMI_GREEN);
	ft_check_img(game, &game->player_up, PLAYER_UP);
	ft_check_img(game, &game->player_down, PLAYER_DOWN);
	ft_check_img(game, &game->player_right, PLAYER_RIGT);
	ft_check_img(game, &game->player_left, PLAYER_LEFT);
	ft_check_img(game, &game->player_sho_l, PLAYER_SHO_L);
	ft_check_img(game, &game->player_sho_r, PLAYER_SHO_R);
	ft_check_img(game, &game->player_sho_u, PLAYER_SHO_U);
	ft_check_img(game, &game->player_sho_d, PLAYER_SHO_D);
	ft_check_img(game, &game->coin, O_COIN);
	ft_check_img(game, &game->floor, O_FLOOR);
	ft_check_img(game, &game->exit_open, EXIT_OPEN);
	ft_check_img(game, &game->exit_closed, EXIT_CLOSED);
	ft_check_img(game, &game->wall, O_WALL);
}

void	ft_initialize_game(t_game *game)
{
	game->mlxptr = mlx_init();
	if (!game->mlxptr)
		exit_point(game);
	game->direction[0] = 0;
	game->count_movements = 0;
	ft_img_init(game);
	game->player = game->player_left;
	game->exit = game->exit_closed;
	game->winptr = mlx_new_window(game->mlxptr, game->widthmap * CELL_SIZE,
			game->heightmap * CELL_SIZE, "PACMAN");
	if (!game->winptr)
		exit_point(game);
}
