/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   king.cpp
 * Author: goelarna
 * 
 * Created on December 25, 2016, 2:41 PM
 */
#include "king.h"
#include "Polygon.h"
king::king(char _colour) {
    t_point temp[20]={(44,45),(23,45),(23,22),(44,22),(44,0),(68,0),(68,22),(89,22),(89,45),(68,45)};  
    for (int i=0;i<20;i++){ 
        vertice[i]= temp[i]; 
    }
    Polygon("king",_colour,vertice,10,57,31);
}

king::king(const king& orig) {
}

king::~king() {
}

