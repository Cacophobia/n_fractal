/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:44:59 by nranna            #+#    #+#             */
/*   Updated: 2024/05/06 12:28:40 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		ft_putstr_fd("you choose mandelbrot set :)\n", 1);
		fractal_init(&fractal, argv[1]);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connect);
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		ft_putstr_fd("you choose julia set :)\n", 1);
		if (!ft_strncmp(argv[2], "A", 1))
		{
			//TODO: julia set 1;
		}
		else if (!ft_strncmp(argv[2], "B"))
		{
			//TODO: julia set 2;
		}
		else if (!ft_strncmp(argv[2], "C"))
		{
			//TODO: julia set 3;
		}
		else
		{
			//TODO: julia set 4;
		}
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, 1);
	}
	return (0);
}
