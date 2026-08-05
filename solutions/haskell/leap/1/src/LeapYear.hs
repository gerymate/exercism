module LeapYear (isLeapYear) where

isLeapYear :: Integer -> Bool
isLeapYear year | divisible 400 = True
                | divisible 100 = False
                | divisible 4 = True
                | otherwise = False
    where divisible n = (0 == year `mod` n) 

