/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bishop.h
 * Author: goelarna
 *
 * Created on December 25, 2016, 2:40 PM
 */

#ifndef BISHOP_H
#define BISHOP_H
#include "ChessPieces.h"
class bishop:public ChessPieces {
public:
    bishop(char _colour);
    bishop(const bishop& orig);
    bool ValidMove(int srcrow,int srccol, int dstrow , int dstcol);
    virtual ~bishop();
private:

};

#endif /* BISHOP_H */

