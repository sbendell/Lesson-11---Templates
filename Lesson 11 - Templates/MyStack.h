#pragma once

template <typename T>
class MyStack
{
public:
	MyStack();
	~MyStack();
	void Push(T item);
	void Pop();
	int Size();
	bool Empty();
private:
	T** values;
};

template <typename T>
MyStack<T>::MyStack() {
}

template <typename T>
MyStack<T>::~MyStack() {

}

template <typename T>
void MyStack<T>::Push(T item) {

}

template <typename T>
void MyStack<T>::Pop() {

}

template <typename T>
int MyStack<T>::Size() {
	return sizeof(values) / sizeof(T);
}

template <typename T>
bool MyStack<T>::Empty() {

}

