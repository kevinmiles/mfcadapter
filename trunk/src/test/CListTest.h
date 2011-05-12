/*
 * CListTest.h
 *
 *  Created on: 2011-3-29
 *      Author: zhujianfeng
 */
#include <gtest/gtest.h>
#ifndef CLISTTEST_H_
#define CLISTTEST_H_

class CListTest :public ::testing::Test{
protected:
	CListTest(){};
	virtual ~CListTest(){};
	virtual void SetUp() {
	  }

	virtual void TearDown() {
	  }
};

#endif /* CLISTTEST_H_ */
