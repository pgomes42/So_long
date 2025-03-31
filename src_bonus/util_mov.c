/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:25:04 by pgomes            #+#    #+#             */
/*   Updated: 2024/08/17 16:34:01 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	can_move(t_game *game, int new_row, int new_col)
{
	return (game->map[new_row][new_col] != WALL);
}

int	can_move_diretion(t_game *game, t_point verif, int dir)
{
	if (dir == 0)
		return (can_move(game, verif.y - 1, verif.x));
	else if (dir == 1)
		return (can_move(game, verif.y, verif.x - 1));
	else if (dir == 2)
		return (can_move(game, verif.y + 1, verif.x));
	else
		return (can_move(game, verif.y, verif.x + 1));
}

int	ft_check_keyboard(int key, t_game *game)
{
	if (key == ESC)
		exit_point(game);
	if (key == W || key == UP)
		game->direction[1] = 0;
	else if (key == A || key == LEFT)
		game->direction[1] = 1;
	else if (key == S || key == DOWN)
		game->direction[1] = 2;
	else if (key == D || key == RIGHT)
		game->direction[1] = 3;
	return (0);
}
