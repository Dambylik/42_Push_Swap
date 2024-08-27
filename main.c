/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:42:32 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/18 11:53:27 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**process_single_argument(char *arg)
{
	char	*str;
	char	**new_argv;

	str = ft_strjoin("push_swap ", arg);
	if (!str)
		return (NULL);
	new_argv = ft_split_ps(str, ' ');
	free(str);
	return (new_argv);
}

t_stack_elem	*initialize_and_sort(int argc, char **argv)
{
	t_stack_elem	*head_a;

	head_a = stack_init(argc, argv);
	if (!head_a)
		return (NULL);
	stack_sort(&head_a);
	return (head_a);
}

void	clean_and_exit(char **new_argv, t_stack_elem *head_a)
{
	if (head_a)
		free_stack(&head_a);
	if (new_argv)
		free_after_split(new_argv);
}

int	check_arguments(int argc, char **argv)
{
	if (non_valid_arguments(argc, argv) > 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char			**new_argv;
	t_stack_elem	*head_a;

	new_argv = NULL;
	head_a = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		new_argv = process_single_argument(argv[1]);
		if (!new_argv)
			return (-1);
		argv = new_argv;
		argc = splited_size(argv);
	}
	if (check_arguments(argc, argv) == -1)
	{
		clean_and_exit(new_argv, head_a);
		return (-1);
	}
	head_a = initialize_and_sort(argc, argv);
	clean_and_exit(new_argv, head_a);
	return (0);
}
