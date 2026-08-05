module Luhn (isValid) where

isValid :: String -> Bool
isValid str = isValid' (filter (/=' ') str) 

isValid' :: String -> Bool
isValid' str
  | (length str) < 2 = False
  | otherwise = (isDivisibleByTen . sum . doubleEverySecondFromRight . getDigits) str

isDivisibleByTen :: Int -> Bool
isDivisibleByTen n = n `mod` 10 == 0

doubleEverySecondFromRight :: [Int] -> [Int]
doubleEverySecondFromRight = reverse . doubleEverySecondDigit . reverse

doubleEverySecondDigit :: [Int] -> [Int]
doubleEverySecondDigit [] = []
doubleEverySecondDigit [x] = [x]
doubleEverySecondDigit (x:y:xs) = x:(doubleDigitWithBound y):(doubleEverySecondDigit xs)

doubleDigitWithBound :: Int -> Int
doubleDigitWithBound digit = if digit > 4 then (2 * digit - 9) else (2 * digit)

getDigits :: String -> [Int]
getDigits = map (\ch -> read [ch])

