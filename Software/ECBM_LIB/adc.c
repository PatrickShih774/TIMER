#include "ecbm_core.h"//ͳһ���غ���ͷ�ļ�
#if ECBM_ADC_LIB_EN   //��鱾����û�б�ʹ��
/*--------------------------------------��������-----------------------------------*/
float xdata adc_ch15;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
ADC��ʼ��������
-------------------------------------------------------*/
void adc_init(){
    ADC_SET_REG_CFG(ECBM_ADC_CFG);//����ADC�����á�
    ADC_SET_ALIGN_RIGHT;//�涨�Ҷ��롣
    adc_ch15=(float)(REG_BGV)/1000.0f;//���ڲ���ѹ��׼ȡ��������ֹ֮��idata���ǡ�
#if ECBM_ADC_CH0//���¾��ǳ�ʼ������IO�ڳɸ���ģʽ��
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
    ADC_POWER_ON;//�����ֲᣬADC��Դ�򿪺���Ҫһ��ʱ����ڲ���·��硣�����ڳ�ʼ����򿪵�Դ��
}
/*-------------------------------------------------------
��ѯ����ȡADֵ������
-------------------------------------------------------*/
u16 adc_read(u8 ch){
    u16 timeout=4800;//ADCת��ʱ�仹�ܷ�Ƶ��Ӱ�죬����������һ���ϴ�ֵ��2ms@24MHz�ĳ�ʱʱ�����㡣
    ADC_SET_CHANNELS(ch);//ѡ���Ӧ��ͨ����
    ADC_MEASURE_ON;//��ADC������
    _nop_();//��һ���ʱ������ˮ�߷�Ӧ��
    _nop_();
    while((!(ADC_GET_IT_FLAG))&&(timeout))timeout--;//�ȴ�ת����ɡ�
    ADC_IT_CLS;//���ת����ɱ�־λ��
    return (u16)(ADC_GET_REG_RES_HL);//����������Ĵ�����ֵ�����һ�𣬷���һ��12λ���ݡ�
}
/*-------------------------------------------------------
��ȡ��ѹ������
-------------------------------------------------------*/
float adc_voltage(u8 ch,float vref){
    u16 jg;
    jg=adc_read(ch);//�ȶ�ȡADֵ��
    return (float)jg*vref/(ECBM_MCU_ADC_MAX);//�������ѹֵ��
}
/*-------------------------------------------------------
ADC��ȡVref������
-------------------------------------------------------*/
float adc_read_vref(void){
    u16 jg;
    jg=adc_read(15);//�ȶ�ȡADֵ��  
    if(jg==0)return 0.0f;//��ֹ����NaN
    return (adc_ch15)*(ECBM_MCU_ADC_MAX)/((float)jg);//�����Vref��
}
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��