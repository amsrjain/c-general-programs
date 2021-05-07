#if 1

#include <stdio.h>
#include <string.h>

#include "LinkList_common.h"
#include "LinkList_sort.h"

void linklist_interactive(void) {

	int					userInput;
	LinkList_t			LinkList;
	LinkNode_t			*pNewNode = NULL;

	LinkList.ListHead = LinkList.ListTail = NULL;

	printf("\n LINK LIST -------------------------- \n");
	LinkList_print(&LinkList);

	while (1) {
		printf("Menu: \n Add new element in sorted (1) \n Add new element unsorted (2) \n Bubble Sort (3) \n Isert Sort (4) \n or Exit (0) ? \n"); 
		scanf_s("%d", &userInput);

		if (userInput == 1) {
			pNewNode = LinkList_create_node();
			LinkList_add_sort(&LinkList, pNewNode);
		} else if (userInput == 2) {
			pNewNode = LinkList_create_node();
			LinkList_add_node(&LinkList, pNewNode);
		} else if (userInput == 3) {
			LinkList_bubble_sort(&LinkList);
		} else if (userInput == 4) {
			LinkList_insert_sort(&LinkList);
		} else if (userInput == 0) {
			break;
		} else {
			printf(" Wrong Input...try again! \n");
		}

		printf("\n");
		LinkList_print(&LinkList);
	}
}

#endif
