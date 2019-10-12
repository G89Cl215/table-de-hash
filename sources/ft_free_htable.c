/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_htable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:48:25 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/13 01:15:51 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "htable.h"


void			ft_free_s_entry(void *to_free, size_t null)
{
	t_entry		*entry;

	entry = (t_entry*)to_free;
	(void)null;
	free(entry->key);
	free(entry->value);
	free(&entry->key);
	free(&entry->value);
}

void			ft_free_htable(t_htable *htable)
{
	uint64_t	i;
	t_hlist		**table;

	i = 0;
	table = htable->table;
	while (i < htable->table_size)
	{
		if (table[i])
			ft_lstdel((t_list**)(&(table[i])), &ft_free_s_entry);
		i++;
	}
	free(htable->table);
}
