#ifndef ELOQUENTRTLS_COLLECT_H
#define ELOQUENTRTLS_COLLECT_H

#include "./scanner.h"


namespace Eloquent {
    namespace RTLS {
        /**
         * Help user collect data
         */
        class Collect {
        public:

            /**
             *
             */
            Collect(Scanner& scanner) :
                _scanner(&scanner),
                _location("") {

            }

            /**
             *
             */
            void setup() {
                Serial.println("Move into a location and type 'scan {location}'");
                Serial.println("(where {location} is the name of the room)");
                Serial.println("After you mapped the location, type 'stop'");
            }

            /**
             * Handle user input
             */
            void loop() {
                handleUserInput();

                if (_location == "")
                    return;

                _scanner->scan();
                _scanner->toJSON(Serial, _location);
            }

        protected:
            String _location;
            Scanner *_scanner;

            /**
             *
             */
            void handleUserInput() {
                if (!Serial.available())
                    return;

                String command = Serial.readStringUntil('\n');

                if (command.startsWith("scan ")) {
                    command.replace("scan ", "");
                    command.trim();

                    _location = command;
                    Serial.print("Start scanning ");
                    Serial.print(_location);
                    Serial.println("...");
                }
                else if (command.startsWith("stop")) {
                    _location = "";
                }
                else {
                    Serial.print("Unknown command: ");
                    Serial.println(command);
                }
            }
        };
    }
}

namespace eloq {
    namespace rtls {
        using Collect = Eloquent::RTLS::Collect;
    }
}

#endif //ELOQUENTRTLS_COLLECT_H
