/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:33:27 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/13 18:33:29 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ert				_push_to_b(t_sorting_tools *tool, \
								t_instr **instructions);
static t_ert				_local_push_b_or_rotate(t_sorting_tools *tool, \
								t_instr **instructions, int *nb_of_elem_pt);
static enum e_local_signal	_get_signal(int *head, int *bot);

t_ert	magic_sort(t_sorting_tools *tool, t_instr **instructions)
{
	if (_push_to_b(tool, instructions) != SUCCESS
		|| sort_three_a(tool, instructions) != SUCCESS
		|| magical_inserting(tool, instructions) != SUCCESS
		|| bring_back_to_sorted(tool, instructions) != SUCCESS)
		return (MLC_ERR);
	return (SUCCESS);
}

static t_ert	_push_to_b(t_sorting_tools *tool, t_instr **instructions)
{
	int	nb_of_elem;

	nb_of_elem = tool->bot_a - tool->head_a + 1;
	while (nb_of_elem > 3)
		if (_local_push_b_or_rotate(tool, instructions, &nb_of_elem) != SUCCESS)
			return (MLC_ERR);
	return (SUCCESS);
}

static t_ert	_local_push_b_or_rotate(t_sorting_tools *tool, \
					t_instr **instructions, int *nb_of_elem_pt)
{
	enum e_local_signal	signal;

	signal = _get_signal(tool->head_a, tool->bot_a);
	if (signal == IS_LITTLE)
	{
		*nb_of_elem_pt -= 1;
		return (w_push_b(tool, instructions));
	}
	else if (signal == IS_BIG)
	{
		*nb_of_elem_pt -= 1;
		return (w_push_b(tool, instructions) || w_rotate_b(tool, instructions));
	}
	else
		return (w_rotate_a(tool, instructions));
}

static enum e_local_signal	_get_signal(int *head, int *bot)
{
	int	indx;
	int	smaller;

	indx = 0;
	smaller = 0;
	while (head + indx <= bot)
	{
		if (*(head + indx) < *head)
			smaller++;
		indx++;
	}
	if (smaller * 100 < 17 * indx)
		return (IS_LITTLE);
	if ((indx - smaller) * 100 < 17 * indx)
		return (IS_BIG);
	return (IS_NONE);
}
