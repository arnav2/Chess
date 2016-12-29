/* 
 * File:   Polygon.cpp
 * Author: goelarna
 * 
 * Created on December 1, 2016, 7:31 PM
 */
#include "Shape.h"
#include "Polygon.h"
#include <iostream>
#include <cmath>
using namespace std;

//Constructor function of polygon 
Polygon::Polygon(string _name, string _colour, t_point* vertices, int numPoints , float _xcen , float _ycen):Shape(_name,_colour,_xcen,_ycen) {
    Polyvertices= new t_point[numPoints];
    nPoint=numPoints; 
    for (int i=0;i<numPoints;i++){
        Polyvertices[i].x=vertices[i].x;
        Polyvertices[i].y=vertices[i].y;
    }
}
//Printing all the vertices of the polygon 
void Polygon::print () const{
   Shape::print();
   cout<<" polygon ";
   for (int i = 0 ; i< nPoint ; i++){
    cout<<"("<<getXcen()+Polyvertices[i].x<<","<<getYcen()+ Polyvertices[i].y<<") ";
   }
   cout<< endl;
}
//Scaling the polygon using a scale factor
void Polygon::scale (float scaleFac){
     for (int i = 0; i < nPoint; i++) {
      Polyvertices[i].x *= scaleFac;
      Polyvertices[i].y *= scaleFac;
   }
 }

//Compute the area of polygon using the formula of polygon 
float Polygon::computeArea () const{
    float area = 0;
    int j = nPoint-1;
    for (int i=0; i<nPoint; i++)
    { area = area +  (Polyvertices[j].x+Polyvertices[i].x) * (Polyvertices[j].y-Polyvertices[i].y); 
      j = i;  //j is previous vertex to i
    }
    return (area/2);
}

//Compute the perimeter of the polygon 
float Polygon::computePerimeter () const {
   float perimeter = 0;
   float sideLength;
   int endIndex;
   t_point dist;
   
   for (int i = 0; i < nPoint; i++) {
      endIndex = (i + 1) % nPoint;
      dist = getVecBetweenPoints (Polyvertices[i], Polyvertices[endIndex]);
      sideLength = sqrt (dist.x * dist.x + dist.y * dist.y);
      perimeter += sideLength;
   }
   return perimeter;
}

//Destructor function 
Polygon::~Polygon() {
    delete Polyvertices; 
}


//Checking whether the point inside or not 
bool Polygon::pointInside (float x, float y) const {
   // Make a point that corresponds to where you clicked. Since all my
   // vertices are relative to the triangle center, it is more convenient
   // to also shift the click point so it is an offset from the triangle 
   // center.
   t_point click;
   click.x = x - getXcen();
   click.y = y - getYcen();
   
   // The test is that a horizontal line (ray) from x = -infinity to the click point
   // will cross (intersect) only one side of triangle to the left of the 
   // click point.  If the point is above or below the triangle, the ray will not
   // intersect any triangle sides. If the point is to the left of the triangle
   // the ray will also not intersect any sides to the left of the point.
   // If the point is to the right of the triangle, the ray will intersect
   // two sides of the triangle to its left. Only if the point is inside the 
   // triangle will the ray intersect exactly one side to the left of the point.
   
   t_point vecOfSide;
   float distanceAlongVector, yDistance;
   int endIndex;
   int sidesToLeft = 0;
   
   for (int istart = 0; istart < nPoint; istart++) {
      endIndex = (istart + 1) % nPoint; // Next vertex after istart
      vecOfSide = getVecBetweenPoints (Polyvertices[istart], Polyvertices[endIndex]);
      yDistance = (click.y - Polyvertices[istart].y);
      if (vecOfSide.y != 0) {
          distanceAlongVector = yDistance / vecOfSide.y;
      }
      else if (yDistance == 0) {
          distanceAlongVector = 0;
      }
      else {
          distanceAlongVector = 1e10; // Really infinity, but this is big enough
      }
      
      // We intersect this side if the distance (scaling) along the side vector to 
      // get to our "click" y point is between 0 and 1.  Count the first 
      // endpoint of the side as being part of the line (distanceAlongVector = 0)
      // but don't count the second endPoint; we'll intersect that point later 
      // when we check the next side.
      if (distanceAlongVector >= 0 && distanceAlongVector < 1) {
         float xIntersection = Polyvertices[istart].x + vecOfSide.x * distanceAlongVector;
         if (xIntersection <= click.x ) 
             sidesToLeft++;
      }
   }
   //Checking whether the number is odd or even. If odd return true 
   return (sidesToLeft %2 == 1);
}


// Private helper functions below.  Working out triangle area etc. 
// requires some vector math, so these helper functions are useful.

// Return the (x,y) vector between start and end points.
t_point Polygon::getVecBetweenPoints (t_point start, t_point end) const {
   t_point vec;
   vec.x = end.x - start.x;
   vec.y = end.y - start.y;
   return (vec);
}

//Drawing the polygon 
void Polygon::draw (easygl* window) const {
   // Load up the data structure needed by easygl, and draw the triangle
   // using the easygl::draw_polygon call.
   t_point coords[nPoint];  // This data type is in easygl_constants.h
   for (int i = 0; i < nPoint; i++) {
      coords[i].x = getXcen() + Polyvertices[i].x;
      coords[i].y = getYcen() + Polyvertices[i].y;
   }
   window->gl_setcolor(getColour());
   window->gl_fillpoly(coords, nPoint);
}