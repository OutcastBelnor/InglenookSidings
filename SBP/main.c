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
#include <string.h>

int sidings[4] = {0, 0, 0, 0};
int max_capacity[4] = {3, 5, 3, 3};

enum router {NORMAL, REVERSE};
enum router switch_one = NORMAL;
enum router switch_two = NORMAL;

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
    int i;
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
        else
        {
            status = -4;
        }
        
        printf("Status %d %s %s\n", status, getSwitch(switch_one), getSwitch(switch_two));
//        printf ("%d %d %d %d\n", sidings[0], sidings[1], sidings[2], sidings[3]);
    }
    
    return (EXIT_SUCCESS);
}