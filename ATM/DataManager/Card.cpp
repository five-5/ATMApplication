/*************************************************************************************************************************
**  File Name:  Card.cpp
**  Summary:    Realize the Card's function
**  Create:     2017-07-06 
**  Author:     Shen Huan
**  Update history:
**  NO.     Author         Date              Content
**  1.      Shen Huan    2017-07-06            New
*************************************************************************************************************************/

#include "Card.h"


Card::Card(string strNum,string strName,string strID,string strTel,string strPwd)
{
	this->strNum = strNum;
	this->strName = strName;
	this->strID = strID;                   
	this->strTel = strTel;
	this->strPwd = strPwd;
	s32Money = 0;                      //Ä¬ÈÏÒøĞĞ¿¨ÖĞÓà¶îÎª0
	s32Type = 0;                       //
}

Card::Card()
{
	strNum = "";
	strName = "";
	strID = "";
	strTel = "";
	strPwd = "";
}

//ĞŞ¸ÄÃÜÂë
void Card::ChangePwd(string strPwd)
{
	this->strPwd = strPwd;
}

//´æÇ®
void Card::Deposit(int money)
{
	this->s32Money = this->s32Money + money;
}

//È¡Ç®
int Card::Withdraw(int money)                   //Óà¶î×ã·µ»Ø0£¬Óà¶î²»×ã·µ»Ø1
{
	int count = 0;
	count = this->s32Money - money;
	if (count < 0)
		return 1;
	else
	{
		s32Money = s32Money - money;
		return 0;
	}	
}
	
//²éÑ¯Óà¶î
int Card::GetAvailM()
{
	return s32Money;
}

//ÏÔÊ¾¿¨ĞÅÏ¢
void Card::Show()
{
	string strType = "´¢Ğî¿¨";
	printf(" %s  %s  %s  %s  %s  %d\n",strName.c_str(),strNum.c_str(), strType.c_str(), strID.c_str(),strTel.c_str(),s32Money);
}

//·µ»ØÀàÀàĞÍ
Card* Card::GetClassType()
{
	return this;
}

Card::~Card(void)
{

}

/*seters and geters*/
//strNum
string Card::GetstrNum()
{
	return strNum;
}

void Card::SetstrNum(string strNum)
{
	this->strNum = strNum;
}

//strName
string Card::GetstrName()
{
	return strName;
}

void Card::SetstrName(string strName)
{
	this->strName = strName;
}

//strID
string Card::GetstrID()
{
	return strID;
}

void Card::SetstrID(string strID)
{

}

//strTel
string Card::GetstrTel()
{
	return strTel;
}

void Card::SetstrTel(string strTel)
{
	this->strTel = strTel;
}

//strPwd
string Card::GetstrPwd()
{
	return strPwd;
}

void Card::SetstrPwd(string strPwd)
{
	this->strPwd = strPwd;
}

//s32Money
int Card::Gets32Money()
{
	return s32Money;
}

void Card::Sets32Money(int s32Money)
{
	this->s32Money = s32Money;
}

//s32Type
int Card::Gets32Type()
{
	return s32Type;
}

void Card::Sets32Type(int s32Type)
{
	this->s32Type = s32Type;
}

int Card::Gets32Limit()
{
	return 0;
}

void Card::Sets32Limit(int s32Limit)
{
	
}