#ifndef LIB_SORTEDTABLE_SORTEDTABLE_H_
#define LIB_SORTEDTABLE_SORTEDTABLE_H_

#include "..\lib_UnorderedTable\UnorderedTable.h"
template <typename TKey, typename TValue>
class SortedTable : public UnorderedTable<TKey, TValue> {
public:
	virtual int insert(TKey key, TValue value) = 0;
	virtual int remove(TKey key) = 0;
	virtual TValue find(TKey key) = 0;
	virtual void print() = 0;
};
#endif // !LIB_SORTEDTABLE_SORTEDTABLE_H_