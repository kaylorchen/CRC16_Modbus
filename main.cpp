#include <iostream>
#include "stdio.h"
#include "crc16_modbus.h"


int main() {
  unsigned char data[] = {0x02, 0x04, 0x04, 0x08, 0x20, 0x1A, 0x43};
  unsigned short tmp;
  tmp = Crc16Modbus(data, sizeof(data));
  uint8_t *p = (uint8_t *)(&tmp);
  printf("crc value = 0x%X , 0x%X\r\n", *p, *(p+1));
  return 0;
}
