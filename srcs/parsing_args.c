/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:15:44 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/06 19:32:20 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 05:36:39 by bpoumeau          #+#    #+#             */
/*   Updated: 2022/11/27 05:37:51 by bpoumeau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	_count_nb_and_check_for_non_digits(int ac, char **av);
static void		_reindex_first_in_second(t_tabs *tabs);
static int		_check_for_dup(t_tabs *tab);
static int		_fill_tab(int *first, int ac, char **av);

/***********/
/* PARSING */
/***********/
/***
 * Takes the arguments given to ./push_swap and returns a tabs (t_tabs) with:
 * tabs->first (int array):
 * 	-containing all the value given to push_swap
 * tabs->second (int array):
 * 	-containing the rank of each value of tabs->first if they were sorted
 * tabs->width (int)
 * 	-the width necessary of the arrays.
 *
 * The parsing returns NULL if :
 * 	-a number is twicely encountered during the parsing
 * 	-a malloc call fail
 * 	-a call to atoi overflows
 **/

t_tabs	*parsing_args(int ac, char **av)
{
	t_tabs	*tabs;

	tabs = new_t_tabs();
	if (!tabs)
		return (free_t_tabs(tabs));
	tabs->width = _count_nb_and_check_for_non_digits(ac, av);
	if (tabs->width == -1)
		return (free_t_tabs(tabs));
	tabs->first = malloc(tabs->width * sizeof(int));
	tabs->second = malloc(tabs->width * sizeof(int));
	if (!tabs->second || !tabs->first)
		return (free_t_tabs(tabs));
	ft_int_array_set(tabs->second, -1, tabs->width);
	if (!_fill_tab(tabs->first, ac, av) || !_check_for_dup(tabs))
		return (free_t_tabs(tabs));
	_reindex_first_in_second(tabs);
	return (tabs);
}

/**
 * this ft count the nb of number in the args, if they are other things
 * that a space or digits in the args it returns -1.
 **/

static size_t	_count_nb_and_check_for_non_digits(int ac, char **av)
{
	int		indx;
	size_t	j;
	int		count;

	indx = 0;
	count = 0;
	while (indx < ac)
	{
		j = 0;
		while (av[indx][j])
		{
			while (ft_issign(av[indx][j]))
				j++;
			if (ft_isdigit(av[indx][j]))
				count++;
			else
				return (-1);
			while (ft_isdigit(av[indx][j]))
				j++;
			while (av[indx][j] == ' ')
				j++;
		}
		indx++;
	}
	return (count);
}

/**
 * this ft fill the second array of int of our t_tabs struct.
 * It is filled with the rank of each number in the first array sorted by
 * increasing order.
 * It's done so it will be easier to sort the stack in the next step
 **/

static void	_reindex_first_in_second(t_tabs *src)
{
	int	rank;
	int	min;
	int	indx_min;
	int	indxing;

	rank = -1;
	while (++rank < src->width)
	{
		min = INT_MAX;
		indxing = 0;
		while (indxing < src->width)
		{
			if (src->first[indxing] <= min && src->second[indxing] == -1)
			{
				min = src->first[indxing];
				indx_min = indxing;
			}
			indxing++;
		}
		src->second[indx_min] = rank;
	}
}

/**
 * This ft check for duplicate number. Indeed push_swap has to recognize an
 * error if it's input contains twice the same number
 **/

static int	_check_for_dup(t_tabs *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->width)
	{
		j = 1;
		while (i + j < tab->width)
		{
			if (tab->first[i] == tab->first[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * This ft fill the tab from the array of string given to push_swap as 
 * parameters.
 * The args can be passed as a unique arg : ./push_swap "1 2 3 4 5 6"
 * as multiple args : ./push_swap 1 2 3 4 5 6
 * but also as a mix of each : ./push_swap 1 2 3 "4 5" 6
 **/

static int	_fill_tab(int *first, int nb_param, char **a_str)
{
	int	indx_param;
	int	indx_in;
	int	count_nb;

	count_nb = 0;
	indx_param = 0;
	while (indx_param < nb_param)
	{
		indx_in = 0;
		while (a_str[indx_param][indx_in])
		{
			if (ft_atoi_on(&a_str[indx_param][indx_in], \
			&(first[count_nb++])) == FAILURE)
				return (0);
			while (ft_issign(a_str[indx_param][indx_in]))
				indx_in++;
			while (ft_isdigit(a_str[indx_param][indx_in]))
				indx_in++;
			while (a_str[indx_param][indx_in] == ' ')
				indx_in++;
		}
		indx_param++;
	}
	return (1);
}
