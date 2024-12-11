#pragma once

#include "controller/controldevice/controller/mapping/ControllerInputMapping.h"
#include "Context.h"

namespace Ship {
class MouseButtonToAnyMapping : virtual public ControllerInputMapping {
  public:
    MouseButtonToAnyMapping(MouseBtn button);
    ~MouseButtonToAnyMapping();
    std::string GetPhysicalInputName() override;
    std::string GetPhysicalDeviceName() override;
    bool PhysicalDeviceIsConnected() override;

  protected:
    MouseBtn button;
};
} // namespace Ship
