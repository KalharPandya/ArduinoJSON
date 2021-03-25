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
  myObj.addUnit("Name", "Kalhar Pandya");
  Serial.println("Name Updated");
  Serial.println("Name : " + myObj.getValue("Name"));
  Serial.println();
  //You need to Mention Data-Type in Function name if Value is not string
  Serial.println("Age : " + String(myObj.getNumberValue("Age")));
  Serial.println("CPI : " + String(myObj.getDoubleValue("CPI")));
  Serial.println(); Serial.println();
  //Get JSON String Which represents Entire onject
  Serial.println("Normal String");
  Serial.println(myObj.getString());
  Serial.println();
  //Get JSON String with Escape Chars which allows you to copy paste it to another code
  Serial.println("String With Escape Characters");
  Serial.println(myObj.getString(true));
  Serial.println();

  //Remove Exixting Key from JSON
  Serial.println("Removed Age");
  myObj.remove("Age");
  Serial.println(myObj.getString());
  Serial.println();
  //Clear Entire JSON
  Serial.println("Cleared");
  myObj.clear();
  Serial.println(myObj.getString());
}

void loop() {

}