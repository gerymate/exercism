module Prime (nth) where

nth :: Int -> Maybe Integer
nth n 
  | n > 0 = Just (primes !! (n - 1))
  | otherwise  = Nothing

primes :: [Integer]
primes = filter is_prime [2..]

is_prime :: Integer -> Bool
is_prime pc = and (map (divisible pc) [2..(div pc 2)])

divisible :: Integer -> Integer -> Bool
divisible a b = (mod a b) /= 0

