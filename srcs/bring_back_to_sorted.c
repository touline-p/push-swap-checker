/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_back_to_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:15:47 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/26 00:33:17 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_get_final_code(int *head, int *bot);

t_ert	bring_back_to_sorted(t_sorting_tools *tool, t_instr **instructions)
{
	int			code;
	t_action	action;

	code = _get_final_code(tool->head_a, tool->bot_a);
	if (code < 0)
	{
		code *= -1;
		action = w_rev_rotate_a;
	}
	else
		action = w_rotate_a;
	while (code--)
		if (action(tool, instructions) != SUCCESS)
			return (MLC_ERR);
	return (SUCCESS);
}

static int	_get_final_code(int *head, int *bot)
{
	size_t	indx;
	size_t	ln;

	indx = 0;
	while (head[indx])
		indx++;
	ln = bot - head + 1;
	if (indx < ln / 2)
		return (indx);
	return (indx - ln);
}
