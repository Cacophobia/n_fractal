/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:38:23 by nranna            #+#    #+#             */
/*   Updated: 2024/05/03 20:54:57 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	close_handle(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connect, fractal->image.img_ptr);
	mlx_destroy_window(fractal->mlx_connect, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx_connect);
	free(fractal->mlx_connect);
	exit(EXIT_SUCCESS);
}

int	key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handle(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += (0.25 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.25 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.25 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.25 * fractal->zoom);
	else if (keysym == XK_Page_Up)
		fractal->nof_iterations += 10;
	else if (keysym == XK_Page_Down)
		fractal->nof_iterations -= 10;
	fractal_render(fractal);
		return (0);
}

int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
		fractal->zoom *= 0.95; 
	else if (button == Button4)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}
