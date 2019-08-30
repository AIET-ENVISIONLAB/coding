  //Comparing DHT11 and DHT22 test for data logging.
  
  #include <dht.h>   // dht library
  #include <SPI.h>   
  #include <SD.h>    //sd library
  
  
  unsigned long int milli_time;
  
  int chk_dht11=0;
  int chk_dht22=0;
   
  dht DHT;
  
  File dataLogTest;          //initialise file name.
  
  const int chipSelect = 10; 
  
  
  #define DHT11_PIN 6     // connect dht11 data pin to 6
  #define DHT22_PIN 5     // connect dht22 data pin to 5
  
  
  
  void setup()
  {
    Serial.begin(9600);
    Serial.println("Time , Temp , Humidity");
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
    }
  
  
    Serial.print("Initializing SD card...");
  
    // see if the card is present and can be initialized:
    if (!SD.begin(chipSelect)) {
    
    // don't do anything more:
    while (1);
    }
    Serial.println("card initialized.");
  
  }
  
  
  
  
  void loop()
  {
    int chk_dht11 = DHT.read(DHT11_PIN);
    int chk_dht22 = DHT.read(DHT22_PIN);
    dataLogTest = SD.open("DHTTEST1.csv",FILE_WRITE);   //creates and opens file by name DHTTEST1.csv 
    ++milli_time;
    float temp_buff11=DHT.temperature;      //reads tempreature and stores in temp_buff
    float hum_buff11=DHT.humidity;          //reads humidity and stores in hum_buff
    
    float temp_buff22=DHT.temperature;      //reads tempreature and stores in temp_buff
    float hum_buff22=DHT.humidity;          //reads humidity and stores in hum_buff
   
    delay(1000);
    if(dataLogTest)             //if open 
    {
    
    dataLogTest.print(milli_time);       //prints time in file 
    dataLogTest.print(" , ");     
    dataLogTest.print(temp_buff11);      //prints tempreature in file 
    Serial.print(temp_buff11);
    dataLogTest.print(" ,  ");
    dataLogTest.print(hum_buff11);         //prints humidity in file
    Serial.print(temp_buff11);
    dataLogTest.print(" ,  ");
    dataLogTest.print(temp_buff22);        //prints tempreature in file
    Serial.print(temp_buff11);
    dataLogTest.print(" ,  ");
    dataLogTest.println(hum_buff22);      //prints humidity in file
    Serial.println(temp_buff11);
  
    dataLogTest.close();                 //close  file DHTTEST1.csv
    }
    
  }
