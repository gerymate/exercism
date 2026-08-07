module Hamming (distance) where

distance :: String -> String -> Maybe Int
distance xs ys
  | length xs /= length ys = Nothing 
  | null xs = Just 0
  | head xs == head ys = rest_distance
  | otherwise = (+1) <$> rest_distance
      where rest_distance = distance (tail xs) (tail ys)

