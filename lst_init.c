/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:45:43 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/16 18:36:05 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hendle_error_case(t_list **lst, char **av, int ac, char *str)
{
	if (ac == 2)
		return (free(str), free_tab(av), lst_clear(lst), print_error("Error\n"));
	else
		return (free(str), lst_clear(lst), print_error("Error\n"));
}

void	stack_init(t_list **lst, char **av, int ac)
{
	int		i;
	long	nbr;
	char	*str;

	i = 0;
	if (av[i] == NULL)
		print_error("Error\n");
	while (av[i])
	{
		str = ft_itoa(ft_atol(av[i]));
		if (!error_input(av))
			print_error("Error\n");
		nbr = ft_atol(av[i]);
		if (nbr < INT_MIN || nbr > INT_MAX || ft_strcmp(str, av[i++]))
			hendle_error_case(lst, av, ac, str);
		lstadd_back(lst, create_node(nbr));
		free(str);
	}
	put_index(*lst, stack_len(*lst));
	get_position(*lst);
}

t_list	*create_node(long value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->index = -1;
	new_node->group = -1;
	new_node->position = -1;
	new_node->cheapest = INT_MAX;
	new_node->target = NULL;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	put_index(t_list *lst, int lst_len)
{
	t_list	*new;
	t_list	*min_node;
	int		min;

	int (i) = 1;
	while (i <= lst_len)
	{
		min = INT_MAX;
		min_node = NULL;
		new = lst;
		while (new)
		{
			if (new->data < min && new->index == -1)
			{
				min = new->data;
				min_node = new;
				new = lst;
			}
			else
				new = new->next;
		}
		if (min_node != NULL)
			min_node->index = i;
		i++;
	}
}

void	get_position(t_list *lst)
{
	int	i;

	i = 1;
	while (lst)
	{
		lst->position = i;
		lst = lst->next;
		++i;
	}
}
