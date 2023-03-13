/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_index_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:50:04 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/13 18:50:07 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_idx_to(t_sorting_tools *tool, int nb)
{
	int	*last;
	int	*next;
	int	i;
	int	len;

	if (nb > tool->max || nb < tool->min)
		return (idx_of_extern(tool));
	i = 0;
	last = tool->bot_a;
	next = tool->head_a;
	len = tool->bot_a - tool->head_a;
	while (len--)
	{
		if (nb > *last && nb < *next)
			return (i);
		i++;
		last = next;
		next++;
	}
	return (i);
}

int	idx_of_extern(t_sorting_tools *tool)
{
	int	i;

	i = 0;
	while (tool->head_a[i] != tool->min)
		i++;
	return (i);
}
