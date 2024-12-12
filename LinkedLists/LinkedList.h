#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

typedef struct node{
    int i;
    struct node*next;
    struct node*prev;
}algoNode;

algoNode *createList(algoNode *listHead);    //VALID
algoNode *createNewNode(int n);             //VALID
algoNode *intIndextoPointer(algoNode* listHead, int n); //VALID
algoNode *insertBeforeTarget(algoNode *listHead, algoNode *newNode, algoNode *target); //VALID
algoNode *insertAfterTarget(algoNode *listHead, algoNode *newNode, algoNode *target); //VALID
algoNode *targetNodePointer(algoNode *listHead, int x); //VALID
algoNode *removeNode(algoNode *listHead, algoNode *targetNode); //VALID
algoNode *swapNodes(algoNode *listHead, int x, int y); //VALID
algoNode *ptrNodeSwap(algoNode *listHead, algoNode *xnode, algoNode *ynode);//VALID
algoNode *manualList(algoNode *listHead, int listLength); //VALID
algoNode *appendNode(algoNode *listHead, algoNode *newNode); //VALID
algoNode *arrayToList(int sample[], int sampleSize); //VALID

void displayList(algoNode *listHead);        //VALID

algoNode *createList(algoNode *listHead)
{
    algoNode*newNode;

    for(int n=1;n<8;n++){
        newNode = createNewNode(n);

       listHead=appendNode(listHead, newNode);
    }
    return listHead;
};

algoNode *createNewNode(int n)
{
    algoNode *newNode;

    newNode = (algoNode*)malloc(sizeof(algoNode));

    newNode->i = n;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
};

algoNode *intIndextoPointer(algoNode *listHead, int n)
{
    algoNode *runner;
    runner=listHead;
    int i=0;
    if(listHead==NULL)
    {
        printf("listHead is NULL");
    }
    else if(n < 0 )
    {
        printf("Index is invalid");
    }
    else
    {
        if(n!=i)
        {
            while(runner->next!=NULL && i<n)
            {
//                printf("passed %d\n", runner->i);
                runner=runner->next;
                i++;
            }
        }
    }

    return runner;
}

algoNode *swapNodes(algoNode *listHead, int x, int y)
{
    algoNode *xnode;
    algoNode *ynode;

    xnode=intIndextoPointer(listHead, x);
    ynode=intIndextoPointer(listHead, y);
    printf("x = %d\ty = %d\n", xnode->i, ynode->i);

    listHead = ptrNodeSwap(listHead, xnode, ynode);
    return listHead;
}

algoNode *insertBeforeTarget(algoNode *listHead, algoNode *newNode, algoNode *target)
{
    newNode->next=target;
    if(target->prev==NULL)
    {
        newNode->prev=NULL;
        listHead=newNode;
    }
    else
    {
        newNode->prev=target->prev;
        target->prev->next=newNode;
    }
    target->prev=newNode;
    return listHead;
}

algoNode *insertAfterTarget(algoNode *listHead, algoNode *newNode, algoNode *target)
{
    if(target->next!=NULL)
    {
        target->next->prev=newNode;
    }
    newNode->next=target->next;
    target->next=newNode;
    newNode->prev=target;
    return listHead;
}

algoNode *targetNodePointer(algoNode *listHead, int x)
{
    algoNode *temp;
    temp = intIndextoPointer(listHead, x);

    return temp;
}

algoNode *removeNode(algoNode *listHead, algoNode *targetNode)
{
    if(targetNode->prev==NULL)
        listHead=targetNode->next;
    else
    {
        targetNode->prev->next=targetNode->next;
    }
    if(targetNode->next!=NULL)
    {
        targetNode->next->prev=targetNode->prev;
    }

    return listHead;
}

algoNode *ptrNodeSwap(algoNode *listHead, algoNode *xnode, algoNode *ynode)
{
    algoNode *prev;
    if(xnode == ynode)
        printf("Cannot Swap! pointers are pointing at the same node!");
    else if(listHead==NULL || xnode == NULL || ynode == NULL)
    {
        if(listHead==NULL)
            printf("listHead | ");
        if(xnode==NULL)
            printf("xnode | ");
        if(ynode==NULL)
            printf("ynode | ");

        printf("pointers are NULL");
    }
    else
    {
        if(ynode->prev==NULL)
        {
            prev=xnode->prev;
            xnode=ynode;
            ynode=prev->next;
//          If ynode points to the first item, the y node will swap pointers with the x node
        }
        else
        {
            prev=ynode->prev;
            //Sets a previous pointer
        }

        if(prev==xnode)
        {
            listHead=removeNode(listHead, ynode);
            listHead=insertBeforeTarget(listHead, ynode, xnode);
        }

        else
        {
//            printf("previous is %d\n", prev->i);
            listHead=removeNode(listHead, ynode);
//            printf("%d has been removed\n", ynode->i);
//            displayList(listHead);

            listHead=insertBeforeTarget(listHead, ynode, xnode);
//            printf("%d has been added before x node\n", ynode->i);
//            displayList(listHead);

            listHead=removeNode(listHead, xnode);
//            printf("%d has been removed\n", xnode->i);
//            displayList(listHead);

            listHead=insertAfterTarget(listHead, xnode, prev);
//            printf("%d has been added after %d\n", xnode->i, prev->i);
//            displayList(listHead);
        }
    }
    return listHead;
}

algoNode *manualList(algoNode *listHead, int listLength)
{
    algoNode *newNode;
    int n;
    for(int i=0;i<listLength;i++)
    {
        printf("Enter new Node: ");
        scanf("%d", &n);
        newNode=createNewNode(n);
        listHead=appendNode(listHead, newNode);
    }

    return listHead;
}

algoNode *appendNode(algoNode *listHead, algoNode *newNode)
{
    algoNode *runner;
    runner = listHead;

    if(listHead==NULL)
            listHead=newNode;
    else{
        runner=listHead;
        while(runner->next!=NULL)
            runner=runner->next;

        runner->next=newNode;
        newNode->prev=runner;
    }
    return listHead;
}

algoNode *arrayToList(int sample[], int sampleSize)
{
    algoNode *listHead=NULL;
    for(int i=0;i<sampleSize;i++){
        listHead=appendNode(listHead, createNewNode(sample[i]));
    }

    return listHead;
}

void displayList(algoNode *listHead)
{
    int y = 0;
    while(listHead->next!=NULL && y <=100)
    {
        printf("%d->", listHead->i);
        listHead=listHead->next;
        y++;
    }
    printf("%d->\n", listHead->i);
    y=0;
    while(listHead!=NULL && y <= 100)
    {
        printf("<-%d", listHead->i);
        listHead=listHead->prev;
        y++;
    }
    printf("\n\n");
}
#endif // LINKEDLIST_H_INCLUDED
