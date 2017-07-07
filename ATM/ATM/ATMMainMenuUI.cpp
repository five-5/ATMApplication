#include "stdafx.h"
#include "ATMMainMenuUI.h"


ATMMainMenuUI::ATMMainMenuUI(CardManager* cardManager)
{
	this->cardManager = cardManager;
}


ATMMainMenuUI::~ATMMainMenuUI(void)
{
}
 
void ATMMainMenuUI::MainMenuUI(string CardNum)
{   
	system("Cls");
	cout<<"尊敬的"<< cardManager->GetstrName(CardNum) <<"客户："<<endl;
	cout<<endl; 
	cout<<"\t\t--------------欢迎使用ATM取款机系统--------------"<<endl<<endl<<endl;
	 
	cout<<"\t\t\t\t* 1:查询余额"<<endl<<endl;
	cout<<"\t\t\t\t* 2:存款"<<endl<<endl;
	cout<<"\t\t\t\t* 3:取款"<<endl<<endl;
	cout<<"\t\t\t\t* 4:转账"<<endl<<endl;
	cout<<"\t\t\t\t* 5:修改密码"<<endl<<endl;
	cout<<"\t\t\t\t* 6:退出登录"<<endl<<endl;
	cout<<" 请输入数字1-6选择功能：";
	int a;
	cin>>a;
	switch( a )
	{
	case 1:  
		GetAvailMUI(CardNum);
		break;
	case 2:
		DepositUI(CardNum);
		break;
	case 3:
		WithdrawUI(CardNum);
		break;
	case 4:
		TransferMUI(CardNum);
		break;
	case 5:
		ChangePwdUI(CardNum);
		break;
	case 6:
		  LogoutUI(CardNum);
		break;
	default:
		MainMenuUI(CardNum);
		break;
   }

}

void  ATMMainMenuUI::GetAvailMUI(string CardNum)
{ 
	system("Cls");
	cout<<"尊敬的"<< cardManager->GetstrName(CardNum) <<"客户："<<endl;
	cout<<endl; 
	cout<<"\t\t--------------欢迎使用ATM取款机系统--------------"<<endl<<endl<<endl;
	cout<<" 您当前余额为："<< cardManager->GetAvailM(CardNum)<<endl<<endl;
	cout<<" 按任意键返回主菜单：";
	  getchar();
	  getchar();
	MainMenuUI(CardNum);
}
void ATMMainMenuUI::DepositUI(string CardNum)
{
	system("Cls");
	 
	cout<<"尊敬的"<< cardManager->GetstrName(CardNum)<<"客户："<<endl;
	cout<<endl; 
	cout<<"\t\t--------------欢迎使用ATM取款机系统--------------"<<endl<<endl<<endl;
	cout<<"\t\t\t*********请注意存款安全*********"<<endl<<endl<<endl;
	cout<<" 请输入您的存款金额：";
	 int num;
	cin>>num;
	int i;
	i=cardManager->Deposit(CardNum,num);
	if(i==0)
	{
		DepositSuccessUI(CardNum);
	}
	else
	{
		cout << "系统错误，按任意键回主菜单";
		getchar();
		MainMenuUI(CardNum);
	}
  
}
void ATMMainMenuUI::DepositSuccessUI(string CardNum)
{
	system("Cls");
 
	cout<<"尊敬的"<< cardManager->GetstrName(CardNum) <<"客户："<<endl;
	cout<<endl; 
	cout<<"\t\t--------------欢迎使用ATM取款机系统--------------"<<endl<<endl<<endl;
	cout<<" 存款成功！欢迎再次使用！"<<endl<<endl;
	cout<<" 按任意键返回主菜单：";
	getchar();
	  getchar();
	MainMenuUI(CardNum);
}
void ATMMainMenuUI::WithdrawUI(string CardNum)
{
	  system("Cls");
	   
	cout<<"尊敬的"<< cardManager->GetstrName(CardNum) <<"客户："<<endl;
	cout<<endl; 
	cout<<"\t\t--------------欢迎使用ATM取款机系统--------------"<<endl<<endl<<endl;
	cout<<"\t\t\t*********请注意取款安全*********"<<endl<<endl<<endl;
	cout<<" 请输入您的取款金额：";
	int num;
	cin>>num;
	int i;
	i=cardManager->Withdraw(CardNum,num);
	if( i ==0 )
	{
		WithdrawSuccessUI(CardNum);
	}
	else
	{
		WithdrawFailUI(CardNum);
	}

 }
   void ATMMainMenuUI::WithdrawSuccessUI(string CardNum)
{
	 system("Cls");
	 
	cout<<"尊敬的"<< cardManager->GetstrName(CardNum) <<"客户："<<endl;
	cout<<endl; 
	cout<<"\t\t--------------欢迎使用ATM取款机系统--------------"<<endl<<endl<<endl;
	cout<<" 取款成功！欢迎再次使用！"<<endl<<endl;
	cout<<" 按任意键返回主菜单：";
	getchar();
	  getchar();
	MainMenuUI(CardNum);
}

void ATMMainMenuUI::WithdrawFailUI(string CardNum)
{
	system("Cls");
	 
	cout<<"尊敬的"<< cardManager->GetstrName(CardNum) <<"客户："<<endl;
	cout<<endl; 
	cout<<"\t\t--------------欢迎使用ATM取款机系统--------------"<<endl<<endl<<endl;
	cout<<" 取款失败！请先查询余额！"<<endl<<endl;
	cout<<" 按任意键返回主菜单：";
	getchar();
	  getchar();
	MainMenuUI(CardNum);
}
void ATMMainMenuUI::TransferMUI(string CardNum)
{
	system("Cls");
	 
	cout<<"尊敬的"<< cardManager->GetstrName(CardNum) <<"客户："<<endl;
	cout<<endl; 
	cout<<"\t\t--------------欢迎使用ATM取款机系统--------------"<<endl<<endl<<endl;
	cout<<"\t\t\t*********请注意转账安全*********"<<endl<<endl<<endl;
	cout<<" 请输入您的转账金额：";
	int num;
	cin>>num;
	cout<<" 请输入您的转账卡号：";
	string cardnum;
	cin>>cardnum;
	int i=3;
	i=cardManager->Transfer(CardNum,cardnum,num);
	switch( i )
	{
	case 0:
		TransferMSuccessUI(CardNum);
		break;
	case 1:
		TransferMFailForNUI(CardNum);
		break;
	case 2:
		TransferMFailForMUI(CardNum);
		 break;
	default:
		cout << "系统错误，按任意键回主菜单";
		getchar();
		MainMenuUI(CardNum);
		break;
	}
	 
}
 void ATMMainMenuUI::TransferMSuccessUI(string CardNum)
{
	system("Cls");
	 
	cout<<"尊敬的"<< cardManager->GetstrName(CardNum) <<"客户："<<endl;
	cout<<endl; 
	cout<<"\t\t--------------欢迎使用ATM取款机系统--------------"<<endl<<endl<<endl;
	cout<<" 转账成功！欢迎再次使用！"<<endl<<endl;
	cout<<" 按任意键返回主菜单：";
	getchar();
	  getchar();
	MainMenuUI(CardNum);
}
void ATMMainMenuUI::TransferMFailForMUI(string CardNum)
{
	system("Cls");
	 
	cout<<"尊敬的"<< cardManager->GetstrName(CardNum) <<"客户："<<endl;
	cout<<endl; 
	cout<<"\t\t--------------欢迎使用ATM取款机系统--------------"<<endl<<endl<<endl;
	cout<<" 转账失败！余额不足，请查询余额！"<<endl<<endl;
	cout<<" 继续转账请按1，返回主菜单请按2：";
	string a;
	cin>>a;
	if( a == "1" )
	{
		TransferMUI(CardNum);
	}
	else
	{
		MainMenuUI(CardNum);
	}
}
void ATMMainMenuUI::TransferMFailForNUI(string CardNum)
{
	system("Cls");
	 
	cout<<"尊敬的"<< cardManager->GetstrName(CardNum) <<"客户："<<endl;
	cout<<endl; 
	cout<<"\t\t--------------欢迎使用ATM取款机系统--------------"<<endl<<endl<<endl;
	cout<<" 转账失败！输入卡号错误，请检查卡号！"<<endl<<endl;
	cout<<" 继续转账请按1，返回主菜单请按2：";
	string a;
	cin>>a;
	if( a == "1" )
	{
		TransferMUI(CardNum);
	}
	else
	{
		MainMenuUI(CardNum);
	}
}
void ATMMainMenuUI::ChangePwdUI(string CardNum)
{
	system("Cls");
	 
	cout<<"尊敬的"<< cardManager->GetstrName(CardNum) <<"客户："<<endl;
	cout<<endl; 
	cout<<"\t\t--------------欢迎使用ATM取款机系统--------------"<<endl<<endl<<endl;
	cout<<"\t\t\t*********请注意环境安全*********"<<endl<<endl<<endl;
	cout<<" 请输入您的新密码:";
	 string pwd1;
	 cin>>pwd1;
	 cout<<endl;
	 cout<<" 请再次输入您的新密码：";
	 string pwd2;
	 cin>>pwd2;
	 int i=1;
	i=cardManager->ChangePwd(CardNum,pwd1,pwd2);
	if( i ==0 )
	{
		ChangePwdSuccessUI(CardNum);
	}
	else
	{
		ChangePwdFailUI(CardNum);
	}
}
void ATMMainMenuUI::ChangePwdSuccessUI(string CardNum)
{
	system("Cls");
 
	cout<<"尊敬的"<< cardManager->GetstrName(CardNum) <<"客户："<<endl;
	cout<<endl; 
	cout<<"\t\t--------------欢迎使用ATM取款机系统--------------"<<endl<<endl<<endl;
	cout<<" 修改密码成功！欢迎再次使用！"<<endl<<endl;
	cout<<" 按任意键返回主菜单：";
	getchar();
	  getchar();
	MainMenuUI(CardNum);
}
void ATMMainMenuUI::ChangePwdFailUI(string CardNum)
{
	system("Cls");
	 
	cout<<"尊敬的"<< cardManager->GetstrName(CardNum) <<"客户："<<endl;
	cout<<endl; 
	cout<<"\t\t--------------欢迎使用ATM取款机系统--------------"<<endl<<endl<<endl;
	cout<<" 修改密码失败！两次密码不一致！请重新修改！"<<endl<<endl;
	cout<<" 继续修改请按1，返回主菜单请按2：";
	string a;
	cin>>a;
	if( a == "1" )
	{
		ChangePwdUI(CardNum);
	}
	else
	{
		MainMenuUI(CardNum);
	}
}
void ATMMainMenuUI::LogoutUI(string CardNum)
{
	cardManager->Exit(CardNum);	 
}


 
