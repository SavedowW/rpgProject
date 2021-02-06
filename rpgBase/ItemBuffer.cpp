#include "ItemBuffer.h"

ItemBuffer::ItemBuffer(string nName, string nShortName, int nPrice, Rarity nRarity, const vector<Buff>& nEffects, const vector<string>& nDescr, int nId) :
	Item(nName, nShortName, nPrice, BUFFER, nRarity, nDescr, nId)
{
	effects = nEffects;
}