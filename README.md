# HalloweenEyes
Make a fancy blinking eyes decoration for Halloween!

Parts list:

* 8x LEDs. I suggest red due to the low voltage drop, allowing you to connect them in pairs. The colors you can use depends on the battery. You can put them in parallel instead of in pairs if you want, but you'll have to limit the current more to fit within the GPIO max current draw. Or you could use 4x transistors to toggle the eyes directly from the power supply.
* Battery case: 3x rechargeable NiMH AA worked for me. Your PIR sensor might want a bit more. The microcontroller I used works at 2.7-5.5V. And a fully charged NiMH caps at 1.4V, so 3 of them have 4.2V max, with a nominal voltage of 3.6V. You can also use a 5V LDO, but that's gonna drain the batteries faster.
* 1x 0.1uF capacitor.
* 1x PIR sensor
* 4x 39 ohm (or greater) resistors.
* 1x ATTINY13A microcontroller.
* Wire
* 3d printed case

Optional:

* 1x DIP8 socket.
* 1x 5-pin JST connector pair.
* 2x 3-pin JST connector pair.



