#ifndef LIB_SORTEDARRAYTABLE_SORTEDARRAYTABLE_H_
#define LIB_SORTEDARRAYTABLE_SORTEDARRAYTABLE_H_

#include "..\lib_SortedTable\SortedTable.h"
#include <algorithm>

template <typename TKey, typename TValue>
class SortedArrayTable : public SortedTable<TKey, TValue> {
	size_t size;
	size_t count;
	TTableRecord<TKey, TValue>* data;
	double loadFactor;
public:
	SortedArrayTable();
	~SortedArrayTable();
	virtual int insert(TKey key, TValue value) override;
	virtual int remove(TKey key) override;
	virtual TValue find(TKey key) override;
	virtual void print() override;
};

template<typename TKey, typename TValue>
SortedArrayTable<TKey, TValue>::SortedArrayTable() {
	size = 100;
	count = 0;
	loadFactor = 0.75;
	data = new TTableRecord<TKey, TValue>[size];
}

template<typename TKey, typename TValue>
SortedArrayTable<TKey, TValue>::~SortedArrayTable() {
	delete[] data;
}

template<typename TKey, typename TValue>
int SortedArrayTable<TKey, TValue>::insert(TKey key, TValue value) {
	if (count >= size * loadFactor) {
		size_t newSize = size * 2;
		TTableRecord<TKey, TValue>* newData = new TTableRecord<TKey, TValue>[newSize];
		std::copy(data, data + count, newData);
		delete[] data;
		data = newData;
		size = newSize;
	}

	size_t left = 0;
	size_t right = count;

	while (left < right) {
		size_t mid = (left + right) / 2;
		if (data[mid].key == key) {
			throw std::runtime_error("Duplicate key");
		}
		else if (data[mid].key < key) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	for (size_t i = count; i > left; --i) {
		data[i] = data[i - 1];
	}

	data[left].key = key;
	data[left].value = value;
	++count;

	return 0;
}

template<typename TKey, typename TValue>
int SortedArrayTable<TKey, TValue>::remove(TKey key) {
	for (size_t index = 0; index < count; index++) {
		if (data[index].key == key) {
			for (size_t j = index + 1; j < count; j++) {
				data[j - 1] = data[j];
			}
			count--;
			return 0;
		}
	}
	throw std::runtime_error("This object not found");
}

template<typename TKey, typename TValue>
TValue SortedArrayTable<TKey, TValue>::find(TKey key) {
	try {
		for (size_t index = 0; index < count; index++) {
			if (data[index].key == key) {
				return data[index].value;
			}
		}
		throw std::runtime_error("This object not found");
	}
	catch (const std::exception& ex) {
		std::cerr << "Error:" << ex.what() << std::endl;
		return TValue();
	}
}

template<typename TKey, typename TValue>
void SortedArrayTable<TKey, TValue>::print() {
	std::cout << "Sorted Array Table:" << std::endl;
	std::cout << "Table contents:" << std::endl;
	for (size_t index = 0; index < count; index++) {
		if constexpr (std::is_same_v<TValue, Polynom>) {
			std::cout << "  " << data[index].key << ": " << data[index].value.toString() << std::endl;
		}
		else {
			std::cout << "  " << data[index].key << ": " << data[index].value << std::endl;
		}
	}
}

#endif // !LIB_SORTEDARRAYTABLE_SORTEDARRAYTABLE_H_