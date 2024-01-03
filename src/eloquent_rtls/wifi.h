#ifndef ELOQUENTRTLS_WIFI_H
#define ELOQUENTRTLS_WIFI_H

#include <WiFi.h>
#include "./scanner.h"

using Eloquent::Error::Exception;


namespace Eloquent {
    namespace RTLS {
        class WiFiScanner : public Scanner {
        public:
            Exception exception;

            /**
             *
             */
            WiFiScanner() :
                exception("WiFiScanner"),
                _identifyBy("ssid"),
                _i(-1),
                _numNetworks(0) {

            }

            /**
             * Identify networks by SSID
             */
            void identifyBySSID() {
                _identifyBy = "ssid";
            }

            /**
             * Identify networks by MAC address
             */
            void identifyByMAC() {
                _identifyBy = "mac";
            }

            /**
             *
             * @return
             */
            Exception& scan() {
                this->reset();
                _numNetworks = WiFi.scanNetworks();

                return exception.clear();
            }

            /**
             *
             * @return
             */
            bool hasNext() {
                return _numNetworks > 0 && _i < _numNetworks - 1;
            }

            /**
             *
             */
            void next() {
                _i += 1;
            }

            /**
             *
             * @return
             */
            String identifier() {
                // SSID
                if (_identifyBy == "ssid") {
                    return WiFi.SSID(_i);
                }
                // MAC address
                else {
                    uint8_t *bssid = WiFi.BSSID(_i);

                    return  this->hex(bssid[0]) + ":" +
                            this->hex(bssid[1]) + ":" +
                            this->hex(bssid[2]) + ":" +
                            this->hex(bssid[3]) + ":" +
                            this->hex(bssid[4]) + ":" +
                            this->hex(bssid[5]) + ":" +
                            this->hex(bssid[6]);
                }
            }

            /**
             *
             * @return
             */
            int16_t rssi() {
                return WiFi.RSSI(_i);
            }

        protected:
            int8_t _i;
            uint8_t _numNetworks;
            String _identifyBy;

            /**
             *
             */
            void reset() {
                _i = -1;
                _numNetworks = 0;
            }

            /**
             * Convert byte to hex string
             * @param byte
             * @return
             */
            String hex(uint8_t byte) {
                const char alphabet[17] = "0123456789ABCDEF";
                const char a = alphabet[byte >> 4];
                const char b = alphabet[byte & 0b1111];

                return String(a) + String(b);
            }
        };
    }
}

namespace eloq {
    namespace rtls {
        static Eloquent::RTLS::WiFiScanner wifiScanner;
    }
}

#endif //ELOQUENTRTLS_WIFI_H