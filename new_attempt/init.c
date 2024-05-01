/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:42:45 by nranna            #+#    #+#             */
/*   Updated: 2024/05/01 07:38:02 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init(t_fractal *fractal, char *name)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WID, HEI, char *name);
}
