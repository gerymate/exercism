-module(triangle).

-export([kind/3]).


kind(A, B, C) when A+B < C; A+C < B; B+C < A -> 
  { error , "side lengths violate triangle inequality" };
kind(A, A, A) when A > 0 -> equilateral;
kind(A, A, A) -> { error , "all side lengths must be positive" };
kind(_, A, A) -> isosceles;
kind(A, A, _) -> isosceles;
kind(A, _, A) -> isosceles;
kind(_A, _B, _C) -> scalene.



