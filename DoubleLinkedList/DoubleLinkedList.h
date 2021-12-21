#pragma once

#include"Monster.h"

struct MonsterList
{
	Monster* head = nullptr;
	Monster* tail = nullptr;
};

Monster* CreateMonster(MonsterList& list, int hp, std::string name);
Monster* FindMonster(MonsterList& list, std::string name);
int GetCountMonsterList(MonsterList& list);
void PrintListRecursive(Monster* monster);
void DeleteList(MonsterList& list);
bool Delete(MonsterList& list, std::string name);
void PrintMonsterList(MonsterList& list);