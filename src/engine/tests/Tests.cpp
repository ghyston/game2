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
	test_1.length(5.0f);

	//test_3 = test_1 + test_2;
	//test_1 = test_2 - test_3;
}

/*ShrPtr<Test> test_ptr_funk(ShrPtr<Test> teest)
{
	ShrPtr<Test> temp = teest;
	return temp;
}*/

/*void test_shr_ptr()
{

	std::list<ShrPtr<Test> > tests;
	
	{
		ShrPtr<Test> ptr_1(new Test(1));
		ShrPtr<Test> ptr_2(new Test(2));
		ShrPtr<Test> ptr_3(new Test(3));
		ShrPtr<Test> ptr_4(new Test(4));
		ShrPtr<Test> ptr_5(new Test(5));
		
		ShrPtr<Test> ptr_6 = test_ptr_funk(ptr_4);

		tests.push_back(ptr_1);
		tests.push_back(ptr_2);
		ptr_3->mark_deleted();
		tests.push_back(ptr_3);
	//	tests.push_back(ptr_4);
		tests.push_back(ptr_5);
	}
	
	
	ShrPtr<Test> ptr_5_back = tests.back();
	
	RemoveDeletedObjectsFromContainer(tests);
	//int test = 55;
}
*/
void test_math()
{
	Vec2f a1, a2, b1, b2;
	bool t = false;
	
	// Intersected
	a1 = Vec2f(-2.0f, -1.5f);
	a2 = Vec2f( 1.5f,  1.0f);
	b1 = Vec2f( 0.0f, -1.5f);
	b2 = Vec2f(-1.5f,  1.0f);
	t = SegmentsIntersected(a1, a2, b1, b2);
	
	// Not intersected
	a1 = Vec2f(-2.0f, -1.0f);
	a2 = Vec2f(-0.5f,  1.0f);
	b1 = Vec2f(-1.5f,  2.0f);
	b2 = Vec2f( 1.0f,  1.5f);
	t = SegmentsIntersected(a1, a2, b1, b2);
	
	// Perpendicular, intersected
	a1 = Vec2f(-0.5f, -1.5f);
	a2 = Vec2f(-0.5f,  1.0f);
	b1 = Vec2f(-1.0f, -0.5f);
	b2 = Vec2f( 1.5f, -0.5f);
	t = SegmentsIntersected(a1, a2, b1, b2);
	
	// on same line
	a1 = Vec2f(-1.0f, -1.5f);
	a2 = Vec2f(-0.5f, -0.5f);
	b1 = Vec2f( 0.0f,  0.5f);
	b2 = Vec2f( 0.5f,  1.5f);
	t = SegmentsIntersected(a1, a2, b1, b2);
	
	// Intersected on one point
	a1 = Vec2f(-1.0f, -0.5f);
	a2 = Vec2f( 0.5f, -0.5f);
	b1 = Vec2f( 0.0f, -1.5f);
	b2 = Vec2f( 1.0f,  0.5f);
	t = SegmentsIntersected(a1, a2, b1, b2);
	
	//int test = 55;

}











