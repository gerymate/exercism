module Luhn (isValid) where
import qualified Data.Char as DC

isValid :: String -> Bool
isValid str = let spacelessStr = filter (not . DC.isSpace) str in (all DC.isDigit spacelessStr) && isValid' spacelessStr

isValid' :: String -> Bool
isValid' [] = False
isValid' [_] = False
isValid' str = divisibleByTen . createLuhnSum . getDigits $ str
  where divisibleByTen n = (n `rem` 10) == 0
        getDigits = map DC.digitToInt

createLuhnSum :: [Int] -> Int
createLuhnSum = sum . doubleSecondDigits . reverse
  where doubleSecondDigits = zipWith ($) (cycle [id, doubleDigitWithBound])
        doubleDigitWithBound digit = if digit > 4 then (2 * digit - 9) else (2 * digit)



