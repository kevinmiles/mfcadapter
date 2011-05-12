/*
 * CTimeSpan.h
 *
 *  Created on: 2011-3-8
 *      Author: zhujianfeng
 */
#include <time.h>
#include "Types.h"
#include "CString.h"
#ifndef CTIMESPAN_H_
#define CTIMESPAN_H_

class CTimeSpan {
public:

// Constructors
	CTimeSpan();
	CTimeSpan(time_t time);
	CTimeSpan(LONG lDays, int nHours, int nMins, int nSecs);
	CTimeSpan(const CTimeSpan& timeSpanSrc);
	const CTimeSpan& operator=(const CTimeSpan& timeSpanSrc);

// Attributes
	// extract parts
	LONG GetDays() const;   // total # of days
	LONG GetTotalHours() const;
	int GetHours() const;
	LONG GetTotalMinutes() const;
	int GetMinutes() const;
	LONG GetTotalSeconds() const;
	int GetSeconds() const;

// Operations
	// time math
	CTimeSpan operator-(CTimeSpan timeSpan) const;
	CTimeSpan operator+(CTimeSpan timeSpan) const;
	const CTimeSpan& operator+=(CTimeSpan timeSpan);
	const CTimeSpan& operator-=(CTimeSpan timeSpan);
	BOOL operator==(CTimeSpan timeSpan) const;
	BOOL operator!=(CTimeSpan timeSpan) const;
	BOOL operator<(CTimeSpan timeSpan) const;
	BOOL operator>(CTimeSpan timeSpan) const;
	BOOL operator<=(CTimeSpan timeSpan) const;
	BOOL operator>=(CTimeSpan timeSpan) const;
//
//#ifdef _UNICODE
//	// for compatibility with MFC 3.x
//	CString Format(LPCSTR pFormat) const;
//#endif
	CString Format(LPCSTR pFormat) const;
//	CString Format(UINT nID) const;

	// serialization
//#ifdef _DEBUG
//	friend CDumpContext& AFXAPI operator<<(CDumpContext& dc,CTimeSpan timeSpan);
//#endif
//	friend CArchive& AFXAPI operator<<(CArchive& ar, CTimeSpan timeSpan);
//	friend CArchive& AFXAPI operator>>(CArchive& ar, CTimeSpan& rtimeSpan);

private:
	time_t m_timeSpan;
	friend class CTime;
};

#endif /* CTIMESPAN_H_ */
