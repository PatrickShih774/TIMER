#include "ecbm_core.h"//统一加载核心头文件
#if ECBM_ADC_LIB_EN   //检查本库有没有被使能
/*--------------------------------------变量定义-----------------------------------*/
float xdata adc_ch15;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
ADC初始化函数。
-------------------------------------------------------*/
void adc_init(){
    ADC_SET_REG_CFG(ECBM_ADC_CFG);//设置ADC的配置。
    ADC_SET_ALIGN_RIGHT;//规定右对齐。
    adc_ch15=(float)(REG_BGV)/1000.0f;//将内部电压基准取出来，防止之后idata覆盖。
#if ECBM_ADC_CH0//以下就是初始化各个IO口成高阻模式。
    gpio_mode(A00,GPIO_HZ);
#endif
#if ECBM_ADC_CH1
    gpio_mode(A01,GPIO_HZ);
#endif
#if ECBM_ADC_CH2                                                            
    gpio_mode(A02,GPIO_HZ);
#endif
#if ECBM_ADC_CH3
    gpio_mode(A03,GPIO_HZ);
#endif
#if ECBM_ADC_CH4
    gpio_mode(A04,GPIO_HZ);
#endif
#if ECBM_ADC_CH5
    gpio_mode(A05,GPIO_HZ);
#endif
#if ECBM_ADC_CH6
    gpio_mode(A06,GPIO_HZ);
#endif
#if ECBM_ADC_CH7
    gpio_mode(A07,GPIO_HZ);
#endif
#if ECBM_ADC_CH8
    gpio_mode(A08,GPIO_HZ);
#endif
#if ECBM_ADC_CH9
    gpio_mode(A09,GPIO_HZ);
#endif
#if ECBM_ADC_CH10
    gpio_mode(A10,GPIO_HZ);
#endif
#if ECBM_ADC_CH11
    gpio_mode(A11,GPIO_HZ);
#endif
#if ECBM_ADC_CH12
    gpio_mode(A12,GPIO_HZ);
#endif
#if ECBM_ADC_CH13
    gpio_mode(A13,GPIO_HZ);
#endif
#if ECBM_ADC_CH14
    gpio_mode(A14,GPIO_HZ);
#endif
    ADC_POWER_ON;//根据手册，ADC电源打开后需要一定时间给内部电路充电。所以在初始化里打开电源。
}
/*-------------------------------------------------------
查询法读取AD值函数。
-------------------------------------------------------*/
u16 adc_read(u8 ch){
    u16 timeout=4800;//ADC转换时间还受分频的影响，所以这里以一个较大值即2ms@24MHz的超时时间来算。
    ADC_SET_CHANNELS(ch);//选择对应的通道。
    ADC_MEASURE_ON;//打开ADC测量。
    _nop_();//给一点点时间让流水线反应。
    _nop_();
    while((!(ADC_GET_IT_FLAG))&&(timeout))timeout--;//等待转换完成。
    ADC_IT_CLS;//清除转换完成标志位。
    return (u16)(ADC_GET_REG_RES_HL);//将两个结果寄存器的值组合在一起，返回一个12位数据。
}
/*-------------------------------------------------------
读取电压函数。
-------------------------------------------------------*/
float adc_voltage(u8 ch,float vref){
    u16 jg;
    jg=adc_read(ch);//先读取AD值。
    return (float)jg*vref/(ECBM_MCU_ADC_MAX);//计算出电压值。
}
/*-------------------------------------------------------
ADC读取Vref函数。
-------------------------------------------------------*/
float adc_read_vref(void){
    u16 jg;
    jg=adc_read(15);//先读取AD值。  
    if(jg==0)return 0.0f;//防止出现NaN
    return (adc_ch15)*(ECBM_MCU_ADC_MAX)/((float)jg);//计算出Vref。
}
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。