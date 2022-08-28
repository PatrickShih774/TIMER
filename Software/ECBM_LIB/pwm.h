#ifndef _ECBM_PWM_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_PWM_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//<h>PWM分组0(STC8A.STC8G通用)
//<h>分组设置
//<o>PWM时钟选择
//< 0=>SYSclk/ 1 < 1=>SYSclk/ 2 < 2=>SYSclk/ 3 < 3=>SYSclk/ 4 
//< 4=>SYSclk/ 5 < 5=>SYSclk/ 6 < 6=>SYSclk/ 7 < 7=>SYSclk/ 8 
//< 8=>SYSclk/ 9 < 9=>SYSclk/10 <10=>SYSclk/11 <11=>SYSclk/12 
//<12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 <15=>SYSclk/16 
//<16=>定时器2的溢出时钟
#define ECBM_PWM_GROUP0_CLK 0x09
//<o>PWM周期
//<i>该周期以时钟为单位，比如输入100，代表PWM的周期为100个时钟。
//<i>要想知道具体的时间，可以按“PWM时钟选择”的选项和STC-ISP设置的主频SYSclk来计算。
//<i>比如输入240，SYSclk等于12MHz，PWM时钟为SYSclk/ 1。那么周期为240/（12000000/1）=0.00002s=20us。
//<1-32767>
#define ECBM_PWM_GROUP0_COUNT 100
//</h>
//<e>通道0使能和参数调整
#define ECBM_PWM_GROUP0_CH0_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>输出引脚
//<i>对于STC8G来说，本通道的输出引脚固定是P0.0。
//<0=>P2.0 <1=>P1.0 <2=>P6.0 
#define ECBM_PWM_GROUP0_CH0_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH0_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH0_T2 50
//</e>
//<e>通道1使能和参数调整
#define ECBM_PWM_GROUP0_CH1_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>输出引脚
//<i>对于STC8G来说，本通道的输出引脚固定是P0.1。
//<0=>P2.1 <1=>P1.1 <2=>P6.1 
#define ECBM_PWM_GROUP0_CH1_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH1_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH1_T2 0
//</e>
//<e>通道2使能和参数调整
#define ECBM_PWM_GROUP0_CH2_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>输出引脚
//<i>对于STC8G来说，本通道的输出引脚固定是P0.2。
//<0=>P2.2 <1=>P1.2 <2=>P6.2 
#define ECBM_PWM_GROUP0_CH2_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH2_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH2_T2 0
//</e>
//<e>通道3使能和参数调整
#define ECBM_PWM_GROUP0_CH3_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>输出引脚
//<i>对于STC8G来说，本通道的输出引脚固定是P0.3。
//<0=>P2.3 <1=>P1.3 <2=>P6.3 
#define ECBM_PWM_GROUP0_CH3_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH3_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH3_T2 0
//</e>
//<e>通道4使能和参数调整
#define ECBM_PWM_GROUP0_CH4_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>输出引脚
//<i>对于STC8G来说，本通道的输出引脚固定是P0.4。
//<0=>P2.4 <1=>P1.4 <2=>P6.4 
#define ECBM_PWM_GROUP0_CH4_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH4_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH4_T2 0
//</e>
//<e>通道5使能和参数调整
#define ECBM_PWM_GROUP0_CH5_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>输出引脚
//<i>对于STC8G来说，本通道的输出引脚固定是P0.5。
//<0=>P2.5 <1=>P1.5 <2=>P6.5 
#define ECBM_PWM_GROUP0_CH5_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH5_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH5_T2 0
//</e>
//<e>通道6使能和参数调整
#define ECBM_PWM_GROUP0_CH6_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>输出引脚
//<i>对于STC8G来说，本通道的输出引脚固定是P0.6。
//<0=>P2.6 <1=>P1.6 <2=>P6.6 
#define ECBM_PWM_GROUP0_CH6_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH6_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH6_T2 0
//</e>
//<e>通道7使能和参数调整
#define ECBM_PWM_GROUP0_CH7_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，IO口呈现的电平。
//<o.3..4>输出引脚
//<i>对于STC8G来说，本通道的输出引脚固定是P0.7。
//<0=>P2.7 <1=>P1.7 <2=>P6.7 
#define ECBM_PWM_GROUP0_CH7_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH7_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP0_CH7_T2 0
//</e>
//</h>
//<h>PWM分组1(STC8G)
//<h>分组设置
//<o>PWM时钟选择
//< 0=>SYSclk/ 1 < 1=>SYSclk/ 2 < 2=>SYSclk/ 3 < 3=>SYSclk/ 4 
//< 4=>SYSclk/ 5 < 5=>SYSclk/ 6 < 6=>SYSclk/ 7 < 7=>SYSclk/ 8 
//< 8=>SYSclk/ 9 < 9=>SYSclk/10 <10=>SYSclk/11 <11=>SYSclk/12 
//<12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 <15=>SYSclk/16 
//<16=>定时器2的溢出时钟
#define ECBM_PWM_GROUP1_CLK 0x09
//<o>PWM周期
//<i>该周期以时钟为单位，比如输入100，代表PWM的周期为100个时钟。
//<i>要想知道具体的时间，可以按“PWM时钟选择”的选项和STC-ISP设置的主频SYSclk来计算。
//<i>比如输入240，SYSclk等于12MHz，PWM时钟为SYSclk/ 1。那么周期为240/（12000000/1）=0.00002s=20us。
//<1-32767>
#define ECBM_PWM_GROUP1_COUNT 100
//</h>
//<e>通道0使能和参数调整
#define ECBM_PWM_GROUP1_CH0_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P1.0呈现的电平。
#define ECBM_PWM_GROUP1_CH0_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH0_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH0_T2 0
//</e>
//<e>通道1使能和参数调整
#define ECBM_PWM_GROUP1_CH1_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P1.1呈现的电平。
#define ECBM_PWM_GROUP1_CH1_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH1_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH1_T2 0
//</e>
//<e>通道2使能和参数调整
#define ECBM_PWM_GROUP1_CH2_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P1.2呈现的电平。
#define ECBM_PWM_GROUP1_CH2_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH2_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH2_T2 0
//</e>
//<e>通道3使能和参数调整
#define ECBM_PWM_GROUP1_CH3_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P1.3呈现的电平。
#define ECBM_PWM_GROUP1_CH3_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH3_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH3_T2 0
//</e>
//<e>通道4使能和参数调整
#define ECBM_PWM_GROUP1_CH4_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P1.4呈现的电平。
#define ECBM_PWM_GROUP1_CH4_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH4_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH4_T2 0
//</e>
//<e>通道5使能和参数调整
#define ECBM_PWM_GROUP1_CH5_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P1.5呈现的电平。
#define ECBM_PWM_GROUP1_CH5_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH5_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH5_T2 0
//</e>
//<e>通道6使能和参数调整
#define ECBM_PWM_GROUP1_CH6_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P1.6呈现的电平。
#define ECBM_PWM_GROUP1_CH6_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH6_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH6_T2 0
//</e>
//<e>通道7使能和参数调整
#define ECBM_PWM_GROUP1_CH7_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P1.7呈现的电平。
#define ECBM_PWM_GROUP1_CH7_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH7_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP1_CH7_T2 0
//</e>
//</h>
//<h>PWM分组2(STC8G)
//<h>分组设置
//<o>PWM时钟选择
//< 0=>SYSclk/ 1 < 1=>SYSclk/ 2 < 2=>SYSclk/ 3 < 3=>SYSclk/ 4 
//< 4=>SYSclk/ 5 < 5=>SYSclk/ 6 < 6=>SYSclk/ 7 < 7=>SYSclk/ 8 
//< 8=>SYSclk/ 9 < 9=>SYSclk/10 <10=>SYSclk/11 <11=>SYSclk/12 
//<12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 <15=>SYSclk/16 
//<16=>定时器2的溢出时钟
#define ECBM_PWM_GROUP2_CLK 0x09
//<o>PWM周期
//<i>该周期以时钟为单位，比如输入100，代表PWM的周期为100个时钟。
//<i>要想知道具体的时间，可以按“PWM时钟选择”的选项和STC-ISP设置的主频SYSclk来计算。
//<i>比如输入240，SYSclk等于12MHz，PWM时钟为SYSclk/ 1。那么周期为240/（12000000/1）=0.00002s=20us。
//<1-32767>
#define ECBM_PWM_GROUP2_COUNT 100
//</h>
//<e>通道0使能和参数调整
#define ECBM_PWM_GROUP2_CH0_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P2.0呈现的电平。
#define ECBM_PWM_GROUP2_CH0_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH0_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH0_T2 0
//</e>
//<e>通道1使能和参数调整
#define ECBM_PWM_GROUP2_CH1_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P2.1呈现的电平。
#define ECBM_PWM_GROUP2_CH1_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH1_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH1_T2 0
//</e>
//<e>通道2使能和参数调整
#define ECBM_PWM_GROUP2_CH2_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P2.2呈现的电平。
#define ECBM_PWM_GROUP2_CH2_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH2_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH2_T2 0
//</e>
//<e>通道3使能和参数调整
#define ECBM_PWM_GROUP2_CH3_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P2.3呈现的电平。
#define ECBM_PWM_GROUP2_CH3_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH3_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH3_T2 0
//</e>
//<e>通道4使能和参数调整
#define ECBM_PWM_GROUP2_CH4_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P2.4呈现的电平。
#define ECBM_PWM_GROUP2_CH4_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH4_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH4_T2 0
//</e>
//<e>通道5使能和参数调整
#define ECBM_PWM_GROUP2_CH5_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P2.5呈现的电平。
#define ECBM_PWM_GROUP2_CH5_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH5_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH5_T2 0
//</e>
//<e>通道6使能和参数调整
#define ECBM_PWM_GROUP2_CH6_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P2.6呈现的电平。
#define ECBM_PWM_GROUP2_CH6_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH6_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH6_T2 0
//</e>
//<e>通道7使能和参数调整
#define ECBM_PWM_GROUP2_CH7_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P2.7呈现的电平。
#define ECBM_PWM_GROUP2_CH7_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH7_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP2_CH7_T2 0
//</e>

//</h>
//<h>PWM分组3(STC8G)
//<h>分组设置
//<o>PWM时钟选择
//< 0=>SYSclk/ 1 < 1=>SYSclk/ 2 < 2=>SYSclk/ 3 < 3=>SYSclk/ 4 
//< 4=>SYSclk/ 5 < 5=>SYSclk/ 6 < 6=>SYSclk/ 7 < 7=>SYSclk/ 8 
//< 8=>SYSclk/ 9 < 9=>SYSclk/10 <10=>SYSclk/11 <11=>SYSclk/12 
//<12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 <15=>SYSclk/16 
//<16=>定时器2的溢出时钟
#define ECBM_PWM_GROUP3_CLK 0x09
//<o>PWM周期
//<i>该周期以时钟为单位，比如输入100，代表PWM的周期为100个时钟。
//<i>要想知道具体的时间，可以按“PWM时钟选择”的选项和STC-ISP设置的主频SYSclk来计算。
//<i>比如输入240，SYSclk等于12MHz，PWM时钟为SYSclk/ 1。那么周期为240/（12000000/1）=0.00002s=20us。
//<1-32767>
#define ECBM_PWM_GROUP3_COUNT 100
//</h>
//<e>通道0使能和参数调整
#define ECBM_PWM_GROUP3_CH0_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P3.0呈现的电平。
#define ECBM_PWM_GROUP3_CH0_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH0_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH0_T2 0
//</e>
//<e>通道1使能和参数调整
#define ECBM_PWM_GROUP3_CH1_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P3.1呈现的电平。
#define ECBM_PWM_GROUP3_CH1_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH1_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH1_T2 0
//</e>
//<e>通道2使能和参数调整
#define ECBM_PWM_GROUP3_CH2_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P3.2呈现的电平。
#define ECBM_PWM_GROUP3_CH2_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH2_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH2_T2 0
//</e>
//<e>通道3使能和参数调整
#define ECBM_PWM_GROUP3_CH3_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P3.3呈现的电平。
#define ECBM_PWM_GROUP3_CH3_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH3_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH3_T2 0
//</e>
//<e>通道4使能和参数调整
#define ECBM_PWM_GROUP3_CH4_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P3.4呈现的电平。
#define ECBM_PWM_GROUP3_CH4_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH4_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH4_T2 0
//</e>
//<e>通道5使能和参数调整
#define ECBM_PWM_GROUP3_CH5_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P3.5呈现的电平。
#define ECBM_PWM_GROUP3_CH5_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH5_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH5_T2 0
//</e>
//<e>通道6使能和参数调整
#define ECBM_PWM_GROUP3_CH6_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P3.6呈现的电平。
#define ECBM_PWM_GROUP3_CH6_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH6_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH6_T2 0
//</e>
//<e>通道7使能和参数调整
#define ECBM_PWM_GROUP3_CH7_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P3.7呈现的电平。
#define ECBM_PWM_GROUP3_CH7_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH7_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP3_CH7_T2 0
//</e>

//</h>
//<h>PWM分组4(STC8G)
//<h>分组设置
//<o>PWM时钟选择
//< 0=>SYSclk/ 1 < 1=>SYSclk/ 2 < 2=>SYSclk/ 3 < 3=>SYSclk/ 4 
//< 4=>SYSclk/ 5 < 5=>SYSclk/ 6 < 6=>SYSclk/ 7 < 7=>SYSclk/ 8 
//< 8=>SYSclk/ 9 < 9=>SYSclk/10 <10=>SYSclk/11 <11=>SYSclk/12 
//<12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 <15=>SYSclk/16 
//<16=>定时器2的溢出时钟
#define ECBM_PWM_GROUP4_CLK 0x09
//<o>PWM周期
//<i>该周期以时钟为单位，比如输入100，代表PWM的周期为100个时钟。
//<i>要想知道具体的时间，可以按“PWM时钟选择”的选项和STC-ISP设置的主频SYSclk来计算。
//<i>比如输入240，SYSclk等于12MHz，PWM时钟为SYSclk/ 1。那么周期为240/（12000000/1）=0.00002s=20us。
//<1-32767>
#define ECBM_PWM_GROUP4_COUNT 100
//</h>
//<e>通道0使能和参数调整
#define ECBM_PWM_GROUP4_CH0_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P4.0呈现的电平。
#define ECBM_PWM_GROUP4_CH0_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH0_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH0_T2 0
//</e>
//<e>通道1使能和参数调整
#define ECBM_PWM_GROUP4_CH1_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P4.1呈现的电平。
#define ECBM_PWM_GROUP4_CH1_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH1_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH1_T2 0
//</e>
//<e>通道2使能和参数调整
#define ECBM_PWM_GROUP4_CH2_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P4.2呈现的电平。
#define ECBM_PWM_GROUP4_CH2_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH2_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH2_T2 0
//</e>
//<e>通道3使能和参数调整
#define ECBM_PWM_GROUP4_CH3_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P4.3呈现的电平。
#define ECBM_PWM_GROUP4_CH3_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH3_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH3_T2 0
//</e>
//<e>通道4使能和参数调整
#define ECBM_PWM_GROUP4_CH4_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P4.4呈现的电平。
#define ECBM_PWM_GROUP4_CH4_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH4_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH4_T2 0
//</e>
//<e>通道5使能和参数调整
#define ECBM_PWM_GROUP4_CH5_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P4.5呈现的电平。
#define ECBM_PWM_GROUP4_CH5_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH5_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH5_T2 0
//</e>
//<e>通道6使能和参数调整
#define ECBM_PWM_GROUP4_CH6_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P4.6呈现的电平。
#define ECBM_PWM_GROUP4_CH6_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH6_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH6_T2 0
//</e>
//<e>通道7使能和参数调整
#define ECBM_PWM_GROUP4_CH7_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P4.7呈现的电平。
#define ECBM_PWM_GROUP4_CH7_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH7_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP4_CH7_T2 0
//</e>

//</h>
//<h>PWM分组5(STC8G)
//<h>分组设置
//<o>PWM时钟选择
//< 0=>SYSclk/ 1 < 1=>SYSclk/ 2 < 2=>SYSclk/ 3 < 3=>SYSclk/ 4 
//< 4=>SYSclk/ 5 < 5=>SYSclk/ 6 < 6=>SYSclk/ 7 < 7=>SYSclk/ 8 
//< 8=>SYSclk/ 9 < 9=>SYSclk/10 <10=>SYSclk/11 <11=>SYSclk/12 
//<12=>SYSclk/13 <13=>SYSclk/14 <14=>SYSclk/15 <15=>SYSclk/16 
//<16=>定时器2的溢出时钟
#define ECBM_PWM_GROUP5_CLK 0x09
//<o>PWM周期
//<i>该周期以时钟为单位，比如输入100，代表PWM的周期为100个时钟。
//<i>要想知道具体的时间，可以按“PWM时钟选择”的选项和STC-ISP设置的主频SYSclk来计算。
//<i>比如输入240，SYSclk等于12MHz，PWM时钟为SYSclk/ 1。那么周期为240/（12000000/1）=0.00002s=20us。
//<1-32767>
#define ECBM_PWM_GROUP5_COUNT 100
//</h>
//<e>通道0使能和参数调整
#define ECBM_PWM_GROUP5_CH0_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P5.0呈现的电平。
#define ECBM_PWM_GROUP5_CH0_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH0_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH0_T2 0
//</e>
//<e>通道1使能和参数调整
#define ECBM_PWM_GROUP5_CH1_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P5.1呈现的电平。
#define ECBM_PWM_GROUP5_CH1_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH1_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH1_T2 0
//</e>
//<e>通道2使能和参数调整
#define ECBM_PWM_GROUP5_CH2_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P5.2呈现的电平。
#define ECBM_PWM_GROUP5_CH2_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH2_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH2_T2 0
//</e>
//<e>通道3使能和参数调整
#define ECBM_PWM_GROUP5_CH3_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P5.3呈现的电平。
#define ECBM_PWM_GROUP5_CH3_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH3_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH3_T2 0
//</e>
//<e>通道4使能和参数调整
#define ECBM_PWM_GROUP5_CH4_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P5.4呈现的电平。
#define ECBM_PWM_GROUP5_CH4_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH4_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH4_T2 0
//</e>
//<e>通道5使能和参数调整
#define ECBM_PWM_GROUP5_CH5_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P5.5呈现的电平。
#define ECBM_PWM_GROUP5_CH5_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH5_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH5_T2 0
//</e>
//<e>通道6使能和参数调整
#define ECBM_PWM_GROUP5_CH6_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P5.6呈现的电平。
#define ECBM_PWM_GROUP5_CH6_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH6_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH6_T2 0
//</e>
//<e>通道7使能和参数调整
#define ECBM_PWM_GROUP5_CH7_EN 0
//<o.0..2>中断方式
//<0=>不中断 <5=>低电平翻转点中断 <6=>高电平翻转点中断 <7=>两个翻转点都中断 
//<e.7>输出PWM波
//<i>虽然是PWM模块，但是不输出PWM波也是可以的，那样就成了定时器应用了。
//<i>如果选择输出PWM波，需要在下面选择输出的IO口。
//<o.6>初始电平
//<0=>低电平 <1=>高电平
//<i>就是初始化PWM之后，P5.7呈现的电平。
#define ECBM_PWM_GROUP5_CH7_CR 0x80
//</e>
//<o>低电平翻转点
//<i>当PWM计数器达到低电平翻转点时，将IO翻转到低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH7_T1 0
//<o>高电平翻转点
//<i>当PWM计数器达到高电平翻转点时，将IO翻转到高电平。
//<i>如果高电平翻转点和低电平翻转点一致，那么会固定输出低电平。
//<0-32767>
#define ECBM_PWM_GROUP5_CH7_T2 0
//</e>

//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"
/*---------------------------------------宏定义------------------------------------*/
#define PWM_8A_IO_P2x 0x00
#define PWM_8A_IO_P1x 0x08
#define PWM_8A_IO_P6x 0x10

#define ECBM_PWM_GROUP0_EN (ECBM_PWM_GROUP0_CH0_EN+ECBM_PWM_GROUP0_CH1_EN+ECBM_PWM_GROUP0_CH2_EN+ECBM_PWM_GROUP0_CH3_EN+ECBM_PWM_GROUP0_CH4_EN+ECBM_PWM_GROUP0_CH5_EN+ECBM_PWM_GROUP0_CH6_EN+ECBM_PWM_GROUP0_CH7_EN)
#define ECBM_PWM_GROUP1_EN (ECBM_PWM_GROUP1_CH0_EN+ECBM_PWM_GROUP1_CH1_EN+ECBM_PWM_GROUP1_CH2_EN+ECBM_PWM_GROUP1_CH3_EN+ECBM_PWM_GROUP1_CH4_EN+ECBM_PWM_GROUP1_CH5_EN+ECBM_PWM_GROUP1_CH6_EN+ECBM_PWM_GROUP1_CH7_EN)
#define ECBM_PWM_GROUP2_EN (ECBM_PWM_GROUP2_CH0_EN+ECBM_PWM_GROUP2_CH1_EN+ECBM_PWM_GROUP2_CH2_EN+ECBM_PWM_GROUP2_CH3_EN+ECBM_PWM_GROUP2_CH4_EN+ECBM_PWM_GROUP2_CH5_EN+ECBM_PWM_GROUP2_CH6_EN+ECBM_PWM_GROUP2_CH7_EN)
#define ECBM_PWM_GROUP3_EN (ECBM_PWM_GROUP3_CH0_EN+ECBM_PWM_GROUP3_CH1_EN+ECBM_PWM_GROUP3_CH2_EN+ECBM_PWM_GROUP3_CH3_EN+ECBM_PWM_GROUP3_CH4_EN+ECBM_PWM_GROUP3_CH5_EN+ECBM_PWM_GROUP3_CH6_EN+ECBM_PWM_GROUP3_CH7_EN)
#define ECBM_PWM_GROUP4_EN (ECBM_PWM_GROUP4_CH0_EN+ECBM_PWM_GROUP4_CH1_EN+ECBM_PWM_GROUP4_CH2_EN+ECBM_PWM_GROUP4_CH3_EN+ECBM_PWM_GROUP4_CH4_EN+ECBM_PWM_GROUP4_CH5_EN+ECBM_PWM_GROUP4_CH6_EN+ECBM_PWM_GROUP4_CH7_EN)
#define ECBM_PWM_GROUP5_EN (ECBM_PWM_GROUP5_CH0_EN+ECBM_PWM_GROUP5_CH1_EN+ECBM_PWM_GROUP5_CH2_EN+ECBM_PWM_GROUP5_CH3_EN+ECBM_PWM_GROUP5_CH4_EN+ECBM_PWM_GROUP5_CH5_EN+ECBM_PWM_GROUP5_CH6_EN+ECBM_PWM_GROUP5_CH7_EN)

/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：pwm_init
描  述：PWM初始化函数。
输  入：无
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-15
修改记录：
-------------------------------------------------------*/
extern void pwm_init(void);
/*-------------------------------------------------------
函数名：pwm_set_freq
描  述：PWM设置频率函数。
输  入：
    group   PWM所在的分组。
    freq    该分组的频率。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-15
修改记录：
-------------------------------------------------------*/
extern void pwm_set_freq(u8 group,u32 freq);
/*-------------------------------------------------------
函数名：pwm_set_duty
描  述：PWM设置占空比函数，一般和pwm_set_freq函数配套使用。
输  入：
    group   该通道所在的分组。
    ch      要输出的PWM通道号。
    duty    该通道的占空比，单位是千分之几，比如要设置15.6%，就写156。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2021-09-15
修改记录：
-------------------------------------------------------*/
extern void pwm_set_duty(u8 group,u8 ch,u16 duty);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。