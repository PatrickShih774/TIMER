#include "ecbm_core.h"//统一加载核心头文件
#if ECBM_EXTI_LIB_EN  //检查本库有没有被使能
/*--------------------------------------程序定义-----------------------------------*/
/*------------------------------------------------------
外部中断初始化函数。
-------------------------------------------------------*/
void exti_init(void){
    #if ECBM_EXTI0_EN           //外部中断0，即P32口。可选择触发方式。
        gpio_mode(D32,GPIO_IN); //设置P32为输入状态。
        EXTI0_SET_IO_HIGH;      //置一，防止内部接地影响读取。       
        #if ECBM_EXTI0_MODE == 0//通过配置信息判断。    
            EXTI0_SET_MODE_UP_DOWM; //设置上升沿/下降沿中断。
        #else
            EXTI0_SET_MODE_DOWM;    //设置下降沿中断。
        #endif
    #endif
    
    #if ECBM_EXTI1_EN           //外部中断1，即P33口。可选择触发方式。  
        gpio_mode(D33,GPIO_IN); //设置P33为输入状态。
        EXTI1_SET_IO_HIGH;      //置一，防止内部接地影响读取。   
        #if ECBM_EXTI1_MODE == 0//通过配置信息判断。    
            EXTI1_SET_MODE_UP_DOWM; //设置上升沿/下降沿中断。
        #else
            EXTI1_SET_MODE_DOWM;    //设置下降沿中断。
        #endif
    #endif
    
    #if ECBM_EXTI2_EN           //外部中断2，即P36口。   
        gpio_mode(D36,GPIO_IN); //设置P36为输入状态。
        EXTI2_SET_IO_HIGH;      //置一，防止内部接地影响读取。
    #endif
    
    #if ECBM_EXTI3_EN           //外部中断3，即P37口。  
        gpio_mode(D37,GPIO_IN); //设置P37为输入状态。
        EXTI3_SET_IO_HIGH;      //置一，防止内部接地影响读取。
    #endif
    
    #if ECBM_EXTI4_EN           //外部中断4，即P30口。
        gpio_mode(D30,GPIO_IN); //设置P30为输入状态。
        EXTI4_SET_IO_HIGH;      //置一，防止内部接地影响读取。
    #endif
}
/*------------------------------------------------------
打开中断函数。
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
关闭中断函数。
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
中断模式设置函数。
-------------------------------------------------------*/
void exti_set_mode(u8 id,u8 mode){
    mode=mode;
    switch(id){//根据ID跳到对应分支。
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
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。