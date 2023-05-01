/*
* Simple code for a flickering candle project.
*
* This version is for Texas Instruments eZ430-F2013 MCU.
* Using Code Composer Essentials for MSP430 version 2.0.4.2
*
* Based on a project by Garde ( http://www.instructables.com/member/Gadre/ )
* http://www.instructables.com/id/YAFLC_Yet_Another_Flickering_LED_Candle/
*
*
* Differences to original:
*
* The original Instructable used 5 output pins to drive one LED at various voltages.
* This version uses ONE output pin, and strobes the LED to simulate changing brightness.
*
* The built in LED on the MCU board is used, so no extra circuitry is needed, just power!
*
* Features a little 'lighting up' phase.
*
* By SarahC, sarah@untamed.zone
*/

#include "msp430x20x1.h"

void delay(volatile unsigned char counter) {
      // If counter isn't 0, decrement it and loop, otherwise return.
      do;
      while (counter--);
}

void LEDOff() {
   // AND 'P1OUT' with 11111110, which leaves all bits as they are
   // except bit 0, which is reset.
   P1OUT &= ~0x01;
}

void LEDOn() {
   // OR 'P1OUT' with 00000001, which leaves all bits as they are
   // except bit 0, which is set.
   P1OUT |= 0x01;
}

unsigned long LEDRun(unsigned long duration, unsigned char brightness) {
   // Loop for 'duration' iterations.
   // 'duration' is a guaranteed period of time, regardless of brightness.
   do {
      //Turn on the LED for the brightness duration.
      LEDOn();
      delay(brightness);

      //Turn off the LED for the inverse of the brightness duration.
      LEDOff();
      delay(256 - brightness);

   } while (duration--);

   return (brightness);
}

void main(void) {

   unsigned long lfsr = 0; // Seed value for pseudo random number
   unsigned char ctr = 0;

   WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
   P1DIR |= 0x01; // Set P1.0 to output direction

   //Turn off the LED and wait awhile after power-on.
   LEDOff();
   for (; ++lfsr < 100000;);

   // Increase LED brightness fairly rapidly.
   // Gives the effect of a candle lighting.
   for (; LEDRun(0, ctr++) < 255;);

   // Move into the pseudo random sequence by 255 numbers.
   // This prevents a small animation pause.
   lfsr = 1;
   for (; ++ctr < 255;)
      lfsr = (lfsr >> 1) ^ (-(lfsr & 1 u) & 0xd0000001 u); // taps 32 31 29 1

   // Loop animation forever
   for (;;) {
      /*
       * Using a Fibonacci linear feedback shift register to produce pseudo random numbers
       * http://en.wikipedia.org/wiki/Linear_feedback_shift_register
       *
       */
      lfsr = (lfsr >> 1) ^ (-(lfsr & 1 u) & 0xd0000001 u); // taps 32 31 29 1

      //Drive the LED for a specific length of time, at a particular brightness.
      LEDRun((unsigned char)(lfsr >> 20) & 31 // Take the 20th to 24th bit for the timer. Range: 0-31
         , (unsigned char)(lfsr >> 24) & 255); // and 24th to 29th bit for the brightness. Range: 0-63

   }
}

