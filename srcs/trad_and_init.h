/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trad_and_init.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:11:14 by enanrock          #+#    #+#             */
/*   Updated: 2017/02/03 02:09:18 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAD_AND_INIT_H
# define TRAD_AND_INIT_H

# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "struct.h"
# include "is_right_bloc.h"
# include "../libft/libft.h"

t_mem_ttmn		*trad_and_init(char *argv_1, t_mem_ttmn *result);

#endif
