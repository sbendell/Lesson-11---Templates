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
	T** newValues = new T*[Size() + 1];

	for (int i = 0; i < arraySize; i++)
	{
		newValues[i] = values[i];
		delete values[i];
	}
	delete values;

	newValues[Size() - 1] = new T*(item);

	values = newValues;
}

template <typename T>
void MyStack<T>::Pop() {
	delete values[Size() - 1];
}

template <typename T>
int MyStack<T>::Size() {
	return sizeof(values) / sizeof(T);
}

template <typename T>
bool MyStack<T>::Empty() {
	if (sizeof(values) == 0)
		return true;
	else
		return false;
}

