/*
 * CTimeTest.h
 *
 *  Created on: 2011-3-7
 *      Author: zhujianfeng
 */

#ifndef CTIMETEST_H_
#define CTIMETEST_H_
#include "../CTime.h"
#include <gtest/gtest.h>
class CTimeTest: public ::testing::Test {
protected:
	CTimeTest(){};
	virtual ~CTimeTest(){};
	virtual void SetUp() {
	  }

	virtual void TearDown() {
	  }
protected:
	//CTime *ctime;

};

#endif /* CTIMETEST_H_ */
