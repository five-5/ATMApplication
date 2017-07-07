// ATM.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CardManager.h"
#include "ATMMainMenuUI.h"
#include "ATMMainUI.h"

static CardManager* cardManager = CardManager::GetInstance();

int _tmain(int argc, _TCHAR* argv[])
{
	ATMMainUI mainUI(cardManager);
	mainUI.MainUI();	
	return 0;
}

