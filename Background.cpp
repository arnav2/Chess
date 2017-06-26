#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include <algorithm>
#include <string>
#include "easygl.h"
#include "Background.h"
using namespace std;
 
// Default constructor. Allocate a small amount of space for an array of 
// Backgrounds. No valid Backgrounds to start with.
Background::Background() {
   capacity = 1;
   Backgrounds = new Shape*[capacity];
   nBackground = 0;
   selectedBackground = NULL; // Nothing clicked on.
   savedColour = "";
   
   window = NULL;   // No graphics window open yet.
}


Background::~Background() {
   for (int i = 0; i < nBackground; i++) {
      delete Backgrounds[i];  // Delete each Background.
   }
   delete[] Backgrounds;  // Now delete the array of pointers to Background objects.
   Backgrounds = NULL;    // For safety only
   
   delete window;
   window = NULL;
}
   
   
// Insert the pointer to a newBackground into the array of Backgrounds.
// Create more space in the array if necessary.
void Background::addBackground (Shape *newBackground) {
   if (nBackground == capacity) 
      resize (2 * capacity);  // Double array size if we're out of room.
   
   Backgrounds[nBackground] = newBackground;
   nBackground++;
}


// Helper routine to resize the Backgrounds array (to get more storage).
void Background::resize (int newCapacity) {
   Shape **tmpArray = new Shape*[newCapacity];
   assert (newCapacity >= nBackground);   // Ensure enough space for valid data.
   
   for (int i = 0; i < nBackground; i++) // Copy over data.
      tmpArray[i] = Backgrounds[i];
   
   delete[] Backgrounds;
   Backgrounds = tmpArray;
   capacity = newCapacity;
}


Shape* Background::findBackground (string name) {
   for (int i = 0; i < nBackground; i++) {
      if (Backgrounds[i]->getName() == name) {
         return Backgrounds[i];
      }
   }   
   
   return NULL;   // Not found
}

void Background::scale (stringstream& linestream) {
   string name;
   float scaleFac;
   
   linestream >> name >> scaleFac;
   if (linestream.fail()) {
      cout << "Error: invalid arguments\n";
      return;
   }
   
   if (scaleFac < 0) {
      cout << "Error: scaling factor must be nonnegative\n";
      return;
   }
   
   Shape* Background = findBackground (name);
   if (Background == NULL) {
      cout << "Error: could not find Background with name " << name << endl;
      return;
   }   
   Background->scale (scaleFac);
   cout << "Success\n";
}


void Background::remove (stringstream& linestream) {
   string name;
   
   linestream >> name;
   if (linestream.fail()) {
      cout << "Error: invalid arguments\n";
      return;
   }
   
   int ifound = -1;
   for (int i = 0; i < nBackground; i++) {
      if (Backgrounds[i]->getName() == name) {
         ifound = i;
         break;
      }
   }
   
   if (ifound == -1) {
      cout << "Error: could not find Background with name " << name << endl;
      return;
   }
   
   delete Backgrounds[ifound];   // Remove this Background.
   // Now shift all entries after ifound over by one, to remove the empty
   // spot in the array.
   for (int i = ifound + 1; i < nBackground; i++)
      Backgrounds[i-1] = Backgrounds[i];
   
   nBackground--;
   cout << "Success\n";
}


void Background::printAll (stringstream& linestream) {
   for (int i = 0; i < nBackground; i++) {
      Backgrounds[i]->print();
   }
}


void Background::computeArea (stringstream& linestream) {
   double totalArea = 0;
   for (int i = 0; i < nBackground; i++) {
      totalArea += Backgrounds[i]->computeArea();
   }
   cout.precision (ShapePrecision);
   cout.setf (ios::fixed);
   cout << "Total area: " << totalArea << endl;
}


void Background::computePerimeter (stringstream& linestream) {
   double totalPerimeter = 0;
   for (int i = 0; i < nBackground; i++) {
      totalPerimeter += Backgrounds[i]->computePerimeter();
   }
   cout.precision (ShapePrecision);
   cout.setf (ios::fixed);
   cout << "Total perimeter: " << totalPerimeter << endl;
}


void Background::handleDraw() {
   
   
   // Create the graphics window, if it doesn't exist already.
   if (window == NULL)
      window = new easygl ("Background class program", RED);
   
   selectedBackground = NULL;  // Nothing clicked on
   
   // Figure out a reasonable coordinate system to draw in, based on the
   // centers of the Background objects. 
   float xmin = 0, ymin = 0, xmax = 0, ymax = 0;
   for (int i = 0; i < nBackground; i++) {
      xmin = min (xmin, Backgrounds[i]->getXcen() );
      xmax = max (xmax, Backgrounds[i]->getXcen() );
      ymin = min (ymin, Backgrounds[i]->getYcen() );
      ymax = max (ymax, Backgrounds[i]->getYcen() );
   }
   
   // Expand the drawable area a bit, since we just made something that 
   // covers the center of all the objects, not the edges.
   xmin -= (xmax - xmin) * .1;
   xmax += (xmax - xmin) * .1;
   ymin -= (ymax - ymin) * .1;
   ymax += (ymax - ymin) * .1;
   // Avoid making a coordinate system that is too small.
   if (xmin == xmax) {
      xmax++;
   }
   if (ymin == ymax) {
      ymax++;
   }
   
   // Sets the coordinate system such that these coordinates define the 
   // edges of the window.  The user can still zoom and zoom out after.
   window->set_world_coordinates(xmin, ymin, xmax, ymax);
   cout << "Passing control to graphics window. Click Proceed to return control to this command window\n";
   reDraw();  // Make any graphics changes show up right away.
   window->gl_flush();  // Ensure the graphics get displayed right away.
   window->gl_event_loop(this, false, false);
   cout << "Control returned to command window\n";

   delete window;  // Close down window so it's out of the way.
   window = NULL;
}


void Background::reDraw () {
   window->gl_clearscreen ();
   for (int i = 0; i < nBackground; i++) {
      Backgrounds[i]->draw(window);
   }
}


// Callback function used to highlight and move Backgrounds around in 
// response to mouse clicks in the graphics window.
// 1. First click:  highlight the Background clicked on, at (x,y).
// 2. Second click: move the Background to the specified (x,y).
void Background::clickHighlight (float x, float y) {
   
   if (selectedBackground != NULL) {
      // Second mouse click --> move the Background.
      // Move the selected Background to x,y and unhighlight it.
      selectedBackground->setXcen (x);
      selectedBackground->setYcen (y);
      selectedBackground->setColour (savedColour);
      selectedBackground = NULL;  // Unselected now.
   }
   else {
      // First mouse click: find the Background and highlight it
      selectedBackground = findBackground (x, y);
      if (selectedBackground != NULL) {
         savedColour = selectedBackground->getColour();
         if (savedColour != "red") {
            selectedBackground->setColour("green");
         }
         else {
            selectedBackground->setColour("green");
         }
      }
   }

   // Redraw the graphics and flush the graphics to make sure the screen is 
   // updated.
   reDraw();
   window->gl_flush();
}


// Look through Backgrounds in reverse order, checking to see if we clicked
// inside a Background. We go in reverse order so we check the Background on top 
// (draw last) first.  
Shape* Background::findBackground (float x, float y) {
   
   for (int i = nBackground-1; i >= 0; i--) {
      if (Backgrounds[i]->pointInside(x, y)) {
         return (Backgrounds[i]);
      }
   }
   
   return NULL;   // Not found
}
