/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   knight.h
 * Author: goelarna
 *
 * Created on December 25, 2016, 2:39 PM
 */

#ifndef KNIGHT_H
#define KNIGHT_H
#include "ChessPieces.h"
class knight:public ChessPieces {
public:
    knight(char _colour);
    knight(const knight& orig);
    bool ValidMove(int srcrow,int srccol, int dstrow , int dstcol);
    virtual ~knight();
private:

};

#endif /* KNIGHT_H */

