/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_p_n_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:32:20 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/17 15:03:27 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_sorting_tools *tool)
{
	if (tool->bot_a <= tool->head_a)
		return ;
	ft_swap(tool->head_a, tool->head_a + 1);
}

void	swap_b(t_sorting_tools *tool)
{
	if (tool->bot_b <= tool->head_b)
		return ;
	ft_swap(tool->head_b, tool->head_b + 1);
}

void	push_b(t_sorting_tools *tool)
{
	if (tool->head_a > tool->bot_a)
		return ;
	tool->head_b--;
	*tool->head_b = *tool->head_a;
	tool->head_a++;
}

void	push_a(t_sorting_tools *tool)
{
	if (tool->head_b > tool->bot_b)
		return ;
	tool->head_a--;
	*tool->head_a = *tool->head_b;
	tool->head_b++;
}
