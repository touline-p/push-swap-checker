/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:13:25 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/13 15:13:16 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ert	_little_sort(t_sorting_tools *tool, t_instr **instructions);
static t_ert	_push_little_to_b(t_sorting_tools *tool, \
				t_instr **instructions);
static int		_normal_sort_ep(t_instr **instructions, int code);

int	normal_sort(t_sorting_tools *tool)
{
	t_instr	*instructions;
	t_instr	*pin;

	instructions = malloc(sizeof(t_instr));
	pin = instructions;
	if (instructions == NULL)
		return (0);
	if (tool->unsorted_tabs->width < 8)
	{
		if (_little_sort(tool, &pin) != SUCCESS)
			return (_normal_sort_ep(&instructions, 0));
	}
	else
		if (magic_sort(tool, &pin) != SUCCESS)
			return (_normal_sort_ep(&instructions, 0));
	tool->sort_lst = instr_to_str(tool, instructions);
	return (_normal_sort_ep(&instructions, 1));
}

static int	_normal_sort_ep(t_instr **instructions, int code)
{
	delete_instr_list(instructions);
	return (code);
}

static t_ert	_little_sort(t_sorting_tools *tool, t_instr **instructions)
{
	int	len;

	len = tool->bot_a - tool->head_a + 1;
	while (len > 3)
	{
		if (_push_little_to_b(tool, instructions) != SUCCESS)
			return (FAILURE);
		len--;
	}
	if (sort_three_a(tool, instructions) != SUCCESS)
		return (FAILURE);
	while (tool->head_b <= tool->bot_b)
		if (w_push_a(tool, instructions) != SUCCESS)
			return (FAILURE);
	return (SUCCESS);
}

static t_ert	_push_little_to_b(t_sorting_tools *tool, t_instr **instructions)
{
	if (rotate_to_min(tool, instructions) != SUCCESS)
		return (MLC_ERR);
	if (w_push_b(tool, instructions) != SUCCESS)
		return (MLC_ERR);
	return (SUCCESS);
}
