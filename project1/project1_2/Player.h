//
//  Player.h
//  project1_2
//
//  Created by WangSiwen on 15-4-6.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.
//

#ifndef __project1_2__Player__
#define __project1_2__Player__

class Pit;

class Player
{
public:
    // Constructor
    Player(Pit *pp, int r, int c);
    
    // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    bool isDead() const;
    
    // Mutators
    void   stand();
    void   move(int dir);
    void   setDead();
    
private:
    Pit*  m_pit;
    int   m_row;
    int   m_col;
    int   m_age;
    bool  m_dead;
};

#endif /* defined(__project1_2__Player__) */
