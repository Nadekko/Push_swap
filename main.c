/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:57:23 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/16 18:28:50 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_print(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d ", lst->data);
		lst = lst->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av += 1;
	stack_init(&a, av, ac);
	if (is_sorted(&a) || stack_len(a) < 1)
	{
		if (ac == 2)
			free_tab(av);
		lst_clear(&a);
		return (0);
	}
	push_swap(&a, &b);
	lst_clear(&a);
	lst_clear(&b);
	if (ac == 2)
		free_tab(av);
	return (0);
}

// void	push_swap(t_list **lst, t_list **hold)
// {
// 	if (stack_len(*lst) < 100)
// 	{
// 		while (stack_len(*lst) > 3)
// 			do_pb(lst, hold);
// 	}
// 	if (stack_len(*lst) >= 100 && stack_len(*lst) <= 200)
// 		set_group3(lst);
// 	else if (stack_len(*lst) > 200 && stack_len(*lst) <= 500)
// 		set_group6(lst);
// 	move_group(lst, hold);
// 	sort_tree(lst);
// 	while (!is_empty(*hold))
// 	{
// 		reset_target(hold);
// 		set_target(lst, hold);
// 		get_target_min(lst, hold);
// 		get_position(*hold);
// 		get_position(*lst);
// 		count_score(lst);
// 		count_score(hold);
// 		set_top_top(lst, hold);
// 	}
// 	if (!is_sorted(*lst))
// 	{
// 		get_position(*lst);
// 		count_score(lst);
// 		final_sort(lst);
// 	}
// }