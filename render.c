/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:28:05 by nranna            #+#    #+#             */
/*   Updated: 2024/04/09 23:29:10 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits / 8));
	*(unsigned int *)(img->pix_ptr + offset) = color;
}

static void	handle_pix(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int		i;
	int		color;
	//first iteration
	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	//pix cordinates (x && y) scaled to fit on minilibx map
	c.x = rescale_map(x, -2, +2, 0, WID);
	c.y = rescale_map(y, +2, -2, 0, HEI);
	
	//TODO the more iterations you have to do, the worst it get.
	while (i < fractal->nof_iterations)
	{
		z = sum_complex(square_complex(z), c);
		//did the point escape?
		if ((pow(z.x, 2)) + (pow(z.y, 2)) > fractal->esc_value)
		{
			//we left mandel
			color = rescale_map(i, B, W, 0, fractal->nof_iterations);
			my_pixel_put(x, y, &fractal->image, color);
			return ;
		}

		//we're in mandel
		i++;
	}
	my_pixel_put(x, y, &fractal->image, R);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (y < HEI)
	{
		x = 0;
		while (x < WID)
		{
			handle_pix(x, y, fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx_connect,
				fractal->mlx_win,
				fractal->image.img_ptr,
				0, 0);
}
