/**
* Collect RTLS training data
* using WiFi
*/
#include <eloquent_rtls.h>
#include <eloquent_rtls/wifi.h>
#include <eloquent_rtls/collect.h>

using eloq::rtls::Collect;
using eloq::rtls::wifiScanner;

Collect collector(wifiScanner);


/**
 *
 */
void setup() {
    delay(3000);
    Serial.begin(115200);
    Serial.println("__RTLS WIFI__");

    wifiScanner.identifyBySSID();
    // or
    // wifiScanner.identifyByMAC();

    // set lower bound for RSSI
    wifiScanner.discardWeakerThan(-85);

    // print collection instructions
    collector.setup();
}


/**
 *
 */
void loop() {
    // collect data
    collector.loop();
}