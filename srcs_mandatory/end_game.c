/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:49:12 by megrelli          #+#    #+#             */
/*   Updated: 2026/01/02 20:12:49 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	cross_clicked(t_game *game)
{
	ft_printf("Game closed by player.\n");
	close_game(game);
	return (0);
}

int	close_game(t_game *game)
{
	free_map(game);
	free_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

void	free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i])
			free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

void	free_images(t_game *game)
{
	if (game->player_up)
		mlx_destroy_image(game->mlx, game->player_up);
	if (game->player_down)
		mlx_destroy_image(game->mlx, game->player_down);
	if (game->player_left)
		mlx_destroy_image(game->mlx, game->player_left);
	if (game->player_right)
		mlx_destroy_image(game->mlx, game->player_right);
	if (game->exit_on)
		mlx_destroy_image(game->mlx, game->exit_on);
	if (game->exit_off)
		mlx_destroy_image(game->mlx, game->exit_off);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
}
