/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:57:07 by pgomes            #+#    #+#             */
/*   Updated: 2024/08/17 16:17:41 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../lib/libft/header/libft.h"
# include "../lib/minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# define PLAYER 'P'
# define EXIT 'E'
# define COIN 'C'
# define WALL '1'
# define FLOOR '0'

# define TRUE 1
# define FALSE 0
# define CELL_SIZE 40
// player
# define PLAYER_UP "img/player_up.xpm"
# define PLAYER_DOWN "img/player_down.xpm"
# define PLAYER_LEFT "img/player_lefth.xpm"
# define PLAYER_RIGT "img/player_right.xpm"
// objects game
# define O_WALL "img/wall.xpm"
# define O_COIN "img/coin.xpm"
# define O_FLOOR "img/floor.xpm"
# define EXIT_OPEN "img/exit_open.xpm"
# define EXIT_CLOSED "img/exit_closed.xpm"
// keywords pressed
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define DOWN 65364
# define RIGHT 65363
# define UP 65362
# define LEFT 65361
# define RESTART 114

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game_obj
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		count_coin;
	int		exitcount;
	int		count_movements;
	int		player_row;
	int		player_col;
	int		exit_row;
	int		exit_col;

	char	**map;

	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*player_up;
	void	*player;

	void	*coin;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*exit_open;
	void	*exit_closed;
	void	*mlxptr;
	void	*winptr;

}			t_game;

int			exit_point(t_game *game);
int			map_reading(t_game *game, char **argv);
int			add_img_grap(t_game *game);
int			ft_map_draw(t_game *game);
int			ft_check_keyboard(int key, t_game *game);

void		ft_initialize_game(t_game *game);
void		check_errors(t_game *game);
void		flood_fill(t_game *game, int time);
#endif
