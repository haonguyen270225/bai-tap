#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;


typedef int ElementType;

typedef struct Node *PtrToNode;

typedef PtrToNode Stack;
typedef PtrToNode Position;

struct Node
{
	ElementType Element;
	Position    Next;
};


/* Prototypes */

void Makenull_Stack( Stack &S );
int isEmpty_Stack( Stack S );
void Push( ElementType X, Stack S );
void Pop(Stack S);
ElementType Top(Stack S);
Position Header( Stack S );
//void doiso(Stack S);
void Doi_co_so_k( int k , int n , Stack S);

int main()
{
	int n;
	Stack S;
	ElementType X;
	Position P;
	Makenull_Stack(S);
	//doiso(S);
	cout << " Vui long nhap gia tri n tu ban phim : ";
	cin >> n;
	int  k;
	cout << " Nhap co so ban muon chuyen doi (2 or 8) : ";
	cin >> k;
	Doi_co_so_k(k  , n , S);
	P = S->Next;
	while(P != NULL ){
		cout << P->Element;
		P = P->Next;
	}
	getch();
	return 1;
}

//Doi co so;
void Doi_co_so_k( int k , int n , Stack S){
	if( k == 2 ){
		while(n != 0 ){
			int m = n % 2;
			Push( m , S);
			n /= 2;
		}
	}
	else if( k == 8 ){
		while(n != 0 ){
			int m = n % 8;
			Push(m , S);
			n /= 8;
		}
	}
	else{
		cout <<"Gia tri k khong hop le !";
		return;
	}
}
/*Tao 1 stack rong*/
void  Makenull_Stack( Stack &S )
{
	S = new Node;
	S->Next = NULL;
}

/* Kiem tra stack rong? */
int isEmpty_Stack( Stack S )
{
	return S->Next == NULL;
}

/* Chen phan tu X vao stack  */
void  Push( ElementType X, Stack S)
{
	Position TmpCell, P;
	P = Header(S);

	/*TmpCell =(List)malloc( sizeof( struct Node ) );*/
	TmpCell = new Node;
	if( TmpCell == NULL )
		printf( "Out of space!!!" );

	TmpCell->Element = X;

	TmpCell->Next = P->Next;

	P->Next = TmpCell;
}

/* Lay phan tu dau ra khoi stack */
void	Pop(Stack S )
{
	Position P, TmpCell;

	P = Header(S);
	if( P->Next!=NULL )
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free( TmpCell );
	}
}

/* Tim phan tu header */
Position	Header( Stack S )
{
	return S;
}

/* Tim phan tu dau tien */
ElementType    Top( Stack S )
{
	return S->Next->Element;
}



