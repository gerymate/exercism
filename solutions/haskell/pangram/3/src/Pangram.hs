module Pangram (isPangram) where

import qualified Data.Set as Set (fromList)
import Data.Char (toUpper, isAscii, isAlpha)

isPangram :: String -> Bool
isPangram text = setOfAllLettersIn text == setOfAllAsciiLetters where 
  setOfAllAsciiLetters = Set.fromList ['A'..'Z']
  setOfAllLettersIn str = Set.fromList $ map toUpper $ justTheChars str
  justTheChars = filter (\ch -> isAscii ch && isAlpha ch)
  