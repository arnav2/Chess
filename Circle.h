/* 
 * File:   Circle.h
 * Author: goelarna
 *
 * Created on December 1, 2016, 7:31 PM
 */

#ifndef CIRCLE_H
#define	CIRCLE_H
#include "Shape.h"

class Circle:public Shape  {
public:
    
    //Circle constructor 
    Circle(string _name, string _color, float _xcen, float _ycen, float radius);
   
    //compute the area 
    virtual float computeArea () const;
    //Compute the perimeter
    virtual float computePerimeter () const;
    //draw signal 
    virtual void draw (easygl* window) const;
    //checking whether a point is inside 
    virtual bool pointInside (float x, float y) const;
    
    //Print function 
    virtual void print () const;
    // Scales the circle to a factor of scaleFac. 
    virtual void scale (float scaleFac);
     
    virtual ~Circle();  //overrides the shape destructor 
    //Private variable 
private:
    float radius; 

};

#endif	/* CIRCLE_H */

