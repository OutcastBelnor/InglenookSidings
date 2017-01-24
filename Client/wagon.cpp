/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wagon.cpp
 * Author: jaj48
 * 
 * Created on 14 December 2016, 12:32
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include "vehicle.h"
#include "wagon.h"

using namespace std;

wagon::wagon(boost::tokenizer<boost::escaped_list_separator<char> >::iterator &data)
: vehicle(data)
{
    string contents = *data;
    boost::trim(contents);
    
    cargo = contents;
}

//wagon::~wagon()
//{
//    cout << "Destroying wagon." << endl;
//}

string wagon::getCargo()
{
    return cargo;
}

string wagon::streamHelper() const
{
    stringstream os;
    
    os << this->vehicle::streamHelper() << " Cargo: " << cargo;
    
    return os.str();
}