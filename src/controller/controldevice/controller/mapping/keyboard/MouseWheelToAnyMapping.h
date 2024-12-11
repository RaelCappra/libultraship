#pragma once

#include "controller/controldevice/controller/mapping/ControllerInputMapping.h"

namespace Ship {
enum class WheelDirection { LEFT, RIGHT, UP, DOWN };
class MouseWheelToAnyMapping : virtual public ControllerInputMapping {
  public:
    MouseWheelToAnyMapping(WheelDirection direction);
    ~MouseWheelToAnyMapping();
    std::string GetPhysicalInputName() override;
    std::string GetPhysicalDeviceName() override;
    bool PhysicalDeviceIsConnected() override;

  protected:
    WheelDirection direction;
};
} // namespace Ship
