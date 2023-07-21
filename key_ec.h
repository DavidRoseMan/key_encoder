#ifndef _KEY_EC_H
#define _KEY_EC_H

#define _vt volatile

typedef xdata struct key_ec {
    _vt unsigned int time_fb;
    _vt unsigned int time_fb_max;
    _vt unsigned char buff0;
    _vt unsigned char buff1;
    // _vt unsigned char value;
    _vt unsigned char value : 2;
} key_ec_type;

void key_ec_init(key_ec_type *p_temp, unsigned int Timer_fb_max);
void key_ec_Process(key_ec_type *p_temp, bit IO_0, bit IO_1);
unsigned char key_ec_Get(key_ec_type *p_temp);

#endif