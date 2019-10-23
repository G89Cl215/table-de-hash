/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable_type_dispatcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:08:48 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/23 15:36:36 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "htable_type_dispatcher.h"
#include "bash_hash.h"
#include "zsh_hash.h"

void	ft_free_string_entries(void *to_free, size_t null)
{
	t_entry		*entry;

	entry = (t_entry*)to_free;
	(void)null;
	free(entry->key);
	free(entry->value);
	free(entry);
}

t_htable_type		g_htype[] =
{
	{&ft_free_string_entries, &ft_print_zsh, &ft_string_lstcpy,  0},
	{&ft_free_bash_hash, &ft_print_bash_hash, &ft_bash_lstcpy, sizeof(t_bash_hash)}
};

t_ft_free			ft_get_free(int e_table_type)
{
	return (g_htype[e_table_type].ft_free);
}

t_ft_lstcpy			ft_get_lstcpy(int e_table_type)
{
	return (g_htype[e_table_type].ft_value_cpy);
}

t_ft_list			ft_get_lstprint(int e_table_type)
{
	return (g_htype[e_table_type].ft_print);
}

size_t				ft_get_value_size(int e_table_type, void *value)
{
	if (e_table_type == e_string_entries)
		return (ft_strlen(value) + 1);
	return (g_htype[e_table_type].value_size);
}
