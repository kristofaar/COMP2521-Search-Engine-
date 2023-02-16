// COMP2521 Assignment 2

// Written by: Chris Tsang z5310212
// Date: 20 / 11 / 2021

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"
#include "readData.h"
#define LENGTH 1001

int main(int argc, char *argv[]) {
    // Put urls matching the terms into list
    List l = ListTerms(argc, argv);
        
    // Order and print list
    ListSetRank(l);    
    List new = ListOrderMatch(l);
    ListPrintArray(new);   
}



