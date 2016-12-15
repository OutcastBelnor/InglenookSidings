/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wagon.h
 * Author: jaj48
 *
 * Created on 14 December 2016, 12:32
 */

#ifndef WAGON_H
#define WAGON_H

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <boost/tokenizer.hpp>
#include "vehicle.h"

using namespace std;

class wagon : public vehicle
{
    public:
        wagon(boost::tokenizer<boost::escaped_list_separator<char> >::iterator &data);
//        virtual ~wagon();
        string getCargo();
        
    protected:
        string streamHelper() const override;
        
    private:
        string cargo;
};

#endif /* WAGON_H */

