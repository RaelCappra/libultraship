#include "controller/controldevice/controller/mapping/ControllerButtonMapping.h"
#include "MouseWheelToAnyMapping.h"

namespace Ship {
class MouseWheelToButtonMapping final : public MouseWheelToAnyMapping, public ControllerButtonMapping {
  public:
    MouseWheelToButtonMapping(uint8_t portIndex, CONTROLLERBUTTONS_T bitmask, WheelDirection direction);
    void UpdatePad(CONTROLLERBUTTONS_T& padButtons) override;
    uint8_t GetMappingType() override;
    std::string GetButtonMappingId() override;
    void SaveToConfig() override;
    void EraseFromConfig() override;
};
} // namespace Ship

