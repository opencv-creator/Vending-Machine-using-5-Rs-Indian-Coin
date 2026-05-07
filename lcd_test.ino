

void lcd_setup() {
  // Initiate the LCD and turn on the backlight
  lcd.init();          // Initiate the LCD module
  lcd.backlight();     // Turn on the backlight
}

void lcd_print(char* data1,char* data2) {
lcd.clear();
  // Print 'Hello World!' on the first line of the LCD
  lcd.setCursor(0, 0);          // Set the cursor on the first column and first row.
  lcd.print(data1);    // Print the string "Hello World!"
  
  lcd.setCursor(0, 1);          //Set cursor to 2nd column and 2nd row (counting starts at 0)
  lcd.print(data2);
}