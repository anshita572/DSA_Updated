//With a union, all members share the same memory.The size of a union variable will always be the size of its largest element
#include <stdio.h>
#include <stdlib.h>
int main()
{
union {
short s; //short int is of 2 bytes
char c[sizeof(short)]; //char c[2] => 2 bytes
}un; //union variable
//size of un = 2 bytes
// The elements of a union occupy
// a common "piece" of memory.
// So un.s and un.c[] refer to same
// memory
un.s = 0x0102; //hexadecimal
if (sizeof(short) == 2)
{
if (un.c[0] == 1 && un.c[1] == 2)
printf("big-endian\n");//If c={0x01, 0x02}→ Big Endian
else if (un.c[0] == 2 && un.c[1] == 1)
printf("little-endian\n");//If c={0x02, 0x01}→ Little Endian
else printf("unknown\n");
}
else {
printf("sizeof(short) = %d\n",
sizeof(short));
}
exit(0);
}