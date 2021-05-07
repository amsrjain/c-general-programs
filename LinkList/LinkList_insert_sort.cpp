#if 1

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "LinkList_common.h"

void LinkList_insert_sort(LinkList_t *pLinkList) {

	LinkNode_t **ppListHead = &pLinkList->ListHead;
	LinkNode_t *pRemoveNode, *pCurrentNode;

	unsigned int	pass = 0;
	unsigned int	count = LinkList_count_nodes(pLinkList);

	// nothing to sort if List is empty or only one element
	if ((*ppListHead == NULL) || ((*ppListHead)->Next == NULL) || (count < 2)) {
		printf("...Nothing to sort \n");
		return;
	}

	pCurrentNode = *ppListHead;		// This cannot be Null as the condition is checked above

	do {
		// remove the node next to current node and insert in sorted order
		pRemoveNode = LinkList_remove_node(pLinkList, pCurrentNode);

		if(pRemoveNode != NULL)
			LinkList_add_sort(pLinkList, pRemoveNode);

		LinkList_print(pLinkList);

		// move to next if the next node didn't change
		if (pCurrentNode->Next == pRemoveNode)
			pCurrentNode = pCurrentNode->Next;

		pass++;
	} while (pCurrentNode != NULL);

	printf("\ Insertion Sort completed in %u Pass for %u elements \n", pass, count);
	return;
}
#endif