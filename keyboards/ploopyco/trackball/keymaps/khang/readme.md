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

| define | value | effect |
|---|---|---|
| `PLOOPY_DPI_OPTIONS` | `{ 1400 }` | pinned at 1400 CPI; `DPI_CONFIG` is inert |
| `PLOOPY_DPI_DEFAULT` | `0` | |
| `PLOOPY_DRAGSCROLL_DIVISOR_H/V` | `64.0` (inherited) | 1400 / 64 = ~22 ticks per inch |
| `DYNAMIC_KEYMAP_LAYER_COUNT` | `8` | VIA layers |

## Adjusting the DPI

It is pinned at 1400, so `DPI_CONFIG` does nothing. 1400 was chosen from a
runtime ladder of:

```c
#define PLOOPY_DPI_OPTIONS { 1100, 1200, 1300, 1400, 1500 }
```

Put that line back in `config.h` to cycle through it again with **DPI Config**
assigned in <https://usevia.app> - `DPI_CONFIG` saves the index to EEPROM, so
you can tune without reflashing.

Granularity is 100 CPI, the PMW3360's resolution register step
(`PMW33XX_CPI_STEP`). There is no 50 step: `pmw33xx_set_cpi()` divides the
requested value by 100, so 1150 writes the same register value as 1100 and
reads back as 1100.

## Finding your DPI without reflashing

`DPI_CONFIG` steps through `PLOOPY_DPI_OPTIONS` and writes the chosen index to
EEPROM, so the value survives reboots and reflashes. This only applies while
`PLOOPY_DPI_OPTIONS` has more than one entry.

1. Assign **DPI Config** to a button in <https://usevia.app>. The wheel click
   (`[0,1]`) is free in this keymap.
2. Press it to step forward through the ladder. It wraps at the end.
3. Settle on whatever feels right and stop - nothing else to do. The choice is
   already saved.

Boots on 1100 CPI (index 0). Each press moves one step, so the value is:

| presses | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| CPI | **1100** | 1200 | 1300 | 1400 | 1500 |

The granularity is 100 CPI, which is the PMW3360's resolution register step
(`PMW33XX_CPI_STEP`). There is no 50 step: `pmw33xx_set_cpi()` divides the
requested CPI by 100, so 1150 writes the same register value as 1100 and reads
back as 1100. Asking for 50 increments would produce duplicate entries.

Once you know the number, it can be pinned to a single value so `DPI_CONFIG`
stops doing anything - which is what this keymap now does with 1400.

Note that drag-scroll speed scales with CPI, because ticks per inch is
`CPI / divisor`. At 1200 CPI with the inherited `64.0` that's ~19 ticks per
inch, against ~14 for the Adept at 900. Set the divisor to `85.0` to hold the
Adept's rate at 1200 CPI; `8.0` (the upstream default) is roughly 8x faster
again.

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
