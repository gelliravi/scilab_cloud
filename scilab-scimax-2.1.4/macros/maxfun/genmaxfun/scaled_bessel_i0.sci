function b=scaled_bessel_i0(a)

if argn(2)~=1 then error(42), end
b=maxevalf('scaled_bessel_i0',a)

endfunction
