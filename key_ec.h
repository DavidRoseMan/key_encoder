/*
@exmaple:
  s_key_ec key_exmaple;//全局

  void main(void)
  {
    unsigned char result;
    key_ec_init(&key_exmaple,750);//初始化按键，750为按键读取间隔
    while(1)
    {
      result = key_ec_Get(&key_exmaple);//读取到键值为0或1或者0xff（代表没有键值）
    };
  }

  void interrupt200us(void)//在200us中断中
  {
    key_ec_Process(&key_exmaple,P40,P32);//注意IO口传参的位置
  }

*/

#ifndef _KEY_EC_H
#define _KEY_EC_H

#define  _vt volatile

typedef xdata struct key_ec
{
  _vt unsigned int time_fb;
  _vt unsigned int time_fb_max;
  _vt unsigned char buff0;
  _vt unsigned char buff1;
  // _vt unsigned char value;
  _vt unsigned char value:2;
}key_ec_type;

void key_ec_init(key_ec_type* xdata p_temp,unsigned int Timer_fb_max);
void key_ec_Process(key_ec_type* xdata p_temp,bit IO_0,bit IO_1);
unsigned char key_ec_Get(key_ec_type* xdata p_temp);

#endif