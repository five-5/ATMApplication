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
CardManager::CardManager(void)          //将文件全部读入链表中
{
	file.File_AllInfo(m_List);
}

CardManager::~CardManager(void)
{
}

//获取实例
CardManager* CardManager::GetInstance()
{
	if (m_instance == NULL)
		return (new CardManager());
	else
		return m_instance;
}

//生成银行卡类
Card* CardManager::CreateCard(string strNum)
{
	return m_List.get(strNum);
}

//登录  0成功 1不成功   2
int CardManager::Login(string strNum, string strPwd)
{
	//查找卡信息
	Card* card = CreateCard(strNum);
	if (card->GetstrNum().empty())               //没有找到对象
		return 1;
	else
	{
		if (card->GetstrPwd() == strPwd)          //密码相符
			return 0;
		else
			return 1;
	}
}

//注册储蓄卡 0成功 1不成功  2系统异常
int CardManager::Register(string strNum,string strName,string strID,string strTel,string strPwd)
{
	Card* card = new Card(strNum, strName, strID, strTel, strPwd);
	/************test**************/
	//位数未验证
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

//注册信用卡 0成功 1不成功  2系统异常
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

//随机产生密码
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

//随机产生卡号
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
		if (m_List.get(str)->GetstrNum().empty())              //无重复卡号
			          flag = 0;
	}
	return str;
}

//列出所有银行卡信息
void CardManager::ListAllCardInfo()
{
	if (m_List.size() == 0)
		printf("无该用户名开户的银行卡信息\n");
	else
	{
		printf("用户名\t\t卡号\t卡号类型\t身份证号\t电话号码\t账号余额\t信用额度\n");
		for (int i = 0; i < m_List.size(); i++)
		{
			m_List.get(i)->Show();
		}
	}
}

//按姓名查找银行卡信息
void CardManager::FindCardByName(string strName)
{
	string num = m_List.get(strName,0);
	if (num.empty())
	{
		printf("无该用户名开户的银行卡信息\n");
	}
	else
	{
		printf("用户名\t\t卡号\t卡号类型\t身份证号\t电话号码\t账号余额\t信用额度\n");
		int count[100] = { 0 };
		//获取数组
		int j;
		for (j = 0; num.size() != 0; j++)
		{
			count[j] = atoi(num.substr(0, num.find('|', 0)).c_str());
			num = num.erase(0, num.find('|', 0));
		}
		//遍历姓名含有的卡号信息
		for (int i = 0; i < j; i++)
		{
			m_List.get(i)->Show();
		}
	}
}

/***********登录后界面数据操作函数***************/

//存钱 0成功 1系统异常
int CardManager::Deposit(string strNum, int money)
{
	Card* card = CreateCard(strNum);
	int s32oldMoney = card->Gets32Money();
	card->Deposit(money);
	if (!m_List.modify(card))                      //链表修改成功
		return 0;
	else
	{
		card->Sets32Money(s32oldMoney);             //链表修改不成功
		return 1;
	}	
}

//取钱 0成功 1不成功 2系统异常
int CardManager::Withdraw(string strNum, int money)
{
	Card* card = CreateCard(strNum);
	if (card->GetAvailM() >= money)                      //余额足
	{
		card->Withdraw(money);
		if (card->Gets32Type() == 0)                    //储蓄卡
		{
			int s32oldMoney = card->Gets32Money();
			if (!m_List.modify(card))                      //链表修改成功
				return 0;
			else
			{
				card->Sets32Money(s32oldMoney);             //链表修改不成功
				return 2;
			}
		}
		else
		{
			int s32oldMoney = card->Gets32Money();
			int s32oldLimit = card->Gets32Limit();
			if (!m_List.modify(card,0))                      //链表修改成功
				return 0;
			else
			{
				card->Sets32Money(s32oldMoney);             //链表修改不成功
				card->Sets32Money(s32oldLimit);             //链表修改不成功
				return 2;
			}
		}	
	}
	else
		return 1;
}

//转账 0成功 1卡号不存在 2余额不足 3系统异常
int CardManager::Transfer(string strNum, string strTransferNum, int money)
{
	Card* card = CreateCard(strNum);
	Card* TransferCard = CreateCard(strTransferNum);
	if (TransferCard->GetstrNum().empty())        
		return 1;
	if (card->GetAvailM() >= money)                      //余额足
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

//获取余额  返回余额数
int CardManager::GetAvailM(string strNum)
{
	Card* card = CreateCard(strNum);
	return card->GetAvailM();
}

//修改密码 0成功 1不成功
int CardManager::ChangePwd(string strNum, string strPwd,string strPwdSure)
{
	if (strPwd == strPwdSure)       //两次输入密码一致
	{
		Card* card = CreateCard(strNum);
		string oldPwd = card->GetstrPwd();
		card->SetstrPwd(strPwd);
		if (!m_List.modify(card))  //修改链表成功
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

//获取用户名
string CardManager::GetstrName(string strNum)
{
	Card* card = CreateCard(strNum);
	if (card->GetstrNum().empty())
		return "null";
	else
		return card->GetstrName();
}

//退出	
void CardManager::Exit(string strNum)
{
	Card* card = CreateCard(strNum);
	file.File_Modify(*card,card->Gets32Type());
}