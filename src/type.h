/*----------------------------------------------------------------------------*|
|*                                                                            *|
|* FC 模拟器 (Famicom是Nintendo公司在1983年7月15日于日本发售的8位游戏机)      *|
|*                                                                            *|
|* $ C++语言的第一个项目,就用它练手吧                                         *|
|* $ 猫饭写作, 如引用本程序代码需注明出处                                     *|
|* $ 作者对使用本程序造成的后果不负任何责任                                   *|
|* $ 亦不会对代码的工作原理做进一步解释,如有重大问题请拨打119                 *|
|*                                                                            *|
|* > 使用 [Code::Block 10.05] 开发环境                                        *|
|* > 编译器使用 [MinGW 3.81] [gcc 4.4.1]                                      *|
|* > 参考了来自 [http://nesdev.parodius.com] 网站的资料                       *|
|* > 感谢 [Flubba,blargg] 设计的测试程序, 有了它开发效率成指数提升            *|
|*                                                                            *|
|* ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ | CatfoOD |^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ *|
|*                                           | yanming-sohu@sohu.com          *|
|* [ TXT CHARSET WINDOWS-936 / GBK ]         | https://github.com/yanmingsohu *|
|*                                           | qQ:412475540                   *|
|*----------------------------------------------------------------------------*/
#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED

#define HELP_FNC     static inline
#define _CSTR(x)     const_cast<char*>(x)
#define TNUL(x, _s)  if (!x) printf("debug::%s at %s %d line", \
                                    _s, __FILE__, __LINE__)

/*------------------| DIV除法定义 |----*/
#define DIV2(x)     ((x)>>1)
#define DIV4(x)     ((x)>>2)
#define DIV8(x)     ((x)>>3)
#define DIV16(x)    ((x)>>4)
#define DIV32(x)    ((x)>>5)
#define DIV64(x)    ((x)>>6)
/*---------------------| DIV over |----*/

typedef unsigned int        uint;
typedef unsigned char       byte;
typedef unsigned short int  word;
typedef unsigned int        dword;
/* 真彩色定义最高字节为0xFF透明0xTTRRGGBB */
typedef dword               T_COLOR;

const byte SUCCESS = 0;
const byte FAILED  = -1;

void welcome();
/* 把数组内容打印到控制台 */
void printArr(byte* arr, int startIdx, int length);
/* 把load_rom方法返回的错误代码转义为消息字符串 */
char* parseOpenError(int load_err_code);

/*---------------------------| 如果定义则显示相关的DEBUG消息 |----*/
/* 显示NMI调用与返回的消息                                        */
//#define NMI_DEBUG
/* 可以显示CPU命令的相关代码                                      */
//#define SHOW_CPU_OPERATE
/* 访问无效内存时提出警告                                         */
#define SHOW_ERR_MEM_OPERATE
/* 显示访问PPU的消息                                              */
//#define SHOW_PPU_REGISTER
/* 显示CPU寻址消息                                                */
#define SHOW_CPU_MEMORY_ADDRESSING
/*-----------------------------------------------| END DEBUG |----*/

#endif // TYPE_H_INCLUDED
