#ifndef DEVICESTRUCT_H
#define DEVICESTRUCT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  DISPLAY_LCD,
  DISPLAY_OLED,
  DISPLAY_AMOLED,
  DISPLAY_EINK
} DisplayType;

typedef enum { CPU_LOW_POWER, CPU_STANDARD, CPU_HIGH_PERF } CPUType;

typedef enum {
  MEM_16KB = 0,
  MEM_32KB = 1,
  MEM_64KB = 2,
  MEM_128KB = 3
} MemorySize;

typedef enum { WATER_NONE = 0, WATER_IP67 = 1, WATER_IP68 = 2 } WaterResistance;

typedef struct {
  unsigned int display_type : 2;
  unsigned int brightness : 3;
  unsigned int time_format : 1;
  unsigned int alarm_flag : 1;
  unsigned int memory : 2;
  unsigned int cpu_type : 2;
  unsigned int water_resist : 2;
} BitDevice;

typedef struct __attribute__((packed)) {
  unsigned int display_type : 2;
  unsigned int brightness : 3;
  unsigned int time_format : 1;
  unsigned int alarm_flag : 1;
  unsigned int memory : 2;
  unsigned int cpu_type : 2;
  unsigned int water_resist : 2;
} PackedBitDevice;

BitDevice *create_bit_device(DisplayType disp, int bright, int format,
                             bool alarm, MemorySize mem, CPUType cpu,
                             WaterResistance water);
void destroy_bit_device(BitDevice *device);
void bit_device_set_brightness(BitDevice *device, int brightness);
int bit_device_get_brightness(const BitDevice *device);
void bit_device_set_alarm(BitDevice *device, bool status);
bool bit_device_get_alarm(const BitDevice *device);
void bit_device_print_info(const BitDevice *device);

#endif