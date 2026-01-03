/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:29:10 by megrelli          #+#    #+#             */
/*   Updated: 2026/01/02 20:04:49 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("Game closed by player.\n");
		close_game(game);
	}
	else if (keycode == KEY_W)
		move_player(game, 0, -1, game->player_up);
	else if (keycode == KEY_S)
		move_player(game, 0, 1, game->player_down);
	else if (keycode == KEY_A)
		move_player(game, -1, 0, game->player_left);
	else if (keycode == KEY_D)
		move_player(game, 1, 0, game->player_right);
	return (0);
}
/*mlx_hook(void *win, int event, int mask, int (*f)(), void *param);
« Quand l’événement event arrive sur la fenêtre win,
si cet événement correspond au mask,
alors j’appelle la fonction f(param)*/

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1 << 0, key_handler, game);
	mlx_hook(game->win, 17, 0, cross_clicked, game);
}
