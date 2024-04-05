/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:59:09 by nranna            #+#    #+#             */
/*   Updated: 2024/03/28 17:15:38 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx_linux/mlx.h"

//TODO: make a better error message
#define ERROR_MSG "CORRECT USAGE: ./executable.out <mandelbrot | julia>\n"

//TODO: define more shit
#define WIN_WIDTH 500
#define WIN_HEIGHT 500



//pixels buffer
typedef struct	s_image
{
	void	*img_ptr;
	char	*pix_ptr;
	int	bits;
	int	endian;
	int	line_len;
}	t_image;

//MLX stuff, image and hooks
typedef struct	s_fractal
{
	void	*mlx_connect;
	void	*mlx_win;
	
	t_image	image;
	//TODO: hooks..?
}	t_fractal;


int	ft_strncmp(char *s1, char *s2, int n);
int	ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);


#endif
