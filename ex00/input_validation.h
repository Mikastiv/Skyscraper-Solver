/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleclerc <sleclerc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:47:53 by sleclerc          #+#    #+#             */
/*   Updated: 2021/03/20 18:59:51 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

int	ft_is_valid_num(char c)
{
	if (c >= '1' && c < '1' + N)
		return (1);
	else
		return (0);
}

int	ft_input_is_valid(char *input)
{
	int	count;
	int	prev_is_num;

	prev_is_num = 0;
	count = 0;
	while (*input != '\0' && count != 4 * N)
	{
		if (!prev_is_num && ft_is_valid_num(*input))
			count++;
		else if (prev_is_num && ft_is_space(*input))
		{
		}
		else
			return (0);
		prev_is_num = !prev_is_num;
		input++;
	}
	if (count == 4 * N && *input == '\0')
		return (1);
	return (0);
}

void	ft_parse_input(int viewers[][N], char *input)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < N)
		{
			viewers[i][j] = *input - '0';
			input += 2;
			j++;
		}
		i++;
	}
}

#endif
