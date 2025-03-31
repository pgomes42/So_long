/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:01:56 by pgomes            #+#    #+#             */
/*   Updated: 2024/08/17 16:19:19 by pgomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	error_map(void)
{
	ft_printf("ERROR\nFormat of file is not valid!\n");
	exit(0);
}

static int	width_of_map(char **string)
{
	int	row;
	int	col;
	int	cont;

	row = 0;
	cont = 0;
	while (string[row])
	{
		col = 0;
		while (string[row][col])
		{
			if (row == 0)
				cont++;
			col++;
		}
		if (cont != col)
		{
			ft_printf("ERROR\nMap is not retangular\n");
			exit(0);
		}
		row++;
	}
	if (string[0][cont - 1] == '\n')
		cont--;
	return (cont);
}

static int	add_line(t_game *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	temporary[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	free(game->map);
	game->map = temporary;
	return (1);
}

static void	ft_map_extension(char *map)
{
	char		*extension;
	char		*file_extension;
	static int	file_count;

	file_count = 0;
	extension = ".ber";
	file_extension = ft_strrchr(map, '.');
	if ((map[ft_strlen(map) - 1] == '/'))
		error_map();
	else if (!file_extension || !ft_strncmp(file_extension, "", 1))
		error_map();
	else if (file_extension && !ft_strncmp(file_extension, extension, 4))
	{
		if (file_count >= 1)
			error_map();
		file_count++;
	}
	else
		error_map();
}

int	map_reading(t_game *game, char **argv)
{
	char	*readmap;

	ft_map_extension(argv[1]);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		perror("Error\n");
		exit(0);
	}
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close(game->fd);
	if (!game->map)
	{
		ft_printf("ERROR\nMap empty!\n");
		exit(0);
	}
	game->widthmap = width_of_map(game->map);
	return (1);
}
