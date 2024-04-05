/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trypophobia <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:43:01 by trypophobia       #+#    #+#             */
/*   Updated: 2024/03/16 16:48:33 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_linux/mlx.h"

int	main(void)
{
	void	*mlx_connect;
	void	*win;
	int	i;

	i = 0;
	//We need to give them to their own void ptr.
	mlx_connect = mlx_init();
	if (mlx_connect == NULL)
		return (1);
	win = mlx_new_window(mlx_connect, 500, 500, "Hello World");
	if (win == NULL)
		return (1);
	//put a pixel on screen, colors in RGB HEX values.
	while (i < 240)
	{
		//sadly, we have to put our pixels in X/Y coordinates
		//(0,0) is in the top left corner... wtf.
		mlx_pixel_put(mlx_connect, win, 250 + i, 250 + i, 0xff0000);
		mlx_pixel_put(mlx_connect, win, 0 + i, 0 + i, 0x00ff00);
		//horizontal (to the right) growing lines.
		mlx_pixel_put(mlx_connect, win, 0 + i, 0, 0x0000ff);
		//vertical (down) growing line
		mlx_pixel_put(mlx_connect, win, 0, 0 + i, 0x0000ff);
		//horizontal (left) growing line
		mlx_pixel_put(mlx_connect, win, 500 - i, 0, 0xffffff);
		//vertical (left) growing line
		mlx_pixel_put(mlx_connect, win, 0, 500 - i, 0xffffff);
		i++;
	}
	//Will only create screen if we have this lil buddy on.
	mlx_loop(mlx_connect);
	return (0);
}
