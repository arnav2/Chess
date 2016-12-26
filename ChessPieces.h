/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ChessPieces.h
 * Author: goelarna
 *
 * Created on December 25, 2016, 2:38 PM
 */

#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include <string>
using namespace std;

class ChessPieces {
    private:
        string state;
        int posrow; 
        int poscol; 
    public:
        ChessPieces();
        ChessPieces(const ChessPieces& orig);
        //virtual bool ValidMove(int srcrow,int srccol, int dstrow , int dstcol);
        virtual ~ChessPieces();
 

};

#endif /* CHESSPIECES_H */

