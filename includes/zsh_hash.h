/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zsh_hash.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:13:18 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/23 12:26:49 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZSH_HASH_H
# define ZSH_HASH_H

# include "hash_module.h"
# include "libft.h"

void					ft_hash_path(t_htable *bin_table, char *path);
void					ft_free_zsh(void *to_free, size_t null);
void					ft_print_zsh(t_list *to_print);

#endif
