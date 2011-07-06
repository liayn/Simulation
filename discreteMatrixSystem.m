
function res = discreteMatrixSystem(m,n,z,s)

len = size(z,2);
res = discreteLine(1,m,n,z,s);

for i = 2:len
   res = vertcat(res, discreteLine(i,m,n,z,s));
end

end