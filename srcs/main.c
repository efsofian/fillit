/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:25:07 by enanrock          #+#    #+#             */
/*   Updated: 2017/02/08 18:16:45 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(int argc, char **argv)
{
	t_mem_ttmn	mem;
	char		*result;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file");
	}
	else if (trad_and_init(argv[1], &mem) == NULL)
	{
		ft_putstr("error""\n");
	}
	else
	{
		find_checkboard(&mem);
		if ((result = ft_pretrad(&mem)) == NULL)
		{
			ft_putstr("error""\n");
		}
		else
		{
			ft_putstr(result);
			free(result);
		}
	}
	return (0);
}
