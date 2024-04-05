/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:28:05 by nranna            #+#    #+#             */
/*   Updated: 2024/04/03 21:37:54 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

void	handle_pix(int x, int y, t_fractal *fractal)
{

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
			handle_pix();
			y++;
		}
		x++;
	}
}
