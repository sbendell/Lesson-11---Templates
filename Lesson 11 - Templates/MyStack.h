#pragma once

template <typename T>
class MyStack
{
public:
	MyStack();
	~MyStack();
	void Push(T item);
	T Pop();
	int Size();
	bool Empty();
private:
	T* values;
	int size;
};

template <typename T>
MyStack<T>::MyStack():
	size(0) {
	values = new T[size];
}

template <typename T>
MyStack<T>::~MyStack() {

}

template <typename T>
void MyStack<T>::Push(T item) {
	int newArraySize = ++size;
	T* newValues = new T[newArraySize];

	for (int i = 0; i < Size(); i++)
	{
		newValues[i] = values[i];
	}

	delete[] values;
	newValues[newArraySize - 1] = item;

	values = newValues;
}

template <typename T>
T MyStack<T>::Pop() {
	size--;
	return values[Size()];
}

template <typename T>
int MyStack<T>::Size() {
	return size;
}

template <typename T>
bool MyStack<T>::Empty() {
	if (Size == 0)
		return true;
	else
		return false;
}

