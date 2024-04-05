/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_fractal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:59:09 by nranna            #+#    #+#             */
/*   Updated: 2024/04/03 21:20:07 by nranna           ###   ########.fr       */
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
#define WID 400
#define HEI 400
//TODO: define more shit



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
//init
void	fractal_init(t_fractal *fractal, char *name);

#endif
