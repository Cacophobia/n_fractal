/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:28:05 by nranna            #+#    #+#             */
/*   Updated: 2024/05/06 21:34:09 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_pix(int x, int y, t_fractal *fractal);
static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal);
static void	my_pixel_put(int x, int y, t_image *img, int color);

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEI)
	{
		x = -1;
		while (++x < WID)
			handle_pix(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connect, fractal->mlx_win,
		fractal->image.img_ptr, 0, 0);
}

static void	handle_pix(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (rescale_map(x, -2, +2, WID) * fractal->zoom) + fractal->shift_x;
	z.y = (rescale_map(y, +2, -2, HEI) * fractal->zoom) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->nof_iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->esc_value)
		{
			color = rescale_map(i, B, W, fractal->nof_iterations);
			my_pixel_put(x, y, &fractal->image, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->image, 0xFF007F);
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (fractal->flag == 4)
	{
		c->x = -0.8;
		c->y = +0.156;
	}
	else if (fractal->flag == 3)
	{
		c->x = -0.4;
		c->y = +0.6;
	}
	else if (fractal->flag == 2)
	{
		c->x = 0.285;
		c->y = 0;
	}
	else if (fractal->flag == 1)
	{
		c->x = 0.285;
		c->y = +0.01;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits / 8));
	*(unsigned int *)(img->pix_ptr + offset) = color;
}
