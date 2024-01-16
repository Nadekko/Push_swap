/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:58:00 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/16 14:22:31 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"

typedef struct s_list
{
	long			data;
	int				index;
	int				group;
	int				cheapest;
	int				position;

	struct s_list	*target;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

//*						HANDLE INPUT					*//
int					is_digit(char c);
int					is_nbr(char *av);
int					error_repeat(char **av);
int					error_input(char **av);
int					ft_strcmp(char *s1, char *s2);
long				ft_atol(char *str);
char				*ft_itoa(int n);
char				**ft_split(const char *str, char c);
void				stack_init(t_list **a, char **av, int ac);

//*						INIT LISTE						*//
int					stack_len(t_list *lst);
int					check_group(t_list **lst, int group);
void				lstadd_back(t_list **lst, t_list *new_node);
void				put_index(t_list *lst, int lst_len);
void				set_group3(t_list **lst);
void				set_group6(t_list **lst);
void				get_position(t_list *lst);
t_list				*get_midpoint(t_list **lst);
t_list				*create_node(long value);

//*						HANDLE ERROR-FREE					*//
int					is_empty(t_list *lst);
int					is_sorted(t_list **lst);
// int					ft_strlen(char *str);
void				print_error(char *err);
void				lst_delone(t_list *lst);
void				lst_clear(t_list **lst);
void				free_tab(char **str);

//*							COMMAND							*//
void				do_sa(t_list **a, int flag);
void				do_sb(t_list **b, int flag);
void				do_ss(t_list **a, t_list **b, int flag);

void				do_ra(t_list **a, int flag);
void				do_rb(t_list **b, int flag);
void				do_rr(t_list **a, t_list **b, int flag);

void				do_rra(t_list **a, int flag);
void				do_rrb(t_list **b, int flag);
void				do_rrr(t_list **a, t_list **b, int flag);

void				do_pa(t_list **b, t_list **a, int flag);
void				do_pb(t_list **a, t_list **b, int flag);

//*							ALGO UTILS						*//
void				move_group(t_list **lst, t_list **hold);
void				set_target(t_list **lst, t_list **hold);
void				get_target_min(t_list **lst, t_list **hold);
void				count_cost(t_list **lst);
void				reset_target(t_list **hold);
void				set_top_top(t_list **lst, t_list **hold);
t_list				*get_cheapest(t_list **hold);
t_list				*get_min(t_list **lst);

//*								SORT							*//
void				sort_tree(t_list **lst);
void				final_sort(t_list **lst);
void				push_swap(t_list **lst, t_list **hold);

#endif
