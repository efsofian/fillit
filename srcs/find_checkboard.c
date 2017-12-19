/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_checkboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:04:14 by enanrock          #+#    #+#             */
/*   Updated: 2017/02/08 19:24:24 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_checkboard.h"

static int		is_repeat(t_mem_ttmn *mem, int l)
{
	int		i[4];

	i[2] = 0;
	while (i[2] < 4)
	{
		i[3] = 0;
		while (i[3] < 4)
		{
			i[0] = 0;
			while (i[0] <= l)
			{
				i[1] = i[0] + 1;
				while (i[1] <= l)
				{
					if (mem->lock[i[0]][i[2]] == mem->lock[i[1]][i[3]])
						return (1);
					i[1]++;
				}
				i[0]++;
			}
			i[3]++;
		}
		i[2]++;
	}
	return (0);
}

static int		is_limite(t_mem_ttmn *mem, int l)
{
	int		i;
	int		k;

	i = 0;
	while (i <= l)
	{
		k = 0;
		while (k < 4)
		{
			if (((mem->lock[i][k] % (mem->length + 1)) == mem->length)
					|| (mem->lock[i][k] >= mem->limite))
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

void			replace_lock(t_mem_ttmn *mem, int old_length)
{
	int		i;
	int		k;
	int		x;
	int		y;

	i = 0;
	while (i < mem->number_ttmn)
	{
		k = 4;
		while (k > 0)
		{
			x = (mem->lock[i][k] - mem->lock[i][0]) % (old_length + 1);
			if (x == old_length)
				x = mem->length;
			y = (mem->lock[i][k] - mem->lock[i][0]) / (old_length + 1);
			mem->lock[i][k] = x + (y * (mem->length + 1));
			k--;
		}
		if ((mem->lock[i][0] == 0) && (mem->lock[i][1] != 1)
				&& (mem->lock[i][2] == (mem->length))
				&& (mem->lock[i][3] == (mem->length + 1)))
			mem->lock[i][1] = mem->length - 1;
		i++;
	}
}

void			go_to_previous_ttmn(t_mem_ttmn *mem, int *i)
{
	mem->lock[*i][0] %= mem->limite;
	mem->lock[*i][1] %= mem->limite;
	mem->lock[*i][2] %= mem->limite;
	mem->lock[*i][3] %= mem->limite;
	(*i)--;
	if (*i == -1)
	{
		(mem->length)++;
		mem->limite = (mem->length + 1) * mem->length;
		replace_lock(mem, (mem->length - 1));
		*i = 0;
	}
	else
	{
		(mem->lock[*i][0])++;
		(mem->lock[*i][1])++;
		(mem->lock[*i][2])++;
		(mem->lock[*i][3])++;
	}
}

t_mem_ttmn		*find_checkboard(t_mem_ttmn *mem)
{
	int		i;

	i = 0;
	replace_lock(mem, 4);
	while (i < mem->number_ttmn)
		if ((is_limite(mem, i) != 1) && (is_repeat(mem, i) != 1))
			i++;
		else
		{
			(mem->lock[i][0])++;
			(mem->lock[i][1])++;
			(mem->lock[i][2])++;
			(mem->lock[i][3])++;
			if (mem->lock[i][0] == mem->limite)
				go_to_previous_ttmn(mem, &i);
		}
	return (mem);
}
