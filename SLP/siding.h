/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   siding.h
 * Author: jaj48
 *
 * Created on 14 December 2016, 14:50
 */

#ifndef SIDING_H
#define SIDING_H

#include <cstdlib>
#include <vector>
#include <sstream>

#include "wagon.h"

using namespace std;

class siding
{
    public:
        siding();
        siding(int capacity, int current, vector<wagon> wagons);
        siding(boost::tokenizer<boost::char_separator<char> > tok,
                vector<wagon> wagons);
        int getMaxCapacity();
        int getCurrentCapacity();
        vector<wagon> getWagons();
        string sidingPrint();
        virtual string streamHelper() const;
        
        wagon takeWagon();
        void putWagon(wagon w);
        
    private:
        int max_capacity;
        int current_capacity;
        vector<wagon> wagons_on_siding;
    };

#endif /* SIDING_H */

