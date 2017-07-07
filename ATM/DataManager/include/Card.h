/*************************************************************************************************************************
**  File Name:  Card.h
**  Summary:    Define the Card's function and parameters
**  Create:     2017-07-06
**  Author:     Shen Huan
**  Update history:
**  NO.     Author         Date              Content
**  1.      Shen Huan    2017-07-06            New
*************************************************************************************************************************/
#pragma once
#include "Tools.h"

class Card
{
protected:
	string strNum;    //����
	string strName;   //�û���
	string strID;     //���֤��
	string strTel;    //�绰����
	string strPwd;    //����
	int s32Money;     //���
	int s32Type;      //����

public:
	Card(string strNum,string strName,string strID,string strTel,string strPwd);
	Card();
	~Card(void);
	void ChangePwd(string strPwd);
	void Deposit(int money);
	virtual int Withdraw(int money);
	virtual int GetAvailM();
	virtual void Show();
	virtual Card* GetClassType();

	string GetstrNum();
	void SetstrNum(string strNum);

	string GetstrName();
	void SetstrName(string strName);

	string GetstrID();
	void SetstrID(string strID);

	string GetstrTel();
	void SetstrTel(string strTel);

	string GetstrPwd();
	void SetstrPwd(string strPwd);

	int Gets32Money();
	void Sets32Money(int s32Money);

	int Gets32Type();
	void Sets32Type(int s32Type);

	virtual int Gets32Limit();
	virtual void Sets32Limit(int s32Limit);
};



