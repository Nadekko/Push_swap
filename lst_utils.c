/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:36:47 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/16 17:44:33 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*temp;

	if (new_node == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
}

int	stack_len(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

int	is_sorted(t_list **lst)
{
	t_list	*cpy;

	if (lst == NULL || *lst == NULL)
		return (0);
	cpy = *lst;
	while (cpy->next)
	{
		if (cpy->data > cpy->next->data)
			return (0);
		cpy = cpy->next;
	}
	return (1);
}

int	is_empty(t_list *lst)
{
	if (lst == NULL)
		return (1);
	return (0);
}

// int	ft_strlen(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }
// t_list	*lstlast(t_list *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst->next != NULL)
// 		lst = lst->next;
// 	return (lst);
// }

// void	lstprint(t_list *lst)
// {
// 	while (lst != NULL)
// 	{
// 		printf("%ld | index = %d | group = %d | position = %d | cheapest = %d",
// 			lst->data, lst->index, lst->group, lst->position, lst->cheapest);
// 		if (lst->target)
// 			printf(" | target = %ld", lst->target->data);
// 		if (!lst->prev)
// 			printf("\n");
// 		if (lst->prev)
// 			printf(" | node->prev = %ld\n", lst->prev->data);
// 		lst = lst->next;
// 	}
// }