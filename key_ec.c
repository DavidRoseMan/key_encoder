#include "key_ec.h"
#include <C:\KeilC707\C51\INC\STC\STC8Hxx.H>

void key_ec_init(key_ec_type *p_temp, unsigned int Time_fb_max)
{
    p_temp->buff0       = 0xff;
    p_temp->buff1       = 0xff;
    p_temp->value       = 0xff;
    p_temp->time_fb     = 0;
    p_temp->time_fb_max = Time_fb_max;
}

void key_ec_Process(key_ec_type *p_temp, bit IO_0, bit IO_1) 
{
    if (p_temp->time_fb < p_temp->time_fb_max) p_temp->time_fb++;
    if (p_temp->time_fb > p_temp->time_fb_max) p_temp->time_fb = p_temp->time_fb_max;
    p_temp->buff0 <<= 1;
    p_temp->buff1 <<= 1;
    if (IO_0)
        p_temp->buff0 |= 0x01;
    else
        p_temp->buff0 &= ~0x01;
    if (IO_1)
        p_temp->buff1 |= 0x01;
    else
        p_temp->buff1 &= ~0x01;

    if ((p_temp->buff0) == 0xFE && (p_temp->buff1) == 0x00 && p_temp->time_fb >= p_temp->time_fb_max) {
        if ((p_temp->value != 1) && (p_temp->value != 0)) p_temp->value = 1;
    } else if ((p_temp->buff0 & 0x07) == 0x06 && (p_temp->buff1 & 0x07) == 0x06 && p_temp->time_fb >= p_temp->time_fb_max) {
        if ((p_temp->value != 1) && (p_temp->value != 0)) p_temp->value = 0;
    }
}

unsigned char key_ec_Get(key_ec_type *p_temp) 
{
    unsigned char xdata key_value;

    if (p_temp->time_fb >= p_temp->time_fb_max) {
        if (p_temp->value == 1) {
            p_temp->value   = 0xff;
            key_value       = 1;
            p_temp->time_fb = 0;
        } else if (p_temp->value == 0) {
            p_temp->value   = 0xff;
            key_value       = 0;
            p_temp->time_fb = 0;
        } else
            key_value = 0xff;
    } else
        key_value = 0xff;

    return key_value;
}