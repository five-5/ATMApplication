/*************************************************************************************************************************
**  File Name:  CreditCard.cpp
**  Summary:    Realize the CreditCard's function 
**  Create:     2017-07-06
**  Author:     Shen Huan
**  Update history:
**  NO.     Author         Date              Content
**  1.      Shen Huan    2017-07-06            New
*************************************************************************************************************************/

#include "CreditCard.h"


CreditCard::CreditCard(string strNum,string strName,string strID,string strTel,string strPwd,int s32Limit):Card( strNum, strName, strID, strTel, strPwd)
{
	this->s32Limit = s32Limit;
	s32Type = 1;
}

CreditCard::~CreditCard(void)
{

}

//ȡǮ
int CreditCard::Withdraw(int money)
{
	int count = 0;
	count = this->s32Money + this->s32Limit - money;
	if (count < 0)
		return 1;
	else
	{
		if (s32Money < money)
		{
			s32Limit = s32Limit + s32Money - money;
			s32Money = 0;
		}
		else
			s32Money = s32Money - money;
		return 0;
	}		
}

//��ѯ���ÿ����
int CreditCard::GetAvailM()
{
	return this->s32Money + s32Limit;
}

//����������
CreditCard* CreditCard::GetClassType()
{
	return this;
}

//��ʾ����Ϣ
void CreditCard::Show()
{
	string strType = "���ÿ�";
	printf(" %s  %s  %s  %s  %s  %d  %d\n",strName.c_str(),strNum.c_str(), strType.c_str(), strID.c_str(),strTel.c_str(),s32Money,s32Limit);
}

//seters and geters
//s32Limit
int CreditCard::Gets32Limit()
{
	return s32Limit;
}

void CreditCard::Sets32Limit(int s32Limit)
{
	this->s32Limit = s32Limit;
}