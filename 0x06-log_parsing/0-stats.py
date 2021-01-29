#!/usr/bin/python3
'''DOCSTRING'''
import fileinput

file_size = 0
stat_code = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
    }
counter = 0

for line in fileinput.input():
    line_split = line.split()
    if isinstance(line_split[-1], int):
        continue
    file_size = file_size + int(line_split[8])
    if line_split[7] in stat_code.keys():
        stat_code[line_split[7]] = stat_code[line_split[7]] + 1
    counter += 1
    if counter == 10:
        counter = 0
        print("File size: {}".format(file_size))
        if stat_code['200'] > 0:
            print("200: {}".format(stat_code['200']))
        if stat_code['301'] > 0:
            print("301: {}".format(stat_code['301']))
        if stat_code['400'] > 0:
            print("400: {}".format(stat_code['400']))
        if stat_code['401'] > 0:
            print("401: {}".format(stat_code['401']))
        if stat_code['403'] > 0:
            print("403: {}".format(stat_code['403']))
        if stat_code['404'] > 0:
            print("404: {}".format(stat_code['404']))
        if stat_code['405'] > 0:
            print("405: {}".format(stat_code['405']))
        if stat_code['500'] > 0:
            print("500: {}".format(stat_code['500']))

print("File size: {}".format(file_size))
if stat_code['200'] > 0:
    print("200: {}".format(stat_code['200']))
if stat_code['301'] > 0:
    print("301: {}".format(stat_code['301']))
if stat_code['400'] > 0:
    print("400: {}".format(stat_code['400']))
if stat_code['401'] > 0:
    print("401: {}".format(stat_code['401']))
if stat_code['403'] > 0:
    print("403: {}".format(stat_code['403']))
if stat_code['404'] > 0:
    print("404: {}".format(stat_code['404']))
if stat_code['405'] > 0:
    print("405: {}".format(stat_code['405']))
if stat_code['500'] > 0:
    print("500: {}".format(stat_code['500']))
