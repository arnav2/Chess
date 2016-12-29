/* 
 * File:   Circle.cpp
 * Author: goelarna
 * 
 * Created on December 1, 2016, 7:31 PM
 */

#include "Circle.h"
#include "Shape.h"
#include <cmath>
#include "easygl.h"
#include <iostream>
using namespace std;
//Circle constructor 
Circle::Circle(string _name, string _colour, float _xcen, float _ycen, float _radius)
        :Shape(_name,_colour,_xcen,_ycen) {
    radius=_radius;
}
//Calculating the area of the circle 
float Circle::computeArea () const{
    float area; 
    area = M_PI*radius*radius;
    return area; 
}
//Calculating the perimeter of the circle 
float Circle::computePerimeter () const{
    float perimeter;
    perimeter = M_PI*radius*2;
    return perimeter; 
}
//Drawing the circle on the window 
void Circle:: draw (easygl* window) const{
   window->gl_setcolor(getColour());
   window->gl_fillarc (getXcen(), getYcen(), radius, 0, 360);
   
}

//Printing the circle 
void Circle:: print() const { 
    Shape::print();
    cout<<"circle radius: "<< radius<<endl;
}
//Checking whether a point is inside the circle or not 
bool Circle::pointInside (float x, float y) const{
    float distance;
    distance= pow((pow((x-getXcen()),2)+pow((y-getYcen()),2)),0.5);
    if (distance<=radius)
        return true;
    else 
        return false; 
}
//Changing the size of the circle 
void Circle::scale (float scaleFac){
    radius=radius*scaleFac;
}

//Destructor in the circle 
Circle::~Circle() {
    
}

