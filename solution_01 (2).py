#!/usr/bin/env python3

# Ask for the distance.
distance = input('How far would you like to travel in miles? ')

# Convert the distance to an integer.
distance = int(distance)

# Determine what mode of transport to use.
if distance < 3:
    mode_of_transport = 'walking'
elif distance < 300:
    mode_of_transport = 'driving'
else:
    mode_of_transport = 'flying'

# Display the result.
print('I suggest {} to your destination.'.format(mode_of_transport))
