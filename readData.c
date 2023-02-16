#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"
#include "Graph.h"

#define LENGTH 100

// Return list of urls from collection.txt
List GetCollection() {
    List urls = ListNew();
    FILE *fp = fopen("collection.txt", "r");
    char str[LENGTH + 1];
    while (fscanf(fp, "%s", str) != EOF) { //Insert urls into list
        ListAppend(urls, str);
    }
    fclose(fp);
    ListIndexPR(urls);
    return urls;
}

// Puts list into graph
// Returns graph of links between pages 
Graph GetGraph(List l) {
    Graph new = GraphNew(ListSize(l));
    ReadUrl(l, new); 
    FindWeight(new, l); 
    return new;
}

// Takes in parameters 
// Return rankpaged list 
List calculatePageRank(Graph g, double d, double diffPR, int maxIterations, List l) {

    // Make 2 graphs for storing inlink and outlink weights
    Graph win = GraphNew(ListSize(l));
    Graph wout = GraphNew(ListSize(l));
    calcWeight(win, wout, g, l);
    
    List copyL = ListCopy(l);    // List-copy to be swapped during iterations
    PageRank(l, copyL, win, wout, d);  
    
    int iteration = 0;
    double diff = diffPR;
    List src, dest;
    while (iteration < maxIterations && diff >= diffPR) {  //Calculate pagerank      
        if (iteration % 2) { // if iteration odd
            src = copyL;
            dest = l;        
        } else { // if iteration even
            src = l;
            dest = copyL;
        }
        PageRank(src, dest, win, wout, d);  
        diff = DiffRank(src, dest);          
        iteration++;                       
    }
    
    GraphFree(win);
    GraphFree(wout);   
    ListFree(src); 
    return dest;
}

// Reads in matching urls for given terms 
// Then inserts into and returns list
List ListTerms(int argc, char **argv) {
    List l = ListNew();
    FILE *fp = fopen("invertedIndex.txt", "r");
    for (int i = 1; i < argc; i++) {        
        char str[LENGTH];          
        while (fgets(str, 1000, fp) != NULL) {
            char s[2] = " ";
            char *token;
            token = strtok(str, s);             
            if (!strcmp(argv[i], token)) {                
                token = strtok(NULL, s);
                while (token != NULL) {
                    if (strcmp(token, "\n")) {
                        if (ListCheck(l, token)) {
                            ListAppend(l, token); 
                        } 
                    }                        
                    token = strtok(NULL, s);
                }
                break;          
            }   
        }
        fseek(fp, 0, SEEK_SET);
    }
    fclose(fp);
    return l;
}


