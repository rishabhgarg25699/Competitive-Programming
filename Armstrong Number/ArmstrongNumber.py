'''A positive integer of n digits is called an Armstrong number of order n  if
abcd... = a^n + b^n + c^n + d^n + .... 
Here x^y = x raised to power y '''


#Function to check if the number is Armstrong or Not
def armstrong(temp, power):
    asum = 0
    while (temp > 0):
        asum +=  (temp % 10) ** power
        temp //= 10
    return asum

#Driver Code
num = int(input("Enter the number: "))

temp = num

order = len(str(num)) #No. of digits

checksum = armstrong(temp, order)

if (checksum == num):
    print(f'{num} is an Armstrong number')
else:
    print(f'{num} is not an Armstrong number')