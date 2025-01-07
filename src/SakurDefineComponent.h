
/* definsi komponen untuk OLED */
#define LED_ORI         LED_BUILTIN     // akses led builtin
#define BOUND           115200            // bounding rate 921600
#define SCREEN_WIDTH    128
#define SCREEN_HEIGHT   64
#define SSD1306         SSD1306_SWITCHCAPVCC
#define PORT            0x3C

/* definisi komponen SHT20 */
#define BOUNDRATESHT20  9600 // boundrate untuk SHT20
#define PIN_RX          16   // saya tidak tahu pin yang mana karena belum dapat info jadi sya coba" aja
#define PIN_TX          17   // begitu juga yang ini

/* definisi Sensor LDR */
#define PIN_LDR         14    // begitu juga yang ini, saya tidak ada info.

/* definei pin sensor SOIL MOISTURE */
#define BOUNDRATESOIL   9600
#define PIN_SOIL        34    // ini juga sya tidak ada info jika nomor pin ini yg di pakai
