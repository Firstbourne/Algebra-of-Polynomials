#ifndef LIB_TABLE_TABLE_H_
#define LIB_TABLE_TABLE_H_

#include <iostream>
#include "TTableRecord.h"
#include "../../Functional/lib_Polynom/Polynom.h"
template <typename TKey, typename TValue>
class Table {
public:
    virtual int insert(TKey key, TValue value) = 0;
    virtual int remove(TKey key) = 0;
    virtual TValue find(TKey key) = 0;
    virtual void print() = 0;
};

#endif // !LIB_TABLE_TABLE_H_