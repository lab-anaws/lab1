
/**
 * \file
 *         A very simple Contiki application to control buttons and led
 * \author
 *         Carlo Vallati <c.vallati@iet.unipi.it>
 */

#include "contiki.h"

#include "dev/button-sensor.h"
#include "dev/leds.h"

#include <stdio.h> /* For printf() */
/*---------------------------------------------------------------------------*/
PROCESS(hello_world_process, "Led button example");
AUTOSTART_PROCESSES(&hello_world_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(hello_world_process, ev, data)
{
  PROCESS_BEGIN();

  SENSORS_ACTIVATE(button_sensor);

  while(1){

  	PROCESS_WAIT_EVENT_UNTIL( ev == sensors_event && data == &button_sensor);

	leds_toggle(LEDS_ALL);

  }

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
