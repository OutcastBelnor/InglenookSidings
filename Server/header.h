/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   header.h
 * Author: jaj48
 *
 * Created on 13 December 2016, 15:05
 */

#ifndef HEADER_H
#define HEADER_H

#ifdef __cplusplus
extern "C" {
#endif
    
extern int number_of_sidings;
extern int *sidings;
extern int *max_capacity;

enum router {NORMAL, REVERSE};
extern enum router *switches;

int put_or_take(int from_siding, int to_siding, int wagons);

void config(char *config_info);


#ifdef __cplusplus
}
#endif

#endif /* HEADER_H */

