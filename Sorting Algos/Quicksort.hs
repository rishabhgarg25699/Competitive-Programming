module Quicksort where


qsort [] = []
qsort (x:xs) = qsort ys ++ [x] ++ qsort zs
           where
             ys = [a | a <- xs, a <= x]
             zs = [b | b <- xs, b > x]
