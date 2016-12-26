/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pawn.h
 * Author: goelarna
 *
 * Created on December 25, 2016, 2:39 PM
 */

#ifndef PAWN_H
#define PAWN_H
#include <string>
#include "ChessPieces.h"
class Pawn: public ChessPieces {
public:
    Pawn();
    char getColour(){return colour;}
    void setColour(char _colour){colour=_colour;}
    Pawn(const Pawn& orig);
    bool ValidMove(int srcrow,int srccol, int dstrow , int dstcol);
    virtual ~Pawn();
private:
    char colour;  
};

#endif /* PAWN_H */

