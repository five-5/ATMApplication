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


//显示主界面
void ATMMainUI::MainUI()
{
	system("Cls");
	cout<<endl;
	cout<<"\t\t --------欢迎使用ATM取款机系统 -----------"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|           * 1.登录                      |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|           * 2.开户                      |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|           * 3.按姓名查找银行卡信息      |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|           * 4.列出所有银行卡信息        |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
    cout<<"\t\t|           * 5.系统语言选择              |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t -----------------------------------------"<<endl;
	cout<<endl;
	cout<<" 请输入数字1-5选择功能：";	
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

//注册
int ATMMainUI::RegisterUI()
{
	system("Cls");
	cout<<endl;
	cout<<"\t\t --------欢迎使用ATM取款机系统 -----------"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|               *------*                  |"<<endl;
	cout<<"\t\t                | 开户 |                  |"<<endl;
	cout<<"\t\t|               *------*                  |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|           * 1.储蓄卡开户                |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|           * 2.信用卡开户                |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|           * 3.返回主界面                |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t -----------------------------------------"<<endl;
	cout<<" 请输入数字1-3选择功能：";

	string strNum;
	string strName;
	string strID;
	string strTel;
	int i; 
	cin>>i;
	cout<<"请输入您的姓名：";
	cin>>strName;
	cout<<"请输入您的身份证号：";
	cin>>strID;
	cout<<"请输入您的电话号码：";
	cin>>strTel;
	strNum = cardManager->GetNum();
	string strPwd;
	strPwd = cardManager->GetPwd();
    //信用额度int型 都调用register重载的函数
    int re;
	if(i ==1)
        re = cardManager->Register(strNum,strName,strID,strTel,strPwd);
	else if(i == 2)
	{
		int AvailM;
		cout<<"请输入您要申请的信用额度（请输入大于0的整数）：";
		cin>>AvailM;
		re = cardManager->Register(strNum,strName,strID,strTel,strPwd,AvailM);
	}
            
	//返回值为1是不成功，0是成功,2使系统异常
	if(re == 1)
		return 1;
	else if(re == 0)
	{
		cout<<"***开户成功：请牢记您的卡号和密码。"<<endl<<endl;
		cout<<"您的卡号为:"<<strNum<<endl;
		cout<<"该卡的初始密码为："<<strPwd<<endl;
		cout<<"按下任意键返回上一级界面";
        getchar();
        getchar();
        MainUI();    
		return 0;
	}
	else 
	{
        cout<<"系统出现异常"<<endl;
		cout<<"按下任意键返回上一级界面";
        getchar();
        getchar();
        MainUI();  
		return 0;
    }
}

//登录  调用ATMMainMenuUI
int ATMMainUI::LoginUI()//0成功  1失败
{
		system("Cls");
		cout<<"\t\t------------欢迎使用ATM取款机系统-------------"<<endl<<endl<<endl;
		cout<<"\t\t--------------------登录-------------------"<<endl<<endl<<endl;

		cout<<"\t\t\t\t* 1.登录"<<endl<<endl;
		cout<<"\t\t\t\t* 2.取消并返回上一级界面"<<endl<<endl;
		cout<<" 请输入数字1-2选择功能：";
		cout<<endl;
        int i;
        cin>>i;
        if(i == 1)           //登录
		{
			string strNum,strPwd;
			cout<<"请输入您的银行卡号：";
			cin>>strNum;
			cout<<"请输入对应的密码：";
			cin>>strPwd;
			int re = cardManager->Login(strNum,strPwd);
			if(re == 1)  
			{
				cout<<"该银行卡号或密码错误"<<endl;
		        return 1;
			}
		    else            //登录成功
			{
				ATMMainMenuUI atmMainMenuUI(cardManager);
				atmMainMenuUI.MainMenuUI(strNum);
				MainUI();
				return 0;
		    }
         }
         else               //返回上一级界面
			MainUI();
		return 0;
}

//选择语言
void ATMMainUI::LanguageUI()
{
	system("Cls");
	cout<<"\t\t------------欢迎使用ATM取款机系统-------------"<<endl<<endl<<endl;
	cout<<"\t\t----------------请选择系统语言类型---------------"<<endl<<endl<<endl;
	cout<<"\t\t\t\t* 1.中文简体"<<endl<<endl;
	cout<<"\t\t\t\t* 2.英文"<<endl<<endl;
	cout<<" 请输入数字1-2选择语言：";
	//int i;
	//Language(i);
}


//界面保持一致  标题
//列出所有银行卡信息
void ATMMainUI::ListAllCardInfoUI()   //链表中无信息
{
	system("Cls");
	cout<<"\t\t------------欢迎使用ATM取款机系统-------------"<<endl<<endl<<endl;
	cout<<"\t\t----------------所有持卡信息---------------"<<endl<<endl<<endl;
	cardManager->ListAllCardInfo();
	cout<<endl;
	cout<<"按下任意键返回上一级界面";
	getchar();
	getchar();
	MainUI();
}

//按姓名查找银行卡信息
void ATMMainUI::FindCardInfoUI()       //查找不到持卡人的情况
{
	system("Cls");
	cout<<"\t\t------------欢迎使用ATM取款机系统-------------"<<endl<<endl<<endl;
	cout<<"\t\t--------------按姓名查找持卡信息---------------"<<endl<<endl<<endl;
	string strName;
	cout<<"请输入需要查找持卡人的姓名：";
	cin>>strName;
	cout<<endl;
	cout<<"\t\t--------------该持卡人持有的卡信息---------------"<<endl;
	cardManager->FindCardByName(strName);
	cout<<"按下任意键返回上一级界面";
	getchar();
	getchar();
	MainUI();
}