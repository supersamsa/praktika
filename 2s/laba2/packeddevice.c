#include "packeddevice.h"

PackedDevice *create_packed_device(uint8_t disp, uint8_t bright, uint8_t format,
                                   bool alarm, uint8_t mem, uint8_t cpu,
                                   uint8_t water) {
  PackedDevice *device = (PackedDevice *)malloc(sizeof(PackedDevice));
  if (device == NULL)
    return NULL;

  *device = 0;
  *device |= (disp & 0x03) << POS_DISPLAY_TYPE;
  *device |= (bright & 0x07) << POS_BRIGHTNESS;
  *device |= (format & 0x01) << POS_TIME_FORMAT;
  *device |= (alarm ? 1 : 0) << POS_ALARM_FLAG;
  *device |= (mem & 0x03) << POS_MEMORY;
  *device |= (cpu & 0x03) << POS_CPU_TYPE;
  *device |= (water & 0x03) << POS_WATER_RESIST;

  return device;
}

void destroy_packed_device(PackedDevice *device) { free(device); }

void packed_set_brightness(PackedDevice *device, uint8_t brightness) {
  if (device == NULL)
    return;
  *device =
      (*device & ~MASK_BRIGHTNESS) | ((brightness & 0x07) << POS_BRIGHTNESS);
}

uint8_t packed_get_brightness(const PackedDevice *device) {
  return (uint8_t)((*device & MASK_BRIGHTNESS) >> POS_BRIGHTNESS);
}

void packed_set_alarm(PackedDevice *device, bool status) {
  if (device == NULL)
    return;
  if (status) {
    *device |= MASK_ALARM_FLAG;
  } else {
    *device &= ~MASK_ALARM_FLAG;
  }
}

bool packed_get_alarm(const PackedDevice *device) {
  return (*device & MASK_ALARM_FLAG) != 0;
}

void packed_print_info(const PackedDevice *device) {
  if (device == NULL)
    return;

  printf("--- Информация об устройстве (битовая арифметика) ---\n");
  printf("Сырое значение (hex): 0x%04X\n", *device);
  printf("Тип дисплея: %u\n",
         (*device & MASK_DISPLAY_TYPE) >> POS_DISPLAY_TYPE);
  printf("Яркость: %u\n", packed_get_brightness(device));
  printf("Формат времени: %s\n",
         ((*device & MASK_TIME_FORMAT) >> POS_TIME_FORMAT) ? "24ч" : "12ч");
  printf("Будильник: %s\n", packed_get_alarm(device) ? "Вкл" : "Выкл");
  printf("Память: %u\n", (*device & MASK_MEMORY) >> POS_MEMORY);
  printf("Процессор: %u\n", (*device & MASK_CPU_TYPE) >> POS_CPU_TYPE);
  printf("Водостойкость: %u\n",
         (*device & MASK_WATER_RESIST) >> POS_WATER_RESIST);
  printf("Размер структуры (sizeof): %zu байт\n", sizeof(*device));
}