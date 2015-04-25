//
//  main.cpp
//  proj2
//
//  Created by WangSiwen on 15-4-14.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.
//

#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Sequence s,s2,res;
    assert(s.insert(0, 10));
    assert(s.insert(0, 30));
    assert(s.insert(0, 50));
    assert(s2.insert(0, 20));
    assert(s2.insert(0, 40));
    assert(s2.insert(0, 1));
    assert(s2.insert(0, 2));
    assert(s2.insert(0, 3));
    assert(s2.insert(0, 4));
    assert(s.size() == 3);
   // ItemType x = 999;
   // assert(s.get(0, x)  &&  x == 20);
    //assert(s.get(1, x)  &&  x == 10);
    assert(subsequence(s, s2)==-1);
    interleave(s, s2, res);
    ItemType val;
    res.get(6, val);
    assert(res.size()==9);
    assert(val==2);
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}
