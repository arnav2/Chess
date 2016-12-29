/* 
 * File:   Rectangle.h
 * Author: goelarna
 *
 * Created on December 1, 2016, 7:32 PM
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H
#include "ChessPieces.h"
class Rectangle:public Shape {
public:
    //Constructor
    Rectangle(string _name, string _color, int sqaurecol, char squarerow, float _xcen, float _ycen, float width, float height);
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

