#include "JsonType/JsonType.h"
json parsed;
int knowTokenType(String token){
    bool isNumber = true;
    bool isDouble = true;
    bool isString = true;
    for(int i = 0 ; i < token.length(); i ++){
        if(!isDigit(token[i])){
            isNumber = false;
            if(token[i]!='.'){
                isDouble = false;
                return STRING;
            }
        }
    }
    if(isNumber)
        return NUMBER;
    if(isDouble)
        return DOUBLE;
    if(isString)
        return STRING;
    return -1;
}

long getNumber(String token){
    long result = 0;
    for(int i =0;i< token.length(); i ++){
        result= result*10 + (token[i]-'0');
    }
    return result;
}
double getDouble(String token){
    return token.toDouble();
}

String strSplit(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
void createUnit(String token){
    String key = strSplit(token,':',0);
    String value = strSplit(token,':',1);
    switch (knowTokenType(value))
    {
    case STRING:
    
        value.remove(0,1);
        value.remove(value.length()-1,1);
        parsed.addUnit(key,value);
        break;
    case NUMBER:
        parsed.addUnit(key,getNumber(value));
        break;
    case DOUBLE:
        parsed.addUnit(key,double(getDouble(value)));
        break;
    default:
        parsed.addUnit(key,value);
    }
}
json parseJSON(String jsonStr){
    jsonStr.remove(0,1);
    jsonStr.remove(jsonStr.length()-1,1);
    // Serial.println(jsonStr);
    parsed.clear();
    int i = 0;
    while(strSplit(jsonStr,',',i).length()!=0){
        createUnit(strSplit(jsonStr,',',i));
        i++;
    }
    return parsed;
}