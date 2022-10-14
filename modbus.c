//
// Created by Kaylor on 22-10-14.
//
#include "modbus.h"
#include "crc16_modbus.h"
write_fn write;
read_fn read;
void InitializeModbus(write_fn write_fn_, read_fn read_fn_) {
  write = write_fn_;
  read = read_fn_;
}

/**
* @param  std_ID: Motor's ID
* @param  count: the number of data to be sent
* @param  order_code: register address
* @param  sub_code: subaddress
* @param  data: data to be sent
*/
void SendData(const uint32_t std_ID,
              const uint8_t count,
              const uint16_t order_code,
              const uint8_t sub_code,
              const uint32_t data) {
  uint8_t buffer[8];
  switch (count) {
    case 1:buffer[0] = 0x2F;
      break;
    case 2:buffer[0] = 0x2B;
      break;
    case 4:buffer[0] = 0x23;
      break;
    default:buffer[0] = 0x00;
      break;
  }
  buffer[1] = order_code & 0x00FF;
  buffer[2] = order_code >> 8;
  buffer[3] = sub_code;
  buffer[4] = data & 0xFF;
  buffer[5] = (data >> 8) & 0xFF;
  buffer[6] = (data >> 16) & 0xFF;
  buffer[7] = (data >> 24) & 0xFF;
  write(std_ID, buffer, 8);
}

/**
* @param  std_ID: Motor's ID
* @param  order_code: register address
* @param  sub_code: subaddress
* @param  data: pointer of data to be receiced
 * */

void ReceiveData(const uint32_t std_ID, const uint16_t order_code, const uint8_t sub_code, uint32_t *data) {
  uint8_t buffer[8];
  buffer[0] = 0x40;
  buffer[1] = order_code&0x00FF;
  buffer[2] = order_code>>8;
  buffer[3] = sub_code;
  buffer[4] = 0x00;
  buffer[5] = 0x00;
  buffer[6] = 0x00;
  buffer[7] = 0x00;
  write(std_ID, buffer, 8);
  read(data, 8);
}