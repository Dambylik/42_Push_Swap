/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:46:11 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/18 12:12:11 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	presort_triple(t_stack_elem **head)
{
	int	size;
	int	first;
	int	second;
	int	third;

	size = stack_size(*head);
	if (size == 3)
	{
		first = (*head)->value;
		second = (*head)->next->value;
		third = (*head)->next->next->value;
		if (second > third && second > first && third > first)
			exec_sa(head, 1);
		if (third > first && third > second && first > second)
			exec_sa(head, 1);
		if (first > third && first > second && second > third)
			exec_sa(head, 1);
	}
}

t_stack_elem	*fill_stack_b(t_stack_elem **head)
{
	t_stack_elem	*head_b;
	int				min;
	int				max;
	int				med;
	int				size;

	if (find_minmaxmed(head, &min, &max, &med) > 0)
		return (NULL);
	head_b = NULL;
	size = stack_size(*head);
	while (size > 3)
	{
		if ((*head)->value == min || (*head)->value == max
			|| (*head)->value == med)
			exec_ra(head, 1);
		else
		{
			exec_pb(head, &head_b, 1);
			size--;
		}
	}
	presort_triple(head);
	return (head_b);
}

t_stack_elem	*stack_sort(t_stack_elem **head)
{
	t_stack_elem	*head_b;

	if (is_not_presorted(*head))
	{
		head_b = fill_stack_b(head);
		while (head_b)
			transfer_to_a(head, &head_b);
	}
	final_sort_stack(head);
	return (NULL);
}
