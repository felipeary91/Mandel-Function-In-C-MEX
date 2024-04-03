clear
close all
gridSize = 512;
maxIterations = 500;

xlim = [-0.748766713922161, -0.748766707771757];
ylim = [ 0.123640844894862,  0.123640851045266];

x = linspace( xlim(1), xlim(2), gridSize );
count_MATLAB = zeros(gridSize, gridSize);
count_C = zeros(gridSize, gridSize);

ind = 1;
for y = linspace( ylim(1), ylim(2), gridSize)
    z0 = x + 1i*y;
    count_MATLAB(ind, :) = func_mandel(z0, maxIterations);
    count_C(ind, :) = func_mandel_MEX(z0, maxIterations);
    ind = ind + 1;
end
count_MATLAB = log(count_MATLAB);
count_C = log(count_C);
imagesc(count_C );
colormap hot
axis off
title('C result');

title(['Difference between MATLAB and C = ' num2str(norm(count_C-count_MATLAB))]);