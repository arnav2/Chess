/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Square.h
 * Author: goelarna
 *
 * Created on December 26, 2016, 3:44 PM
 */

#ifndef SQUARE_H
#define SQUARE_H
#include "ChessPieces.h"
#include <iostream>
using namespace std; 
class Square {
private:
    char colour; 
    int squarecol; 
    char squarerow;
    bool hasPiece; 
    ChessPieces storePiece; 
public:
    Square();
    
    //setters
    void setcolour(char _colour){colour=_colour;}
    void setsquarecol(int _squarecol){squarecol=_squarecol;}
    void setsquarerow(char _squarerow){squarerow=_squarerow;}
    void sethasPiece(bool _hasPiece){hasPiece=_hasPiece;}
    void setstorePiece(ChessPieces _storePiece){storePiece=_storePiece;}
    //Getters 
    char& getcolour(){return colour;}
    int& getsquarecol(){return squarecol;}
    char& getsquarerow(){return squarerow;}
    bool& gethasPiece(){return hasPiece;}
    ChessPieces& getstorePiece(){return storePiece;}
    
    void makerect();
    Square(const Square& orig);
    //Print function 
    void print(){cout<<storePiece;} 
    
    virtual ~Square();
    
};

#endif /* SQUARE_H */

