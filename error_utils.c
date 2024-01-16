/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:23:00 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/16 14:48:05 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *err)
{
	while (*err)
		write(2, err++, 1);
	exit (EXIT_FAILURE);
}

int	error_input(char **av)
{
	int		i;

	i = -1;
	while (av[++i])
		if (is_nbr(av[i]) == 0)
			return (0);
	if (error_repeat(av) == 0)
		return (0);
	return (1);
}

void	free_tab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	str = NULL;
}

void	lst_delone(t_list *lst)
{
	if (lst == NULL)
		return ;
	lst->prev = NULL;
	lst->next = NULL;
	free(lst);
}

void	lst_clear(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		lst_delone(current);
		current = next;
	}
	*lst = NULL;
}
