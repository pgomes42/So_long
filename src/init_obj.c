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

#include "../include/so_long.h"

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
	ft_check_img(game, &game->player_up, PLAYER_UP);
	ft_check_img(game, &game->player_down, PLAYER_DOWN);
	ft_check_img(game, &game->player_right, PLAYER_RIGT);
	ft_check_img(game, &game->player_left, PLAYER_LEFT);
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
	game->count_movements = 0;
	ft_img_init(game);
	game->player = game->player_left;
	game->exit = game->exit_closed;
	game->winptr = mlx_new_window(game->mlxptr, game->widthmap * CELL_SIZE,
			game->heightmap * CELL_SIZE, "PACMAN");
	if (!game->winptr)
		exit_point(game);
}
