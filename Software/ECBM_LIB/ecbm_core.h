#ifndef _ECBM_CORE_H_
#define _ECBM_CORE_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2021 ����

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

����˵����
	����������MIT��ԴЭ�����������ṩ������ֻ��֤ԭʼ�汾����������ά����BUG��
����ͨ�����紫���İ汾Ҳ���������޸Ĺ����ɴ˳��ֵ�BUG�������޹ء�������ʹ��ԭʼ
�汾����BUGʱ������ϵ���߽����
                            **************************
                            * ��ϵ��ʽ����Ⱥ778916610 *
                            ************************** 
------------------------------------------------------------------------------------*/
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//Frame Version Number ��ܰ汾��
#define ECBM_FVN 1
//Release Version Number �����汾��
//�������ؼ����ļ�����ʱ���ð汾�ż�һ��
#define ECBM_RVN 0
//BUG Version Number �����汾��
//ÿ�η���������ʱ����ֻ���޸�BUG���ð汾�ż�һ��
#define ECBM_BVN 1
//<h>��Ƭ��ϵͳ����
//<i>�ÿ��ڵ�ѡ���л����ѡ�����ϸ�Ķ��˽��˽����ѡ��
//<o>����(HSI/HSE)Ƶ��ѡ��
//<i>���嵥Ƭ�����е�ʱ��Ƶ�ʣ���λHz����
//<5529600UL=>5.5296M <6000000UL=>6.000M <11059200UL=>11.0592M <12000000UL=>12.000M <18432000UL=>18.432M  
//<20000000UL=>20.000M <22118400UL=>22.1184M <24000000UL=>24.000M <27000000UL=>27.000M
//<30000000UL=>30.000M <33000000UL=>33.000M <33177600UL=>33.1776M <35000000UL=>35.000M 
//<36864000UL=>36.864M <40000000UL=>40.000M <44236800UL=>44.2368M <45000000UL=>45.000M 
#define ECBM_SYSCLK_SETTING 24000000L
//<e>ϵͳʱ�����
//<i>�������ʱ��Ƶ�����������������裬�������ڼ���ڲ��Ĺ���Ƶ�ʡ�
#define ECBM_SYSCLK_OUT_EN 0
//<o>�������
//<0=>�����P54 <1=>�����P16
#define	ECBM_SYSLCK_OUT_PIN 1
//<o.4..7>STC8F��STC8A���������Ƶ
//<i>����������ͺ�ѡ���������÷�Ƶ��ѡ��ֻ����Чһ����
//< 1=>SYSCLK/ 1  < 2=>SYSCLK/ 2 < 4=>SYSCLK/ 4 
//< 6=>SYSCLK/ 8  < 8=>SYSCLK/16 <10=>SYSCLK/32 
//<12=>SYSCLK/64  <14=>SYSCLK/128
#define ECBM_SYSCLK_OUT_SETTING_FA 0x18
//<o>STC8G��STC8H���������Ƶ
//<1-127>
//<i>����������ͺ�ѡ���������÷�Ƶ��ѡ��ֻ����Чһ����
//<i>����پ��Ƿ�Ƶ���٣�������6������SYSCLK/6��
#define ECBM_SYSCLK_OUT_SETTING_GH 1
//</e>
//</h>
//<h>ECBM��������
//<q>�Զ����ع���
//<i>��ѡ��ѡ�����ʹ���Զ����ع��ܡ���������ʹ���˴���1�����Ե�ȷ������1��ʹ��״̬�����������ӳ�䵽P30��P31��
//<i>�����Զ����ع��ܺ�uart_int�����ͻ���system_init�ﱻ���ã��������ֶ�����uart_int�����ˡ�
#define ECBM_AUTO_DOWNLOAD_EN  1
//<i>��������8K������С��Ƭ�����߸�С�ĵ�Ƭ����ʹ�ñ����ʱ��������Ѷ���ĺ����Ż�����
//<q>strϵ�к���
//<i>��ϵ�к�����Ҫ��Ϊ�˴��ַ����л�ȡ���õ���Ϣ��ĳЩ�����ʹ�õ���������Ϊ��չ���ܣ���ʵ��������Ŀ��ʱ������Ż�����
#define ECBM_STRING_EN 0
//</h>
//<h>��Ƭ��������ѡ��
//<i>��Щ���Ա�Ŀ�����������ע�⿴˵�����֡��ڹ�ѡĳ���ʱ����ͬ�����Ŀ�һ��ѡ��
//<q>POWER��
//<i>�ÿ��ṩ�˹���STC8�ĵ�Դ����λ�����Ź���ز���������
#define ECBM_POWER_LIB_EN 0
//<q>UART��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��UART��ز���������
#define ECBM_UART_LIB_EN 1
//<q>EXTI��
//<i>�ÿ��ṩ�˹���STC8���ⲿ�ж���ز���������
#define ECBM_EXTI_LIB_EN 0
//<q>TIMER��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��TIMER��ز���������
#define ECBM_TIMER_LIB_EN 0
//<q>EEPROM��
//<i>�ÿ��ṩ�˹���STC8ʹ������FLASHģ���EEPROM��ز���������
#define ECBM_EEPROM_LIB_EN 0
//<q>SPI��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��SPI��ز���������
#define ECBM_SPI_LIB_EN 0
//<q>SOFT_SPI��
//<i>�ÿ��ṩ�˹���STC8����GPIO�������SPI��ز���������
#define ECBM_SOFTSPI_LIB_EN 1
//<q>IIC��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��IIC��ز���������
#define ECBM_IIC_LIB_EN 0
//<q>SOFT_IIC��
//<i>�ÿ��ṩ�˹���STC8����GPIO�������IIC��ز���������
#define ECBM_SOFTIIC_LIB_EN 0
//<q>ADC��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��ADC��ز���������
#define ECBM_ADC_LIB_EN 0
//<q>CMP��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��CMP��ز���������
#define ECBM_CMP_LIB_EN 0
//<q>MDU16��
//<i>�ÿ��ṩ�˹���STC8G��Ӳ���˳�����ز���������
#define ECBM_MDU16_LIB_EN 0
//<q>PCA��
//<i>�ÿ��ṩ�˹���STC8A��Ӳ��PCA��ز���������
#define ECBM_PCA_LIB_EN 0
//<q>PWM��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��PWM��ز���������
#define ECBM_PWM_LIB_EN 0
//<q>LCM��
//<i>�ÿ��ṩ�˹���STC8��Ӳ��LCM��ز���������
#define ECBM_LCM_LIB_EN 0
//</h>
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*------------------------------------ͷ�ļ�����------------------------------------*/
#include "ecbm_reg.h"	//��Ƭ���Ĵ�����ͷ�ļ���
#include "intrins.h"    //��Ƭ��C����ʹ�û��ָ���ͷ�ļ���
#include "STDARG.H"     //���������֧�ֵ�ͷ�ļ���	
#include "stdio.h"      //sprintf��غ���֧�ֵ�ͷ�ļ���
/*--------------------------------------��������-----------------------------------*/
extern u16 xdata ecbm_delay_base;
/*------------------------------------оƬ���ü���----------------------------------*/
/*####################################оƬ���ֽ���##################################*/
#if			(ECBM_MCU&0xF00000)==0x100000
#	define	ECBM_MCU_NAME	"STC8F"
#elif		(ECBM_MCU&0xF00000)==0x200000
#	define	ECBM_MCU_NAME	"STC8A"
#elif		(ECBM_MCU&0xF00000)==0x300000
#	define	ECBM_MCU_NAME	"STC8G"
#elif		(ECBM_MCU&0xF00000)==0x400000
#	define	ECBM_MCU_NAME	"STC8H"
#endif
/*##################################���������ַ����################################*/
#if		(ECBM_MCU==0x110301)||(ECBM_MCU==0x110302)//STC8F1Kxx_8PIN//STC8F1KxxS2_16PIN_20PIN 
#	if		ECBM_MCU_ROM_SIZE==8
#		define	MCUID			(  (unsigned char code *)(0x1FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x1FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x1FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x1FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x1FF3)))	//24MHz��IRC������
#	elif	ECBM_MCU_ROM_SIZE==12
#		define	MCUID			(  (unsigned char code *)(0x2FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x2FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x2FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x2FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x2FF3)))	//24MHz��IRC������
#	elif	ECBM_MCU_ROM_SIZE==17
#		define	MCUID			(  (unsigned char code *)(0x43F9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x43F7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x43F5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x43F4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x43F3)))	//24MHz��IRC������
#	endif
#elif	(ECBM_MCU==0x120502)||(ECBM_MCU==0x120504)||(ECBM_MCU==0x2405C2)||(ECBM_MCU==0x2805C4)||(ECBM_MCU==0x2815C4)//STC8F2KxxS2_ALL//STC8F2KxxS4_ALL//STC8A4KxxS2A12_ALL//STC8A8KxxS4A12_ALL//STC8A8K64D4_ALL   
#	if		ECBM_MCU_ROM_SIZE==16
#		define	MCUID			(  (unsigned char code *)(0x3FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x3FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x3FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x3FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x3FF3)))	//24MHz��IRC������
#	elif	ECBM_MCU_ROM_SIZE==32
#		define	MCUID			(  (unsigned char code *)(0x7FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x7FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x7FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x7FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x7FF3)))	//24MHz��IRC������
#	elif	ECBM_MCU_ROM_SIZE==60
#		define	MCUID			(  (unsigned char code *)(0xEFF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xEFF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xEFF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xEFF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xEFF3)))	//24MHz��IRC������
#	elif	ECBM_MCU_ROM_SIZE==64
#		define	MCUID			(  (unsigned char code *)(0xFDF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xFDF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xFDF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xFDF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xFDF3)))	//24MHz��IRC������
#	endif
#elif	(ECBM_MCU==0x3103A2)||(ECBM_MCU==0x310201)||(ECBM_MCU==0x3102A1)||(ECBM_MCU==0x3103A1)//STC8G1Kxx_16PIN_20PIN//STC8G1Kxx_8PIN//STC8G1KxxA_8PIN//STC8G1KxxT_20PIN 
#	if		ECBM_MCU_ROM_SIZE==8
#		define	MCUID			(  (unsigned char code *)(0x1FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x1FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x1FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x1FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x1FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x1FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x1FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x1FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x1FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x1FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x1FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x1FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x1FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==12
#		define	MCUID			(  (unsigned char code *)(0x2FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x2FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x2FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x2FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x2FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x2FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x2FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x2FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x2FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x2FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x2FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x2FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x2FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==17
#		define	MCUID			(  (unsigned char code *)(0x43F9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x43F7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x43F5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x43F4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x43F3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x43F2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x43F1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x43F0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x43EF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x43EE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x43ED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x43EA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x43E9)))	//40MƵ�ε�VRTRIM������
#	endif
#elif	(ECBM_MCU==0x3205A2)||(ECBM_MCU==0x3205A4)//STC8G2KxxS2_ALL//STC8G2KxxS4_ALL 
#	if		ECBM_MCU_ROM_SIZE==16
#		define	MCUID			(  (unsigned char code *)(0x3FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x3FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x3FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x3FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x3FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x3FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x3FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x3FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x3FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x3FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x3FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x3FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x3FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==32
#		define	MCUID			(  (unsigned char code *)(0x7FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x7FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x7FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x7FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x7FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x7FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x7FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x7FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x7FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x7FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x7FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x7FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x7FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==60
#		define	MCUID			(  (unsigned char code *)(0xEFF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xEFF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xEFF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xEFF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xEFF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0xEFF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0xEFF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0xEFF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xEFEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0xEFEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xEFED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0xEFEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0xEFE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==64
#		define	MCUID			(  (unsigned char code *)(0xFDF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xFDF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xFDF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xFDF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xFDF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0xFDF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0xFDF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0xFDF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xFDEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0xFDEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xFDED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0xFDEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0xFDE9)))	//40MƵ�ε�VRTRIM������
#	endif
#elif	(ECBM_MCU==0x4103A2)||(ECBM_MCU==0x4105A2)//STC8H1Kxx_20PIN//STC8H1Kxx_32PIN 
#	if		ECBM_MCU_ROM_SIZE==8
#		define	MCUID			(  (unsigned char code *)(0x1FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x1FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x1FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x1FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x1FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x1FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x1FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x1FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x1FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x1FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x1FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x1FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x1FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==12
#		define	MCUID			(  (unsigned char code *)(0x2FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x2FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x2FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x2FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x2FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x2FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x2FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x2FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x2FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x2FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x2FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x2FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x2FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==17
#		define	MCUID			(  (unsigned char code *)(0x43F9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x43F7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x43F5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x43F4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x43F3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x43F2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x43F1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x43F0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x43EF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x43EE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x43ED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x43EA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x43E9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==16
#		define	MCUID			(  (unsigned char code *)(0x3FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x3FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x3FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x3FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x3FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x3FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x3FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x3FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x3FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x3FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x3FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x3FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x3FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==28
#		define	MCUID			(  (unsigned char code *)(0x6FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x6FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x6FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x6FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x6FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x6FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x6FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x6FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x6FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x6FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x6FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x6FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x6FE9)))	//40MƵ�ε�VRTRIM������
#	endif
#elif	(ECBM_MCU==0x4205C4)||(ECBM_MCU==0x4305C2)||(ECBM_MCU==0x4305C4)//STC8H2KxxT_48PIN//STC8H3KxxS2_48PIN//STC8H3KxxS4_48PIN 
#	if		ECBM_MCU_ROM_SIZE==32
#		define	MCUID			(  (unsigned char code *)(0x7FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x7FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x7FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x7FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x7FF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0x7FF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x7FF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x7FF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x7FEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x7FEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x7FED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0x7FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0x7FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==60
#		define	MCUID			(  (unsigned char code *)(0xEFF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xEFF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xEFF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xEFF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xEFF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0xEFF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0xEFF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0xEFF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xEFEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0xEFEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xEFED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0xEFEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0xEFE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==64
#		define	MCUID			(  (unsigned char code *)(0xFDF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xFDF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xFDF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xFDF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xFDF3)))	//24MHz��IRC������
#		define	IRC20MHZ		(*((unsigned char code *)(0xFDF2)))	//20MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0xFDF1)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0xFDF0)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xFDEF)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0xFDEE)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xFDED)))	//36.864MHz��IRC������
#		define	IRC20M_VRTRIM	(*((unsigned char code *)(0xFDEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC35M_VRTRIM	(*((unsigned char code *)(0xFDE9)))	//40MƵ�ε�VRTRIM������
#	endif
#elif	ECBM_MCU == 0x4805C4//STC8H8KxxU_48PIN_64PIN 
#	if		ECBM_MCU_ROM_SIZE==32
#		define	MCUID			(  (unsigned char code *)(0x7FF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0x7FF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0x7FF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0x7FF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0x7FF3)))	//24MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0x7FF2)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0x7FF1)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0x7FF0)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0x7FEF)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0x7FEE)))	//36.864MHz��IRC������
#		define	IRC40MHZ		(*((unsigned char code *)(0x7FED)))	//40MHz��IRC������
#		define	IRC44_2368MHZ	(*((unsigned char code *)(0x7FEC)))	//44.2368MHz��IRC������
#		define	IRC48MHZ		(*((unsigned char code *)(0x7FEB)))	//48MHz��IRC������
#		define	IRC24M_VRTRIM	(*((unsigned char code *)(0x7FEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC40M_VRTRIM	(*((unsigned char code *)(0x7FE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==60
#		define	MCUID			(  (unsigned char code *)(0xEFF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xEFF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xEFF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xEFF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xEFF3)))	//24MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0xEFF2)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0xEFF1)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xEFF0)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0xEFEF)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xEFEE)))	//36.864MHz��IRC������
#		define	IRC40MHZ		(*((unsigned char code *)(0xEFED)))	//40MHz��IRC������
#		define	IRC44_2368MHZ	(*((unsigned char code *)(0xEFEC)))	//44.2368MHz��IRC������
#		define	IRC48MHZ		(*((unsigned char code *)(0xEFEB)))	//48MHz��IRC������
#		define	IRC24M_VRTRIM	(*((unsigned char code *)(0xEFEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC40M_VRTRIM	(*((unsigned char code *)(0xEFE9)))	//40MƵ�ε�VRTRIM������
#	elif	ECBM_MCU_ROM_SIZE==64
#		define	MCUID			(  (unsigned char code *)(0xFDF9))	//��Ƭ����ΨһID�롣
#		define	BGV				(*((unsigned int  code *)(0xFDF7)))	//Ƭ�ڼ�϶��ѹ��ʵ��ֵ��
#		define	IRC32KHZ		(*((unsigned int  code *)(0xFDF5)))	//32K���绽�Ѷ�ʱ��Ƶ�ʡ�
#		define	IRC22_1184MHZ	(*((unsigned char code *)(0xFDF4)))	//22.1184MHz��IRC������
#		define	IRC24MHZ		(*((unsigned char code *)(0xFDF3)))	//24MHz��IRC������
#		define	IRC27MHZ		(*((unsigned char code *)(0xFDF2)))	//27MHz��IRC������
#		define	IRC30MHZ		(*((unsigned char code *)(0xFDF1)))	//30MHz��IRC������
#		define	IRC33_1776MHZ	(*((unsigned char code *)(0xFDF0)))	//33.1776MHz��IRC������
#		define	IRC35MHZ		(*((unsigned char code *)(0xFDEF)))	//35MHz��IRC������
#		define	IRC36_864MHZ	(*((unsigned char code *)(0xFDEE)))	//36.864MHz��IRC������
#		define	IRC40MHZ		(*((unsigned char code *)(0xFDED)))	//40MHz��IRC������
#		define	IRC44_2368MHZ	(*((unsigned char code *)(0xFDEC)))	//44.2368MHz��IRC������
#		define	IRC48MHZ		(*((unsigned char code *)(0xFDEB)))	//48MHz��IRC������
#		define	IRC24M_VRTRIM	(*((unsigned char code *)(0xFDEA)))	//24MƵ�ε�VRTRIM������
#		define	IRC40M_VRTRIM	(*((unsigned char code *)(0xFDE9)))	//40MƵ�ε�VRTRIM������
#	endif
#endif
/*------------------------------------ͨ�������趨----------------------------------*/
sbit    LED       =P5^5;     //ͨ��ECBM�İ��Ӷ����һ��LED����LED���õ͵�ƽ������
#define LED_ON    LED=0;     //����LED��
#define LED_OFF   LED=1;     //�ر�LED��
#define LED_BLINK LED=!LED;  //��LED��˸��
/*------------------------------------���ù����趨----------------------------------*/
//���¼�����������idata������ʱ����б����ǵķ��գ����鱣��idata����Ҫʹ�ã���ʹ��xdata����
#define REG_HSI1  read_idata_u8 (0xFA)//Ƭ��24M��·������ֵ��
#define REG_HSI   read_idata_u8 (0xFB)//Ƭ��24M��·������ֵ��
#define REG_BGV   read_idata_u16(0xEF)//Ƭ��1.3V��ѹ��ʵ��ֵ��
#define REG_LSI   read_idata_u16(0xF8)//Ƭ��32K��·������ֵ��
#define REG_ID(x) read_idata_u8 (0xF1+x)//��Ƭ����ΨһID�롣

#define io2port(n) (n)>>4           //ȡ�������ڵ�P�ڣ����Ÿ�ʽ�����0xXX�ĸ�ʽ��
#define io2pin(n)  0x01<<((n)&0x0f) //ȡ�������ڵ�PIN�����Ÿ�ʽ�����0xXX�ĸ�ʽ��
/*-----------------------------------�⺯������-----------------------------------*/
#include "gpio.h"
#include "power.h"
#include "uart.h"
#include "exti.h"
#include "timer.h"
#include "eeprom.h"
#include "spi.h"
#include "soft_spi.h"
#include "iic.h"
#include "soft_iic.h"
#include "adc.h"
#include "cmp.h"
#include "mdu16.h"
#include "pca.h"
#include "lcm.h"
#include "pwm.h"

/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
��������delay_ms
��  �������뼶��ʱ����
��  �룺��Ҫ��ʱ�ĺ�������������1~65535��
��  ������
����ֵ����
�����ߣ�����
�������̣�delay_ms(500);//��ʱ500����
�������ڣ�2019-10-8
�޸ļ�¼��
2020-06-02:�޸�����ʱ0ms�����ʱ65535ms��BUG��
-------------------------------------------------------*/
extern void delay_ms(u16 ms);
/*-------------------------------------------------------
��������delay_us
��  ����΢�뼶��ʱ����
��  �룺��Ҫ��ʱ�Ľ�����������΢����������ͨ��delay_set_us
        �����������΢���Ӧ�Ľ�������
��  ������
����ֵ����
�����ߣ�����
�������̣�
		us_val=delay_set_us(20);//�����20us��Ӧ�Ľ�������
		...//�����޹صĴ��롣
		delay_us(us_val);//��ʱ20us��
		...//�����޹صĴ��롣
�������ڣ�2019-10-8
�޸ļ�¼��
2020-1-3��ȥ����us_code.h�ļ�
-------------------------------------------------------*/
extern void delay_us(u16 us);
/*-------------------------------------------------------
��������delay_set_us
��  ����΢�뼶��ʱת�����������ڰ�΢����ת���ɶ�Ӧ��������
��  �룺������ʱ��΢������
��  ������
����ֵ����΢������Ӧ�Ľ�������
�����ߣ�����
�������̣�
		us_val=delay_set_us(20);//�����20us��Ӧ�Ľ�������
		...//�����޹صĴ��롣
		delay_us(us_val);//��ʱ20us��
		...//�����޹صĴ��롣
�������ڣ�2019-10-8
�޸ļ�¼��
-------------------------------------------------------*/
extern u16  delay_set_us(u16 us);
/***********************************���ڵ���ģ��***************/#if ECBM_AUTO_DOWNLOAD_EN
extern u8 data old_char;  //������һ�ν��յ�����
extern u8 data char_count;//��ͬ���ݼ���
/*-------------------------------------------------------
��������system_uart_reset
��  �����Զ�����������������õ������жϵĽ��ղ��־���ʵ���Զ����ء�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣���
�������ڣ�2019-10-8
�޸ļ�¼��
-------------------------------------------------------*/
extern void system_uart_reset();
/****************************************************************************/#endif
/*----------------------------------����ϵͳ����-----------------------------------*/
/*-------------------------------------------------------
��������system_init
��  ����ECBM�⺯���ĳ�ʼ���������������еĺ�����
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�
	void main(){
		system_init();//��ʼ�������⺯����
		while(1){  
		}	
	}
�������ڣ�2019-10-8
�޸ļ�¼��
2020-1-3���¼����Զ��жϾ���Ĺ��ܡ�
-------------------------------------------------------*/
extern void system_init(void);
/********************************strϵ�к���************************/#if ECBM_STRING_EN
/*-------------------------------------------------------
��������str_find
��  �����ַ������Һ��������ڲ���һ���ַ����Ƿ�����һ���ַ����ڡ�
��  �룺
		dest - ��Ҫ���ҵ�Ŀ���ַ�����
		key  - ��Ҫ���ҵ��ַ���������
��  ������
����ֵ���ַ���������Ŀ���ַ�����λ�ã���0��ʼ���㡣�����-1��˵��Ŀ���ַ���û�и�������
�����ߣ�����
�������̣�
	str_find("0123456789","4",i);//��"0123456789"�в���"4"���ڵ�λ�á�
�������ڣ�2019-10-9
�޸ļ�¼��
-------------------------------------------------------*/
extern u16 str_find(char * dest,char * key);
/*-------------------------------------------------------
��������str_read_pin
��  ����IO��Ϣ��ȡ���������ڶ�ȡ�ַ�����Ŀ��λ�õ�IO��Ϣ��
��  �룺
		str - ����IO��Ϣ���ַ�����
		pos - IO��Ϣ��λ�ã�ͨ������������ַ����ڵĶ��IO��Ϣ��
��  ������
����ֵ���ڸ�λ�õ�IO��Ϣ��
�����ߣ�����
�������̣�
	str_read_pin("SCL=D13,SDA=D14",11);//��ȡ���±�11��ʼ��IO��Ϣ�����᷵��0x14��
�������ڣ�2019-10-9
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 str_read_pin(char * str,u16 pos);
/*-------------------------------------------------------
��������str_read_u16
��  ����u16������ȡ���������ڶ�ȡ�ַ�����Ŀ��λ�õ�u16����ֵ��
��  �룺
		str - ������ֵ���ַ�����
		pos - ��ֵ��λ�ã�ͨ������������ַ����ڵĶ����ֵ��
��  ������
����ֵ���ڸ�λ�õ���ֵ��U16���ͣ���0~65535��
�����ߣ�����
�������̣�
	str_read_u16("SCL=D13,w=128",9);//��ȡ���±�8��ʼ����ֵ�����᷵��128��
�������ڣ�2019-10-9
�޸ļ�¼��
2020-02-17��������һ��ֹͣ�����������������ҲҪֹͣ��
-------------------------------------------------------*/
extern u16 str_read_u16(char * str,u16 pos);
/*-------------------------------------------------------
��������str_push_len
��  �����ַ����Ƴ�ָ��������ַ������Ȳ����棩�����ڰ�ָ�������е�ָ���ؼ����Ƴ��û��档
		Ϊ�˷�ֹǰ������������ɸ��ţ����硰LEDLED_ON_OFF�����Ƴ���LED_ON����ʣ�µĲ��ֻ�������ɡ�LED_OFF������
		�����Ƴ��ؼ���֮��ֻ��ѹؼ�������λ�����㣬����������β���ݣ�����LEDLED_ON_OFF�����Ƴ���LED_ON����ʣ�¡�LED      _OFF������
��  �룺dest  -  Ŀ���ַ������档
		dlen  -  Ŀ���ַ�������ĳ��ȡ�
		key   -  ��Ҫ�Ƴ��Ĺؼ��ʡ�
		klen  -  �ؼ��ʵĳ��ȡ�
��  ������
����ֵ��0 - �Ƴ�ʧ�ܣ�������Ŀ�껺����û�иùؼ��ʡ�
		1 - �Ƴ��ɹ���
�����ߣ�����
�������̣���
�������ڣ�2020-02-17
�޸ļ�¼��
-------------------------------------------------------*/
extern u8 str_push_len(u8 * dest,u16 dlen,u8 * key,u16 klen);
/**************************************************************************/#endif
#endif