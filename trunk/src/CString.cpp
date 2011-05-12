/*
 * CString.cpp
 *
 *  Created on: 2011-3-8
 *      Author: zhujianfeng
 */

#include "CString.h"
#include <algorithm>
#include <cctype>
#include <stdarg.h>
using namespace std;
CString::CString() {
	m_str="";

}

CString::CString(const CString& stringSrc){
	m_str=stringSrc.m_str;
}

CString::CString(TCHAR ch,int nRepeat){
	string s(nRepeat,ch);
	m_str=s;
}

CString::CString(LPCSTR lpsz){
	m_str=lpsz;
}


string CString::GetCppStr(){
	return m_str;
}

BOOL CString::IsEmpty()const{
	if(m_str.length()==0){
		return true;
	}
	return false;
}

void CString::Empty(){
	m_str="";
}

TCHAR CString::GetAt(int nIndex)const{
	return m_str.at(nIndex);
}

TCHAR CString::operator[](int nIndex) const{
	return m_str[nIndex];
}

void CString::SetAt(int nIndex, TCHAR ch){
	m_str[nIndex]=ch;
}

//LPCSTR CString::operator LPCSTR()const{
//	return m_str.c_str();
//}

const CString& CString::operator=(const CString& stringSrc){
	string s="";
	for(int i=0;i<stringSrc.GetLength();i++){
		string temp(1,stringSrc[i]);
		s+=temp;
	}
	m_str=s;
	return *this;
}

const CString& CString::operator=(TCHAR ch){
	string s(1,ch);
	m_str=s;
	return *this;
}

const CString& CString::operator=(LPCSTR lpsz){
	string s(lpsz);
	m_str=s;
	return *this;
}

const CString& CString::operator+=(const CString& stringSrc){
	for(int i=0;i<stringSrc.GetLength();i++){
		m_str+=stringSrc[i];
	}
	return *this;
}

const CString& CString::operator+=(TCHAR ch){
	m_str+=ch;
	return *this;
}

const CString& CString::operator+=(LPCSTR lpsz){
	m_str+=lpsz;
	return *this;
}
int CString::GetLength()const{
	return m_str.length();
}

CString CString::operator+(const CString& string1){
	string s=m_str;
	for(int i=0;i<string1.GetLength();i++){
		s+=string1[i];
	}
	CString result(s.c_str());
	return result;
}

CString CString::operator+(TCHAR ch){
	string s=m_str+ch;
	CString str(s.c_str());
	return str;
}
CString CString::operator+(LPCSTR lpsz){
	string s=m_str+lpsz;
	CString str(s.c_str());
	return str;
}

int CString::Compare(LPCSTR lpsz) const{
	return m_str.compare(lpsz);
}

int CString::Compare(CString &str) const{
	string s(str.GetCppStr().c_str());
	return m_str.compare(s);
}

int CString::CompareNoCase(LPCSTR lpsz) const{
	string s(lpsz);
	string m_s=m_str;
	transform(s.begin(),s.end(),s.begin(),towupper);
	transform(m_s.begin(),m_s.end(),m_s.begin(),towupper);
	return m_s.compare(s);
}

int CString::CompareNoCase(CString &str) const{
	string s(str.GetCppStr().c_str());
	string m_s=m_str;
	transform(s.begin(),s.end(),s.begin(),towupper);
	transform(m_s.begin(),m_s.end(),m_s.begin(),towupper);
	return m_s.compare(s);
}

CString CString::Mid(int nFirst, int nCount) const{
	string s=m_str.substr(nFirst,nCount);
	CString str(s.c_str());
	return str;
}

CString CString::Mid(int nFirst) const{
	int nCount=m_str.length()-nFirst;
	string s=m_str.substr(nFirst,nCount);
	CString str(s.c_str());
	return str;
}

CString CString::Left(int nCount) const{
	string s=m_str.substr(0,nCount);
	CString str(s.c_str());
	return str;
}

CString CString::Right(int nCount) const{
	int nFirst=m_str.length()-nCount;
	string s=m_str.substr(nFirst,nCount);
	CString str(s.c_str());
	return str;
}

void CString::MakeUpper(){
	int m_len=m_str.length();
	for(int i=0;i<m_len;i++){
		if(m_str[i]>='a'&&m_str[i]<='z'){
			m_str[i]=m_str[i]-('a'-'A');
		}
	}
}

void CString::MakeLower(){
	int m_len=m_str.length();
	for(int i=0;i<m_len;i++){
		if(m_str[i]>='A'&&m_str[i]<='Z'){
			m_str[i]=m_str[i]+('a'-'A');
		}
	}
}

void CString::MakeReverse(){
	int m_len=m_str.length();
	for(int i=0,j=m_len-1;i<j;i++,j--){
		char temp;
		temp=m_str[i];
		m_str[i]=m_str[j];
		m_str[j]=temp;
	}
}

void CString::TrimRight(){
	int m_len=m_str.length();
	for(int i=m_len-1;(m_str[i]=='\n'||m_str[i]=='\r'||m_str[i]=='\t'||m_str[i]==' ')&&i>=0;i--){
		m_str=m_str.substr(0,m_str.length()-1);
	}
}

void CString::TrimLeft(){
	int m_len=m_str.length();
	for(int i=0;(m_str[i]=='\n'||m_str[i]=='\r'||m_str[i]=='\t'||m_str[i]==' ')&&i<m_len;i++){
		m_str=m_str.substr(1,m_str.length()-1);
		i--;
	}
}

void CString::TrimRight(TCHAR chTarget){
	int m_len=m_str.length();
	for(int i=m_len-1;m_str[i]==chTarget&&i>=0;i--){
		m_str=m_str.substr(0,m_str.length()-1);
	}
}
bool CString::isInstr(TCHAR c,LPCSTR str){
	bool result=false;
	string s(str);
	int s_len=s.length();
	for(int i=0;i<s_len;i++){
		if(s[i]==c){
			return true;
		}
	}
	return result;
}
void CString::TrimRight(LPCSTR lpszTargets){
	int m_len=m_str.length();
	for(int i=m_len-1;isInstr(m_str[i],lpszTargets)&&i>=0;i--){
		m_str=m_str.substr(0,m_str.length()-1);
	}
}

void CString::TrimLeft(TCHAR chTarget){
	int m_len=m_str.length();
	for(int i=0;m_str[i]==chTarget&&i<m_len;i++){
		m_str=m_str.substr(1,m_str.length()-1);
		i--;
	}
}

void CString::TrimLeft(LPCSTR lpszTargets){
	int m_len=m_str.length();
	for(int i=0;isInstr(m_str[i],lpszTargets)&&i<m_len;i++){
		m_str=m_str.substr(1,m_str.length()-1);
		i--;
	}
}

int CString::Replace(TCHAR chOld, TCHAR chNew){
	int m_len=m_str.length();
	int result=0;
	for(int i=0;i<m_len;i++){
		if(m_str[i]==chOld){
			m_str[i]=chNew;
			result++;
		}
	}
	return result;
}

int CString::Replace(LPCSTR lpszOld, LPCSTR lpszNew){
	int result=0;
	string strOld(lpszOld);
	int lenOld=strOld.length();
	if(lenOld==0){
		return result;
	}
	size_t found=m_str.find(lpszOld);
	while(found!=string::npos){
		m_str.replace(found,lenOld,lpszNew);
		result++;
		found=m_str.find(lpszOld,found+lenOld);
	}
	return result;
}

int CString::Replace(CString lpszOld, CString lpszNew){
	return Replace(lpszOld.GetCppStr().c_str(),lpszNew.GetCppStr().c_str());
}

int CString::Remove(TCHAR chRemove){
	int result=0;
	size_t found=m_str.find(chRemove);
	while(found!=string::npos){
		m_str.erase(found,1);
		result++;
		found=m_str.find(chRemove,found+1);
	}
	return result;
}

int CString::Insert(int nIndex, TCHAR ch){
	if((size_t)nIndex>m_str.length()){
		nIndex=m_str.length();
	}
	m_str.insert(nIndex,1,ch);
	return m_str.length();
}

int CString::Insert(int nIndex, LPCSTR pstr){
	if((size_t)nIndex>m_str.length()){
		nIndex=m_str.length();
	}
	m_str.insert(nIndex,pstr);
	return m_str.length();
}

int CString::Insert(int nIndex, CString pstr){
	return Insert(nIndex,pstr.GetCppStr().c_str());
}

int CString::Delete(int nIndex, int nCount){
	int result=m_str.length();
	if((size_t)nIndex>m_str.length()){
		return result;
	}
	m_str.erase(nIndex,nCount);
	return result;
}

int CString::Find(TCHAR ch) const{
	return m_str.find(ch);
}

int CString::ReverseFind(TCHAR ch) const{
	return m_str.find_last_of(ch);
}

int CString::Find(TCHAR ch, int nStart) const{
	return m_str.find(ch,nStart);
}

int CString::Find(LPCSTR lpszSub) const{
	return m_str.find(lpszSub);
}

int CString::Find(CString lpszSub) const{
	return Find(lpszSub.GetCppStr().c_str());
}

int CString::Find(LPCSTR lpszSub, int nStart) const{
	return m_str.find(lpszSub,nStart);
}

int CString::Find(CString lpszSub, int nStart) const{
	return Find(lpszSub.GetCppStr().c_str(),nStart);
}

int CString::FindOneOf(LPCSTR lpszCharSet) const{
	return m_str.find_first_of(lpszCharSet);
}
int CString::FindOneOf(CString lpszCharSet) const{
	return FindOneOf(lpszCharSet.GetCppStr().c_str());
}

void CString::Format(LPCSTR lpszFormat, ...){
	char buffer[2048];
	/*******************************************
	 *
	 * 这里限定了最终字符串长度最大不能超过2048字节
	 * 暂时还没想到使用变长字符串的方法
	 *
	 ******************************************/
	va_list arg_ptr;
	va_start(arg_ptr,lpszFormat);
	vsprintf(buffer,lpszFormat,arg_ptr);
	va_end(arg_ptr);
	string s(buffer);
	m_str=s;
}



CString::~CString() {
	// TODO Auto-generated destructor stub
}
CString operator+(TCHAR ch, const CString& string1){
	string s="";
	s+=ch;
	for(int i=0;i<string1.GetLength();i++){
		s+=string1[i];
	}
	CString str(s.c_str());
	return str;
}

CString operator+(LPCSTR lpsz, const CString& string1){
	string s(lpsz);
	for(int i=0;i<string1.GetLength();i++){
		s+=string1[i];
	}
	CString str(s.c_str());
	return str;
}
