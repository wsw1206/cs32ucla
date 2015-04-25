//
//  main.cpp
//  HW1
//
//  Created by WangSiwen on 15-4-7.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.


#include <iostream>
#include <cassert>
#include "Sequence.h"
int main(int argc, const char * argv[]) {
    Sequence s;
    s.insert(0, "a");
    s.insert(1, "b");
    s.insert(2, "c");
    s.insert(3, "b");
    s.insert(4, "e");
    assert(s.remove("b") == 2);
    assert(s.size() == 3);
    string x;
    assert(s.get(0, x)  &&  x == "a");
    assert(s.get(1, x)  &&  x == "c");
    assert(s.get(2, x)  &&  x == "e");
    return 0;
}
