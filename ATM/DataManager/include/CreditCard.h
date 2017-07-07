/*************************************************************************************************************************
**  File Name:  CreditCard.h
**  Summary:    Define the CreditCard's function and parameters
**  Create:     2017-07-06
**  Author:     Shen Huan
**  Update history:
**  NO.     Author         Date              Content
**  1.      Shen Huan    2017-07-06            New
*************************************************************************************************************************/

#pragma once
#include "Card.h"


class CreditCard :public Card
{
private:
	int s32Limit;
public:
	CreditCard(string strNum,string strName,string strID,string strTel,string strPwd,int s32Limit);
	~CreditCard(void);
	int GetAvailM();
	void Show();
	CreditCard* GetClassType();
	int Gets32Limit();
	void Sets32Limit(int s32Limit);
	int Withdraw(int money);
};
