# Arduino Pixel driver for WS2812b and SK6812 LEDs
With this sketch (on an Raspberry PI PICO), you can controll every single LED on your stripe by color and brightness through USB Serial Bus.

## Serial bus
Default Bus Speed: 115200

## Item array
id: Pixels ID as int in stripe  
r: int value red (0-255)  
g: int value green (0-255)  
b: int value blue (0-255)  
w: int value white (0-255)  
bri: brightness in (0-100)

## Examples

### traffic light
```[[0,255,0,0,0,100], [1,255,255,0,0,25], [2,0,255,0,0,5]]```

#### What this example does
LED0: red with 100% brightness  
LED1: yellow with 25% brightness  
LED2: green with 50% brightness

### Off
```[[0,0,0,0,0,0], [1,0,0,0,0,0], [2,0,0,0,0,0]]```

#### What this example does
LED0: off  
LED1: off  
LED2: off
