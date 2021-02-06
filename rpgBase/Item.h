//=============================
//
//   Item.h
//   Item interface
//
//=============================
#pragma once
#include <iostream>
#include <vector>
#include "Buff.h"

using namespace std;

class Item
{
public:
	int itemId;
	string name;
	string shortName;
	int price;
	enum Type {OTHER, WEAPON, ARMOR, BUFFER} type;
	enum Rarity {COMMON, RARE, UNIQUE, LEGENDARY} rarity;
	Item(string nName, string nShortName, int nPrice, Type nType, Rarity nRarity, const vector<string>& nDescr, int nId = 0);
	vector<string> description;
};