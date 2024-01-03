#ifndef ELOQUENTRTLS_SCANNER_H
#define ELOQUENTRTLS_SCANNER_H

#include "./exception.h"

using Eloquent::Error::Exception;


namespace Eloquent {
    namespace RTLS {
        /**
         * Hardware-independent scanner
         */
        class Scanner {
        public:

            /**
             * Perform scan
             * @return
             */
            virtual Exception& scan() = 0;

            /**
             * Test if there are more scan results to consume
             * @return
             */
            virtual bool hasNext() = 0;

            /**
             * Consume next scan result
             */
            virtual void next() = 0;

            /**
             * Get current identifier
             * @return
             */
            virtual String identifier() = 0;

            /**
             * Get current signal strength
             * @return
             */
            virtual int16_t rssi() = 0;

            /**
             * Discard readings weaker than given value
             * @param rssi
             */
            virtual void discardWeakerThan(int16_t rssi) {
                _minRSSI = rssi;
            }

            /**
             *
             * @return
             */
            virtual bool isValid() {
                return rssi() >= _minRSSI;
            }

            /**
             * Print scan results as JSON
             * @tparam Stream
             * @param stream
             */
            template<typename Stream>
            void toJSON(Stream& stream, String location = "") {
                uint8_t count = 0;

                stream.print('{');

                if (location != "") {
                    stream.print("\"__location\":\"");
                    stream.print(location);
                    stream.print("\",");
                }

                while (hasNext()) {
                    next();

                    if (!isValid())
                        continue;

                    if (count > 0)
                        stream.print(',');

                    stream.print('"');
                    stream.print(identifier());
                    stream.print('"');
                    stream.print(':');
                    stream.print(rssi());
                    count += 1;
                }

                stream.print("}\n");
            }

        protected:
            int16_t _minRSSI = -9999;

            /**
             * Reset scan results
             */
            virtual void reset() = 0;
        };
    }
}

#endif //ELOQUENTRTLS_SCANNER_H
