/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   king.h
 * Author: goelarna
 *
 * Created on December 25, 2016, 2:41 PM
 */

#ifndef KING_H
#define KING_H
#include "ChessPieces.h"
class king:public ChessPieces {
public:
    king(char _colour);
    king(const king& orig);
    bool ValidMove(int srcrow,int srccol, int dstrow , int dstcol);
    virtual ~king();
private:

};

#endif /* KING_H */

