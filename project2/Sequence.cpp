//
//  Sequence.cpp
//  proj2
//
//  Created by WangSiwen on 15-4-14.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.
//

#include "Sequence.h"
#include <iostream>
//#include <cassert>


using namespace std;
Sequence::Sequence()
: m_size(0)
{
    m_data=new ItemType[DEFAULT_MAX_ITEMS];
}

Sequence::~Sequence(){
    delete [] m_data;
}

Sequence::Sequence(const Sequence &other)
{
    m_size=other.m_size;
    m_data=new ItemType[DEFAULT_MAX_ITEMS];
    for(int i=0;i<other.m_size;i++)
    {
        m_data[i]=other.m_data[i];
    }
}

Sequence& Sequence::operator=(const Sequence& other)
{
    Sequence tmp(other);
    swap(tmp);
    return *this;
}


bool Sequence::insert(int pos, const ItemType& value)
{
    if (pos < 0  ||  pos > size()  ||  size() == DEFAULT_MAX_ITEMS)
        return false;
    uncheckedInsert(pos, value);
    return true;
}

bool Sequence::insert(const ItemType& value)
{
    if (size() == DEFAULT_MAX_ITEMS)
        return false;
    int pos;
    for (pos = 0; pos < size()  &&  value > m_data[pos]; pos++)
        ;
    uncheckedInsert(pos, value);
    return true;
}

bool Sequence::erase(int pos)
{
    if (pos < 0  ||  pos >= size())
        return false;
    for ( ; pos < size() - 1; pos++)
        m_data[pos] = m_data[pos+1];
    m_size--;
    return true;
}

int Sequence::remove(const ItemType& value)
{
    int keepPos = find(value);
    if (keepPos == -1)
        return 0;
    int count = 1;
    for (int examinePos = keepPos+1; examinePos < size(); examinePos++)
    {
        if (m_data[examinePos] == value)
            count++;
        else
        {
            m_data[keepPos] = m_data[examinePos];
            keepPos++;
        }
    }
    m_size -= count;
    return count;
}

bool Sequence::get(int pos, ItemType& value) const
{
    if (pos < 0  ||  pos >= size())
        return false;
    value = m_data[pos];
    return true;
}

bool Sequence::set(int pos, const ItemType& value)
{
    if (pos < 0  ||  pos >= size())
        return false;
    m_data[pos] = value;
    return true;
}

int Sequence::find(const ItemType& value) const
{
    for (int pos = 0; pos < size(); pos++)
        if (m_data[pos] == value)
            return pos;
    return -1;
}

void Sequence::swap(Sequence& other)
{
    // Swap elements.  Since the only elements that matter are those up to
    // m_size and other.m_size, only they have to be moved.
    
    int maxSize = (m_size > other.m_size ? m_size : other.m_size);
    for (int k = 0; k < maxSize; k++)
    {
        ItemType tempItem = m_data[k];
        m_data[k] = other.m_data[k];
        other.m_data[k] = tempItem;
    }
    
    // Swap sizes
    
    int tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;
}

void Sequence::uncheckedInsert(int pos, const ItemType& value)
{
    for (int k = size(); k > pos; k--)
        m_data[k] = m_data[k-1];
    m_data[pos] = value;
    m_size++;
}
int subsequence(const Sequence& seq1, const Sequence& seq2)
{
    if (seq1.size()<seq2.size()) return -1;
    int i,j,cur=0;
    ItemType val1,val2;
    for (i=0; i<=seq1.size()-seq2.size(); i++) {
        cur=i;
        for(j=0;j<seq2.size();j++){
            seq1.get(cur+j, val1);
            seq2.get(j, val2);
            if (val1!=val2) {
                break;
            }
        }
        if (j>=seq2.size()) {
            return cur;
        }
    }
    return -1;
}
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
    Sequence tmp(seq1);
    result=tmp;
    if (seq2.size()==0) {
        return;
    }
    if (seq1.size()==0) {
        result=seq2;
        return;
    }
    ItemType cur;
    for (int i=0; i<seq2.size(); i++) {
        seq2.get(i, cur);
        if (2*i<seq1.size()) {
            result.insert(2*i+1, cur);
        }
        else{
            result.insert(seq1.size(), cur);
        }
        
    }
    
}
