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

//����Ԫ�ص���s32Postion+1��Ԫ�ص�ǰ�� ��Ŵ�0��ʼ
//insert�����ڴ棬removeɾ���ڴ�
template <typename dataType>
void LinkListCplus<dataType>::insert(int s32Postion,dataType data)
{
	//�ȼ���������Ч��
	int s32InsertIndex = s32Postion;    //����λ��
	if (s32Postion >= this->m_s32CurrentLen)
	{
		s32InsertIndex = this->m_s32CurrentLen -1;
	}
	else if (s32Postion < 0 ) 
	{
		s32InsertIndex = 0;
	}


	//����ԭ������µ�s32Postion+1��Ԫ�ؼ�������һ��Ԫ��
	LinkNode *ptrPreNode = this->m_pFirst;     
	LinkNode *ptrNode = this->m_pFirst;

	for (int i = 0; i < s32InsertIndex && ptrNode != NULL; i++)
	{
		ptrPreNode = ptrNode;             //�±� Խ��
		ptrNode = ptrNode->pNext;         //ָ�� ������Ч
	}

	LinkNode *ptrNewNode = new LinkNode;  //ָ����ڴ��ǵ�ǰ�����е�
	ptrNewNode->data = data;
	ptrNewNode->pNext = ptrNode;

	if (s32InsertIndex ==0 || ptrPreNode == NULL) //û����һ��Ԫ�أ��½ڵ�Ϊ��һ��Ԫ��
	{
		this->m_pFirst = ptrNewNode;
	}
	else
	{
		ptrPreNode->pNext = ptrNewNode;
	}
	this->m_s32CurrentLen++;
}

//ɾ����s32Postion��Ԫ�ز��ͷ��ڴ�ռ�
template <typename dataType>
void LinkListCplus<dataType>::remove(int s32Postion)
{
	//�ȼ���������Ч��
	if (this->m_s32CurrentLen == 0)               //�ж�����������Ԫ��
	{
		printf("��ǰ��������Ԫ�ؿ�ɾ��\n");
		return;
	}

	int s32RemoveIndex = s32Postion;        //ɾ��λ��
	if (s32Postion >= this->m_s32CurrentLen)
	{
		s32RemoveIndex = this->m_s32CurrentLen -1;
	}
	else if (s32Postion < 0 ) 
	{
		s32RemoveIndex = 0;
	}


	//���ҵ�s32Postion��Ԫ��
	LinkNode *ptrCurrentNode = this->m_pFirst; 
	LinkNode *ptrPreNode = this->m_pFirst; 

	for (int i = 0; i < s32RemoveIndex && ptrCurrentNode != NULL; i++)
	{
		ptrPreNode = ptrCurrentNode;
		ptrCurrentNode = ptrCurrentNode->pNext;
	}

	//ɾ��
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

//��ȡ����ĳ���
template <typename dataType>
int LinkListCplus<dataType>::size()                         //��ɶ����
{
	return this->m_s32CurrentLen;
}

//��ȡ��s32Postion��λ�õ�Ԫ��ֵ
template <typename dataType>
dataType LinkListCplus<dataType>::get(int s32Postion)      //�鲻����ô����ֵ������
{
	//����������Ч��
	if(s32Postion < 0 || s32Postion >= this->m_s32CurrentLen)
	{
		printf("�����ѯλ�ò��Ϸ�\n");
		return NULL;
	}
	else                                        //����λ�úϷ�
	{
		LinkNode *ptrNode = this->m_pFirst;
		for (int i = 0; i < s32Postion; i++)
		{
			ptrNode = ptrNode->pNext;
		}
		return ptrNode->data;
	}
}

//��ȡ����������Ϣ
template <typename dataType>
dataType LinkListCplus<dataType>::get(string strNum)
{
	Card* card = new Card();
	if (size() != 0)                   //����������Ϣ
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

//��ȡ����������Ϣ
template <typename dataType>
string LinkListCplus<dataType>::get(string strName,int i)
{
	string str = "";
	if (size() != 0)                   //����������Ϣ
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

//�޸������е���Ϣ 0�ɹ� 1���ɹ�
template <typename dataType>
int LinkListCplus<dataType>::modify(dataType data)
{
	//�Ȳ�ѯ���������޴���Ϣ
	if (size() != 0)                   //����������Ϣ
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

//�޸������е���Ϣ 0�ɹ� 1���ɹ�
template <typename dataType>
int LinkListCplus<dataType>::modify(dataType data,int i)
{
	//�Ȳ�ѯ���������޴���Ϣ
	if (size() != 0)                   //����������Ϣ
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