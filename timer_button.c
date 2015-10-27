
/**
 * \file
 *         A very simple Contiki application to control buttons and timers
 * \author
 *         Carlo Vallati <c.vallati@iet.unipi.it>
 */

#include "contiki.h"

#include "dev/button-sensor.h"
#include "dev/leds.h"
#include "sys/etimer.h"

#include <stdio.h> /* For printf() */
/*---------------------------------------------------------------------------*/
PROCESS(hello_world_process, "Button timer test");
AUTOSTART_PROCESSES(&hello_world_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(hello_world_process, ev, data)
{
  PROCESS_BEGIN();

  static struct etimer et;

  etimer_set(&et, CLOCK_SECOND*4);

  SENSORS_ACTIVATE(button_sensor);

  while(1){

	PROCESS_WAIT_EVENT();

	if(etimer_expired(&et)){

		printf("Timer expired\n");

		etimer_reset(&et);

	} else if(ev == sensors_event && data == &button_sensor){
		printf("Button pressed\n");

		leds_toggle(LEDS_ALL);
	}

  }

  
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
