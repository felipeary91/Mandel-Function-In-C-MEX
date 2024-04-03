function out = func_mandel(z0, maxIterations)
out = ones(1, length(z0));
z = z0;
for n = 0:maxIterations
    z = z.*z + z0;
    inside = abs( z )<=2;
    out = out + inside;
end
