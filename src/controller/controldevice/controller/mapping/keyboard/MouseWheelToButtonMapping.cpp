#include "MouseWheelToButtonMapping.h"
#include <spdlog/spdlog.h>
#include "utils/StringHelper.h"
#include "public/bridge/consolevariablebridge.h"
#include "Context.h"

namespace Ship {
MouseWheelToButtonMapping::MouseWheelToButtonMapping(uint8_t portIndex, CONTROLLERBUTTONS_T bitmask,
                                                       WheelDirection direction)
    : ControllerInputMapping(ShipDeviceIndex::Keyboard), MouseWheelToAnyMapping(direction),
      ControllerButtonMapping(ShipDeviceIndex::Keyboard, portIndex, bitmask) {
}

void MouseWheelToButtonMapping::UpdatePad(CONTROLLERBUTTONS_T& padButtons) {
    if (!Context::GetInstance()->GetWindow()->IsMouseCaptured()) {
        return;
    }
    auto wheel = Context::GetInstance()->GetWindow()->GetMouseWheel();
    if ((wheel.x < 0 &&
         direction == WheelDirection::LEFT) ||
        (wheel.x > 0 &&
         direction == WheelDirection::RIGHT) ||
        (wheel.y > 0 &&
         direction == WheelDirection::UP) ||
        (wheel.y < 0 &&
         direction == WheelDirection::DOWN)) {

        padButtons |= mBitmask;
    }
}

uint8_t MouseWheelToButtonMapping::GetMappingType() {
    return MAPPING_TYPE_MOUSE;
}

std::string MouseWheelToButtonMapping::GetButtonMappingId() {
    return StringHelper::Sprintf("P%d-B%d-MW%d", mPortIndex, mBitmask, (s32)direction);
}

void MouseWheelToButtonMapping::SaveToConfig() {
    const std::string mappingCvarKey = CVAR_PREFIX_CONTROLLERS ".ButtonMappings." + GetButtonMappingId();
    CVarSetString(StringHelper::Sprintf("%s.ButtonMappingClass", mappingCvarKey.c_str()).c_str(),
                  "MouseWheelToButtonMapping");
    CVarSetInteger(StringHelper::Sprintf("%s.Bitmask", mappingCvarKey.c_str()).c_str(), mBitmask);
    CVarSetInteger(StringHelper::Sprintf("%s.MouseWheel", mappingCvarKey.c_str()).c_str(), (s32)direction);
    CVarSave();
}

void MouseWheelToButtonMapping::EraseFromConfig() {
    const std::string mappingCvarKey = CVAR_PREFIX_CONTROLLERS ".ButtonMappings." + GetButtonMappingId();

    CVarClear(StringHelper::Sprintf("%s.ButtonMappingClass", mappingCvarKey.c_str()).c_str());
    CVarClear(StringHelper::Sprintf("%s.Bitmask", mappingCvarKey.c_str()).c_str());
    CVarClear(StringHelper::Sprintf("%s.MouseWheel", mappingCvarKey.c_str()).c_str());

    CVarSave();
}
} // namespace Ship
