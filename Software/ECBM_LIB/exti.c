#include "ecbm_core.h"//ͳһ���غ���ͷ�ļ�
#if ECBM_EXTI_LIB_EN  //��鱾����û�б�ʹ��
/*--------------------------------------������-----------------------------------*/
/*------------------------------------------------------
�ⲿ�жϳ�ʼ��������
-------------------------------------------------------*/
void exti_init(void){
    #if ECBM_EXTI0_EN           //�ⲿ�ж�0����P32�ڡ���ѡ�񴥷���ʽ��
        gpio_mode(D32,GPIO_IN); //����P32Ϊ����״̬��
        EXTI0_SET_IO_HIGH;      //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��       
        #if ECBM_EXTI0_MODE == 0//ͨ��������Ϣ�жϡ�    
            EXTI0_SET_MODE_UP_DOWM; //����������/�½����жϡ�
        #else
            EXTI0_SET_MODE_DOWM;    //�����½����жϡ�
        #endif
    #endif
    
    #if ECBM_EXTI1_EN           //�ⲿ�ж�1����P33�ڡ���ѡ�񴥷���ʽ��  
        gpio_mode(D33,GPIO_IN); //����P33Ϊ����״̬��
        EXTI1_SET_IO_HIGH;      //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��   
        #if ECBM_EXTI1_MODE == 0//ͨ��������Ϣ�жϡ�    
            EXTI1_SET_MODE_UP_DOWM; //����������/�½����жϡ�
        #else
            EXTI1_SET_MODE_DOWM;    //�����½����жϡ�
        #endif
    #endif
    
    #if ECBM_EXTI2_EN           //�ⲿ�ж�2����P36�ڡ�   
        gpio_mode(D36,GPIO_IN); //����P36Ϊ����״̬��
        EXTI2_SET_IO_HIGH;      //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��
    #endif
    
    #if ECBM_EXTI3_EN           //�ⲿ�ж�3����P37�ڡ�  
        gpio_mode(D37,GPIO_IN); //����P37Ϊ����״̬��
        EXTI3_SET_IO_HIGH;      //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��
    #endif
    
    #if ECBM_EXTI4_EN           //�ⲿ�ж�4����P30�ڡ�
        gpio_mode(D30,GPIO_IN); //����P30Ϊ����״̬��
        EXTI4_SET_IO_HIGH;      //��һ����ֹ�ڲ��ӵ�Ӱ���ȡ��
    #endif
}
/*------------------------------------------------------
���жϺ�����
-------------------------------------------------------*/
void exti_start(u8 id){
    #if ECBM_EXTI0_EN
        if(id==0){EXTI0_ENABLE;} 
    #endif
    #if ECBM_EXTI1_EN
        if(id==1){EXTI1_ENABLE;} 
    #endif
    #if ECBM_EXTI2_EN
        if(id==2){EXTI2_ENABLE;} 
    #endif
    #if ECBM_EXTI3_EN
        if(id==3){EXTI3_ENABLE;} 
    #endif
    #if ECBM_EXTI4_EN
        if(id==4){EXTI4_ENABLE;} 
    #endif
}
/*------------------------------------------------------
�ر��жϺ�����
-------------------------------------------------------*/
void exti_stop(u8 id){
    #if ECBM_EXTI0_EN
        if(id==0){EXTI0_DISABLE;}
    #endif
    #if ECBM_EXTI1_EN
        if(id==1){EXTI1_DISABLE;}
    #endif
    #if ECBM_EXTI2_EN
        if(id==2){EXTI2_DISABLE;}
    #endif
    #if ECBM_EXTI3_EN
        if(id==3){EXTI3_DISABLE;}
    #endif
    #if ECBM_EXTI4_EN
        if(id==4){EXTI4_DISABLE;}
    #endif
}
/*------------------------------------------------------
�ж�ģʽ���ú�����
-------------------------------------------------------*/
void exti_set_mode(u8 id,u8 mode){
    mode=mode;
    switch(id){//����ID������Ӧ��֧��
        default:break;
        #if ECBM_EXTI0_EN
            case 0:{
                if(mode){
                    EXTI0_SET_MODE_DOWM;
                }else{
                    EXTI0_SET_MODE_UP_DOWM;
                }
            }break;
        #endif
        #if ECBM_EXTI1_EN
            case 1:{
                if(mode){
                    EXTI1_SET_MODE_DOWM;
                }else{
                    EXTI1_SET_MODE_UP_DOWM;
                }
            }break;
        #endif
    }
}
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��