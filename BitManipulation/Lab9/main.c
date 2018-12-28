//Kateryna Osadchuk
//11/8/18
//Lab 9
//CIS 2107

#include <stdio.h>
#include <stdint.h>

/* weatherlog_t is a "weather sensor log type"
 which is really defined as a 64-bit unsigned
 integer.  See below. */
typedef uint64_t weatherlog_t;


unsigned int add(unsigned int, unsigned int);
unsigned int sub(unsigned int, unsigned int);
unsigned int mul(unsigned int, unsigned int);
void print_half_nybbles(unsigned int);
int is_negative(int);
int has_odd(unsigned int);
unsigned int make_odd(unsigned int);
unsigned int reverse_half_nybbles(unsigned int);

weatherlog_t pack_log_entry(unsigned int, unsigned int, unsigned int,
                            unsigned int,
                            int, int,
                            unsigned int, unsigned int);

unsigned int get_year(weatherlog_t entry);
unsigned int get_month(weatherlog_t entry);
unsigned int get_day(weatherlog_t entry);
unsigned int get_zip(weatherlog_t entry);
unsigned int get_high(weatherlog_t entry);
unsigned int get_low(weatherlog_t entry);
unsigned int get_precip(weatherlog_t entry);
unsigned int get_wind(weatherlog_t entry);

int main(int argc, char **argv) {
    unsigned int i, j;
    int x, y;
    unsigned int year, month, day,
    zip, high_temp, low_temp, precip, avg_wind_speed;
    weatherlog_t log_entry;
    
    printf("Enter an integer: ");
    scanf("%u", &i);
    printf("Enter another integer: ");
    scanf("%u", &j);
    printf("One more integer, please: ");
    scanf("%d", &x);
    printf("Please enter a positive integer: ");
    scanf("%d", &y);
    
    printf("i + j = %u\n", add(i,j));
    printf("i - j = %u\n", sub(i,j));
    printf("i * j = %u\n", mul(i,j));
    
    if (is_negative(x))
        printf("%d is negative\n", x);
    else
        printf("%d is non-negative\n", x);
    
    if (has_odd(y)) {
        printf("%x has an odd number of bits in its binary representation\n", y);
    }
    else {
        printf("%x has an even number of bits in its binary representation\n", y);
        printf("but %x has an odd number of bits in its binary representation\n", make_odd(y));
    }
    
    printf("The half-nybbles of %d (in hex 0x%x) are:", x, x);
    print_half_nybbles(x);
    
    printf("%x with reversed half-nybbles is %x\n", x, reverse_half_nybbles(x));
    
    printf("Enter a year: ");
    scanf("%u", &year);
    
    printf("Enter a month as an integer (1-12): ");
    scanf("%u", &month);
    
    printf("Enter a day as an integer (1-31): ");
    scanf("%u", &day);
    
    printf("Enter a zip code as an integer (0-99999): ");
    scanf("%u", &zip);
    
    printf("Enter a temperature as an integer: ");
    scanf("%u", &high_temp);
    
    printf("Enter another temperature as an integer: ");
    scanf("%u", &low_temp);
    
    
    printf("Enter rainfall amount as an integer (mm): ");
    scanf("%u", &precip);
    
    printf("Enter a as an integer (km/hr): ");
    scanf("%u", &avg_wind_speed);
    
    
    log_entry=pack_log_entry(year, month, day, zip, high_temp, low_temp,
                             precip, avg_wind_speed);
    printf("You entered: %u/%u/%u for zip %5d: high %d F, low %d F, precip %d mm, wind speed %d km/hr\n",
           get_day(log_entry), get_month(log_entry), get_year(log_entry),
           get_zip(log_entry), get_high(log_entry), get_low(log_entry),
           get_precip(log_entry), get_wind(log_entry));
    return 0;
}

unsigned int add(unsigned int i, unsigned int j) {
    unsigned int sum = i;
    //iterate over all bits
    while(j != 0){
        //if bit is 1 for both, carry 1 to next bit
        int carry = sum & j;
        //add
        sum = sum ^ j;
        //update j for next iteration
        j = carry << 1;
    }
    return sum;
}

unsigned int sub(unsigned int i, unsigned int j) {
    unsigned int diff = i;
    //while has next bit
    while(j != 0){
        //borrow has common bits of of j and unset bits of diff
        int borrow = ~diff & j;
        //subtraction
        diff = diff ^ j;
        //shift j for next iteration
        j = borrow << 1;
    }
    return diff;
}

unsigned int mul(unsigned int i, unsigned int j) {
    unsigned int product = 0;
    //iterate over all bits of j
    while(j > 0){
        //if has a one at position
        if((j & 1) == 1){
            //add i to the product
            product = add(product, i);
        }
        //shift to next bits
        j = j >> 1;
        i = i << 1;
    }

    return product;
}

/* prints the half-nybbles (i.e. 2 bit values) of x,
 one half-nybble at a time */
void print_half_nybbles(unsigned int x) {
    //iterates over all bits
    while(x != 0){
        //get two rightmost bits
        int nib = x & 0x03;
        //print them
        printf("%u\n", nib);
        //shift over two bits
        x = x >> 2;
    }
}

/* returns the reverse of the half-nybbles of i */
unsigned int reverse_half_nybbles(unsigned int i) {
    unsigned int ret = i;
    int numBits = mul(sizeof(ret), 8);
    
    int j = 0;
    //iterate over all bits
    while(j < numBits-1){
        //get bit on right
        int bit1 = (ret >> j) & 1U;
        //get left bit
        int bit2 =(ret >> add(j, 1)) & 1U;
        
        //swap bits and add onto end of ret
        ret ^= (-bit2 ^ ret) & (1UL << j);
        ret ^= (-bit1 ^ ret) & (1UL << add(j, 1));
    
        //go to next two bits
        j = add(j, 2);
    }
    
    return ret;
}

/* returns 1 if x < 0
 returns 0 otherwise
 
 Do not use the <, > operators. */
int is_negative(int x) {
    int numBits = mul(sizeof(x), 8);
    //go to most significant bit
    while(numBits > 0){
        x>>=1;
        numBits = sub(numBits, 1);
    }
    //if msb is 1, then number is negative
    if(x & 1){
        return 1;
    } else {
        return 0;
    }
}

/* returns 1 if x's binary representation
 has an odd number of 1s or 0 otherwise */
int has_odd(unsigned int x) {
    int numBits = mul(sizeof(x), 8);
    int numOnes = 0;
    //iterate over all bits
    while(numBits > 0){
        //count number of ones
        if(x & 1){
            numOnes = add(numOnes, 1);
        }
        //go to next position
        x>>=1;
        numBits = sub(numBits, 1);
    }
    //if odd number of ones, return 1
    if(numOnes & 1){
        return 1;
    } else {
        return 0;
    }
    
}


/* If x's binary representation contains an odd number of 1s, x is
 returned. Otherwise, it returns a copy of x, but with its most significant
 bit modified so that there is an odd number of 1s. */
unsigned int make_odd(unsigned int x) {
    unsigned int retVal = x;
    int isOdd = has_odd(x);
    //if has even number of ones
    if(isOdd == 0){
        //go to most significant bit
        unsigned int numBits = mul(sizeof(x), 8);
        printf("number of bits in %d: %u\n", x, numBits);
        unsigned int msb = 1 << (numBits - 1);
        printf("msb of %d is: %u\n", x, msb);
        //set most significant bit as 1
        retVal ^= (-(unsigned long)1 ^ retVal) & (1UL << (numBits-1));
    } else {
        printf("The number %u already has an odd number of ones\n", x);
    }
    
    return retVal;
}


/* combines all of the arguments into a single weatherlog_t entry as described below */
weatherlog_t pack_log_entry(unsigned int year, unsigned int month, unsigned int day,
                            unsigned int zip, int high_temp, int low_temp,
                            unsigned int precip, unsigned int avg_wind_speed) {
    
    weatherlog_t entry;
    
    //get year in proper format
    year = sub(year, 2000);
    //initialize entry to hold only year
    entry = year;
    
    //add four bits to end for month
    entry <<= 4;
    //add month to entry
    entry |= month;
    
    //add 5 bits for day
    entry <<= 5;
    //add day
    entry |= day;
    
    //add 16 bits for zip
    entry <<= 16;
    //add zip
    entry |= zip;
   
    //add 8 bits for high temp
    entry <<= 8;
    //add high temp
    entry |= high_temp;
    
    //add 8 bits for low temp
    entry <<= 8;
    //add low temp
    entry |= low_temp;
   
    //sadd 10 bits for amount of precip
    entry <<= 10;
    //add precip
    entry |= precip;
    
    //add 7 bits for windspeed
    entry <<= 7;
    //add windspeed
    entry |= avg_wind_speed;
    
    return entry;
}

unsigned int get_year(weatherlog_t entry) {
    //shift to where year is stored
    unsigned int year = entry >>58;
    return year;
    
}

unsigned int get_month(weatherlog_t entry) {
    //shift to where month is stored
    unsigned int month = entry << 6 >> 60;
    return month;
}

unsigned int get_day(weatherlog_t entry) {
    //shift to where day is stored
    unsigned int day = entry << 10 >> 59;
    return day;
}

unsigned int get_zip(weatherlog_t entry) {
    //shift to zipcode
    return entry << 15 >> 48;
}

unsigned int get_high(weatherlog_t entry){
    //shift to high temp
    return entry << 31 >> 56;
}

unsigned int get_low(weatherlog_t entry) {
    //shift to low temp
    return entry << 39 >> 56;
}

unsigned int get_precip(weatherlog_t entry) {
    //shift to precip
    return  entry << 47 >> 54;
}

unsigned int get_wind(weatherlog_t entry) {
    //shift to windspeed
    return entry << 57 >> 57;
}

/* weatherlog_t
 
 A particular weather sensor called the WeatherJuicer 2000 TM stores a
 log entry each day, representing weather activity from the
 previous 24 hours. Each entry includes a:
 
 - year :: 6 bits -- stored as the number of years since the year 2000.
 - month :: 4 bits
 - day :: 5 bits
 - zip_code :: 16 bits
 - high_temp :: in degrees Fahrenheit, stored as an 8-bit signed integer
 - low_temp :: in degrees Fahrenheit, stored as 8-bit signed integer
 - precipitation :: in mm. stored as a 10-bit unsigned integer.
 - average_wind_speed :: 7 bits. unsigned int km/hr.
 
 All of these are packed into a 64 bit unsigned integer in the above order.
 
 For example, if on September 16, 2015, on Temple's main campus, which
 is in zip code 19122, we have 15 mm of rain, a high temperature of 85
 degrees, a low temperature of 65 degrees, and an average wind speed of
 5 km/hour.
 
 We'd store:
 - year :: 2015, which is 15 years from 2000, so 001111
 - month :: September, which is the 9th month, so 1001.
 - day :: 16, which is 1 0000
 - zip_code :: 19122 which is 0100 1010 1011 0010
 - high_temp :: 85F, so 0101 0101
 - low_temp :: 65F, so 0100 0001
 - precipitation :: 35 mm so 00 0010 0011
 - average wind speed :: 5 km/h, so 000 0101
 
 And all would be packed into a single 64-bit unsigned integer:
 
 00 1111 1001 10000 0100 1010 1011 0010 0101 0101 0100 0001 00 0010 0011 000 0101
 
 OR
 
 0011 1110 0110 0000 1001 0101 0110 0100 1010 1010 1000 0010 0001 0001 1000 0101
 
 OR
 
 0x3e609564aa821185
 
 
 We define this weather log as its own datatype called weatherlog_t, which
 under the covers is really a 64-bit unsigned int. This is done in the line:
 
 typedef uint64_t weatherlog_t;
 
 */
