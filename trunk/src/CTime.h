/*
 * CTime.h
 *
 *  Created on: 2011-3-7
 *      Author: zhujianfeng
 */
#include <time.h>
#include "Types.h"
#include "CTimeSpan.h"
#include "CString.h"
#ifndef CTIME_H_
#define CTIME_H_
class CTime {
public:

// Constructors
	static CTime GetCurrentTime();

	CTime();
	CTime(time_t time);
	CTime(int nYear, int nMonth, int nDay, int nHour, int nMin, int nSec,
		int nDST = -1);
//	CTime(WORD wDosDate, WORD wDosTime, int nDST = -1);
	CTime(const CTime& timeSrc);
//
//	CTime(const SYSTEMTIME& sysTime, int nDST = -1);
//	CTime(const FILETIME& fileTime, int nDST = -1);
	const CTime& operator=(const CTime& timeSrc);
	const CTime& operator=(time_t t);

// Attributes
//	struct tm* GetGmtTm(struct tm* ptm = NULL) const;
//	struct tm* GetLocalTm(struct tm* ptm = NULL) const;
//	BOOL GetAsSystemTime(SYSTEMTIME& timeDest) const;
//
	time_t GetTime() const;
	int GetYear() const;
	int GetMonth() const;       // month of year (1 = Jan)
	int GetDay() const;         // day of month
	int GetHour() const;
	int GetMinute() const;
	int GetSecond() const;
	int GetDayOfWeek() const;   // 1=Sun, 2=Mon, ..., 7=Sat

// Operations
	// time math
	CTimeSpan operator-(CTime time) const;
	CTime operator-(CTimeSpan timeSpan) const;
	CTime operator+(CTimeSpan timeSpan) const;
	const CTime& operator+=(CTimeSpan timeSpan);
	const CTime& operator-=(CTimeSpan timeSpan);
	BOOL operator==(CTime time) const;
	BOOL operator!=(CTime time) const;
	BOOL operator<(CTime time) const;
	BOOL operator>(CTime time) const;
	BOOL operator<=(CTime time) const;
	BOOL operator>=(CTime time) const;

	// formatting using "C" strftime
	CString Format(LPCSTR pFormat) const;
	CString FormatGmt(LPCSTR pFormat) const;
//	CString Format(UINT nFormatID) const;
//	CString FormatGmt(UINT nFormatID) const;

//#ifdef _UNICODE
//	// for compatibility with MFC 3.x
//	CString Format(LPCSTR pFormat) const;
//	CString FormatGmt(LPCSTR pFormat) const;
//#endif

	// serialization
//#ifdef _DEBUG
//	friend CDumpContext& AFXAPI operator<<(CDumpContext& dc, CTime time);
//#endif
	//friend CArchive& AFXAPI operator<<(CArchive& ar, CTime time);
	//friend CArchive& AFXAPI operator>>(CArchive& ar, CTime& rtime);

private:
	time_t m_time;
};

#endif /* CTIME_H_ */
