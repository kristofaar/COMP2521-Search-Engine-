// Interface to the String List ADT
// Taken from lab05     


#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include "Graph.h"

typedef struct list *List;



// Takes list, convert to array, print array
void ListPrintArray(List l);

// Sets pagerank for each page in list from pagerankList 
void ListSetRank(List l);

// Order list by match terms
// Returns new list, frees original
List ListOrderMatch(List l);

// Check if name already exists in list
int ListCheck(List l, char *n);

// Write list to file
void ListWrite(List l);

//Returns sorted list copy, frees original 
List ListSortOrder(List l);

// Print outdegrees for all pages in list
void PrintOutdeg(List l);

// Returns sum of pagerank difference between 2 lists
double DiffRank(List src, List dest);

// Print out every pagerank in list
void PrintRank(List l);

// Find pageranks for every page in list
void PageRank(List l, List dest, Graph win, Graph wout, double d);

// Create copy of list 
// Insert node in order starting from head
List ListCopy(List l);

// Find in-weight and out-weight for every link 
void calcWeight(Graph win, Graph wout, Graph g, List l);

// Find outdegree and indegree for every page (indexed in graph)
void FindWeight(Graph g, List l);

// Find index by name for url in list
// Return index
int FindIndex(char *s, List l);

// Orders list node indexes and sets page rank to 1 / N
void ListIndexPR(List l);

// Takes in list and
// Reads in urls inside each url 
void ReadUrl(List l, Graph g);

// Creates a new empty list
// Complexity: O(1)
List ListNew(void);

// Frees all memory allocated for the given list
// Complexity: O(n)
void ListFree(List l);

// Adds a string to the end of the list. Makes a copy of the string
// before adding it to the list.
// Complexity: O(1)
void ListAppend(List l, char *s);

// Returns the number of items in the list
// Complexity: O(1)
int  ListSize(List l);

// Sorts the list in ASCII order
// Average complexity: O(n log n)
void ListSort(List l);

// Prints the list, one string per line
// If the strings themselves contain newlines, too bad
void ListPrint(List l);

////////////////////////////////////////////////////////////////////////
// Do NOT use these functions

typedef struct listIterator *ListIterator;

// Creates an iterator for the given list
// Complexity: O(1)
ListIterator ListItNew(List l);

// Gets the next item in the list. The item should not be modified.
// Complexity: O(1)
char *ListItNext(ListIterator it);

// Checks if the list has a next item
// Complexity: O(1)
bool ListItHasNext(ListIterator it);

// Frees the given iterator
// Complexity: O(1)
void ListItFree(ListIterator it);

#endif

