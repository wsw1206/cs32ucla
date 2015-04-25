//
//  mazestack.cpp
//  HW2
//
//  Created by WangSiwen on 15-4-24.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.


//Write a C++ function named pathExists that determines whether or not a there's a path from start to finish in a 10x10 maze. Here is the prototype

#include <iostream>
#include <stack>
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
    stack<Coord> mazestack;
    Coord tmp=Coord(sr,sc);
    int row,col;
    mazestack.push(tmp);
    maze[sr][sc]='*';
    while (!mazestack.empty()) {
        tmp=mazestack.top();
        mazestack.pop();
        row=tmp.r();
        col=tmp.c();
        if (row==er && col==ec) {
            return true;
        }
        else
        {
            if (maze[row-1][col]!= 'X' && maze[row-1][col]!= '*') {
                maze[row-1][col]= '*';
                mazestack.push(Coord(row-1, col));
            }
            if (maze[row][col+1]!= 'X' && maze[row][col+1]!= '*') {
                maze[row][col+1]= '*';
                mazestack.push(Coord(row, col+1));
            }
            if (maze[row+1][col]!= 'X' && maze[row+1][col]!= '*') {
                maze[row+1][col]= '*';
                mazestack.push(Coord(row+1, col));
            }
            if (maze[row][col-1]!= 'X' && maze[row][col-1]!= '*') {
                maze[row][col-1]= '*';
                mazestack.push(Coord(row, col-1));
            }
        }
    }
    return false;
}


int main()
{
    char maze[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X'},
        { 'X','.','.','.','.','.','.','.','.','X'},
        { 'X','X','.','X','.','X','X','X','X','X'},
        { 'X','.','.','X','.','X','.','.','.','X'},
        { 'X','.','.','X','.','.','.','X','.','X'},
        { 'X','X','X','X','.','X','X','X','.','X'},
        { 'X','.','X','.','.','.','.','X','X','X'},
        { 'X','.','.','X','X','.','X','X','.','X'},
        { 'X','.','.','.','X','.','.','.','.','X'},
        { 'X','X','X','X','X','X','X','X','X','X'}
    };
    
    if (pathExists(maze, 6,4, 1,1))
    cout << "Solvable!" << endl;
    else
    cout << "Out of luck!" << endl;
}
