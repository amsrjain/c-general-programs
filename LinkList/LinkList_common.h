#pragma once

typedef struct tagLinkNode {
	int					Value;
	void*				ptrToObject;
	struct tagLinkNode* Next;
} LinkNode_t;

typedef struct tagLinkList {
	LinkNode_t*		ListHead;
	LinkNode_t*		ListTail;
} LinkList_t;

// function prototypes
LinkNode_t* LinkList_create_node (void);
void LinkList_add_node (LinkList_t* pLinkList, LinkNode_t* pNewNode);
LinkNode_t* LinkList_remove_node(LinkList_t* pLinkList, LinkNode_t* pCurrentNode);

void LinkList_print (LinkList_t* pLinkList);
unsigned int LinkList_count_nodes (LinkList_t* pLinkList);

void LinkList_add_sort(LinkList_t* pLinkList, LinkNode_t* pNewNode);

// test support
void linklist_interactive(void);
