/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:44:59 by nranna            #+#    #+#             */
/*   Updated: 2024/05/06 16:44:39 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	start_fractal(t_fractal *fractal, char *name);

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		ft_putstr_fd("you choose mandelbrot set :)\n");
		fractal.flag = 0;
	}
	else if (argc == 3 && !ft_strncmp(argv[1], "julia", 5))
	{
		ft_putstr_fd("you choose julia set :)\n");
		if (!ft_strncmp(argv[2], "A", 1))
			fractal.flag = 1;
		else if (!ft_strncmp(argv[2], "B", 1))
			fractal.flag = 2;
		else if (!ft_strncmp(argv[2], "C", 1))
			fractal.flag = 3;
		else
			fractal.flag = 4;
	}
	else
		ft_putstr_fd(ERROR_MSG);
	start_fractal(&fractal, argv[1]);
	return (0);
}

static void	start_fractal(t_fractal *fractal, char *name)
{
	fractal_init(fractal, name);
	fractal_render(fractal);
	mlx_loop(fractal->mlx_connect);
}
