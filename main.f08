program main
   implicit none
   integer(4), external :: forf

   integer(4) :: x,  y
   x=10
   y=20

   print '(A,I4)', "The results from Fortran is ", forf(x,y)

end program
