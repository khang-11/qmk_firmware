VIA_ENABLE = yes

# The original keymap used `EXTRAFLAGS += -flto`; LTO_ENABLE is the supported
# form and adds the linker flags that go with it. Needed to fit an 8-layer
# dynamic keymap into the ATmega32u4's 28K.
LTO_ENABLE = yes
