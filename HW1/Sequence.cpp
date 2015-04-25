//
//  Sequence.cpp
//  HW1
//
//  Created by WangSiwen on 15-4-7.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.
//

#include "Sequence.h"
#include <iostream>
//#include <cassert>


using namespace std;
Sequence::Sequence()
:m_size(0)
{
}

bool Sequence::empty() const
{
    if (m_size == 0)
        return true;
    return false;
}

int Sequence::size() const
{
    return m_size;
}

bool Sequence::insert(int pos, const ItemType& value)
{
    if (pos<0||pos>m_size) {
        return false;
    }
    m_size++;
    for(int i=m_size-1;i>pos;i--){
        m_list[i]=m_list[i-1];
    }
    m_list[pos]=value;
    return true;
}

bool Sequence::insert(const ItemType& value)
{
    for(int i=0;i<m_size;i++){
        if(m_list[i]<=value){
            if(m_size<DEFAULT_MAX_ITEMS){insert(i, value);return true;}
            else return false;
        }
    }
    if(m_size<DEFAULT_MAX_ITEMS)insert(m_size, value);
    else return false;
    return true;
}

bool Sequence::erase(int pos)
{
    if (pos<0||pos>=m_size) {
        return false;
    }
    for(int i=pos;i<m_size-1;i++){
        m_list[i]=m_list[i+1];
    }
    m_size--;
    return true;
}

int Sequence::remove(const ItemType& value)
{
    int sum=0;
    for(int i=0;i<m_size;i++){
        if(m_list[i]==value){sum++; erase(i);i--;}
    }
    return sum;
}

bool Sequence::get(int pos, ItemType& value)const
{
    if (pos<0||pos>=m_size) {
        return false;
    }
    value=m_list[pos];
    return true;
}

bool Sequence::set(int pos, const ItemType& value)
{
    if (pos<0||pos>=m_size) {
        return false;
    }
    m_list[pos]=value;
    return true;
}

int Sequence::find(const ItemType& value)const
{
    for(int i=0;i<m_size;i++){
        if(m_list[i]==value) return i;
    }
    return -1;
}

void Sequence::swap(Sequence& other)
{
    //swap sizes
    int hold_size = m_size;
    m_size = other.size();
    other.m_size = hold_size;
    //swap values
    ItemType hold;
    for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    {
        hold = m_list[i];
        m_list[i] = other.m_list[i];
        other.m_list[i] = hold;
    }
}

