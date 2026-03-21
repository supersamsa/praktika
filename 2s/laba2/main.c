#include "devicestruct.h"
#include "packeddevice.h"

void demonstrate_alignment() {
  printf("\n=== Демонстрация выравнивания ===\n");
  printf("Размер обычной BitDevice: %zu байт\n", sizeof(BitDevice));
  printf("Размер упакованной BitDevice: %zu байт\n", sizeof(PackedBitDevice));
  printf("(Обычно 4 байта для обычной и 2 байта для упакованной)\n");
}

int main() {
  printf("Лабораторная работа №2 - Управление устройством\n");

  printf("\n========== БИТОВЫЕ ПОЛЯ ==========\n");
  BitDevice *dev1 = create_bit_device(DISPLAY_OLED, 5, 1, true, MEM_64KB,
                                      CPU_STANDARD, WATER_IP67);
  if (dev1) {
    bit_device_print_info(dev1);

    bit_device_set_brightness(dev1, 7);
    bit_device_set_alarm(dev1, false);
    printf("\nПосле изменений (яркость=7, будильник=выкл):\n");
    bit_device_print_info(dev1);

    destroy_bit_device(dev1);
  }

  demonstrate_alignment();

  printf("\n========== ПОБИТОВАЯ АРИФМЕТИКА ==========\n");
  PackedDevice *dev2 = create_packed_device(1, 3, 0, true, 2, 1, 2);
  if (dev2) {
    packed_print_info(dev2);

    packed_set_brightness(dev2, 6);
    packed_set_alarm(dev2, false);
    printf("\nПосле изменений (яркость=6, будильник=выкл):\n");
    packed_print_info(dev2);

    destroy_packed_device(dev2);
  }

  return 0;
}