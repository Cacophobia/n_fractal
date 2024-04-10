/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:45:12 by nranna            #+#    #+#             */
/*   Updated: 2024/04/09 23:24:41 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

//TLD;DR = WE ARE PUTTING EVERY NUMBER FROM 0 T0 400 INSIDE THE INTERVAL OF -2 TO 2
//THAT'S POSSIBLE BECAUSE FROM -2 TO 2 THERE IS AN INFINITY OF DECIMAL NUMBERS.

#define OLD_MIN 0
#define OLD_MAX 400
#define NEW_MIN -2
#define NEW_MAX 2

double	rescale(double unscaled_number, double new_min, double new_max, double old_min, double old_max)
{
	double	proportion;
	double	rescaled_value;

	proportion = (unscaled_number - old_min) / (old_max - old_min);
	rescaled_value = proportion * (new_max - new_min);
	return (rescaled_value + new_min);
}

int	main(void)
{
	double	wtf;

	wtf = 0;
	while (wtf <= 400)
	{
		printf("%f\t-->\t%f\n", wtf, rescale(wtf, NEW_MIN, NEW_MAX, OLD_MIN, OLD_MAX));
		wtf++;
	}
	printf("%f", pow(2, 2));
	return (0);
}
