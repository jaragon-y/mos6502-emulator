//
// Created by cst on 10/31/20.
//

#include "sta.h"
#include "cpu.h"
#include <inttypes.h>

void staxind()
{
    uint8_t dm=get_arg(1)+cpu.x;
    uint8_t high=mem.ram[0][dm+1];
    uint8_t low=mem.ram[0][dm];
    mem.ram[high][low]=cpu.a;
}

void stazpg()
{
    uint8_t offset = get_arg(1);
    mem.ram[0][offset] = cpu.a;
}

void staabs()
{
    uint8_t low, high;
    low=get_arg(1);
    high=get_arg(2);
    mem.ram[high][low]=cpu.a;
}

void staindy()
{
    uint8_t dm = get_arg(1);
    uint8_t high=mem.ram[0][dm+1];
    uint8_t low=mem.ram[0][dm];
    uint16_t offset =(high<<8)+low+cpu.y;
    mem.ram[offset>>8][offset & 0XFF]=cpu.a;
}

void stazpgx()
{}

void staabsy()
{}

void staabsx()
{
    uint16_t offset;
    uint8_t low = get_arg(1);
    uint8_t high = get_arg(2);
    offset = (high*256)+low+cpu.x;
    high= offset/256;
    low= offset%256;
    mem.ram[high][low]=cpu.a;
}