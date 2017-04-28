#
# my simple makefile act as something like a user interface
#

ifeq "${MIBLOS_HOME}" ""
    $(error error: please source a *_env file first!)
endif

AVR_LIBS = libhelper libserial

all::
	@echo " "
	@echo "--> Building $(AVR_LIBS) "
	@echo " "
	for dir in $(AVR_LIBS); do (cd $$dir && $(MAKE) $@ && $(MAKE) install); done

clean::
	rm -f *~ *.o .*~
	for dir in $(AVR_LIBS); do (cd $$dir && $(MAKE) $@); done

install::
	@echo " "
	@echo "--> Install $(AVR_LIBS) "
	@echo " "
	for dir in $(AVR_LIBS); do (cd $$dir && $(MAKE) $@); done
