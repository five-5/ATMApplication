#pragma once
#include<iostream>
#include "CardManager.h"
#include<string>
#include "Card.h"

using namespace std;

class ATMMainMenuUI
{
private:
	CardManager* cardManager;
public:
	ATMMainMenuUI(CardManager* cardManager);
	~ATMMainMenuUI(void);
	void MainMenuUI(string CardNum);
    void GetAvailMUI(string CardNum);
    void DepositUI(string CardNum);
	void DepositSuccessUI(string CardNum);
    void WithdrawUI(string CardNum);
	void WithdrawSuccessUI(string CardNum);
	void WithdrawFailUI(string CardNum);
    void TransferMUI(string CardNum);
	void TransferMSuccessUI(string CardNum);
	void TransferMFailForMUI(string CardNum);
	void TransferMFailForNUI(string CardNum);
    void ChangePwdUI(string CardNum);
	void ChangePwdSuccessUI(string CardNum);
	void ChangePwdFailUI(string CardNum);
	void LogoutUI(string CardNum);
};

