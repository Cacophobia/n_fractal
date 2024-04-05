/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pollock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:02:55 by nranna            #+#    #+#             */
/*   Updated: 2024/03/16 16:40:08 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_linux/mlx.h"
#include <stdlib.h>
#define WID 500
#define HEI 500

int	main(void)
{
	void	*mlx_connect;
	void	*window;

	mlx_connect = mlx_init();
	window = mlx_new_window(mlx_connect, WID, HEI, "Pollock");
	for (int y = HEI * 0.1; y < HEI * 0.9; y++)
	{
		for (int x = WID * 0.1; x < WID * 0.9; x++)
		{
			mlx_pixel_put(mlx_connect, window, x, y, rand() % 0xffffff);
		}
	}
	mlx_string_put(mlx_connect, window, WID * 0.8, HEI * 0.95, 0xffffff, "NRANNA - 42");
	mlx_loop(mlx_connect);
}
