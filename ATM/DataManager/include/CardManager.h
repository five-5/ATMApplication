/*************************************************************************************************************************
**  File Name:  CardManager.h
**  Summary:    Define the CardManager's function and parameters
**  Create:     2017-07-06
**  Author:     Shen Huan
**  Update history:
**  NO.     Author         Date              Content
**  1.      Shen Huan    2017-07-06            New
*************************************************************************************************************************/

#pragma once
#include "LinkListCplus.hpp"
#include "FileManager.h"

class CardManager
{
private:
	 LinkListCplus<Card*> m_List;
	 FileManager file;
	 static CardManager* m_instance;
	 CardManager(void);
protected:
	 Card* CreateCard(string strNum);

public:
	~CardManager(void);
	static CardManager* GetInstance();
	int Login(string strNum,string strPwd);             
	int Register(string strNum, string strName, string strID, string strTel, string strPwd);
	int Register(string strNum, string strName, string strID, string strTel, string strPwd, int s32Limit);
	int Deposit(string strNum, int money);
	int Withdraw(string strNum, int money);
	int Transfer(string strNum, string strTransferNum, int money);
	int GetAvailM(string strNum);
	int ChangePwd(string strNum, string strPwd, string strPwdSure);
	void Exit(string strNum);
	string GetPwd();
	string GetNum();
	void FindCardByName(string strName);
	void ListAllCardInfo();
	string GetstrName(string strNum);
};

