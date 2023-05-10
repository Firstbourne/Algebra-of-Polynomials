#ifndef LIB_TREE_TREE_H_
#define LIB_TREE_TREE_H_
#include "..\lib_Node\Node.h"

template <typename TKey, typename TValue>
class Tree { 
public:
	virtual int insert(TKey key, TValue value) = 0;
	virtual int remove(TKey key) = 0;
    virtual TValue find(TKey key) = 0;
};
#endif // !LIB_TREE_TREE_H_
