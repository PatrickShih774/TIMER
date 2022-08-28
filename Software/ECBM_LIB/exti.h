#ifndef _ECBM_EXTI_H_//ͷ�ļ���ֹ�ؼ��رر����ȿ�����û�ж�������������˵���Ѿ����ع�һ���ˡ�
#define _ECBM_EXTI_H_//û����˵�����״μ��أ���ô����ִ�С����Ҷ�������궨�壬��ֹ��һ�α����ء�
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
//<e>�ⲿ�ж�0
//<i>��Ӧ������ΪP32
//<i>֧�������жϷ�ʽ����������/�½��ء��͡�ֻ�½��ء���
#define ECBM_EXTI0_EN 0
//<o>�ж�ģʽѡ��
//<i>��������/�½��ء�ģʽ�����������ػ����½��ض��ᴥ���жϡ�
//<i>��ֻ�½��ء�ģʽ��ֻ���½��زŻᴥ���жϡ�
//<0=>������/�½��� <1=>ֻ�½���
#define ECBM_EXTI0_MODE 0
//</e>
//<e>�ⲿ�ж�1
//<i>��Ӧ������ΪP33
//<i>֧�������жϷ�ʽ����������/�½��ء��͡�ֻ�½��ء���
#define ECBM_EXTI1_EN 0
//<o>�ж�ģʽѡ��
//<i>��������/�½��ء�ģʽ�����������ػ����½��ض��ᴥ���жϡ�
//<i>��ֻ�½��ء�ģʽ��ֻ���½��زŻᴥ���жϡ�
//<0=>������/�½��� <1=>ֻ�½���
#define ECBM_EXTI1_MODE 0
//</e>
//<q>�ⲿ�ж�2
//<i>��Ӧ������ΪP36
//<i>ֻ֧��һ���жϷ�ʽ����ֻ�½��ء����̶�Ϊ0���ж����ȣ���������ȼ�����it�����ѯ��
#define ECBM_EXTI2_EN 0
//<q>�ⲿ�ж�3
//<i>��Ӧ������ΪP37
//<i>ֻ֧��һ���жϷ�ʽ����ֻ�½��ء����̶�Ϊ0���ж����ȣ���������ȼ�����it�����ѯ��
#define ECBM_EXTI3_EN 0
//<q>�ⲿ�ж�4
//<i>��Ӧ������ΪP30
//<i>ֻ֧��һ���жϷ�ʽ����ֻ�½��ء���
#define ECBM_EXTI4_EN 0
//<<< end of configuration section >>>
//-----------------������ͼ�����ý��棬����Configuration Wizard��������-----------------
/*---------------------------------------ͷ�ļ�------------------------------------*/
#include "ecbm_core.h"    //ECBM���ͷ�ļ��������Ѿ�������STC8��ͷ�ļ���
/*---------------------------------------�궨��------------------------------------*/
#define EXTI_MODE_UP_DOWM   0//������/�½��ض������жϡ�
#define EXTI_MODE_DOWM      1//ֻ���½��زŴ����жϡ�
/*--------------------------------------������-----------------------------------*/
/*------------------------------------------------------
��������exti_init
��  �����ⲿ�жϳ�ʼ����������ͼ�ν��������úò�����Ȼ��ֱ�ӵ��þ��С�
��  �룺��
��  ������
����ֵ����
�����ߣ�����
�������̣�
    exti_init();
�������ڣ�2021-9-15
�޸ļ�¼��
-------------------------------------------------------*/
extern void exti_init(void);
/*------------------------------------------------------
��������exti_start
��  �������жϺ�������������Ҫ�򿪵�����´򿪶�Ӧ���ⲿ�ж�ʹ�ܡ�
��  �룺
    id      ��Ҫ�򿪵��ⲿ�ж�ID�ţ�������0~4��
��  ������
����ֵ����
�����ߣ�����
�������̣�
    exti_start(0);//���ⲿ�ж�0���ж�ʹ�ܡ�
�������ڣ�2021-9-15
�޸ļ�¼��
-------------------------------------------------------*/
extern void exti_start(u8 id);
/*------------------------------------------------------
��������exti_stop
��  �����ر��жϺ�������������Ҫ�رյ�����¹رն�Ӧ���ⲿ�ж�ʹ�ܡ�
��  �룺
    id      ��Ҫ�رյ��ⲿ�ж�ID�ţ�������0~4��
��  ������
����ֵ����
�����ߣ�����
�������̣�
    exti_stop(0);//�ر��ⲿ�ж�0���ж�ʹ�ܡ�
�������ڣ�2021-9-15
�޸ļ�¼��
-------------------------------------------------------*/
extern void exti_stop(u8 id);
/*------------------------------------------------------
��������exti_set_mode
��  �����ж�ģʽ���ú�����ֻ���ⲿ�ж�0���ⲿ�ж�1�����á�
��  �룺
    id      ���õ��ⲿ�ж�ID��������0��1��
    mode    �ж�ģʽ���С�EXTI_UD���͡�EXTI_D�����֡�
��  ������
����ֵ����
�����ߣ�����
�������̣�
    exti_set_mode(0,EXTI_UD);//���ⲿ�ж�0���ж�ģʽ����Ϊ������/�½��ض������жϡ�
�������ڣ�2021-9-15
�޸ļ�¼��
-------------------------------------------------------*/
extern void exti_set_mode(u8 id,u8 mode);
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��