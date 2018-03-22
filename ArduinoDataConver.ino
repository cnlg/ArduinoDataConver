#include <Arduino.h>
#include "DataConver.h"

///char类型的原始数据
char          dataChar =65;
unsigned char dataUchar = 200;
byte   dataByte = 250;
int    dataInt = 400;
long   dataLong = 500;
unsigned long dataUlong = 600;
float  dataFloat = 700.1234;
double dataDouble = 800.00;
char   *dataPchar = "123.456";
String dataString = "456.123";

///存放char数据
char          storeChar = 0;
unsigned char storeUchar = 0;
byte   storeByte = 0;
int    storeInt = 0;
long   storeLong = 0;
unsigned long storeUlong = 0;
float  storeFloat = 0;
double storeDouble = 0.00;
char  *storePchar = "";
char  storeArrayChar[20];
String storeString = "";


/** 
 * @brief char类型转成其他类型
 * @param   无
 * @return  无 
 * @see    Test()    （本函数参考其它的相关的函数，这里作一个链接） 
 * @note    (note描述需要注意的问题) 
 */
void charConverDest()
{
    storeByte  = (byte)dataChar;
    storeInt   = (int)dataChar;
    storeLong  = (long)dataChar;
    storeUlong = (unsigned long)dataChar;
    storeDouble = (double)dataChar;
    itoa(int(dataChar), storeArrayChar, 10);  //注意存储的是字符数组
    storeString += (String)dataChar;
}

/** 
 * @brief unsigned char类型转成其他类型
 * @param   无
 * @return  无 
 */
void uCharConverDest()
{
    storeByte  = (byte)dataUchar;
    storeInt   = (int)dataUchar;
    storeLong  = (long)dataUchar;
    storeUlong = (unsigned long)dataUchar;
    storeDouble = (double)dataUchar;
    itoa(int(dataUchar), storeArrayChar, 10);  //注意存储的是字符数组
    storeString += (String)dataUchar;
}

/** 
 * @brief byte类型转成其他类型
 * @param   无
 * @return  无 
 */
void byteConverDest()
{
    storeUchar  = (byte)dataByte;
    storeInt   = (int)dataByte;
    storeLong  = (long)dataByte;
    storeUlong = (unsigned long)dataByte;
    storeDouble = (double)dataByte;
    itoa(int(dataByte), storeArrayChar, 10);  //注意存储的是字符数组
    storeString += (String)dataByte;
}

/** 
 * @brief int类型转成其他类型
 * @param   无
 * @return  无 
 */
void intConverDest()
{
    storeChar = (char)dataInt;
    storeUchar  = (unsigned char)dataInt;
    storeByte  = (byte)dataInt;
    storeInt   = (int)dataInt;
    storeLong  = (long)dataInt;
    storeUlong = (unsigned long)dataInt;
    storeDouble = (double)dataInt;
    itoa(dataInt, storeArrayChar, 10);  //注意存储的是字符数组
    storeString += (String)dataInt;
}

/** 
 * @brief long类型转成其他类型
 * @param   无
 * @return  无 
 */
void longConverDest()
{
    storeInt   = (int)dataLong;
    storeLong  = (long)dataLong;
    storeUlong = (unsigned long)dataLong;
    storeDouble = (double)dataLong;
    ltoa(dataLong, storeArrayChar, 10);  //注意存储的是字符数组
    storeString += (String)dataLong;
}


/** 
 * @brief unsigned long类型转成其他类型
 * @param   无
 * @return  无 
 */
void uLongConverDest()
{
    storeInt   = (int)dataUlong;
    storeLong  = (long)dataUlong;
    storeUlong = (unsigned long)dataUlong;
    storeDouble = (double)dataUlong;
    ultoa(dataUlong, storeArrayChar, 10);  //注意存储的是字符数组
    storeString += (String)dataUlong;
}

/** 
 * @brief float类型转成其他类型
 * @param   无
 * @return  无 

 */
void floatConverDest()
{
    storeInt   = (int)dataFloat;  //小数位被截断
    storeLong  = (long)dataFloat; //小数位被截断
    storeUlong = (unsigned long)dataFloat; //小数位被截断
    storeDouble = (double)dataFloat;       //默认保留2位小数位
    dtostrf(dataFloat,2,3,storeArrayChar); //可控制输出的小数位
    storeString += (String)dataFloat;     //默认保留2位小数位
}

/** 
 * @brief char字符串 类型转成其他类型
 * @param   无
 * @return  无 
 * @see int atoi(const char *nptr);
 * @see double atof(const char *nptr);
 * @see long atol(const char *nptr);
 * @see double strtod(const char *nptr,char **endptr)
 * @see long int strtol(const char *nptr,char **endptr,int base);
 * @see unsigned long strtoul(const char *nptr,char **endptr,int base);
 * @see 参数：若参数endptr不为NULL，则会将遇到不合条件而终止的nptr中的字符指针由endptr返回；若参数endptr为NULL，则会不返回非法字符串。
 * @see 参数：参数base范围从2至36，或0。参数base代表采用的进制方式，如base值为10则采用10进制，若base值为16则采用16进制数等
 * @note atof()与使用strtod(nptr,(char**)NULL)结果相同。
 * @note atol()与使用strtol(nptr,(char**)NULL,10)；结果相同。
 */
void pCharConverDest()
{
    storeInt   = atoi(dataPchar);  //小数位被截断
    storeLong  = atol(dataPchar); //小数位被截断
    storeUlong = strtoul(dataPchar,NULL,10); //小数位被截断
    storeDouble = atof(dataPchar);       //默认保留2位小数位
    strcpy(storeArrayChar,dataPchar);
    storeString += (String)dataPchar;     
}


/** 
 * @brief String字符串类型转成其他类型
 * @param   无
 * @return  无 
 * @see string.toCharArray(buf, len)
 * @see Parameters
 * @see string: a variable of type String
 * @see buf: the buffer to copy the characters into (char [])
 * @see len: the size of the buffer (unsigned int) 

 */

void stringConverDest()
{
    storeInt   = dataString.toInt();          //小数位被截断
    storeDouble = dataString.toFloat();       //默认保留2位小数位
    storePchar  = dataString.c_str();
    dataString.toCharArray(storeArrayChar,20);
    storeString += (String)dataString;     
}


/** 
 * @brief 清理所有的存储变量
 * @param   无
 * @return  无 
 */
void cleanStorData()
{
    storeChar = 0;
    storeUchar = 0;
    storeByte = 0;
    storeInt = 0;
    storeFloat = 0;
    storeDouble = 0.00;
    storePchar = "";
    storeString = "";
}

/** 
 * @brief 串口打印转换后的数据
 * @param   无
 * @return  无 
 */
void showStoreData()
{
    Serial.print("storeUchar=");
    Serial.println(storeUchar);

    Serial.print("storeByte=");
    Serial.println(storeByte);

    Serial.print("storeInt=");
    Serial.println(storeInt);

    Serial.print("storeLong=");
    Serial.println(storeLong);

    Serial.print("storeUlong=");
    Serial.println(storeUlong);


    Serial.print("storeDouble=");
    Serial.println(storeDouble);

    Serial.print("storePchar=");
    Serial.println(storePchar);

    Serial.print("storeArrayChar=");
    Serial.println(storeArrayChar);

    Serial.print("storeString=");
    Serial.println(storeString);    
}



void setup() {
    Serial.begin(9600);
    
}

void loop() {

    charConverDest();
    showStoreData();
    Serial.println("**************************************");
    cleanStorData();
    uCharConverDest();
    showStoreData();
     Serial.println("**************************************");
    cleanStorData();
    byteConverDest();
    showStoreData();
    Serial.println("**************************************");
    cleanStorData();
    intConverDest();
    showStoreData();
    Serial.println("**************************************");
    cleanStorData();
    longConverDest();
    showStoreData();
    Serial.println("**************************************");
    cleanStorData();
    uLongConverDest();
    showStoreData();
    Serial.println("**************************************");
    cleanStorData();
    floatConverDest();
    showStoreData();
    Serial.println("**************************************");
    cleanStorData();
    pCharConverDest();
    showStoreData();
    Serial.println("**************************************");
    cleanStorData();
    stringConverDest();
    showStoreData();
    while(1);

}

