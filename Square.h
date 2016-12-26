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
    void setcolour(char _colour);
    void setsquarecol(int _squarecol);
    void setsquarerow(char _squarerow);
    void sethasPiece(bool _hasPiece);
    void setstorePiece(ChessPieces _storePiece);
    //Getters 
    char& getcolour();
    int& getsquarecol();
    char& getsquarerow();
    bool& gethasPiece();
    ChessPieces& getstorePiece();
    
    Square(const Square& orig);
    //Print function 
    void print(); 
    
    virtual ~Square();
    
};

#endif /* SQUARE_H */

