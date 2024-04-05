/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trypophobia <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:43:01 by trypophobia       #+#    #+#             */
/*   Updated: 2024/03/28 15:01:46 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_linux/mlx.h"

#define WID 500
#define HEI 500

int	main(void)
{
	void	*mlx_connect;
	void	*win;

	//We need to give them to their own void ptr.
	mlx_connect = mlx_init();
	win = mlx_new_window(mlx_connect, WID, HEI, "Hello World");
	//That's an interesting way of changing the screen color or making a square.
	for (int y = HEI * 0.1; y < HEI * 0.9; y++)
	{
		for (int x = WID * 0.1; x < WID * 0.9; x++)
		{
			mlx_pixel_put(mlx_connect, win, x, y, 0x00ff00);
			mlx_pixel_put(mlx_connect, win, x - 20, y - 20, 0xff0000);
			mlx_pixel_put(mlx_connect, win, x + 20, y + 20, 0x0000ff);
		}
	}
	//Will only create screen if we have this lil buddy on.
	mlx_loop(mlx_connect);
	return (0);
}
