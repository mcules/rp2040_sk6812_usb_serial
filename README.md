# JSON Data to send on serial bus
Bus Speed default: 115200

## Item array
id: Pixels ID as int in stripe  
rgbw: int array with red, green, blue, white values  
bri: brightness in 0-100%

## Example command
```[{"id": 0, "rgbw": [0,255,0,0], "bri": 10}, {"id": 1, "rgbw": [255, 0, 0, 0], "bri": 2}, {"id": 2, "rgbw": [0, 0, 255, 0], "bri": 50}]```

## What this example does
LED0: green with 10% brightness  
LED1: red with 2% brightness  
LED2: blue with 50% brightness