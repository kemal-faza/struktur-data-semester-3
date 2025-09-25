/* Program   : mbrowser.c */
/* Deskripsi : file DRIVER browser modul stack karakter */
/* NIM/Nama  : 24060124120013/Muhamad Kemal Faza */
/* Tanggal   : 24-09-2025 */
/***********************************/

#include <stdio.h>
#include "tstack.h"
/* include tstack+boolean */

void addLink(Tstack *Current, Tstack *Backward)
{
	// kamus lokal
	char input;

	// algoritma
	if (!isFullStack(*Current))
	{
		createStack(&(*Backward));
		printf("Masukkan link karakter: ");
		scanf(" %c", &input);
		push(&(*Current), input);
	}
}

void backwardBrowser(Tstack *Current, Tstack *Backward, char *link)
{
	// kamus lokal

	// algoritma
	if (!isEmptyStack(*Current))
	{

		pop(&(*Current), &(*link));
		push(&(*Backward), *link);
	}
	else
	{
		printf("Tidak ada link untuk kembali.\n");
	}
}

void forwardBrowser(Tstack *Current, Tstack *Backward, char *link)
{
	// kamus lokal

	// algoritma
	if (!isEmptyStack(*Backward))
	{
		pop(&(*Backward), link);
		push(&(*Current), *link);
	}
	else
	{
		printf("Tidak ada link untuk maju.\n");
	}
}

int main()
{
	/* kamus main */
	Tstack Backward, Current;
	char input, link;

	/* algoritma */
	createStack(&Backward);
	createStack(&Current);

	input = '1';
	while (input != '4')
	{
		printf("Menu Browser:\n");
		printf("1. Add Link\n");
		printf("2. Backward\n");
		printf("3. Forward\n");
		printf("4. Exit\n");
		printf("Pilihan: ");
		scanf(" %c", &input);

		switch (input)
		{
		case '1':
			addLink(&Current, &Backward);
			printf("Current: ");
			printStack(Current);
			printf("Backward: ");
			printStack(Backward);
			break;
		case '2':
			backwardBrowser(&Current, &Backward, &link);
			printf("Current: ");
			printStack(Current);
			printf("Backward: ");
			printStack(Backward);
			break;
		case '3':

			forwardBrowser(&Current, &Backward, &link);
			printf("Current: ");
			printStack(Current);
			printf("Backward: ");
			printStack(Backward);
			break;
		case '4':
			printf("Exiting browser.\n");
			break;
		default:
			printf("Pilihan tidak valid. Silakan coba lagi.\n");
			break;
		}
	}

	return 0;
}
