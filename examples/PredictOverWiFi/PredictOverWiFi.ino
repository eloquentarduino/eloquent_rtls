/**
* Collect RTLS training data
* using WiFi
*/
#include <eloquent_rtls.h>
#include <eloquent_rtls/wifi.h>
#include "Classifier.h"
#include "FeaturesConverter.h"

using eloq::rtls::wifiScanner;
using eloq::rtls::FeaturesConverter;

Classifier classifier;
FeaturesConverter converter(wifiScanner, classifier);


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

    // print feature vector before predictions
    converter.verbose();

    Serial.println("Move around the mapped space...");
}


/**
 *
 */
void loop() {
    // scan & predict
    Serial.println(converter.predict());
    delay(1000);
}