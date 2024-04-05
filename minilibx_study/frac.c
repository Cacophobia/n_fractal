/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:44:59 by nranna            #+#    #+#             */
/*   Updated: 2024/03/28 19:40:24 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		//TODO implement mandelbrot set
		ft_putstr_fd("you choose mandelbrot set :)\n", 1);
		//first function
		fractal_init(&fractal);
		//second function
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connect);









	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		//TODO implement at least 4 julia sets
		ft_putstr_fd("you choose julia set :)\n", 1);
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, 1);
		//TODO: show correct usage
	}
	return (0);
}
