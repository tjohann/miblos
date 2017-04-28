# common defines

ifeq "${MIBLOS_HOME}" ""
    $(error error: please source a *_env file first!)
endif

# add global include dir
INCLUDEDIR = ./include
INCLUDEDIR += -I${MIBLOS_HOME}/include

# add global lib dir
LIBDIR = ./lib
LIBDIR += -L${MIBLOS_HOME}/lib

# common cflags
CFLAGS = -ffunction-sections -fdata-sections
LDFLAGS = -Wl,--relax,--gc-sections -Wl,-Map,$(TARGET).map

# common stuff
#WARN = -Wall -Wstrict-prototypes
WARN = -Wall -Wextra
DEBUG = -g -ggdb
CSTD = gnu11

# common tool defines
AVR-GCC = avr-gcc
AVR-AR = avr-ar
AVR-OBJCOPY = avr-objcopy
AVR-OBJDUMP = avr-objdump
AVRSIZE = avr-size


