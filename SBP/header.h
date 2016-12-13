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
    
extern int sidings[4];
extern int max_capacity[4];

enum router {NORMAL, REVERSE};
extern enum router switch_one;
extern enum router switch_two;

int put(int siding, int wagons);
int take(int siding, int wagons);
int load(int one, int two, int three);
void help ();


#ifdef __cplusplus
}
#endif

#endif /* HEADER_H */

