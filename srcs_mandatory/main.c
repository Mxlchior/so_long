/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 04:43:16 by megrelli          #+#    #+#             */
/*   Updated: 2026/01/02 19:55:20 by megrelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || !check_extension(argv[1]))
		return (ft_printf("Error\nFormat: ./so_long *.ber\n"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	if (!get_map(&game, argv[1]))
	{
		free_map(&game);
		return (ft_printf("Error\nFaild to load map\n"), 1);
	}
	if (!check_map(&game))
		return (free_map(&game), 1);
	if (!init_mlx(&game))
	{
		free_map(&game);
		return (ft_printf("Error\nmlx failed\n"), 1);
	}
	if (!init_sprites(&game))
		return (close_game(&game), 1);
	render_map(&game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
}
