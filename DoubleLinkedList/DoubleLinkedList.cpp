#include"DoubleLinkedList.h"

Monster* CreateMonster(MonsterList& list, int hp, std::string name)
{
	Monster* pElement = new Monster{name, hp };


	// 비어 있을 때
	if (list.head == nullptr && list.tail == nullptr)
	{
		list.head = pElement;
		list.tail = pElement;
	}
	else
	{
		pElement->prev = list.tail;
		list.tail->next = pElement;
		list.tail = pElement;
	}

	return pElement;
}


//travers
int GetCountMonsterList(MonsterList& list)
{
	Monster* element = list.head;
	int count{ 0 };

	while (element != nullptr)
	{
		count++;
		element = element->next;
	}

	return count;
}

void PrintMonsterList(MonsterList& list)
{
	Monster* element = list.head;

	while (element != nullptr)
	{
		std::cout << element->name << " : " << element->HP << std::endl;
		element = element->next;
	}
}

void PrintListRecursive(Monster* monster)
{
	if (monster == nullptr)
	{
		return;
	}
	else
	{
		std::cout << monster->name << " : " << monster->HP << std::endl;
		PrintListRecursive(monster->next);
	}
}

Monster* FindMonster(MonsterList& list, std::string name)
{
	Monster* element = list.head;

	while (element != nullptr)
	{
		if (element->name == name)
		{
			return element;
		}

		element = element->next;
	}

	return nullptr;
}

void DeleteList(MonsterList& list)
{
	Monster* element = list.head;

	while (element != nullptr)
	{
		Monster* pTemp = element->next;
		delete element;

		element = pTemp;
	}

	list.head = nullptr;
	list.tail = nullptr;
}

bool Delete(MonsterList& list, std::string name)
{
	Monster* p = FindMonster(list, name);

	if (p != nullptr)
	{
		/*if (list.pHead == list.pTail)
		{
			list.pHead = list.pTail = nullptr;
		}
		else if (list.pHead == p)
		{
			list.pHead = p->pNext;
			list.pHead->pPrev = nullptr;
		}
		else if (list.pTail == p)
		{
			list.pTail = p->pPrev;
			list.pTail->pNext = nullptr;
		}
		else
		{
			p->pPrev->pNext = p->pNext;
			p->pNext->pPrev = p->pPrev;
		}*/

		//좀더 간단하게 표현
		if (p->prev == nullptr)
		{
			list.head = p->next;
		}
		else
		{
			p->prev->next = p->next;
		}

		if (p->next == nullptr)
		{
			list.tail = p->prev;
		}
		else
		{
			p->next->prev = p->prev;
		}

		delete p;

		return true;
	}

	return false;
}