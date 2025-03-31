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

void	ft_result(t_game *game, int result)
{
	if (result)
		ft_printf("\nSORRY! You lost...\n");
	if (!result)
		ft_printf("\nCongratulation! You wim...\n");
	game->map[game->player_row][game->player_col] = FLOOR;
	game->count_movements++;
	exit_point(game);
}

void	ft_print_shell(t_game *game)
{
	static int	moviment = -1;
	char		*str;
	char		*aux;

	aux = ft_itoa(game->count_movements);
	str = ft_strjoin("Moved : ", aux);
	free(aux);
	aux = ft_strjoin(str, " time");
	free(str);
	if (game->count_movements != moviment)
		moviment = game->count_movements;
	mlx_string_put(game->mlxptr, game->winptr, 40, 50, 0xFFFFFF, aux);
	ft_printf ("%s\n", aux);
	free(aux);
}

static void	moved_pac(t_game *game, void *player, int column, int row)
{
	int	new_row;
	int	new_col;
	int	current_tile;

	new_row = game->player_row + row;
	new_col = game->player_col + column;
	current_tile = game->map[new_row][new_col];
	if (current_tile == EXIT && game->count_coin == 0)
		ft_result(game, 0);
	if (current_tile == ENEMI)
		ft_result(game, 1);
	if (current_tile == FLOOR || current_tile == COIN)
	{
		game->player = player;
		game->map[new_row][new_col] = PLAYER;
		game->map[game->player_row][game->player_col] = FLOOR;
		game->player_row = new_row;
		game->player_col = new_col;
		if (current_tile == COIN)
			game->count_coin--;
		game->count_movements++;
	}
}

static void	ft_move_player_two(t_game *game, int eat)
{
	if (game->direction[0] == 1)
	{
		if (eat)
			moved_pac(game, game->player_left, -1, 0);
		else
			moved_pac(game, game->player_sho_l, -1, 0);
	}
	else if (game->direction[0] == 2)
	{
		if (eat)
			moved_pac(game, game->player_down, 0, 1);
		else
			moved_pac(game, game->player_sho_d, 0, 1);
	}
	else if (game->direction[0] == 3)
	{
		if (eat)
			moved_pac(game, game->player_right, 1, 0);
		else
			moved_pac(game, game->player_sho_r, 1, 0);
	}
	if (game->count_coin == 0)
		game->exit = game->exit_open;
}

int	ft_move_player(t_game *game)
{
	static int	eat;
	static int	i;

	if (i == 75)
	{
		if (can_move_diretion(game, (t_point){game->player_col,
				game->player_row}, game->direction[1]))
			game->direction[0] = game->direction[1];
		if (game->direction[0] == 0)
		{
			if (eat)
				moved_pac(game, game->player_up, 0, -1);
			else
				moved_pac(game, game->player_sho_u, 0, -1);
		}
		ft_move_player_two(game, eat);
		eat = !eat;
		i = 0;
	}
	i++;
	return (0);
}
