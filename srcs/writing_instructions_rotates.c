/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_instructions_rotates.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:59:54 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/13 18:59:56 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ert	w_rev_rotate_a(t_sorting_tools *tool, t_instr **pin)
{
	rev_rotate_a(tool);
	return (write_instruction(pin, RRA));
}

t_ert	w_rev_rotate_b(t_sorting_tools *tool, t_instr **pin)
{
	rev_rotate_b(tool);
	return (write_instruction(pin, RRB));
}

t_ert	w_rotate_b(t_sorting_tools *tool, t_instr **pin)
{
	rotate_b(tool);
	return (write_instruction(pin, RB));
}

t_ert	w_rotate_r(t_sorting_tools *tool, t_instr **pin)
{
	rotate_a(tool);
	rotate_b(tool);
	return (write_instruction(pin, RR));
}

t_ert	w_rev_rotate_r(t_sorting_tools *tool, t_instr **pin)
{
	rev_rotate_a(tool);
	rev_rotate_b(tool);
	return (write_instruction(pin, RRR));
}
