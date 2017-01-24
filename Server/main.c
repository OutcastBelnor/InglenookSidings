/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates5
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
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include "header.h"

#define error(param) { fprintf(stderr, "Error: ");\
                        fprintf param ; }

#define abort(param) { fprintf(stderr, "Aborting: ");\
                        perror (param) ;\
                        exit(1) ; }
#define LAMBPORT 10040

int number_of_sidings;
int *sidings;
int *max_capacity;

enum router *switches;

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
    int status = 0, size = 10, i;
    
    printf ("Inglenook Sidings jaj48\n");
    
    struct sockaddr_in ourself;
    int socketid = -1;
    int my_socket, dup_sock;
    
    socketid = socket(AF_INET, SOCK_STREAM, 0);
    if (socketid < 0)
    {
        abort(" Couldn't create socket. ");
    }
    
#define TRUE  1
#define FALSE 0
    int z;
    int so_reuseaddr = TRUE;
    z = setsockopt(socketid, SOL_SOCKET, SO_REUSEADDR, &so_reuseaddr, sizeof so_reuseaddr);
    
    printf("setsockopt returned %d\n", z);
    
    ourself.sin_family = AF_INET;
    ourself.sin_addr.s_addr = INADDR_ANY;
    ourself.sin_port = htons(LAMBPORT);

    if (bind(socketid, (struct sockaddr *) & ourself, sizeof (ourself)) < 0) {
        (void) close(socketid);
        abort(" Couldn't bind to socket error ");
    }

    listen(socketid, 10);
    
    for (;;)
    {
        unsigned int len_otherend;
        struct sockaddr_in otherend;

        /* Wait for connection. */
        printf("About to accept...\n");
        do
        {
            errno = 0; // to make sure we don't react to an old error
            len_otherend = sizeof (otherend);
            my_socket = accept(socketid, (struct sockaddr *) & otherend,
                    &len_otherend);
        } while (my_socket < 0 && errno == EINTR);

        if (my_socket < 0)
        {
            error((stderr, " Couldn't accept; waiting..\n"));
            sleep(5);
            continue;
        }
        printf("Connected.\n");
        
        dup_sock = dup(my_socket);
        
        char command[100];
        read(my_socket, command, sizeof(command));
        
        write(dup_sock, "Inglenook Sidings jaj48", 24 * sizeof(char));

        config(command);

        while (command[0] != 'q')
        {
//            scanf (" %[a-zA-Z0-9 ]", command);
            read(my_socket, command, sizeof(command));
//            printf("%s", command);

            if (command[0] == 'p' || command[0] == 't')
            {
                char instruction[5];
                int siding, wagons;
                sscanf (command, "%s %d %d", &instruction, &siding, &wagons);

                if (instruction[0] == 'p')
                {
                    status = put_or_take(0, siding, wagons);
                }
                else if (instruction[0] == 't')
                {
                    status = put_or_take(siding, 0, wagons);
                }
            }
            else
            {
                status = -4;
            }
            
            char status_str[200];
            strcpy(status_str,"Status ");
            strcat(status_str, status - 48);

            int i;
            for (i = 0; i < number_of_sidings - 1; i++)
            {
                strcat(status_str, " ");
                strcat(status_str, getSwitch(switches[i]));
            }

//            write(dup_sock, status_str, sizeof(status_str));
        }
    }
    
    free(max_capacity);
    free(sidings);
    free(switches);    
    
    return (EXIT_SUCCESS);
}