# Strings

## Chracter set / ASCII codes

0 - 48, .... 9 - 57
<br>
A - 65, .... Z - 90
<br>
a - 97, .... z - 122

-   ASCII code ranges from 0 - 127, ie 7 bits are enough to represent an ASCII code, thus taking 1 byte of memory to represent them
-   Unicode takes 2 bytes, 16 bits, representing the characters in hexadecimal format

## Character Array or String

```C
char X[5];
char X[5] = {'A','B','C','D','E'};
char X[ ] = {'A','B','C','D','E'};
char X[ ] = {65, 66, 67, 68, 69};

// By adding a string delimiter at the end of the character array it becomes a string
// \0 is the delimiter of a string or null character

char name[10] = {'J','o','h','n', \0}; 
// -> InMemory: name = 'J','o','h','n', \0, 0, 0, 0, 0, 0
```

## Creating, Reading, Writing a string

```C
char name[10] = {'J','o','h','n', \0}; // Size: 10
char name[  ] = {'J','o','h','n', \0}; // Size: 5
char name[  ] = "John";

// for printing:
printf("%s", name);

// for creating:
scanf("%s", name); // can read only one word
gets(name); // reads words till you hit enter
```
