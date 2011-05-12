/*
 * CTimeSpanTest.h
 *
 *  Created on: 2011-3-8
 *      Author: zhujianfeng
 */

#ifndef CTIMESPANTEST_H_
#define CTIMESPANTEST_H_
#include "../CtimeSpan.h"
#include <gtest/gtest.h>
class CTimeSpanTest: public ::testing::Test {
protected:
	CTimeSpanTest(){};
	virtual ~CTimeSpanTest(){};
	virtual void SetUp() {
	  }

	virtual void TearDown() {
	  }
};

#endif /* CTIMESPANTEST_H_ */
