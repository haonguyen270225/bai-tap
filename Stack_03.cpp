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
void Tinh_Giai_Thua(int n , Stack S);

int main()
{
	int n;
	Stack S;
	ElementType X;
	Position P;
	Makenull_Stack(S);
	//doiso(S);
	cout << " Nhap gia tri n ban can tinh : ";
	cin >> n;
	Tinh_Giai_Thua(n , S);
	cout << n << "! = " <<  Top(S);
	getch();
	return 1;
}
// Tinh n!
void Tinh_Giai_Thua(int n , Stack S){
	if( n == 0 || n == 1 ){
		Push(1 , S);
		return;
	}
	Push(1 , S);
	for( int i = 2 ; i <= n ; i++ ){
		//Pop(S);
		int k = Top(S) * i;
		Pop(S);
		Push(k , S);
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



