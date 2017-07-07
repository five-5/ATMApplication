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
	cout<<"�𾴵�"<< cardManager->GetstrName(CardNum) <<"�ͻ���"<<endl;
	cout<<endl; 
	cout<<"\t\t--------------��ӭʹ��ATMȡ���ϵͳ--------------"<<endl<<endl<<endl;
	 
	cout<<"\t\t\t\t* 1:��ѯ���"<<endl<<endl;
	cout<<"\t\t\t\t* 2:���"<<endl<<endl;
	cout<<"\t\t\t\t* 3:ȡ��"<<endl<<endl;
	cout<<"\t\t\t\t* 4:ת��"<<endl<<endl;
	cout<<"\t\t\t\t* 5:�޸�����"<<endl<<endl;
	cout<<"\t\t\t\t* 6:�˳���¼"<<endl<<endl;
	cout<<" ����������1-6ѡ���ܣ�";
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
	cout<<"�𾴵�"<< cardManager->GetstrName(CardNum) <<"�ͻ���"<<endl;
	cout<<endl; 
	cout<<"\t\t--------------��ӭʹ��ATMȡ���ϵͳ--------------"<<endl<<endl<<endl;
	cout<<" ����ǰ���Ϊ��"<< cardManager->GetAvailM(CardNum)<<endl<<endl;
	cout<<" ��������������˵���";
	  getchar();
	  getchar();
	MainMenuUI(CardNum);
}
void ATMMainMenuUI::DepositUI(string CardNum)
{
	system("Cls");
	 
	cout<<"�𾴵�"<< cardManager->GetstrName(CardNum)<<"�ͻ���"<<endl;
	cout<<endl; 
	cout<<"\t\t--------------��ӭʹ��ATMȡ���ϵͳ--------------"<<endl<<endl<<endl;
	cout<<"\t\t\t*********��ע���ȫ*********"<<endl<<endl<<endl;
	cout<<" ���������Ĵ���";
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
		cout << "ϵͳ���󣬰�����������˵�";
		getchar();
		MainMenuUI(CardNum);
	}
  
}
void ATMMainMenuUI::DepositSuccessUI(string CardNum)
{
	system("Cls");
 
	cout<<"�𾴵�"<< cardManager->GetstrName(CardNum) <<"�ͻ���"<<endl;
	cout<<endl; 
	cout<<"\t\t--------------��ӭʹ��ATMȡ���ϵͳ--------------"<<endl<<endl<<endl;
	cout<<" ���ɹ�����ӭ�ٴ�ʹ�ã�"<<endl<<endl;
	cout<<" ��������������˵���";
	getchar();
	  getchar();
	MainMenuUI(CardNum);
}
void ATMMainMenuUI::WithdrawUI(string CardNum)
{
	  system("Cls");
	   
	cout<<"�𾴵�"<< cardManager->GetstrName(CardNum) <<"�ͻ���"<<endl;
	cout<<endl; 
	cout<<"\t\t--------------��ӭʹ��ATMȡ���ϵͳ--------------"<<endl<<endl<<endl;
	cout<<"\t\t\t*********��ע��ȡ�ȫ*********"<<endl<<endl<<endl;
	cout<<" ����������ȡ���";
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
	 
	cout<<"�𾴵�"<< cardManager->GetstrName(CardNum) <<"�ͻ���"<<endl;
	cout<<endl; 
	cout<<"\t\t--------------��ӭʹ��ATMȡ���ϵͳ--------------"<<endl<<endl<<endl;
	cout<<" ȡ��ɹ�����ӭ�ٴ�ʹ�ã�"<<endl<<endl;
	cout<<" ��������������˵���";
	getchar();
	  getchar();
	MainMenuUI(CardNum);
}

void ATMMainMenuUI::WithdrawFailUI(string CardNum)
{
	system("Cls");
	 
	cout<<"�𾴵�"<< cardManager->GetstrName(CardNum) <<"�ͻ���"<<endl;
	cout<<endl; 
	cout<<"\t\t--------------��ӭʹ��ATMȡ���ϵͳ--------------"<<endl<<endl<<endl;
	cout<<" ȡ��ʧ�ܣ����Ȳ�ѯ��"<<endl<<endl;
	cout<<" ��������������˵���";
	getchar();
	  getchar();
	MainMenuUI(CardNum);
}
void ATMMainMenuUI::TransferMUI(string CardNum)
{
	system("Cls");
	 
	cout<<"�𾴵�"<< cardManager->GetstrName(CardNum) <<"�ͻ���"<<endl;
	cout<<endl; 
	cout<<"\t\t--------------��ӭʹ��ATMȡ���ϵͳ--------------"<<endl<<endl<<endl;
	cout<<"\t\t\t*********��ע��ת�˰�ȫ*********"<<endl<<endl<<endl;
	cout<<" ����������ת�˽�";
	int num;
	cin>>num;
	cout<<" ����������ת�˿��ţ�";
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
		cout << "ϵͳ���󣬰�����������˵�";
		getchar();
		MainMenuUI(CardNum);
		break;
	}
	 
}
 void ATMMainMenuUI::TransferMSuccessUI(string CardNum)
{
	system("Cls");
	 
	cout<<"�𾴵�"<< cardManager->GetstrName(CardNum) <<"�ͻ���"<<endl;
	cout<<endl; 
	cout<<"\t\t--------------��ӭʹ��ATMȡ���ϵͳ--------------"<<endl<<endl<<endl;
	cout<<" ת�˳ɹ�����ӭ�ٴ�ʹ�ã�"<<endl<<endl;
	cout<<" ��������������˵���";
	getchar();
	  getchar();
	MainMenuUI(CardNum);
}
void ATMMainMenuUI::TransferMFailForMUI(string CardNum)
{
	system("Cls");
	 
	cout<<"�𾴵�"<< cardManager->GetstrName(CardNum) <<"�ͻ���"<<endl;
	cout<<endl; 
	cout<<"\t\t--------------��ӭʹ��ATMȡ���ϵͳ--------------"<<endl<<endl<<endl;
	cout<<" ת��ʧ�ܣ����㣬���ѯ��"<<endl<<endl;
	cout<<" ����ת���밴1���������˵��밴2��";
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
	 
	cout<<"�𾴵�"<< cardManager->GetstrName(CardNum) <<"�ͻ���"<<endl;
	cout<<endl; 
	cout<<"\t\t--------------��ӭʹ��ATMȡ���ϵͳ--------------"<<endl<<endl<<endl;
	cout<<" ת��ʧ�ܣ����뿨�Ŵ������鿨�ţ�"<<endl<<endl;
	cout<<" ����ת���밴1���������˵��밴2��";
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
	 
	cout<<"�𾴵�"<< cardManager->GetstrName(CardNum) <<"�ͻ���"<<endl;
	cout<<endl; 
	cout<<"\t\t--------------��ӭʹ��ATMȡ���ϵͳ--------------"<<endl<<endl<<endl;
	cout<<"\t\t\t*********��ע�⻷����ȫ*********"<<endl<<endl<<endl;
	cout<<" ����������������:";
	 string pwd1;
	 cin>>pwd1;
	 cout<<endl;
	 cout<<" ���ٴ��������������룺";
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
 
	cout<<"�𾴵�"<< cardManager->GetstrName(CardNum) <<"�ͻ���"<<endl;
	cout<<endl; 
	cout<<"\t\t--------------��ӭʹ��ATMȡ���ϵͳ--------------"<<endl<<endl<<endl;
	cout<<" �޸�����ɹ�����ӭ�ٴ�ʹ�ã�"<<endl<<endl;
	cout<<" ��������������˵���";
	getchar();
	  getchar();
	MainMenuUI(CardNum);
}
void ATMMainMenuUI::ChangePwdFailUI(string CardNum)
{
	system("Cls");
	 
	cout<<"�𾴵�"<< cardManager->GetstrName(CardNum) <<"�ͻ���"<<endl;
	cout<<endl; 
	cout<<"\t\t--------------��ӭʹ��ATMȡ���ϵͳ--------------"<<endl<<endl<<endl;
	cout<<" �޸�����ʧ�ܣ��������벻һ�£��������޸ģ�"<<endl<<endl;
	cout<<" �����޸��밴1���������˵��밴2��";
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


 
