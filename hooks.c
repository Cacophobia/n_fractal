/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:38:23 by nranna            #+#    #+#             */
/*   Updated: 2024/04/19 13:59:45 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		return (0);
	
}