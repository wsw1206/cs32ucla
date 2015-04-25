//
//  Game.h
//  project1_2
//
//  Created by WangSiwen on 15-4-6.
//  Copyright (c) 2015年 WangSiwen. All rights reserved.
//

#ifndef __project1_2__Game__
#define __project1_2__Game__

//#include <stdio.h>

class Pit;

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nSnakes);
    ~Game();
    
    // Mutators
    void play();
    
private:
    Pit* m_pit;
};
#endif /* defined(__project1_2__Game__) */
