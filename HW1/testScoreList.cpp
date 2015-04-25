//
//  testScoreList.cpp
//  HW1
//
//  Created by WangSiwen on 15-4-7.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.
//

//
#include "ScoreList.h"
#include <iostream>
#include <cassert>
#include <stdio.h>
using namespace std;
int main()
{
    ScoreList s;
    s.add(0);
    s.add(33);
    s.add(0);
    s.add(7);
    s.add(1);
    s.add(9);
    s.add(24);
    s.remove(33);
    //s.print();

    assert(s.size() == 6);
    //s.print();
    assert(s.minimum()==0);
    assert(s.maximum()==24);

}