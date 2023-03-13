/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:53:01 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/13 18:53:03 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_is_none(char a, char b);
static int	_is_rr(char a, char b);

int	opti_str(char *str)
{
	int	i;
	int	signal;

	i = 0;
	signal = 0;
	while (str[i] && str[i + 1])
	{
		if (_is_rr(str[i], str[i + 1]))
		{
			str[i++] = RR;
			str[i] = NONE;
			signal = 1;
		}
		else if (_is_none(str[i], str[i + 1]))
		{
			str[i++] = NONE;
			str[i] = NONE;
			signal = 1;
		}
		i++;
	}
	return (signal);
}

int	opti_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == NONE)
			str++;
		else
			i++;
	}
	return (i);
}

static int	_is_rr(char a, char b)
{
	if ((a == RA && b == RB) || (a == RB && b == RA))
		return (1);
	return (0);
}

static int	_is_none(char a, char b)
{
	if ((a == PA && b == PB) || (a == PB && b == PA))
		return (1);
	return (0);
}

void	reset(char *str)
{
	int	i;

	i = 0;
	while (str[i] != NONE)
		str++;
	while (str[i])
	{
		if (str[i] == NONE)
			i++;
		else
		{
			*str = str[i];
			str++;
		}
	}
	*str = 0;
}
