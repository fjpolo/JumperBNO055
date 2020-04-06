#pragma once
#include "ModelingFramework.h"

class BNO055 : public ExternalPeripheral {
  public:
    BNO055();
    void Main() override;
    void Stop() override;
  private:
     iI2cSlave* i2c_slave_{};
     uint8_t device_address_{};
     void OnMasterRead(uint8_t device_address, iI2cSlaveBaseWriteStream& i2c_slave_read_stream);
     void OnMasterWrite(uint8_t device_address, iI2cSlaveBaseReadStream& i2c_slave_write_stream);
};

extern "C" ExternalPeripheral *PeripheralFactory() {
    return new BNO055();
}

