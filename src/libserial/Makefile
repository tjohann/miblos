#
# makefile for libavrserial
#

ifeq "${MIBLOS_HOME}" ""
    $(error error: please source a *_env file first!)
endif

include $(MIBLOS_HOME)/mk/defines.mk
include $(MIBLOS_HOME)/mk/defines_compile_macros.mk
include $(PROJECT_CONTROLLER)

TARGET = libserial
SRC = libserial.c
HEADER = libserial.h

#
# common CFLAGS in $(MIBLOS_HOME)/include/defines.mk
#
CONTROLLER = -mmcu=$(MCU) -DF_CPU=$(F_CPU)UL -DBAUD=$(BAUD)UL
OPT_FLAGS = -Os
COMPILER_SWITCHES = -DUSE_SERIAL=$(USE_SERIAL) -DSERIAL_ERROR=$(SERIAL_ERROR)

#
# ---------  BUILD all in a single step ----------
#
all: $(TARGET).a $(TARGET).lst

$(TARGET).a: $(TARGET).c $(TARGET).h $(TARGET)_priv.h
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
	cp -d $(TARGET).a $(MIBLOS_HOME)/lib
	cp -d $(TARGET).h $(MIBLOS_HOME)/include

#
# -> surprise surpirse a cleanup tag
#
clean:
	rm -rf *~ *.a *.i *.s *.elf *.hex *.bin *.srec *.obj *.o *.eeprom *.lst *.map core.d

