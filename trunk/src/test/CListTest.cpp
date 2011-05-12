/*
 * CListTest.cpp
 *
 *  Created on: 2011-3-29
 *      Author: zhujianfeng
 */

#include "CListTest.h"
#include <iostream>
#include "../MFCAdapter.h"
using namespace std;
TEST_F(CListTest,CList){
	CList<int,int> clist;
	EXPECT_EQ(10,clist.GetCount());
	CList<CString,CString&> strlist(2);
	EXPECT_EQ(2,strlist.GetCount());
}
