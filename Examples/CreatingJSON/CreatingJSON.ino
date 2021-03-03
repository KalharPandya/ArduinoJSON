#include<ArduinoJSON.h>
json myObj;
void setup() {
  Serial.begin(115200);
  //Add Key-Value Pair in JSON
  //DataTypes allowed for Key is String 
  //DataTypes allowed for value is Number, Double, String
  myObj.addUnit("Name", "Kalhar");
  myObj.addUnit("Age", 21);
  myObj.addUnit("CPI", 9.15);

  //Getting Elements from JSON
  Serial.println("Name : " + myObj.getValue("Name"));

  //Updates Existing Key
  myObj.updateValue("Name","Kalhar Pandya");
  Serial.println("Name : " + myObj.getValue("Name"));
  
  //You need to Mention Data-Type in Function name if Value is not string
  Serial.println("Age : " + String(myObj.getNumberValue("Age")));
  Serial.println("CPI : " + String(myObj.getDoubleValue("CPI")));

  //Get JSON String Which represents Entire onject
  Serial.println(myObj.getString());

  //Remove Exixting Key from JSON
  myObj.remove("Age");
  Serial.println(myObj.getString());

  //Clear Entire JSON
  myObj.clear();
  Serial.println(myObj.getString());
}

void loop() {

}
