module Main where

import Language.Copilot
import Copilot.Compile.C99
import Prelude hiding ((>), (<), div)

-- External temperature as a byte, range of −50C to 100C
temp :: Stream Word8
temp = extern "temperature" (Just [0..100])

-- Calculate temperature in Celcius .
-- We need to cast the Word8 to a Float. Note that it is an unsafeCast, as there
-- is no direct relation between Word8 and Float.
ctemp :: Stream Float
ctemp = (unsafeCast temp) * (150.0 / 255.0) - 50.0

spec = do
  -- Triggers that fire when the ctemp is too low or too high,
  -- pass the current ctemp as an argument.
  trigger "heaton" (ctemp < 18.0) [arg ctemp]
  trigger "heatoff" (ctemp > 21.0) [arg ctemp]

-- Compile the spec
main = do
  --interpret 100 spec
  reified <- reify spec
  compile "heater" reified
