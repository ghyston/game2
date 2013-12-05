//
//  Tests.cpp
//  Game2
//
//  Created by Stepanov Ilia on 08/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "Tests.h"

void test_vectors()
{
	Vec2f test_1(0.1f, 0.0f);
	Vec2f test_2(0.3f, 0.4f);
	Vec2f test_3(0.5f, 0.6f);
	test_3 += 2.0f * test_1;
	test_1.lenth(5.0f);

	//test_3 = test_1 + test_2;
	//test_1 = test_2 - test_3;
}

void test_shr_ptr()
{

	std::list<ShrPtr<Test>> tests;
	
	{
		ShrPtr<Test> ptr_1(new Test(1));
		ShrPtr<Test> ptr_2(new Test(2));
		ShrPtr<Test> ptr_3(new Test(3));
		ShrPtr<Test> ptr_4(new Test(4));

		tests.push_back(ptr_1);
		tests.push_back(ptr_2);
		ptr_3->mark_deleted();
		tests.push_back(ptr_3);
		tests.push_back(ptr_4);
	}
	
	
	ShrPtr<Test> ptr_3_back = tests.back();
	RemoveDeletedObjectsFromVector(tests);
	int test = 55;
}