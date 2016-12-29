/* 
 * File:   Polygon.h
 * Author: goelarna
 *
 * Created on December 1, 2016, 7:31 PM
 */

#ifndef POLYGON_H
#define	POLYGON_H

class Polygon:public Shape{
public:
    //Polygon constructor 
    Polygon(string _name, string _colour, t_point* vertices, int numPoints , float _xcen , float _ycen);
    //Print function 
    virtual void print () const;
    //Scale function 
    virtual void scale (float scaleFac);
    //COmputing the area 
    virtual float computeArea () const;
    //COmputing the perimeeter 
    virtual float computePerimeter () const;
    //Draw function 
    virtual void draw (easygl* window) const;
    //CHecking whether a point is inside 
    virtual bool pointInside (float x, float y) const;
    //Helper function that gets the vecctor between points 
    virtual t_point getVecBetweenPoints (t_point start, t_point end) const;
    //Destructor function 
    virtual ~Polygon();
private:
    //Private variable 
    t_point* Polyvertices;
    int nPoint;
};

#endif	/* POLYGON_H */

