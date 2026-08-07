module Acronym (abbreviate) where
import Data.Char (isUpper, isLower, toUpper, isLetter)

abbreviate :: String -> String
abbreviate xs = map (toUpper . head) $ words' xs 

words' :: String -> [String]
words' xs = parseWords [] [] cleanedXs
  where cleanedXs = map (\ch -> if isLetter ch || ch == '\'' then ch else ' ') xs

parseWords :: [String] -> String -> String -> [String]
parseWords output [] "" = reverse output
parseWords output current "" = parseWords (current:output) [] "" 
parseWords output current (' ':' ':chars) = parseWords output current (' ':chars) 
parseWords output current (' ':chars) = parseWords (current:output) [] chars 
parseWords output current chars
  | current /= [] && (isLower . last) current && (isUpper . head) chars = parseWords (current:output) [] chars 
parseWords output current (ch:chars) = parseWords output (current ++ [ch]) chars
