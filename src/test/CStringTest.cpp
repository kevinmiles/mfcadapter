/*
 * CStringTest.cpp
 *
 *  Created on: 2011-3-8
 *      Author: zhujianfeng
 */

#include "CStringTest.h"
#include <iostream>
using namespace std;
TEST_F(CStringTest,CString){
	CString s("test");
	string s1("test");
	//cout<<s.GetCppStr()<<endl;
	EXPECT_STREQ(s.GetCppStr().c_str(),s1.c_str());
}

TEST_F(CStringTest,GetLenth){
	CString s("asdf");
	EXPECT_EQ(4,s.GetLength());
}

TEST_F(CStringTest,Empty){
	CString s("asdf");
	EXPECT_FALSE(s.IsEmpty());
	s.Empty();
	EXPECT_TRUE(s.IsEmpty());
}

TEST_F(CStringTest,GetSetAt){
	CString s("fdse");
	EXPECT_EQ(s.GetAt(0),'f');
	EXPECT_EQ(s.GetAt(3),'e');
	EXPECT_EQ(s[0],'f');
	EXPECT_EQ(s[2],'s');

	s.SetAt(3,'f');
	EXPECT_EQ(s.GetAt(3),'f');
	EXPECT_STREQ("fdsf",s.GetCppStr().c_str());
}

//TEST_F(CStringTest,operatorLPCSTR){
//	CString s("fdse");
//	EXPECT_STREQ("fdse",(LPCSTR)s);
//}

TEST_F(CStringTest,operatorAssign){
	CString s("fdse");
	CString s1=s;
	EXPECT_STREQ(s.GetCppStr().c_str(),s1.GetCppStr().c_str());
	s.SetAt(3,'f');
	EXPECT_STRNE(s.GetCppStr().c_str(),s1.GetCppStr().c_str());
	CString s2='a';
	EXPECT_STREQ("a",s2.GetCppStr().c_str());
	string temp="lov";
	const char *st=temp.c_str();
	s1=st;
	EXPECT_STREQ(st,s1.GetCppStr().c_str());
	EXPECT_EQ(3,s1.GetLength());
	s1.SetAt(0,'f');
	EXPECT_STRNE(st,s1.GetCppStr().c_str());
	s1="fdsa";
	EXPECT_STREQ("fdsa",s1.GetCppStr().c_str());
}

TEST_F(CStringTest,operatorJoin){
	CString s1("abc");
	CString s2("def");
	s1+=s2;
	EXPECT_STREQ("abcdef",s1.GetCppStr().c_str());
	s1+='g';
	EXPECT_STREQ("abcdefg",s1.GetCppStr().c_str());
	string temp="hij";
	const char *st=temp.c_str();
	s1+=st;
	EXPECT_STREQ("abcdefghij",s1.GetCppStr().c_str());
}

TEST_F(CStringTest,operatorTwoStrJoin){
	CString s1="asdf";
	CString s2="hjkl";
	CString s3=s1+s2;
	EXPECT_STREQ("asdfhjkl",s3.GetCppStr().c_str());
	CString s4=s1+'g';
	EXPECT_STREQ("asdfg",s4.GetCppStr().c_str());
	s4='g'+s1;
	EXPECT_STREQ("gasdf",s4.GetCppStr().c_str());
	s4=s1+"qwe";
	EXPECT_STREQ("asdfqwe",s4.GetCppStr().c_str());
	s4="uio"+s1;
	EXPECT_STREQ("uioasdf",s4.GetCppStr().c_str());
}

TEST_F(CStringTest,Compare){
	CString s1="asdf";
	CString s2="asde";
	EXPECT_EQ(0,s1.Compare("asdf"));
	EXPECT_EQ(-1,s1.Compare("asdh"));
	EXPECT_EQ(1,s1.Compare("asde"));
	EXPECT_EQ(1,s1.Compare(s2));
	CString s3="asdF";
	CString s4="asdf";
	EXPECT_EQ(-1,s3.Compare("asdf"));
	EXPECT_EQ(0,s3.CompareNoCase("asdf"));
	EXPECT_EQ(0,s3.CompareNoCase(s4));
}

TEST_F(CStringTest,SubStr){
	CString s("I have a dream");
	CString s2=s.Mid(9,5);
	EXPECT_STREQ("dream",s2.GetCppStr().c_str());
	s2=s.Mid(9);
	EXPECT_STREQ("dream",s2.GetCppStr().c_str());
	s2=s.Left(6);
	EXPECT_STREQ("I have",s2.GetCppStr().c_str());
	s2=s.Right(5);
	EXPECT_STREQ("dream",s2.GetCppStr().c_str());
}

TEST_F(CStringTest,MakeUpper){
	CString s("aAbBcCzZ18");
	s.MakeUpper();
	EXPECT_STREQ("AABBCCZZ18",s.GetCppStr().c_str());
}

TEST_F(CStringTest,MakeLower){
	CString s("aAbBcCzZ12");
	s.MakeLower();
	EXPECT_STREQ("aabbcczz12",s.GetCppStr().c_str());
}

TEST_F(CStringTest,MakeReverse){
	CString s("abcd12");
	s.MakeReverse();
	EXPECT_STREQ("21dcba",s.GetCppStr().c_str());
}

TEST_F(CStringTest,TrimRight){
	CString s("ss 	\n\r\t");
	s.TrimRight();
	EXPECT_STREQ("ss",s.GetCppStr().c_str());
	s="\n\r   ";
	s.TrimRight();
	EXPECT_STREQ("",s.GetCppStr().c_str());

	s="ss****";
	s.TrimRight('*');
	EXPECT_STREQ("ss",s.GetCppStr().c_str());

	s="ss***&&%";
	s.TrimRight("*&%");
	EXPECT_STREQ("ss",s.GetCppStr().c_str());
}

TEST_F(CStringTest,TrimLeft){
	CString s("\t\r 	 \nss");
	s.TrimLeft();
	EXPECT_STREQ("ss",s.GetCppStr().c_str());

	s="***ss";
	s.TrimLeft('*');
	EXPECT_STREQ("ss",s.GetCppStr().c_str());

	s="** %$ss";
	s.TrimLeft("* %$");
	EXPECT_STREQ("ss",s.GetCppStr().c_str());
}

TEST_F(CStringTest,Replace){
	CString s("ss**SS");
	int n=s.Replace('*','%');
	EXPECT_STREQ("ss%%SS",s.GetCppStr().c_str());
	EXPECT_EQ(2,n);

	s="I test replace!test!";
	n=s.Replace("test","bing");
	EXPECT_STREQ("I bing replace!bing!",s.GetCppStr().c_str());
	EXPECT_EQ(2,n);

	s="aabbbbcc";
	n=s.Replace("bb","cb");
	EXPECT_STREQ("aacbcbcc",s.GetCppStr().c_str());
	EXPECT_EQ(2,n);

	CString s1("bb");
	CString s2("cb");
	s.Replace(s1,s2);
	EXPECT_STREQ("aacbcbcc",s.GetCppStr().c_str());
	EXPECT_EQ(2,n);
}

TEST_F(CStringTest,Remove){
	CString s("This is a test");
	int n=s.Remove('t');
	EXPECT_STREQ("This is a es",s.GetCppStr().c_str());
	EXPECT_EQ(2,n);
}

TEST_F(CStringTest,Insert){
	CString s("abc");
	int n=s.Insert(0,'c');
	EXPECT_STREQ("cabc",s.GetCppStr().c_str());
	EXPECT_EQ(4,n);

	s="abc";
	n=s.Insert(1,'c');
	EXPECT_STREQ("acbc",s.GetCppStr().c_str());
	EXPECT_EQ(4,n);

	s="abc";
	n=s.Insert(6,'d');
	EXPECT_STREQ("abcd",s.GetCppStr().c_str());
	EXPECT_EQ(4,n);

	s="abcdef";
	n=s.Insert(2,"heihei");
	EXPECT_STREQ("abheiheicdef",s.GetCppStr().c_str());
	EXPECT_EQ(12,n);

	s="abcdef";
	CString s1="heihei";
	n=s.Insert(2,s1);
	EXPECT_STREQ("abheiheicdef",s.GetCppStr().c_str());
	EXPECT_EQ(12,n);

	s="abcdef";
	s1="heihei";
	n=s.Insert(50,s1);
	EXPECT_STREQ("abcdefheihei",s.GetCppStr().c_str());
	EXPECT_EQ(12,n);
}

TEST_F(CStringTest,Delete){
	CString s="abcdef";
	int n=s.Delete(1,2);
	EXPECT_STREQ("adef",s.GetCppStr().c_str());
	EXPECT_EQ(6,n);
}

TEST_F(CStringTest,Find){
	CString s="abcdefabcd";
	EXPECT_EQ(1,s.Find('b'));
	EXPECT_EQ(-1,s.Find('x'));

	EXPECT_EQ(7,s.ReverseFind('b'));

	EXPECT_EQ(7,s.Find('b',2));

	CString s1="efa";
	EXPECT_EQ(4,s.Find("efa"));
	EXPECT_EQ(4,s.Find(s1));
	s1="bcd";
	EXPECT_EQ(7,s.Find("bcd",2));
	EXPECT_EQ(7,s.Find(s1,2));
}

TEST_F(CStringTest,FindOneOf){
	CString s="abcdef";
	EXPECT_EQ(3,s.FindOneOf("xyde"));
	CString s1="xyde";
	EXPECT_EQ(3,s.FindOneOf(s1));
}

TEST_F(CStringTest,Format){
	CString s;
	s.Format("%d",10);
	EXPECT_STREQ("10",s.GetCppStr().c_str());
	s.Format("%s%d","abc",12);
	EXPECT_STREQ("abc12",s.GetCppStr().c_str());
	EXPECT_EQ(5,s.GetCppStr().length());
}
