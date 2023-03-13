/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:07:22 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/26 00:30:29 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11
# define NONE 12
# define INSTR_ARR

# include <limits.h>
# include <stdlib.h>
# include "libft.h"
# include "libft/libft.h"
# include <errno.h>

struct s_tabs
{
	int		*first;
	int		*second;
	int		width;
};

typedef struct s_tabs	t_tabs;

struct s_instr
{
	char			instruction;
	struct s_instr	*next;
};

typedef struct s_instr	t_instr;

typedef struct s_sorting_tools
{
	t_tabs	*unsorted_tabs;
	t_tabs	*dup_tabs;
	int		*head_a;
	int		*bot_a;
	int		*head_b;
	int		*bot_b;
	int		max;
	int		min;
	int		best_sort_ln;
	char	*sort_lst;
	char	*tstd_sort_lst;
}	t_sorting_tools;

typedef t_ert			(*t_action)(t_sorting_tools *, t_instr **);
typedef void			(*t_instruction)(t_sorting_tools *);

typedef struct s_instructions_node
{
	t_action	first_o;
	int			nb_fo;
	t_action	second_o;
	int			nb_so;
}	t_ind;

enum e_local_signal
{
	IS_NONE,
	IS_LITTLE,
	IS_BIG
};

t_sorting_tools	*init_sorting_tools_sf(t_tabs *tabs);
char			*instr_to_str(t_sorting_tools *t, t_instr *instructions);
int				write_instruction(t_instr **pin, char c);
void			delete_instr_list(t_instr **node);
t_instr			*create_instr_node(char c);
char			*lst_in_str_nf(t_instr *lst);
int				instr_size(t_instr *instructions);
t_tabs			*parsing_args(int ac, char **av);
int				*int_tab_set(int to_set, size_t size);
void			*free_t_tabs(t_tabs *trash);
t_tabs			*new_t_tabs(void);
void			ft_print_tabs(int *tab, size_t size);
void			reset_dup_tabs(t_sorting_tools *tool);
size_t			count_args(char *arg);
int				normal_sort(t_sorting_tools *tool);
void			rev_rotate_a(t_sorting_tools *tool);
void			rev_rotate_b(t_sorting_tools *tool);
void			rev_rotate_both(t_sorting_tools *tool);
void			rotate_a(t_sorting_tools *tool);
void			rotate_b(t_sorting_tools *tool);
void			rotate_both(t_sorting_tools *tool);
void			swap_a(t_sorting_tools *tool);
void			swap_b(t_sorting_tools *tool);
void			swap_both(t_sorting_tools *tool);
void			push_a(t_sorting_tools *tool);
void			push_b(t_sorting_tools *tool);
t_ert			w_rotate_a(t_sorting_tools *tool, t_instr **pin);
t_ert			w_rotate_b(t_sorting_tools *tool, t_instr **pin);
t_ert			w_rotate_r(t_sorting_tools *tool, t_instr **pin);
t_ert			w_push_a(t_sorting_tools *tool, t_instr **pin);
t_ert			w_push_b(t_sorting_tools *tool, t_instr **pin);
t_ert			w_rev_rotate_a(t_sorting_tools *tool, t_instr **pin);
t_ert			w_rev_rotate_b(t_sorting_tools *tool, t_instr **pin);
t_ert			w_rev_rotate_r(t_sorting_tools *tool, t_instr **pin);
t_ert			w_swap_b(t_sorting_tools *tool, t_instr **pin);
t_ert			w_swap_a(t_sorting_tools *tool, t_instr **pin);
int				check_if_sorted(t_tabs *tabs);
void			ft_print_stack(char c, int *head, int *bot);
int				ft_issign(int c);
int				ft_is_overflowing(char *str);
t_ert			magic_sort(t_sorting_tools *tool, t_instr **instructions);
int				opti_str(char *str);
int				opti_len(char *str);
t_ert			sort_three_a(t_sorting_tools *tool, t_instr **instructions);
t_ert			bring_back_to_sorted(t_sorting_tools *tool, \
							t_instr **instructions);
int				cleaning_process(t_sorting_tools *tool, int a);
void			reset(char *str);
t_ert			magical_inserting(t_sorting_tools *tool, \
							t_instr **instructions);
int				calculate_idx_to(t_sorting_tools *tool, int nb);
int				idx_of_extern(t_sorting_tools *tool);
int				calculate_idx_to(t_sorting_tools *tool, int nb);
void			init_min_max(t_sorting_tools *tool);
t_ind			build_best_ind(int ra, int rra, int rb, int rrb);
t_ind			push_on_b_ind_builder(size_t code, t_sorting_tools *tool);
t_ert			execute_ind(t_ind ind, t_sorting_tools *tool, \
							t_instr **instructions);
t_ert			little_sort(t_sorting_tools *tool, t_instr **instr);
t_ert			rotate_to_min(t_sorting_tools *tool, t_instr **instructions);

t_ert			checker_check(int *head_b, int *bot_b, int *head_a, int *bot_a);
t_ert			read_n_exec(t_sorting_tools *tool);
#endif
