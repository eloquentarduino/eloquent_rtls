# RTLS (Real Time Location System) for Arduino

This library allows you to integrate RTLS into your Arduino projects.

It tries to stay hardware-independent, so it would work with:

 - WiFi
 - Bluetooth
 - Zigbee
 - Decawave 1000
 - ...

At the current state, WiFi is implemented. You can refer to it 
to implement more hardware.

## How to use

The process is made by two steps.

### Collect training data

You will load this sketch and more around the space you want to map.
You need to collect data for each room/zone you want to recognize.

```cpp
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
```

### Prediction

Once you have your data, go to [this webpage](https://eloquentarduino.com/arduino-indoor-positioning/)
and train a classifier (it is done in the cloud, you only have to press a button).

It will generate the required files to perform the inference.

```cpp
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
```