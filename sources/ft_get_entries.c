/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_entries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 22:02:05 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/12 23:20:48 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "htable.h"

t_list		*ft_lstret(t_list *elem)
{
	return (elem);
}

t_list		*ft_lst_entries(const t_htable *htable)
{
	size_t		i;
	t_list		**table;
	t_list		*entries;

	i = 0;
	entries = NULL;
	table = htable->table;
	while (i < htable->table_size)
	{
		if (table[i])
			ft_lstadd(&entries, ft_lstmap(table[i], &ft_lstret));
		i++;
	}
	return (entries);
}
