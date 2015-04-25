//
//  testnewSequence.cpp
//  HW1
//
//  Created by WangSiwen on 15-4-7.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.


#include <stdio.h>
#include "newSequence.h"
#include <cassert>
#include <iostream>
//
using namespace std;
//

int main(){
    //cout<<1;
Sequence a(1000);   // a can hold at most 1000 items
    //cout<<1;
Sequence b(5);      // b can hold at most 5 items
Sequence c;         // b can hold at most DEFAULT_MAX_ITEMS items
ItemType v = 3;

// No failures inserting 5 items into b
for (int k = 0; k < 5; k++)
assert(b.insert(v));

// Failure if we try to insert a sixth item into b
assert(!b.insert(v));

// When two Sequences' contents are swapped, their capacities are
// swapped as well:
a.swap(b);
    assert(!a.insert(v)  &&  b.insert(v));
    assert(a.find(3)!=-1);
}