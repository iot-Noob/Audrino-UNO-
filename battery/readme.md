# Battery Percenteage  on JHD LCD Arduino
Help user to see barrety life on JHD screen along with percentage of how much charge remaining in our LIPO battery may not work on other dry cells or battery. 
 

## Features

- Check battery percentage
- how much charge left on your battery.
- visual view of battery showing charge left onto JHD LCD module
 
## Circuit and schematic

### JHD162A circuit.
 
 * LCD RS pin to digital pin 6
 * LCD Enable pin to digital pin 7
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
### Battery to Arduino schematic
## [Voltage divider](https://www.google.com/search?q=voltage+divider&rlz=1C1GGRV_enPK915PK915&hl=en&sxsrf=ALeKk03zfhjx8U_RWuHaVyrSTgsQEr_M1Q:1620411378234&source=lnms&tbm=isch&sa=X&ved=2ahUKEwjZp9vklrjwAhU_SxUIHWCRCIMQ_AUoAXoECAEQAw&biw=1920&bih=937)

- You can use voltage divider circuit for getting voltae input from battery 
- direct connection of battery to arduino may damage your board
- [Multimeter Module Arduino](https://www.electronics-lab.com/wp-content/uploads/2018/11/b25.jpg) You can use those as well it can handle upto 24V 

## Include Library
- Copy your library to C:\Users\Admin\Documents\Arduino\libraries
- include battery measurment library i made in your arduino ide by typing  
```c++
 #include<battery.h>
 ``` 
## How to use Code
- in void setup inilitise te code to do that you need to write 
```c++
void setup() {
battery b1(A0);     
}
 ``` 
 - This define pin of your battery inout in arduino wether its conneced to an  [Multimeter module ](https://www.electronics-lab.com/wp-content/uploads/2018/11/b25.jpg) or 
Dillinger requires [Voltage divder Module ](data:image/png;base64,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) 

##### Battery position in JHD LCD
- Jhd 162a  lcd  had 16 rows 2 columns.
- This piece of code in setup define each column and row where to display battey on screen.

```c++
void setup() {
 b1.begin(11,1); //set position of battery onto LCD   
}
```
- in loop you need to add this line to draw battery on screen
```c++
void loop() {
 b1.Main(); //show battery on screen    
}
```

## Author

Created by IOT Noob Mar 22  2021 



 
