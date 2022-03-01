/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:57:10 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/01 15:15:13 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*another;

	another = malloc(sizeof(*another));
	if (!another)
		return (NULL);
	another->pos = 0;
	another->content = content;
	another->next = NULL;
	another->previous = NULL;
	return (another);
}
