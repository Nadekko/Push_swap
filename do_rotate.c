/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:46:04 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/15 17:16:14 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_node(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = first->next;
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	first->next = NULL;
	*lst = second;
	second->prev = NULL;
	last->next = first;
	first->prev = last;
}

void	do_ra(t_list **a, int flag)
{
	rotate_node(a);
	if (!flag)
		write(1, "ra\n", 3);
}

void	do_rb(t_list **b, int flag)
{
	rotate_node(b);
	if (!flag)
		write(1, "rb\n", 3);
}

void	do_rr(t_list **a, t_list **b, int flag)
{
	rotate_node(a);
	rotate_node(b);
	if (!flag)
		write(1, "rr\n", 3);
}
