/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:56:54 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/16 20:23:02 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

/*linked list를 만든다*/
LinkedList*	createLinkedList()
{
	LinkedList	*pList;

	pList = (LinkedList *)calloc(1, sizeof(LinkedList));
	if (!pList)
		return (FALSE);
	return (pList);
}

/*linked list의 특정 위치에 node를 추가한다.*/
int addLLElement(LinkedList* pList, int position, ListNode element)  
{
	ListNode* pNode;
	ListNode* pNewNode;

	if (!pList || !(position >= 0 && position <= pList->currentElementCount))
		return (FALSE);
	
	pNewNode = (ListNode*)malloc(sizeof(ListNode));
	if (!pNewNode)
		return (FALSE);
	*pNewNode = element;
	pNewNode->pLink = NULL;
	if (position == 0) {
		// if (pList->currentElementCount == 0) {
		// 	pList->headerNode.pLink = pNewNode;
		// } else {
			pNewNode->pLink = pList->headerNode.pLink;
			pList->headerNode.pLink = pNewNode;
		// }
	} else {
		pNode = getLLElement(pList, position-1);
		pNewNode->pLink = pNode->pLink;
		pNode->pLink = pNewNode;
	}
	pList->currentElementCount++;
	return (TRUE);
}

/*linked list의 특정 위치에 있는 node를 제거한다.*/
int removeLLElement(LinkedList *pList, int position)
{
	ListNode	*pDelNode;
	ListNode	*pNode;

	if (!pList || !(position >= 0 && position <= pList->currentElementCount))
		return (FALSE);
	if (position == 0) {
		pDelNode = pList->headerNode.pLink;
		pList->headerNode.pLink = pDelNode->pLink;
	} else {
		pNode = getLLElement(pList, position - 1);
		pDelNode = pNode->pLink;
		pNode->pLink = pDelNode->pLink;
	}
	free(pDelNode);
	pDelNode = NULL;
	pList->currentElementCount--;
	return (TRUE);
}

/*linked list의 특정 위치에 있는 node값 반환한다.*/
ListNode*	getLLElement(LinkedList *pList, int position)
{
	ListNode	*pNode;

	if (!pList || !(position >= 0 && position <= pList->currentElementCount))
		return (FALSE);
	pNode = pList->headerNode.pLink;
	while (position--)
		pNode = pNode->pLink;
	return (pNode);
}

/*linked list를 비운다.*/
void clearLinkedList(LinkedList *pList)
{
	ListNode	*pDelNode;
	ListNode	*pNode;

	if (!pList || pList->currentElementCount == 0)
		return ;
	pNode = pList->headerNode.pLink;
	while (pNode) {
		pNode = pDelNode->pLink;
		free(pDelNode);
		pDelNode = pNode;
	}
	pList->headerNode.pLink = NULL;
	pList->currentElementCount = 0;
}

/*linked list의 길이를 반환한다.*/
int	getLinkedListLength(LinkedList *pList)
{
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}

/*linked list를 삭제한다.*/
void	deleteLinkedList(LinkedList *pList)
{
	if (!pList)
		return ;
	clearLinkedList(pList);
	free(pList);
	pList = NULL;
}


int	main(void)
{
	LinkedList *pList;
	ListNode 	*pNode;
	ListNode 	element;
	int 	 	i;
	int 	 	position;
	ListNode 	a;
	ListNode 	b;
	ListNode 	c;
	ListNode 	d;
	ListNode 	e;

	pList = NULL;

	a.data = 5;
	a.pLink = NULL;

	b.data = 1;
	b.pLink = NULL;

	c.data = 3;
	c.pLink = NULL;

	d.data = 4;
	d.pLink = NULL;

	e.data = 19;
	e.pLink = NULL;
	
	//1. CREATE - 성공
	pList = createLinkedList();
	// if (pList)
	// 	printf("Create Linked List : Success\n");
	// else
	// 	printf("Create Linked List : Failed\n");
	
	//2. ADD
	position = 0;
	// element.data = 3;
	addLLElement(pList, 0, a); // 5 
	addLLElement(pList, 1, b); // 1
	addLLElement(pList, 2, c); // 3
	addLLElement(pList, 3, d); // 4
	addLLElement(pList, 1, e); // 19
	// if (addLLElement(pList, 1, b))
	// 	printf("Add : Success\n");
	// else 
	// 	printf("ADD : Failed\n");
	i = 0;
	pNode = &(pList->headerNode);
	while (pNode) // 리스트 노드 순회
	{
		printf("[%d]: %d\n", i++, pNode->data);
		pNode = pNode->pLink;
	}
	printf("\n");

	//3. REMOVE
	// if(removeLLElement(pList, position))
	// 	printf("Remove : Success\n");
	// else
	// 	printf("Remove : Failes\n");
	// i = 0;
	// pNode = &(pList->headerNode);
	// while (pNode) // 리스트 노드 순회
	// {
	// 	printf("[%d]: %d\n", i++, pNode->data);
	// 	pNode = pNode->pLink;
	// }
	// printf("\n");

	//4. GET_E
	// pNode = getLLElement(pList, position);
	// if (pNode)
	// 	printf("Get : [%d]: %d\n", position, pNode->data);
	// else
	// 	printf("Get : Failed\n");

	//5. GET_L
	// printf("Length: %d\n", getLinkedListLength(pList));

	//6. CLEAR
	// clearLinkedList(pList);

	//7. DEL
	// deleteLinkedList(pList);
	// pList = NULL;

	//PRINT
	// i = 0;
	// pNode = &(pList->headerNode);
	// while (pNode) // 리스트 노드 순회
	// {
	// 	printf("[%d]: %d\n", i++, pNode->data);
	// 	pNode = pNode->pLink;
	// }
	// printf("\n");

	return 0;
}
