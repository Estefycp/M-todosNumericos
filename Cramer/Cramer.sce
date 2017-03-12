function [ X ] = cramer(A, B)

    [s u] = size(A);
    
    if s~= u
      error('A debe ser una matriz cuadratica');
    elseif s ~= size(B)(1)
      error('A y B no concuerdan en size');
    end
    
    detS = det(A);
    X = zeros(s(1), 1);
    for i = 1 : s(1)
        t = A(:, i);
        A(:, i) = B;
        R(i) = det(A) / detS;
        A(:, i) = t;
    end
endfunction

A = [3., -0.1, -0.2; 0.1, 7., -0.3; 0.3, -0.2, 10.]
B = [7.85; -19.3; 71.4]

X = cramer(A, B)
