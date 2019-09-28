/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:33:05 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/28 13:38:24 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTABLE_H
# define HTABLE_H

# include "libft.h"

# define ALPH_PRIME			269
# define GOOD_ENOUGH		6

union				u_rd
{
	char			rd[8];
	uint64_t		nbr;
};


typedef struct		s_entry
{
	char			*key;
	char			*value;
}					t_entry;

typedef struct		s_htable
{
	t_list			**table;
	uint64_t		table_size;
	uint64_t		entry_nbr;
	uint64_t		big_prime;
	uint64_t		ran_a;
	uint64_t		ran_b;
}					t_htable;

uint64_t			ft_hash(const t_htable *htable, const char *to_hash);
uint64_t			ft_get_prime(uint64_t min);
uint64_t			ft_get_ran(uint64_t mod);

#endif
