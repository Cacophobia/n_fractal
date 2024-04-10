/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:16:57 by nranna            #+#    #+#             */
/*   Updated: 2024/04/09 23:17:13 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("SOMETHING BAD HAPPENED!!");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->esc_value = 4;
	fractal->nof_iterations = 42;
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
	fractal->image.img_ptr = mlx_new_image(fractal->mlx_connect,
			WID, HEI);
	if (fractal->image.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connect, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		malloc_error();
	}
	//that is the start of something that might not be correct... 
	//TODO: check if there's a better way of doing that!
	fractal->image.pix_ptr = mlx_get_data_addr(fractal->image.img_ptr,
			&fractal->image.bits,
			&fractal->image.line_len, &fractal->image.endian);
	//TODO: events_init(fractal);
	data_init(fractal);
}
