#pragma once
#include "stdafx.h"
#include "ATMMainMenuUI.h"
class ATMMainUI
{
private:
	CardManager* cardManager;
	
public:
	ATMMainUI(CardManager* cardManager);
	~ATMMainUI(void);
	 void MainUI();
	int RegisterUI();
	int LoginUI();
	void LanguageUI();
	void ListAllCardInfoUI();
	void FindCardInfoUI();	
};

