#pragma once

#include "controller/controldevice/controller/mapping/ControllerButtonMapping.h"
#include "MouseKeyToAnyMapping.h"
#include "window/MouseMeta.h"

namespace Ship {
class MouseKeyToButtonMapping final : public MouseKeyToAnyMapping, public ControllerButtonMapping {
  public:
    MouseKeyToButtonMapping(uint8_t portIndex, CONTROLLERBUTTONS_T bitmask, MouseBtn button);
    void UpdatePad(CONTROLLERBUTTONS_T& padButtons) override;
    uint8_t GetMappingType() override;
    std::string GetButtonMappingId() override;
    void SaveToConfig() override;
    void EraseFromConfig() override;
};
} // namespace Ship