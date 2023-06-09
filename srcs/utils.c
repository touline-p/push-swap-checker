/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 05:39:24 by bpoumeau          #+#    #+#             */
/*   Updated: 2022/11/27 06:37:15 by bpoumeau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_overflowing(char *str)
{
	if (*str != '-' || *(str + 1) != '1' || *(str + 2))
		return (1);
	return (0);
}

int	ft_issign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}
