#pragma once
#include "CreditCard.h"
#include "LinkListCplus.hpp"

class FileManager
{
public:
	FileManager();
	~FileManager();
	int File_Add(Card card, int type);
	int File_Modify(Card card, int type);
	void File_AllInfo(LinkListCplus<Card*> &List);
};

