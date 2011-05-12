/*
 * CList.cpp
 *
 *  Created on: 2011-3-29
 *      Author: zhujianfeng
 */
#ifndef CLIST_CPP_
#define CLIST_CPP_
#include "CList.h"
template<class TYPE, class ARG_TYPE>
CList<TYPE,ARG_TYPE>::CList(int nBlockSize) {
	list<TYPE> temp(nBlockSize,NULL);
	m_list=temp;

}

template<class TYPE, class ARG_TYPE>
int CList<TYPE,ARG_TYPE>::GetCount()const{
	return (int)m_list.size();
}
//
//CList::~CList() {
//	// TODO Auto-generated destructor stub
//}
#endif /* CLIST_CPP_ */
