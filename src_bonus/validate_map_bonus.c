/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:43:56 by pgomes            #+#    #+#             */
/*   Updated: 2024/08/17 17:11:12 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	horizontalwall(t_game *game)
{
	int	col;

	col = 0;
	while (col < game->widthmap)
	{
		if (game->map[0][col] != WALL
		|| game->map[game->heightmap - 1][col] != WALL)
		{
			ft_printf("Error\nMissing wall in horizontal walls\n");
			exit_point(game);
		}
		col++;
	}
}

static void	verticalwall(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (game->map[height][0] != WALL
		|| game->map[height][width - 1] != WALL)
		{
			ft_printf("Error!\nMissing wall in vertical walls\n");
			exit_point(game);
		}
		height++;
	}
	horizontalwall(game);
}

static void	init_enemi(t_game *game, int row, int col)
{
	t_enemi	*ghost;

	if (game->map[row][col] == 'R' || game->map[row][col] == 'B'
		|| game->map[row][col] == 'G')
	{
		ghost = (t_enemi *)malloc(sizeof(t_enemi));
		ghost->pos_row = row;
		ghost->pos_col = col;
		ghost->mov = 0;
		ghost->direction[1] = 0;
		ghost->direction[0] = 0;
		ghost->obj = game->map[row][col];
		if (game->map[row][col] == 'R')
			game->enemi_one = ghost;
		if (game->map[row][col] == 'B')
			game->enemi_two = ghost;
		if (game->map[row][col] == 'G')
			game->enemi_tree = ghost;
	}
}

static void	count_checker(t_game *game, int height, int width)
{
	if (game->map[height][width] != WALL && game->map[height][width] != FLOOR
		&& game->map[height][width] != PLAYER && game->map[height][width] != 'R'
		&& game->map[height][width] != 'G' && game->map[height][width] != 'B'
		&& game->map[height][width] != EXIT && game->map[height][width] != COIN
		&& game->map[height][width] != '\n')
	{
		ft_printf("Error\nCaracter invalid here! %c\n",
			game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == COIN)
		game->count_coin++;
	if (game->map[height][width] == PLAYER)
	{
		game->player_row = height;
		game->player_col = width;
		game->playercount++;
	}
	if (game->map[height][width] == EXIT)
	{
		game->exit_row = height;
		game->exit_col = width;
		game->exitcount++;
	}
}

void	check_errors(t_game *game)
{
	int	height;
	int	width;

	verticalwall(game);
	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			init_enemi(game, height, width);
			width++;
		}
		height++;
	}
	flood_fill(game, 1);
	flood_fill(game, 0);
	if (!(game->playercount == 1 && game->count_coin >= 1
			&& game->exitcount == 1))
	{
		ft_printf("Error\nCheck your map\n");
		exit_point(game);
	}
}
