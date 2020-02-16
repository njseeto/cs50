## Problem Set 1 - Mario (more comfortable)
Let’s create a pyramid in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramid itself is also be taller than it is wide.

```
       #
      ##
     ###
    ####
   #####
  ######
 #######
########
```

The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramid should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

Here’s how the program might work if the user inputs 8 when prompted:

```
$ ./mario
Height: 8

       #
      ##
     ###
    ####
   #####
  ######
 #######
########
```
Here’s how the program might work if the user inputs 4 when prompted:

```
$ ./mario
Height: 4
   #
  ##
 ###
####
```

If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:

```
$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4

   #
  ##
 ###
####
```

<br>


## My thoughts breaking down the problem
```
   #
  ##
 ###
####
```
For the above pyramid:
- We need 4 lines
-  Each line has 4 characters, either a # or a space
- From top to bottom, the number of spaces decrease and the the number of hashes increase


So to type it out for each line:
- The first line we need, 4-1=3 spaces and 1 hash.
- The second line we need, 4-2=2 spaces and 2 hashes.
- The third line we need, 4-3=1 spaces and 3 hashes.
- The fourth line we need, 4-4=0 spaces and 4 hashes.

...Now we’re seeing a pattern.

If we look at using a loop, we’ll need:
- 4-0-1=3, 0+1=1
- 3-0-1=2, 1+1=2
- 2-0-1=1, 2+1=3
- 1-0-1=0, 3+1=4

So for a pyramid of size n:
- (n-1)-0=(n-1), 0+1=1
- (n-1)-1=(n-2), 1+1=2
......

- The last line will be: (n-1)-(n-1)=0, (n-1)+1=n

Solution is found in: `mario_more_comfy.c`


<br>

## Proble Set 1: Mario - less comfortable

The slightly more difficult version of mario is to make a pyramid that looks like this.

```
$ ./mario
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########
```

### My thoughts
Since we have the harder bit out of the way, we just need to add two spaces and a right aligned pyramid (ie: no spaces).

Solution: `mario_less_comfy.c`




### Problem Set - Cash (Greedy Algorithms)

Implement, a program that first asks the user how much change is owed and then prints the minimum number of coins with which that change can be made.
Use `get_float` to get the user’s input and printf to output your answer. Assume that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).

We ask that you use `get_float` so that you can handle dollars and cents, albeit sans dollar sign. In other words, if some customer is owed $9.75 (as in the case where a newspaper costs 25¢ but the customer pays with a $10 bill), assume that your program’s input will be 9.75 and not $9.75 or 975. However, if some customer is owed $9 exactly, assume that your program’s input will be 9.00 or just 9 but, again, not $9 or 900. Of course, by nature of floating-point values, your program will likely work with inputs like 9.0 and 9.000 as well; you need not worry about checking whether the user’s input is “formatted” like money should be.

You need not try to check whether a user’s input is too large to fit in a float. Using get_float alone will ensure that the user’s input is indeed a floating-point (or integral) value but not that it is non-negative.

If the user fails to provide a non-negative value, your program should re-prompt the user for a valid amount again and again until the user complies.

So that we can automate some tests of your code, be sure that your program’s last line of output is only the minimum number of coins possible.

Beware the inherent imprecision of floating-point values. If x is 2, and y is 10, x / y is not precisely two tenths! And so, before making change, you’ll probably want to convert the user’s inputted dollars to cents (i.e., from a float to an int) to avoid tiny errors that might otherwise add up!

Take care to round your cents to the nearest penny, as with round, which is declared in math.h. For instance, if dollars is a float with the user’s input (e.g., 0.20), then code like
int coins = round(dollars * 100);

Will safely convert 0.20 (or even 0.200000002980232238769531250) to 20.

Your program should behave per the examples below.

```
$ ./cash
Change owed: 0.41
4

$ ./cash
Change owed: -0.41
Change owed: foo
Change owed: 0.41
4
```

### My Thinking
- Will need to check the user's input is valid.
- Will need to convert user input to nearest penny (prevent off by one errors)
- Will require a way to track the change and the coins used.
- Will check each denomination (25, 10, 5, 1), if the remaining does not equal zero then take away from the change and add one to coins used.
- If the change remaining can not be less than 0.
- Will output the number of coins used.


Something like...

```
   int cents = users_input;
   int coinsUsed = 0;

   while (cents >= 25)
   {
      // add to the variable if a 25c is used
      coinsUsed ++;

      // updates change owed as required 
      cents -= 25; 
   }

   while (cents >= 10)
   {
      coinsUsed ++;
      cents -= 10;
   }

   while (cents >= 5)
   {
      coinsUsed ++;
      cents -= 5;
   }

   while (cents >= 1)
   {
      coinsUsed ++;
      cents -= 1;
   }

   printf(coinsUsed);
   ```