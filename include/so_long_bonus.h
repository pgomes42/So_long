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

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../lib/libft/header/libft.h"
# include "../lib/minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <time.h>

# define PLAYER 'P'
# define EXIT 'E'
# define COIN 'C'
# define WALL '1'
# define FLOOR '0'
# define ENEMI 'T'

# define TRUE 1
# define FALSE 0
# define CELL_SIZE 40
// player
# define PLAYER_SHO_U "img/player_sho_u.xpm"
# define PLAYER_SHO_D "img/player_sho_d.xpm"
# define PLAYER_SHO_L "img/player_sho_l.xpm"
# define PLAYER_SHO_R "img/player_sho_r.xpm"
# define PLAYER_UP "img/player_up.xpm"
# define PLAYER_DOWN "img/player_down.xpm"
# define PLAYER_LEFT "img/player_lefth.xpm"
# define PLAYER_RIGT "img/player_right.xpm"
//enemi
# define ENEMI_RED "img/enemi_red.xpm"
# define ENEMI_BLUE "img/enemi_blue.xpm"
# define ENEMI_GREEN "img/enemi_green.xpm"
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

typedef struct s_enemi
{
	void	*enemi;
	char	obj;
	int		direction[2];
	int		obj_b;
	int		pos_col;
	int		pos_row;
	int		mov;
}		t_enemi;

typedef struct s_game_obj
{
	t_enemi	*enemi_one;
	t_enemi	*enemi_two;
	t_enemi	*enemi_tree;

	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*player_up;
	void	*player_sho_l;
	void	*player_sho_r;
	void	*player_sho_u;
	void	*player_sho_d;
	void	*player;
	void	*coin;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*exit_open;
	void	*exit_closed;
	void	*mlxptr;
	void	*winptr;

	char	**map;

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
	int		direction[2];

}			t_game;

int			exit_point(t_game *game);
int			map_reading(t_game *game, char **argv);
int			add_img_grap(t_game *game);
int			ft_map_draw(t_game *game);
int			ft_check_keyboard(int key, t_game *game);
int			ft_move_player(t_game *game);
int			can_move(t_game *game, int new_row, int new_col);
int			can_move_diretion(t_game *game, t_point verif, int dir);

void		ft_print_shell(t_game *game);
void		ft_result(t_game *game, int result);
void		patrol(t_game *game);
void		move_all_ghosts(t_game *game);
void		print_maps(t_game *game);
void		ft_initialize_game(t_game *game);
void		check_errors(t_game *game);
void		flood_fill(t_game *game, int time);
#endif
