/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:52:37 by pgomes            #+#    #+#             */
/*   Updated: 2024/08/17 17:27:52 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_maps(t_game game)
{
	int	i;

	i = -1;
	while (game.map[++i])
		ft_printf(game.map[i]);
	ft_printf("\n");
}

static void	detroy_img(t_game *game)
{
	mlx_destroy_image(game->mlxptr, game->player_left);
	mlx_destroy_image(game->mlxptr, game->player_right);
	mlx_destroy_image(game->mlxptr, game->player_down);
	mlx_destroy_image(game->mlxptr, game->player_up);
	mlx_destroy_image(game->mlxptr, game->coin);
	mlx_destroy_image(game->mlxptr, game->wall);
	mlx_destroy_image(game->mlxptr, game->floor);
	mlx_destroy_image(game->mlxptr, game->exit_open);
	mlx_destroy_image(game->mlxptr, game->exit_closed);
}

int	exit_point(t_game *game)
{
	int	line;

	line = 0;
	if (game->player)
		detroy_img(game);
	if (game->winptr)
	{
		mlx_destroy_window(game->mlxptr, game->winptr);
		mlx_destroy_display(game->mlxptr);
	}
	free(game->mlxptr);
	while (line < game->heightmap)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc == 2)
	{
		ft_memset(&game, 0, sizeof(t_game));
		if (map_reading(&game, argv))
		{
			check_errors(&game);
			ft_initialize_game(&game);
			mlx_hook(game.winptr, 17, 0, exit_point, &game);
			mlx_hook(game.winptr, 2, (1L << 0), ft_check_keyboard, &game);
			mlx_loop_hook(game.mlxptr, &ft_map_draw, &game);
			mlx_loop(game.mlxptr);
		}
		else
			exit_point(&game);
	}
	else
		ft_printf("\nERROR!\n Valid: ./so_long <map>.ber\n");
	return (0);
}
