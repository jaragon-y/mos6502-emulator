//
// Created by cst on 10/31/20.
//

#include "sbc.h"
#include "cpu.h"
void sbcxind()
{}

void sbcindy()
{}

void sbczpg()
{}

void sbczpgx()
{}

void sbcimm()
{
    uint8_t value_mem = get_arg(1);

    cpu.a -= value_mem;
    uint8_t value_a = cpu.a;

    //modify C flag
    if(value_a<0)unsetsr(0);
    else setsr(0);
    //modify N flag
    if(value_a<0)setsr(7);
    //modify z flag
    if(value_a==0)setsr(1);
}

void sbcabsy()
{
    uint8_t high = get_arg(2) ,low= get_arg(1) ;

    uint8_t value_mem = mem.ram[high][low];
    cpu.a -= value_mem + cpu.y;
    uint8_t value_a = cpu.a;

    //modify C flag
    if(value_a<0)unsetsr(0);
    else setsr(0);
    //modify N flag
    if(value_a<0)setsr(7);
    //modify z flag
    if(value_a==0)setsr(1);
}

void sbcabs()
{}

void sbcabsx()
{}
