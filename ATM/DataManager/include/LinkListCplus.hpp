/*************************************************************************************************************************
**  File Name:  LinkListCplus.hpp
**  Summary:    Define the CreditCard's function and parameters and realize the CreditCard's function.
**  Create:     2017-07-06
**  Author:     Shen Huan
**  Update history:
**  NO.     Author         Date              Content
**  1.      Shen Huan    2017-07-06            New
*************************************************************************************************************************/

#pragma once
#include "CreditCard.h"
template <typename dataType>

class LinkListCplus
{
public:
	LinkListCplus();       
	~LinkListCplus();     
	void insert(int s32Postion, dataType data);
	void remove(int s32Postion);               
	int size();                                                
	dataType get(int s32Postion);   
	dataType get(string strNum);
	string get(string strName,int i);
	int modify(dataType data);
	int modify(dataType data,int i);
private:
	struct LinkNode              
	{
		dataType data;
		LinkNode *pNext;
	};
	int m_s32CurrentLen; 
	LinkNode *m_pFirst;
};

template <typename dataType>
LinkListCplus<dataType>::LinkListCplus()
{
	m_s32CurrentLen = 0;
	m_pFirst = NULL;
}

template <typename dataType>
LinkListCplus<dataType>::~LinkListCplus()
{
	while (size() != 0)
		remove(0);
}

//插入元素到第s32Postion+1个元素的前面 序号从0开始
//insert创建内存，remove删除内存
template <typename dataType>
void LinkListCplus<dataType>::insert(int s32Postion,dataType data)
{
	//先检查参数的有效性
	int s32InsertIndex = s32Postion;    //插入位置
	if (s32Postion >= this->m_s32CurrentLen)
	{
		s32InsertIndex = this->m_s32CurrentLen -1;
	}
	else if (s32Postion < 0 ) 
	{
		s32InsertIndex = 0;
	}


	//查找原链表里德第s32Postion+1个元素及它的上一个元素
	LinkNode *ptrPreNode = this->m_pFirst;     
	LinkNode *ptrNode = this->m_pFirst;

	for (int i = 0; i < s32InsertIndex && ptrNode != NULL; i++)
	{
		ptrPreNode = ptrNode;             //下标 越界
		ptrNode = ptrNode->pNext;         //指针 不能无效
	}

	LinkNode *ptrNewNode = new LinkNode;  //指向的内存是当前链表中的
	ptrNewNode->data = data;
	ptrNewNode->pNext = ptrNode;

	if (s32InsertIndex ==0 || ptrPreNode == NULL) //没有上一个元素，新节点为第一个元素
	{
		this->m_pFirst = ptrNewNode;
	}
	else
	{
		ptrPreNode->pNext = ptrNewNode;
	}
	this->m_s32CurrentLen++;
}

//删除第s32Postion个元素并释放内存空间
template <typename dataType>
void LinkListCplus<dataType>::remove(int s32Postion)
{
	//先检查参数的有效性
	if (this->m_s32CurrentLen == 0)               //判断链表中有无元素
	{
		printf("当前链表中无元素可删除\n");
		return;
	}

	int s32RemoveIndex = s32Postion;        //删除位置
	if (s32Postion >= this->m_s32CurrentLen)
	{
		s32RemoveIndex = this->m_s32CurrentLen -1;
	}
	else if (s32Postion < 0 ) 
	{
		s32RemoveIndex = 0;
	}


	//查找第s32Postion个元素
	LinkNode *ptrCurrentNode = this->m_pFirst; 
	LinkNode *ptrPreNode = this->m_pFirst; 

	for (int i = 0; i < s32RemoveIndex && ptrCurrentNode != NULL; i++)
	{
		ptrPreNode = ptrCurrentNode;
		ptrCurrentNode = ptrCurrentNode->pNext;
	}

	//删除
	if (s32RemoveIndex ==0)  
	{
		this->m_pFirst = ptrCurrentNode->pNext;
	}
	else
	{
		ptrPreNode->pNext = ptrCurrentNode->pNext;
	}
	this->m_s32CurrentLen--;
	delete ptrCurrentNode;
}

//获取链表的长度
template <typename dataType>
int LinkListCplus<dataType>::size()                         //有啥子用
{
	return this->m_s32CurrentLen;
}

//获取第s32Postion个位置的元素值
template <typename dataType>
dataType LinkListCplus<dataType>::get(int s32Postion)      //查不到怎么返回值。。。
{
	//检查参数的有效性
	if(s32Postion < 0 || s32Postion >= this->m_s32CurrentLen)
	{
		printf("输入查询位置不合法\n");
		return NULL;
	}
	else                                        //输入位置合法
	{
		LinkNode *ptrNode = this->m_pFirst;
		for (int i = 0; i < s32Postion; i++)
		{
			ptrNode = ptrNode->pNext;
		}
		return ptrNode->data;
	}
}

//获取链表数据信息
template <typename dataType>
dataType LinkListCplus<dataType>::get(string strNum)
{
	Card* card = new Card();
	if (size() != 0)                   //链表中有信息
	{
		LinkNode *ptrNode = this->m_pFirst;
		while (ptrNode != NULL)
		{
			if (ptrNode->data->GetstrNum() == strNum)
			{
				delete card;
				return ptrNode->data;
			}
			ptrNode = ptrNode->pNext;
		}
		return card;
	}
	else 
		return card;
}

//获取链表数据信息
template <typename dataType>
string LinkListCplus<dataType>::get(string strName,int i)
{
	string str = "";
	if (size() != 0)                   //链表中有信息
	{
		LinkNode *ptrNode = this->m_pFirst;
		int i = 0;
		while (ptrNode != NULL)
		{
			if (ptrNode->data->GetstrName() == strName)
			{
					str.append(1,char(i)).append(1,'|');
			}
			ptrNode = ptrNode->pNext;
			i++;
		}
		return str;
	}
	else
		return str;
}

//修改链表中的信息 0成功 1不成功
template <typename dataType>
int LinkListCplus<dataType>::modify(dataType data)
{
	//先查询链表中有无此信息
	if (size() != 0)                   //链表中有信息
	{
		LinkNode *ptrNode = this->m_pFirst;
		while(ptrNode != NULL)
		{
			if (ptrNode->data->GetstrNum() == data->GetstrNum())
			{
				ptrNode->data->SetstrPwd(data->GetstrPwd());
				ptrNode->data->Sets32Money(data->Gets32Money());
				return 0;
			}
			else
				ptrNode = ptrNode->pNext;
		}
		return 1;
	}
	else
		return 1;
}

//修改链表中的信息 0成功 1不成功
template <typename dataType>
int LinkListCplus<dataType>::modify(dataType data,int i)
{
	//先查询链表中有无此信息
	if (size() != 0)                   //链表中有信息
	{
		LinkNode *ptrNode = this->m_pFirst;
		while (ptrNode != NULL)
		{
			if (ptrNode->data->GetstrNum() == data->GetstrNum())
			{
				ptrNode->data->Sets32Money(data->Gets32Money());
				ptrNode->data->Sets32Limit(data->Gets32Limit());
				return 0;
			}
			else
				ptrNode = ptrNode->pNext;
		}
		return 1;
	}
	else
		return 1;
}