/*******************************************************************************
 * Stefan Bylund 2017
 *
 * Implementation of layer2_configure() in zxnext_layer2.h.
 ******************************************************************************/

#include <stdint.h>
#include <stdbool.h>

#include "zxnext_layer2.h"
#include "layer2_defs.h"

// FIXME: If the LAYER2_PORT is also readable, we can split this function into
// two functions; one for enabling the layer 2 screen and one for paging it in.
// Then we should also preserve the other bits when setting the layer 2 screen
// section for writing.

// FIXME: Remove parameter layer2_behind_ula_screen later on.

void layer2_configure(bool layer2_visible,
                      bool layer2_behind_ula_screen,
                      bool layer2_write_enabled,
                      uint8_t layer2_screen_section)
{
    uint8_t value = (layer2_screen_section & LAYER2_SCREEN_SECTION_MASK) << LAYER2_SCREEN_SECTION_SHIFT;

    if (layer2_visible)
    {
        value = value | LAYER2_VISIBLE_MASK;
    }

    if (layer2_behind_ula_screen)
    {
        value = value | LAYER2_BEHIND_ULA_SCREEN_MASK;
    }

    if (layer2_write_enabled)
    {
        value = value | LAYER2_WRITE_ENABLE_MASK;
    }

    IO_LAYER2_PORT = value;
}