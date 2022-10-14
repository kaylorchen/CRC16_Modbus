cmake_minimum_required(VERSION 3.23)
project(CRC16_Modbus)

set(CMAKE_CXX_STANDARD 14)

add_executable(CRC16_Modbus main.cpp crc16_modbus.c modbus.c)
