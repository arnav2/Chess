/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ChessPieces.cpp
 * Author: goelarna
 * 
 * Created on December 25, 2016, 2:38 PM
 */
#include <string>
#include "ChessPieces.h"

ChessPieces::ChessPieces() {
}

ChessPieces::ChessPieces(const ChessPieces& orig) {
}

ChessPieces::~ChessPieces() {
}
ostream& operator<< (ostream& os,const ChessPieces& rhs){
    os<< rhs.state; 
    return(os); 
}
