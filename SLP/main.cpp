/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jaj48
 *
 * Created on 12 December 2016, 12:27
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include "vehicle.h"
#include "wagon.h"

using namespace std;

vector<string> readFile(string fileName)
{
    fstream file;
    file.open(fileName);
    
    vector<string> data;
    while (!file.eof())
    {
        string line;
        getline(file, line);
        data.push_back(line);
    }
    
    file.close();
    return data;
}

/*
 * 
 */
int main(int argc, char** argv)
{
    vector<string> wagon_data = readFile("wagon_data.txt");
    vector<string> positions = readFile("wagon_positions.txt");    
    
    
    
    return 0;
}

