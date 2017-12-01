
/* Farbpalette des Bildes. Jede Farbe ist 8-Bit kodiert. Das Bild verf�gt ueber 16 verschiedene
   Farben.
   Achtung: Die Farbe mit dem Index 0 ist die Hintergrundfarbe! */

const unsigned char FarbTabelle[16] =
{
   0xFF, 0xFC, 0x00, 0xB6, 0x91, 0x44, 0xC0, 0xAC, 0xAC, 0x68, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00 
};

/* Pixeldaten des Bildes. Es handelt sich um ein Bild der Groesse 66 x 82 Pixel	(X x Y).
   Die Pixeldaten sind als Indizes in die FarbTabelle zu interpretieren. Jedes Halb-Byte (4Bit)
   kodiert genau ein Pixel. Die Daten sind nicht komprimiert.
   66 x 82 = 5412 Pixel. Jeweils 1 Byte fuer 2 Pixel => 2706 Bytes */ 
const unsigned char Bild1[2706] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x66, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x66, 
      0x66, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x66, 0x66, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 
      0x66, 0x66, 0x66, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x56, 0x66, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 
      0x66, 0x66, 0x66, 0x66, 0x66, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x26, 0x66, 0x66, 0x66, 0x66, 0x66, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x66, 0x66, 0x66, 0x66, 0xA6, 0x40, 0x00, 0x00, 
      0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x66, 0x66, 0x66, 0x62, 0x66, 0x50, 0x00, 
      0x00, 0x05, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x66, 0x66, 0x66, 0x6A, 0x66, 0x00, 
      0x00, 0x00, 0x06, 0x66, 0x66, 0xA4, 0x44, 0x44, 0x44, 0x4A, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x66, 0x66, 0x66, 0x66, 0x62, 
      0x00, 0x00, 0x00, 0x26, 0x66, 0x94, 0x33, 0x00, 0x00, 0x03, 0x33, 0x44, 0x90, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x66, 0x66, 0x66, 0x66, 
      0x60, 0x00, 0x00, 0x00, 0x66, 0x64, 0x33, 0x00, 0x33, 0x30, 0x00, 0x00, 0x03, 0x44, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x66, 0x66, 0x66, 
      0xA5, 0xA0, 0x00, 0x00, 0x00, 0x66, 0x64, 0x00, 0x03, 0x44, 0x43, 0x00, 0x00, 0x00, 0x03, 0x40, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x24, 0x33, 
      0x33, 0x33, 0x40, 0x00, 0x00, 0x03, 0x66, 0x23, 0x34, 0x44, 0x77, 0x74, 0x30, 0x00, 0x00, 0x03, 
      0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23, 0x30, 
      0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x0A, 0x66, 0x64, 0xA7, 0x77, 0x77, 0x72, 0x43, 0x30, 0x00, 
      0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 
      0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x02, 0x66, 0xA7, 0x0A, 0x47, 0x77, 0x77, 0x54, 0x43, 
      0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 
      0x30, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x02, 0x66, 0x77, 0x04, 0x37, 0x78, 0x87, 0x47, 
      0xA3, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x05, 0x30, 0x03, 0x33, 0x34, 0x43, 0x33, 0x00, 0x00, 0x06, 0xA2, 0x78, 0x77, 0x77, 0x77, 0x20, 
      0x77, 0x74, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x30, 0x34, 0x56, 0x66, 0x66, 0x64, 0x00, 0x00, 0x06, 0x44, 0x77, 0x77, 0x78, 0x77, 
      0x77, 0x77, 0x74, 0x30, 0x03, 0x33, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x53, 0x56, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00, 0xA6, 0x40, 0x34, 0xAA, 0x77, 
      0x77, 0x77, 0x87, 0x75, 0x33, 0x34, 0x42, 0xA9, 0x99, 0x99, 0x99, 0xA9, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x02, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00, 0x56, 0x20, 0x00, 0x00, 
      0x33, 0x42, 0x77, 0x87, 0x74, 0x34, 0x45, 0xA9, 0x99, 0x99, 0x99, 0x99, 0x99, 0x92, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x05, 0x66, 0x4A, 0x44, 
      0x95, 0x53, 0x03, 0x42, 0x5A, 0x33, 0x45, 0x59, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x93, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x22, 0x62, 0x33, 
      0x34, 0x65, 0x52, 0x30, 0x00, 0x00, 0x04, 0x5A, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 
      0x99, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x25, 0x23, 
      0x30, 0x34, 0x66, 0x66, 0x44, 0x30, 0x33, 0x45, 0xA9, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 
      0x99, 0x99, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x64, 
      0x33, 0x00, 0x03, 0x26, 0xA4, 0x33, 0x42, 0x56, 0x66, 0x25, 0x55, 0x5A, 0xA9, 0x99, 0x99, 0x99, 
      0x99, 0x99, 0x99, 0x99, 0x20, 0x00, 0x00, 0x00, 0x00, 0x06, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 
      0x43, 0x00, 0x00, 0x03, 0x33, 0x33, 0x03, 0x46, 0x66, 0x66, 0x66, 0x66, 0x66, 0x25, 0xA9, 0x99, 
      0x99, 0x99, 0x99, 0x99, 0x99, 0x95, 0x00, 0x00, 0x00, 0x00, 0x06, 0x66, 0x66, 0x66, 0x66, 0x66, 
      0x64, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x56, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x25, 
      0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x00, 0x00, 0x00, 0x00, 0x05, 0x66, 0x66, 0x66, 0x66, 
      0x66, 0x63, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x66, 0x66, 0x66, 0x66, 0x62, 0x34, 0x46, 
      0x66, 0x59, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0xA0, 0x00, 0x00, 0x00, 0x02, 0x66, 0x66, 0x66, 
      0x66, 0x66, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x66, 0x66, 0x66, 0x66, 0x66, 0x33, 
      0x34, 0x66, 0x65, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x9A, 0x00, 0x00, 0x00, 0x00, 0x66, 0x66, 
      0x66, 0x66, 0x64, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x29, 0x56, 0x66, 0x66, 0x66, 
      0x30, 0x03, 0x46, 0x66, 0x59, 0x99, 0x99, 0x9A, 0xA9, 0x99, 0x99, 0x00, 0x00, 0x00, 0x00, 0x46, 
      0x66, 0x66, 0x66, 0x66, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x99, 0x95, 0x66, 0x66, 
      0x65, 0x30, 0x03, 0x46, 0x66, 0x2A, 0x99, 0x9A, 0xAA, 0xAA, 0xA9, 0x99, 0x40, 0x00, 0x00, 0x00, 
      0x00, 0x56, 0x66, 0x66, 0x66, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3A, 0x99, 0x99, 0x66, 
      0x66, 0x64, 0x30, 0x03, 0x46, 0x66, 0x65, 0x99, 0xAA, 0xAA, 0xAA, 0xA9, 0x99, 0x50, 0x00, 0x00, 
      0x00, 0x00, 0x03, 0x56, 0x66, 0x6A, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xA5, 0xA9, 0x99, 
      0xA6, 0x66, 0x43, 0x30, 0x03, 0x46, 0x66, 0x65, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x99, 0x90, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x24, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3A, 0x55, 0x55, 
      0x99, 0x55, 0x44, 0x33, 0x00, 0x03, 0x26, 0x66, 0x66, 0x5A, 0xAA, 0xAA, 0xAA, 0xAA, 0x99, 0x99, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x35, 0x55, 
      0x55, 0x23, 0x33, 0x33, 0x00, 0x00, 0x34, 0x66, 0x66, 0x66, 0x5A, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 
      0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x30, 0x00, 0x00, 0x00, 0x00, 0x33, 0x46, 
      0x6A, 0xAA, 0x53, 0x00, 0x00, 0x00, 0x03, 0x35, 0x66, 0x66, 0x66, 0x5A, 0xAA, 0xAA, 0xAA, 0xAA, 
      0xA9, 0x9A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x66, 0x43, 0x30, 0x00, 0x00, 0x33, 0x32, 
      0x66, 0x66, 0x66, 0x53, 0x00, 0x00, 0x00, 0x33, 0x26, 0x66, 0x66, 0x66, 0x5A, 0xAA, 0xAA, 0xAA, 
      0xAA, 0xA9, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x66, 0x44, 0x33, 0x33, 0x33, 0x42, 
      0x66, 0x66, 0x66, 0x66, 0x23, 0x00, 0x00, 0x03, 0x39, 0x66, 0x66, 0x66, 0x66, 0x5A, 0xAA, 0xAA, 
      0xAA, 0xAA, 0xA9, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x62, 0x44, 0x4A, 0x22, 0x56, 
      0x66, 0x66, 0x66, 0x66, 0x66, 0x53, 0x00, 0x00, 0x33, 0x46, 0x66, 0x66, 0x66, 0x65, 0x5A, 0xAA, 
      0xAA, 0xAA, 0xAA, 0xAA, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x27, 0x17, 0x46, 0x66, 
      0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x64, 0x30, 0x03, 0x34, 0x66, 0x66, 0x66, 0x66, 0x65, 0xAA, 
      0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x18, 0x17, 0x75, 
      0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x65, 0x43, 0x34, 0x56, 0x66, 0x66, 0x66, 0x66, 0x55, 
      0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x55, 0x75, 0x55, 
      0x75, 0x55, 0xA6, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x62, 0x26, 0x25, 0x66, 0x66, 0x66, 0x62, 
      0x5A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x57, 0x15, 
      0x51, 0x15, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x66, 0x62, 
      0x5A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x61, 
      0x75, 0x57, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
      0xAA, 0x99, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 
      0x61, 0x77, 0x11, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
      0x59, 0x99, 0x99, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0xA6, 0x64, 0x49, 0x15, 0x66, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
      0x55, 0x2A, 0x99, 0x99, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0x92, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x66, 0x24, 0x44, 0x46, 0x66, 0x66, 0x66, 0xA2, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x52, 
      0x66, 0x66, 0x62, 0x99, 0x99, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0x95, 0x00, 0x00, 0x00, 
      0x00, 0x02, 0x66, 0x44, 0x43, 0x46, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 
      0x66, 0x66, 0x66, 0x66, 0x59, 0x99, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x99, 0x90, 0x00, 0x00, 
      0x00, 0x00, 0x56, 0x66, 0x44, 0x43, 0x46, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 
      0x66, 0x66, 0x66, 0x66, 0x66, 0x6A, 0x99, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x99, 0xA0, 0x00, 
      0x00, 0x00, 0x54, 0x26, 0x62, 0x34, 0x40, 0x46, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 
      0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xA9, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x99, 0x20, 
      0x00, 0x00, 0x00, 0x43, 0x46, 0x64, 0x34, 0x40, 0x4A, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 
      0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x62, 0x59, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 0x99, 
      0x00, 0x00, 0x00, 0x00, 0x33, 0x46, 0x24, 0x34, 0x40, 0x32, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 
      0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x65, 0x44, 0x59, 0x9A, 0xAA, 0xAA, 0xAA, 0xAA, 0xA9, 
      0x92, 0x00, 0x00, 0x00, 0x00, 0x30, 0x34, 0x43, 0x34, 0x40, 0x34, 0x66, 0x66, 0x66, 0x66, 0x66, 
      0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x62, 0x44, 0x34, 0x59, 0x99, 0xAA, 0xAA, 0xAA, 0xAA, 
      0x99, 0x90, 0x00, 0x00, 0x00, 0x00, 0x40, 0x34, 0x33, 0x40, 0x40, 0x34, 0x66, 0x66, 0x66, 0x66, 
      0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x2A, 0x44, 0x33, 0x34, 0x59, 0x99, 0x9A, 0xAA, 0xAA, 
      0xA9, 0x99, 0x90, 0x00, 0x00, 0x00, 0x00, 0x43, 0x00, 0x03, 0x49, 0x30, 0x03, 0x26, 0x66, 0x66, 
      0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x25, 0x44, 0x43, 0x30, 0x00, 0x3A, 0x99, 0x99, 0x99, 0xAA, 
      0xAA, 0x99, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x30, 0x03, 0x3A, 0x30, 0x03, 0x46, 0x66, 
      0x66, 0x66, 0x66, 0x92, 0x25, 0x44, 0x44, 0x33, 0x33, 0x00, 0x00, 0x03, 0x45, 0x99, 0x99, 0x99, 
      0x99, 0x99, 0x99, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x30, 0x03, 0x04, 0x30, 0x00, 0x34, 
      0x44, 0x44, 0x44, 0x44, 0x43, 0x33, 0x33, 0x30, 0x00, 0x00, 0x00, 0x00, 0x34, 0x2A, 0x99, 0x99, 
      0x99, 0x99, 0x99, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x04, 0x00, 0x40, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x33, 0x42, 0x59, 0x99, 
      0x99, 0x99, 0x99, 0x99, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x44, 0x00, 0x43, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x33, 0x44, 0x92, 0x5A, 0x99, 
      0x99, 0x99, 0x99, 0x99, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x43, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x66, 0x6A, 0x99, 
      0x99, 0x99, 0x99, 0x99, 0x99, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x02, 0x94, 0x92, 0xA6, 0xA2, 0x44, 0x44, 0x45, 0xA6, 0xA5, 0xA6, 0x66, 0x66, 0x66, 0x6A, 
      0x99, 0x99, 0x99, 0x99, 0x99, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x06, 0x66, 0x66, 0x66, 0x66, 0x66, 0x25, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 
      0x60, 0xA2, 0xA9, 0x9A, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x06, 0x66, 0x66, 0x66, 0x66, 0x66, 0x52, 0x66, 0x66, 0x66, 0x66, 0x66, 
      0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x66, 0x66, 0x66, 0x66, 0x66, 0x60, 0xA6, 0x66, 0x66, 0x66, 
      0x62, 0x88, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x72, 0x56, 0x66, 0x66, 0x65, 0x24, 0x00, 0x87, 0x77, 
      0x77, 0x77, 0x77, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x00, 0x87, 
      0x77, 0x77, 0x77, 0x77, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x00, 
      0x88, 0x77, 0x77, 0x77, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x77, 0x88, 0x88, 0x88, 0x88, 0x8A, 
      0x00, 0x08, 0x87, 0x77, 0x78, 0x88, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x52, 0x22, 0x25, 0x92, 
      0x00, 0x00, 0x05, 0x55, 0x98, 0x8A, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x77, 0x88, 0x88, 0x88, 
      0x82, 0x00, 0x00, 0x04, 0x88, 0x77, 0x77, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x77, 0x88, 0x88, 
      0x88, 0x85, 0x00, 0x00, 0x00, 0x88, 0x77, 0x77, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x77, 0x88, 
      0x88, 0x88, 0x85, 0x00, 0x00, 0x00, 0x87, 0x77, 0x77, 0x89, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 
      0x88, 0x88, 0x88, 0x82, 0x00, 0x00, 0x00, 0x87, 0x77, 0x77, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x77, 0x77, 
      0x88, 0x88, 0x88, 0x88, 0x82, 0x00, 0x00, 0x00, 0x88, 0x77, 0x77, 0x88, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x77, 0x77, 
      0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x00, 0x00, 0x00, 0x88, 0x77, 0x77, 0x88, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x77, 
      0x77, 0x77, 0x78, 0x88, 0x88, 0x88, 0x85, 0x00, 0x00, 0x00, 0x82, 0x77, 0x77, 0xA8, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 
      0x88, 0x77, 0x78, 0x88, 0x88, 0x88, 0x95, 0xAA, 0x30, 0x00, 0x00, 0x27, 0x77, 0x77, 0x77, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x0A, 0x28, 0x88, 0x88, 0x88, 0x82, 0xAA, 0xAA, 0xA2, 0x00, 0x00, 0x00, 0x77, 0x77, 0x77, 0x77, 
      0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x2A, 0xAA, 0xAA, 0xAA, 0xA2, 0x30, 0x20, 0x00, 0x00, 0x00, 0x02, 0x87, 0x77, 0x77, 
      0x78, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x58, 0x88, 
      0x88, 0x88, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 
      0x2A, 0x92, 0x5A, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x35, 0x25, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00};
