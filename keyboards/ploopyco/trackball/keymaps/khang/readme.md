# Ploopy Classic - `khang` keymap

Adapted from the `elenium` keymap in
[eleniums/qmk_firmware PR #2](https://github.com/eleniums/qmk_firmware/pull/2).

## Layout

Five buttons. Only layer 0 is populated; VIA is enabled, so set the real layout
in <https://usevia.app>.

| matrix | physical button | default keymap | this keymap |
|---|---|---|---|
| `[0,0]` | left | `MS_BTN1` | `KC_BTN1` - left click |
| `[0,1]` | **wheel click** | `MS_BTN3` | `KC_NO` - nothing |
| `[0,2]` | right | `MS_BTN2` | `KC_BTN3` - middle click |
| `[0,3]` | back (right of ball) | `MS_BTN4` | `KC_BTN2` - right click |
| `[0,4]` | forward | `MS_BTN5` | `DRAG_SCROLL` |

Two changes from the original:

- `PLOOPY_DPI_DEFAULT` is no longer relied on: the DPI and drag-scroll defines
  are dropped entirely so the keymap inherits the shared defaults the Adept
  uses. The original had `PLOOPY_DPI_DEFAULT 1` against a single-element
  `PLOOPY_DPI_OPTIONS`, which reads past the end of `dpi_array[]` and leaves the
  sensor on a garbage CPI.
- `LTO_ENABLE = yes` instead of `EXTRAFLAGS += -flto`, which is the supported
  way to get the same thing.

## Configuration

This keymap sets no DPI or drag-scroll defines, so it inherits these from
`keyboards/ploopyco/ploopyco.c` - the same values the Adept runs:

| define | value | effect |
|---|---|---|
| `PLOOPY_DPI_OPTIONS` | `{900}` | sensor runs at 900 CPI |
| `PLOOPY_DPI_DEFAULT` | `0` | |
| `PLOOPY_DRAGSCROLL_DIVISOR_H/V` | `64.0` | 900 / 64 = ~14 scroll ticks per inch of ball travel |
| `DYNAMIC_KEYMAP_LAYER_COUNT` | `8` | VIA layers |

`PLOOPY_DRAGSCROLL_INVERT` is deliberately not set, which reverses the
vertical drag-scroll direction relative to the original keymap. Note this tree
only implements the vertical inversion - `PLOOPY_DRAGSCROLL_H_INVERT` is
documented in the readme but not handled by the code, so the horizontal
component always follows the ball.

Lower the divisor for faster drag scrolling, raise it for slower. `8.0` (the
upstream default before this fork's tuning) is about 8x faster than `64.0`.

## Build

```
qmk compile -kb ploopyco/trackball/rev1_005 -km khang
```

## Flash

1. Unplug the trackball.
2. Hold the button immediately to the right of the ball (the "back" button).
3. While holding it, plug the trackball in. It should enumerate as an Atmel DFU
   device.
4. Flash:

```
qmk flash -kb ploopyco/trackball/rev1_005 -km khang
```

Or flash the built hex directly:

```
qmk flash ploopyco_trackball_rev1_005_khang.hex
```

## Links

- <https://github.com/ploopyco/classic-trackball/wiki/Appendix-C:-QMK-Firmware-Programming>
- <https://docs.qmk.fm/#/newbs_building_firmware>
- <https://docs.qmk.fm/#/newbs_flashing>
