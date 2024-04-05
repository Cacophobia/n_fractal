/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:45:19 by nranna            #+#    #+#             */
/*   Updated: 2024/03/16 19:28:59 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_linux/mlx.h"
#include <unistd.h>

#define WID 500
#define HEI 500

int	main(void)
{
	void	*mlx_connect;
	void	*win;
	int	x, y;

	x = WID * 0.1;
	y = HEI * 0.1;
	mlx_connect = mlx_init();
	if (mlx_connect == NULL)
		return (1);
	win = mlx_new_window(mlx_connect, WID, HEI, "Square&Rectangle");
	if (win == NULL)
		return (1);
	//make red square.
	while (x < WID * 0.9)
	{
		y = 0;
		while (y < HEI * 0.9)
		{
			mlx_pixel_put(mlx_connect, win, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
	mlx_loop(mlx_connect);
}
