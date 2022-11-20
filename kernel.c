#define VGA_ADRESS 0xB8000

//int _t
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed long int32_t;
typedef signed long long int_64_t;

//uint _t
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint_64_t;

int SCREEN_WIDE = 80;
int SCREEN_HIGH = 80;

int pointerPosition = 0;
uint8_t* g_ScreenBuffer = (uint8_t*)VGA_ADRESS;
void puts(char what, int wo) { //Puts with static position
    g_ScreenBuffer[wo] = what;
    pointerPosition = wo+1;
}

void put(char what) { //Puts with dynamic position
    g_ScreenBuffer[pointerPosition] = what;
    pointerPosition += 1;
}

void clearScreen() {
    for (uint8_t x = 0; x < SCREEN_WIDE; x++) {
        for (uint8_t y = 0; y < SCREEN_HIGH; y++) {
            puts('\0', x+y);
        }
    }
}
void grafics_init(void) {
    /*init grafiks*/
    clearScreen();
}
void kernel_early(void) {
    /*Bevor Main*/
    grafics_init();
    main();
}
int main(void) {
    /*Main Kernel*/
    put('O');
    put('S');
}