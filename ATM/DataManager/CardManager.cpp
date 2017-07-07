/*************************************************************************************************************************
**  File Name:  CardManager.cpp
**  Summary:    Realize the CardManager's function
**  Create:     2017-07-06
**  Author:     Shen Huan
**  Update history:
**  NO.     Author         Date              Content
**  1.      Shen Huan    2017-07-06            New
*************************************************************************************************************************/

#include "CardManager.h"

CardManager* CardManager::m_instance = NULL;
CardManager::CardManager(void)          //���ļ�ȫ������������
{
	file.File_AllInfo(m_List);
}

CardManager::~CardManager(void)
{
}

//��ȡʵ��
CardManager* CardManager::GetInstance()
{
	if (m_instance == NULL)
		return (new CardManager());
	else
		return m_instance;
}

//�������п���
Card* CardManager::CreateCard(string strNum)
{
	return m_List.get(strNum);
}

//��¼  0�ɹ� 1���ɹ�   2
int CardManager::Login(string strNum, string strPwd)
{
	//���ҿ���Ϣ
	Card* card = CreateCard(strNum);
	if (card->GetstrNum().empty())               //û���ҵ�����
		return 1;
	else
	{
		if (card->GetstrPwd() == strPwd)          //�������
			return 0;
		else
			return 1;
	}
}

//ע�ᴢ� 0�ɹ� 1���ɹ�  2ϵͳ�쳣
int CardManager::Register(string strNum,string strName,string strID,string strTel,string strPwd)
{
	Card* card = new Card(strNum, strName, strID, strTel, strPwd);
	/************test**************/
	//λ��δ��֤
	m_List.insert(0,card);
	return 0;

	if (!file.File_Add(*card, 0))
	{
		m_List.insert(0, card);
		return 0;
	}		
	else
		return 1;
}

//ע�����ÿ� 0�ɹ� 1���ɹ�  2ϵͳ�쳣
int CardManager::Register(string strNum, string strName, string strID, string strTel, string strPwd,int s32Limit)
{
	CreditCard* card = new CreditCard(strNum, strName, strID, strTel, strPwd, s32Limit);
	
	/************test**************/
	m_List.insert(0, card);
	return 0;
	if (!file.File_Add(*card, 1))
	{
		m_List.insert(0, card);
		return 0;
	}
	else
		return 1;
}

//�����������
string CardManager::GetPwd()
{
	char pwd[7] = {'0'};
	for(int i = 0; i < 6; i++)
	{
		pwd[i] = rand()%10 + '0';
	}
	string str(pwd);
	return str;
}

//�����������
string CardManager::GetNum()
{
	int flag = 1;
	char num[17] = { '0' };
	string str(num);
	while (flag)
	{
		for (int i = 0; i < 16; i++)
		{
			num[i] = rand() % 10 + '0';
		}
		str.assign(num);
		if (m_List.get(str)->GetstrNum().empty())              //���ظ�����
			          flag = 0;
	}
	return str;
}

//�г��������п���Ϣ
void CardManager::ListAllCardInfo()
{
	if (m_List.size() == 0)
		printf("�޸��û������������п���Ϣ\n");
	else
	{
		printf("�û���\t\t����\t��������\t���֤��\t�绰����\t�˺����\t���ö��\n");
		for (int i = 0; i < m_List.size(); i++)
		{
			m_List.get(i)->Show();
		}
	}
}

//�������������п���Ϣ
void CardManager::FindCardByName(string strName)
{
	string num = m_List.get(strName,0);
	if (num.empty())
	{
		printf("�޸��û������������п���Ϣ\n");
	}
	else
	{
		printf("�û���\t\t����\t��������\t���֤��\t�绰����\t�˺����\t���ö��\n");
		int count[100] = { 0 };
		//��ȡ����
		int j;
		for (j = 0; num.size() != 0; j++)
		{
			count[j] = atoi(num.substr(0, num.find('|', 0)).c_str());
			num = num.erase(0, num.find('|', 0));
		}
		//�����������еĿ�����Ϣ
		for (int i = 0; i < j; i++)
		{
			m_List.get(i)->Show();
		}
	}
}

/***********��¼��������ݲ�������***************/

//��Ǯ 0�ɹ� 1ϵͳ�쳣
int CardManager::Deposit(string strNum, int money)
{
	Card* card = CreateCard(strNum);
	int s32oldMoney = card->Gets32Money();
	card->Deposit(money);
	if (!m_List.modify(card))                      //�����޸ĳɹ�
		return 0;
	else
	{
		card->Sets32Money(s32oldMoney);             //�����޸Ĳ��ɹ�
		return 1;
	}	
}

//ȡǮ 0�ɹ� 1���ɹ� 2ϵͳ�쳣
int CardManager::Withdraw(string strNum, int money)
{
	Card* card = CreateCard(strNum);
	if (card->GetAvailM() >= money)                      //�����
	{
		card->Withdraw(money);
		if (card->Gets32Type() == 0)                    //���
		{
			int s32oldMoney = card->Gets32Money();
			if (!m_List.modify(card))                      //�����޸ĳɹ�
				return 0;
			else
			{
				card->Sets32Money(s32oldMoney);             //�����޸Ĳ��ɹ�
				return 2;
			}
		}
		else
		{
			int s32oldMoney = card->Gets32Money();
			int s32oldLimit = card->Gets32Limit();
			if (!m_List.modify(card,0))                      //�����޸ĳɹ�
				return 0;
			else
			{
				card->Sets32Money(s32oldMoney);             //�����޸Ĳ��ɹ�
				card->Sets32Money(s32oldLimit);             //�����޸Ĳ��ɹ�
				return 2;
			}
		}	
	}
	else
		return 1;
}

//ת�� 0�ɹ� 1���Ų����� 2���� 3ϵͳ�쳣
int CardManager::Transfer(string strNum, string strTransferNum, int money)
{
	Card* card = CreateCard(strNum);
	Card* TransferCard = CreateCard(strTransferNum);
	if (TransferCard->GetstrNum().empty())        
		return 1;
	if (card->GetAvailM() >= money)                      //�����
	{
		int i = Withdraw(strNum,money);
		int j = Deposit(strTransferNum,money);
		if (!(i || j))
			return 0;
		else
			return 3;
	}
	else
		return 2;
}

//��ȡ���  ���������
int CardManager::GetAvailM(string strNum)
{
	Card* card = CreateCard(strNum);
	return card->GetAvailM();
}

//�޸����� 0�ɹ� 1���ɹ�
int CardManager::ChangePwd(string strNum, string strPwd,string strPwdSure)
{
	if (strPwd == strPwdSure)       //������������һ��
	{
		Card* card = CreateCard(strNum);
		string oldPwd = card->GetstrPwd();
		card->SetstrPwd(strPwd);
		if (!m_List.modify(card))  //�޸�����ɹ�
			return 0;
		else
		{
			card->SetstrPwd(oldPwd);
			return 1;
		}		
	}
	else
		return 1;
}

//��ȡ�û���
string CardManager::GetstrName(string strNum)
{
	Card* card = CreateCard(strNum);
	if (card->GetstrNum().empty())
		return "null";
	else
		return card->GetstrName();
}

//�˳�	
void CardManager::Exit(string strNum)
{
	Card* card = CreateCard(strNum);
	file.File_Modify(*card,card->Gets32Type());
}