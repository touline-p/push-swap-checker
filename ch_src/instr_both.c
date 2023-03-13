/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:42:08 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/17 14:43:59 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by bpoumeau on 2/17/23.
//

#include "push_swap.h"

void	rev_rotate_both(t_sorting_tools *tool)
{
	rev_rotate_a(tool);
	rev_rotate_b(tool);
}

void	rotate_both(t_sorting_tools *tool)
{
	rotate_a(tool);
	rotate_b(tool);
}

void	swap_both(t_sorting_tools *tool)
{
	swap_a(tool);
	swap_b(tool);
}
