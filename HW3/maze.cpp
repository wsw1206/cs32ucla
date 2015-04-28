//
//  mazequeue.cpp
//  HW2
//
//  Created by WangSiwen on 15-4-24.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.


//Write a C++ function named pathExists that determines whether or not a there's a path from start to finish in a 10x10 maze. Here is the prototype

#include <iostream>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};
bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    if (sr==er && sc==ec) {
        return true;
    }
    maze[sr][sc]='*';
    if (maze[sr-1][sc]!= 'X' && maze[sr-1][sc]!= '*') {
        if( pathExists(maze, sr-1, sc, er, ec)) return true;
    }
    if (maze[sr][sc+1]!= 'X' && maze[sr][sc+1]!= '*'){
        if(pathExists(maze, sr, sc+1, er, ec)) return true;
    }
    if (maze[sr+1][sc]!= 'X' && maze[sr+1][sc]!= '*'){
        if(pathExists(maze, sr+1, sc, er, ec))return true;
    }
    if (maze[sr][sc-1]!= 'X' && maze[sr][sc-1]!= '*'){
        if(pathExists(maze, sr, sc-1, er, ec)) return true;
    }
    return false;
}


