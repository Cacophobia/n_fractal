/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:59:09 by nranna            #+#    #+#             */
/*   Updated: 2024/04/09 23:26:13 by nranna           ###   ########.fr       */
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

#define B 0x000000
#define W 0xFFFFFF
#define R 0xFF0000
#define G 0x00FF00
#define BL 0x0000FF

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
	double	esc_value;
	int	nof_iterations;
}	t_fractal;

//complex
typedef struct	s_complex
{
	//real
	double 	x;
	//imaginary
	double	y;
}	t_complex;


int	ft_strncmp(char *s1, char *s2, int n);
int	ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);
//init
void	fractal_init(t_fractal *fractal, char *name);

//render
void	fractal_render(t_fractal *fractal);

//math... linear interpolation
double	rescale_map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
#endif
