My simple bare-metal os (MIBLOS)
================================


This repository provides a basic playground for the bare-metal realtime topics which should end in an simple realtime os for avr controller.

In the future cortex-M3 (https://github.com/tjohann/arm_cortex_sdk) controller based version will follow.

Micheal J. Pont (http://www.safetty.net/about) describes in his book ERES (http://www.safetty.net/publications/the-engineering-of-reliable-embedded-systems) a time triggert os/system/environment to build reliable embedded systems. This book is something like a guideline for me.

WARNING: This is work in progress! So it's possible that something is not working or possibly not implemented yet. If you face a bug then pls use create an issue (https://github.com/tjohann/miblos/issues).


AVR controller based
====================

Here`re the AVR controller based examples.


avr_blink_led
-------------

Something like a hello_world -> let a LED blink. It`s the starting point to check if everhing of your development environment works fine.

State: started


avr_ttenv_simple
----------------

A simple time-triggert environment with 1/10/100ms time slices. It established the concept of states and modes. Also a something like hello_world.

State: started


avr_ttenv
---------

A time-triggert environment for AVR controller.

State: not started


ARM controller based
====================

Here`re the ARM-Cortex-M3 controller based examples.

arm_blink_led
-------------

tbd.

State: not started


arm_ttenv_simple
----------------

tbd.

State: started


arm_ttenv
---------

tbd.

State: not started
