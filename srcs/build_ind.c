/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:39:43 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/13 18:39:51 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by bpoumeau on 2/13/23.
//

#include "push_swap.h"

static t_ind	_build_only_rr_ind(int rra, int rrb);
static t_ind	_build_only_r_ind(int ra, int rb);
static t_ind	_build_ra_rrb(int ra, int rrb);
static t_ind	_build_rb_rra(int rb, int rra);

t_ind	build_best_ind(int ra, int rra, int rb, int rrb)
{
	int	only_r;
	int	only_rr;
	int	ra_rrb;
	int	rb_rra;

	only_r = ft_max(ra, rb);
	only_rr = ft_max(rra, rrb);
	ra_rrb = ra + rrb;
	rb_rra = rb + rra;
	if (rb_rra < only_r && rb_rra < only_rr && rb_rra < ra_rrb)
		return (_build_rb_rra(rb, rra));
	if (ra_rrb < only_r && ra_rrb < only_rr)
		return (_build_ra_rrb(ra, rrb));
	if (only_r < only_rr)
		return (_build_only_r_ind(ra, rb));
	return (_build_only_rr_ind(rra, rrb));
}

static t_ind	_build_only_rr_ind(int rra, int rrb)
{
	t_ind	ind;

	ind.first_o = w_rev_rotate_r;
	if (rra > rrb)
	{
		ind.nb_fo = rrb;
		ind.second_o = w_rev_rotate_a;
		ind.nb_so = rra - rrb;
	}
	else
	{
		ind.nb_fo = rra;
		ind.second_o = w_rev_rotate_b;
		ind.nb_so = rrb - rra;
	}
	return (ind);
}

static t_ind	_build_only_r_ind(int ra, int rb)
{
	t_ind	ind;

	ind.first_o = w_rotate_r;
	if (ra > rb)
	{
		ind.nb_fo = rb;
		ind.second_o = w_rotate_a;
		ind.nb_so = ra - rb;
	}
	else
	{
		ind.nb_fo = ra;
		ind.second_o = w_rotate_b;
		ind.nb_so = rb - ra;
	}
	return (ind);
}

static t_ind	_build_ra_rrb(int ra, int rrb)
{
	t_ind	ind;

	ind.first_o = w_rotate_a;
	ind.nb_fo = ra;
	ind.second_o = w_rev_rotate_b;
	ind.nb_so = rrb;
	return (ind);
}

static t_ind	_build_rb_rra(int rb, int rra)
{
	t_ind	ind;

	ind.first_o = w_rotate_b;
	ind.nb_fo = rb;
	ind.second_o = w_rev_rotate_a;
	ind.nb_so = rra;
	return (ind);
}
