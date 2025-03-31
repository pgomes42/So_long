/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:12:35 by pgomes            #+#    #+#             */
/*   Updated: 2024/08/09 14:49:50 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_set(t_game *game, void *img, int wid, int hgt)
{
	mlx_put_image_to_window(game->mlxptr, game->winptr, img, wid * CELL_SIZE,
		hgt * CELL_SIZE);
}

int	ft_map_draw(t_game *game)
{
	int	row;
	int	column;

	row = -1;
	while (game->map[++row])
	{
		column = 0;
		while (game->map[row][column])
		{
			if (game->map[row][column] == WALL)
				ft_set(game, game->wall, column, row);
			if (game->map[row][column] == FLOOR)
				ft_set(game, game->floor, column, row);
			if (game->map[row][column] == PLAYER)
				ft_set(game, game->player, column, row);
			if (game->map[row][column] == EXIT)
				ft_set(game, game->exit, column, row);
			if (game->map[row][column] == COIN)
				ft_set(game, game->coin, column, row);
			column++;
		}
	}
	return (0);
}
