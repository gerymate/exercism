module Anagram (anagramsFor) where
import Data.List (sort)
import Data.Char (toUpper)

anagramsFor :: String -> [String] -> [String]
anagramsFor xs = filter (anagramOf xs)
  where anagramOf x y = (sortedUpcase x) == (sortedUpcase y) && (upcase x) /= (upcase y)
        sortedUpcase = sort . upcase
        upcase = map toUpper



