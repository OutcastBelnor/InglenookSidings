/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wagon.h
 * Author: jaj48
 *
 * Created on 13 December 2016, 19:02
 */

#ifndef WAGON_H
#define WAGON_H

#include <cstdlib>
#include "vehicle.h"

using namespace std;

class wagon : public vehicle
{
    public:
        wagon();
        wagon(const wagon& orig);
        virtual ~wagon();
    private:
        string cargo;
};

#endif /* WAGON_H */

