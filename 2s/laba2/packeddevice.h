#ifndef PACKEDDEVICE_H
#define PACKEDDEVICE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint16_t PackedDevice;

#define POS_DISPLAY_TYPE 0
#define POS_BRIGHTNESS 2
#define POS_TIME_FORMAT 5
#define POS_ALARM_FLAG 6
#define POS_MEMORY 7
#define POS_CPU_TYPE 9
#define POS_WATER_RESIST 11

#define MASK_DISPLAY_TYPE (0x03 << POS_DISPLAY_TYPE)
#define MASK_BRIGHTNESS (0x07 << POS_BRIGHTNESS)
#define MASK_TIME_FORMAT (0x01 << POS_TIME_FORMAT)
#define MASK_ALARM_FLAG (0x01 << POS_ALARM_FLAG)
#define MASK_MEMORY (0x03 << POS_MEMORY)
#define MASK_CPU_TYPE (0x03 << POS_CPU_TYPE)
#define MASK_WATER_RESIST (0x03 << POS_WATER_RESIST)

PackedDevice *create_packed_device(uint8_t disp, uint8_t bright, uint8_t format,
                                   bool alarm, uint8_t mem, uint8_t cpu,
                                   uint8_t water);
void destroy_packed_device(PackedDevice *device);
void packed_set_brightness(PackedDevice *device, uint8_t brightness);
uint8_t packed_get_brightness(const PackedDevice *device);
void packed_set_alarm(PackedDevice *device, bool status);
bool packed_get_alarm(const PackedDevice *device);
void packed_print_info(const PackedDevice *device);

#endif