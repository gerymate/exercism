module PerfectNumbers (classify, Classification(..)) where

data Classification = Deficient | Perfect | Abundant deriving (Eq, Show)

classify :: Int -> Maybe Classification
classify n
  | n < 1 = Nothing
  | summedDivisors == n = Just Perfect
  | summedDivisors < n  = Just Deficient
  | summedDivisors > n  = Just Abundant
  | otherwise = Nothing
  where summedDivisors = sum [d | d <- [1..(n `div` 2)], n `mod` d == 0]

