/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:22:00 by nranna            #+#    #+#             */
/*   Updated: 2024/05/01 07:04:52 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		ft_putstr("you choose mandelbrot set :)\n");
		fractal_init(&fractal, "Mandelbrot");
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		ft_putstr("you choose julia set :)\n");
	}
	else
		ft_pustr(ERROR_MSG);
	return (0);
}
