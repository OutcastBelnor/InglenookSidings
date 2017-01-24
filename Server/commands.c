/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "header.h"

int put_or_take(int from_siding, int to_siding, int wagons)
{
    if (from_siding > number_of_sidings || from_siding < 0 || to_siding > number_of_sidings || to_siding < 0)
    {
        return -3;
    }
    else if (sidings[from_siding] - wagons < 0)
    {
        return -2;
    }
    else if (sidings[to_siding] + wagons > max_capacity[to_siding])
    {
        return -1;
    }
    else
    {
        int i; // This loop changes appropriate switches
        for (i = 0; i < abs(from_siding - to_siding); i++) //goes from zero to
        {                                       //the one before last and changes
            switches[i] = NORMAL;               //the switches to normal to allow
        }                                       //wagons to move
        switches[abs(from_siding - to_siding) - 1] = REVERSE; // and the last one 
                                                //to reverse to connect the siding
                                                //to the mainline
        sidings[from_siding] -= wagons;
        sidings[to_siding] += wagons;
        
        return wagons;
    }
}

void config(char *config_info)
{
    number_of_sidings = 0;
    int i;
    for (i = 6; i < strlen(config_info); i++)
    {
        if (config_info[i] == ' ')
        {
            number_of_sidings++;
        }
    }
    number_of_sidings /= 2;
    
    sidings = (int*)malloc(number_of_sidings * sizeof(int));
    max_capacity = (int*)malloc(number_of_sidings * sizeof(int));
    
    int j = 0;
    for (i = 7; i < strlen(config_info); i++)
    {
        max_capacity[j] = config_info[i] - 48;
        i += 2;
        sidings[j] = config_info[i] - 48;
        i++;
        j++;
    }
    
    switches = (enum router*)malloc((number_of_sidings - 2) * sizeof(enum router));
    for (i = 0; i < number_of_sidings - 1; i++)
    {
        switches[i] = NORMAL;
    }
}