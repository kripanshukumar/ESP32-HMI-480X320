void clr(uint8_t r, uint8_t g, uint8_t b) {
  color = tft.color565(r, g, b);
}

void clr16(uint16_t c) {
  color = c;
}

void scr(int r, int g, int b) {
  tft.fillScreen(tft.color565(r, g, b));
}
void scr16(uint16_t c) {
  tft.fillScreen(c);
}

void Tsize(uint8_t s) {
  tft.setTextSize(s);
}

void Font(int fl) {
  switch (fl) {
    case 1:
      
      if (cx < 1) {
        tft.setTextFont(2);
        fontwidth = 5;
      }
      else {
        tft.setFreeFont(FMB9);
        fontwidth = 5.5;
      }
      break;

    case 2:
      
      if (cx < 1) {
        tft.setFreeFont(FMB9);
        fontwidth = 5;
      }
      else {
        tft.setFreeFont(FMB12);
        fontwidth = 7;
      }
      break;

    case 3:
      
      if (cx < 1) {
        tft.setFreeFont(FMB12);
        fontwidth = 10;
      }
      else {
        tft.setFreeFont(FMB18);
        fontwidth = 11;
      }
      break;

    case 4:
      tft.setFreeFont(FMB24);
      break;
  }
}
void Tclr(uint16_t c) {
  tft.setTextColor(c);
}
void BTclr(uint8_t r, uint8_t g, uint8_t b, uint8_t r1, uint8_t g1, uint8_t b1) {
  tft.setTextColor(tft.color565(r, g, b), tft.color565(r1, g1, b1));
}

void text(String t, int x1, int y1 ) {
  tft.drawString(t, x1 * cx, y1 * cy);
}

void rect(int x1, int y1, int x2, int y2) {
  tft.drawRect(x1 * cx, y1 * cy, x2 * cx, y2 * cy, color);
}

void Rrect(int x1, int y1, int x2, int y2, int c) {
  tft.drawRoundRect(x1 * cx, y1 * cy, x2 * cx, y2 * cy, c, color);
}

void Srect(int x1, int y1, int x2, int y2) {
  tft.fillRect(x1 * cx, y1 * cy, x2 * cx, y2 * cy, color);
}

void SRrect(int x1, int y1, int x2, int y2, int c) {
  tft.fillRoundRect(x1 * cx, y1 * cy, x2 * cx, y2 * cy, c, color);
}

void circle(int x1, int y1, int r) {
  tft.drawCircle(x1 * cx, y1 * cy, r, color);
}

void Scircle(int x1, int y1, int r) {
  tft.fillCircle(x1 * cx, y1 * cy, r, color);
}

void triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
  tft.drawTriangle(x1 * cx, y1 * cy, x2 * cx, y2 * cy, x3 * cx, y3 * cy, color);
}

void Striangle(int x1, int y1, int x2, int y2, int x3, int y3) {
  tft.fillTriangle(x1 * cx, y1 * cy, x2 * cx, y2 * cy, x3 * cx, y3 * cy, color);
}

void ellipse(int x1, int y1, int x2, int y2) {
  tft.drawEllipse(x1 * cx, y1 * cy, x2 * cx, y2 * cy, color);
}

void Sellipse(int x1, int y1, int x2, int y2) {
  tft.fillEllipse(x1 * cx, y1 * cy, x2 * cx, y2 * cy, color);
}

void pixel(int x1, int y1) {
  tft.drawPixel(x1 * cx, y1 * cy, color);
}

void line( int x1, int y1, int x2, int y2) {
  tft.drawLine(x1 * cx, y1 * cy, x2 * cx, y2 * cy, color);
}

void vline(int x1, int y1, int h) {
  tft.drawFastVLine(x1 * cx, y1 * cy, h, color);
}

void hline(int x1, int y1, int h) {
  tft.drawFastHLine(x1 * cx, y1 * cy, h, color);
}

void optionbar() {
  uint16_t tempclr = color;
  clr16(TFT_WHITE);
  SRrect(10, 10, 30, 4, 2);
  SRrect(10, 18, 30, 4, 2);
  SRrect(10, 26, 30, 4, 2);
  color = tempclr;
}

void initScreen() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  clr(1, 90, 84);
  spr.createSprite(64, 64);
  spr.fillRect(0, 0, 64, 64, color);
  clr16(theme);
  spr.fillRect(0, 4, 60, 58, color);
  clr16(TFT_WHITE);
  spr.fillRoundRect(20, 28, 36, 6, 3, color);
  spr.fillTriangle(10, 31, 31, 19, 31, 44, color);


  clr(1, 90, 84);
  spr1.createSprite(48, 48);
  spr1.fillRect(0, 0, 48, 48, color);
  clr16(theme);
  spr1.fillRect(0, 4, 44, 42, color);
  clr16(TFT_WHITE);
  spr1.fillRoundRect(15, 21, 27, 4, 3, color);
  spr1.fillTriangle(7, 23, 23, 14, 23, 33, color);

}

void backicon(int x1, int y1) {
  if (cx == 1) {
    spr.pushSprite(x1, y1);
  }
  if (cx < 1) {
    spr1.pushSprite(x1, y1);
  }
}
