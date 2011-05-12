/*
 * CTime.cpp
 *
 *  Created on: 2011-3-7
 *      Author: zhujianfeng
 */

#include "CTime.h"
CTime::CTime() {
	m_time=0;

}
CTime::CTime(time_t time){
	m_time=time;
}

CTime::CTime(int nYear, int nMonth, int nDay, int nHour, int nMin, int nSec,int nDST){
	tm time;//定义tm结构体
	time.tm_year=nYear-1900;
	time.tm_mon=nMonth-1;
	time.tm_mday=nDay;
	time.tm_hour=nHour;
	time.tm_min=nMin;
	time.tm_sec=nSec;
	time.tm_isdst=nDST;
	m_time=mktime(&time);
}

CTime::CTime(const CTime &timeSrc){//拷贝构造函数
	m_time=timeSrc.GetTime();
}

const CTime& CTime::operator =(const CTime &timeSrc){
	m_time=timeSrc.GetTime();
	return *this;
}

const CTime& CTime::operator =(time_t t){
	m_time=t;
	return *this;
}

CTime CTime::GetCurrentTime(){
	time_t t=time(NULL);
	CTime ctime(t);
	return ctime;
}

time_t CTime::GetTime() const{
	return m_time;
}

int CTime::GetYear() const{
	tm *time;
	time=localtime(&m_time);
	return time->tm_year+1900;
}

int CTime::GetMonth() const{
	tm *time;
	time=localtime(&m_time);
	return time->tm_mon+1;
}

int CTime::GetDay() const{
	tm *time;
	time=localtime(&m_time);
	return time->tm_mday;
}

int CTime::GetHour()const{
	tm *time;
	time=localtime(&m_time);
	return time->tm_hour;
}

int CTime::GetMinute()const{
	tm *time;
	time=localtime(&m_time);
	return time->tm_min;
}

int CTime::GetSecond()const{
	tm *time;
	time=localtime(&m_time);
	return time->tm_sec;
}

int CTime::GetDayOfWeek()const{
	tm *time;
	time=localtime(&m_time);
	return time->tm_wday;
}

CTimeSpan CTime::operator-(CTime time) const{
	time_t t=m_time-time.GetTime();
	CTimeSpan ctspan(t);
	return ctspan;
}

CTime CTime::operator-(CTimeSpan timeSpan) const{
	time_t t=m_time-timeSpan.GetTotalSeconds();
	CTime ctime(t);
	return ctime;
}

CTime CTime::operator+(CTimeSpan timeSpan) const{
	time_t t=m_time+timeSpan.GetTotalSeconds();
	CTime ctime(t);
	return ctime;
}

const CTime& CTime::operator+=(CTimeSpan timeSpan){
	m_time+=timeSpan.GetTotalSeconds();
	return *this;
}

const CTime& CTime::operator-=(CTimeSpan timeSpan){
	m_time-=timeSpan.GetTotalSeconds();
	return *this;
}

BOOL CTime::operator==(CTime time)const{
	if(m_time==time.GetTime()){
		return true;
	}
	return false;
}

BOOL CTime::operator!=(CTime time)const{
	if(m_time!=time.GetTime()){
		return true;
	}
	return false;
}

BOOL CTime::operator <(CTime time)const{
	if(m_time<time.GetTime()){
		return true;
	}
	return false;
}

BOOL CTime::operator <=(CTime time)const{
	if(m_time<=time.GetTime()){
		return true;
	}
	return false;
}

BOOL CTime::operator >(CTime time)const{
	if(m_time>time.GetTime()){
		return true;
	}
	return false;
}

BOOL CTime::operator >=(CTime time)const{
	if(m_time>=time.GetTime()){
		return true;
	}
	return false;
}

CString CTime::Format(LPCSTR pFormat) const{
	char buffer[256];
	tm *time;
	time=localtime(&m_time);
	strftime(buffer,256,pFormat,time);
	CString s(buffer);
	return s;
}

CString CTime::FormatGmt(LPCSTR pFormat) const{
	char buffer[256];
	tm *time;
	time=gmtime(&m_time);
	strftime(buffer,256,pFormat,time);
	CString s(buffer);
	return s;
}
