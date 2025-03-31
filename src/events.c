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

#include "../include/so_long.h"

static void	ft_win(t_game *game)
{
	game->map[game->player_row][game->player_col] = FLOOR;
	game->count_movements++;
	ft_printf("\nCongratulation! You wim...\n");
	exit_point(game);
}

static void	ft_print_shell(t_game *game)
{
	static int	moviment = -1;

	if (game->count_movements != moviment)
	{
		ft_printf("You moved %d times.\n", game->count_movements);
		moviment = game->count_movements;
	}
}

static void	ft_events_pressed(t_game *game, void *player, int column, int row)
{
	int	new_row;
	int	new_col;
	int	current_tile;

	game->player = player;
	new_row = game->player_row + row;
	new_col = game->player_col + column;
	current_tile = game->map[new_row][new_col];
	if (current_tile == EXIT && game->count_coin == 0)
		ft_win(game);
	if (current_tile == FLOOR || current_tile == COIN)
	{
		game->map[new_row][new_col] = PLAYER;
		game->map[game->player_row][game->player_col] = FLOOR;
		game->player_row = new_row;
		game->player_col = new_col;
		if (current_tile == COIN)
			game->count_coin--;
		game->count_movements++;
	}
	ft_print_shell(game);
}

int	ft_check_keyboard(int key, t_game *game)
{
	if (key == ESC)
	{
		ft_printf("\nOh,Game is closed...\n");
		exit_point(game);
	}
	else if (key == W || key == UP)
		ft_events_pressed(game, game->player_up, 0, -1);
	else if (key == A || key == LEFT)
		ft_events_pressed(game, game->player_left, -1, 0);
	else if (key == S || key == DOWN)
		ft_events_pressed(game, game->player_down, 0, +1);
	else if (key == D || key == RIGHT)
		ft_events_pressed(game, game->player_right, +1, 0);
	if (game->count_coin == 0)
		game->exit = game->exit_open;
	return (0);
}
