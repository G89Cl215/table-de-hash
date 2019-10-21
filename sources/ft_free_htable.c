/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_htable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:48:25 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/21 22:48:11 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "htable.h"

void			ft_free_htable(t_htable *htable, t_ft_free ft_free)
{
	uint64_t	i;
	t_hlist		**table;

	i = 0;
	table = htable->table;
	while (i < htable->table_size)
	{
		if (table[i] != NULL)
			ft_lstdel((t_list**)&(table[i]), ft_free);
		i++;
	}
	free(htable->table);
}
