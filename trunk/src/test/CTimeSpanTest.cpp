/*
 * CTimeSpanTest.cpp
 *
 *  Created on: 2011-3-8
 *      Author: zhujianfeng
 */

#include "CTimeSpanTest.h"

TEST_F(CTimeSpanTest,CTimeSpan){
	time_t t=100;
	CTimeSpan ctspan(t);
	EXPECT_EQ(ctspan.GetTotalSeconds(),t);
	CTimeSpan ctspan2(1,0,0,0);
	EXPECT_EQ(ctspan2.GetTotalSeconds(),86400);
	CTimeSpan ctspan3(ctspan);
	EXPECT_EQ(ctspan.GetTotalSeconds(),ctspan3.GetTotalSeconds());
	CTimeSpan ctspan4=ctspan2;
	EXPECT_EQ(ctspan4.GetTotalSeconds(),86400);
}

TEST_F(CTimeSpanTest,GetXXs){
	LONG days=3;
	int hour=2;
	int min=0;
	int sec=59;
	CTimeSpan ctspan(days,hour,min,sec);
	EXPECT_EQ(ctspan.GetDays(),days);
	EXPECT_EQ(ctspan.GetTotalHours(),days*24+hour);
	EXPECT_EQ(ctspan.GetHours(),hour);
	EXPECT_EQ(ctspan.GetTotalMinutes(),days*24*60+hour*60+min);
	EXPECT_EQ(ctspan.GetMinutes(),min);
	EXPECT_EQ(ctspan.GetSeconds(),sec);
}

TEST_F(CTimeSpanTest,operatorMath){
	CTimeSpan ctime1(1,0,0,0);
	CTimeSpan ctime2(0,23,0,0);
	CTimeSpan ctime3=ctime1-ctime2;
	CTimeSpan ctime4=ctime1+ctime2;
	EXPECT_EQ(ctime3.GetTotalHours(),1);
	EXPECT_EQ(ctime4.GetTotalHours(),47);
	ctime3+=ctime2;
	EXPECT_EQ(ctime3.GetTotalSeconds(),ctime1.GetTotalSeconds());
	ctime4-=ctime2;
	EXPECT_EQ(ctime4.GetTotalSeconds(),ctime1.GetTotalSeconds());
}

TEST_F(CTimeSpanTest,operatorBiJiao){
	CTimeSpan ctime1(2,1,4,8);
	CTimeSpan ctime2(ctime1);
	CTimeSpan ctime3=ctime1+ctime2;
	EXPECT_TRUE(ctime1==ctime2);
	EXPECT_TRUE(ctime1!=ctime3);
	EXPECT_TRUE(ctime3>ctime1);
	EXPECT_TRUE(ctime3>=ctime1);
	EXPECT_TRUE(ctime1<ctime3);
	EXPECT_TRUE(ctime1<=ctime3);
}

TEST_F(CTimeSpanTest,Format){
	CTimeSpan ts( 3, 1, 5, 12 ); // 3 days, 1 hour, 5 min, and 12 sec
	CString s = ts.Format( "Total days: %D, hours: %H, mins: %M, secs: %S" );
	EXPECT_STREQ("Total days: 3, hours: 01, mins: 05, secs: 12",s.GetCppStr().c_str());
	s=ts.Format("%%%D %%%H %%%M %%%S%");
	EXPECT_STREQ("%3 %01 %05 %12%",s.GetCppStr().c_str());
}
