/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   siding.cpp
 * Author: jaj48
 * 
 * Created on 14 December 2016, 14:50
 */

#include <cstdlib>
#include <sstream>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include "siding.h"

using namespace std;

//siding::siding(int capacity, int current, vector<wagon> wagons)
//{
//    max_capacity = capacity;
//    current_capacity = capacity;
//    wagons_on_siding = wagons;
//}

siding::siding(boost::tokenizer<boost::char_separator<char> > tok,
                vector<wagon> wagons)
{
    auto data = tok.begin();
    
    string capacity = *data;
    boost::trim(capacity);
    max_capacity = stoi(capacity);
    data++;
    
    capacity = *data;
    boost::trim(capacity);
    current_capacity = stoi(capacity);
    data++;
    
    for(data; data != tok.end(); data++)
    {
        string number = *data;
        boost::trim(number);
        
        for (int i = 0; i < wagons.size(); i++)
        {
            if (stoi(number) == wagons[i].getSerialNumber())
            {
                wagons_on_siding.push_back(wagons[i]);
                break;
            }
        }
    }
}

int siding::getMaxCapacity()
{
    return max_capacity;
}

int siding::getCurrentCapacity()
{
    return current_capacity;
}

//stack<wagon> siding::getWagons()
//{
//    stack<wagon> wagons;
//    
//    wagons = wagons_on_siding.
//    
//    return wagons;
//}

string siding::sidingPrint()
{
    string siding = "";
    
    for (int i = wagons_on_siding.size() - 1; i >= 0 ; i--)
    {        
        siding += "=" + to_string(wagons_on_siding[i].getSerialNumber());
    }
    
    while (siding.size() < max_capacity * 6)
    {
        siding = "=" + siding;
    }
    
    return siding;
}

wagon siding::takeWagon()
{
    wagon w = wagons_on_siding.back();
    wagons_on_siding.pop_back();
    current_capacity--;
    return w;
}

void siding::putWagon(wagon w)
{
    wagons_on_siding.push_back(w);
    current_capacity++;
}

string siding::streamHelper() const
{
    stringstream os;
    
    os << "Siding of capacity " << max_capacity << " number of wagons " << current_capacity << endl;
    
    for (int i = 0; i < wagons_on_siding.size(); i++)
    {
        os << wagons_on_siding[i] << endl;
    }
    
    return os.str();
}