#pragma once

namespace eloq {
    namespace rtls {
        class FeaturesConverter {
        public:
            float features[11];

            /**
             * Constructor
             */
            FeaturesConverter(Eloquent::RTLS::Scanner& scanner, Classifier& classifier) :
            _scanner(&scanner),
            _classifier(&classifier),
            _verbose(false) {
                    memset(features, 0, 11);
            }

            /**
             * Toggle verbose output
             * @param enabled
             */
            void verbose(bool enabled = true) {
                _verbose = enabled;
            }

            /**
             * Perform scan and convert to features
             */
            String predict() {
                memset(features, 0, 11);
                _scanner->scan();

                /* build features */
                while (_scanner->hasNext()) {
                    _scanner->next();

                    if (!_scanner->isValid())
                        continue;

                    String identifier = _scanner->identifier();
                    const int16_t rssi = _scanner->rssi();

                    if (identifier == "DIRECT-BA-HP DOMENICO") features[0] = rssi;
                    if (identifier == "FASTWEB-ABCDEF") features[1] = rssi;
                    if (identifier == "Linkem_ABCDEF") features[2] = rssi;
                    if (identifier == "PinguiniWifi") features[3] = rssi;
                    if (identifier == "PosteMobile_ABCDEF_2.4G") features[4] = rssi;
                    if (identifier == "SSID") features[5] = rssi;
                    if (identifier == "Vodafone-ABCDEF") features[6] = rssi;
                    if (identifier == "Vodafone-WiFi") features[7] = rssi;
                    if (identifier == "Wi-Fi_Casa") features[8] = rssi;
                    if (identifier == "Wi-Fi_DiSavino") features[9] = rssi;
                    if (identifier == "Wi-Fi_Ospiti") features[10] = rssi;
                }

                dump();

                /** predict **/
                int prediction = _classifier->predict(features);

                switch (prediction) {
                    case 0: return "bedroom";
                    case 1: return "kitchen";
                    case 2: return "office";
                }

                return "ERROR";
            }

        protected:
            bool _verbose;
            Eloquent::RTLS::Scanner *_scanner;
            Classifier *_classifier;

            /**
             * Print features vector
             */
            void dump() {
                if (!_verbose)
                    return;

                Serial.print("Features: [");
                Serial.print(features[0]);

                for (int i = 1; i < 11; i++) {
                    Serial.print(", ");
                    Serial.print(features[i]);
                }

                Serial.println("]");
            }
        };
    }
}