/*
 * CString.h
 *
 *  Created on: 2011-3-8
 *      Author: zhujianfeng
 */
#include <string>
#include <iostream>
#include "Types.h"
#ifndef CSTRING_H_
#define CSTRING_H_
using namespace std;
class CString {
public:
// Constructors

	// constructs empty CString
	CString();
	// copy constructor
	CString(const CString& stringSrc);
	// from a single character
	CString(TCHAR ch, int nRepeat = 1);
//	// from an ANSI string (converts to TCHAR)
	CString(LPCSTR lpsz);
//	// from a UNICODE string (converts to TCHAR)
//	CString(LPCWSTR lpsz);
//	// subset of characters from an ANSI string (converts to TCHAR)
//	CString(LPCSTR lpch, int nLength);
//	// subset of characters from a UNICODE string (converts to TCHAR)
//	CString(LPCWSTR lpch, int nLength);
//	// from unsigned characters
//	CString(const unsigned char* psz);


	string GetCppStr();
//// Attributes & Operations

//	// get data length
	int GetLength() const;
//	// TRUE if zero length
	BOOL IsEmpty() const;
//	// clear contents to empty
	void Empty();
//
//	// return single character at zero-based index
	TCHAR GetAt(int nIndex) const;
//	// return single character at zero-based index
	TCHAR operator[](int nIndex) const;
//	// set a single character at zero-based index
	void SetAt(int nIndex, TCHAR ch);
//	// return pointer to const string
//	operator LPCSTR() const;
//
//	// overloaded assignment
//
//	// ref-counted copy from another CString
	const CString& operator=(const CString& stringSrc);
//	// set string content to single character
	const CString& operator=(TCHAR ch);
//#ifdef _UNICODE
//	const CString& operator=(char ch);
//#endif
//	// copy string content from ANSI string (converts to TCHAR)
	const CString& operator=(LPCSTR lpsz);
//	// copy string content from UNICODE string (converts to TCHAR)
//	const CString& operator=(LPCWSTR lpsz);
//	// copy string content from unsigned chars
//	const CString& operator=(const unsigned char* psz);
//
//	// string concatenation
//
//	// concatenate from another CString
	const CString& operator+=(const CString& stringSrc);
//
//	// concatenate a single character
	const CString& operator+=(TCHAR ch);
//#ifdef _UNICODE
//	// concatenate an ANSI character after converting it to TCHAR
//	const CString& operator+=(char ch);
//#endif
//	// concatenate a UNICODE character after converting it to TCHAR
	const CString& operator+=(LPCSTR lpsz);
//
	CString operator+(const CString& string1);
    CString operator+(TCHAR ch);
//	friend CString operator+(TCHAR ch, const CString& string);
//#ifdef _UNICODE
//	friend CString AFXAPI operator+(const CString& string, char ch);
//	friend CString AFXAPI operator+(char ch, const CString& string);
//#endif
	CString operator+(LPCSTR lpsz);
//	friend CString AFXAPI operator+(LPCTSTR lpsz, const CString& string);
//
//	// string comparison
//
//	// straight character comparison
	int Compare(LPCSTR lpsz) const;
	int Compare(CString &str) const;
//	// compare ignoring case
	int CompareNoCase(LPCSTR lpsz) const;
	int CompareNoCase(CString &str) const;
//	// NLS aware comparison, case sensitive
//	int Collate(LPCTSTR lpsz) const;
//	// NLS aware comparison, case insensitive
//	int CollateNoCase(LPCTSTR lpsz) const;
//
//	// simple sub-string extraction
//
//	// return nCount characters starting at zero-based nFirst
	CString Mid(int nFirst, int nCount) const;
//	// return all characters starting at zero-based nFirst
	CString Mid(int nFirst) const;
//	// return first nCount characters in string
	CString Left(int nCount) const;
//	// return nCount characters from end of string
	CString Right(int nCount) const;
//
//	//  characters from beginning that are also in passed string
//	CString SpanIncluding(LPCTSTR lpszCharSet) const;
//	// characters from beginning that are not also in passed string
//	CString SpanExcluding(LPCTSTR lpszCharSet) const;
//
//	// upper/lower/reverse conversion
//
//	// NLS aware conversion to uppercase
	void MakeUpper();
//	// NLS aware conversion to lowercase
	void MakeLower();
//	// reverse string right-to-left
	void MakeReverse();
//
//	// trimming whitespace (either side)
//
//	// remove whitespace starting from right edge
	void TrimRight();
//	// remove whitespace starting from left side
	void TrimLeft();
//
//	// trimming anything (either side)
//
//	// remove continuous occurrences of chTarget starting from right
	void TrimRight(TCHAR chTarget);
//	// remove continuous occcurrences of characters in passed string,
//	// starting from right
	void TrimRight(LPCSTR lpszTargets);
//	// remove continuous occurrences of chTarget starting from left
	void TrimLeft(TCHAR chTarget);
//	// remove continuous occcurrences of characters in
//	// passed string, starting from left
	void TrimLeft(LPCSTR lpszTargets);
//
//	// advanced manipulation
//
//	// replace occurrences of chOld with chNew
	int Replace(TCHAR chOld, TCHAR chNew);
//	// replace occurrences of substring lpszOld with lpszNew;
//	// empty lpszNew removes instances of lpszOld
	int Replace(LPCSTR lpszOld, LPCSTR lpszNew);
	int Replace(CString lpszOld, CString lpszNew);
//	// remove occurrences of chRemove
	int Remove(TCHAR chRemove);
//	// insert character at zero-based index; concatenates
//	// if index is past end of string
	int Insert(int nIndex, TCHAR ch);
//	// insert substring at zero-based index; concatenates
//	// if index is past end of string
	int Insert(int nIndex, LPCSTR pstr);
	int Insert(int nIndex, CString pstr);
//	// delete nCount characters starting at zero-based index
	int Delete(int nIndex, int nCount = 1);
//
//	// searching
//
//	// find character starting at left, -1 if not found
	int Find(TCHAR ch) const;
//	// find character starting at right
	int ReverseFind(TCHAR ch) const;
//	// find character starting at zero-based index and going right
	int Find(TCHAR ch, int nStart) const;
//	// find first instance of any character in passed string
	int FindOneOf(LPCSTR lpszCharSet) const;
	int FindOneOf(CString lpszCharSet) const;
//	// find first instance of substring
	int Find(LPCSTR lpszSub) const;
	int Find(CString lpszSub) const;
//	// find first instance of substring starting at zero-based index
	int Find(LPCSTR lpszSub, int nStart) const;
	int Find(CString lpszSub, int nStart) const;
//
//	// simple formatting
//
//	// printf-like formatting using passed string
	void Format(LPCSTR lpszFormat, ...);
//	// printf-like formatting using referenced string resource
//	void Format(UINT nFormatID, ...);
//	// printf-like formatting using variable arguments parameter
//	void FormatV(LPCTSTR lpszFormat, va_list argList);
//
//	// formatting for localization (uses FormatMessage API)
//
//	// format using FormatMessage API on passed string
//	void AFX_CDECL FormatMessage(LPCTSTR lpszFormat, ...);
//	// format using FormatMessage API on referenced string resource
//	void AFX_CDECL FormatMessage(UINT nFormatID, ...);
//
//	// input and output
//#ifdef _DEBUG
//	friend CDumpContext& operator<<(CDumpContext& dc,const CString& string);
//#endif
//	friend CArchive& AFXAPI operator<<(CArchive& ar, const CString& string);
//	friend CArchive& AFXAPI operator>>(CArchive& ar, CString& string);

//	// load from string resource
//	BOOL LoadString(UINT nID);
//
//#ifndef _UNICODE
//	// ANSI <-> OEM support (convert string in place)
//
//	// convert string from ANSI to OEM in-place
//	void AnsiToOem();
//	// convert string from OEM to ANSI in-place
//	void OemToAnsi();
//#endif
//
//#ifndef _AFX_NO_BSTR_SUPPORT
//	// OLE BSTR support (use for OLE automation)
//
//	// return a BSTR initialized with this CString's data
//	BSTR AllocSysString() const;
//	// reallocates the passed BSTR, copies content of this CString to it
//	BSTR SetSysString(BSTR* pbstr) const;
//#endif
//
//	// Access to string implementation buffer as "C" character array
//
//	// get pointer to modifiable buffer at least as long as nMinBufLength
//	LPCSTR GetBuffer(int nMinBufLength);
//	// release buffer, setting length to nNewLength (or to first nul if -1)
//	void ReleaseBuffer(int nNewLength = -1);
//	// get pointer to modifiable buffer exactly as long as nNewLength
//	LPTSTR GetBufferSetLength(int nNewLength);
//	// release memory allocated to but unused by string
//	void FreeExtra();
//
//	// Use LockBuffer/UnlockBuffer to turn refcounting off
//
//	// turn refcounting back on
//	LPTSTR LockBuffer();
//	// turn refcounting off
//	void UnlockBuffer();

// Implementation
public:
	~CString();
//	int GetAllocLength() const;

protected:
	string m_str;
	bool isInstr(TCHAR c,LPCSTR str);
//	LPTSTR m_pchData;   // pointer to ref counted string data
//
//	// implementation helpers
//	CStringData* GetData() const;
//	void Init();
//	void AllocCopy(CString& dest, int nCopyLen, int nCopyIndex, int nExtraLen) const;
//	void AllocBuffer(int nLen);
//	void AssignCopy(int nSrcLen, LPCTSTR lpszSrcData);
//	void ConcatCopy(int nSrc1Len, LPCTSTR lpszSrc1Data, int nSrc2Len, LPCTSTR lpszSrc2Data);
//	void ConcatInPlace(int nSrcLen, LPCTSTR lpszSrcData);
//	void CopyBeforeWrite();
//	void AllocBeforeWrite(int nLen);
//	void Release();
//	static void PASCAL Release(CStringData* pData);
//	static int PASCAL SafeStrlen(LPCTSTR lpsz);
//	static void FASTCALL FreeData(CStringData* pData);
};
CString operator+(TCHAR ch, const CString& string1);
CString operator+(LPCSTR lpsz, const CString& string1);
#endif /* CSTRING_H_ */
