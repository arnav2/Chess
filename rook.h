/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rook.h
 * Author: goelarna
 *
 * Created on December 25, 2016, 2:39 PM
 */

#ifndef ROOK_H
#define ROOK_H
#include "ChessPieces.h"
class rook:public ChessPieces {
public:
    rook(char _colour);
    rook(const rook& orig);
    bool ValidMove(int srcrow,int srccol, int dstrow , int dstcol);
    virtual ~rook();
private:

};

#endif /* ROOK_H */

