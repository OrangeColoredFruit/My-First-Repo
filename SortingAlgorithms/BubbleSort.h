#ifndef BUBBLESORT_H_INCLUDED
#define BUBBLESORT_H_INCLUDED

#include <stdbool.h>

algoNode *bubbleSort(algoNode *listHead);

algoNode *bubbleSort(algoNode *listHead)
{
    bool swapped;
    algoNode *runner;

    int swapCount=0;

    do{
        swapped=false;
        runner=listHead;

        while(runner->next!=NULL)
        {
            displayList(listHead);
            printf("runner at %d\n", runner->i);

            if(runner->i > runner->next->i)
            {
                printf("Swapped %d and %d \n", runner->i, runner->next->i);
                listHead = ptrNodeSwap(listHead, runner, runner->next);
                swapped = true;
                swapCount++;
            }
            else
            {
                printf("No Swap!\n");
                runner=runner->next;
            }
            displayList(listHead);
        }
        printf("Swap Count: %d\n\n", swapCount);

    }while(swapped);

    return listHead;
}
#endif // BUBBLESORT_H_INCLUDED
