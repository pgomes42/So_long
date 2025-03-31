/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:56:07 by pgomes            #+#    #+#             */
/*   Updated: 2024/08/17 17:26:20 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != to_fill && tab[cur.y][cur.x] != 'E'
			&& tab[cur.y][cur.x] != 'C' && tab[cur.y][cur.x] != '0'
			&& tab[cur.y][cur.x] != 'G' && tab[cur.y][cur.x] != 'R'
			&& tab[cur.y][cur.x] != 'B'))
		return ;
	tab[cur.y][cur.x] = 'X';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

static void	fill_two(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != to_fill && tab[cur.y][cur.x] != 'C'
		&& tab[cur.y][cur.x] != '0' && tab[cur.y][cur.x] != 'G'
		&& tab[cur.y][cur.x] != 'R' && tab[cur.y][cur.x] != 'B'))
		return ;
	tab[cur.y][cur.x] = 'X';
	fill_two(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill_two(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill_two(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill_two(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

static void	free_map_temp(t_game *game, char **temp)
{
	int	i;

	i = 0;
	while (i < game->heightmap)
		free(temp[i++]);
	free(temp);
}

static void	verifi_map(t_game *game, char **map_fill)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->heightmap)
	{
		j = 0;
		while (j < game->widthmap)
		{
			if (map_fill[i][j] != '0' && map_fill[i][j] != '1'
				&& map_fill[i][j] != 'X')
			{
				ft_printf("\nError\nThe path is not valid\n");
				free_map_temp(game, map_fill);
				exit_point(game);
			}
			j++;
		}
		i++;
	}
	free_map_temp(game, map_fill);
}

void	flood_fill(t_game *game, int time)
{
	char	**temp;
	int		i;

	temp = (char **)malloc(sizeof(char *) * game->heightmap + 1);
	if (!temp)
		return ;
	i = -1;
	while (game->map[++i])
		temp[i] = ft_strdup(game->map[i]);
	if (time)
		fill(temp, (t_point){game->widthmap, game->heightmap},
			(t_point){game->player_col, game->player_row},
			temp[game->player_row][game->player_col]);
	else
	{
		temp[game->exit_row][game->exit_col] = 'X';
		fill_two(temp, (t_point){game->widthmap, game->heightmap},
			(t_point){game->player_col, game->player_row},
			temp[game->player_row][game->player_col]);
	}
	verifi_map(game, temp);
}
