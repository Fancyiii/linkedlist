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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "linkedlist.h"  // header file for linked list functions

#define True  (1)
#define False (0)

/**
* Perform error check after get the first instruction
* @param ptr   the input string after the first instruction
* @param data  store the data
* @param index store the index
* @param n     number of integers needed for the instruction
* @return 0
*/
int ErrorCheck(char* ptr, int* data, int* index, int n) {
   char deLim[] = " ";
   ptr = strtok(NULL, deLim);

   if (ptr == NULL) {
       printf("Please input an integer followed by the instruction.\n");
       return False;
   }

   /* Check if the second input argument is an integer */
   if (sscanf(ptr, "%d", data) != 1) {
       printf("Please input a valid integer.\n");
       return False;
   }

   if (sscanf(ptr, "%d", index) != 1) {
       printf("Please input a valid integer.\n");
       return False;
   }

   ptr = strtok(NULL, deLim);
   if ( ptr != NULL) {
      printf("Please input correct number of argument.\n");
      return False;
   }
}

int main() {
    struct ListNode* pHead = NULL;
    char text[100];    // read instruction lines
    char deLim[] = " "; // delimiter

    char instruction[100];
    int data = 0;
    int index = 0;

    while (1) {
        fgets(text, sizeof(text), stdin); // Read a line of input

        char* ptr = strtok(text, deLim);
        if (ptr == NULL) {
            printf("Invalid input.\n");
            continue;
        }

        strcpy(instruction, ptr);

        /* exit */
        if (strcmp(instruction, "exit") == 0) {
            break;
        }

        if (strcmp(instruction, "a") == 0) {
         #if 0
            ptr = strtok(NULL, deLim);

            if (ptr == NULL) {
                printf("Please input an integer followed by the instruction.\n");
                continue;
            }

            /* Check if the second input argument is an integer */
            if (sscanf(ptr, "%d", &data) != 1) {
                printf("Please input a valid integer.\n");
                continue;
            }

            ptr = strtok(NULL, deLim);
            if ( ptr != NULL) {
               printf("Please input correct number of argument.\n");
               continue;
            }
#endif
            if (ErrorCheck(ptr, &data, &index, 1) == False) continue;
            printf("data and index: %d, %d", data, index);
            pHead = LinkedList_Insert(pHead, data);
        } else if (strcmp(instruction, "b") == 0) {
            // Handle the "b" instruction here
        } else {
            printf("Unknown instruction: %s\n", instruction);
        }
    }

    // Free any allocated memory for the linked list here if needed

    return 0;
}

