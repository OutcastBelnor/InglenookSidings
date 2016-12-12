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

void put()
{
    printf ("put func");
}

void take()
{
    printf ("take func");
}

void load()
{
    printf ("load func");
}

int sidings[4] = {{0, 0, 0},
                  {0, 0, 0, 0, 0,},
                  {0, 0, 0},
                  {0, 0, 0}};

/*
 * 
 */
int main(int argc, char** argv)
{
    int i;
    
    printf ("Inglenook Sidings jaj48\n");
    
    char command[14] = "";
    while (command[0] != 'q')
    {
        scanf (" %[a-zA-Z0-9 ]", command);
//        printf(command);
        
        if (command[0] == 'p')
        {
            char *word;
            word = strtok(command, " ");
            printf ("%s\n", word);
            word = strtok(command, " ");
            printf ("%s\n", word);
            printf ("%s\n", command);
            
            
//            if(command[i+1] != ' ' || command[i+1] != 0)
//            {
//                int siding_no = atoi(command[i] + command [i+1]);
//                i = 7;
//            }
//            else
//            {
//                int siding_no
//
//            }
//            put ();
        }
        else if (command[0] == 't')
        {
//            take ();
        }
        else if (command[0] == 'l')
        {
//            load ();
        }
        else
        {
            
        }
    }
    
    
    return (EXIT_SUCCESS);
}

