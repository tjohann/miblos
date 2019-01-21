#
# my simple makefile act as something like a user interface
#

ifeq "${MIBLOS_HOME}" ""
    $(error error: please source a *_env file first!)
endif

#include include/defines.mk

MODULES = src avr_ttenv_simple avr_blink_led
MODULES_ADDITIONAL = include bin lib mk pics Documentation schematics

all::
	@echo "+-----------------------------------------------+"
	@echo "|                                               |"
	@echo "|            Building all in src                |"
	@echo "|                                               |"
	@echo "+-----------------------------------------------+"
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done

clean::
	rm -f *~ *.o .*~
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done
	for dir in $(MODULES_ADDITIONAL); do (cd $$dir && $(MAKE) $@); done

distclean: clean
	@echo "+-----------------------------------------------+"
	@echo "|                                               |"
	@echo "|         Nothing to do for distclean           |"
	@echo "|                                               |"
	@echo "+-----------------------------------------------+"

install:: all
	@echo "+-----------------------------------------------+"
	@echo "|                                               |"
	@echo "|            Install all in src                 |"
	@echo "|                                               |"
	@echo "+-----------------------------------------------+"
	for dir in $(MODULES); do (cd $$dir && $(MAKE) $@); done
