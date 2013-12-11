/*
 * stack.h
 *
 *  Created on: Dec 8, 2013
 *      Author: Coeus
 */

#ifndef STACK_H_
#define STACK_H_

/***********************************************
 *Interface for stack template class
 ***********************************************/
template<class T>
class IStack {
public:
	virtual ~IStack(){}
	virtual void Push(const T& element)=0;
	virtual bool Pop(T& element)=0;
	virtual bool get_top(T& element)const=0;
	virtual bool IsEmpty(void)const=0;
	virtual bool IsFull(void)const=0;
	virtual int get_size(void)const=0;
	virtual void Clear(void)=0;
};

#endif /* STACK_H_ */
