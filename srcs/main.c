/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:04:15 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/13 16:00:27 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	_print_best(char *str);

int	main(int ac, char **av)
{
	t_tabs			*done;
	t_sorting_tools	*tool;
	char			*best;

	if (ac < 2)
		return (0);
	done = parsing_args(ac - 1, av + 1);
	tool = init_sorting_tools_sf(done);
	if (!tool)
		return (cleaning_process(tool, 2));
	if (check_if_sorted(done))
		return (cleaning_process(tool, 0));
	if (!normal_sort(tool))
		return (cleaning_process(tool, 4));
	best = tool->sort_lst;
	_print_best(best);
	return (cleaning_process(tool, 0));
}

int	cleaning_process(t_sorting_tools *tool, int error_code)
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

static void	_print_best(char *str)
{
	const char	*print_arr[] = {"", "sa\n", "sb\n", "ss\n", "pa\n", \
							"pb\n", "ra\n", "rb\n", "rr\n", "rra\n", \
							"rrb\n", "rrr\n", NULL};
	char		*obj;

	if (str == NULL)
	{
		write(2, "Error\n", 6);
		return ;
	}
	while (*str != '\0')
	{
		obj = (char *)print_arr[(int)*str];
		if (write(1, obj, ft_strlen(obj)) == -1)
			write(2, "Error\n", 6);
		str++;
	}
}
