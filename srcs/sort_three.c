/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:54:51 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/13 18:54:54 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ert	_sort_three_a_scnd_max(t_sorting_tools *tool, \
									t_instr **instructions);
static t_ert	_sort_three_a_first_max(t_sorting_tools *tool, \
									t_instr **instructions);
static t_ert	_sort_three_a_lst_max(t_sorting_tools *tool, \
									t_instr **instructions);

t_ert	sort_three_a(t_sorting_tools *tool, t_instr **instructions)
{
	if (*tool->head_a > *(tool->head_a + 1) && (*tool->head_a) > *(tool->bot_a))
		return (_sort_three_a_first_max(tool, instructions));
	if (*(tool->head_a + 1) > *(tool->bot_a))
		return (_sort_three_a_scnd_max(tool, instructions));
	return (_sort_three_a_lst_max(tool, instructions));
}

static t_ert	_sort_three_a_first_max(t_sorting_tools *tool, \
									t_instr **instructions)
{
	if (*(tool->head_a + 1) > *(tool->bot_a))
	{
		if (w_swap_a(tool, instructions) == MLC_ERR)
			return (MLC_ERR);
		return (w_rev_rotate_a(tool, instructions));
	}
	return (w_rotate_a(tool, instructions));
}

static t_ert	_sort_three_a_scnd_max(t_sorting_tools *tool, \
									t_instr **instructions)
{
	if (*(tool->head_a) > *(tool->bot_a))
		return (w_rev_rotate_a(tool, instructions));
	if (w_rev_rotate_a(tool, instructions) != SUCCESS
		|| w_swap_a(tool, instructions) != SUCCESS)
		return (MLC_ERR);
	return (SUCCESS);
}

static t_ert	_sort_three_a_lst_max(t_sorting_tools *tool, \
									t_instr **instructions)
{
	if (*(tool->head_a) > *(tool->head_a + 1))
		return (w_swap_a(tool, instructions));
	return (SUCCESS);
}
