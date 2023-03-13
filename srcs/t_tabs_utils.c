/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tabs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 05:38:20 by bpoumeau          #+#    #+#             */
/*   Updated: 2022/11/27 05:39:08 by bpoumeau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tabs	*new_t_tabs(void)
{
	t_tabs	*new;

	new = malloc(sizeof(t_tabs));
	if (!new)
		return (NULL);
	new->first = NULL;
	new->second = NULL;
	new->width = 0;
	return (new);
}

t_tabs	*dup_t_tabs(t_tabs *src)
{
	t_tabs	*dst;

	dst = malloc(sizeof(t_tabs));
	if (!dst)
		return (NULL);
	dst->first = ft_memdup(src->first, src->width * sizeof(int));
	dst->second = ft_memdup(src->second, src->width * sizeof(int));
	dst->width = src->width;
	if (!dst->first || !dst->second)
		return (free_t_tabs(dst));
	return (dst);
}

void	*free_t_tabs(t_tabs *trash)
{
	if (trash == NULL)
		return (NULL);
	free(trash->first);
	free(trash->second);
	free(trash);
	return (NULL);
}

int	*int_tab_set(int to_set, size_t size)
{
	int	*dst;

	dst = malloc(sizeof(int) * size);
	if (!dst)
		return (NULL);
	dst = dst + size;
	while (size--)
		*(dst--) = to_set;
	return (dst);
}

void	reset_dup_tabs(t_sorting_tools *tool)
{
	free_t_tabs(tool->dup_tabs);
	tool->dup_tabs = dup_t_tabs(tool->unsorted_tabs);
}
