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
void Fibonacci(int n , Stack S);

int main()
{
	int n;
	Stack S;
	ElementType X;
	Position P;
	Makenull_Stack(S);
	//doiso(S);
	cout << "Vui long nhap gia tri n tu ban phim : ";
	cin >> n;
	cout << " Day so fibonacci la : ";
	Fibonacci(n , S);
	P = S->Next;
	while( P != NULL ){
		cout << P->Element <<" ";
		P = P->Next;
	}
	getch();
	return 1;
}

// In ra day fibonacci : 
void Fibonacci(int n , Stack S){
	Stack tmp;
	Makenull_Stack(tmp);
	int a = 1;
	Push(a , tmp);
	int b = 2;
	Push( b , tmp);
	int c = a + b;
	Push( c , tmp);
	for( int i = 4 ; i <= n ; i++){
		a = b;
		b = c;
		c = a + b;
		Push( c , tmp);
	}
	Position P = tmp->Next;
	while(P != NULL){
		Push(P->Element , S);
		P = P->Next;
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



