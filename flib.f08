
!gfortran -shared flib.f08 -o a.so
pure real(8) function myfunc(x)
!00000000000010f9 T myfunc_
    implicit none
    real(8),intent(in)::x

    myfunc = 10.0*x
end function