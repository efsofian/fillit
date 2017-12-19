/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:10:05 by enanrock          #+#    #+#             */
/*   Updated: 2017/01/10 16:01:13 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		sqrt_int(int i)
{
	int		inf;
	int		sup;
	int		temp;

	inf = -42;
	sup = 1;
	while ((sup * sup) < i)
		sup *= 2;
	inf = sup / 2;
	while ((inf < sup) && ((inf + 1) != sup))
	{
		temp = (inf / 2) + (sup / 2);
		if ((temp * temp) < i)
			inf = temp;
		else
			sup = temp;
	}
	return (sup);
}
/*
**  #include <stdio.h>
**
**  int		main(void)
**  {
**  	printf("i = %d""\n", 152);
**  	printf("V = %d""\n", sqrt_int(152));
**  	return (0);
**  }
*/
