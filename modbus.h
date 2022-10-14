//
// Created by SXF-Admin on 22-10-14.
//

#ifndef CRC16_MODBUS__MODBUS_H_
#define CRC16_MODBUS__MODBUS_H_
#include "stdint.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef void (*write_fn)(const uint32_t, const uint8_t const *, const uint16_t);
typedef void (*read_fn)(uint8_t const *, const uint16_t);

void InitializeModbus(write_fn write_fn_, read_fn read_fn_);
void SendData(const uint32_t std_ID,
              const uint8_t count,
              const uint16_t order_code,
              const uint8_t sub_code,
              const uint32_t data);
void ReceiveData(const uint32_t std_ID, const uint16_t order_code, const uint8_t sub_code, uint32_t *data);
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif //CRC16_MODBUS__MODBUS_H_
