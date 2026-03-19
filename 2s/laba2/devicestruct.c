#include "devicestruct.h"

BitDevice *create_bit_device(DisplayType disp, int bright, int format,
                             bool alarm, MemorySize mem, CPUType cpu,
                             WaterResistance water) {
  BitDevice *new_device = (BitDevice *)malloc(sizeof(BitDevice));
  if (new_device == NULL) {
    fprintf(stderr, "Ошибка выделения памяти!\n");
    return NULL;
  }

  new_device->display_type = disp;
  new_device->brightness = bright;
  new_device->time_format = format;
  new_device->alarm_flag = alarm ? 1 : 0;
  new_device->memory = mem;
  new_device->cpu_type = cpu;
  new_device->water_resist = water;

  return new_device;
}

void destroy_bit_device(BitDevice *device) {
  if (device != NULL) {
    free(device);
  }
}

void bit_device_set_brightness(BitDevice *device, int brightness) {
  if (device != NULL) {
    device->brightness = brightness & 0x07;
  }
}

int bit_device_get_brightness(const BitDevice *device) {
  return (device != NULL) ? device->brightness : -1;
}

void bit_device_set_alarm(BitDevice *device, bool status) {
  if (device != NULL) {
    device->alarm_flag = status ? 1 : 0;
  }
}

bool bit_device_get_alarm(const BitDevice *device) {
  return (device != NULL) ? (device->alarm_flag != 0) : false;
}

void bit_device_print_info(const BitDevice *device) {
  if (device == NULL)
    return;

  printf("--- Информация об устройстве (битовые поля) ---\n");
  printf("Тип дисплея: %u\n", device->display_type);
  printf("Яркость: %u\n", device->brightness);
  printf("Формат времени: %s\n", device->time_format ? "24ч" : "12ч");
  printf("Будильник: %s\n", device->alarm_flag ? "Вкл" : "Выкл");
  printf("Память: ");
  switch (device->memory) {
  case 0:
    printf("16KB\n");
    break;
  case 1:
    printf("32KB\n");
    break;
  case 2:
    printf("64KB\n");
    break;
  case 3:
    printf("128KB\n");
    break;
  default:
    printf("Unknown\n");
  }
  printf("Процессор: %u\n", device->cpu_type);
  printf("Водостойкость: %u\n", device->water_resist);
  printf("Размер структуры (sizeof): %zu байт\n", sizeof(BitDevice));
}