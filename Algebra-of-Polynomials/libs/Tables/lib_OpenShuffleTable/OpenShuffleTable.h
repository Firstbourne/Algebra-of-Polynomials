#ifndef LIB_OPENSHUFFLETABLE_OPENSHUFFLETABLE_H_
#define LIB_OPENSHUFFLETABLE_OPENSHUFFLETABLE_H_

#include "..\lib_HashTable\HashTable.h"
template <typename TKey, typename TValue>
class OpenShuffleTable : public HashTable<TKey, TValue> {
    int count;
    int size;
    double loadFactor;
    int findFreeIndex(TKey key);
    virtual int hash(TKey key);
    virtual void resize(int newSize);
    TTableRecord<TKey, TValue>* data;
public:
    OpenShuffleTable();
    ~OpenShuffleTable();
    virtual int insert(TKey key, TValue value);
    virtual int remove(TKey key);
    virtual TValue find(TKey key);
    virtual void print();
};

template <typename TKey, typename TValue>
OpenShuffleTable<TKey, TValue>::OpenShuffleTable() {
    size = 100; // íà÷àëüíûé ðàçìåð òàáëèöû
    count = 0; // êîëè÷åñòâî ýëåìåíòîâ â òàáëèöå
    loadFactor = 0.75; // ìàêñèìàëüíàÿ çàãðóçêà òàáëèöû 
    data = new TTableRecord<TKey, TValue>[size];
}

template <typename TKey, typename TValue>
OpenShuffleTable<TKey, TValue>::~OpenShuffleTable() {
    delete[] data;
}

template <typename TKey, typename TValue>
int OpenShuffleTable<TKey, TValue>::insert(TKey key, TValue value) {
    if (count >= size * loadFactor) {
        // Åñëè äîñòèãíóòà ìàêñèìàëüíàÿ çàãðóçêà òàáëèöû, òî óâåëè÷èâàåì åå ðàçìåð
        resize(size * 2);
    }

    int index = findFreeIndex(key);
    if (index != -1) {
        // Åñëè íàøëè ñâîáîäíûé èíäåêñ, òî âñòàâëÿåì ýëåìåíò
        TTableRecord<TKey, TValue> record = { key, value };
        data[index] = record;
        count++;
    }

    return 0;
}

template <typename TKey, typename TValue>
int OpenShuffleTable<TKey, TValue>::remove(TKey key) {
    try {
        int index = findFreeIndex(key);
        if (index != -1) {
            // Åñëè íàøëè ýëåìåíò ñ òàêèì æå êëþ÷îì, òî óäàëÿåì åãî
            data[index] = TTableRecord<TKey, TValue>(TKey(), TValue());
            count--;
            return 0;
        }
        throw std::runtime_error("This object not found");
    }
    catch (const std::exception& ex) {
        std::cerr << "Error:" << ex.what() << std::endl;
    }
}

template <typename TKey, typename TValue>
TValue OpenShuffleTable<TKey, TValue>::find(TKey key) {
    try {
        int index = findFreeIndex(key);
        if (index != -1) {
            // Åñëè íàøëè ýëåìåíò ñ òàêèì æå êëþ÷îì, òî âîçâðàùàåì åãî çíà÷åíèå
            return data[index].value;
        }
        // Åñëè ýëåìåíò íå íàéäåí, òî âîçâðàùàåì îøèáêó
        throw std::runtime_error("This object not found");
    }
    catch (const std::exception& ex) {
        std::cerr << "Error:" << ex.what() << std::endl;
    }
}

template <typename TKey, typename TValue>
void OpenShuffleTable<TKey, TValue>::print() {
    std::cout << "Open Shuffle Table:" << std::endl;
    std::cout << "{ ";
    for (int i = 0; i < size; i++) {
        if (data[i].key != TKey()) {
            if constexpr (std::is_same_v<TValue, Polynom>) {
                std::cout << "(" << data[i].key << ", " << data[i].value.toString() << ") ";
            }
            else {
                std::cout << "(" << data[i].key << ", " << data[i].value << ") ";
            }
            
        }
    }
    std::cout << "}" << std::endl;
}

template <typename TKey, typename TValue>
int OpenShuffleTable<TKey, TValue>::hash(TKey key) {
    return std::hash<TKey>()(key) % size;
}

template <typename TKey, typename TValue>
int OpenShuffleTable<TKey, TValue>::findFreeIndex(TKey key) {
    int index = hash(key);
    int startIndex = index;
    do {
        if (data[index].key == key || data[index].key == TKey()) {
            // Åñëè íàøëè ýëåìåíò ñ òàêèì æå êëþ÷îì èëè ýëåìåíò áåç êëþ÷à,
            // òî âîçâðàùàåì èíäåêñ
            return index;
        }
        index = (index + 1) % size; // äâèãàåìñÿ ïî òàáëèöå
    } while (index != startIndex);
    // Åñëè ïðîøëè âñþ òàáëèöó è íå íàøëè ñâîáîäíûé èíäåêñ, òî âîçâðàùàåì -1
    return -1;
}

template <typename TKey, typename TValue>
void OpenShuffleTable<TKey, TValue>::resize(int newSize) {
    TTableRecord<TKey, TValue>* newData = new TTableRecord<TKey, TValue>[newSize];
    for (int i = 0; i < newSize; i++) {
        newData[i].key = TKey();
        newData[i].value = TValue();
    }
    int newCount = 0;
    for (int i = 0; i < size; i++) {
        if (data[i].key != TKey()) {
            int newIndex = findFreeIndex(data[i].key);
            newData[newIndex].key = data[i].key;
            newData[newIndex].value = data[i].value;
            ++newCount;
        }
    }
    delete[] data;
    data = newData;
    size = newSize;
    count = newCount;
}

#endif // !LIB_OPENSHUFFLETABLE_OPENSHUFFLETABLE_H_