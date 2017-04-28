# common compiler switches to active/deactivate code fragments
#
# Note: also edit avr/arm_compile_macros.h if needed

ifeq "${MIBLOS_HOME}" ""
    $(error error: please source a *_env file first!)
endif

# ----------- ERRNO parts -------------

# use serial_errno to indicate serial specific erros
# -> ON  (use it)
# -> OFF (no i can do it better)
SERIAL_ERROR = __ON__


