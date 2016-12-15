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
#include <sstream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

#include "wagon.h"
#include "siding.h"

using namespace std;

vector<wagon> wagons;
vector<siding> sidings;

enum router {NORMAL, REVERSE};
vector<enum router> switches;

void readWagons()
{
    fstream file;
    file.open("wagon_data.txt");
    
    while (!file.eof())
    {
        string line;
        getline(file, line);
        
        boost::tokenizer<boost::escaped_list_separator<char> > tok(line);
        auto tok_it = tok.begin();
        wagon w(tok_it);
        
        wagons.push_back(w);
    }
    
    file.close();
}

void readSidings()
{
    fstream file;
    file.open("wagon_positions1.txt");
    
    vector<string> data;
    while (!file.eof())
    {
         string line;
        getline(file, line);
        
//        boost::char_separator<char> sep(" ", "\\t");
        boost::tokenizer<boost::char_separator<char> > tok(line);
        
        siding s(tok, wagons);
        
        sidings.push_back(s);
    }
    
    // create switches for appropriate sidings
    for (int i = 0; i < sidings.size() - 2; i++)
    {
        switches.push_back(NORMAL);
    }
    
    file.close();
}

void print()
{
    cout << "Here are the sidings\n" << endl;
    
    for (int i = 0; i < sidings.size(); i++)
    {
        cout << sidings[i].streamHelper() << endl;
    }
}


/**
 * Example diagram:
 *  Sidings diagram
    =77777=66666=55555\
                       |
                       | ===================22222=11111
                       \
                        \==================
                       \
                        \=99999=33333=88888
**/
void printDiagram()
{
    cout << "Sidings diagram" << endl;
    
    string s = sidings[0].sidingPrint();
    cout << "=";
    for (int i = s.size() - 1; i > 0; i--)
    {
        cout << s[i];
    }
    cout << "\\" << endl;
        
    string spaces = " ";
    for (int i = 0; i < s.size(); i++)
    {
        spaces += " ";
    }
    
    for (int i = 1; i < sidings.size(); i++)
    {
        
        if (switches[i - 1] == REVERSE || i == sidings.size() - 1)
        {
            cout << spaces << "\\" << endl;
            cout << spaces << " \\";
        }
        else if (switches[i - 1] == NORMAL)
        {
            cout << spaces << "|" << endl;
            cout << spaces << "| ";
        }
        string s = sidings[i].sidingPrint();
        cout << s << endl;
    }
    
    cout << endl;
}

void interpretCommands(int from_siding, int to_siding, int number_of_wagons)
{
    if (from_siding != 0 && to_siding != 0)
    {
        cout << "take " << from_siding << " " << number_of_wagons << endl;
        cout << "put " << to_siding << " " << number_of_wagons << endl;
    }
    else if (from_siding == 0)
    {
        cout << "put " << to_siding << " " << number_of_wagons << endl;
    }
    else if (to_siding == 0)
    {
        cout << "take " << from_siding << " " << number_of_wagons << endl; 
    }
}

void changeSwitches(int siding)
{
    for (int i = 0; i < siding; i++)
    {
        switches[i] = NORMAL;
    }
    
    if (siding != sidings.size() - 1)
    {
        switches[siding - 1] = REVERSE;
    }
}

void moveWagons(int from_siding, int to_siding, int number_of_wagons)
{
    if (sidings[from_siding].getCurrentCapacity() - number_of_wagons >= 0)
    {
        if (sidings[to_siding].getCurrentCapacity() + number_of_wagons <= sidings[to_siding].getMaxCapacity())
        {
            if (from_siding != 0 && to_siding != 0)
            {
                for (int i = 0; i < number_of_wagons; i++)
                {
                    wagon w = sidings[from_siding].takeWagon();
                    sidings[0].putWagon(w);
                }
                changeSwitches(from_siding);
                for (int i = 0; i < number_of_wagons; i++)
                {
                    wagon w = sidings[0].takeWagon();
                    sidings[to_siding].putWagon(w);
                }
                changeSwitches(to_siding);
            }
            else
            {
                for (int i = 0; i < number_of_wagons; i++)
                {
                    wagon w = sidings[from_siding].takeWagon();
                    sidings[to_siding].putWagon(w);
                }

                if(from_siding != 0)
                {
                    changeSwitches(from_siding);
                }
                else
                {
                    changeSwitches(to_siding);
                }
            }
        }
        else
        {
            cout << "There are is no space in siding " << to_siding << endl;
        }
    }
    else
    {
        cout << "There are not enough wagons in siding " << from_siding << endl;
    }
}

/*
 * 
 */
int main(int argc, char** argv)
{
    cout << "Inglenook Sidings jaj48" << endl;
    
    readWagons();    
    readSidings();
    
//    print();
    printDiagram();
    
    while(true)
    {
        cout << "Enter <from siding number> <to siding number> <number of wagons>" << endl;
        int from_siding, to_siding, number_of_wagons;
        cin >> from_siding >> to_siding >> number_of_wagons;
        
        if (from_siding > 0 && from_siding < sidings.size() - 1)
        {
            if (to_siding > 0 && to_siding < sidings.size() - 1)
            {
                if (number_of_wagons > 0)
                {
                    interpretCommands(from_siding, to_siding, number_of_wagons);
                    moveWagons(from_siding, to_siding, number_of_wagons);
                }
            }
            else
            {
                cout << "Invalid siding number." << endl;
            }
        }
        else
        {
            cout << "Invalid siding number." << endl;
        }
        
        printDiagram();
    }
        
    return 0;
}