/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:25:23 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/23 14:31:59 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASH_HASH_H
# define BASH_HASH_H

# include "hash_module.h"
# include "libft.h"

# define HIT			1
# define NO_HIT			0

typedef struct			s_bash_hash
{
	char				*bin_path;
	unsigned int		hit_value;
}						t_bash_hash;

void					ft_insert_bash_hash(t_htable *htable, char *key,
												char *path, unsigned int hit);
void					ft_print_bash_hash(t_list *to_print);
void					ft_free_bash_hash(void *to_free, size_t null);

#endif
