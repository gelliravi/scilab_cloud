function c=igeodesic_coords(a,b)

if argn(2)~=2 then error(42), end
c=maxevalf('igeodesic_coords',a,b)

endfunction
