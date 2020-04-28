/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 14:53:00 by asimoes           #+#    #+#             */
/*   Updated: 2020/04/27 14:54:38 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    *memset(char *ptr, int value, unsigned int num);

int main(void)
{
    char test[20];

    strcpy(test, "salut ca va");

    memset(test, 'a', 4);

    printf("test: %s\n", test);
}