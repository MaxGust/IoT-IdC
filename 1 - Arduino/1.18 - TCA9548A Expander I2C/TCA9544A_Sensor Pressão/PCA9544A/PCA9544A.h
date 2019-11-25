#define MUX         0x70  // Multiplexer I2C Address

/********************************************************
* Set the MUX Channel
* If channel = 0XFF, no channel selected
********************************************************/
void mux_channel(byte channel)
{
  byte cRegister = 0x04;  
  cRegister |= channel;
  Wire.beginTransmission(MUX);
  if (channel == 0xFF)
  {
     Wire.write(0x00);      //deselect all channels
  } 
  else 
  {
    Wire.write(cRegister);  //set to selected channel
  }     
  Wire.endTransmission();
}
