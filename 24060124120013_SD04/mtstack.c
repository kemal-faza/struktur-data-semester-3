/* Program   : mtstack.c (tester) */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza */
/* Tanggal   : 24-09-2025 */
/***********************************/

#include <stdio.h>
#include "tstack.h"

int main(void)
{
	Tstack S;
	int i;

	createStack(&S);
	char x[20] = "malam";
	printf(isPalindrom(x) ? "malam is palindrom" : "malam is not palindrom");
	printf("\n");
	pushN(&S, 3);
	printStack(S);

	// printf("=== Test createStack & isEmpty ===\n");
	// createStack(&S);
	// printStack(S);
	// printf("isEmptyStack = %s\n\n", b2s(isEmptyStack(S)));

	// printf("=== Test push ===\n");
	// push(&S, 'A');
	// push(&S, 'B');
	// push(&S, 'C');
	// printStack(S);
	// printf("viewStack: ");
	// viewStack(S);
	// printf("isFullStack = %s, terisi = %d\n\n", b2s(isFullStack(S)), countFilled(S));

	// printf("=== Test pop ===\n");
	// pop(&S, &x);
	// printf("pop -> %c\n", x);
	// pop(&S, &x);
	// printf("pop -> %c\n", x);
	// pop(&S, &x);
	// printf("pop -> %c\n", x);
	// pop(&S, &x);
	// printf("pop (underflow) -> %c\n", x);
	// printStack(S);
	// printf("isEmptyStack = %s\n\n", b2s(isEmptyStack(S)));

	// printf("=== Test overflow (push > capacity) ===\n");
	// createStack(&S);
	// for (i = 0; i < 11; i++)
	// {
	// 	char c = (char)('0' + (i % 10));
	// 	push(&S, c);
	// }
	// printStack(S);
	// printf("viewStack: ");
	// viewStack(S);
	// printf("isFullStack = %s, terisi = %d\n\n", b2s(isFullStack(S)), countFilled(S));

	return 0;
}
