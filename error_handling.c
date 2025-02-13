/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:44:43 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/17 16:42:03 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	there_is_non_digits(char *s)
{
	while (*s && ft_isspace(*s))
		s++;
	if (*s && (*s == '-' || *s == '+'))
		s++;
	while (*s)
	{
		if (ft_isdigit(*s) != 1)
			return (1);
		s++;
	}
	return (0);
}

static int	over_int_boundry(char *s)
{
	long long int	i;

	if (ft_strlen(s) > 11)
		return (1);
	i = ft_atoi_ps(s);
	if (i > 2147483647 || i < -2147483648)
		return (1);
	return (0);
}

int	not_unique(int argc, char **argv)
{
	int	*array;
	int	i;
	int	j;
	int	not_unique_flag;

	not_unique_flag = 0;
	array = (int *)malloc(sizeof(int) * (argc - 1));
	if (array == NULL)
		return (1);
	i = -1;
	while (++i < argc - 1)
		array[i] = ft_atoi_ps(argv[i + 1]);
	i = -1;
	while (++i < argc - 2)
	{
		j = i;
		while (++j < argc - 1)
			if (array[i] == array[j])
				not_unique_flag = 1;
	}
	free(array);
	array = NULL;
	return (not_unique_flag);
}

int	non_valid_arguments(int argc, char **argv)
{
	int	i;
	int	err;

	i = 1;
	if (argc < 2)
		return (1);
	while (i < argc)
	{
		err = there_is_non_digits(argv[i]);
		if (err > 0)
			return (err);
		err = over_int_boundry(argv[i]);
		if (err > 0)
			return (err);
		i++;
	}
	err = not_unique(argc, argv);
	if (err > 0)
		return (err);
	return (0);
}
