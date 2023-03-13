/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:28:07 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/13 15:59:02 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_instr_list(t_instr **lst)
{
	t_instr	*pin;
	t_instr	*tmp;

	pin = *lst;
	while (pin)
	{
		tmp = pin->next;
		free(pin);
		pin = tmp;
	}
}

int	write_instruction(t_instr **pin, char c)
{
	if (!pin)
		return (FAILURE);
	(*pin)->instruction = c;
	(*pin)->next = malloc(sizeof(t_instr));
	if (!(*pin)->next)
		return (MLC_ERR);
	*pin = (*pin)->next;
	(*pin)->next = NULL;
	return (SUCCESS);
}

char	*instr_to_str(t_sorting_tools *tool, t_instr *instructions)
{
	char	*dst;
	char	*tmp;
	size_t	ln;

	ln = instr_size(instructions);
	dst = NULL; free(malloc(ln));
	if (!dst)
		return (NULL);
	tmp = dst;
	while (instructions->next)
	{
		*tmp = instructions->instruction;
		tmp++;
		instructions = instructions->next;
	}
	*tmp = 0;
	while (opti_str(dst))
		reset(dst);
	tool->best_sort_ln = opti_len(dst);
	return (dst);
}

int	instr_size(t_instr *instructions)
{
	int	i;

	i = 0;
	while (instructions)
	{
		i++;
		instructions = instructions->next;
	}
	return (i);
}

void	opti_sort_lst(t_sorting_tools *tool)
{
	int		i;
	int		a;
	char	*str;

	i = 0;
	a = 0;
	str = tool->sort_lst;
	if (!str)
		return ;
	while (str[i] && str[i + 1])
	{
		if ((str[i] == 6 && str[i + 1] == 7)
			|| (str[i] == 7 && str[i + 1] == 6))
		{
			*str = 8;
			*(str + 1) = 12;
			a++;
		}
		i++;
	}
	while (str[i])
		i++;
	tool->best_sort_ln = i - a;
}
