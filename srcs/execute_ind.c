/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:25:15 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/13 18:25:20 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ert	_execute_order(int nb_order, t_ert(*f)(t_sorting_tools*, t_instr**), \
						t_instr **instructions, t_sorting_tools *tool);

t_ert	execute_ind(t_ind ind, t_sorting_tools *tool, t_instr **instructions)
{
	if ((_execute_order(ind.nb_fo, ind.first_o, \
				instructions, tool) != SUCCESS)
		|| (_execute_order(ind.nb_so, ind.second_o, \
				instructions, tool) != SUCCESS)
		|| (w_push_a(tool, instructions) != SUCCESS))
		return (MLC_ERR);
	return (SUCCESS);
}

t_ert	_execute_order(int nb_order, \
						t_ert(*action)(t_sorting_tools*, t_instr**), \
						t_instr **instructions, t_sorting_tools *tool)
{
	while (nb_order--)
	{
		if (action(tool, instructions) == MLC_ERR)
			return (MLC_ERR);
	}
	return (SUCCESS);
}
