module Luhn (isValid) where

isValid :: String -> Bool
isValid str = isValid' (filter (/=' ') str) 

isValid' :: String -> Bool
isValid' str
  | (length str) < 2 = False
  | otherwise = (divisibleByTen . sumAll . doubleEverySecondFromRight . getDigits) str

divisibleByTen :: Int -> Bool
divisibleByTen n = n `mod` 10 == 0

sumAll :: [Int] -> Int
sumAll = foldl1 (+) 

doubleEverySecondFromRight :: [Int] -> [Int]
doubleEverySecondFromRight digits = let lastIndex = ((length digits) - 1) in  
    map 
    (\i -> 
        if ((lastIndex - i) `mod` 2 == 0)
            then (digits !! i)
            else (doubleDigitWithBound (digits !! i))
    )
    [0..lastIndex]

doubleDigitWithBound :: Int -> Int
doubleDigitWithBound digit
  | doubleDigit > 9 = doubleDigit - 9
  | otherwise = doubleDigit
  where doubleDigit = 2 * digit

getDigits :: String -> [Int]
getDigits str = map getDigit str

getDigit :: Char -> Int
getDigit '0' = 0
getDigit '1' = 1
getDigit '2' = 2
getDigit '3' = 3
getDigit '4' = 4
getDigit '5' = 5
getDigit '6' = 6
getDigit '7' = 7
getDigit '8' = 8
getDigit '9' = 9
getDigit _   = -1

