#include <stdio.h>
#include <stdlib.h>

#include "LinkedLists/LinkedList.h"
#include "SortingAlgorithms/BubbleSort.h"
#include "Unsorted.h"

int main()
{
    algoNode *listHead=NULL;

    int sample[]={2,4,30,14,12,2,3,47,22,24};
    listHead=arrayToList(sample, 10);
    displayList(listHead);
    listHead=bubbleSort(listHead);
    displayList(listHead);

    return 0;
}
