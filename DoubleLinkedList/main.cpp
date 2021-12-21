#include<iostream>
#include"Monster.h"
#include"DoubleLinkedList.h"

int main()
{
	MonsterList myList;

	Monster* newMonster = nullptr;

	CreateMonster(myList, 100, "Demon");
	CreateMonster(myList, 10, "Wolf");
	CreateMonster(myList, 5, "Slime");

	PrintListRecursive(myList.head);
	std::cout << GetCountMonsterList(myList) << std::endl;

	Delete(myList, "Wolf");
	PrintMonsterList(myList);
	std::cout << GetCountMonsterList(myList) << std::endl;

	Delete(myList, "Slime");
	PrintListRecursive(myList.head);
	std::cout << GetCountMonsterList(myList) << std::endl;

	Delete(myList, "Demon");
	PrintListRecursive(myList.head);
	std::cout << GetCountMonsterList(myList) << std::endl;

	DeleteList(myList);

}