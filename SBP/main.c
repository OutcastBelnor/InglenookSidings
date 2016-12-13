/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: jaj48
 *
 * Created on 12 December 2016, 12:26
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "header.h"

int sidings[4] = {0, 0, 0, 0};
int max_capacity[4] = {3, 5, 3, 3};

enum router switch_one = NORMAL;
enum router switch_two = NORMAL;

const char* getSwitch (enum router router)
{
    switch (router) 
    {
       case NORMAL: return "NORMAL";
       case REVERSE: return "REVERSE";
    }
}

/*
 * 
 */
int main(int argc, char** argv)
{
    int status;
    
    printf ("Inglenook Sidings jaj48\n");
    load(2, 3, 3);
//    printf ("%d %d %d %d", sidings[0], sidings[1], sidings[2], sidings[3]);
    
    char command[14] = "";
    while (command[0] != 'q')
    {
        scanf (" %[a-zA-Z0-9 ]", command);
//        printf("%s\n", command);
        
        if (command[0] == 'l')
        {
            char instruction[5];
            int siding_one_count, siding_two_count, siding_three_count;
            sscanf (command, "%s %d %d %d", instruction, &siding_one_count, &siding_two_count, &siding_three_count);
            printf("%s, %d, %d, %d\n", instruction, siding_one_count, siding_two_count, siding_three_count);
            
            status = load(siding_one_count, siding_two_count, siding_three_count);
        }
        else if (command[0] == 'p' || command[0] == 't')
        {
            char instruction[5];
            int siding, wagons;
            sscanf (command, "%s %d %d", &instruction, &siding, &wagons);
//            printf("%s, %d, %d\n", type, no1, no2);
            
            if (command[0] == 'p')
            {
                status = put(siding, wagons);
            }
            else if (command[0] == 't')
            {
                status = take(siding, wagons);
            }
        }
        else if (command[0] == 'h')
        {
            help();
            continue;
        }
        else
        {
            status = -4;
        }
        
        printf("Status %d %s %s\n", status, getSwitch(switch_one), getSwitch(switch_two));
//        printf ("%d %d %d %d\n", sidings[0], sidings[1], sidings[2], sidings[3]);
    }
    
    return (EXIT_SUCCESS);
}