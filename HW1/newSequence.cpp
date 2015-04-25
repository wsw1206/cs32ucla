//
//  newSequence.cpp
//  HW1
//
//  Created by WangSiwen on 15-4-7.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.
//

#include "newSequence.h"
#include <iostream>
//#include <cassert>


using namespace std;
Sequence::Sequence()
:m_size(0),maxsize(DEFAULT_MAX_ITEMS)
{
    m_list=new ItemType [maxsize];
}

Sequence::Sequence(int siz)
:m_size(0),maxsize(siz)
{
    //maxsize=siz;
    m_list=new ItemType [maxsize];
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
    if(m_size>=maxsize) return false;
    m_size++;
    for(int i=m_size-1;i>pos;i--){
        m_list[i]=m_list[i-1];
    }
    m_list[pos]=value;
    return true;
}

bool Sequence::insert(const ItemType& value)
{
    if(m_size>=maxsize) return false;
    for(int i=0;i<m_size;i++){
        if(m_list[i]<=value){
            insert(i, value);return true;
            
        }
    }
    insert(m_size, value);
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
    
    int hold_max=maxsize;
    maxsize=other.maxsize;
    other.maxsize=hold_max;

    //swap values
    ItemType *hold;
    hold=m_list;
    m_list=other.m_list;
    other.m_list=hold;
    
    
//    for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
//    {
//        hold = m_list[i];
//        m_list[i] = other.m_list[i];
//        other.m_list[i] = hold;
//    }
}

Sequence::Sequence(const Sequence &other)
:m_size(other.m_size),maxsize(other.maxsize)
{
    m_list=new ItemType[maxsize];
    for (int i = 0; i < maxsize; i++)
        m_list[i] = other.m_list[i];
}