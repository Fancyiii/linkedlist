/** @addtogroup [C] [C: C Programming Exercise]
* [C Programming Exerceise]
* @{
*/

/*
 * Copyright (C) 2023 Creative Technology Ltd.
 * All Rights Reserved.
 *
 * This software and its associated documentation may contain some
 * proprietary, confidential and trade secret information of
 * Creative Technology Ltd. and except as provided by written agreement with
 * Creative Technology Ltd.
 *
 * a)   no part may be disclosed, distributed, reproduced, transmitted,
 *      transcribed, stored in a retrieval system, adapted or translated
 *      in any form or by any means electronic, mechanical, magnetic,
 *      optical, chemical, manual or otherwise,
 *
 *      and
 *
 * b)   the recipient is not entitled to discover through reverse
 *      engineering or reverse compiling or other such techniques or
 *      processes the trade secrets contained therein or in the
 *      documentation.
 */

#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"

// struct ListNode* head = NULL;
// struct ListNode* pCurrent = NULL;



/**
* LinkedList_Insert a ListNode with value of data to the end of the list.
* @pre function expect input of the data to be LinkedList_Inserted
* @param data linked list data to be LinkedList_Inserted at the end of the list
* @return 0
*/
struct ListNode* LinkedList_Insert(struct ListNode* head, int data){        /* a */

   struct ListNode* pNewListNode = (struct ListNode*)malloc(sizeof(struct ListNode));
   if (pNewListNode == NULL) {
      printf("Memory allocation failed.\n");
      exit(1);
    }

   pNewListNode->data = data;
   pNewListNode->next = NULL;

   if (head == NULL) {
      head = pNewListNode;
   } else {
      struct ListNode* pCurrent = head;
      while (pCurrent->next != NULL) {
         pCurrent = pCurrent->next;
      }
      pCurrent->next = pNewListNode;
   }

   return head;
}

/**
* LinkedList_Insert a ListNode with value of data in the specified index.
* @pre function expect input of the data and the index to be LinkedList_Inserted
* @param data linked list data to be LinkedList_Inserted 
* @param index linked list index to be LinkedList_Inserted at
* @return 0
*/
struct ListNode* LinkedList_InsertAtIndex(struct ListNode* head, int index, int data){  /* b */
   struct ListNode* pNewListNode = (struct ListNode*)malloc(sizeof(struct ListNode));
   pNewListNode->data = data;
   pNewListNode->next = NULL;


   /* Find the ListNode just before the index */
   int indexCnt = 0;
   struct ListNode* pCurrent = head;
   while (indexCnt < index - 1) {
      indexCnt = indexCnt + 1;
      pCurrent = pCurrent->next;
   }

   if (0 == index) {          /* LinkedList_Insert at head */
      pNewListNode->next = head;
      head = pNewListNode;
   } else {                   /* LinkedList_Insert at not head ListNode */
      struct ListNode* pTemp;
      pTemp = pCurrent->next;
      pCurrent->next = pNewListNode;
      pNewListNode->next = pTemp;
   }

   printf("LinkedList_Inserted %d at index %d.\n", data, index);

   return head;

}

/**
* LinkedList_Delete the ListNode at the specified index.
* @pre function expect input of the index to be LinkedList_Deleted
* @param index linked list index to be LinkedList_Deleted at
* @return 0
*/
struct ListNode* LinkedList_Delete(struct ListNode* head, int index){       /* c */

   if (head == NULL) {                  /* Empty List */
      printf("List is empty.\n");
      return head;
   }

   if (0 == index) {                    /* delete head */
      struct ListNode* pTemp;
      pTemp = head;
      head = head->next;
      free(pTemp);
   }

   if (0 > index) {                     /* Index < 0 is Invalid */
      printf("Invalid Index\n");
      return head;
   }

   int indexCnt = 0;
   struct ListNode* pCurrent = head;
   while (indexCnt < index - 1) {       /* Move to the ListNode before the one need to be deleted */
      indexCnt = indexCnt + 1;
      pCurrent = pCurrent->next;
   }

   struct ListNode* pTemp;                   /* Delete the ListNode at Index, link the ListNode besides */
   pTemp = pCurrent->next;
   pCurrent->next = pTemp->next;

   printf("Deleted %d at index %d.\n", pTemp->data, index);
   free(pTemp);

   return head;
}

/**
* LinkedList_Delete the entire lineked list
* @return 0
*/
struct ListNode* LinkedList_DeleteList(struct ListNode* head){            /* d */
   struct ListNode* pTemp;
   while (head != NULL) {         /* LinkedList_Delete the head ListNode until it is empty */
      pTemp = head;
      head = head->next;
      free(pTemp);
   }

   printf("The linked list is cleared.\n");

   return head;
}

/**
* Display and print the pCurrent elements in the linked list.
* @return 0
*/
void LinkedList_DisplayList(struct ListNode* head){           /* e */
   struct ListNode* pCurrent = head;
   if (head == NULL) {
      printf("Empty List.\n");
      return;
   }
   printf("Current list:");
   while (pCurrent != NULL) {
      printf(" %d", pCurrent->data);
      pCurrent = pCurrent->next;
   }
   printf("\n");
}

/**
* Get the number of elements / ListNodes in the list.
* @return the number of elements / ListNodes in the list
*/
int LinkedList_Length(struct ListNode* head){                 /* f */
   int len = 0;
   struct ListNode* pCurrent = head;
   while (pCurrent != NULL) {
      pCurrent = pCurrent->next;
      len = len + 1;
   }

   return len;
}

/**
* Get the element data in the specified index.
* @pre function expect input of the index
* @param index The index of the data for the output
* @return 0
*/
void LinkedList_GetElementAt(struct ListNode* head, int index){ /* g */

   if (0 > index) {                    /* Invalid index if it is less than 0 */
      printf("Invalid Index.\n");
   }

   int indexCnt = 0;        // Store the index of current node
   struct ListNode* pCurrent = head;
   while (indexCnt < index) {
      /* go through the list and stop at the input index */
      if (pCurrent == NULL) {
         printf("Index out of range.\n");   /* Index out of range if it exceeds the max of the list ListNode*/
         return;
      }
      pCurrent = pCurrent->next;
      indexCnt = indexCnt + 1;
   }

   printf("The element data at index %d is : %d.\n", index, pCurrent->data);

}

/**
* Find the index of the specified data from the list.
* @pre function expect input of data
* @param data The specified data for the output index
* @return 0
*/
void LinkedList_FindElement(struct ListNode* head, int data){   /* h */
   struct ListNode* pCurrent = head;
   int found = 0;          // Check if found the data in the list node
   int indexCnt = 0;       // Store the index of current node
   while (pCurrent != NULL) {
      /* go throught the list from head to check if it can find the data in a node */
      if(pCurrent->data == data) {
         printf("The element data %d is at index %d.\n", data, indexCnt);
         found = 1;
      }
      pCurrent = pCurrent->next;
      indexCnt = indexCnt + 1;
   }
   if (0 == found){
      printf("The element %d is not found in the list.\n", data);
   }
}

/**
* Reverse the pCurrent linked list.
* @return 0
*/
struct ListNode* LinkedList_ReverseList(struct ListNode* head){           /* i */
   struct ListNode* pPrev = NULL;       // pointer points to the previous node
   struct ListNode* pCurrent = head;   // pointer points to current node
   struct ListNode* pNext = NULL;       // pointer points to the next node

   while (pCurrent != NULL) {
      /* reverse the list */
      pNext = pCurrent->next;   /* let the next be the current->next */
      pCurrent->next = pPrev;   /* reverse the link of current node */
      pPrev = pCurrent;         /* move prev and current to the next node */
      pCurrent = pNext;
   }

   head = pPrev;               /* when finished reversing the link, let head be the last node */

   printf("The list is reversed.\n");
   LinkedList_DisplayList(head);

   return head;
}

/**
* Swap the element at index1 and index2.
* @pre function expect input of two integers
* @param index1 index of the ListNode to be swapped with index2
* @param index2 index of the ListNode to be swapped with index1
* @return 0
*/
struct ListNode* LinkedList_SwapElement(struct ListNode* head, int index1, int index2){            /* j */

   /* Find the ListNode in index1 */

   struct ListNode* pPre1 = NULL;
   struct ListNode* pCurrent1 = head;

   int indexCnt1 = 0;

   while (pCurrent1 != NULL && indexCnt1 < index1) {
      pPre1 = pCurrent1;
      pCurrent1 = pCurrent1->next;
      indexCnt1 = indexCnt1 + 1;
   }

   /* Find the ListNode in Index2 */

   struct ListNode* pPre2 = NULL;
   struct ListNode* pCurrent2 = head;

   int indexCnt2 = 0;

   while (pCurrent2 != NULL && indexCnt2 < index2) {
      pPre2 = pCurrent2;
      pCurrent2 = pCurrent2->next;
      indexCnt2 = indexCnt2 + 1;
   }

   /* Swap the the link of previous to current ListNode*/

   if (pPre1 == NULL) {
      head = pCurrent2;
   } else {
      pPre1->next = pCurrent2;
   }

   if (pPre2 == NULL) {
      head = pCurrent1;
   } else {
      pPre2->next = pCurrent1;
   }

   /* Swap the the link of current to current->next ListNode*/

   struct ListNode* pTemp = pCurrent1->next;
   pCurrent1->next = pCurrent2->next;
   pCurrent2->next = pTemp;

   printf("Swapped element at index %d and %d.\n", indexCnt1, indexCnt2);
   LinkedList_DisplayList(head);

   return head;

}

/**
* LinkedList_Sort the pCurrent linked list in ascending order.
* @return 0
*/
struct ListNode* LinkedList_Sort(struct ListNode* head){                  /* k */
   int len = LinkedList_Length(head);
   struct ListNode* pNextListNode;

   for (int i = 0; i < len; i++) {
      struct ListNode* pCurrent = head;
      for (int j = 0; j < len - i - 1; j++) {
         pNextListNode = pCurrent->next;
         if (pCurrent->data > pNextListNode->data) {
            /* Swap the data of pCurrent and pNextListNode */
            int temp = pCurrent->data;
            pCurrent->data = pNextListNode->data;
            pNextListNode->data = temp;
         }
         pCurrent = pCurrent->next;
      }
   }

   printf("The list is sorted.\n");
   LinkedList_DisplayList(head);

   return head;
}



