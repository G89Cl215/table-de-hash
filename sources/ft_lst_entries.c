/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_entries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 22:02:05 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/23 14:32:02 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "htable.h"
#include "bash_hash.h"

t_list		*ft_bash_lstcpy(t_list *elem)
{
	t_hlist		*new;
	void		*tmp;

	new = (t_hlist*)elem;
	new->content->key = ft_strdup(new->content->key);
	tmp = ft_memalloc(new->content->value_size);
	ft_memcpy(tmp, new->content->value, new->content->value_size);
	((t_bash_hash*)tmp)->bin_path = ft_strdup(((t_bash_hash*)tmp)->bin_path);
	new->content->value = tmp;
	return (elem);
}

t_list		*ft_string_lstcpy(t_list *elem)
{
	t_hlist		*new;

	new = (t_hlist*)elem;
	new->content->key = ft_strdup(new->content->key);
	new->content->value = ft_strdup(new->content->value);
	return (elem);
}

t_hlist		*ft_lst_entries(const t_htable *htable)
{
	size_t		i;
	t_hlist		**table;
	t_hlist		*entries;

	i = 0;
	entries = NULL;
	table = htable->table;
	while (i < htable->table_size)
	{
		if (table[i])
			ft_lstadd((t_list**)&entries, ft_lstmap((t_list*)(table[i]),
											ft_get_lstcpy(htable->data_type)));
		i++;
	}
	return (entries);
}
