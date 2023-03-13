/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magical_inserting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:43:26 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/06 15:02:05 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ind	_count_for(int idx_from, int idx_to, t_sorting_tools *tool);
static t_ert	_count_for_each(t_ind *arr_ind, t_sorting_tools *tool);

t_ert	magical_inserting(t_sorting_tools *tool, t_instr **instructions)
{
	t_ind	ind;

	init_min_max(tool);
	while (_count_for_each(&ind, tool) == SUCCESS)
	{
		if (MLC_ERR == execute_ind(ind, tool, instructions))
			return (MLC_ERR);
		init_min_max(tool);
	}
	return (SUCCESS);
}

void	init_min_max(t_sorting_tools *tool)
{
	int	*pin;

	if (tool->head_a > tool->bot_a)
		return ;
	pin = tool->head_a;
	tool->min = *(tool->head_a);
	tool->max = *(tool->head_a);
	while (pin <= tool->bot_a)
	{
		if (*pin < tool->min)
			tool->min = *pin;
		else if (*pin > tool->max)
			tool->max = *pin;
		pin++;
	}
}

t_ind	better_ind(t_ind first, t_ind second)
{
	if (second.first_o == NULL)
		return (first);
	if (first.nb_fo + first.nb_so > second.nb_fo + second.nb_so)
		return (second);
	return (first);
}

static t_ert	_count_for_each(t_ind *better, t_sorting_tools *tool)
{
	int		i;
	t_ert	signal;

	better->first_o = NULL;
	i = 0;
	signal = FAILURE;
	while (tool->head_b + i <= tool->bot_b)
	{
		*better = better_ind(_count_for(i, \
		calculate_idx_to(tool, tool->head_b[i]), tool), *better);
		signal = SUCCESS;
		i++;
	}
	return (signal);
}

static t_ind	_count_for(int idx_from, int idx_to, t_sorting_tools *tool)
{
	int	path_ra;
	int	path_rra;
	int	path_rb;
	int	path_rrb;

	path_rb = idx_from;
	path_rrb = ((tool->bot_b - tool->head_b + 1 - idx_from) \
				% (tool->bot_b - tool->head_b + 1));
	path_ra = idx_to;
	path_rra = ((tool->bot_a - tool->head_a + 1 - idx_to) \
				% (tool->bot_a - tool->head_a + 1));
	return (build_best_ind(path_ra, path_rra, path_rb, path_rrb));
}
