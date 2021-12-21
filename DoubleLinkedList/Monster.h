#pragma once

#include<iostream>


struct Monster
{
	std::string name{};
	int HP;

	Monster* prev;
	Monster* next;
};