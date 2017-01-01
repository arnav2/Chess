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
#include "Square.h"
#include "ChessPieces.h"
#include "Pawn.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "Rectangle.h"

#include <iostream>
#include <cstdio>
#include <string>
#include "Shape.h"
#include "ShapeArray.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Background.h"
using namespace std;
const int width = 200; 
const int height= 200;  
/*
 * 
 */
//This should return an initial board with a graphics library 
int initialBoard();

string itoa(int value, int base) {

		string buf;

		// check that the base if valid
		if (base < 2 || base > 16) return buf;

		enum { kMaxDigits = 35 };
		buf.reserve( kMaxDigits ); // Pre-allocate enough space.


		int quotient = value;

		// Translating number to string with base:
		do {
			buf += "0123456789abcdef"[ abs( quotient % base ) ];
			quotient /= base;
		} while ( quotient );

		// Append the negative sign
		if ( value < 0) buf += '-';

		buf.assign( buf.rbegin(), buf.rend());
		return buf;
	}
int main(int argc, char** argv) {
    ShapeArray shapes; 
    king wKing('w');
    Rectangle*** rect= new Rectangle**[8];
    for (int i=0;i<8;i++){
        rect[i] =new Rectangle*[8];
    }
    //Rectangle(string _name, string _color, int sqaurecol, char squarerow, float _xcen, float _ycen, float width, float height);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++){
            string row=itoa(i,10);
            string col=itoa(j,10);
            if ((i+j)%2==0){
                rect[i][j]=new Rectangle(row+col,"black",j,i,j*width+width/2,i*height+height/2,width, height);
                shapes.addShape(rect[i][j]);
            }
            else {
                rect[i][j]=new Rectangle(row+col,"white",j,i,j*width+width/2,i*height+height/2,width, height);
                shapes.addShape(rect[i][j]);
            }
        }
    }
    
    shapes.handleDraw();
    
    
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
    Pawn bPawn[8];
    
    for (int i=0 ; i< 8 ; i++){
        wPawn[i].setColour('w');
        bPawn[i].setColour('b');
    }
    
    king bKing('b');
    queen bQueen('b');
    rook bRookleft('b');
    rook bRookright('b');
    bishop bBishopleft('b');
    bishop bBishopright('b');
    knight bKnightleft('b');
    knight bKnightright('b');
    //Set the initial position now ! 
    
    
}

