/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:46:53 by nranna            #+#    #+#             */
/*   Updated: 2024/05/03 11:18:00 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

double	rescale_map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	double	proportion;
	double	rescaled_value;

	proportion = (unscaled_num - old_min) / (old_max - old_min);
	rescaled_value = proportion * (new_max - new_min);
	return (rescaled_value + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (pow(z.x, 2)) - (pow(z.y, 2));
	result.y = 2 * z.x * z.y;
	return (result);
}
