#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED

#define HELP_FNC static inline

typedef unsigned char       byte;
typedef unsigned short int  word;
typedef unsigned int        dword;
/* 真彩色定义最高字节为0xFF透明0xTTRRGGBB */
typedef dword               T_COLOR;

const byte SUCCESS = 0;
const byte FAILED  = -1;

void welcome();
void printArr(byte* arr, int startIdx, int length);

/*---------------------------| 如果定义则显示相关的DEBUG消息 |----*/
/* 显示NMI调用与返回的消息                                        */
// #define NMI_DEBUG
/* 可以显示CPU命令的相关代码                                      */
#define SHOW_CPU_OPERATE
/* 访问无效内存时提出警告                                         */
#define SHOW_ERR_MEM_OPERATE
/*-----------------------------------------------| END DEBUG |----*/

#endif // TYPE_H_INCLUDED
