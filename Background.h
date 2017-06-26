

#ifndef Background_H
#define	Background_H

#include <sstream>
#include "Shape.h"
#include "easygl.h"
using namespace std;

class Background {
private:
   // Array of pointers to Background objects
   // From [0..nBackground-1] have valid data, and there is storage for data from [0..capacity-1]
   Shape** Backgrounds;  
   int nBackground;          // Number of valid Background objects
   int capacity;        // Capacity (allocated size) of Background
   
   Shape* selectedBackground;  // Pointer to any "clicked on" Background.
   string savedColour;    // Original colour of selected Background.
   
   easygl* window;      // pointer to the graphics window object (for drawing)
   
   /*******  Miscellaneous helper functions. *******************/
   void resize (int newCapacity);  // Resizes Backgrounds to the new capacity.
  
   // Returns a pointer the Background covering the specified (x,y) location,
   // or NULL if no Background covers thats spot.  If multiple Backgrounds cover that
   // spot, the one on top (last drawn) is returned.
   Shape* findBackground (float x, float y);
      
public:
   Background();
   ~Background();

   // Adds newBackground to the Backgrounds array, creating more storage if necessary.
   void addBackground (Shape *newBackground);  
   
      // Returns a pointer to the Background (in Backgrounds) with the specified name,
   // or NULL if no Background with that name is in the array.
   Shape* findBackground (string name);
   
   // Functions which each parse and execute a specific command.
   // They all take a stringstream argument, which contains a single input
   // line. The command has already been extracted; the arguments are left.
   void translate (stringstream& linestream);
   void scale (stringstream& linestream);
   void remove (stringstream& linestream);
   void printAll (stringstream& linestream);
   void computeArea (stringstream& linestream);
   void computePerimeter (stringstream& linestream);
   void handleDraw();
   
   // Function that redraws all the graphics; used in callbacks after a 
   // window events.
   void reDraw ();
   
   // Function that checks where a mouse click was, and highlights the Background
   // clicked on (if any).  Used in callbacks.
   void clickHighlight (float x, float y);
};

#endif	/* Background_H */

