#include <stdio.h>
#include <stdlib.h>

                      
struct listNode {                                      
   int ID; 
   int math, com;
   float average;
   struct listNode *nextPtr;
}; 

typedef struct listNode ListNode; 
typedef ListNode *ListNodePtr; 

void insert(ListNodePtr *sPtr, int id, int math, int computer,float average);
char delete(ListNodePtr *sPtr, int value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

int main(void)
{ 
   ListNodePtr startPtr = NULL; 
   int item,math, computer;
   float aver;

   instructions();
   printf("%s", "? ");
   unsigned int choice;
   scanf("%u", &choice);

   
   while (choice != 3) { 

      switch (choice) { 
         case 1:
            printf("%s", "�п�J�Ǹ�: ");
            scanf("\n%d", &item);
            printf("%s", "�п�J�ƾ�: ");
            scanf("\n%d", &math);
            printf("%s", "�п�J�q��: ");
            scanf("\n%d", &computer);
            aver=(math+computer)/2.0;
            insert(&startPtr, item,math,computer,aver);
            printList(startPtr);
            break;
         case 2: 
            if (!isEmpty(startPtr)) { 
               printf("%s", "��J�Ǹ�: ");
               scanf("\n%d", &item);

               if (delete(&startPtr, item)) { 
                  printf("%d deleted.\n", item);
                  printList(startPtr);
               } 
               else {
                  printf("%d not found.\n\n", item);
               } 
            } 
            else {
               puts("List is empty.\n");
            }    

            break;
         default:
            puts("Invalid choice.\n");
            instructions();
            break;
      }
      printf("%s", "? ");
      scanf("%u", &choice);
   } 

   puts("End of run.");
} 

void instructions(void)
{ 
   puts("Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end.");
} 

void insert(ListNodePtr *sPtr, int id, int math, int computer,float average)
{ 
   ListNodePtr newPtr = malloc(sizeof(ListNode));

   if (newPtr != NULL) { 
      newPtr->ID = id; 
      newPtr->math = math; 
      newPtr->com = computer; 
      newPtr->average=average;
      newPtr->nextPtr = NULL; 

      ListNodePtr previousPtr = NULL;
      ListNodePtr currentPtr = *sPtr;

      
      while (currentPtr != NULL && id > currentPtr->ID) {
         previousPtr = currentPtr; 
         currentPtr = currentPtr->nextPtr;
      }                                          

     if (previousPtr == NULL) { 
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
      } 
      else {
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      } 
   } 
   else {
      printf("%c not inserted. No memory available.\n", id);
   } 
} 

char delete(ListNodePtr *sPtr, int value)
{ 
   if (value == (*sPtr)->ID) { 
      ListNodePtr tempPtr = *sPtr; 
      *sPtr = (*sPtr)->nextPtr;
      free(tempPtr);
      return value;
   } 
   else { 
      ListNodePtr previousPtr = *sPtr;
      ListNodePtr currentPtr = (*sPtr)->nextPtr;

      while (currentPtr != NULL && currentPtr->ID != value) { 
         previousPtr = currentPtr;
         currentPtr = currentPtr->nextPtr; 
      } 

      if (currentPtr != NULL) { 
         ListNodePtr tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free(tempPtr);
         return value;
      } 
   } 

   return '\0';
} 

int isEmpty(ListNodePtr sPtr)
{ 
   return sPtr == NULL;
} 


void printList(ListNodePtr currentPtr)
{ 
   if (isEmpty(currentPtr)) {
      puts("List is empty.\n");
   } 
   else { 
      puts("�쵲��C���e��:");

      while (currentPtr != NULL) { 
         printf("%d %d %d %.1f--> ", currentPtr->ID,currentPtr->math,currentPtr->com,currentPtr->average);
         currentPtr = currentPtr->nextPtr;   
      } 

      puts("NULL\n");
   } 
} 
