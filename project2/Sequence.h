//
//  Sequence.h
//  proj2
//
//  Created by WangSiwen on 15-4-14.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.
//

#ifndef proj2_Sequence_h
#define proj2_Sequence_h

#include <stdio.h>
#include <string>
using namespace std;

typedef unsigned long ItemType;
//typedef string ItemType;
const int DEFAULT_MAX_ITEMS = 200;
// Later in the course, we'll see that templates provide a much nicer
// way of enabling us to have Sequences of different types.  For now,
// we'll use a typedef.


class Sequence
{
public:
    Sequence();          // Create an empty sequence (i.e., one whose size() is 0).
    ~Sequence();
    Sequence(const Sequence &other);
    Sequence& operator=(const Sequence &other);
    bool empty() const;  // Return true if the sequence is empty, otherwise false.
    int size() const;    // Return the number of items in the sequence.
    
    bool insert(int pos, const ItemType& value);
    // Insert value into the sequence so that it becomes the item at
    // position pos.  The original item at position pos and those that
    // follow it end up at positions one higher than they were at before.
    // Return true if 0 <= pos <= size() and the value could be
    // inserted.  (It might not be, if the sequence has a fixed capacity,
    // e.g., because it's implemented using a fixed-size array.)  Otherwise,
    // leave the sequence unchanged and return false.  Notice that
    // if pos is equal to size(), the value is inserted at the end.
    
    bool insert(const ItemType& value);
    // Let p be the smallest integer such that value <= the item at
    // position p in the sequence; if no such item exists (i.e.,
    // value > all items in the sequence), let p be size().  Insert
    // value into the sequence so that it becomes the item at position
    // p.  The original item at position p and those that follow it end
    // up at positions one higher than before.  Return true if the value
    // was actually inserted.  Return false if the value was not inserted
    // (perhaps because the sequence has a fixed capacity and is full).
    
    bool erase(int pos);
    // If 0 <= pos < size(), remove the item at position pos from
    // the sequence (so that all items that followed this item end up at
    // positions one lower than they were at before), and return true.
    // Otherwise, leave the sequence unchanged and return false.
    
    int remove(const ItemType& value);
    // Erase all items from the sequence that == value.  Return the
    // number of items removed (which will be 0 if no item == value).
    
    bool get(int pos, ItemType& value) const;
    // If 0 <= pos < size(), copy into value the item at position pos
    // in the sequence and return true.  Otherwise, leave value unchanged
    // and return false.
    
    bool set(int pos, const ItemType& value);
    // If 0 <= pos < size(), replace the item at position pos in the
    // sequence with value and return true.  Otherwise, leave the sequence
    // unchanged and return false.
    
    int find(const ItemType& value) const;
    // Let p be the smallest integer such that value == the item at
    // position p in the sequence; if no such item exists, let p be -1.
    // Return p.
    
    void swap(Sequence& other);
    // Exchange the contents of this sequence with the other one.
    
private:
    ItemType *m_data;  // the items in the sequence
    int      m_size;                     // number of items in the sequence
    
    // At any time, the elements of m_data indexed from 0 to m_size-1
    // are in use.
    
    void uncheckedInsert(int pos, const ItemType& value);
    // Insert value at position pos, shifting items to the right to make
    // room for it.  Assume pos is valid and there's room.
};
int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

// Inline implementations

inline
int Sequence::size() const
{
    return m_size;
}

inline
bool Sequence::empty() const
{
    return size() == 0;
}
#endif
