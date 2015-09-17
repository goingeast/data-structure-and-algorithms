/*
To read n characters, we first call read4 for n / 4 times. For example, if we want to read 10 characters, we will read them in the 8 (4 * 2) + 2 manner by first calling read4 for 2 (n / 4) times to read the 8 characters.
Then we see if there is any remaining number of characters to read (in this case, remain = 2).
If remain > 0, we read them again using read4. However, we may not be able to read all of them. For example, buf has 9 characters and we need to read 10. After reading the 8 characters we can only read the remaining 1 character. In this case, we simply add the minimum of remain and the actual number of characters read by read4 to the couter (total) and return it.
Otherwise, we are done and just return n.
*/
