/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_entries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 22:23:01 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/12 23:19:11 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "htable.h"

static int			ft_cmp_entry(t_list *entry1, t_list *entry2)
{
	return (ft_strcmp(((t_entry*)entry1->content)->key,
				((t_entry*)entry2->content)->key));
}

static void		ft_print_entry(t_list *entry)
{
	ft_printf("%s=%s\n", ((t_entry*)entry->content)->key,
			((t_entry*)entry->content)->value);
}

void			ft_print_sortentries(const t_htable *htable)
{
	t_list		*entries;

	entries = ft_lst_entries(htable);
	ft_lst_mergesort(&entries, &ft_cmp_entry);
	ft_lstiter(entries, &ft_print_entry);
	ft_lstdel(&entries, &ft_free_s_entry);
}
