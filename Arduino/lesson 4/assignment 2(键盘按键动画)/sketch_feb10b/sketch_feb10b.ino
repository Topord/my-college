#include <Keypad.h>
#define KEY_ROWS 4 // 按鍵模組的列數
#define KEY_COLS 4 // 按鍵模組的行數
 
// 依照行、列排列的按鍵字元（二維陣列）
char keymap[KEY_ROWS][KEY_COLS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};

byte rowPins[KEY_ROWS] = {9, 8, 7, 6}; // 按鍵模組，列1~4接腳。 
byte colPins[KEY_COLS] = {13, 12, 11, 10};     // 按鍵模組，行1~4接腳。
// 初始化Keypad物件
// 語法：Keypad(makeKeymap(按鍵字元的二維陣列), 模組列接腳, 模組行接腳, 模組列數, 模組行數)
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS, KEY_COLS);
 
void setup(){
  Serial.begin(9600);
}
   
void loop(){
  // Key通过padgetKey()方法读取按键
  char key = myKeypad.getKey();
   
  if (key){  // 若有按鍵被按下
    if(key == 'A')  Serial.println(11);
    else if(key == 'B') Serial.println(12);
    else if(key == 'C') Serial.println(13);
    else if(key == 'D') Serial.println(14);
    else if(key == '*') Serial.println(15);
    else if(key == '#') Serial.println(16);
    else Serial.println(key);  // 显示按下的
    delay(1000);
  }
}
