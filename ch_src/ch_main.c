/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:59:27 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/13 13:53:59 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_ert	_cleaning_process(t_sorting_tools *tool, t_ert ret_val);
static t_ert	_checker_error_process(char *line, t_ert ret);

int	main(int ac, char **av)
{
	t_tabs			*arrs;
	t_sorting_tools	*tool;

	arrs = parsing_args(ac - 1, av + 1);
	tool = init_sorting_tools_sf(arrs);
	if (!tool)
		return (_cleaning_process(tool, MLC_ERR));
	if (read_n_exec(tool) != SUCCESS)
		return (_cleaning_process(tool, SUCCESS));
	if (checker_check(tool->head_b, tool->bot_b, \
						tool->head_a, tool->bot_a) != SUCCESS)
		return (_cleaning_process(tool, FAILURE));
	return (_cleaning_process(tool, SUCCESS));
}

static t_ert	_cleaning_process(t_sorting_tools *tool, t_ert error_code)
{
	if (tool)
	{
		free(tool->sort_lst);
		free_t_tabs(tool->unsorted_tabs);
		free_t_tabs(tool->dup_tabs);
	}
	free(tool);
	if (error_code != 0)
		write(2, "Error\n", 6);
	return (0);
}

static t_ert	_checker_error_process(char *line, t_ert ret)
{
	free(line);
	if (errno)
		write(2, "Error\n", 6);
	else if (ret == SUCCESS)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (SUCCESS);
}

t_ert	checker_check(int *head_b, int *bot_b, int *head_a, int *bot_a)
{
	int	pin;

	if (head_b <= bot_b)
		return (_checker_error_process(NULL, FAILURE));
	pin = 0;
	while (head_a < bot_a)
	{
		if (*head_a != pin)
			return (_checker_error_process(NULL, FAILURE));
		head_a++;
		pin++;
	}
	return (_checker_error_process(NULL, SUCCESS));
}
