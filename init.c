/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:16:57 by nranna            #+#    #+#             */
/*   Updated: 2024/05/06 21:25:45 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("SOMETHING BAD HAPPENED!!");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->esc_value = 4;
	fractal->nof_iterations = 84;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress,
		KeyPressMask, key_handle, fractal);
	mlx_hook(fractal->mlx_win, ButtonPress,
		ButtonPressMask, mouse_handle, fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify,
		StructureNotifyMask, close_handle, fractal);
}

void	fractal_init(t_fractal *fractal, char *name)
{
	fractal->mlx_connect = mlx_init();
	if (fractal->mlx_connect == NULL)
		malloc_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx_connect,
			WID, HEI, name);
	if (fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		malloc_error();
	}
	fractal->image.img_ptr = mlx_new_image(fractal->mlx_connect, WID, HEI);
	if (fractal->image.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connect, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		malloc_error();
	}
	fractal->image.pix_ptr = mlx_get_data_addr(fractal->image.img_ptr,
			&fractal->image.bits, &fractal->image.line_len,
			&fractal->image.endian);
	events_init(fractal);
	data_init(fractal);
}
