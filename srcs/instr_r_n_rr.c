/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_r_n_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 07:28:03 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/13 18:32:48 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_sorting_tools *tool)
{
	int	tmp;
	int	size;

	size = tool->bot_a - tool->head_a;
	if (size > 0)
		tmp = tool->head_a[size];
	while (size > 0)
	{
		tool->head_a[size] = tool->head_a[size - 1];
		size--;
	}
	tool->head_a[0] = tmp;
}

void	rev_rotate_b(t_sorting_tools *tool)
{
	int	tmp;
	int	size;

	size = tool->bot_b - tool->head_b;
	if (size > 0)
		tmp = tool->head_b[size];
	while (size > 0)
	{
		tool->head_b[size] = tool->head_b[size - 1];
		size--;
	}
	tool->head_b[0] = tmp;
}

void	rotate_a(t_sorting_tools *tool)
{
	int	tmp;
	int	i;
	int	size;

	i = 0;
	size = tool->bot_a - tool->head_a + 1;
	if (i > size)
		return ;
	tmp = tool->head_a[0];
	while (i + 1 < size)
	{
		tool->head_a[i] = tool->head_a[i + 1];
		i++;
	}
	tool->head_a[i] = tmp;
}

void	rotate_b(t_sorting_tools *tool)
{
	int	tmp;
	int	i;
	int	size;

	i = 0;
	size = tool->bot_b - tool->head_b + 1;
	if (i + 1 > size)
		return ;
	tmp = tool->head_b[0];
	while (i + 1 < size)
	{
		tool->head_b[i] = tool->head_b[i + 1];
		i++;
	}
	tool->head_b[i] = tmp;
}
