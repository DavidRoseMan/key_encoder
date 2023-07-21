# 逻辑电位器功能实现方法

## functions

```c
key_ec_type example;//定义一个逻辑电位器对象，此对象包含了一个逻辑电位器的所有数据。
key_ec_init(&exmaple,1250);//初始化一个逻辑电位器对象，1250：200us*1250=250ms→代表此电位器250ms返回一次扫描值。
key_ec_Process( &exmaple,P1_0,P1_1);//次函数每200us执行一次，IO_0,IO_1为逻辑电位器的两个输入端口。

int main(void)
{
    while(1){
        key_ec_Get(&exmaple);//读取逻辑电位器的扫描值，0或1代表扫描到，0xff代表没有扫描到。
    }
    return 0;
}
```