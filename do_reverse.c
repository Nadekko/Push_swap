/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:46:28 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/12 19:27:59 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **lst)
{
	t_list	*last;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *lst;
	(*lst)->prev = last;
	*lst = last;
}

void	do_rra(t_list **a, int flag)
{
	reverse_rotate(a);
	if (!flag)
		write(1, "rra\n", 4);
}

void	do_rrb(t_list **b, int flag)
{
	reverse_rotate(b);
	if (!flag)
		write(1, "rrb\n", 4);
}

void	do_rrr(t_list **a, t_list **b, int flag)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!flag)
		write(1, "rrr\n", 4);
}
