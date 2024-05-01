/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:43:06 by nranna            #+#    #+#             */
/*   Updated: 2024/05/01 07:11:30 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

//# DEFINES
# define ERROR_MSG "CORRECT USAGE: ./executable.out <mandelbrot | julia>\n"
# define WID 800
# define HEI 800

//# STRUCTS
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
}	t_fractal;

//# PROTOTYPES
//## str_utils
int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr(char *s);

//## init
void	init(t_fractal *fractal, char *name);
#endif
