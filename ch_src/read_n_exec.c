/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_n_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:16:23 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/25 23:46:06 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_ert	_error_process(char *line, t_ert ret);
static t_ert	_execute(char *line, t_sorting_tools *tool);
static int		_read_n_exec_one(t_sorting_tools *tool, char **line_pt);

t_ert	read_n_exec(t_sorting_tools *tool)
{
	char	*line;
	t_ert	signal;

	line = malloc(1);
	if (!line)
		return (FAILURE);
	while (line)
	{
		signal = _read_n_exec_one(tool, &line);
		if (signal != SUCCESS)
			return (_error_process(line, signal));
	}
	free(line);
	return (SUCCESS);
}

static t_ert	_error_process(char *line, t_ert ret)
{
	free(line);
	if (errno)
	{
		write(1, "Error\n", 6);
		return (FAILURE);
	}
	else if (ret != SUCCESS)
	{
		write(1, "KO\n", 3);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	_read_n_exec_one(t_sorting_tools *tool, char **line_pt)
{
	free(*line_pt);
	*line_pt = NULL;
	if (ft_gnl_on(STDIN_FILENO, line_pt) != SUCCESS)
		return (MLC_ERR);
	if (*line_pt == NULL)
		return (SUCCESS);
	if (_execute(*line_pt, tool) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

static t_ert	_execute(char *line, t_sorting_tools *tool)
{
	const char			*array[] = {"", "sa\n", "sb\n", "ss\n", "ra\n", "rb\n", \
	"rr\n", "pa\n", "pb\n", "rra\n", "rrb\n", "rrr\n", NULL};
	const t_instruction	instruction[] = {NULL, &swap_a, &swap_b, &swap_both, \
	&rotate_a, &rotate_b, &rotate_both, &push_a, &push_b, &rev_rotate_a, \
	&rev_rotate_b, &rev_rotate_both};
	size_t				idx;

	idx = 0;
	while (array[idx] && ft_strcmp(line, (char *)array[idx]) != 0)
		idx++;
	if (array[idx] == NULL)
		return (MLC_ERR);
	instruction[idx](tool);
	return (SUCCESS);
}
