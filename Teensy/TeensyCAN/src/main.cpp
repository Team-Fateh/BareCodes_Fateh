#include <FlexCAN_T4.h>

FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;
FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> can2;
CAN_message_t msg;
int32_t packetSize;
int32_t packId;
#define RPM_PKT_ID 218099784
#define TEMPBATT_PKT_ID 218101064
int32_t rMSB=0,rLSB=0;
int32_t tMSB=0,tLSB=0;
int32_t vMSB=0,vLSB=0;
int32_t RPM;
float temp;
float volts;
int _rxLength;
int _rxIndex;
uint8_t _rxData[8];

int available()
{
  return (_rxLength - _rxIndex);
}

int Cread()
{
  if (!available()) {
    return -1;
  }

  return _rxData[_rxIndex++];
}

void setup(void) {
  can1.begin();
  can1.setBaudRate(1000000);
}

void loop() {
  can1.read(msg);
  for ( uint8_t i = 0; i < 8; i++ ) {
    _rxData[i]=msg.buf[i];
  }
  _rxLength=msg.len;
  packId=msg.id;

  if(packId==RPM_PKT_ID){                                        //RPM_PKT_ID 218099784
      int d=0;
      _rxIndex=0;
      while (available()){
        if (d==0){                            //0th and 1st Byte are RPM data
                d++;
                rLSB=(int)Cread();
            }
        if (d==1){
                d++;
                rMSB=(int)Cread();
            }
       Cread(),d++;
      }
      RPM=((rMSB*255)+rLSB);  
    }  
  if(packId==TEMPBATT_PKT_ID){                                       
      int e=0;
      _rxIndex=0;
      while (available()){
        
        if (e==0){                            //0th and 1st Byte are RPM data
                e++;
                vLSB=(int)Cread();
            }
        if (e==1){
                e++;
                vMSB=(int)Cread();
            }
        if (e==4){                            
                e++;
                tLSB= (int)Cread();
            }
        if (e==5){
                e++;
                tMSB=(int)Cread();
            }
        Cread(),e++;
      }
      temp =((tMSB*256)+tLSB)*0.1;
      volts =((vMSB*256)+vLSB)*0.01;   
      }
Serial.print(RPM);
Serial.print(" ");
Serial.print(temp);
Serial.print(" ");
Serial.println(volts); 
  }
 
  

  
