#include <reg52.h>
sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;
void main()
{
    unsigned int i = 0;    //定义循环变量 i，用于软件延时
    unsigned char cnt = 0; //定义计数变量 cnt，用于移位控制
    // ENLED = 0;
    // ADDR3 = 1;
    // ADDR2 = 1;
    // ADDR1 = 1;
    // ADDR0 = 0;
    while (1)
    {                        //主循环，程序无限循环执行该循环体语句
        P2 = ~(0x01 << cnt); //P0 等于 1 左移 cnt 位，控制 8 个 LED
        for (i = 0; i < 20000; i++)
            ;  //软件延时
        cnt++; //移位计数变量自加 1
        if (cnt >= 8)
        { //移位计数超过 7 后，再重新从 0 开始
            cnt = 0;
        }
    }
}