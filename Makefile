CONTIKI_PROJECT = led timer_test timer_button 
all: $(CONTIKI_PROJECT)

CONTIKI = ../../..
include $(CONTIKI)/Makefile.include
