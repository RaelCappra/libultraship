#include "MouseWheelToAnyMapping.h"
#include "Context.h"

#include "utils/StringHelper.h"
#include "window/gui/IconsFontAwesome4.h"

std::string mouseDirectionNames[4] = { "WheelLeft", "WheelRight", "WheelUp", "WheelDown" };

namespace Ship {
MouseWheelToAnyMapping::MouseWheelToAnyMapping(WheelDirection direction)
    : ControllerInputMapping(ShipDeviceIndex::Keyboard), direction(direction){
}

MouseWheelToAnyMapping::~MouseWheelToAnyMapping() {
}

std::string MouseWheelToAnyMapping::GetPhysicalInputName() {
    return mouseDirectionNames[(u32)direction];
}

std::string MouseWheelToAnyMapping::GetPhysicalDeviceName() {
    return "Mouse";
}

bool MouseWheelToAnyMapping::PhysicalDeviceIsConnected() {
    // todo: handle non-keyboard devices?
    return true;
}
} // namespace Ship
