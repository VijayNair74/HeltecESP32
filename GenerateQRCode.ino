#include "qrcode.h"
#include "heltec.h"

void setup() {
    Heltec.begin(true, false, true);
    Heltec.display->clear();

    // Create the QR code
    QRCode qrcode;
    const int qrcodeVersion = 3; 
    const int pixelsPerSquare = 2; 
    const int ecc_low = 0;
    
    uint8_t qrcodeData[qrcode_getBufferSize(qrcodeVersion)];
    qrcode_initText(&qrcode, qrcodeData, qrcodeVersion, ecc_low, "HELLO WORLD");

    for (uint8_t y = 0; y < qrcode.size; y++) {
        for (uint8_t x = 0; x < qrcode.size; x++) {
          if (qrcode_getModule(&qrcode, x, y)) {
            for(int xi = x*pixelsPerSquare + 2; xi < x*pixelsPerSquare + pixelsPerSquare + 2; xi++){
              for(int yi= y*pixelsPerSquare + 2; yi < y*pixelsPerSquare + pixelsPerSquare + 2; yi++){
                Heltec.display->setPixel(xi, yi);
              }
            }
          } 
        }
    }
    Heltec.display->display();
}

void loop() {
}
