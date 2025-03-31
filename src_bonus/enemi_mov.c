/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:22:19 by pgomes            #+#    #+#             */
/*   Updated: 2024/09/02 11:33:27 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	get_direction_ghost_two(t_game *game, t_enemi *ghost)
{
	if (ghost->direction[0] == 2)
	{
		if (can_move_diretion(game, (t_point){ghost->pos_col,
				ghost->pos_row}, 3))
			ghost->direction[1] = 3;
		else if (can_move_diretion(game, (t_point){ghost->pos_col,
				ghost->pos_row}, 1))
			ghost->direction[1] = 1;
		else
			ghost->direction[1] = 0;
	}
	else if (ghost->direction[0] == 3)
	{
		if (can_move_diretion(game, (t_point){ghost->pos_col,
				ghost->pos_row}, 2))
			ghost->direction[1] = 2;
		else if (can_move_diretion(game, (t_point){ghost->pos_col,
				ghost->pos_row}, 0))
			ghost->direction[1] = 0;
		else
			ghost->direction[1] = 1;
	}
}

static void	get_direction_ghost(t_game *game, t_enemi *ghost)
{
	if (ghost->direction[0] == 0)
	{
		if (can_move_diretion(game, (t_point){ghost->pos_col,
				ghost->pos_row}, 1))
			ghost->direction[1] = 1;
		else if (can_move_diretion(game, (t_point){ghost->pos_col,
				ghost->pos_row}, 3))
			ghost->direction[1] = 3;
		else
			ghost->direction[1] = 2;
	}
	else if (ghost->direction[0] == 1)
	{
		if (can_move_diretion(game, (t_point){ghost->pos_col,
				ghost->pos_row}, 0))
			ghost->direction[1] = 0;
		else if (can_move_diretion(game, (t_point){ghost->pos_col,
				ghost->pos_row}, 2))
			ghost->direction[1] = 2;
		else
			ghost->direction[1] = 3;
	}
	else
		get_direction_ghost_two(game, ghost);
}

static void	moved_ghost(t_game *game, t_enemi *ghost, int column, int row)
{
	int	new_row;
	int	new_col;
	int	current_tile;

	new_row = ghost->pos_row + row;
	new_col = ghost->pos_col + column;
	current_tile = game->map[new_row][new_col];
	if (current_tile == PLAYER)
		ft_result(game, 1);
	if (current_tile == FLOOR || current_tile == COIN)
	{
		ghost->obj_b = current_tile;
		game->map[new_row][new_col] = ghost->obj;
		game->map[ghost->pos_row][ghost->pos_col] = ghost->obj_b;
		ghost->pos_row = new_row;
		ghost->pos_col = new_col;
	}
	else if (current_tile == WALL || current_tile == 'G'
		|| current_tile == 'B' || current_tile == 'R' || current_tile == EXIT)
		get_direction_ghost(game, ghost);
}

static void	mov_enemi(t_game *game, t_enemi *ghost)
{
	int	dir;

	if (ghost->mov == 70)
	{
		dir = rand() % 4;
		if ((dir != (ghost->direction[0] + 2)
				&& dir != (ghost->direction[0] - 2))
			&& dir != ghost->direction[0])
			ghost->direction[1] = dir;
		if (can_move_diretion(game, (t_point){ghost->pos_col,
				ghost->pos_row}, ghost->direction[1]))
			ghost->direction[0] = ghost->direction[1];
		if (ghost->direction[0] == 0)
			moved_ghost(game, ghost, 0, -1);
		else if (ghost->direction[0] == 1)
			moved_ghost(game, ghost, -1, 0);
		else if (ghost->direction[0] == 2)
			moved_ghost(game, ghost, 0, 1);
		else if (ghost->direction[0] == 3)
			moved_ghost(game, ghost, 1, 0);
		ghost->mov = 0;
	}
	ghost->mov++;
}

void	move_all_ghosts(t_game *game)
{
	if (game->enemi_one)
		mov_enemi(game, game->enemi_one);
	if (game->enemi_two)
		mov_enemi(game, game->enemi_two);
	if (game->enemi_tree)
		mov_enemi(game, game->enemi_tree);
}
