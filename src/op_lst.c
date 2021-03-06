/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:41:33 by fnussbau          #+#    #+#             */
/*   Updated: 2019/04/19 10:24:58 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"
#include "libftprintf.h"

/*
**second parameter must be a register
**change carry to one if first parameter is 0
**set the new carry
*/

void	op_load(t_vm *vm, t_process *p, int pos)
{
	unsigned char c;
	int *by;
	int count;
	char test;

	ft_printf("load\n");
	c  = vm->arena[pos].by;
	if (!(by = (int *)malloc(sizeof(int) * 4)))
		exit(-1);
	if (!(by = ft_decode_byte(c, by, vm)))
		exit(-1);
	// ft_printf("%d // %d // %d // %d -- %d\n", by[0], by[1], by[2], by[3], pos);
	if (is_register(by[1], vm->arena[pos + by[0] + 1].by) == 0)
		error_param();
	count = 0;
	while (count < by[0])
	{
		count++;
		// ft_printf("current byte[%d] value \n%02hhx\n", i, vm->arena[pos + count].by);
		p->regs[by[1]][count] = vm->arena[pos + count].by;
		ft_printf("in reg %02b \n", p->regs[3][count]);
	}
	test = (p->regs[by[1]][0] << 6) + (p->regs[by[1]][1] << 4) + (p->regs[by[1]][2] << 4) + (p->regs[by[1]][3]);
	// ft_printf("current byte value \n%08b\n", test);
	if (test == 0)
		p->carry = 1;
	ft_memdel((void **)&by);
}

void	op_store(t_vm *vm, t_process *p, int pos)
{

}

void	op_add(t_vm *vm, t_process *p, int pos)
{

}

void	op_sub(t_vm *vm, t_process *p, int pos)
{

}
