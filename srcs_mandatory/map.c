/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:21:02 by megrelli          #+#    #+#             */
/*   Updated: 2026/01/02 18:20:39 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*check that the map is in a ".ber" file*/

int	check_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		return (0);
	if (ft_strncmp(&path[len - 4], ".ber", 4) == 0)
		return (1);
	return (0);
}

static int	count_lines(char *path)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static int	allocate_map(t_game *game, char *path)
{
	game->map_height = count_lines(path);
	if (game->map_height <= 0)
		return (0);
	game->map = ft_calloc(game->map_height + 1, sizeof(char *));
	if (!game->map)
		return (0);
	return (1);
}

/*saves the map in an array of strings*/

int	get_map(t_game *game, char *path)
{
	int		fd;
	int		i;
	char	*line;

	if (!allocate_map(game, path))
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free_map(game);
		return (0);
	}
	i = 0;
	while (i < game->map_height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		if (!game->map[i++])
			break ;
	}
	close(fd);
	return (i == game->map_height);
}
