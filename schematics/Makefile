# only for cleaning :-)

ifeq "${MIBLOS_HOME}" ""
    $(error error: please source a *_env file first!)
endif


SUBDIRS =

.PHONY: all
all:
	@echo Cheers

.PHONY: clean
clean:
	rm -f *~ *.o
	for dir in $(SUBDIRS); do (cd $$dir && $(MAKE) $@); done


