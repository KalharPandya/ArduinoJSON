#include <ArduinoJSON.h>
void setup()
{
  //See CreateJson before seeing this example

  //*NOTE* Here \ needs to be added when you want to type " into the String
  //While String is not typed, for example Recieved from network or Another Variable,
  //it doesnt require / before "
  String jsonString = "{\"Name\":\"Kalhar Pandya\",\"Age\":21,\"CPI\":9.15}";

  //parseJSON will convert proper String into JSON object
  //On Which we call apply all the functions of JSON

  Serial.begin(115200);
  if (isJsonString(jsonString))
  {
    json myObj = parseJSON(jsonString);
    Serial.println("Name : " + myObj.getValue("Name"));
    Serial.println("Age : " + String(myObj.getNumberValue("Age")));
    Serial.println("CPI : " + String(myObj.getDoubleValue("CPI")));
  }
  else
    Serial.println("JSON dede");
}

void loop()
{
}