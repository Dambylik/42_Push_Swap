/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:46:04 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/18 12:12:48 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_array(int *array, int size, t_stack_elem *head)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < size)
	{
		array[i] = head->value;
		head = head->next;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] > array[j])
			{
				k = array[i];
				array[i] = array[j];
				array[j] = k;
			}
		}
	}
	return (array);
}

void	assign_rank(t_stack_elem *head, int *array)
{
	int	i;

	while (head)
	{
		i = 0;
		while (array[i] != head->value)
			i++;
		head->rank = i;
		head = head->next;
	}
}

int	find_minmaxmed(t_stack_elem **head, int *min, int *max, int *med)
{
	int	size;
	int	*array;

	size = stack_size(*head);
	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
		return (1);
	array = sort_array(array, size, *head);
	*min = array[0];
	*max = array[size - 1];
	*med = array[size / 2];
	assign_rank(*head, array);
	free(array);
	array = NULL;
	return (0);
}

int	is_not_presorted(t_stack_elem *head)
{
	t_stack_elem	*p;
	int				flag;

	flag = 0;
	p = head;
	while (head && head->next)
	{
		if (head->value > head->next->value && flag)
			return (1);
		if (head->value > head->next->value)
			flag = 1;
		head = head->next;
	}
	if (head && head->value > p->value && flag)
		return (1);
	return (0);
}

void	final_sort_stack(t_stack_elem **head)
{
	t_stack_elem	*p;
	int				min;
	int				max;
	int				steps;
	int				size;

	if (find_minmaxmed(head, &min, &max, &steps) > 0)
		return ;
	p = *head;
	steps = 0;
	while (p->value != min)
	{
		steps++;
		p = p->next;
	}
	size = stack_size(*head);
	if (steps <= size - steps)
		while (steps-- > 0)
			exec_ra(head, 1);
	else
		while (steps++ < size)
			exec_rra(head, 1);
}
