//                                      LINKED LISTS PROJECT
// Team members:-
//Name1 : Thabet hussien thabet          sec:1                BN: 49
//Name2 : ehab mostafa farghaly          sec:1                BN: 42
//Name3 : waheed mohamed                 sec:4                BN:43
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
typedef struct listnode{
    char Student_Name[30];
    int Student_ID;
    int Score_Of_Last_Year;
    int Day_Of_Birth;
    int Year_Of_Birth;
    int Month_Of_Birth;
    struct listnode* next;
}ListNode;

typedef struct dynamicarray
{
    char Student_Name[30];
    int Student_ID;
    int Score_Of_Last_Year;
    int Day_Of_Birth;
    int Year_Of_Birth;
    int Month_Of_Birth;
}DynamicArray;

typedef struct list
{
    ListNode* head;
    ListNode* tail;
    size_t size;
}List;
void initializeList(List *);
void designList(int, List *);
void printList(List *);
ListNode* enterInformationOfStudent();// enter information of a student in linked list part
void enterInformationOfStudent2(DynamicArray*);//enter information of a student in dynamic array part
void insertInTheBeginning(List *, ListNode*);//linked list
void insertInTheEnd(List *, ListNode*);//linked list
void insert_In_Nth_Position_In_The_Middle(List *, int, ListNode*);//linked list
void print_dynamic_array_elements(DynamicArray*);
void Insert_in_the_beginning_of_dynamic_array(DynamicArray*, DynamicArray*);
void Insert_in_the_middle_of_dynamic_array(DynamicArray*, int, DynamicArray*);
void Insert_in_the_end_of_dynamic_array(DynamicArray*, DynamicArray*);

int n;

int main()
{
    int start1, start2, start3, start4 ,start5, start6;
    int end1, end2, end3, end4, end5, end6;
    puts("Welcome to our program!");
    printf("\n");
    printf("%s", "press 1, to develop functions using dynamic memory allocation\npress 2, to develop functions using linked lists\n");
    int choice1;
    scanf("%i", &choice1);

        switch(choice1)
        {
        case 1:
            {
                DynamicArray* currentElement = (DynamicArray*) malloc(sizeof(DynamicArray));
                puts ("Let's design your dynamic array!");
                printf("How many elements does the array initially consist of ? : ");
                scanf("%i", &n);
                bool validitySize = false;
                while (validitySize == false)
                {
                    if(n >= 1)
                    {
                        validitySize = true;
                    }
                    else
                    {
                        puts("you should enter a number which is greater than or equal to 1 !");
                        printf("Enter the new number : ");
                        scanf("%i", &n);
                    }
                }
                DynamicArray *arrayPtr = (DynamicArray* )malloc(n * sizeof(DynamicArray));
                for (int i = 0; i < n; ++i)
                {
                    printf("Now, we will enter the information of student %i\n", i + 1);
                    enterInformationOfStudent2((arrayPtr + i));
                }

            int choice4;
            bool endProgram = false;
            while (endProgram == false)
            {
                puts("To insert an element in the beginning of dynamic array, press 1!");
                puts("To insert an element in the middle of dynamic array, press 2!");
                puts("To insert an element in the end of dynamic array, press 3!");
                puts("To print the content of the dynamic array, press 4!");
                scanf("%i", &choice4);
                switch(choice4)
                {
                case 1:
                    puts("Now, you will insert the information of the recently added student");
                    puts("Insertion will be in the beginning!");
                    arrayPtr = (DynamicArray*) realloc(arrayPtr, (n + 1) * sizeof(DynamicArray));
                    enterInformationOfStudent2(currentElement);
                    start4 = clock();
                    Insert_in_the_beginning_of_dynamic_array(arrayPtr, currentElement);
                    end4 = clock();
                    break;
                case 2:
                    if (n <= 1)
                    {
                        printf("\n");
                        puts("size should be greater than 1!");
                        printf("\n");

                        break;
                    }
                    puts("Now, you will insert the information of the recently added student");
                    puts("Insertion will be in the middle!");
                    printf("Position should be greater than 0 and less than %i.!\n", n);
                    printf("Enter position where you want to insert! : ");
                    int position;
                    scanf("%i", &position);
                    if (position > 0 && position < n)
                    {
                        arrayPtr = (DynamicArray*) realloc(arrayPtr, (n + 1) * sizeof(DynamicArray));
                        enterInformationOfStudent2(currentElement);
                        start5 = clock();
                        Insert_in_the_middle_of_dynamic_array(arrayPtr, position, currentElement);
                        end5 = clock();
                    }
                    else
                    {
                        puts("Position out of scope!");
                        printf("Position should be greater than 0 and less than %i.!\n", n);
                    }
                    break;
                case 3:
                    puts("Now, you will insert the information of the recently added student");
                    puts("Insertion will be in the end!");
                    arrayPtr = (DynamicArray*) realloc(arrayPtr, (n + 1) * sizeof(DynamicArray));
                    enterInformationOfStudent2(currentElement);
                    start6 = clock();
                    Insert_in_the_end_of_dynamic_array(arrayPtr, currentElement);
                    end6 = clock();
                    break;
                case 4:
                    print_dynamic_array_elements(arrayPtr);
                    break;
                default:
                    puts("Invalid choice!");
                    puts("Choice should be between 1 and 4!");
                    break;
                }
                puts("If you want to end program, press -1.otherwise, The program continues!");
                int choice3;
                scanf("%i", &choice3);

                if(choice3 == -1)
                    endProgram = true;
            }
            printf("Time taken to insert a node in the beginning of a dynamic array is : %f\n", (float)(end4 - start4) / CLOCKS_PER_SEC);
            printf("Time taken to insert a node in the middle of a dynamic array is : %f\n", (float)(end5 - start5) / CLOCKS_PER_SEC);
            printf("Time taken to insert a node in the end of a dynamic array is : %f\n", (float)(end6 - start6) / CLOCKS_PER_SEC);
            printf("Size taken by an element of the dynamic array is : %i", sizeof(arrayPtr[0]));
            printf("Size taken by total elements of the dynamic array is : %i", n * sizeof(arrayPtr[0]));
            break;
            }

        case 2:
            {
                List list1;
                initializeList(&list1);
                puts("Let's design your list!");
                printf("How many elements does the list initially consist of ? : ");
                int N;
                scanf("%i", &N);
                bool validitySize = false;
                while (validitySize == false)
                {
                    if(N >= 1)
                    {
                        designList(N, &list1);
                        validitySize = true;
                    }
                    else
                    {
                       puts("you should enter a number which is greater than or equal to 1 !");
                       scanf("%i", &N);
                    }
                }
            int choice2;
            bool endProgram = false;
            while (endProgram == false)
            {
                printf("To insert in the beginning, press 1!\nTo insert in a certain position, press 2!\n");
                printf("To insert in the end, press 3!\nTo print your list, press 4!\n");
                scanf("%i", &choice2);
                ListNode* currentPtr;
                switch(choice2)
                {
                case 1:
                    currentPtr = enterInformationOfStudent();
                    start1 = clock();
                    insertInTheBeginning(&list1, currentPtr);
                    end1 = clock();
                    break;
                case 2:
                    if (list1.size <= 1)
                    {
                        puts("The size should be greater than or equal to 2");
                        puts("Add some new nodes, Then come back again!");
                        break;
                    }
                    printf("%s", "Enter the position where you want to insert ! : ");
                    int position;
                    scanf("%i", &position);
                    bool validityPostion = false;
                    while (validityPostion == false)
                    {
                        if(position > 0 && position < (list1.size))
                        {
                            currentPtr = enterInformationOfStudent();
                            start2 = clock();
                            insert_In_Nth_Position_In_The_Middle(&list1, position, currentPtr);
                            end2 = clock();
                            validityPostion = true;
                        }
                        else{
                            puts("Invalid position!!");
                            printf("position should be greater than 0 and less than %i\n", list1.size);
                            puts("Enter the new position!");
                            scanf("%i", &position);
                        }
                    }
                    break;
                case 3:
                    currentPtr = enterInformationOfStudent();
                    start3 = clock();
                    insertInTheEnd(&list1, currentPtr);
                    end3 = clock();
                    break;
                case 4:
                    printList(&list1);
                    break;
                default:
                    puts("Invalid choice!");
                    puts("Your choice must be greater than or equal to 1 and less than or equal to 7!");
                    break;
                }
                puts("If you want to end program, press -1.otherwise, The program continues!");
                int choice3;
                scanf("%i", &choice3);
                if(choice3 == -1)
                    endProgram = true;
            }
            printf("Time taken to insert a node in the beginning of a linked list is : %f\n", (float)(end1 - start1) / CLOCKS_PER_SEC);
            printf("Time taken to insert a node in the middle of a linked list is : %f\n", (float)(end2 - start2) / CLOCKS_PER_SEC);
            printf("Time taken to insert a node in the end of a linked list is : %f\n", (float)(end3 - start3) / CLOCKS_PER_SEC);
            printf("Size taken by a node of the linked list is : %i", sizeof(ListNode));
            printf("Size taken by total nodes of the linked list is : %i", (list1.size) * sizeof(ListNode));
            break;
            }
                default:
                    puts("Wrong choice!");
                    puts("You should enter either 1 or 2!");
                break;

        }


    return 0;
}


void initializeList(List *pointerToList)
{
    pointerToList->head = NULL;
    pointerToList->tail = NULL;
    pointerToList->size = 0;
}
void designList(int size,List *pointerToList)
{
    for(int j = 0; j < size; ++j)
    {
        printf("Enter the information of student %i\n", j + 1);
        if(pointerToList->head != NULL)
        {
            ListNode* newPtr = (ListNode*) malloc(sizeof(ListNode));

            newPtr = enterInformationOfStudent();
            newPtr->next = pointerToList->tail->next;
            pointerToList->tail->next = newPtr;
            pointerToList->tail = pointerToList->tail->next;
        }
        else
        {
            ListNode* newPtr = (ListNode*) malloc(sizeof(ListNode));

            newPtr = enterInformationOfStudent();
            newPtr->next = pointerToList->head;
            pointerToList->head = newPtr;
            pointerToList->tail = newPtr;
        }

        (pointerToList->size)++;
    }
}
void printList(List *pointerToList)
{
    printf("\n");
    printf("The size of the list is : %i !\n\n", pointerToList->size);
    if (pointerToList->size == 0)
    {
        puts("There are no nodes to print");
        return;
    }
    ListNode *currentPtr = pointerToList->head;
    puts("The list nodes are : ");
    printf("\n");
    int count = 1;
    while(currentPtr != NULL)
    {
        printf("The name of student %i is : %s",count, currentPtr->Student_Name);
        printf("The ID of this student is : %i\n", currentPtr->Student_ID);
        printf("The score of last year of this student is : %i\n", currentPtr->Score_Of_Last_Year);
        printf("The date of birth of this student is : %i.%i.%i\n" , currentPtr->Day_Of_Birth, currentPtr->Month_Of_Birth
               , currentPtr->Year_Of_Birth);
        currentPtr = currentPtr->next;
        count++;
        printf("\n\n");
    }
}
void insertInTheBeginning(List *pointerToList, ListNode* pointerToNode)
{
    ListNode* newPtr = (ListNode*) malloc(sizeof(ListNode));
    newPtr = pointerToNode;
    newPtr->next = pointerToList->head;
    pointerToList->head = newPtr;
    (pointerToList->size)++;
}
void insertInTheEnd(List *pointerToList, ListNode* pointerToNode)
{
    ListNode* newPtr = (ListNode*) malloc(sizeof(ListNode));

    newPtr = pointerToNode;
    newPtr->next = pointerToList->tail->next;
    pointerToList->tail->next = newPtr;
    pointerToList->tail = newPtr;
    (pointerToList->size)++;
}
void insert_In_Nth_Position_In_The_Middle(List *pointerToList, int position, ListNode* pointerToNode)
{

    ListNode* currentPtr;
    currentPtr = pointerToList->head;
    ListNode* newPtr = (ListNode*) malloc(sizeof(ListNode));
    newPtr = pointerToNode;
    for(int i = 0; i < position - 1; ++i)
    {
        currentPtr = currentPtr->next;
    }
    newPtr->next = currentPtr->next;
    currentPtr->next = newPtr;
    (pointerToList->size)++;
}

ListNode* enterInformationOfStudent()
{

    fflush(stdin);
    ListNode* pointerToListNode = (ListNode*) malloc(sizeof(ListNode));
    printf("Enter the name of your student : ");
    fgets(pointerToListNode->Student_Name, 30, stdin);

    printf("Enter the ID of of your student : ");
    scanf("%i", &(pointerToListNode->Student_ID));

    bool validity_ID = false;
    while (!validity_ID)
    {
        if (pointerToListNode->Student_ID >= 0)
            validity_ID = true;
        else
            {
                puts("Wrong ID!");
                printf("Enter a new ID : ");
                scanf("%i", &(pointerToListNode->Student_ID));
            }
    }

    printf("Enter the score of last year of of your student : ");
    scanf("%i", &(pointerToListNode->Score_Of_Last_Year));
    bool validity_Score = false;
    while (!validity_Score)
    {
        if (pointerToListNode->Score_Of_Last_Year >= 0)
            validity_Score = true;
        else
            {
                puts("Wrong score!");
                printf("Enter a new score : ");
                scanf("%i", &(pointerToListNode->Score_Of_Last_Year));
            }
    }

    printf("Enter the date of birth of of your student!\n");
    printf("%s","Enter the day : ");
    scanf("%i", &(pointerToListNode->Day_Of_Birth));
    printf("%s", "Enter the month :");
    scanf("%i", &(pointerToListNode->Month_Of_Birth));
    printf("%s", "Enter the year : ");
    scanf("%i", &(pointerToListNode->Year_Of_Birth));
    bool validity_DateOfBirth = false;
    while (!validity_DateOfBirth)
    {
        if ((pointerToListNode->Day_Of_Birth > 0 && pointerToListNode->Day_Of_Birth <= 31) && ((pointerToListNode->Month_Of_Birth) > 0
            && (pointerToListNode->Month_Of_Birth) <=12) && ((pointerToListNode->Year_Of_Birth) >= 0))
                validity_DateOfBirth = true;
        else
            {
                puts("Wrong date of birth!");
                printf("%s","Enter the day : ");
                scanf("%i", &(pointerToListNode->Day_Of_Birth));
                printf("%s", "Enter the month :");
                scanf("%i", &(pointerToListNode->Month_Of_Birth));
                printf("%s", "Enter the year : ");
                scanf("%i", &(pointerToListNode->Year_Of_Birth));
            }
    }
    printf("\n\n");
    return pointerToListNode;
}

void enterInformationOfStudent2(DynamicArray *pointerToDynamicArray)
{

    fflush(stdin);
    printf("Enter the name of your student : ");
    fgets(pointerToDynamicArray->Student_Name, 30, stdin);
    printf("Enter the ID of of your student : ");
    scanf("%i", &(pointerToDynamicArray->Student_ID));

    bool validity_ID = false;
    while (!validity_ID)
    {
        if (pointerToDynamicArray->Student_ID >= 0)
            validity_ID = true;
        else
            {
                puts("Wrong ID!");
                printf("Enter a new ID : ");
                scanf("%i", &(pointerToDynamicArray->Student_ID));
            }
    }

    printf("Enter the score of last year of of your student : ");
    scanf("%i", &(pointerToDynamicArray->Score_Of_Last_Year));
    bool validity_Score = false;
    while (!validity_Score)
    {
        if (pointerToDynamicArray->Score_Of_Last_Year >= 0)
            validity_Score = true;
        else
            {
                puts("Wrong score!");
                printf("Enter a new score : ");
                scanf("%i", &(pointerToDynamicArray->Score_Of_Last_Year));
            }
    }

    printf("Enter the date of birth of of your student!\n");
    printf("%s","Enter the day : ");
    scanf("%i", &(pointerToDynamicArray->Day_Of_Birth));
    printf("%s", "Enter the month :");
    scanf("%i", &(pointerToDynamicArray->Month_Of_Birth));
    printf("%s", "Enter the year : ");
    scanf("%i", &(pointerToDynamicArray->Year_Of_Birth));
    bool validity_DateOfBirth = false;
    while (!validity_DateOfBirth)
    {
        if ((pointerToDynamicArray->Day_Of_Birth > 0 && pointerToDynamicArray->Day_Of_Birth <= 31) && ((pointerToDynamicArray->Month_Of_Birth) > 0
            && (pointerToDynamicArray->Month_Of_Birth) <=12) && ((pointerToDynamicArray->Year_Of_Birth) >= 0))
                validity_DateOfBirth = true;
        else
            {
                puts("Wrong date of birth!");
                printf("%s","Enter the day : ");
                scanf("%i", &(pointerToDynamicArray->Day_Of_Birth));
                printf("%s", "Enter the month :");
                scanf("%i", &(pointerToDynamicArray->Month_Of_Birth));
                printf("%s", "Enter the year : ");
                scanf("%i", &(pointerToDynamicArray->Year_Of_Birth));
            }
    }
    printf("\n\n");
}

void print_dynamic_array_elements(DynamicArray* pointerToDynamicArray)
{
    printf("The number of elements of the array is : %i", n);
    printf("\n");
    for (int j = 0; j < n; ++j)
    {
        printf("The name of student %i is : %s",j + 1, (pointerToDynamicArray + j)->Student_Name);
        printf("The ID of this student is : %i\n", (pointerToDynamicArray + j)->Student_ID);
        printf("The score of last year of this student is : %i\n", (pointerToDynamicArray + j)->Score_Of_Last_Year);
        printf("The date of birth of this student is : %i.%i.%i\n" , (pointerToDynamicArray + j)->Day_Of_Birth, (pointerToDynamicArray + j)->Month_Of_Birth
               , (pointerToDynamicArray + j)->Year_Of_Birth);
        printf("\n\n");
    }
}

void Insert_in_the_end_of_dynamic_array(DynamicArray* pointerToDynamicArray, DynamicArray* pointerToDynamicElement)
{
    *(pointerToDynamicArray + n) = *pointerToDynamicElement;
    ++n;
}

void Insert_in_the_beginning_of_dynamic_array(DynamicArray* pointerToDynamicArray, DynamicArray* pointerToDynamicElement)
{
    int h = n;
    for(int i = h; i >= 1; --i)
    {
        *(pointerToDynamicArray + i) = *(pointerToDynamicArray + i - 1);
    }
    *(pointerToDynamicArray) = *(pointerToDynamicElement);
    n++;
}

void Insert_in_the_middle_of_dynamic_array(DynamicArray* pointerToDynamicArray, int position, DynamicArray* pointerToDynamicElement)
{

    int h = n;
    for(int i = h; i >= position + 1; --i)
    {
        *(pointerToDynamicArray + i) = *(pointerToDynamicArray + i - 1);
    }
    *(pointerToDynamicArray + position) = *pointerToDynamicElement;
    n++;
}
