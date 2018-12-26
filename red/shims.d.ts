

    declare namespace radioxx {

        //% help=radioxx/set-transmit-power
        //% weight=9 blockGap=8
        //% blockId=radioxx_set_transmit_power block="radioxx set transmit power %power"
        //% power.min=0 power.max=7
        //% advanced=true shim=radioxx::setTransmitPower
        function setTransmitPower(power: int32): void;
    
       
    }
    

    