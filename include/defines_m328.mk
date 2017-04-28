# common defines for m328 (-> nano v3)

# arduino default fuses
# low_fuses=0xff
# high_fuses=0xde
# extended_fuses=0x05

# atmege328 defaults
LFUSE_DEF = 0x62
# full-speed-mode -> CLDIV8 = 1
# -> LFUSE = 0xE2
HFUSE_DEF = 0xdf
# preserve eeprom across flashing
# -> HFUSE = 0xD7
EFUSE_DEF = 0x00

# atmega328 project specific
LFUSE = 0xe2
HFUSE = 0xdf
EFUSE = 0x00

# default fuses
FUSE_DEFAULT = -U lfuse:w:$(LFUSE_DEF):m -U hfuse:w:$(HFUSE_DEF):m -U efuse:w:$(EFUSE_DEF):m

#
# Note:
#       set also FUSE_STRING in project makefile
#
# to add some useful changes, set the below values
# full-speed-mode -> CLDIV8 = 1 -> LFUSE = 0xE2
# preserve eeprom across flashing -> HFUSE = 0xD7
