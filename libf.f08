
!gfortran -c libf.f08 -> libf.o

!cliff@DESKTOP-TBDVVBV:~/fortran_c$ nm libf.o
!0000000000000000 T forf_

!objdump -t libf.o
! libf.o:     file format elf64-x86-64

! SYMBOL TABLE:
! 0000000000000000 l    df *ABS*  0000000000000000 libf.f08
! 0000000000000000 l    d  .text  0000000000000000 .text
! 0000000000000000 g     F .text  000000000000002e forf_

! cliff@DESKTOP-TBDVVBV:~/fortran_c$ readelf -s libf.o
! Symbol table '.symtab' contains 4 entries:
!    Num:    Value          Size Type    Bind   Vis      Ndx Name
!      0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND
!      1: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS libf.f08
!      2: 0000000000000000     0 SECTION LOCAL  DEFAULT    1 .text
!      3: 0000000000000000    46 FUNC    GLOBAL DEFAULT    1 forf_

pure function forf(a, b)
   integer(4),intent(in) :: a,b
   forf =  a+b
end function
