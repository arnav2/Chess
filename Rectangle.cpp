/* 
 * File:   Rectangle.cpp
 * Author: goelarna
 * 
 * Created on December 1, 2016, 7:32 PM
 */
#include "Shape.h"
#include "Rectangle.h"
#include <iostream>
#include "easygl.h"
#include <cmath>
using namespace std;
//Constructors 
Rectangle :: Rectangle (string _name, string _colour, float _xcen, float _ycen, float _width,float _height)
        :Shape(_name,_colour,_xcen,_ycen){
    width=_width;
    height=_height;
}
//Printing the rectangle 
void Rectangle::print () const{
    Shape::print();
    cout<<"rectangle width: "<<width<<" height: "<<height<<endl;
}
//Scale factor that has to be multiplied 
void Rectangle::scale (float scaleFac){
    width=width*scaleFac;
    height=height*scaleFac;
}
//Computing the area 
float Rectangle::computeArea () const{
    return  width*height; 
}
//Calcultaing the perimeter 
float Rectangle::computePerimeter () const{
 return 2*(width+height);
}
//drawing the rectangle 
void Rectangle::draw (easygl* window) const{
    window->gl_setcolor(getColour()); // Sets color for subsequent drawing commands
    window->gl_fillrect (getXcen()-(width/2), getYcen()+(height/2), getXcen()+(width/2), getYcen()-(height/2));
}
//Checking whether a point insdide
bool Rectangle::pointInside (float x, float y) const{
    if ( (fabs(x-getXcen())<=(width/2)) && (fabs(y-getYcen())<=(height/2)) ){
        return true; 
    }
    else return false; 
}
//Destructor function 
Rectangle::~Rectangle() {
    
}

