#include <iostream>

using namespace std;

typedef char TData;
typedef int TKey;

class TabRecord
{
protected:
	TData *data;
	TKey key;
public:
	TabRecord(TKey, TData*);
	
	TKey GetKey(void) const;
	TData* GetData(void) const;
};

class Table
{
protected:
	int size;
	int count;
	int pos;
public:
	Table(int);
	virtual TabRecord* Search(TKey) const = 0;
	virtual void Push(TKey, TData*) = 0;
	virtual void Remove(TKey) = 0;
	int IsEmpty(void) const;
	int IsFull(void) const;
	int GetCount(void) const;
	virtual void Reset(void);
	virtual int GetNext(void);
	virtual int IsTabEnded(void) const;
};

class ScanTable :public Table
{
protected:
	TabRecord **recs;
public:
	ScanTable(int);
	~ScanTable();
	virtual TabRecord* Search(TKey);
	virtual void Push(TKey, TData*);
	virtual void Remove(TKey);
};
