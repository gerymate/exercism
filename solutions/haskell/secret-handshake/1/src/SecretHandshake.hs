module SecretHandshake (handshake) where

handshake :: Int -> [String]
handshake n
  | n >= 16 = reverse $ handshake (n - 16)
  | otherwise = hs n [] ["wink", "double blink", "close your eyes", "jump"]

hs :: Int -> [String ] -> [String] -> [String]
hs 0 outlist _ = reverse outlist
hs n outlist (w:wx)
  | odd n = hs (div n 2) (w:outlist) wx
  | otherwise  = hs (div n 2) outlist wx
hs _ _ _ = error "This should not happen!"
