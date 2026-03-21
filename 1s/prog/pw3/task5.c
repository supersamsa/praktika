#include <stdio.h>

int main() {
    float speed_mbps, file_size_mb, time_seconds;
    
    printf("Введите скорость загрузки в Мбит/с: ");
    scanf("%f", &speed_mbps);
    printf("Введите размер файла в МБ: ");
    scanf("%f", &file_size_mb);
    
    time_seconds = (file_size_mb * 8) / speed_mbps;
    
    printf("%.2f Мбит/с %.2f МБ\n", speed_mbps, file_size_mb);
    printf("Время загрузки: %.2f секунд\n", time_seconds);
    
    return 0;
}
