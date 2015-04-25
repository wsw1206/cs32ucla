//
//  ScoreList.cpp
//  HW1
//
//  Created by WangSiwen on 15-4-7.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.
//

#include "ScoreList.h"
#include <iostream>

using namespace std;

ScoreList::ScoreList(){
    m_sequence=Sequence();
}

bool ScoreList::add(unsigned long score){
    if(score>=0 && score<=100 && m_sequence.size()<DEFAULT_MAX_ITEMS){
        m_sequence.insert(score);
        return true;
    }
    return false;
}

bool ScoreList::remove(unsigned long score){
    int mark=m_sequence.find(score);
    if(mark==-1) return false;
    if(m_sequence.erase(mark)) return true;
    return false;
}

int ScoreList::size()const{
    return m_sequence.size();
}

unsigned long ScoreList::minimum() const{
    unsigned long value;
    if(m_sequence.size()==0) return NO_SCORE;
    else{
        if(m_sequence.get(m_sequence.size()-1, value)) return value;
        else return NO_SCORE;
    }
}

unsigned long ScoreList::maximum() const{
    unsigned long value;
    if(m_sequence.size()==0) return NO_SCORE;
    else{
        if(m_sequence.get(0, value)) return value;
        else return NO_SCORE;
    }
}