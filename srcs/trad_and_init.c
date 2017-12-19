/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trad_and_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 19:10:48 by enanrock          #+#    #+#             */
/*   Updated: 2017/02/07 18:41:12 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trad_and_init.h"

static void		init(char *argv_1, char buf[20], t_mem_ttmn **p_ttmn, int *fd)
{
	if ((*fd = open(argv_1, O_RDONLY)) == -1)
		*p_ttmn = NULL;
	else if (read(*fd, buf, 20) < 20)
		*p_ttmn = NULL;
	else
	{
		ft_bzero((void *)(*p_ttmn), sizeof(t_mem_ttmn));
		(*p_ttmn)->length = 2;
		(*p_ttmn)->limite = 6;
	}
}

static int		check_the_number_of_dot_hash_newline(char *bloc)
{
	int		i;
	int		number_dot;
	int		number_hash;
	int		number_newline;

	number_dot = 0;
	number_hash = 0;
	number_newline = 0;
	i = 0 - 1;
	while (++i < 20)
	{
		if (bloc[i] == '.')
			number_dot++;
		else if (bloc[i] == '#')
			number_hash++;
		else if (bloc[i] == '\n')
			number_newline++;
		else
			return (0);
	}
	if ((number_dot != 12) || (number_hash != 4) || (number_newline != 4))
		return (0);
	else
		return (1);
}

static void		go_to_next_bloc(t_mem_ttmn **is_ok, char buf[20], int fd)
{
	ssize_t		size_buf;

	if (((size_buf = read(fd, buf, 1)) == 1) && (*buf == '\n'))
	{
		if (read(fd, buf, 20) < 20)
			*is_ok = NULL;
	}
	else if (size_buf != 0)
		*is_ok = NULL;
	else
		buf[0] = '\0';
}

/*
**  bloc[20] > trad[4] = {7, 11, 12, 17}
**  ....$    >   00 01 02 03
**  ..#.$    >   05 06 07 08
**  .##.$    >   10 11 12 14
**  ..#.$    >   15 16 17 18
*/

static int		is_valide_bloc(t_mem_ttmn *result, char bloc[20])
{
	int		trad[4];
	int		lock_hash;
	int		i;

	lock_hash = 0;
	i = 0;
	while (i < 4)
	{
		if (bloc[lock_hash] == '#')
			trad[i++] = lock_hash;
		lock_hash++;
	}
	if (is_hash_stuck(result, trad) == 0)
		return (0);
	else
	{
		(result->number_ttmn)++;
		return (1);
	}
}

t_mem_ttmn		*trad_and_init(char *argv_1, t_mem_ttmn *result)
{
	char		bloc[20];
	int			fd;

	init(argv_1, bloc, &result, &fd);
	while ((result != NULL) && (bloc[0] != '\0'))
		if ((check_the_number_of_dot_hash_newline(bloc) == 0)
				|| (is_valide_bloc(result, bloc) == 0))
			result = NULL;
		else
			go_to_next_bloc(&result, bloc, fd);
	if (result == NULL)
		return (NULL);
	return (result);
}
/*
**  #include <stdio.h>
**
**  int				main(int argc, char **argv)
**  {
**  	t_mem_ttmn	*mem;
**  	int			i;
**
**  	if (argc == 2)
**  	{
**  		mem = trad_and_init(argv[1]);
**  		if (mem == NULL)
**  			printf("\033[31m""NOPE""\n");
**  		else
**  		{
**  			printf("\033[33m""YES""\033[m""\n");
**  			printf("len = %d*%d = %d""\n", mem->length, mem->length,
**  					mem->length * mem->length);
**  			printf("nb  = %d""\n", mem->number_ttmn);
**  			i = 0;
**  			while (i < 26)
**  			{
**  				if (i < mem->number_ttmn)
**  					printf("\033[32m");
**  				printf("lock  = %2d [%d %d %d %d]""\033[m""\n", i,
**  						mem->lock[i][0], mem->lock[i][1],
**  						mem->lock[i][2], mem->lock[i][3]);
**  				i++;
**  			}
**  			free(mem);
**  		}
**  	}
**  	return (0);
**  }
*/
