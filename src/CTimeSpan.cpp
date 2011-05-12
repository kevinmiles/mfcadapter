/*
 * CTimeSpan.cpp
 *
 *  Created on: 2011-3-8
 *      Author: zhujianfeng
 */

#include "CTimeSpan.h"

CTimeSpan::CTimeSpan() {
	m_timeSpan=0;
}

CTimeSpan::CTimeSpan(time_t time){
	m_timeSpan=time;
}

CTimeSpan::CTimeSpan(LONG lDays, int nHours, int nMins, int nSecs){
	m_timeSpan=86400*lDays+3600*nHours+60*nMins+nSecs;
}

CTimeSpan::CTimeSpan(const CTimeSpan& timeSpanSrc){
	m_timeSpan=timeSpanSrc.GetTotalSeconds();
}

const CTimeSpan& CTimeSpan::operator =(const CTimeSpan& timeSpanSrc){
	m_timeSpan=timeSpanSrc.GetTotalSeconds();
	return *this;
}

LONG CTimeSpan::GetDays()const{
	return m_timeSpan/86400;
}

LONG CTimeSpan::GetTotalHours()const{
	return m_timeSpan/3600;
}

int CTimeSpan::GetHours()const{
	return GetTotalHours()-GetDays()*24;
}

LONG CTimeSpan::GetTotalMinutes()const{
	return m_timeSpan/60;
}

int CTimeSpan::GetMinutes()const{
	return GetTotalMinutes()-GetTotalHours()*60;
}
LONG CTimeSpan::GetTotalSeconds()const{
	return m_timeSpan;
}

int CTimeSpan::GetSeconds()const{
	return GetTotalSeconds()-GetTotalMinutes()*60;
}

CTimeSpan CTimeSpan::operator-(CTimeSpan timeSpan) const{
	time_t t=m_timeSpan-timeSpan.GetTotalSeconds();
	CTimeSpan ctspan(t);
	return ctspan;
}

CTimeSpan CTimeSpan::operator+(CTimeSpan timeSpan) const{
	time_t t=m_timeSpan+timeSpan.GetTotalSeconds();
	CTimeSpan ctspan(t);
	return ctspan;
}

const CTimeSpan& CTimeSpan::operator+=(CTimeSpan timeSpan){
	m_timeSpan+=timeSpan.GetTotalSeconds();
	return *this;
}

const CTimeSpan& CTimeSpan::operator-=(CTimeSpan timeSpan){
	m_timeSpan-=timeSpan.GetTotalSeconds();
	return *this;
}

BOOL CTimeSpan::operator==(CTimeSpan timeSpan) const{
	if(m_timeSpan==timeSpan.GetTotalSeconds()){
		return true;
	}
	return false;
}

BOOL CTimeSpan::operator!=(CTimeSpan timeSpan) const{
	if(m_timeSpan!=timeSpan.GetTotalSeconds()){
		return true;
	}
	return false;
}

BOOL CTimeSpan::operator<(CTimeSpan timeSpan) const{
	if(m_timeSpan<timeSpan.GetTotalSeconds()){
		return true;
	}
	return false;
}

BOOL CTimeSpan::operator>(CTimeSpan timeSpan) const{
	if(m_timeSpan>timeSpan.GetTotalSeconds()){
		return true;
	}
	return false;
}

BOOL CTimeSpan::operator<=(CTimeSpan timeSpan) const{
	if(m_timeSpan<=timeSpan.GetTotalSeconds()){
		return true;
	}
	return false;
}

BOOL CTimeSpan::operator>=(CTimeSpan timeSpan) const{
	if(m_timeSpan>=timeSpan.GetTotalSeconds()){
		return true;
	}
	return false;
}

CString CTimeSpan::Format(LPCSTR pFormat) const{
	CString s(pFormat);
	CString sD;
	sD.Format("%d",this->GetDays());
	CString sH;
	sH.Format("%d",this->GetHours());
	if(this->GetHours()<10){
		sH="0"+sH;
	}
	CString sM;
	sM.Format("%d",this->GetMinutes());
	if(this->GetMinutes()<10){
		sM="0"+sM;
	}
	CString sS;
	sS.Format("%d",this->GetSeconds());
	if(this->GetSeconds()<10){
		sS="0"+sS;
	}
	int s_len=s.GetLength();
	for(int i=0;i<s_len-1;i++){
		if(s[i]=='%'){
			if(s[i+1]=='%'){
				s.Delete(i,1);

			}else if(s[i+1]=='D'){
				s.Delete(i,2);
				s.Insert(i,sD);
				i+=(sD.GetLength()-2);
			}else if(s[i+1]=='H'){
				s.Delete(i,2);
				s.Insert(i,sH);
				i+=(sH.GetLength()-2);
			}else if(s[i+1]=='M'){
				s.Delete(i,2);
				s.Insert(i,sM);
				i+=(sM.GetLength()-2);
			}else if(s[i+1]=='S'){
				s.Delete(i,2);
				s.Insert(i,sS);
				i+=(sS.GetLength()-2);
			}
		}
	}
	return s;
}
