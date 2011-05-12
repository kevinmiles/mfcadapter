/*
 * CStringTest.h
 *
 *  Created on: 2011-3-8
 *      Author: zhujianfeng
 */
#include <gtest/gtest.h>
#include "../CString.h"
#ifndef CSTRINGTEST_H_
#define CSTRINGTEST_H_

class CStringTest: public ::testing::Test {
protected:
	CStringTest(){};
	virtual ~CStringTest(){};
	virtual void SetUp() {
	  }

	virtual void TearDown() {
	  }
};

#endif /* CSTRINGTEST_H_ */
