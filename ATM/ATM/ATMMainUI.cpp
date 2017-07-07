/*************************************************************************************************************************
**  File Name:  ATMMainUI.cpp
**  Summary:    ATM system's   main UI 
**  Create:     2017-07-06
**  Author:    Wen Jing
**  Update history:
**  NO.     Author         Date              Content
**  1.      Wen Jing       2017-07-06        New
**  2.      Zhou Huijun    2014-04-23        Modify for First Review
**  3.      Zhou Huijun    2014-05-15        Add CAN Communication Abnormal Function
**  4.      Zhou Huijun    2014-05-28        Modify Battery Volt Low Detect Function
**  5.      Zhou Huijun    2014-06-03        Modify CAN Communication Abnormal Function
**  6.      Zhou Huijun    2014-06-11        Add Check ZPD Over Status Function, Modify Check Safety Belt Function
**  7.      Zhou Huijun    2014-06-12        Modify C++ Test Bug
**  8.      Zhou Huijun    2014-06-20        Modify Engine Speed Value, Get Value from Tacho
**  9.      Chen Wenkai    2014-08-20        Add New Define : ALARM_STARTERSTS_CONTROLVALUE
                                             Add New Define For Ymap Constant Data: 
                                                            ALARM_MOVE_MODE / ALARM_ENGSPEED_AMF / ALARM_BATVOLT_AMF
                                             Delete Function: Alarm_In_Get_RomConstant__
                                             Add New Macro :Alarm_In_Read_GearShiftN__ / Alarm_In_Write_GearShiftN__
                                             Add Ymap Constant Data Read Function
                                             Modify Operate Message Function: Starter Status / Check BatVolt Low 
                                                            Check PTO / Check ReverserNSW / Check Charge Error
*************************************************************************************************************************/

/* ============================ Include Files ========================================================================= */
#include "stdafx.h"
#include "ATMMainUI.h"
#include "CardManager.h"
#include "string"



ATMMainUI::ATMMainUI(CardManager* cardManager)
{
	this->cardManager = cardManager;

}


ATMMainUI::~ATMMainUI(void)
{
}


//��ʾ������
void ATMMainUI::MainUI()
{
	system("Cls");
	cout<<endl;
	cout<<"\t\t --------��ӭʹ��ATMȡ���ϵͳ -----------"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|           * 1.��¼                      |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|           * 2.����                      |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|           * 3.�������������п���Ϣ      |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|           * 4.�г��������п���Ϣ        |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
    cout<<"\t\t|           * 5.ϵͳ����ѡ��              |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t -----------------------------------------"<<endl;
	cout<<endl;
	cout<<" ����������1-5ѡ���ܣ�";	
	int i;
	cin>>i;
	switch (i)
	{
	case 1:
			while(LoginUI());break;
		case 2:
			while(RegisterUI());break;
		case 3:
			FindCardInfoUI();break;
		case 4:
			ListAllCardInfoUI();break;
				
		case 5:
			LanguageUI();break;

	default:
		break;
	}
}

//ע��
int ATMMainUI::RegisterUI()
{
	system("Cls");
	cout<<endl;
	cout<<"\t\t --------��ӭʹ��ATMȡ���ϵͳ -----------"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|               *------*                  |"<<endl;
	cout<<"\t\t                | ���� |                  |"<<endl;
	cout<<"\t\t|               *------*                  |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|           * 1.�������                |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|           * 2.���ÿ�����                |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|           * 3.����������                |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t -----------------------------------------"<<endl;
	cout<<" ����������1-3ѡ���ܣ�";

	string strNum;
	string strName;
	string strID;
	string strTel;
	int i; 
	cin>>i;
	cout<<"����������������";
	cin>>strName;
	cout<<"�������������֤�ţ�";
	cin>>strID;
	cout<<"���������ĵ绰���룺";
	cin>>strTel;
	strNum = cardManager->GetNum();
	string strPwd;
	strPwd = cardManager->GetPwd();
    //���ö��int�� ������register���صĺ���
    int re;
	if(i ==1)
        re = cardManager->Register(strNum,strName,strID,strTel,strPwd);
	else if(i == 2)
	{
		int AvailM;
		cout<<"��������Ҫ��������ö�ȣ����������0����������";
		cin>>AvailM;
		re = cardManager->Register(strNum,strName,strID,strTel,strPwd,AvailM);
	}
            
	//����ֵΪ1�ǲ��ɹ���0�ǳɹ�,2ʹϵͳ�쳣
	if(re == 1)
		return 1;
	else if(re == 0)
	{
		cout<<"***�����ɹ������μ����Ŀ��ź����롣"<<endl<<endl;
		cout<<"���Ŀ���Ϊ:"<<strNum<<endl;
		cout<<"�ÿ��ĳ�ʼ����Ϊ��"<<strPwd<<endl;
		cout<<"���������������һ������";
        getchar();
        getchar();
        MainUI();    
		return 0;
	}
	else 
	{
        cout<<"ϵͳ�����쳣"<<endl;
		cout<<"���������������һ������";
        getchar();
        getchar();
        MainUI();  
		return 0;
    }
}

//��¼  ����ATMMainMenuUI
int ATMMainUI::LoginUI()//0�ɹ�  1ʧ��
{
		system("Cls");
		cout<<"\t\t------------��ӭʹ��ATMȡ���ϵͳ-------------"<<endl<<endl<<endl;
		cout<<"\t\t--------------------��¼-------------------"<<endl<<endl<<endl;

		cout<<"\t\t\t\t* 1.��¼"<<endl<<endl;
		cout<<"\t\t\t\t* 2.ȡ����������һ������"<<endl<<endl;
		cout<<" ����������1-2ѡ���ܣ�";
		cout<<endl;
        int i;
        cin>>i;
        if(i == 1)           //��¼
		{
			string strNum,strPwd;
			cout<<"�������������п��ţ�";
			cin>>strNum;
			cout<<"�������Ӧ�����룺";
			cin>>strPwd;
			int re = cardManager->Login(strNum,strPwd);
			if(re == 1)  
			{
				cout<<"�����п��Ż��������"<<endl;
		        return 1;
			}
		    else            //��¼�ɹ�
			{
				ATMMainMenuUI atmMainMenuUI(cardManager);
				atmMainMenuUI.MainMenuUI(strNum);
				MainUI();
				return 0;
		    }
         }
         else               //������һ������
			MainUI();
		return 0;
}

//ѡ������
void ATMMainUI::LanguageUI()
{
	system("Cls");
	cout<<"\t\t------------��ӭʹ��ATMȡ���ϵͳ-------------"<<endl<<endl<<endl;
	cout<<"\t\t----------------��ѡ��ϵͳ��������---------------"<<endl<<endl<<endl;
	cout<<"\t\t\t\t* 1.���ļ���"<<endl<<endl;
	cout<<"\t\t\t\t* 2.Ӣ��"<<endl<<endl;
	cout<<" ����������1-2ѡ�����ԣ�";
	//int i;
	//Language(i);
}


//���汣��һ��  ����
//�г��������п���Ϣ
void ATMMainUI::ListAllCardInfoUI()   //����������Ϣ
{
	system("Cls");
	cout<<"\t\t------------��ӭʹ��ATMȡ���ϵͳ-------------"<<endl<<endl<<endl;
	cout<<"\t\t----------------���гֿ���Ϣ---------------"<<endl<<endl<<endl;
	cardManager->ListAllCardInfo();
	cout<<endl;
	cout<<"���������������һ������";
	getchar();
	getchar();
	MainUI();
}

//�������������п���Ϣ
void ATMMainUI::FindCardInfoUI()       //���Ҳ����ֿ��˵����
{
	system("Cls");
	cout<<"\t\t------------��ӭʹ��ATMȡ���ϵͳ-------------"<<endl<<endl<<endl;
	cout<<"\t\t--------------���������ҳֿ���Ϣ---------------"<<endl<<endl<<endl;
	string strName;
	cout<<"��������Ҫ���ҳֿ��˵�������";
	cin>>strName;
	cout<<endl;
	cout<<"\t\t--------------�óֿ��˳��еĿ���Ϣ---------------"<<endl;
	cardManager->FindCardByName(strName);
	cout<<"���������������һ������";
	getchar();
	getchar();
	MainUI();
}