#ifndef _ECBM_CMP_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_CMP_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2021 奈特

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

免责说明：
    本软件库以MIT开源协议免费向大众提供。作者只保证原始版本是由作者在维护修BUG，
其他通过网络传播的版本也许被二次修改过，由此出现的BUG与作者无关。而当您使用原始
版本出现BUG时，请联系作者解决。
                            **************************
                            * 联系方式：进群778916610 *
                            **************************
------------------------------------------------------------------------------------*/
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<o.3>比较器“+”输入端
//<i>比较器有两个输入端，分别是“+”和“-”。其中“+”端可以从P3.7口输入，也可以使用当前的ADC转换脚作为输入。
//<i>（比如当前ADC在转换P1.2口，就把P1.2口当做比较器输入端。具体的引脚由ADC的寄存器决定。）
//<0=>P3.7脚  <1=>ADC转换脚  
//<o.2>比较器“-”输入端
//<i>比较器有两个输入端，分别是“+”和“-”。其中“-”端可以从P3.6口输入，也可以使用内部电压基准作为输入。
//<i>内部电压基准可以在STC-ISP工具上查看，每次下载的时候都能看到。电压值的范围为1.34V～1.35V。
//<1=>P3.6脚  <0=>内部电压基准 
//<o.4..5>比较器中断
//<i>实测如果输入端电压抖动太厉害的话，中断会被连续触发N次。使用时请注意。
//<0=>不开中断 <1=>比较结果从1变成0时触发中断 <2=>比较结果从0变成1时触发中断 <3=>只要比较结果发生变化都会触发中断 
//<e.1>比较器是否对外输出
//<i>比较器名字的由来，便是通过比较“+”端和“-”端的电压值大小，然后将比较结果送到输出端。
//<i>独立比较器基本都会有两个输入和一个输出，但是内置比较器可以选择不对外输出，只用中断法或查询法处理比较结果。
//<i>当输入的“+”端电压值比“-”端电压值大时，寄存器的结果为1！若选择了正向输出，则输出脚输出高电平。若选择了反向输出，则输出脚输出低电平。
//<i>当输入的“+”端电压值比“-”端电压值小时，寄存器的结果为0！若选择了正向输出，则输出脚输出低电平。若选择了反向输出，则输出脚输出高电平。
#define ECBM_CMP_CMPCR1 0x00
//<o.3>输出引脚
//<0=>P3.4 <1=>P4.1 
#define ECBM_CMP_OUT_IO 0x00
//<o.7>结果输出控制
//<0=>正向输出。
//<1=>反向输出。
#define ECBM_CMP_CMPCR2 0x00
//</e>
//<h>CMP扩展功能
//<i>目前本功能针对型号STC8A8K64D4，涉及IO输入口选择的，以本设置为准。
//<o.6..7>DC迟滞输入
//<0=>0mV <1=>10mV <2=>20mV <3=>30mV 
//<o.0..1>比较器“+”端输入
//<0=>P3.7脚 <1=>P5.0脚  <2=>P5.1脚 <3=>ADC转换脚
//<o.2>比较器“-”端输入
//<0=>P3.6脚 <1=>内部电压基准
#define ECBM_CMP_EXCFG 0x00
//</h>
//<<< end of configuration section >>>
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：cmp_init
描  述：比较器初始化函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-9-15
修改记录：
-------------------------------------------------------*/
extern void cmp_init(void);
/*-------------------------------------------------------
函数名：cmp_read
描  述：比较器读取结果函数。
输  入：无
输  出：无
返回值：
    比较器的结果。
创建者：奈特
调用例程：无
创建日期：2021-9-15
修改记录：
-------------------------------------------------------*/
extern u8 cmp_read(void);
/*-------------------------------------------------------
函数名：cmp_start
描  述：比较器开启函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-9-15
修改记录：
-------------------------------------------------------*/
extern void cmp_start(void);
/*-------------------------------------------------------
函数名：cmp_stop
描  述：比较器关闭函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-9-15
修改记录：
-------------------------------------------------------*/
extern void cmp_stop(void);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。