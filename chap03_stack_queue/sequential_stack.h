/*
 * sequential_stack.h
 *
 *  Created on: Dec 9, 2013
 *      Author: Coeus
 */

#ifndef SEQUENTIAL_STACK_H_
#define SEQUENTIAL_STACK_H_

#include <iostream>
#include <assert.h>
#include "istack.h"
static const int kIncrement=20;
static const int kDefaultCapacity=10;

using namespace std;

/***********************************************
 *A sequential stack implementation
 *Internal storage structure is array
 ***********************************************/
template<class T>
class SequentialStack : public IStack<T> {
public:
	SequentialStack(int capacity=kDefaultCapacity);
	virtual ~SequentialStack() { delete[] _elements; }

	virtual void Push(const T& element);
	virtual bool Pop(T& element);
	T Pop(void);
	virtual bool get_top(T& element)const;
	T get_top(void)const;
	virtual bool IsEmpty(void)const {return _top==-1;}
	virtual bool IsFull(void)const {return _top==_capacity-1;}
	virtual int get_size(void)const {return _top+1;}
	virtual void Clear(void) {_top=-1;}

#ifdef _DEBUG
	//print each element in stack,e.g."[1,9,8,7 <-top(3)"
	friend ostream& operator<<(ostream& out,const SequentialStack<T>& stack) {
		if(!stack.IsEmpty()) {
			out<<"[";
			for(int i=0;i<stack._top;i++) {
				out<<stack._elements[i]<<",";
			}
			T top;
			stack.get_top(top);
			out<<top<<" <-top("<<stack._top<<")\n";
		}
		else
			out<<"the stack is empty.\n";
		return out;
	}
#endif
private:
	T *_elements;					//internal array
	int _top;						//top pointer with initial value -1
	int _capacity;					//current length of array
	//expand capacity when it is not enough
	void OverflowProcess(void);
};

//template class shouldn't be implemented in divided files
//this macro can combine them into one manually
#define SEQUENTIAL_STACK_CC_
#include "sequential_stack.cc"

#endif /* SEQUENTIAL_STACK_H_ */
