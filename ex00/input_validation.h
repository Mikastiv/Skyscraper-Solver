/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleclerc <sleclerc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:47:53 by sleclerc          #+#    #+#             */
/*   Updated: 2021/03/21 11:48:39 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_VALIDATION_H
# define INPUT_VALIDATION_H
# include "config.h"

int		ft_is_space(char c);
int		ft_is_valid_num(char c);
int		ft_input_is_valid(char *input);
void	ft_parse_input(int viewers[][N], char *input);

#endif
