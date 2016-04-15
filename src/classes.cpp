#include "classes.hpp"

//-------------------------------------------------------------TabRecord-------------------------------------------------------

TabRecord::TabRecord(TKey key, TData* data)
{
	this->key = key;
	this->data = data;
}

TKey TabRecord::GetKey(void) const
{
	return key;
}

TData* TabRecord::GetData(void) const
{
	return data;
}


//----------------------------------------------------------------------Table--------------------------------------------------

Table::Table(int size)
{
	count = 0;
	pos = 0;
}

int Table::IsEmpty(void) const
{
	if (count == 0)
		return 0;
	return 1;
}

int Table::IsFull(void) const
{
	if (count == size)
		return 1;
	return 0;
}

int Table::GetCount(void) const
{
	return count;
}

void Table::Reset(void)
{
	pos = 0;
}

int Table::GetNext(void)
{
	if (IsTabEnded())
		return 1;
	pos++;
}

int Table::IsTabEnded(void) const
{
	if (pos == count)
		return 1;
	return 0;
}

//-----------------------------------------------------------ScanTable---------------------------------------------

ScanTable::ScanTable(int size):Table(size)
{
	recs = new TabRecord*[size];
}

ScanTable::~ScanTable()
{
	delete[]recs;
}

TabRecord * ScanTable::Search(TKey key)
{
	for (int i = 0; i < count; i++)
		if (key == recs[i]->GetKey())
		{
			pos = i;
			return recs[i];
		}
	return 0;
}

void ScanTable::Push(TKey key, TData *data)
{
	if (IsFull())
		return;
	recs[count] = new TabRecord(key, data);
	count++;
}

void ScanTable::Remove(TKey key)
{
	if (!Search(key))
		return;
	delete recs[pos];
	recs[pos] = recs[count - 1];
	count--;
}
