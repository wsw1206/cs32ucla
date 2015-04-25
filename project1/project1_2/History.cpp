//
//  History.cpp
//  project1_2
//
//  Created by WangSiwen on 15-4-6.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.
//


#include "History.h"

using namespace std;

void clearScreen();

History::History(int nRows, int nCols)
{
    if (nRows < 1 || nCols < 1 || nRows >= MAXROWS || nCols >= MAXCOLS)
    {
        cout << "***** History created with invalid size " << nRows << " by " << nCols << "!" << endl;
        exit(1);
    }
    m_rows = nRows;
    m_cols = nCols;
    
    int r, c;
    for (r = 0; r < nRows; r++)
        for (c = 0; c < nCols; c++)
            m_grid[r][c] = '.';
}

bool History::record(int r, int c)
{
    if (r < 1 || c < 1 || r >= MAXROWS || c >= MAXCOLS)
        return false;
    else
    {
        switch (m_grid[r-1][c-1])
        {
            case '.': m_grid[r-1][c-1] = 'A'; break;
            case 'Z': break;
            default: m_grid[r-1][c-1]++;
        }
        return true;
    }
    
}

void History::display() const
{
    clearScreen();
    
    int r, c;
    for (r = 0; r < m_rows; r++)
    {
        for (c = 0; c < m_cols; c++)
            cout << m_grid[r][c];
        cout << endl;
    }
    cout << endl;
}
