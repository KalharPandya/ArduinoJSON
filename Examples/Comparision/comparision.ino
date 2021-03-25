

#include<optimizedJSON.h>
#ifdef ESP32   
#else
    #include <MemoryFree.h>
#endif

long getMemory(){
    #ifdef ESP32   
        return ESP.getFreeHeap();
    #else
        return freeMemory();
    #endif
}

void addUnits(json j,int count){
    for(int i = 0 ; i < count ; i ++ ){
        j.addUnit(String("key")+String(i),4585865);
    }
}void addUnits(optimizedJSON j,int count){
    for(int i = 0 ; i < count ; i ++ ){
        j.addUnit(String("key")+String(i),4585865);
    }
}
long initialMemory = 0;
long afterMemory = 0;

void setup(){
    Serial.begin(115200);
    
    Serial.println("Welcome to the unboxing of Optimized Json\n\n");
    Serial.println("Available Memory is "+ String(getMemory()));
    Serial.println("\n\nLets Measure Size occupied by 1 normal JSON Object with 4 units");
    initialMemory = getMemory();
    json j;
    addUnits(j,4);
    afterMemory = getMemory(); 
    Serial.println("Memory Occupied by Normal Json with 4 Units is \n");
    Serial.println(  String(initialMemory  - afterMemory) + "Bytes\n\n");

    Serial.println("Lets Measure Size occupied by 1 normal OptimizedJSON Object with 5 units");
    initialMemory = getMemory();
    optimizedJSON oj;
    addUnits(oj,4);
    afterMemory = getMemory(); 
    Serial.println("Memory Occupied by Normal Json with 4 Units is \n");
    Serial.println(  String(initialMemory  - afterMemory) + "Bytes\n\n");

    
    // Serial.println("Welcome to the unboxing of Optimized Json");
    
}

void loop(){
}