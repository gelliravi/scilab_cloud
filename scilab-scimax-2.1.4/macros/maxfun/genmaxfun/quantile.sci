function c=quantile(a,b)

if argn(2)~=2 then error(42), end
c=maxevalf('quantile',a,b)

endfunction
