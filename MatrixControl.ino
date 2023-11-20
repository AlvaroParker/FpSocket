#include "Arduino_LED_Matrix.h"


ArduinoLEDMatrix matrix;

const int LENGTH = 8;
const int WIDTH = 12;

uint8_t frame[LENGTH][WIDTH] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void setBit(int x, int y) {
    if (x < 0 || x > WIDTH - 1 || y < 0 || y > LENGTH - 1) {
        return;
    }
    frame[y][x] = !frame[y][x];
}
void renderBitMap(){
    matrix.renderBitmap(frame, LENGTH, WIDTH);
}

void beginMatrix() {
  matrix.begin();
  delay(2000);
}