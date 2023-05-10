#ifndef LIB_NODE_NODE_H_
#define LIB_NODE_NODE_H_

#include <string>
#include <sstream>

template <typename TKey, typename TValue>
class Node {
    TValue value;
    TKey key;
	Node<TKey, TValue>* left;
	Node<TKey, TValue>* right;
	Node<TKey, TValue>* top;
	
public:
    Node(TKey key, TValue value) {
        this->key = key;
        this->value = value;
        left = nullptr;
        right = nullptr;
        top = nullptr;
    };
    Node(TValue value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
        top = nullptr;
    };
    Node() {
        left = nullptr;
        right = nullptr;
        top = nullptr;
    }
	TValue& getValue() {
        return value;
    };
    TKey getKey() {
        return key;
    };
	void setValue(TValue value) {
        this->value = value;
    };
	void setKey(TKey key) {
        this->key = key;
    };
	void setLeft(Node<TKey, TValue>* left) {
        this->left = left;
    };
	void setRight(Node<TKey, TValue>* right) {
        this->right = right;
    };
	void setTop(Node<TKey, TValue>* top) {
        this->top = top;
    };
	Node<TKey, TValue>* getLeft() {
        return left;
    };
	Node<TKey, TValue>* getRight() {
        return right;
    };
	Node<TKey, TValue>* getTop() {
        return top;
    };
	Node<TKey, TValue>& operator= (const Node<TKey, TValue>& node) {
        if (this == &node) return *this;
        key = node.key;
        value = node.value;
        left = node.left;
        right = node.right;
        top = node.top;
        return *this;
    };

    std::string toString(TValue t) {
        std::ostringstream ss;
        ss << t;
        return ss.str();
    }
};

#endif // !LIB_NODE_NODE_H_