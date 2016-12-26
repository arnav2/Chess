/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queen.h
 * Author: goelarna
 *
 * Created on December 25, 2016, 2:40 PM
 */

#ifndef QUEEN_H
#define QUEEN_H
#include "ChessPieces.h"
class queen:public ChessPieces {
public:
    queen(char _colour);
    queen(const queen& orig);
    bool ValidMove(int srcrow,int srccol, int dstrow , int dstcol);
    virtual ~queen();
private:

};

#endif /* QUEEN_H */

