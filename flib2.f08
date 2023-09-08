!gfortran -shared -static-libgfortran flib2.f08 -o a3.a

!view exported symbols
!nm -D --demangle a3.a

pure real(8) function mystaticfunc(x)
!00000000000010f9 T mystaticfunc_
    implicit none
    real(8),intent(in)::x

    mystaticfunc = -10.0*x
end function


pure integer(4) function myintfunc(x)
!0000000000001137 T myintfunc_
    implicit none
    integer(4),intent(in)::x

    myintfunc = -10*x
end function

pure subroutine mysub(x, y)
!0000000000001150 T mysub_
    integer(4),intent(in)::x
    integer(4),intent(out)::y

    y = 100 * x
end subroutine

module types
    implicit none

    integer(4), parameter::sz = 10
   
    type :: GasMix
        sequence

        integer(4) :: m_CO2
        real(8):: s
        integer(4):: n
        real(8) :: a(sz)

        !real(8),allocatable::v(:)
    end type

    type :: Vector
        !sequence
        real(8):: x   !v%x -> v.x
        real(8):: y   
        real(8):: z
    end type
  
end module types


pure type(Vector) function addV(v1,v2)
    use types
    implicit none
    type(Vector), intent(in)::v1,v2

    addV%x = v1%x + v2%x
    addV%y = v1%y + v2%y
    addV%z = v1%z + v2%z

end function

subroutine testStruct(gas)
!000000000000164a T teststruct_    
    use types
    implicit none

    type(GasMix) :: gas

    integer(4) :: i

    gas%m_CO2 = 500;

    !allocate(gas%v(10))
    !gas%v(1) = 888.0;

    gas%s = 500.0
    do i = 1, gas%n
        gas%s = gas%s + gas%a(i)
    enddo
    
endsubroutine




