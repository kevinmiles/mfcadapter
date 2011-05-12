/*
 * CObject.h
 *
 *  Created on: 2011-3-29
 *      Author: zhujianfeng
 */

#ifndef COBJECT_H_
#define COBJECT_H_

class CObject {

public:
//
//// Object model (types, destruction, allocation)
//	virtual CRuntimeClass* GetRuntimeClass() const;
//	virtual ~CObject();  // virtual destructors are necessary
//
//	// Diagnostic allocations
//	void* PASCAL operator new(size_t nSize);
//	void* PASCAL operator new(size_t, void* p);
//	void PASCAL operator delete(void* p);
//#if _MSC_VER >= 1200
//	void PASCAL operator delete(void* p, void* pPlace);
//#endif
//
//#if defined(_DEBUG) && !defined(_AFX_NO_DEBUG_CRT)
//	// for file name/line number tracking using DEBUG_NEW
//	void* PASCAL operator new(size_t nSize, LPCSTR lpszFileName, int nLine);
//#if _MSC_VER >= 1200
//	void PASCAL operator delete(void *p, LPCSTR lpszFileName, int nLine);
//#endif
//#endif
//
//	// Disable the copy constructor and assignment by default so you will get
//	//   compiler errors instead of unexpected behaviour if you pass objects
//	//   by value or assign objects.
//protected:
	CObject();
//private:
//	CObject(const CObject& objectSrc);              // no implementation
//	void operator=(const CObject& objectSrc);       // no implementation
//
//// Attributes
//public:
//	BOOL IsSerializable() const;
//	BOOL IsKindOf(const CRuntimeClass* pClass) const;
//
//// Overridables
//	virtual void Serialize(CArchive& ar);
//
//#if defined(_DEBUG) || defined(_AFXDLL)
//	// Diagnostic Support
//	virtual void AssertValid() const;
//	virtual void Dump(CDumpContext& dc) const;
//#endif
//
//// Implementation
//public:
//	static const AFX_DATA CRuntimeClass classCObject;
//#ifdef _AFXDLL
//	static CRuntimeClass* PASCAL _GetBaseClass();
//#endif
};

#endif /* COBJECT_H_ */
