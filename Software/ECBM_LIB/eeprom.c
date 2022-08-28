#include "ecbm_core.h"//ͳһ���غ���ͷ�ļ�
#if ECBM_EEPROM_LIB_EN//��鱾����û�б�ʹ��
/*---------------------------------------�궨��------------------------------------*/
#if     ECBM_SYSCLK_SETTING == 5529600UL//����ϵͳʱ����ѡ��ϵ����
    #define ECBM_EEPROM_WAIT_TIME   4
#elif   ECBM_SYSCLK_SETTING == 6000000UL
    #define ECBM_EEPROM_WAIT_TIME   4
#elif   ECBM_SYSCLK_SETTING == 11059200UL
    #define ECBM_EEPROM_WAIT_TIME   3
#elif   ECBM_SYSCLK_SETTING == 12000000UL
    #define ECBM_EEPROM_WAIT_TIME   3
#elif   ECBM_SYSCLK_SETTING == 18432000UL
    #define ECBM_EEPROM_WAIT_TIME   2
#elif   ECBM_SYSCLK_SETTING == 20000000UL
    #define ECBM_EEPROM_WAIT_TIME   2
#elif   ECBM_SYSCLK_SETTING == 22118400UL
    #define ECBM_EEPROM_WAIT_TIME   2
#elif   ECBM_SYSCLK_SETTING == 24000000UL
    #define ECBM_EEPROM_WAIT_TIME   1
#elif   ECBM_SYSCLK_SETTING == 27000000UL
    #define ECBM_EEPROM_WAIT_TIME   1
#elif   ECBM_SYSCLK_SETTING == 30000000UL
    #define ECBM_EEPROM_WAIT_TIME   0
#elif   ECBM_SYSCLK_SETTING == 33000000UL
    #define ECBM_EEPROM_WAIT_TIME   0
#elif   ECBM_SYSCLK_SETTING == 33177600UL
    #define ECBM_EEPROM_WAIT_TIME   0
#elif   ECBM_SYSCLK_SETTING == 35000000UL
    #define ECBM_EEPROM_WAIT_TIME   0
#elif   ECBM_SYSCLK_SETTING == 36864000UL
    #define ECBM_EEPROM_WAIT_TIME   0
#elif   ECBM_SYSCLK_SETTING == 40000000UL
    #define ECBM_EEPROM_WAIT_TIME   0
#elif   ECBM_SYSCLK_SETTING == 44236800UL
    #define ECBM_EEPROM_WAIT_TIME   0
#elif   ECBM_SYSCLK_SETTING == 45000000UL
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
eeprom�رպ�����
-------------------------------------------------------*/
void eeprom_off(void){
    IAP_SET_REG_CONTR(0);       //�ر�IAP����
    IAP_CMD_NOP;                //�������Ĵ���
    IAP_TRIG_CLS;               //��������Ĵ���
    IAP_SET_REG_ADDR_H8(0xff);  //����ַ���õ���IAP����
    IAP_SET_REG_ADDR_L8(0xff);  //����ַ���õ���IAP����
}
/*-------------------------------------------------------
eeprom��ʼ��������
-------------------------------------------------------*/
void eeprom_init(void){
#if  (((ECBM_MCU&0xF00000) > 0x200000)||(ECBM_MCU == 0x2815C4))
    IAP_TPS=ECBM_SYSCLK_SETTING/1000000;
#endif
    eeprom_off();
}
/*-------------------------------------------------------
eeprom����������
-------------------------------------------------------*/
void eeprom_erase(u16 addr){
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);//ʹ��IAP
    IAP_CMD_ERASE;              //����IAP��������
    IAP_SET_REG_ADDR_HL(addr);  //����IAP��ַ
    IAP_TRIG_ON;                //��������
    _nop_();                    //���Եȴ�һ��
    eeprom_off();               //�ر�IAP����
}
/*-------------------------------------------------------
eepromд������
-------------------------------------------------------*/
void eeprom_write(u16 addr,u8 dat){
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);//ʹ��IAP
    IAP_CMD_WRITE;              //����IAPд����
    IAP_SET_REG_ADDR_HL(addr);  //����IAP��ַ
    IAP_SET_REG_DATA(dat);      //дIAP����
    IAP_TRIG_ON;                //��������
    _nop_();                    //���Եȴ�һ��
    eeprom_off();               //�ر�IAP����
}
/*-------------------------------------------------------
eeprom��������
-------------------------------------------------------*/
u8 eeprom_read(u16 addr){
    u8 dat;
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);  //ʹ��IAP
    IAP_CMD_READ;                           //����IAP������
    IAP_SET_REG_ADDR_HL(addr);              //����IAP��ַ
    IAP_TRIG_ON;                            //��������
    _nop_();                                //���Եȴ�һ��
    dat=IAP_GET_REG_DATA;                   //��IAP����
    eeprom_off();                           //�ر�IAP����
    return dat;
}
#if ECBM_EEPROM_EX_EN
/*-------------------------------------------------------
eeprom�����������(extension)��
-------------------------------------------------------*/
void eeprom_read_ex(u16 addr,u8 * dat,u16 num){
    u16 i;
    for(i=0;i<num;i++){
        dat[i]=eeprom_read(addr+i);
    }
}
/*-------------------------------------------------------
eepromд���������(extension)��
-------------------------------------------------------*/
u8 xdata eeprom_buf[512];//�����������ݵĻ���
void eeprom_write_ex(u16 addr,u8 * dat,u16 num){
    u16 num_yu;         //ʣ��Ҫд�����ݵ�������
    u16 area;           //����������
    u16 area_addr_yu;   //�������µĵ�ַ������
    u16 area_start_addr;//������ʼ��ַ��
    u16 area_stop_addr; //����������ַ��
    u16 addr_offset;    //��ַƫ�ơ�
    u16 dat_offset=0;   //����ƫ�ơ�
    u16 address;        //������ַ��
    u16 i;              //��ʱ������
    address=addr;       //����ַ������ֵ��������ַ��
    num_yu=num;         //������������ֵΪʣ��������
    do{
        area=address>>9;                    //��ȡ������
        area_start_addr=(area<<9);          //��ȡ������ʼ�ĵ�ַ��
        area_stop_addr=(area<<9)+512;       //��ȡ����ĩβ�ĵ�ַ��
        area_addr_yu=area_stop_addr-address;//ĩβ��ַ��������ַ���õ���ַʣ��������
        if(num_yu<=area_addr_yu){           //���Ҫд�������ڵ�ַʣ��������˵�����ÿ�������
            for(i=0;i<512;i++){             //��ԭ�������ݶ�������
                eeprom_buf[i]=eeprom_read(area_start_addr+i);
            }
            eeprom_erase(area_start_addr);      //���������
            addr_offset=address-area_start_addr;//��ȡ��ַƫ�ơ�
            for(i=0;i<num_yu;i++){              //�޸����ݡ�
                eeprom_buf[addr_offset+i]=dat[dat_offset+i];
            }
            for(i=0;i<512;i++){                 //������д��ȥ��
                eeprom_write(area_start_addr+i,eeprom_buf[i]);
            }
            break;                              //д�������ѭ����
        }else{                                  //���Ҫд�������ڵ�ַʣ������
            for(i=0;i<512;i++){                 //��ԭ�������ݶ�������
                eeprom_buf[i]=eeprom_read(area_start_addr+i);
            }
            eeprom_erase(area_start_addr);      //���������
            addr_offset=address-area_start_addr;//��ȡ��ַƫ�ơ�
            for(i=0;i<area_addr_yu;i++){        //�޸����ݡ�
                eeprom_buf[addr_offset+i]=dat[dat_offset+i];
            }
            for(i=0;i<512;i++){                 //������д��ȥ��
                eeprom_write(area_start_addr+i,eeprom_buf[i]);
            }
            address+=area_addr_yu;              //д�˶��٣���ַ�ͼӶ��١�
            num_yu -=area_addr_yu;              //ʣ��������Ҫ�����١�
            dat_offset+=area_addr_yu;           //�����ƫ�ƾͼӶ��١�
        }
    }while(1);
}
#endif
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��