//
//  History.h
//  project1_2
//
//  Created by WangSiwen on 15-4-6.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.
//

#ifndef __project1_2__History__
#define __project1_2__History__

#include "globals.h"

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
private:
    int     m_rows;
    int     m_cols;
    char    m_grid[MAXROWS][MAXCOLS];
};

#endif /* defined(__project1_2__History__) */
