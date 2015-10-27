
/**
 * \file
 *         A very simple Contiki application showing how Contiki timers can be used
 * \author
 *         Carlo Vallati <c.vallati@iet.unipi.it>
 */

#include "contiki.h"

#include "sys/etimer.h"

#include <stdio.h> /* For printf() */
/*---------------------------------------------------------------------------*/
PROCESS(hello_world_process, "Timer test");
AUTOSTART_PROCESSES(&hello_world_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(hello_world_process, ev, data)
{
  PROCESS_BEGIN();

  static struct etimer et;

  etimer_set(&et, CLOCK_SECOND*4);

  while(1){

	PROCESS_WAIT_EVENT();

	if(etimer_expired(&et)){

		printf("Timer expired\n");

		etimer_reset(&et);

	}

  }

  
  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
