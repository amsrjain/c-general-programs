#if 1

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "LinkList_common.h"

void LinkList_bubble_sort(LinkList_t *pLinkList) {

	LinkNode_t		**ppListHead = &pLinkList->ListHead;
	LinkNode_t		*pCurrentNode = NULL;
	LinkNode_t		*pRunner, *pPrevNode;

	unsigned int	count = LinkList_count_nodes(pLinkList);
	unsigned int	sort_pass = 0, swap_count = 0;

	// nothing to sort if List is empty or only one element
	if ((*ppListHead == NULL) || ((*ppListHead)->Next == NULL) || (count < 2)) {
		printf("...Nothing to sort \n");
		return;
	}

	for (sort_pass = 1; sort_pass < count; sort_pass++) {
		printf("\n sort_pass: %u", sort_pass);

		pCurrentNode = *ppListHead;
		pPrevNode	= NULL;
		pRunner		= NULL;

		for (swap_count = 1; swap_count <= (count - sort_pass); swap_count++) {
			if (pCurrentNode->Value > pCurrentNode->Next->Value) {
				// swap the nodes
				pRunner				= pCurrentNode->Next;
				pCurrentNode->Next	= pCurrentNode->Next->Next;
				pRunner->Next		= pCurrentNode;

				if (*ppListHead == pCurrentNode) {	// if this was the 1st node
					*ppListHead	= pRunner;
					pPrevNode	= pRunner;
				}
				else {
					pPrevNode->Next	= pRunner;
					pPrevNode		= pRunner;
				}
			}
			else {
				// move pointers to next
				pPrevNode	 = pCurrentNode;
				pCurrentNode = pCurrentNode->Next;

				// check error
				if (pCurrentNode == NULL)
					printf("UNexpected ERROR! sort_pass %u, swap_count %u", sort_pass, swap_count);
			}
		}
		LinkList_print(pLinkList);
	}

	return;
}

#endif
