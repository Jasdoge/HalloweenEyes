# HalloweenEyes
Make a fancy blinking eyes decoration for Halloween!

Parts list:

* 8x LEDs. I suggest red due to the low voltage drop, allowing you to connect them in pairs. The colors you can use depends on the battery. You can put them in parallel instead of in pairs if you want, but you'll have to limit the current more to fit within the GPIO max current draw. Or you could use 4x transistors to toggle the eyes directly from the power supply.
* LiPo battery: I use a 1200mAh one. You'll likely want to alter the mesh a bit to fit your battery. You could also design your own case and use 3 rechargeable NiMH batteries.
* LiPo charger: [I use a cheap USB one](https://www.aliexpress.com/item/32583428593.html).
* 1x 0.1uF capacitor.
* 1x PIR sensor
* 4x 39 ohm (or greater) resistors.
* 1x ATTINY13A microcontroller.
* Wire
* 3d printed case (files are in the Assets directory)
* [Sparkfun mini perfboard](https://www.digikey.se/product-detail/en/sparkfun-electronics/PRT-08808/1568-1652-ND/7387401)

Optional:

* A switch of your liking to turn it on/off.
* 1x DIP8 socket.
* 1x [5-pin JST connector pair](https://www.digikey.se/product-detail/en/jst-sales-america-inc/B5B-XH-A-LF-SN/455-2270-ND/1530483).
* 2x [3-pin JST connector pair](https://www.digikey.se/product-detail/en/jst-sales-america-inc/B3B-XH-A-LF-SN/455-2248-ND/1651046).



