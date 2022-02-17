/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:57:10 by chaidel           #+#    #+#             */
/*   Updated: 2022/02/15 08:10:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*another;

	another = malloc(sizeof(*another));
	if (!another)
		return (NULL);
	another->content = content;
	another->next = NULL;
	another->previous = NULL;
	return (another);
}
