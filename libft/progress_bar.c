/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:37:32 by enanrock          #+#    #+#             */
/*   Updated: 2016/12/31 18:45:13 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  .oO0
**  .sS$
**  .|PR
*/

static int		init(char sym[4], unsigned int e)
{
	int		i;

	i = 0;
	while (i++ < 52)
		ft_putstr(" ");
	ft_putchar('\r');
	if (e >= 200)
	{
		return (0);
	}
	sym[0] = '.';
	sym[1] = 's';
	sym[2] = 'S';
	sym[3] = '$';
	ft_putstr("\033[1;37m[            '           |            '            ]");
	ft_putchar('\r');
	ft_putchar('[');
	ft_putstr("\033[1;30m");
	return (1);
}

static void		end(void)
{
	ft_putstr("\r""\033[m");
}

void			progress_bar(unsigned long current_state, unsigned int max)
{
	char			sym[4];
	unsigned int	e;

	e = 200 * current_state / max;
	if (init(sym, e) == 1)
	{
		if (e > 150)
			ft_putstr("\033[1;32m");
		else if (e > 100)
			ft_putstr("\033[1;33m");
		else if (e > 50)
			ft_putstr("\033[1;31m");
		while (e >= 4)
		{
			ft_putchar(sym[3]);
			e -= 4;
		}
		if ((e % 4) == 3)
			ft_putchar(sym[2]);
		else if ((e % 4) == 2)
			ft_putchar(sym[1]);
		else if ((e % 4) == 1)
			ft_putchar(sym[0]);
		end();
	}
}
/*
**  #include <unistd.h>
**  #include <stdio.h>
**
**  int				main(void)
**  {
**  	int		i;
**
**  	i = 0;
**  	while (i < 210)
**  	{
**  		progress_bar(i, 200);
**  		i++;
**  		sleep(1);
**  	}
**  	ft_putstr("****\n");
**  	ft_putstr("****\n");
**  	ft_putstr("****\n");
**   	ft_putstr("****\n");
**  	return (0);
**  }
*/
