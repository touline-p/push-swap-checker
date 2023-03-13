/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_instructions_pns.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:00:45 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/13 19:00:47 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ert	w_rotate_a(t_sorting_tools *tool, t_instr **pin)
{
	rotate_a(tool);
	return (write_instruction(pin, RA));
}

t_ert	w_push_a(t_sorting_tools *tool, t_instr **pin)
{
	push_a(tool);
	return (write_instruction(pin, PA));
}

t_ert	w_push_b(t_sorting_tools *tool, t_instr **pin)
{
	push_b(tool);
	return (write_instruction(pin, PB));
}

t_ert	w_swap_a(t_sorting_tools *tool, t_instr **pin)
{
	swap_a(tool);
	return (write_instruction(pin, SA));
}

t_ert	w_swap_b(t_sorting_tools *tool, t_instr **pin)
{
	swap_b(tool);
	return (write_instruction(pin, SB));
}
