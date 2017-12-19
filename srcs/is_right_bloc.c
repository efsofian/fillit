/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_bloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2116/12/21 10:58:01 by enanrock          #+#    #+#             */
/*   Updated: 2017/01/28 21:48:28 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_right_bloc.h"

static void		set_result(t_mem_ttmn *result, int bloc[4])
{
	int		i;
	int		j;

	result->lock[result->number_ttmn][1] = bloc[1] - bloc[0];
	result->lock[result->number_ttmn][2] = bloc[2] - bloc[0];
	result->lock[result->number_ttmn][3] = bloc[3] - bloc[0];
	if (result->length < 4)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (result->length < (bloc[i] / 5 - bloc[j] / 5 + 1))
					result->length = (bloc[i] / 5 - bloc[j] / 5 + 1);
				if (result->length < (bloc[i] % 5 - bloc[j] % 5 + 1))
					result->length = (bloc[i] % 5 - bloc[j] % 5 + 1);
				j++;
			}
			i++;
		}
	}
	result->limite = (result->length + 1) * result->length;
}

int				is_hash_stuck(t_mem_ttmn *result, int bloc[4])
{
	int		num;

	num = (bloc[0] == bloc[1] - 1) +
		((bloc[0] == bloc[1] - 5) + (bloc[0] == bloc[2] - 5) +
			(bloc[0] == bloc[3] - 5)) +
		(bloc[1] == bloc[0] + 5) +
		(bloc[1] == bloc[0] + 1) +
		(bloc[1] == bloc[2] - 1) +
		((bloc[1] == bloc[2] - 5) + (bloc[1] == bloc[3] - 5)) +
		((bloc[2] == bloc[0] + 5) + (bloc[1] == bloc[1] + 5)) +
		(bloc[2] == bloc[1] + 1) +
		(bloc[2] == bloc[3] - 1) +
		(bloc[2] == bloc[3] - 5) +
		((bloc[3] == bloc[2] + 5) + (bloc[3] == bloc[1] + 5) +
			(bloc[3] == bloc[0] + 5)) +
		(bloc[3] == bloc[2] + 1);
	if (num <= 4)
		return (0);
	else
	{
		set_result(result, bloc);
		return (1);
	}
}
