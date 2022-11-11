#include <stdio.h>
#include <stdlib.h>

//defining node structure
typedef struct node{
    int DATA;
    struct node *next;
}Node;

//initialising nodes out of main for global scope
Node *headS = NULL;
Node *headC = NULL;

/* Single Linked List functions {displayListS, insertAtBeginningS, insertAtLocationS, insertAtEndS} */
void displayListS(){
    Node *temp = headS;

    if (temp == NULL)
    {
        printf("            |-----------------------------------------------------------------------------|\n");
        printf("          ! | LINKED LIST IS EMPTY.\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    }
    else
    {
        printf("       List |");
        while (temp != NULL){
            printf(" %d |", temp->DATA);
            temp = temp->next;
        }

        printf("\n            |-----------------------------------------------------------------------------|\n"); 
    }
    return;
}

void insertAtBeginningS(){
    int val;
    printf("         -> | Enter data for node insertion. \n");
    printf(" Enter Data | ");
    scanf("%d", &val);

    if (headS == NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->DATA = val;
        temp->next = NULL;
        headS = temp;
    } else{
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->DATA = val;
        temp->next = headS;
        headS = temp;
    }

    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListS();
    return;
}

void insertAtEndS(){
    int val;
    printf("         -> | Enter data for node insertion. \n");
    printf(" Enter Data | ");
    scanf("%d", &val);

    if (headS == NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->DATA = val;
        temp->next = NULL;
        headS = temp;
    } else{
        Node *temp1 = (Node *)malloc(sizeof(Node));
        temp1->DATA = val;
        temp1->next = NULL;
        Node *temp = headS;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = temp1;
    }

    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListS();
    return;
}

void insertAtLocationS(){
    
    int key;
    printf("         -> | Enter node data to link the node after. \n");
    printf("  Enter Key | ");
    scanf("%d", &key);

    if(headS == NULL){
        printf("            |-----------------------------------------------------------------------------|\n");
        printf("          ! | SINGLE LINKED LIST IS EMPTY.\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    }

    Node *temp = headS;
    Node *temp1 = (Node *)malloc(sizeof(Node));

    while((temp->DATA)!=key){
        if(temp->next == NULL){
            printf("            |-----------------------------------------------------------------------------|\n");
            printf("          ! | ENTERED NODE DATA NOT FOUND.\n");
            printf("            |-----------------------------------------------------------------------------|\n");
            return;
        }
        temp = temp->next;
    }
    if(temp->next == NULL){
        insertAtEndS();
        return;
    } else{
        int val;
        printf("         -> | Enter data for node insertion. \n");
        printf(" Enter Data | ");
        scanf("%d", &val);

        Node *temp2 = temp->next;
        temp1->DATA = val;
        temp->next = temp1;
        temp1->next = temp2;
    }
    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListS();
    return;
}

/* Circular Linked List Functions {displayListC, insertAtBeginningC, insertAtLocationC, insertAtEndC} */
void displayListC(){
    Node *temp = headC;

    if (temp == NULL)
    {
        printf("            |-----------------------------------------------------------------------------|\n");
        printf("          ! | LINKED LIST IS EMPTY.\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    }
    else
    {
        printf("       List |");
        do{
            printf(" %d |",temp->DATA);
            temp = temp->next;
        }while(headC!=temp);
        printf("\n            |-----------------------------------------------------------------------------|\n");
    }
    return;
}

void insertAtBeginningC(){
    int val;
    printf("         -> | Enter data for node insertion. \n");
    printf(" Enter Data | ");
    scanf("%d", &val);

    if (headC == NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->DATA = val;
        temp->next = temp;
        headC = temp;
    } else{
        Node *temp = headC;
        while((temp->next->DATA)!=headC->DATA){
            temp = temp->next;
        }
        Node *temp1 = (Node *)malloc(sizeof(Node));
        temp1->DATA = val;
        temp->next = temp1;
        temp1->next = headC;
        headC = temp1;
    }

    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListC();
    return;
}

void insertAtEndC(){
    int val;
    printf("         -> | Enter data for node insertion. \n");
    printf(" Enter Data | ");
    scanf("%d", &val);

    if(headC == NULL){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->DATA = val;
        temp->next = temp;
        headC = temp;
    } else{
        Node *temp = headC;
        while((temp->next->DATA)!=headC->DATA){
            temp = temp->next;
        }
        Node *temp1 = (Node *)malloc(sizeof(Node));
        temp1->DATA = val;
        temp->next = temp1;
        temp1->next = headC;
    }
    
    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListC();
    return;
}

void insertAtLocationC(){
    int key;
    printf("         -> | Enter node data to link the node after. \n");
    printf("  Enter Key | ");
    scanf("%d", &key);

    if(headC == NULL){
        printf("            |-----------------------------------------------------------------------------|\n");
        printf("          ! | CIRCULAR LINKED LIST IS EMPTY.\n");
        printf("            |-----------------------------------------------------------------------------|\n");
        return;
    }
    Node *temp = headC;
    Node *temp1 = (Node *)malloc(sizeof(Node));
    while(temp->DATA != key){
        temp = temp->next;
        if(temp == headC){
            printf("            |-----------------------------------------------------------------------------|\n");
            printf("          ! | ENTERED NODE DATA NOT FOUND.\n");
            printf("            |-----------------------------------------------------------------------------|\n");
            return;
        }
    }
    if(temp->next == headC){
        insertAtEndC();
        return;
    }
    else{
        int val;
        printf("         -> | Enter data for node insertion. \n");
        printf(" Enter Data | ");
        scanf("%d", &val);

        Node* temp2 = temp->next;
        temp1->DATA = val;
        temp->next = temp1;
        temp1->next = temp2;
    }
    printf("            |-----------------------------------------------------------------------------|\n");
    printf("          ! | NODE INSERTED.\n");
    printf("            |-----------------------------------------------------------------------------|\n");
    displayListC();
    return;
}

int main(){
    int mainMenu = 1;
    
    printf("            ===============================================================================\n");
    printf("            | Welcome User! This is a Menu driven program to insert nodes in Linked Lists |\n");
    printf("            ===============================================================================\n");

    while(mainMenu){
        int mainMenuOption;
        
        printf("         -> | Choose one of the following options: \n");
        printf("          0 | Exit current menu. \n");
        printf("          1 | Single Linked List. \n");
        printf("          2 | Circular Linked List. \n");
        printf("Enter Index | ");
        scanf("%d", &mainMenuOption);
        switch(mainMenuOption){
            case 1: {
                int subMenu = 1;

                while(subMenu){
                    int subMenuOption;

                    printf("         -> | Choose a option to Insert node in a Single Linked List: \n");
                    printf("          0 | Exit current menu. \n");
                    printf("          1 | Insert node at Beginning. \n");
                    printf("          2 | Insert node at specified Location. \n");
                    printf("          3 | Insert node at End. \n");
                    printf("          4 | Display Single Linked List. \n");
                    printf("Enter Index | ");
                    scanf("%d", &subMenuOption);
                    switch(subMenuOption){
                        case 1: {
                            insertAtBeginningS();
                            break;
                        }
                        case 2: {
                            insertAtLocationS();
                            break;
                        }
                        case 3: {
                            insertAtEndS();
                            break;
                        }
                        case 4: {
                            printf("            |-----------------------------------------------------------------------------|\n");
                            displayListS();
                            break;
                        }
                        case 0: {
                            subMenu = 0;
                            printf("            |-----------------------------------------------------------------------------|\n");
                            printf("         !! | SINGLE LINKED LIST MENU EXITED.\n");
                            printf("            |-----------------------------------------------------------------------------|\n");
                            break;
                        }
                        default: {
                            printf("            |-----------------------------------------------------------------------------|\n");
                            printf("          ! | INVALID OPTION.\n");
                            printf("            |-----------------------------------------------------------------------------|\n");
                            break;
                        }
                    }
                }
                break;
            }
            case 2: {
                int subMenu = 1;

                while(subMenu){
                    int subMenuOption;

                    printf("         -> | Choose a option to Insert node in a Circular Linked List: \n");
                    printf("          0 | Exit current menu. \n");
                    printf("          1 | Insert node at Beginning. \n");
                    printf("          2 | Insert node at specified Location. \n");
                    printf("          3 | Insert node at End. \n");
                    printf("          4 | Display Circular Linked List. \n");
                    printf("Enter Index | ");
                    scanf("%d", &subMenuOption);
                    switch(subMenuOption){
                        case 1: {
                            insertAtBeginningC();
                            break;
                        }
                        case 2: {
                            insertAtLocationC();
                            break;
                        }
                        case 3: {
                            insertAtEndC();
                            break;
                        }
                        case 4: {
                            printf("            |-----------------------------------------------------------------------------|\n");
                            displayListC();
                            break;
                        }
                        case 0: {
                            subMenu = 0;
                            printf("            |-----------------------------------------------------------------------------|\n");
                            printf("         !! | CIRCULAR LINKED LIST MENU EXITED.\n");
                            printf("            |-----------------------------------------------------------------------------|\n");
                            break;
                        }
                        default: {
                            printf("            |-----------------------------------------------------------------------------|\n");
                            printf("          ! | INVALID OPTION.\n");
                            printf("            |-----------------------------------------------------------------------------|\n");
                            break;
                        }
                    }
                }
                break;
            }
            case 0: {
                mainMenu = 0;
                printf("            |-----------------------------------------------------------------------------|\n");
                printf("        !!! | PROGRAM TERMINATED.\n");
                printf("            ===============================================================================\n");
                break;
            }
            default: {
                printf("            |-----------------------------------------------------------------------------|\n");
                printf("          ! | INVALID OPTION.\n");
                printf("            |-----------------------------------------------------------------------------|\n");
                break;
            }
        }
        
    }

    return 0;
}