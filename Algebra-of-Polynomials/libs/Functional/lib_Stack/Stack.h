#ifndef LIB_STACK_STACK_H_
#define LIB_STACK_STACK_H_

#include <stdio.h>
#include <string>
#include <stdexcept>

template <class TValue>
class Stack {
private:
	TValue* data;
	int _top;
	int size;
public:
    Stack() {
        size = 10;
        _top = -1;
        data = new TValue[size];
    };
    Stack(int size) {
        this->size = size;
        _top = -1;
        data = new TValue[size];
    };
	int push(TValue value) {
        if (isFull()) {
            TValue* newData = new TValue[size + 1];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            size++;
        }
        _top++;
        data[_top] = value;
        return 1;
    };
	TValue pop() {
        if (isEmpty())
            throw std::logic_error("Stack is empty");
        else
            NULL;
        TValue tmp = data[_top];
        TValue* newData = new TValue[size - 1];
        for (int i = 0; i < size - 1; i++) {
            newData[i] = data[i];
        }
        _top--;
        size--;
        delete[] data;
        data = newData;
        return tmp;
    };
	bool isFull() {
        return _top == size - 1;
    };
	bool isEmpty() {
        return _top == -1;
    };
	TValue top() {
        return data[_top];
    };
	Stack<TValue>& operator=(const Stack<TValue>& stk) {
        if (this != &stk) {
            delete[] data;
            size = stk.size;
            _top = stk.top;
            data = new TValue[size];
            for (int i = 0; i <= _top; i++) {
                data[i] = stk.data[i];
            }
        }
        return *this;
    };
};

#endif // !LIB_STACK_STACK_H_
