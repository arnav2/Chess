/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: goelarna
 *
 * Created on December 25, 2016, 2:37 PM
 */

#include <cstdlib>
#include <string>
#include "ChessPieces.h"
#include "Pawn.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
using namespace std;

/*
 * 
 */
//This should return an initial board with a graphics library 
int initialBoard();

int main(int argc, char** argv) {
    
    return 0;
}

int initialBoard(){
    //Construct the initial board
    king wKing('w');
    queen wQueen('w');
    rook wRookleft('w');
    rook wRookright('w');
    bishop wBishopleft('w');
    bishop wBishopright('w');
    knight wKnightleft('w');
    knight wKnightright('w');
    //For pawn I have to call it 8 times. 
    Pawn wPawn[8];
    
    //Similarly for black 
    Pawn bPawn[8];
    
    king bKing('b');
    queen bQueen('b');
    rook bRookleft('b');
    rook bRookright('b');
    bishop bBishopleft('b');
    bishop bBishopright('b');
    knight bKnightleft('b');
    knight bKnightright('b');
    
}