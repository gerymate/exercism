{-# LANGUAGE OverloadedStrings #-}
module Acronym (abbreviate) where
import qualified Data.Text as T
import           Data.Text (Text)
import Data.Char (isUpper, isLower)


abbreviate :: Text -> Text
abbreviate txt = T.concat $ map capitals $ T.words $ denoise txt where
  denoise = T.replace "-" " "
  capitals = T.filter isUpper . prepare
  prepare word
    | isLower $ T.head word = T.toTitle word
    | T.toUpper word == word = T.toTitle word
    | otherwise = word