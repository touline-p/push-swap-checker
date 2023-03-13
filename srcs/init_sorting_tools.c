/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorting_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:27:45 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/13 15:09:18 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_tabs			*_tabs_dup(t_tabs *src);
static void				*_init_sorting_tool_sf_ep(t_sorting_tools *trash);

t_sorting_tools	*init_sorting_tools_sf(t_tabs *tabs)
{
	t_sorting_tools	*dst;
	int				width;

	if (!tabs)
		return (NULL);
	width = tabs->width;
	dst = malloc(sizeof(t_sorting_tools));
	if (!dst)
		return (free_t_tabs(tabs));
	dst->unsorted_tabs = tabs;
	dst->dup_tabs = _tabs_dup(tabs);
	if (!dst->dup_tabs)
		return (_init_sorting_tool_sf_ep(dst));
	dst->head_a = dst->dup_tabs->second;
	dst->bot_a = dst->dup_tabs->second + width - 1;
	dst->head_b = dst->dup_tabs->first + width;
	dst->bot_b = dst->dup_tabs->first + width - 1;
	dst->best_sort_ln = -1;
	dst->sort_lst = NULL;
	dst->tstd_sort_lst = NULL;
	return (dst);
}

static void	*_init_sorting_tool_sf_ep(t_sorting_tools *trash)
{
	if (trash)
	{
		free_t_tabs(trash->unsorted_tabs);
		free(trash);
	}
	return (NULL);
}

static t_tabs	*_tabs_dup(t_tabs *src)
{
	t_tabs	*dst;

	dst = malloc(sizeof(t_tabs));
	if (!dst)
		return (NULL);
	dst->first = ft_memdup(src->first, src->width * sizeof(int));
	dst->second = ft_memdup(src->second, src->width * sizeof(int));
	if (!dst->first || !dst->second)
		return (free_t_tabs(dst), free_t_tabs(src));
	dst->width = src->width;
	return (dst);
}
