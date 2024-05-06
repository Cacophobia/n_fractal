/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:06:36 by nranna            #+#    #+#             */
/*   Updated: 2024/05/06 12:05:12 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && n > 0)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		n--;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;	
	if (!s || fd < 0)
		return ;
	i = write(fd, s, ft_strlen(s));
	(void)i;
}
