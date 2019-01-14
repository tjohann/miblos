#
# makefile for libhelper
#

ifeq "${MIBLOS_HOME}" ""
    $(error error: please source a *_env file first!)
endif

include ${MIBLOS_HOME}/mk/defines.mk
include $(MIBLOS_HOME)/mk/defines_compile_macros.mk
include $(PROJECT_CONTROLLER)

TARGET = libhelper
SRC = libhelper.c
HEADER = libhelper.h

CONTROLLER = -mmcu=$(MCU) -DF_CPU=$(F_CPU)UL
OPT_FLAGS = -Os
COMPILER_SWITCHES =

#
# ---------  BUILD all in a single step ----------
#
all: $(TARGET).a $(TARGET).lst

$(TARGET).a: $(TARGET).c $(TARGET).h
	@echo "$(MIBLOS_HOME)"
	@echo "|| "
	@echo "|| -->   building $(TARGET).a of $(SRC) for target $(MCU)"
	@echo "|| "
	$(AVR-GCC) $(WARN) $(DEBUG) -std=$(CSTD) $(CONTROLLER) $(CFLAGS) $(OPT_FLAGS) $(COMPILER_SWITCHES) -save-temps -c $(SRC) -I$(INCLUDEDIR)
	$(AVR-AR) rcv $(TARGET).a $(TARGET).o

%.lst: %.a
	@echo " "
	@echo "|| "
	@echo "|| -->  Create $(TARGET).lst "
	@echo "|| "
	$(AVR-OBJDUMP) -h -S $< > $@

install: $(TARGET).a
	cp -d *.a $(MIBLOS_HOME)/lib
	cp -d *.h $(MIBLOS_HOME)/include

clean:
	rm -rf *~ *.a *.i *.s *.elf *.hex *.bin *.srec *.obj *.o *.eeprom *.lst *.map core.d





