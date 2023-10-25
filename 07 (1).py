#!/usr/bin/env python3

contacts = {
    'Jason': ['555-0123', '555-0000'],
    'Carl': '555-0987'
}

if 'Jason' in contacts.keys():
    print("Jason's phone number is:")
    print(contacts['Jason'][0])

if 'Tony' in contacts.keys():
    print("Tony's phone number is:")
    print(contacts['Tony'][0])
