#!/usr/bin/python3
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
    file_size = file_size + int(line_split[8])
    stat_code[line_split[7]] = stat_code[line_split[7]] + 1
    counter += 1
    if counter == 9:
        counter = 0
        print("File size: {}".format(file_size))
        print("200: {}".format(stat_code['200']))
        print("301: {}".format(stat_code['301']))
        print("400: {}".format(stat_code['400']))
        print("401: {}".format(stat_code['401']))
        print("403: {}".format(stat_code['403']))
        print("404: {}".format(stat_code['404']))
        print("405: {}".format(stat_code['405']))
        print("500: {}".format(stat_code['500']))
