program main
   implicit none
   integer(4), external :: forf !forf_ does not work
   integer(4), external :: f2 !

   integer(4) :: x,  y
   x=10
   y=20

   !check dynamic link libraries https://www.hpc.dtu.dk/?page_id=1180

   print '(A,I4)', "The results from Fortran is", forf(x,y)
   print '(A,I4)', "The results from C is", f2(x,y)

end program
