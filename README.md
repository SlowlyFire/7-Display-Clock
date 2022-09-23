# 7-Display-Clock  
![image](https://user-images.githubusercontent.com/83518959/192017547-286603d1-eeb5-4460-8eed-3e3add6dd7d8.png)   
The following C project contains the C source code and C examples used for seven segment display clock.  
At first we have a menu:  
- by pressing 1, we get from the user random strings, and the program returns 1 if the given string
can be represented by seven-segment display, or 0 if it can't. that goes for every single string.  
examples of strings: "hello", "good", "yes", "now", "here", etc.      
- by pressing 2, we get from the user random states (chars such as 0x17, 0x7F), and the program returns
1 if what the given state represents, can be represented by seven-segment display, or 0 if it can't.  
examples of states: 0x4E (represents 'N'), 0x79 ('y'), 0x47 ('G'), etc.  

*we assume in that project that the user won't enter more than 500 strings, or states in a time.**  

  


 
