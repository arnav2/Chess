/* 
 * File:   Rectangle.h
 * Author: goelarna
 *
 * Created on December 1, 2016, 7:32 PM
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H
#include "ChessPieces.h"
#include "easygl.h"
#include "Shape.h"

class Rectangle:public Shape{
public:
    //Constructor
    Rectangle(string _name, string _colour, int sqaurecol, char squarerow, float _xcen, float _ycen, float width, float height);
   //Printing the rectangle 
   virtual void print () const;
   //Myltiplying the rectangle with a scale factor 
   virtual void scale (float scaleFac);
   //Computing the area of the rectangle 
   virtual float computeArea () const;
   //Solving the perimeter of the rectangle 
   virtual float computePerimeter () const;
   //Drawing the rectangle
   virtual void draw (easygl* window) const;
   //Checking if point inside rectangle 
   virtual bool pointInside (float x, float y) const;
   
   virtual void translate(float xshift,float yshift){/*do nothing*/};
   
   //Destructor rectangle 
   virtual ~Rectangle();
private:
    //private variables 
    float width;
    float height; 
    bool hasPiece; 
    int squarecol; 
    char squarerow;
    ChessPieces storePiece;
};

#endif	/* RECTANGLE_H */

//Don't think this is required 
/*
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
 */