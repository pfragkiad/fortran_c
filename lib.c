//gcc -c lib.c   -> lib.o

//nm lib.o
//0000000000000000 T f

//objdump -t lib.o
/*
lib.o:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 lib.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 g     F .text  0000000000000018 f
*/

/*
readelf -s lib.o

Symbol table '.symtab' contains 4 entries:
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS lib.c
     2: 0000000000000000     0 SECTION LOCAL  DEFAULT    1 .text
     3: 0000000000000000    24 FUNC    GLOBAL DEFAULT    1 f
*/

int f(int a, int b)
{
    return a+b;
}