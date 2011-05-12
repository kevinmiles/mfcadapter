/*
 * CList.h
 *
 *  Created on: 2011-3-29
 *      Author: zhujianfeng
 */

#ifndef CLIST_H_
#define CLIST_H_

#include "Types.h"
#include "CObject.h"
#include <list>
using namespace std;
template<class TYPE, class ARG_TYPE> class CList: public CObject {

protected:
	list<TYPE> m_list;
public:
// Construction
	CList(int nBlockSize = 10);
//
//// Attributes (head and tail)
//	// count of elements
	int GetCount() const;
//	BOOL IsEmpty() const;
//
//	// peek at head or tail
//	TYPE& GetHead();
//	TYPE GetHead() const;
//	TYPE& GetTail();
//	TYPE GetTail() const;
//
//// Operations
//	// get head or tail (and remove it) - don't call on empty list !
//	TYPE RemoveHead();
//	TYPE RemoveTail();
//
//	// add before head or after tail
//	POSITION AddHead(ARG_TYPE newElement);
//	POSITION AddTail(ARG_TYPE newElement);
//
//	// add another list of elements before head or after tail
//	void AddHead(CList* pNewList);
//	void AddTail(CList* pNewList);
//
//	// remove all elements
//	void RemoveAll();
//
//	// iteration
//	POSITION GetHeadPosition() const;
//	POSITION GetTailPosition() const;
//	TYPE& GetNext(POSITION& rPosition); // return *Position++
//	TYPE GetNext(POSITION& rPosition) const; // return *Position++
//	TYPE& GetPrev(POSITION& rPosition); // return *Position--
//	TYPE GetPrev(POSITION& rPosition) const; // return *Position--
//
//	// getting/modifying an element at a given position
//	TYPE& GetAt(POSITION position);
//	TYPE GetAt(POSITION position) const;
//	void SetAt(POSITION pos, ARG_TYPE newElement);
//	void RemoveAt(POSITION position);
//
//	// inserting before or after a given position
//	POSITION InsertBefore(POSITION position, ARG_TYPE newElement);
//	POSITION InsertAfter(POSITION position, ARG_TYPE newElement);
//
//	// helper functions (note: O(n) speed)
//	POSITION Find(ARG_TYPE searchValue, POSITION startAfter = NULL) const;
//		// defaults to starting at the HEAD, return NULL if not found
//	POSITION FindIndex(int nIndex) const;
		// get the 'nIndex'th element (may return NULL)

// Implementation
protected:
//	CNode* m_pNodeHead;
//	CNode* m_pNodeTail;
//	int m_nCount;
//	CNode* m_pNodeFree;
//	struct CPlex* m_pBlocks;
//	int m_nBlockSize;
//
//	CNode* NewNode(CNode*, CNode*);
//	void FreeNode(CNode*);

public:
//	~CList();
//	void Serialize(CArchive&);
//#ifdef _DEBUG
//	void Dump(CDumpContext&) const;
//	void AssertValid() const;
//#endif
};
#endif /* CLIST_H_ */

