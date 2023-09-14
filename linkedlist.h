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

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

struct ListNode {
   int data;
   struct ListNode* next;
};

struct ListNode* LinkedList_Insert(struct ListNode* head, int data);

struct ListNode* LinkedList_InsertAtIndex(struct ListNode* head, int index, int data);

struct ListNode* LinkedList_Delete(struct ListNode* head, int index);

struct ListNode* LinkedList_DeleteList(struct ListNode* head);

void LinkedList_DisplayList(struct ListNode* head);

int LinkedList_Length(struct ListNode* head);

void LinkedList_GetElementAt(struct ListNode* head, int index);

void LinkedList_FindElement(struct ListNode* head, int data);

struct ListNode* LinkedList_ReverseList(struct ListNode* head);

struct ListNode* LinkedList_SwapElement(struct ListNode* head, int index1, int index2);

struct ListNode* LinkedList_Sort(struct ListNode* head);

#endif
