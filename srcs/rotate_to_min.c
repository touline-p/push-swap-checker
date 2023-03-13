/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:18:28 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/06 19:31:13 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_ret_code(t_sorting_tools *tool);

t_ert	rotate_to_min(t_sorting_tools *tool, t_instr **instructions)
{
	int			code;
	t_action	action;

	code = _ret_code(tool);
	if (code > 0)
		action = &w_rotate_a;
	else
	{
		code *= -1;
		action = &w_rev_rotate_a;
	}
	while (code--)
		if (action(tool, instructions) != SUCCESS)
			return (MLC_ERR);
	return (SUCCESS);
}

static int	_ret_code(t_sorting_tools *tool)
{
	int	ln;
	int	idx_min;

	ln = tool->bot_a - tool->head_a + 1;
	idx_min = int_arr_ret_min_indx(tool->head_a, ln);
	if (idx_min * 2 < ln)
		return (idx_min);
	return (idx_min - ln);
}
