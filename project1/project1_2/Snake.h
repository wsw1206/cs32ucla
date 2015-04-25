//
//  Snake.h
//  project1_2
//
//  Created by WangSiwen on 15-4-6.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.
//

#ifndef __project1_2__Snake__
#define __project1_2__Snake__

class Pit;

class Snake
{
public:
    // Constructor
    Snake(Pit* pp, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    
    // Mutators
    void move();
    
private:
    Pit* m_pit;
    int  m_row;
    int  m_col;
};

#endif /* defined(__project1_2__Snake__) */
