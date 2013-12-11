/*
 * sequential_stack.cc
 *
 *  Created on: Dec 8, 2013
 *      Author: Coeus
 */

#ifdef SEQUENTIAL_STACK_CC_

template<class T>
SequentialStack<T>::SequentialStack(int capacity) : _top(-1),_capacity(capacity) {
	_elements=new T[capacity];
	assert(_elements!=NULL);
}

template<class T>
void SequentialStack<T>::Push(const T& element) {
	if(IsFull())
		OverflowProcess();
	_elements[++_top]=element;
}

template<class T>
bool SequentialStack<T>::Pop(T& element) {
	if(_top==-1)
		return false;
	element=Pop();
	return true;
}

template<class T>
T SequentialStack<T>::Pop() {
	return _elements[_top--];
}

template<class T>
bool SequentialStack<T>::get_top(T& element)const {
	if(_top==-1)
		return false;
	element=get_top();
	return true;
}

template<class T>
T SequentialStack<T>::get_top()const {
	return _elements[_top];
}

template<class T>
void SequentialStack<T>::OverflowProcess() {
	_capacity+=kIncrement;
	T* tmp=new T[_capacity];
	assert(tmp!=NULL);
	for(int i=0;i<_capacity;i++)
		tmp[i]=_elements[i];
	delete[] _elements;
	_elements=tmp;
}

#endif

