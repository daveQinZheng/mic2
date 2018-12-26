#include "pxt.h"

using namespace pxt;


//% color=#E3008C weight=96 icon="\uf012"
namespace radioxx {

    // -------------------------------------------------------------------------
    // radioxx
    // -------------------------------------------------------------------------
    bool radioxxEnabled = false;
    bool transmitSerialNumber = false;

    PacketBuffer packet;

    uint8_t type;
    uint32_t time;
    uint32_t serial;
    int ivalue;
    double dvalue;
    String msg; // may be NULL before first packet
    Buffer bufMsg; // may be NULL before first packet

    int radioxxEnable() {
        int r = uBit.radio.enable();
        if (r != MICROBIT_OK) {
            uBit.panic(43);
            return r;
        }
        if (!radioxxEnabled) {
            uBit.radio.setGroup(pxt::programHash());
            uBit.radio.setTransmitPower(6); // start with high power by default
            radioxxEnabled = true;
        }
        return r;
    }

   
    /**
     * Change the output power level of the transmitter to the given value.
    * @param power a value in the range 0..7, where 0 is the lowest power and 7 is the highest. eg: 7
    */
    //% help=radioxx/set-transmit-power
    //% weight=9 blockGap=8
    //% blockId=radioxx_set_transmit_power block="radioxx set transmit power %power"
    //% power.min=0 power.max=7
    //% advanced=true
    void setTransmitPower(int power) {
        if (radioxxEnable() != MICROBIT_OK) return;
        uBit.radio.setTransmitPower(power);
    }

}
