/*
 * CTimeTest.cpp
 *
 *  Created on: 2011-3-7
 *      Author: zhujianfeng
 */
#include <iostream>
#include "CTimeTest.h"
using namespace std;
TEST_F(CTimeTest,GetTime){//测试GetTime函数
	time_t t=100;
	CTime *ctime=new CTime(t);
	EXPECT_EQ(t,ctime->GetTime());
	delete ctime;

	time_t t2=time(NULL);
	CTime ctime2(t2);
	CTime ctime3(ctime2);
	EXPECT_EQ(ctime3.GetTime(),t2);
}
TEST_F(CTimeTest,operatorEQ){
	time_t t=time(NULL);
	CTime ctime(t);
	CTime ctime2=ctime;
	EXPECT_EQ(ctime2.GetTime(),t);
	CTime ctime3=t;
	EXPECT_EQ(ctime3.GetTime(),t);
}

TEST_F(CTimeTest,operatorBiJiao){
	CTime ctime=CTime::GetCurrentTime();
	CTime ctime2(ctime);
	time_t t=time(NULL)+1;
	CTime ctime3(t);
	EXPECT_TRUE(ctime==ctime2);
	EXPECT_FALSE(ctime==ctime3);
	EXPECT_TRUE(ctime!=ctime3);
	EXPECT_FALSE(ctime!=ctime2);
	EXPECT_TRUE(ctime<ctime3);
	EXPECT_FALSE(ctime<ctime2);
	EXPECT_FALSE(ctime3<ctime);
	EXPECT_TRUE(ctime<=ctime3);
	EXPECT_TRUE(ctime<=ctime2);
	EXPECT_FALSE(ctime3<=ctime);
	EXPECT_TRUE(ctime3>ctime);
	EXPECT_FALSE(ctime2>ctime);
	EXPECT_FALSE(ctime>ctime3);
	EXPECT_TRUE(ctime3>=ctime);
	EXPECT_TRUE(ctime2>=ctime);
	EXPECT_FALSE(ctime>=ctime3);

}

TEST_F(CTimeTest,GetCurrentTime){
	CTime ctime;
	ctime=CTime::GetCurrentTime();
	time_t t=time(NULL);
	EXPECT_EQ(ctime.GetTime(),t);
}

TEST_F(CTimeTest,YMDHMS){//测试存入时间并取出时间是否正确
	int year=2005;
	int month=2;
	int day=28;
	int hour=23;
	int min=38;
	int sec=12;
	int dst=-1;
	CTime *ctime=new CTime(year,month,day,hour,min,sec,dst);
	EXPECT_EQ(ctime->GetYear(),year);
	EXPECT_EQ(ctime->GetMonth(),month);
	EXPECT_EQ(ctime->GetDay(),day);
	EXPECT_EQ(ctime->GetHour(),hour);
	EXPECT_EQ(ctime->GetMinute(),min);
	EXPECT_EQ(ctime->GetSecond(),sec);
	delete ctime;

	dst=0;
	ctime=new CTime(year,month,day,hour,min,sec,dst);
	EXPECT_EQ(ctime->GetYear(),year);
	EXPECT_EQ(ctime->GetMonth(),month);
	EXPECT_EQ(ctime->GetDay(),day);
	EXPECT_EQ(ctime->GetHour(),hour);
	EXPECT_EQ(ctime->GetMinute(),min);
	EXPECT_EQ(ctime->GetSecond(),sec);
	delete ctime;

//	time_t t=time(NULL);//测试当前系统时间
//	ctime=new CTime(t);
//	EXPECT_EQ(ctime->GetYear(),2011);
//	EXPECT_EQ(ctime->GetMonth(),3);
//	EXPECT_EQ(ctime->GetDay(),7);
//	EXPECT_EQ(ctime->GetHour(),20);
//	EXPECT_EQ(ctime->GetMinute(),33);
//	EXPECT_EQ(ctime->GetSecond(),0);
//	EXPECT_EQ(ctime->GetDayOfWeek(),0);
//	tm *stime;
//	stime=localtime(&t);
//	cout<<asctime(stime)<<endl;
//	delete ctime;

}

TEST_F(CTimeTest,operatorMath){
	int year=2005;
	int month=2;
	int day=28;
	int hour=23;
	int min=38;
	int sec=12;
	int dst=-1;
	CTime ctime1(year,month,day,hour,min,sec,dst);
	CTime ctime2(year,month,day+21,hour,min,sec,dst);
	CTimeSpan ctspan=ctime2-ctime1;
	EXPECT_EQ(ctspan.GetDays(),21);
	CTimeSpan ctspan2(0,2,0,0);
	CTime ctime3=ctime1+ctspan2;
	EXPECT_EQ(ctime3.GetMonth(),3);
	EXPECT_EQ(ctime3.GetDay(),1);
	CTimeSpan ctspan3(100,0,0,0);
	CTime ctime4=ctime1-ctspan3;
	EXPECT_EQ(ctime4.GetYear(),2004);
	ctime3-=ctspan2;
	EXPECT_EQ(ctime3.GetMonth(),2);
	ctime4+=ctspan3;
	EXPECT_EQ(ctime4.GetYear(),2005);

}

TEST_F(CTimeTest,Format){
	CTime t( 1999, 3, 19, 22, 15, 0 );
	CString s = t.Format( "%A, %B %d, %Y" );
	EXPECT_STREQ("Friday, March 19, 1999",s.GetCppStr().c_str());
	s=t.FormatGmt("%A, %B %d, %Y" );
	EXPECT_STREQ("Friday, March 19, 1999",s.GetCppStr().c_str());
}
