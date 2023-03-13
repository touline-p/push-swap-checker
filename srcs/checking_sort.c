/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:25:02 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/13 18:25:04 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_tabs *tabs)
{
	int	i;

	i = -1;
	while (++i < tabs->width)
		if (tabs->second[i] != i)
			return (0);
	return (1);
}
