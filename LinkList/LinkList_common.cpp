#if 1

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "LinkList_common.h"
#include "LinkList_sort.h"

LinkNode_t* LinkList_create_node(void) {

	LinkNode_t  *pNewNode = (LinkNode_t*)malloc(sizeof(LinkNode_t));

	printf("What's the Value of new element? ");
	scanf_s("%d", &pNewNode->Value);

	pNewNode->ptrToObject = NULL;
	pNewNode->Next = NULL;

	return pNewNode;
}

void LinkList_add_node(LinkList_t	*pLinkList, LinkNode_t* pNewNode) {

	LinkNode_t **ppListHead = &pLinkList->ListHead;
	LinkNode_t *pCurrentNode = NULL;

	// List is empty
	if (*ppListHead == NULL) {
		*ppListHead = pNewNode;
		// printf("...List was empty \n");
	}
	// else, traverse till last element
	else {
		pCurrentNode = *ppListHead;
		while (pCurrentNode->Next != NULL) {
			pCurrentNode = pCurrentNode->Next;
		}

		pCurrentNode->Next = pNewNode;
		//printf("...Added after %d \n", pCurrentNode->Value);
	}
}

void LinkList_print(LinkList_t *pLinkList) {

	LinkNode_t *pListHead = pLinkList->ListHead;

	printf("LinkList (%u count): ", LinkList_count_nodes(pLinkList));
	if (pListHead == NULL) {
		printf("(empty)");
		return;
	}

	// trverse and print the list
	do {
		printf("%d, ", (pListHead)->Value);
		pListHead = pListHead->Next;
	} while (pListHead != NULL);

	printf("\n");
}

unsigned int LinkList_count_nodes(LinkList_t *pLinkList) {

	unsigned int	count = 0;
	LinkNode_t      *pListHead = pLinkList->ListHead;
	LinkNode_t		*pCurrentNode = NULL;

	if (pListHead != NULL) {
		pCurrentNode = pListHead;
		count = 1;

		while (pCurrentNode->Next != NULL) {
			pCurrentNode = pCurrentNode->Next;
			count++;
		}
	}

//	printf("No. of elements in link list: %u \n", count);
	return count;
}

void LinkList_add_sort(LinkList_t *pLinkList, LinkNode_t* pNewNode) {

	LinkNode_t		**pListHead = &pLinkList->ListHead;
	LinkNode_t		*pCurrentNode = NULL;

	// List is empty
	if (*pListHead == NULL) {
		*pListHead = pNewNode;
		printf("...List was empty \n");
	}
	else {
		// check if new element needs to be added at head
		if (pNewNode->Value < (*pListHead)->Value) {
			printf("...Added before %d \n", (*pListHead)->Value);

			pNewNode->Next = *pListHead;
			*pListHead = pNewNode;
		}
		// otherwise, we need to traverse the list to find position
		else {
			pCurrentNode = *pListHead;
			while (1) {
				if (pCurrentNode->Next == NULL) {		// Current node is last node in list
					printf("...Added after %d \n", pCurrentNode->Value);

					pCurrentNode->Next = pNewNode;
					break;
				}
				else {									// Current node is not Last node in list
					if (pNewNode->Value < pCurrentNode->Next->Value) {
						pNewNode->Next = pCurrentNode->Next;
						pCurrentNode->Next = pNewNode;

						printf("...Added after %d and before %d \n", pCurrentNode->Value, pNewNode->Next->Value);
						break;
					}
				}
				pCurrentNode = pCurrentNode->Next;
			} // end of traverse loop
		}
	}
}

// Inputs are pointer to Link List and pointer to node previous to the node targeted for removal

LinkNode_t* LinkList_remove_node(LinkList_t *pLinkList, LinkNode_t *pPrevNode) {

	LinkNode_t **ppListHead = &pLinkList->ListHead;
	LinkNode_t *pRemoveNode;

	// nothing to remove if list is empty
	if (*ppListHead == NULL) {				// || ((*ppListHead)->Next == NULL) || (count < 2)) {
		printf("...Nothing to remove \n");
		return NULL;
	}

	if (pPrevNode == NULL) {				// check if 1st node need to be removed...
		pRemoveNode = *ppListHead;
		*ppListHead = pRemoveNode->Next;	// It could be a node or NULL
	}
	else if (pPrevNode->Next == NULL) {		// check current node is last and there is no next node to be removed
		pRemoveNode = NULL;
	}
	else {									// normal case...
		pRemoveNode = pPrevNode->Next;
		pPrevNode->Next = pRemoveNode->Next;	// It could be a node or NULL
	}

	// Making it a standalone node
	if (pRemoveNode)
		pRemoveNode->Next = NULL;

	return pRemoveNode;
}

#endif