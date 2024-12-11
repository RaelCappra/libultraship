#include "MouseButtonToAnyMapping.h"
#include "Context.h"

#include "utils/StringHelper.h"
#include "window/gui/IconsFontAwesome4.h"

std::string mouseBtnNames[6] = {"Left Click", "Middle Click", "Right Click", "Backward Click", "Forward Click", "MOUSE_BTN_COUNT"};

namespace Ship {
MouseButtonToAnyMapping::MouseButtonToAnyMapping(MouseBtn button)
    : ControllerInputMapping(ShipDeviceIndex::Keyboard), button(button) {
}

MouseButtonToAnyMapping::~MouseButtonToAnyMapping() {
}

std::string MouseButtonToAnyMapping::GetPhysicalInputName() {
    return mouseBtnNames[(s32)button];
}

std::string MouseButtonToAnyMapping::GetPhysicalDeviceName() {
    return "Mouse";
}

bool MouseButtonToAnyMapping::PhysicalDeviceIsConnected() {
    // todo: handle non-keyboard devices?
    return true;
}
} // namespace Ship
