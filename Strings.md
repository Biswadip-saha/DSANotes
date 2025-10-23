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

## Functions upon string

### Length of a string

```C
char S[] = "Welcome";

for(i=0; S[i]!='\0'; i++){}
printf("Length: %d", i);
```

### Changing case

```C
// Uppercase to lower
char A[] = "WELCOME";
for(i=0, A[i]!=0; i++){
    A[i] += 32;
}
printf("%s", A);

// Toggle cases
char B[] = "wElCoMe";
for(i=0, B[i]!=0; i++){
    if(B[i]>=65 && B[i]<=90) B[i] += 32;
    else if(B[i]>=97 && B[i]<=122) B[i] -= 32;
}
printf("%s", B);
```

### Counting vowels, consonents, words

```C
int vcount=0, ccount=0, word =1;
char A[] = "How are you";
for(i=0; i!='\0'; i++){
    if(A[i]=='a' || 
        A[i]=='e' || 
        A[i]=='i' || 
        A[i]=='o' || 
        A[i]=='u' || 
        A[i]=='A' || 
        A[i]=='E' || 
        A[i]=='I' || 
        A[i]=='O' || 
        A[i]=='U') v
            count++;
    else if((A[i]>=65 && A[i]<=90) || (A[i]>=97 && A[i]<=122)) 
        ccount++;
}

for(i=0, A[i]!=0; i++){
    if(A[i]==' ' && A[i-1]) word++;
}
```

### Validate a string

```C

```