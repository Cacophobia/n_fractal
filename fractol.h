/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:59:09 by nranna            #+#    #+#             */
/*   Updated: 2024/05/06 16:20:09 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

//TODO: make a better error message
# define ERROR_MSG "CORRECT USAGE: ./executable.out <mandelbrot | julia>\n"
# define WID 800
# define HEI 800

//TODO: define more shit

# define B 0x000000
# define W 0xFFFFFF
# define R 0xFF0000
# define G 0x00FF00
# define BL 0x0000FF

//pixels buffer
typedef struct s_image
{
	void	*img_ptr;
	char	*pix_ptr;
	int		bits;
	int		endian;
	int		line_len;
}	t_image;
//MLX stuff, image and hooks
typedef struct s_fractal
{
	void	*mlx_connect;
	void	*mlx_win;

	t_image	image;
	double	esc_value;
	int		nof_iterations;
	int		flag;
	double	shift_x;
	double	shift_y;
	double	zoom;
}	t_fractal;

//complex (x = real; y = imaginary)
typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

//str_utils
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlen(char *s);
void	ft_putstr_fd(char *s);
//init
void	events_init(t_fractal *fractal);
void	fractal_init(t_fractal *fractal, char *name);

//render
void	fractal_render(t_fractal *fractal);

//hooks
int		key_handle(int keysym, t_fractal *fractal);

//close
int		close_handle(t_fractal *fractal);
int		mouse_handle(int button, int x, int y, t_fractal *fractal);

//math... linear interpolation
double	rescale_map(double unscaled_num, double new_min,
			double new_max, double old_min, double old_max);
t_complex		square_complex(t_complex z);
t_complex		sum_complex(t_complex z1, t_complex z2);

#endif
