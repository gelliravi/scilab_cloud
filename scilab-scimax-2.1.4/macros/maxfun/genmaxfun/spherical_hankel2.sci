function c=spherical_hankel2(a,b)

if argn(2)~=2 then error(42), end
c=maxevalf('spherical_hankel2',a,b)

endfunction
