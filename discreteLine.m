
function line = discreteLine(i, m, n, z, s)
%
%  [ z_{i-m},... ,z_i ,  s_i * z_{i-n},... s_i* z_i ]  
%

ainit = zeros(1, m-i);

as = max(i-m+1, 1);
avect = z(as:i);

binit = zeros(1, n-i);    

bs = max(i-n+1, 1);
bvect = z(bs:i);

line = [ ainit avect 1 binit bvect.*s(i) ];
    
end

