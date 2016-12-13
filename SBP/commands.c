/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "header.h"

int put(int siding, int wagons)
{
//    printf ("put func");
    if (siding > 3 || siding < 0)
    {
        return -3;
    }
    else if (sidings[0] - wagons < 0)
    {
        return -2;
    }
    else if (sidings[siding] + wagons > max_capacity[siding])
    {
        return -1;
    }
    else
    {
        if (siding == 0)
        {
            return -1;
        }
        else if (siding == 1)
        {
            switch_one = REVERSE;
        }
        else if (siding == 2)
        {
            switch_one = NORMAL;
            switch_two = REVERSE;
        }
        else if (siding == 3)
        {
            switch_one = NORMAL;
            switch_two = NORMAL;
        }
        
        sidings[0] -= wagons;
        sidings[siding] += wagons;
        
        return wagons;
    }
}

int take(int siding, int wagons)
{
//    printf ("take func");
    if (siding > 3 || siding < 0)
    {
        return -3;
    }
    else if (sidings[siding] - wagons < 0)
    {
        return -2;
    }
    else if (sidings[0] + wagons > max_capacity[0])
    {
        return -1;
    }
    else
    {
        if (siding == 0)
        {
            return -1;
        }
        else if (siding == 1)
        {
            switch_one = REVERSE;
        }
        else if (siding == 2)
        {
            switch_one = NORMAL;
            switch_two = REVERSE;
        }
        else if (siding == 3)
        {
            switch_one = NORMAL;
            switch_two = NORMAL;
        }
        
        sidings[0] += wagons;
        sidings[siding] -= wagons;
        
        return wagons;
    }
}

int load(int one, int two, int three)
{
//    printf ("load func");
    if (sidings[1] + one <= max_capacity[1])
    {
        if (sidings[2] + two <= max_capacity[2])
        {
            if (sidings[3] + three <= max_capacity[3])
            {
                sidings[1] = one;
                sidings[2] = two;
                sidings[3] = three;
        
                return 0;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}

void help ()
{
    printf ("\nHelp:\n"
            "This program can take three commands: \n\n"
            "put <siding number> <number of wagons>\n"
            "takes two parameters: the destination siding number and number of wagons to move\n\n"
            "take <siding number> <number of wagons>\n"
            "takes two parameters: the source siding and number of wagons to move\n\n"
            "load <siding 1 wagon count> <siding 2 wagon count> <siding 3 wagon count>\n"
            "takes three parameters: number of wagons to put in the siding one two and three\n\n");
}