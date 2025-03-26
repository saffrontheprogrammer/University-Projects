#Defined first checkpoint

def checkpoint1():
    initial_cars = 12  #Number of cars starting with
    increase_per_minute = 4  #Cars to be added each minute
    total_minutes = 5  #how many minutes checkpoint lasts

#Loop through each minute, updating the car count as going along
    	for minute in range(1, total_minutes + 1): #Used to work out the total number of cars at the current minute
        cars = arithmetic_sequence(initial_cars, increase_per_minute, minute)
        #Displays result for the current minute
        print(f"At minute {minute}: {cars} cars")

#Function to calculate arithmetic sequence for cars
def arithmetic_sequence(a1, d, n):
    #Return the nth term in an arithmetic sequence
    return a1 + (n - 1) * d

#Define second checkpoint function
def checkpoint2():  #Defined function for checkpoint number 2
    #Values for 2nd checkoint
    initial_cars = 12  #Starting number (cars)
    increase_per_minute = 4  #Cars added each minute
    total_minutes = 10  #Duration of checkpoint 2 in minutes

    #Loop through each minute, updating the car count
    for minute in range(1, total_minutes + 1):
        #Calculates the total number of cars at the current minute specified
        cars = arithmetic_sequence(initial_cars, increase_per_minute, minute)
        #Display result
        print(f"At minute {minute}: {cars} cars")

#Function that calculates an arithmetic sequence
def arithmetic_sequence(a1, d, n):
    return a1 + (n - 1) * d

#Third Checkpoint
def checkpoint3():  #Defined function for checkpoint number 3
    # Initial values for checkpoint 3
    initial_cars = 12  # Starting number of cars
    increase_per_minute = 4  # Cars added each minute
    total_minutes = 15  # Duration of checkpoint 3 in minutes

    #Loop - Looping through each minute, updating car count
    for minute in range(1, total_minutes + 1):
        # Calculate the total cars at the current minute
        cars = arithmetic_sequence(initial_cars, increase_per_minute, minute)
        # Display the result for the current minute
        print(f"At minute {minute}: {cars} cars")

#Ask the user which checkpoint they want to check
ans = int(input("Which checkpoint would you like to see the results of? "))

#Check which checkpoint the user wishes to view and call the function
if ans == 1:
    checkpoint1()
elif ans == 2:
    checkpoint2()
elif ans == 3:
    checkpoint3()
