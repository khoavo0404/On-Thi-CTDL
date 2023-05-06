#include <iostream>
using namespace std;

struct Node {
	int data;
	Node * pNext;	
};
struct SingleList {
	Node *pHead;
	Node *pTail;
};
void Initialize(SingleList &list){
	list.pHead = list.pTail = NULL;
}
Node *CreateList(int d){
	Node * node = new Node;
	if(node == NULL){
		cout <<"Cap phat that bai!";
	}else{
		node -> data = d;
		node -> pNext = NULL;		
	}
	return node;
}
void InsertFirst(SingleList &list, int d){
	Node * node = CreateList(d);
	Node * ptmp = list.pHead;
	if(ptmp == NULL)
		list.pHead = list.pTail = node;
	else{
		node -> pNext = list.pHead;
		list.pHead = node;
	}
}
void PrintList(SingleList list){
	Node * ptmp = list.pHead;
	if(ptmp == NULL){
		cout <<"The list is empty!";
		return;
	}
	while(ptmp!=NULL){
		cout << ptmp -> data << " ";
		ptmp = ptmp -> pNext;
	}
}
int SizeofList(SingleList list){
	Node * ptmp = list.pHead;
	int nSize = 0;
	while (ptmp != NULL){
		ptmp = ptmp -> pNext;
		nSize++;
	}
	return nSize;
}
void InsertLast(SingleList &list, int d){
	Node *node = CreateList(d);
	Node * ptmp = list.pHead;
	if(ptmp == NULL)
		list.pHead = list.pTail = node;
	else{
		list.pTail -> pNext = node;
		list.pTail = node;
	}
}
void InsertIndex(SingleList &list, int pos, int d){
	if(pos < 0 || pos >= SizeofList(list))
		cout <<"Khong tim thay vi tri chen!";
	if(pos == 0)
		InsertFirst(list,d);
	else if(pos == SizeofList(list)-1)
		InsertLast(list,d);
	else{
		Node * node = CreateList(d);
		Node * pIns = list.pHead;
		Node * pPre = NULL;
		int i=0;
		while(pIns != NULL){
			if(i == pos)
				break;
			pPre = pIns;
			pIns = pIns -> pNext;
			i++;
		}
		pPre -> pNext = node;
		node -> pNext = pIns;
	}
}
void RemoveNode(SingleList &list, int d){
	Node * pDel = list.pHead;
	if(pDel == NULL)
		cout <<"The list is empty!";
	else{
		Node * pPre = NULL;
		while(pDel != NULL){
			if(pDel -> data == d)
				break;
			pPre = pDel;
			pDel = pDel -> pNext;
		}
		if(pDel == NULL)
			cout <<"Could not found number!" << d;
		else{
			if(pDel == list.pHead){
				list.pHead = list.pHead -> pNext;
				pDel -> pNext = NULL;
				delete pDel;
				pDel = NULL;
			}
			else if(pDel == list.pTail){
				list.pTail = pPre;
				pPre -> pNext = NULL;
				delete pDel;
				pDel = NULL;
			}
			else
				pPre -> pNext = pDel -> pNext;
				pDel -> pNext = NULL;
				delete pDel;
				pDel = NULL;
		}
	}
}
Node * SearchNode(SingleList list, int d){
	Node * pTmp = list.pHead;
	while(pTmp != NULL){
		if(pTmp -> data == d)
			break;
		pTmp = pTmp -> pNext;
	}
	return pTmp;
}
void SortList(SingleList &list){
	for(Node *pTmp = list.pHead; pTmp != NULL; pTmp=pTmp -> pNext){
		for(Node *pTmp2 = pTmp -> pNext; pTmp2 != NULL; pTmp2 = pTmp2 -> pNext){
			if(pTmp -> data > pTmp2 -> data){
				int tmp = pTmp->data;
				pTmp->data = pTmp2->data;
				pTmp2->data = tmp;
			}
		}
	}
}
int main(){
	SingleList list;
	Initialize(list);
	InsertFirst(list,10);
	InsertFirst(list,9);
	InsertFirst(list,8);
	InsertFirst(list,7);
	InsertLast(list,11);
	InsertIndex(list,1,16);
	cout <<"\nDanh sach lien ket: ";
	PrintList(list);
	
	RemoveNode(list,10);
	cout <<"\nDanh sach sau khi xoa: ";
	PrintList(list);
	
	int d;
	cout<<"\nNhap node can tim: ";
	cin >> d;
	Node * Found = SearchNode(list,d);
	if(Found==NULL)
		cout <<"\nKhong tim thay " << d << " trong danh sach!";
	else
		cout <<"\nTim thay " << d << "trong danh sach!";
	SortList(list);
	cout << "\nSap xep: ";
	PrintList(list);
	return 0;
}